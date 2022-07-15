
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0


//===========================================================================
//  Semantic analysis
//===========================================================================

#ifndef __CPP2_SEMA
#define __CPP2_SEMA

#include "parse.h"


namespace cpp2 {

//-----------------------------------------------------------------------
// 
//  Symbol/scope table
// 
//-----------------------------------------------------------------------
//
struct declaration_sym {
    bool start = false;
    declaration_node const* declaration = nullptr;
    token const*            identifier  = nullptr;
    statement_node const*   initializer = nullptr;  // must not be null

    auto position() const -> source_position
    {
        assert (declaration);
        return declaration->position();
    }
};

struct identifier_sym {
    bool assignment_to = false;
    token const* identifier = nullptr;

    auto position() const -> source_position
    {
        assert (identifier);
        return identifier->position();
    }
};

struct selection_sym {
    bool start = false;
    selection_statement_node const* selection = nullptr;

    auto position() const -> source_position
    {
        assert (selection);
        return selection->position();
    }
};

struct compound_sym {
    bool start = false;
    compound_statement_node const* compound = nullptr;
    bool is_true_branch;

    auto position() const -> source_position
    {
        assert (compound);
        return compound->position();
    }
};

struct symbol {
    int depth = -1;

    enum active { declaration=0, identifier, selection, compound };
    std::variant <
        declaration_sym,
        identifier_sym,
        selection_sym,
        compound_sym
    > sym;

    symbol(int depth, declaration_sym const& sym) : depth{depth}, sym{sym} { }
    symbol(int depth, identifier_sym  const& sym) : depth{depth}, sym{sym} { }
    symbol(int depth, selection_sym   const& sym) : depth{depth}, sym{sym} { }
    symbol(int depth, compound_sym    const& sym) : depth{depth}, sym{sym} { }

    auto position() const -> source_position
    {
        switch (sym.index())
        {
        break;case declaration: {
            auto const& s = std::get<declaration>(sym);
            return s.position();
        }

        break;case identifier: {
            auto const& s = std::get<identifier>(sym);
            return s.position();
        }

        break;case selection: {
            auto const& s = std::get<selection>(sym);
            return s.position();
        }

        break;case compound: {
            auto const& s = std::get<compound>(sym);
            return s.position();
        }

        break;default:
            assert (!"illegal symbol state");
            return { 0, 0 };
        }
    }
};


//  Keep a list of all token*'s found that are definite first uses
//  of the form "x = expr;" for an uninitialized local variable x,
//  which we will rewrite to construct the local variable.
//
std::vector<token const*> definite_initializations;

auto is_definite_initialization(token const* t) -> bool
{
    return
        std::find(
            definite_initializations.begin(),
            definite_initializations.end(),
            t
            )
        != definite_initializations.end();
}


//-----------------------------------------------------------------------
// 
//  sema: Semantic analysis
// 
//-----------------------------------------------------------------------
//
class sema
{
    using enum declaration_node::active;
    using enum symbol::active;

public:
    std::vector<error>& errors;
    std::vector<symbol> symbols;
    declaration_sym     partial;

    std::vector<selection_statement_node const*> active_selections;
     
public:
    //-----------------------------------------------------------------------
    //  Constructor
    // 
    //  errors      error list
    //
    sema(
        std::vector<error>& errors
    )
        : errors{ errors }
    {
    }

    void debug_print(std::ostream& o)
    {
        for (auto const& s : symbols)
        {
            o << std::setw(3) << s.depth << " |";
            o << std::setw(s.depth*2+1) << " ";

            switch (s.sym.index()) {

            break; case declaration: {
                auto const& sym = std::get<declaration>(s.sym);

                assert (sym.declaration);
                if (sym.declaration->is(function)) {
                    if (sym.start) {
                        o << "function ";
                    }
                    else {
                        o << "/function";
                    }
                }
                else if (sym.declaration->is(variable)) {
                    if (sym.start) {
                        o << "var ";
                    }
                    else {
                        o << "/var ";
                    }
                }

                if (sym.start && sym.identifier) {
                    o << sym.identifier->to_string(true);
                }

                if (sym.start && !sym.initializer) {
                    o << " *** UNINITIALIZED";
                }
            }

            break; case identifier: {
                auto const& sym = std::get<identifier>(s.sym);
                assert (sym.identifier);
                if (is_definite_initialization(sym.identifier)) {
                    o << "*** " << sym.identifier->position().to_string() 
                      << " DEFINITE INITIALIZATION OF ";
                }
                else if (sym.assignment_to) {
                    o << "*** assignment to ";
                }
                else {
                    o << "*** use of ";
                }
                o << sym.identifier->to_string(true);
            }

            break;case selection: {
                auto const& sym = std::get<selection>(s.sym);
                if (!sym.start) {
                    o << "/";
                }
                o << "selection";
            }

            break;case compound: {
                auto const& sym = std::get<compound>(s.sym);
                if (!sym.start) {
                    o << "/";
                    --scope_depth;
                }
                o << (sym.is_true_branch ? "true" : "false") << " branch";
            }

            break;default:
                o << "ERROR";
            }

            o << "\n";
        }
    }


