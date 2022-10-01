
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


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
    declaration_node const*           declaration = nullptr;
    token const*                      identifier  = nullptr;
    statement_node const*             initializer = nullptr;
    parameter_declaration_node const* parameter = nullptr;

    declaration_sym(
        bool s = false,
        declaration_node const*           decl  = nullptr,
        token const*                      id    = nullptr,
        statement_node const*             init  = nullptr,
        parameter_declaration_node const* param = nullptr
    )
        : start{s}
        , declaration{decl}
        , identifier{id}
        , initializer{init}
        , parameter{param}
    { }

    auto position() const -> source_position
    {
        assert (declaration);
        return declaration->position();
    }
};

struct identifier_sym {
    bool assignment_to = false;
    token const* identifier = nullptr;

    identifier_sym(bool a, token const* id) : assignment_to{a}, identifier{id} { }

    auto position() const -> source_position
    {
        assert (identifier);
        return identifier->position();
    }
};

struct selection_sym {
    bool start = false;
    selection_statement_node const* selection = nullptr;

    selection_sym(bool s, selection_statement_node const* sel) : start{s}, selection{sel} { }

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

    compound_sym(bool s, compound_statement_node const* c, bool is_true)
        : start{s}, compound{c}, is_true_branch{is_true}
    { }

    auto position() const -> source_position
    {
        assert (compound);
        return compound->position();
    }
};

struct symbol {
    int  depth = -1;

    enum active { declaration=0, identifier, selection, compound };
    std::variant <
        declaration_sym,
        identifier_sym,
        selection_sym,
        compound_sym
    > sym;

    bool start = true;

    symbol(int depth, declaration_sym const& sym) : depth{depth}, sym{sym}, start{sym.start} { }
    symbol(int depth, identifier_sym  const& sym) : depth{depth}, sym{sym}                   { }
    symbol(int depth, selection_sym   const& sym) : depth{depth}, sym{sym}, start{sym.start} { }
    symbol(int depth, compound_sym    const& sym) : depth{depth}, sym{sym}, start{sym.start} { }

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


//  Keep a list of all token*'s found that are definite last uses
//  for a local variable or copy or forward parameter x, which we
//  will rewrite to move or forward from the variable.
//
struct last_use {
    token const* t;
    bool is_forward;
    last_use( token const* t_, bool is_forward_ = false ) : t{t_}, is_forward{is_forward_} { }
    bool operator==(last_use const& that) { return t == that.t; }
};
std::vector<last_use> definite_last_uses;

auto is_definite_last_use(token const* t) -> last_use const*
{
    auto iter = std::find(
            definite_last_uses.begin(),
            definite_last_uses.end(),
            t
            );
    if (iter != definite_last_uses.end()) {
        return &*iter;
    }
    else {
        return {};
    }
}


//-----------------------------------------------------------------------
//
//  sema: Semantic analysis
//
//-----------------------------------------------------------------------
//
class sema
{
    //using enum declaration_node::active;
    //using enum symbol::active;

public:
    std::vector<error>&          errors;
    std::vector<symbol>          symbols;
    std::vector<declaration_sym> partial_decl_stack;;

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


    auto get_declaration_of(token const& t) -> declaration_sym const*
    {
        //  First find the position the query is coming from
        //  and remember its depth
        auto i = symbols.cbegin();
        while (i != symbols.cend() && i->position() < t.position()) {
            ++i;
        }

        while (i == symbols.cend() || !i->start) {
            --i;
        }

        auto depth = i->depth;

        //  Then look backward to find the first declaration of
        //  this name that is not deeper (in a nested scope)
        for ( ; i != symbols.cbegin(); --i ) {
            if (i->sym.index() == symbol::active::declaration && i->depth <= depth) {
                auto const& decl = std::get<symbol::active::declaration>(i->sym);
                if (decl.identifier && *decl.identifier == t) {
                    return &decl;
                }
            }
        }

        return nullptr;
    }


