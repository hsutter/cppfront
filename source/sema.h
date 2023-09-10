
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

#include "reflect.h"


namespace cpp2 {

//-----------------------------------------------------------------------
//
//  Symbol/scope table
//
//-----------------------------------------------------------------------
//
struct declaration_sym {
    bool                              start       = false;
    declaration_node const*           declaration = {};
    token const*                      identifier  = {};
    statement_node const*             initializer = {};
    parameter_declaration_node const* parameter   = {};
    bool                              member      = false;

    declaration_sym(
        bool                              s     = false,
        declaration_node const*           decl  = {},
        token const*                      id    = {},
        statement_node const*             init  = {},
        parameter_declaration_node const* param = {},
        bool                              mem   = false
    )
        : start{s}
        , declaration{decl}
        , identifier{id}
        , initializer{init}
        , parameter{param}
        , member{mem}
    { }

    auto position() const
        -> source_position
    {
        assert (declaration);
        return declaration->position();
    }
};

struct identifier_sym {
    bool standalone_assignment_to = false;
    token const* identifier = {};

    identifier_sym(
        bool         a,
        token const* id
    )
        : standalone_assignment_to{a}
        , identifier{id}
    { }

    auto position() const
        -> source_position
    {
        assert (identifier);
        return identifier->position();
    }
};

struct selection_sym {
    bool start = false;
    selection_statement_node const* selection = {};

    selection_sym(
        bool                            s,
        selection_statement_node const* sel
    )
        : start{s}
        , selection{sel}
    { }

    auto position() const
        -> source_position
    {
        assert (selection);
        return selection->position();
    }
};

struct compound_sym {
    bool start = false;
    compound_statement_node const* compound = {};
    enum kind { is_scope, is_true, is_false } kind_ = is_scope;

    compound_sym(
        bool                           s,
        compound_statement_node const* c,
        kind                           k
    )
        : start{s}
        , compound{c}
        , kind_{k}
    { }

    auto position() const
        -> source_position
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

    auto position() const
        -> source_position
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

auto is_definite_initialization(token const* t)
    -> bool
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
    bool         is_forward;

    last_use(
        token const* t_,
        bool         is_forward_ = false
    )
        : t{t_}
        , is_forward{is_forward_}
    { }

    bool operator==(last_use const& that) { return t == that.t; }
};
std::vector<last_use> definite_last_uses;

auto is_definite_last_use(token const* t)
    -> last_use const*
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
public:
    std::vector<error_entry>& errors;
    std::vector<symbol>       symbols;

    std::vector<selection_statement_node const*> active_selections;

public:
    //-----------------------------------------------------------------------
    //  Constructor
    //
    //  errors      error list
    //
    sema(
        std::vector<error_entry>& errors_
    )
        : errors{ errors_ }
    {
    }

    //  Get the declaration of t within the same named function or beyond it
    //
    auto get_declaration_of(
        token const* t,
        bool         look_beyond_current_function = false
    )
        -> declaration_sym const*
    {
        if (!t) {
            return {};
        }
        return get_declaration_of(*t, look_beyond_current_function);
    }

    auto get_declaration_of(
        token const& t,
        bool         look_beyond_current_function = false
    )
        -> declaration_sym const*
    {
        //  First find the position the query is coming from
        //  and remember its depth
        auto i = symbols.cbegin();
        while (
            i != symbols.cend()
            && i->position() < t.position()
            )
        {
            ++i;
        }

        while (
            i == symbols.cend()
            || !i->start
            )
        {
            if (i == symbols.cbegin()) {
                return nullptr;
            }
            --i;
        }

        auto depth = i->depth;

        //  Then look backward to find the first declaration of
        //  this name that is not deeper (in a nested scope)
        //  and is in the same function
        for (auto ri = std::make_reverse_iterator(i+1); ri != symbols.crend(); ++ri )
        {
            if (
                ri->sym.index() == symbol::active::declaration
                && ri->depth <= depth
                )
            {
                auto const& decl = std::get<symbol::active::declaration>(ri->sym);

                //  Conditionally look beyond the start of the current named (has identifier) function
                //  (an unnamed function is ok to look beyond)
                assert(decl.declaration);
                if (
                    decl.declaration->type.index() == declaration_node::a_function
                    && decl.declaration->identifier
                    && !look_beyond_current_function
                    )
                {
                    return nullptr;
                }

                //  If the name matches, this is it
                if (
                    decl.identifier
                    && *decl.identifier == t
                    )
                {
                    return &decl;
                }
                depth = ri->depth;
            }
        }

        return nullptr;
    }