    //-----------------------------------------------------------------------
    //  Apply local first- and last-use rules
    //
    auto apply_local_rules() -> bool
    {
        auto ret = true;

        //  Helpers for readability
        //
        auto is_uninitialized_variable_decl = [&](symbol const& s) 
            -> declaration_sym const*
        {
            if (auto const* sym = std::get_if<declaration>(&s.sym)) {
                if (sym->start && !sym->initializer) {
                    assert (sym->declaration->is(variable));
                    return sym;
                }
            }
            return {};
        };

        //  Function logic: For each entry in the table...
        //
        for (auto sympos = std::ssize(symbols) - 1; sympos >= 0; --sympos)
        {
            //  If this is an uninitialized local variable
            //
            if (auto decl = is_uninitialized_variable_decl(symbols[sympos])) {
                assert (decl->identifier && !decl->initializer);
                ret = ret && 
                    ensure_definitely_initialized(decl->identifier, sympos+1, symbols[sympos].depth);
            }
        }

        return ret;
    }

private:
    //  Check that local variable *id is initialized before use on all paths
    //  starting at the given position and depth in the symbol/scope table
    //
    auto ensure_definitely_initialized(token const* id, int pos, int depth) -> bool
    {
        struct stack_entry{
            int pos;    // start of this selection statement

            struct branch {
                int  start;
                bool result = false;
            };
            std::vector<branch> branches;

            auto debug_print(std::ostream& o) const -> void 
            {
                o << "Stack entry: " << pos << "\n";
                for (auto const& e : branches) {
                    o << "  ( " << e.start << " , " << e.result << " )\n";
                }
            }
        };
        std::vector<stack_entry> selection_stack;

        for ( ; symbols[pos].depth >= depth; ++pos) {
            switch (symbols[pos].sym.index()) {

            break;case declaration: {
                auto const& sym = std::get<declaration>(symbols[pos].sym);
                if (sym.start && sym.identifier && *sym.identifier == *id) {
                    errors.emplace_back( 
                        sym.identifier->position(), 
                        "local variable" + sym.identifier->to_string(true)
                            + " cannot have the same name as an uninitialized"
                              " variable in the same function");
                }
            }

            break;case identifier: {
                auto const& sym = std::get<identifier>(symbols[pos].sym);
                assert (sym.identifier);

                if (is_definite_initialization(sym.identifier)) {
                    errors.emplace_back( 
                        sym.identifier->position(), 
                        "local variable " + id->to_string(true)
                            + " must be initialized before " + sym.identifier->to_string(true)
                            + " (local variables must be initialized in the order they are declared)"
                    );
                    return false;
                }

                //  If we find a use of this identifier
                if (*sym.identifier == *id) {

                    //  If we're not inside a selection statement, we're at the top level --
                    //  just return true if it's an assignment to it, else return false
                    if (std::ssize(selection_stack) == 0) {
                        if (sym.assignment_to) {
                            definite_initializations.push_back( sym.identifier );
                        }
                        else {
                            errors.emplace_back( 
                                sym.identifier->position(), 
                                "local variable " + sym.identifier->to_string(true)
                                    + " is used in a general expression before it was initialized");
                        }
                        return sym.assignment_to;
                    }

                    //  Else if we're inside a selection statement but still in the condition
                    //  portion (there are no branches entered yet)
                    else if (std::ssize(selection_stack.back().branches) == 0) {
                        //  If this is a top-level selection statement, handle it the same as
                        //  if we weren't an a selection statement
                        if (std::ssize(selection_stack) == 1) {
                            if (sym.assignment_to) {
                                definite_initializations.push_back( sym.identifier );
                            }
                            else {
                                errors.emplace_back( 
                                    sym.identifier->position(), 
                                    "local variable " + sym.identifier->to_string(true)
                                        + " is used in a condition before it was initialized");
                            }
                            return sym.assignment_to;
                        }
                        //  Else we can skip the rest of this selection statement, and record
                        //  this as the result of the next outer selection statement's current branch
                        else {
                            selection_stack.pop_back();
                            assert (std::ssize(selection_stack.back().branches) > 0);
                            selection_stack.back().branches.back().result = sym.assignment_to;

                            int this_depth = symbols[pos].depth;
                            while (symbols[pos + 1].depth >= this_depth) {
                                ++pos;
                            }
                        }
                    }

                    //  Else we're in a selection branch and can skip the rest of this branch
                    //  and record this as the result for the current branch
                    else {
                        if (sym.assignment_to) {
                            definite_initializations.push_back( sym.identifier );
                        }
                        else {
                            errors.emplace_back( 
                                sym.identifier->position(), 
                                "local variable " + sym.identifier->to_string(true)
                                    + " is used in a branch before it was initialized");
                        }
                        selection_stack.back().branches.back().result = sym.assignment_to;

                        //  The depth of this branch should always be the depth of
                        //  the current selection statement + 1
                        int branch_depth = symbols[selection_stack.back().pos].depth + 1;
                        while (symbols[pos + 1].depth > branch_depth) {
                            ++pos;
                        }
                    }

                }
            }

            break;case selection: {
                auto const& sym = std::get<selection>(symbols[pos].sym);

                //  If we're starting a new selection statement, add a stack entry for it
                if (sym.start) {
                    selection_stack.emplace_back( pos );
                }

                //  If we're ending a selection statement, look at the partial results --
                //  they must all be false or all true, if they're a mix we are missing
                //  initializations on some path(s)
                else {
                    assert (std::ssize(selection_stack) > 0);
                    // selection_stack.back().debug_print(std::cout);

                    auto true_branches  = std::string{};
                    auto false_branches = std::string{};
                    for (auto const& b : selection_stack.back().branches)
                    {
                        //  If this is not an implicit 'else' branch (i.e., if lineno > 0)
                        if (symbols[b.start].position().lineno > 0) {
                            (b.result ? true_branches : false_branches)
                                += "\n  branch starting at line " 
                                    + std::to_string(symbols[b.start].position().lineno);
                        }
                        else {
                            (b.result ? true_branches : false_branches)
                                += "\n  implicit else branch";
                        }
                    }
                    
                    //  If none of the branches was true
                    if (true_branches.length() == 0)
                    {
                        selection_stack.pop_back();
                        //  Nothing else to do, just continue
                    }

                    //  Else if all of the branches were true
                    else if (false_branches.length() == 0)
                    {
                        //  If this is a top-level selection statement, handle it the same as
                        //  if we weren't an a selection statement
                        if (std::ssize(selection_stack) == 1) {
                            return true;
                        }
                        //  Else pop this selection statement, and record this as the result
                        //  of the next outer selection statement's current branch
                        else {
                            selection_stack.pop_back();
                            assert (std::ssize(selection_stack.back().branches) > 0);
                            selection_stack.back().branches.back().result = true;

                            //  And skip the rest of this branch
                            auto skip_depth = symbols[pos].depth - 1;
                            while (symbols[pos + 1].depth >= skip_depth) {
                                ++pos;
                            }
                        }
                    }

                    //  Else we found a missing initializion, report it and return false
                    else
                    {
                        errors.emplace_back( 
                            id->position(), 
                            "local variable " + id->to_string(true)
                                + " is not initialized on all paths");
                        
                        assert (symbols[selection_stack.back().pos].sym.index() == selection);
                        auto const& sym = std::get<selection>(symbols[pos].sym);
                        errors.emplace_back( 
                            sym.selection->identifier->position(),
                            "\"" + sym.selection->identifier->to_string(true)
                                + "\" initializes " + id->to_string(true) 
                                + " on:" + true_branches
                                + "\nbut not on:" + false_branches
                        );

                        return false;
                    }

                }
            }

            break;case compound: {
                auto const& sym = std::get<compound>(symbols[pos].sym);

                //  If we're in a selection 
                if (std::ssize(selection_stack) > 0) {
                    //  If this is a compound start with the current selection's depth
                    //  plus one, it's the start of one of the branches of that selection
                    if (sym.start && 
                        symbols[pos].depth == symbols[selection_stack.back().pos].depth+1
                        )
                    {
                        selection_stack.back().branches.emplace_back( pos, false );
                    }
                }
            }

            break;default:
                assert (!"illegal symbol");
            }

        }

        errors.emplace_back( 
            id->position(), 
            id->to_string(true) 
            + " - variable is not initialized on every path");
        return false;
    }


public:
    //-----------------------------------------------------------------------
    //  Visitor functions
    //
    int  scope_depth = 0;
    bool started_assignment_expression = false;
    expression_list_node::term const* current_expression_list_term = nullptr;
    bool is_out_expression = false;