    void debug_print(std::ostream& o)
    {
        for (auto const& s : symbols)
        {
            o << std::setw(3) << s.depth << " |";
            o << std::setw(s.depth*2+1) << " ";

            switch (s.sym.index()) {

            break;case symbol::active::declaration: {
                auto const& sym = std::get<symbol::active::declaration>(s.sym);

                assert (sym.declaration);
                if (sym.declaration->is(declaration_node::active::function)) {
                    if (sym.start) {
                        o << "function ";
                    }
                    else {
                        o << "/function";
                    }
                }
                else if (sym.declaration->is(declaration_node::active::object)) {
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

                if (sym.start && !(sym.parameter && sym.parameter->pass != passing_style::out) && !sym.initializer) {
                    o << " *** UNINITIALIZED";
                }
            }

            break;case symbol::active::identifier: {
                auto const& sym = std::get<symbol::active::identifier>(s.sym);
                assert (sym.identifier);
                if (auto use = is_definite_last_use(sym.identifier)) {
                    o << "*** " << sym.identifier->position().to_string()
                      << " DEFINITE LAST "
                      << (use->is_forward ? "FORWARDING" : "POTENTIALLY MOVING")
                      << "USE OF ";
                }

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

            break;case symbol::active::selection: {
                auto const& sym = std::get<symbol::active::selection>(s.sym);
                if (!sym.start) {
                    o << "/";
                }
                o << "selection";
            }

            break;case symbol::active::compound: {
                auto const& sym = std::get<symbol::active::compound>(s.sym);
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

        //-----------------------------------------------------------------------
        //  Helpers for readability

        //  It's an uninitialized variable (incl. named return values) if it's
        //  a variable with no initializer and that isn't a parameter
        //
        auto is_uninitialized_variable_decl = [&](symbol const& s)
            -> declaration_sym const*
        {
            if (auto const* sym = std::get_if<symbol::active::declaration>(&s.sym)) {
                assert (sym);
                if (sym->start && !sym->initializer && !(sym->parameter && sym->parameter->pass != passing_style::out)) {
                    assert (sym->declaration->is(declaration_node::active::object));
                    return sym;
                }
            }
            return {};
        };

        //  It's a local (incl. named return value or copy or move or forward parameter)
        //
        auto is_potentially_movable_local = [&](symbol const& s)
            -> declaration_sym const*
        {
            if (auto const* sym = std::get_if<symbol::active::declaration>(&s.sym)) {
                if (sym->start && sym->declaration->is(declaration_node::active::object) &&
                    sym->parameter &&
                        (sym->parameter->pass == passing_style::copy ||
                         sym->parameter->pass == passing_style::move ||
                         sym->parameter->pass == passing_style::forward
                        )
                    )
                    // TODO: Extend move-from-last-use to locals once we can reliably detect rvalue-friendly contexts
                    //(!sym->parameter || sym->parameter->pass == passing_style::copy || sym->parameter->pass == passing_style::move))
                {
                    return sym;
                }
            }
            return {};
        };

        //-----------------------------------------------------------------------
        //  Function logic: For each entry in the table...
        //
        for (auto sympos = std::ssize(symbols) - 1; sympos >= 0; --sympos)
        {
            //  If this is an uninitialized local variable,
            //  ensure it is definitely initialized and tag those initializations
            //
            if (auto decl = is_uninitialized_variable_decl(symbols[sympos])) {
                assert (decl->identifier && !decl->initializer);
                ret = ret &&
                    ensure_definitely_initialized(decl->identifier, sympos+1, symbols[sympos].depth);
            }

            //  If this is a copy, move, or forward parameter or a local variable,
            //  identify and tag its definite last uses to `std::move` from them
            //
            if (auto decl = is_potentially_movable_local(symbols[sympos])) {
                assert (decl->identifier);
                find_definite_last_uses(decl->identifier, sympos, decl->parameter->pass == passing_style::forward);
            }
        }

        return ret;
    }

private:
    //  Find the definite last uses for local variable *id starting at the
    //  given position and depth in the symbol/scope table
    //
    auto find_definite_last_uses(token const* id, int pos, bool is_forward) const -> void
    {
        auto i = pos;
        auto depth = symbols[pos].depth;

        //  Maintain a stack of the depths of the most recently seen
        //  selection statements, using the current depth-2 as a sentinel
        auto selections = std::vector<int>{depth-2};

        //  Scan forward to the end of this scope, keeping track of
        //  the trailing nest of selection statements
        while (i+1 < std::ssize(symbols) && symbols[i+1].depth >= depth)
        {
            assert (std::ssize(symbols) > 1);
            if (symbols[i].sym.index() == symbol::selection) {
                auto const& s = std::get<symbol::selection>(symbols[i].sym);
                if (s.start) {
                    selections.push_back(symbols[i].depth);
                }
                //else {
                //    assert (symbols[i].depth-1 == selections.back());
                //    selections.pop_back();
                //}
            }
            ++i;
        }

        //  i is now at the end of id's scope, so start scanning backwards
        //  until we find the first definite last use
        for (auto found = false; i > pos; --i)
        {
            //  Once we find something, don't continue back further
            //  than the closest enclosing selection statement
            if (found && symbols[i].depth <= selections.back()) {
                break;
            }

            if (symbols[i].sym.index() == symbol::active::identifier)
            {
                auto const& sym = std::get<symbol::active::identifier>(symbols[i].sym);
                assert (sym.identifier);

                //  If we find a use of this identifier
                if (*sym.identifier == *id) {
                    definite_last_uses.emplace_back( sym.identifier, is_forward );
                    found = true;

                    //  Pop any of the last branches that we're outside of
                    while (symbols[i].depth <= selections.back()) {
                        selections.pop_back();
                        assert (!selections.empty());   // won't remove sentinel
                    }
                    //  Then skip over the earlier part of the current branch
                    while (i > pos && symbols[i].depth > selections.back() + 1) {
                        --i;
                    }
                }
            }
        }
    }


    //  Check that local variable *id is initialized before use on all paths
    //  starting at the given position and depth in the symbol/scope table
    //
    //  TODO: After writing the first version of this, I realized that it could be
    //        simplified a lot by using a sentinel value to represent the base case like
    //        the others instead of as a special case. It's tempting to rewrite this now
    //        to do that cleanup, but the code is working and fully localized, so
    //        rewriting it wouldn't give any benefit, and I need to resist the urge to
    //        be distracted by goldplating when I could be implementing a new feature.
    //
    auto ensure_definitely_initialized(token const* id, int pos, int depth) const -> bool
    {
        struct stack_entry{
            int pos;    // start of this selection statement

            struct branch {
                int  start;
                bool result = false;

                branch(int s, bool r) : start{s}, result{r} { }
            };
            std::vector<branch> branches;

            stack_entry(int p) : pos{p} { }

            auto debug_print(std::ostream& o) const -> void
            {
                o << "Stack entry: " << pos << "\n";
                for (auto const& e : branches) {
                    o << "  ( " << e.start << " , " << e.result << " )\n";
                }
            }
        };
        std::vector<stack_entry> selection_stack;

        for ( ; pos < std::ssize(symbols) && symbols[pos].depth >= depth; ++pos) {
            switch (symbols[pos].sym.index()) {

            break;case symbol::active::declaration: {
                auto const& sym = std::get<symbol::active::declaration>(symbols[pos].sym);
                if (sym.start && sym.identifier && *sym.identifier == *id) {
                    errors.emplace_back(
                        sym.identifier->position(),
                        "local variable" + sym.identifier->to_string(true)
                            + " cannot have the same name as an uninitialized"
                              " variable in the same function");
                }
            }

            break;case symbol::active::identifier: {
                auto const& sym = std::get<symbol::active::identifier>(symbols[pos].sym);
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
                                    + " is used before it was initialized");
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

            break;case symbol::active::selection: {
                auto const& sym = std::get<symbol::active::selection>(symbols[pos].sym);

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
                                    + " must be initialized on both branches or neither branch");

                        assert (symbols[selection_stack.back().pos].sym.index() == symbol::active::selection);
                        auto const& sym = std::get<symbol::active::selection>(symbols[pos].sym);
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

            break;case symbol::active::compound: {
                auto const& sym = std::get<symbol::active::compound>(symbols[pos].sym);

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
            + " - variable must be initialized on every branch path");
        return false;
    }


public:
    //-----------------------------------------------------------------------
    //  Visitor functions
    //
    int  scope_depth = 0;
    bool started_assignment_expression = false;
    std::vector<expression_list_node::term const*> current_expression_list_term = {};
    bool is_out_expression     = false;
    bool inside_parameter_list = false;
    bool inside_returns_list   = false;
    parameter_declaration_node const* inside_out_parameter = {};

    auto start(parameter_declaration_list_node const&, int) -> void {
        inside_parameter_list = true;
    }

    auto end(parameter_declaration_list_node const&, int) -> void {
        inside_parameter_list = false;
    }

    auto start(parameter_declaration_node const& n, int) -> void {
        if (
            (!inside_returns_list && n.pass == passing_style::out) ||
            ( inside_returns_list && n.pass == passing_style::out && !n.declaration->initializer)
        )
        {
            inside_out_parameter = &n;
        }

        if (n.pass == passing_style::copy || n.pass == passing_style::move || n.pass == passing_style::forward)
        {
            symbols.emplace_back( scope_depth, declaration_sym( true, n.declaration.get(), n.declaration->identifier->identifier, n.declaration->initializer.get(), &n));
        }
    }

    auto end(parameter_declaration_node const&, int) -> void {
        inside_out_parameter = {};
    }

    auto start(expression_node const& n, int indent) -> void
    {
        is_out_expression = false;

        //  If we are in an expression-list, remember whether this is an `out`
        if (!current_expression_list_term.empty()) {
            if (current_expression_list_term.back()->pass == passing_style::out) {
                is_out_expression = true;
            }
            ++current_expression_list_term.back();
        }
    }

    auto start(expression_list_node const& n, int indent) -> void
    {
        //  We're going to use the pointer as an iterator
        if (!n.expressions.empty()) {
            current_expression_list_term.push_back( &n.expressions[0] );
        }
        else {
            current_expression_list_term.push_back( nullptr );
        }
    }

    auto end(expression_list_node const& n, int indent) -> void
    {
        //  Unlike debug_print, here we don't assert that we visited all the
        //  expressions in the list because visiting them all is not always needed
        current_expression_list_term.pop_back();
    }

    auto start(function_returns_tag const&, int) -> void
    {
        inside_returns_list = true;
    }

    auto end(function_returns_tag const&, int) -> void
    {
        inside_returns_list = false;
    }

    auto start(declaration_node const& n, int) -> void
    {
        if (!inside_parameter_list || inside_out_parameter) {
            partial_decl_stack.emplace_back(true, &n, nullptr, n.initializer.get(), inside_out_parameter);
        }
    }

    auto end(declaration_node const& n, int) -> void
    {
        if (!inside_parameter_list || inside_out_parameter) {
            symbols.emplace_back( scope_depth, declaration_sym( false, &n, nullptr, nullptr, inside_out_parameter ) );
            if (n.type.index() != declaration_node::active::object) {
                --scope_depth;
            }
            partial_decl_stack.pop_back();
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
        if (!partial_decl_stack.empty() && !partial_decl_stack.back().identifier)
        {
            partial_decl_stack.back().identifier = &t;
            symbols.emplace_back( scope_depth, partial_decl_stack.back() );

            assert (partial_decl_stack.back().declaration);
            if (!partial_decl_stack.back().declaration->is(declaration_node::active::object)) {
                ++scope_depth;
            }
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

        //  Otherwise it's just an identifier use (if it's outside the parameter list)
        else if (!inside_parameter_list)
        {
            //  Put this into the table if it's a use of an object in scope
            //  or it's a 'copy' parameter
            if (auto decl = get_declaration_of(t);
                decl
                )
            {
                symbols.emplace_back( scope_depth, identifier_sym( false, &t ) );
            }
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