    //-----------------------------------------------------------------------
    //  Factor out the uninitialized var decl test
    //
    auto is_uninitialized_decl(declaration_sym const& sym)
        -> bool
    {
        return
            sym.start
            && !(sym.identifier && *sym.identifier == "this")
            && !sym.initializer
            && !(sym.parameter && sym.parameter->pass != passing_style::out)
            ;
    }


    auto debug_print(std::ostream& o)
        -> void
    {
        for (auto const& s : symbols)
        {
            o << std::setw(3) << s.depth << " |";
            o << std::setw(s.depth*2+1) << " ";

            switch (s.sym.index()) {

            break;case symbol::active::declaration: {
                auto const& sym = std::get<symbol::active::declaration>(s.sym);

                assert (sym.declaration);
                if (sym.declaration->is_function()) {
                    if (sym.start) {
                        o << "function ";
                    }
                    else {
                        o << "/function";
                    }
                }
                else if (sym.declaration->is_object()) {
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

                if (is_uninitialized_decl(sym)) {
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
                      << " USE OF ";
                }

                if (is_definite_initialization(sym.identifier)) {
                    o << "*** " << sym.identifier->position().to_string()
                      << " DEFINITE INITIALIZATION OF ";
                }
                else if (sym.standalone_assignment_to) {
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
                if (sym.kind_ == sym.is_true) {
                    o << "true branch";
                }
                else if (sym.kind_ == sym.is_false) {
                    o << "false branch";
                }
                else {
                    o << "scope";
                }

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
    auto apply_local_rules()
        -> bool
    {
        auto ret = true;

        //-----------------------------------------------------------------------
        //  Helpers for readability

        //  It's an uninitialized variable (incl. named return values) if it's
        //  a non-namespace-scope non-parameter object with no initializer
        //
        auto is_uninitialized_variable_decl = [&](symbol const& s)
            -> declaration_sym const*
        {
            if (auto const* sym = std::get_if<symbol::active::declaration>(&s.sym)) {
                assert (sym);
                if (is_uninitialized_decl(*sym)) {
                    if (
                        sym->declaration->is_object()
                        && !sym->declaration->parent_is_namespace()
                        )
                    {
                        return sym;
                    }
                    else {
                        return {};
                    }
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
                if (
                    sym->start
                    && sym->declaration->is_object()
                    && (!sym->parameter
                        || sym->parameter->pass == passing_style::copy
                        || sym->parameter->pass == passing_style::move
                        || sym->parameter->pass == passing_style::forward
                        )
                    )
                {
                    //  Must be in function scope
                    if (
                        sym->declaration->parent_declaration
                        && sym->declaration->parent_declaration->is_function()
                        )
                    {
                        return sym;
                    }
                    else {
                        return {};
                    }
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
                assert(
                    decl->identifier
                    && !decl->initializer
                );
                ret = ret
                    && ensure_definitely_initialized(decl, sympos+1, symbols[sympos].depth)
                    ;
            }

            //  If this is a copy, move, or forward parameter or a local variable,
            //  identify and tag its definite last uses to `std::move` from them
            //
            if (auto decl = is_potentially_movable_local(symbols[sympos])) {
                assert (decl->identifier);
                find_definite_last_uses(
                    decl->identifier,
                    sympos,
                    decl->parameter && decl->parameter->pass == passing_style::forward
                );
            }
        }

        return ret;
    }

private:
    //  Find the definite last uses for local variable *id starting at the
    //  given position and depth in the symbol/scope table
    //
    auto find_definite_last_uses(
        token const* id,
        int          pos,
        bool         is_forward
    ) const
        -> void
    {
        auto i = pos;
        auto depth = symbols[pos].depth;

        //  Maintain a stack of the depths of the most recently seen
        //  selection statements, using the current depth-2 as a sentinel
        auto selections = std::vector<int>{depth-2};

        //  Scan forward to the end of this scope, keeping track of
        //  the trailing nest of selection statements
        while (
            i+1 < std::ssize(symbols)
            && symbols[i+1].depth >= depth
            )
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
            if (
                found
                && symbols[i].depth <= selections.back()
                )
            {
                break;
            }

            if (symbols[i].sym.index() == symbol::active::identifier)
            {
                auto const& sym = std::get<symbol::active::identifier>(symbols[i].sym);
                assert (sym.identifier);

                //  If we find a use of this identifier
                if (*sym.identifier == *id)
                {
                    if (
                        !found
                        || symbols[i].depth > selections.back()+1
                        )
                    {
                        definite_last_uses.emplace_back( sym.identifier, is_forward );
                        found = true;
                    }

                    //  Pop any of the last branches that we're outside of
                    while (symbols[i].depth <= selections.back()) {
                        selections.pop_back();
                        assert (!selections.empty());   // won't remove sentinel
                    }
                    //  Then skip over the earlier part of the current branch
                    while (
                        i > pos
                        && symbols[i].depth > selections.back() + 1
                        )
                    {
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
    auto ensure_definitely_initialized(
        declaration_sym const* decl,
        int                    pos,
        int                    depth
    ) const
        -> bool
    {
        //  If this is a member variable in a constructor, the name doesn't
        //  appear lexically right in the constructor, so prepending "this."
        //  to the printed name might make the error more readable to the programmer
        auto name = decl->identifier->to_string(true);
        if (decl->declaration->parent_is_type()) {
            name += " (aka this." + name + ")";
        }

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

        for (
            ;
            pos < std::ssize(symbols) && symbols[pos].depth >= depth;
            ++pos
            )
        {
            switch (symbols[pos].sym.index()) {

            break;case symbol::active::declaration: {
                auto const& sym = std::get<symbol::active::declaration>(symbols[pos].sym);
                if (
                    sym.start
                    && sym.identifier
                    && *sym.identifier == *decl->identifier
                    )
                {
                    errors.emplace_back(
                        sym.identifier->position(),
                        "local variable " + sym.identifier->to_string(true)
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
                        "local variable " + name
                            + " must be initialized before " + sym.identifier->to_string(true)
                            + " (local variables must be initialized in the order they are declared)"
                    );
                    return false;
                }

                //  If we find a use of this identifier
                if (*sym.identifier == *decl->identifier) {

                    //  If we're not inside a selection statement, we're at the top level --
                    //  just return true if it's an assignment to it, else return false
                    if (std::ssize(selection_stack) == 0) {
                        if (sym.standalone_assignment_to) {
                            definite_initializations.push_back( sym.identifier );
                        }
                        else {
                            errors.emplace_back(
                                sym.identifier->position(),
                                "local variable " + name
                                    + " is used before it was initialized");
                        }
                        return sym.standalone_assignment_to;
                    }

                    //  Else if we're inside a selection statement but still in the condition
                    //  portion (there are no branches entered yet)
                    else if (std::ssize(selection_stack.back().branches) == 0) {
                        //  If this is a top-level selection statement, handle it the same as
                        //  if we weren't an a selection statement
                        if (std::ssize(selection_stack) == 1) {
                            if (sym.standalone_assignment_to) {
                                definite_initializations.push_back( sym.identifier );
                            }
                            else {
                                errors.emplace_back(
                                    sym.identifier->position(),
                                    "local variable " + name
                                        + " is used in a condition before it was initialized");
                            }
                            return sym.standalone_assignment_to;
                        }
                        //  Else we can skip the rest of this selection statement, and record
                        //  this as the result of the next outer selection statement's current branch
                        else {
                            selection_stack.pop_back();
                            assert (std::ssize(selection_stack.back().branches) > 0);
                            selection_stack.back().branches.back().result = sym.standalone_assignment_to;

                            int this_depth = symbols[pos].depth;
                            while (symbols[pos + 1].depth >= this_depth) {
                                ++pos;
                            }
                        }
                    }

                    //  Else we're in a selection branch and can skip the rest of this branch
                    //  and record this as the result for the current branch
                    else {
                        if (sym.standalone_assignment_to) {
                            definite_initializations.push_back( sym.identifier );
                        }
                        else {
                            errors.emplace_back(
                                sym.identifier->position(),
                                "local variable " + name
                                    + " is used in a branch before it was initialized");
                        }
                        selection_stack.back().branches.back().result = sym.standalone_assignment_to;

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
                            decl->identifier->position(),
                            "local variable " + name
                                    + " must be initialized on both branches or neither branch");

                        assert (symbols[selection_stack.back().pos].sym.index() == symbol::active::selection);
                        auto const& sym = std::get<symbol::active::selection>(symbols[pos].sym);
                        errors.emplace_back(
                            sym.selection->identifier->position(),
                            "\"" + sym.selection->identifier->to_string(true)
                                + "\" initializes " + name
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
                    if (
                        sym.start
                        && symbols[pos].depth == symbols[selection_stack.back().pos].depth+1
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
            decl->identifier->position(),
            name
            + " - variable must be initialized on every branch path");
        return false;
    }


public:
    //-----------------------------------------------------------------------
    //  Per-node sema rules
    //

    auto check(qualified_id_node const& n)
    {
        //  Check for some incorrect uses of .
        if (auto decl = get_declaration_of(n.get_first_token(), true);
            decl && std::ssize(n.ids) > 1
            )
        {
            assert (decl->declaration);

            if (
                decl->declaration->is_object()
                && n.ids[1].scope_op
                && n.ids[1].scope_op->type() == lexeme::Scope
                )
            {
                errors.emplace_back(
                    n.position(),
                    "use '" + decl->identifier->to_string(true) + ".' to refer to an object member"
                );
                return false;
            }
        }

        return true;
    }


    auto check(postfix_expression_node const& n)
    {
        //  Check for some incorrect uses of :: or .
        if (auto decl = get_declaration_of(n.get_first_token_ignoring_this(), true);
            decl && !n.ops.empty()
            )
        {
            assert (decl->declaration);

            if (
                decl->declaration->is_type()
                && n.ops[0].op
                && n.ops[0].op->type() == lexeme::Dot
                )
            {
                errors.emplace_back(
                    n.position(),
                    "use '" + decl->identifier->to_string(true) + "::' to refer to a type member"
                );
                return false;
            }
        }

        return true;
    }


    auto check(declaration_node const& n)
        -> bool
    {
        //  An object of deduced type must have an initializer
        if (
            n.is_object()
            && n.has_wildcard_type()
            && !n.has_initializer()
            )
        {
            errors.emplace_back(
                n.position(),
                "an object with a deduced type must have an = initializer"
            );
            return false;
        }

        //  An object initializer must be an expression
        if (
            n.is_object()
            && n.initializer
            && !n.initializer->is_expression()
            )
        {
            errors.emplace_back(
                n.position(),
                "an object initializer must be an expression"
            );
            return false;
        }

        //  A type initializer must be a compound expression
        if (
            n.is_type()
            && n.initializer
            && !n.initializer->is_compound()
            )
        {
            errors.emplace_back(
                n.position(),
                "a user-defined type initializer must be a compound-expression consisting of declarations"
            );
            return false;
        }

        //  A namespace must be initialized with a compound expression
        if (
            n.is_namespace()
            && (
                !n.initializer
                || !n.initializer->is_compound()
                )
            )
        {
            errors.emplace_back(
                n.position(),
                "a namespace must be = initialized with a { } body containing declarations"
            );
            return false;
        }

        //  A function body must be an expression-statement or a compound-statement
        if (
            n.is_function()
            && n.initializer
            && n.initializer->is_return()
            )
        {
            errors.emplace_back(
                n.position(),
                "a function with a single-expression body doesn't need to say 'return' - either omit 'return' or write a full { }-enclosed function body"
            );
            return false;
        }

        //  A nonvirtual and nondefaultable function must have an initializer
        if (
            n.is_function()
            && !n.is_virtual_function()
            && !n.is_defaultable_function()
            && !n.has_initializer()
            )
        {
            errors.emplace_back(
                n.position(),
                "a function must have a body ('=' initializer), unless it is virtual (has a 'virtual this' parameter) or is defaultable (operator== or operator<=>)"
            );
            return false;
        }

        if (
            n.is_type()
            && !n.parent_is_namespace()
            && !n.parent_is_type()
            )
        {
            errors.emplace_back(
                n.position(),
                "(temporary alpha limitation) a type must be in a namespace or type scope - function-local types are not yet supported"
            );
            return false;
        }

        //  A type scope variable must have a declared type
        if (
            n.parent_is_type()
            && n.has_wildcard_type()
            )
        {
            errors.emplace_back(
                n.position(),
                "a type scope variable must have a declared type"
            );
            return false;
        }

        //  A 'this' declaration must be an ordinary parameter or a type-scope object
        if (n.identifier && *n.identifier->identifier == "this")
        {
            if (
                n.is_template_parameter
                || (
                    !n.is_parameter
                    && !n.parent_is_type()
                    )
                )
            {
                errors.emplace_back(
                    n.identifier->position(),
                    "'this' may only be declared as an ordinary function parameter or type-scope (base) object"
                );
                return {};
            }
        }

        {
            auto this_index = n.index_of_parameter_named("this");
            auto that_index = n.index_of_parameter_named("that");

            if (this_index >= 0) {
                if (!n.parent_is_type()) {
                    errors.emplace_back(
                        n.position(),
                        "'this' must be the first parameter of a type-scope function"
                    );
                    return false;
                }
                if (this_index != 0) {
                    errors.emplace_back(
                        n.position(),
                        "'this' must be the first parameter"
                    );
                    return false;
                }
            }

            if (that_index >= 0) {
                if (!n.parent_is_type()) {
                    errors.emplace_back(
                        n.position(),
                        "'that' must be the second parameter of a type-scope function"
                    );
                    return false;
                }
                if (that_index != 1) {
                    errors.emplace_back(
                        n.position(),
                        "'that' must be the second parameter"
                    );
                    return false;
                }
                if (this_index != 0) {
                    errors.emplace_back(
                        n.position(),
                        "'that' must come after an initial 'this' parameter"
                    );
                    return false;
                }
            }
        }

        if (
            n.is_object()
            && n.has_wildcard_type()
            && n.parent_is_namespace()
            )
        {
            errors.emplace_back(
                n.identifier->position(),
                "namespace scope objects must have a concrete type, not a deduced type"
            );
            return false;
        }

        if (
            n.has_name("_")
            && !n.is_object()
            && !n.is_namespace()
            )
        {
            errors.emplace_back(
                n.identifier->position(),
                "'_' (wildcard) may not be the name of a function or type - it may only be used as the name of an anonymous object or anonymous namespace"
            );
            return false;
        }

        if (
            n.has_name("this")
            && n.parent_is_type()
            )
        {
            assert(n.is_object());

            if (
                !n.is_public()
                && !n.is_default_access()
                )
            {
                errors.emplace_back(
                    n.position(),
                    "a base type must be public (the default)"
                );
                return false;
            }

            if (n.has_wildcard_type())
            {
                errors.emplace_back(
                    n.position(),
                    "a base type must be a specific type, not a deduced type (omitted or '_'-wildcarded)"
                );
                return false;
            }
        }

        if (
            n.access != accessibility::default_
            && !n.parent_is_type()
            )
        {
            errors.emplace_back(
                n.position(),
                "an access-specifier is only allowed on a type-scope (member) declaration"
            );
            return false;
        }

        if (n.is_constructor())
        {
            auto& func = std::get<declaration_node::a_function>(n.type);
            assert(
                func->parameters->ssize() > 0
                && (*func->parameters)[0]->has_name("this")
            );
            if ((*func->parameters)[0]->is_polymorphic()) {
                errors.emplace_back(
                    n.position(),
                    "a constructor may not be declared virtual, override, or final"
                );
                return false;
            }
        }

        if (
            n.is_function()
            && n.has_name()
            && n.parent_is_function()
            )
        {
            assert (n.identifier->get_token());
            auto name = n.identifier->get_token()->to_string(true);
            errors.emplace_back(
                n.position(),
                "(temporary alpha limitation) local functions like '" + name + ": (/*params*/) = {/*body*/}' are not currently supported - write a local variable initialized with an unnamed function like '" + name + " := :(/*params*/) = {/*body*/};' instead (add '=' and ';')"
            );
            return false;
        }

        //  If this is the main function, it must be 'main: ()' or 'main: (args)'
        if (
            n.identifier
            && n.has_name("main")
            && n.is_function()
            && n.is_global()
            )
        {
            auto& func = std::get<declaration_node::a_function>(n.type);

            //  It's more readable to express this as positive condition here...
            if (
                //  There are no parameters
                func->parameters->parameters.empty()
                //  Or there's a single wildcard in-param named 'args'
                || (
                    func->parameters->parameters[0]->has_name("args")
                    && func->parameters->parameters[0]->pass == passing_style::in
                    && func->parameters->parameters[0]->declaration->is_object()
                    && std::get<declaration_node::an_object>(func->parameters->parameters[0]->declaration->type)->is_wildcard()
                    )
                )
            {
                ;   // ok
            }
            //  ... and if it isn't that, then complain
            else
            {
                errors.emplace_back(
                    func->parameters->parameters[0]->position(),
                    "'main' must be declared as 'main: ()' with zero parameters, or 'main: (args)' with one parameter named 'args' for which the type 'std::vector<std::string_view>' will be deduced"
                );
                return false;
            }
        }

        if (n.has_name("operator="))
        {
            if (!n.is_function())
            {
                errors.emplace_back(
                    n.position(),
                    "'operator=' must be a function"
                );
                return false;
            }
            auto& func = std::get<declaration_node::a_function>(n.type);

            if (func->has_declared_return_type())
            {
                errors.emplace_back(
                    func->parameters->parameters[0]->position(),
                    "'operator=' may not have a declared return type"
                );
                return false;
            }

            if (func->parameters->ssize() == 0)
            {
                errors.emplace_back(
                    n.position(),
                    "an operator= function must have a parameter"
                );
                return false;
            }
            else if (
                (*func->parameters)[0]->has_name("this")
                && (*func->parameters)[0]->pass != passing_style::inout
                && (*func->parameters)[0]->pass != passing_style::out
                && (*func->parameters)[0]->pass != passing_style::move
                )
            {
                errors.emplace_back(
                    n.position(),
                    "an operator= function's 'this' parameter must be inout, out, or move"
                );
                return false;
            }

            if (
                func->parameters->ssize() > 1
                && (*func->parameters)[1]->has_name("that")
                && (*func->parameters)[1]->pass != passing_style::in
                && (*func->parameters)[1]->pass != passing_style::move
                )
            {
                errors.emplace_back(
                    n.position(),
                    "an operator= function's 'that' parameter must be in or move"
                );
                return false;
            }

            if (
                func->parameters->ssize() > 1
                && (*func->parameters)[0]->has_name("this")
                && (*func->parameters)[0]->pass == passing_style::move
                )
            {
                errors.emplace_back(
                    n.position(),
                    "a destructor may not have other parameters besides 'this'"
                );
                return false;
            }
        }

        for (auto& decl : n.get_type_scope_declarations())
        {
            if (decl->has_name("that"))
            {
                errors.emplace_back(
                    n.position(),
                    "'that' may not be used as a type scope name"
                );
                return false;
            }
        }

        if (
            n.is_binary_comparison_function()
            && !n.has_bool_return_type()
            )
        {
            errors.emplace_back(
                n.position(),
                n.name()->to_string(true) + " must return bool"
            );
            return false;
        }

        if (n.has_name("operator<=>")) {
            auto return_name = n.unnamed_return_type_to_string();
            if (
                return_name != "_"
                && return_name.find("strong_ordering" ) == return_name.npos
                && return_name.find("weak_ordering"   ) == return_name.npos
                && return_name.find("partial_ordering") == return_name.npos
                )
            {
                errors.emplace_back(
                    n.position(),
                    "operator<=> must return std::strong_ordering, std::weak_ordering, or std::partial_ordering"
                );
                return false;
            }
        }

        if (n.is_type()) {
            auto compound_stmt = n.initializer->get_if<compound_statement_node>();
            assert (compound_stmt);
            for (auto& stmt : compound_stmt->statements) {
                if (!stmt->is_declaration()) {
                    errors.emplace_back(
                        stmt->position(),
                        "a user-defined type body must contain only declarations, not other code"
                    );
                    return false;
                }
            }
        }

        return true;
    }


    auto check(statement_node const& n)
        -> bool
    {
        if (auto expr_stmt = n.get_if<expression_statement_node>();
            expr_stmt
            && n.compound_parent
            && (
                expr_stmt->expr->is_identifier()
                || expr_stmt->expr->is_id_expression()
                || expr_stmt->expr->is_literal()
                )
            )
        {
            errors.emplace_back(
                n.position(),
                "unused literal or identifier"
            );
            return false;
        }

        return true;
    }


    //-----------------------------------------------------------------------
    //  Visitor functions
    //
    int  scope_depth                              = 0;
    bool started_standalone_assignment_expression = false;
    bool started_postfix_expression               = false;
    bool is_out_expression                        = false;
    bool inside_parameter_list                    = false;
    bool inside_returns_list                      = false;
    bool just_entered_for                         = false;
    parameter_declaration_node const* inside_out_parameter = {};

    auto start(parameter_declaration_list_node const&, int) -> void
    {
        inside_parameter_list = true;
    }

    auto end(parameter_declaration_list_node const&, int) -> void
    {
        inside_parameter_list = false;
    }

    auto start(parameter_declaration_node const& n, int) -> void
    {
        if (
            //  If it's an 'out' parameter
            (
                !inside_returns_list
                && n.pass == passing_style::out
                )
            //  Or it's an uninitialized 'out' return value
            || (
                inside_returns_list
                && n.pass == passing_style::out
                && !n.declaration->initializer
                )
            )
        {
            inside_out_parameter = &n;
        }

        if (
            n.pass == passing_style::copy
            || n.pass == passing_style::move
            || n.pass == passing_style::forward
            )
        {
            // Handle variables in unnamed functions. For such cases scope_depth is increased by +1
            auto depth = scope_depth + ((n.declaration->parent_is_function() && n.declaration->parent_declaration->name() == nullptr) ? 1 : 0 );
            symbols.emplace_back( depth, declaration_sym( true, n.declaration.get(), n.declaration->name(), n.declaration->initializer.get(), &n));
        }
    }

    auto end(parameter_declaration_node const&, int) -> void
    {
        inside_out_parameter = {};
    }

    auto start(expression_list_node::term const&n, int) -> void
    {
        is_out_expression = (n.pass == passing_style::out);
    }

    auto start(function_returns_tag const&, int) -> void
    {
        inside_returns_list = true;
    }

    auto end(function_returns_tag const&, int) -> void
    {
        inside_returns_list = false;
    }

    auto start(iteration_statement_node const& n, int) -> void
    {
        if (*n.identifier == "for") {
            just_entered_for = true;
        }
    }

    auto start(declaration_node const& n, int) -> void
    {
        //  Skip the first declaration after entering a 'for',
        //  which is the for loop parameter - it's always
        //  guaranteed to be initialized by the language
        if (just_entered_for) {
            just_entered_for = false;
            return;
        }

        if (
            !n.is_alias()
            //  Skip type scope (member) variables
            && !(n.parent_is_type() && n.is_object())
            //  Skip unnamed variables
            && n.identifier
            //  Skip non-out parameters
            && (
                !inside_parameter_list
                || inside_out_parameter
                )
            )
        {
            symbols.emplace_back( scope_depth, declaration_sym( true, &n, n.name(), n.initializer.get(), inside_out_parameter ) );
            if (!n.is_object()) {
                ++scope_depth;
            }
        }
    }

    auto end(declaration_node const& n, int) -> void
    {
        if (
            !n.is_alias()
            //  Skip type scope (member) variables
            && !(n.parent_is_type() && n.is_object())
            //  Skip unnamed variables
            && n.identifier 
            //  Skip non-out parameters
            && (
                !inside_parameter_list
                || inside_out_parameter
                )
            )
        {
            symbols.emplace_back( scope_depth, declaration_sym( false, &n, nullptr, nullptr, inside_out_parameter ) );
            if (!n.is_object()) {
                --scope_depth;
            }
        }
    }

    auto start(token const& t, int) -> void
    {
        //  We currently only care to look at identifiers
        if (t.type() != lexeme::Identifier) {
            return;
        }

        //  If this is the first identifier since we started a new assignment,
        //  expression, then it's the left-hand side (target) of the assignment
        else if (started_standalone_assignment_expression)
        {
            symbols.emplace_back( scope_depth, identifier_sym( true, &t ) );
            started_standalone_assignment_expression = false;   // we were the consumer for this information
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

        //  Otherwise it's just an identifier use (if it's outside the parameter list) and
        //  it's the first identifier of a postfix_expressions (not a member name or something else)
        else if (started_postfix_expression)
        {
            started_postfix_expression = false;
            if (!inside_parameter_list)
            {
                //  Put this into the table if it's a use of an object in scope
                //  or it's a 'copy' parameter (but to be a use it must be after
                //  the declaration, not the token in the decl's name itself)
                if (auto decl = get_declaration_of(t);
                    decl
                    && decl->declaration->name() != &t
                    )
                {
                    symbols.emplace_back( scope_depth, identifier_sym( false, &t ) );
                }
            }
        }
    }

    auto start(selection_statement_node const& n, int) -> void
    {
        active_selections.push_back( &n );
        symbols.emplace_back( scope_depth, selection_sym{ true, active_selections.back() } );
        ++scope_depth;
    }

    auto end(selection_statement_node const&, int) -> void
    {
        symbols.emplace_back( scope_depth, selection_sym{ false, active_selections.back() } );
        active_selections.pop_back();
        --scope_depth;
    }

    auto kind_of(compound_statement_node const& n)
        -> compound_sym::kind
    {
        auto kind = compound_sym::is_scope;
        if (!active_selections.empty())
        {
            assert(active_selections.back()->true_branch);
            if (active_selections.back()->true_branch.get() == &n)
            {
                kind = compound_sym::is_true;
            }
            if (
                active_selections.back()->false_branch
                && active_selections.back()->false_branch.get() == &n
                )
            {
                kind = compound_sym::is_false;
            }
        }
        return kind;
    }

    auto start(compound_statement_node const& n, int) -> void
    {
        symbols.emplace_back(
            scope_depth,
            compound_sym{ true, &n, kind_of(n) }
        );
        ++scope_depth;
    }

    auto end(compound_statement_node const& n, int) -> void
    {
        symbols.emplace_back(
            scope_depth,
            compound_sym{ false, &n, kind_of(n) }
        );
        --scope_depth;
    }

    auto start(assignment_expression_node const& n, int)
    {
        if (
            n.is_standalone_expression()
            && n.lhs_is_id_expression()
            && std::ssize(n.terms) > 0
            )
        {
            assert (n.terms.front().op);
            if (n.terms.front().op->type() == lexeme::Assignment) {
                started_standalone_assignment_expression = true;
            }
        }
    }

    auto start(postfix_expression_node const&, int) {
        started_postfix_expression = true;
    }

    auto start(auto const&, int) -> void
    {
        //  Ignore other node types
    }

    auto end(auto const&, int) -> void
    {
        //  Ignore other node types
    }
};


}

#endif