    auto start(expression_node const& n, int indent) -> void
    {
        is_out_expression = false;

        //  If we are in an expression-list, remember whether this is an `out`
        if (current_expression_list_term) {
            if (current_expression_list_term->pass == passing_style::out) {
                is_out_expression = true;
            }
            ++current_expression_list_term;
        }
    }

    auto start(expression_list_node const& n, int indent) -> void
    {
        //  We're going to use the pointer as an iterator
        current_expression_list_term = &n.expressions[0];
    }

    auto end(expression_list_node const& n, int indent) -> void
    {
        //  Unlike debug_print, here we don't assert that we visited all the
        //  expressions in the list because visiting them all is not always needed
        current_expression_list_term = nullptr;
    }

    auto start(declaration_node const& n, int) -> void
    {
        //  We're starting a new declaration, so there shouldn't be a
        //  partial one for which we haven't visited the identifier yet
        assert (!partial.declaration);
        partial = { true, &n, nullptr, n.initializer.get() };
    }

    auto end(declaration_node const& n, int) -> void
    {
        symbols.emplace_back( scope_depth, declaration_sym( false, &n, nullptr, nullptr ) );
        if (n.type.index() != variable) {
            --scope_depth;
        }
    }

    auto start(token const& t, int) -> void
    {
        //  We currently only care to look at identifiers
        if (t.type() != lexeme::Identifier) {
            return;
        }

        //  If this is the first identifier since we started a new decl,
        //  then it's the declaration's identifier name, so finish
        //  recognizing the decl and store it now that we have all the info
        if (partial.declaration)
        {
            partial.identifier = &t;
            symbols.emplace_back( scope_depth, partial );

            assert (partial.declaration);
            if (!partial.declaration->is(variable)) {
                ++scope_depth;
            }

            partial = {};
        }

        //  If this is the first identifier since we started a new assignment,
        //  expression, then it's the left-hand side (target) of the assignment
        else if (started_assignment_expression)
        {
            symbols.emplace_back( scope_depth, identifier_sym( true, &t ) );
            started_assignment_expression = false;
        }

        //  If this is the first identifier since we saw an `out` expression,
        //  then it's the argument of the `out` expression
        //  TODO: for now we just take the first identifier, and we should make
        //  this an id-expression and add a sema rule to disallow complex expressions
        else if (is_out_expression)
        {
            symbols.emplace_back( scope_depth, identifier_sym( true, &t ) );
            is_out_expression = false;
        }

        //  Otherwise it's just an identifier use
        else
        {
            symbols.emplace_back( scope_depth, identifier_sym( false, &t ) );
        }
    }

    auto start(selection_statement_node const& n, int) -> void
    {
        active_selections.push_back( &n );
        symbols.emplace_back( scope_depth, selection_sym{ true, active_selections.back() } );
        ++scope_depth;
    }

    auto end(selection_statement_node const& n, int) -> void
    {
        symbols.emplace_back( scope_depth, selection_sym{ false, active_selections.back() } );
        active_selections.pop_back();
        --scope_depth;
    }

    auto start(compound_statement_node const& n, int) -> void
    {
        if (!active_selections.empty()) {
            assert (active_selections.back());
            if (active_selections.back()->true_branch.get() == &n) {
                symbols.emplace_back( scope_depth, compound_sym{ true, &n, true } );
            }
            else if (active_selections.back()->false_branch.get() == &n) {
                symbols.emplace_back( scope_depth, compound_sym{ true, &n, false } );
            }
        }
        ++scope_depth;
    }

    auto end(compound_statement_node const& n, int) -> void
    {
        if (!active_selections.empty()) {
            assert (active_selections.back());
            if (active_selections.back()->true_branch.get() == &n) {
                symbols.emplace_back( scope_depth, compound_sym{ false, &n, true } );
            }
            else if (active_selections.back()->false_branch.get() == &n) {
                symbols.emplace_back( scope_depth, compound_sym{ false, &n, false } );
            }
        }
        --scope_depth;
    }

    auto start(assignment_expression_node const& n, int) {
        if (std::ssize(n.terms) > 0) {
            assert (n.terms.front().op);
            if (n.terms.front().op->type() == lexeme::Assignment) {
                started_assignment_expression = true;
            }
        }
    }

    auto start(auto const&, int indent) -> void
    {
        //  Ignore other node types
    }

    auto end(auto const&, int indent) -> void
    {
        //  Ignore other node types
    }
};


}

#endif
