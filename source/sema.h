
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

#ifndef CPP2_SEMA_H
#define CPP2_SEMA_H

#include "reflect.h"


namespace cpp2 {

auto parser::apply_type_metafunctions( declaration_node& n )
    -> bool
{
    assert(n.is_type());

    //  Get the reflection state ready to pass to the function
    auto cs = meta::compiler_services{ &errors, generated_tokens };
    auto rtype = meta::type_declaration{ &n, cs };

    return apply_metafunctions(
        n,
        rtype,
        [&](std::string const& msg) { error( msg, false ); }
    );
}


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

    auto get_token() const
        -> token const*
    {
        return identifier;
    }
};

struct identifier_sym {
    enum kind { use, using_declaration, deactivation } kind_ = use;
    bool standalone_assignment_to = false;
    bool is_captured = false;
    bool is_after_dot = false;
    bool safe_to_move = true;
    int safe_to_move_context = 0;
    token const* identifier = {};

    identifier_sym(
        bool         a,
        token const* id,
        kind         k = use,
        bool         mv = true,
        int          mvc = 0,
        bool         after_dot = false
    )
        : kind_{k}
        , standalone_assignment_to{a}
        , is_after_dot{after_dot}
        , safe_to_move{mv}
        , safe_to_move_context{mvc}
        , identifier{id}
    { }

    auto position() const
        -> source_position
    {
        assert (identifier);
        return identifier->position();
    }

    auto get_token() const
        -> token const*
    {
        return identifier;
    }

    auto is_use() const
        -> bool
    {
        return kind_ == use;
    }

    auto is_using_declaration() const
        -> bool
    {
        return kind_ == using_declaration;
    }

    auto is_deactivation() const
        -> bool
    {
        return kind_ == deactivation;
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

    auto get_token() const
        -> token const*
    {
        assert (selection);
        return selection->identifier;
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

    auto get_token() const
        -> token const*
    {
        return nullptr;
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
    symbol(int depth, identifier_sym  const& sym) : depth{depth}, sym{sym}, start{!sym.is_deactivation()} { }
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

    auto get_token() const
        -> token const*
    {
        switch (sym.index())
        {
        break;case declaration: {
            auto const& s = std::get<declaration>(sym);
            return s.get_token();
        }

        break;case identifier: {
            auto const& s = std::get<identifier>(sym);
            return s.get_token();
        }

        break;case selection: {
            auto const& s = std::get<selection>(sym);
            return s.get_token();
        }

        break;case compound: {
            auto const& s = std::get<compound>(sym);
            return s.get_token();
        }

        break;default:
            assert (!"illegal symbol state");
            return nullptr;
        }
    }

    auto get_global_token_order() const
        -> index_t
    {
        if (auto t = get_token()) {
            return t->get_global_token_order();
        }
        return 0;
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
//   will rewrite to move or forward from the variable.
//
struct last_use {
    token const* t;
    bool         is_forward;
    bool         safe_to_move;

    last_use(
        token const* t_,
        bool         is_forward_ = false,
        bool         safe_to_move_ = true
    )
        : t{t_}
        , is_forward{is_forward_}
        , safe_to_move{safe_to_move_}
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
    stable_vector<symbol>     symbols;

    std::vector<selection_statement_node const*> active_selections;

    mutable std::unordered_map< token const*, cpp2::stable_vector<symbol>::const_iterator > token_to_symbol_iterator;

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
    //  For a this parameter, optionally include uses of implicit this
    //
    auto get_declaration_of(
        token const* t,
        bool         look_beyond_current_function = false,
        bool         include_implicit_this        = false
    ) const
        -> declaration_sym const*
    {
        if (!t) {
            return {};
        }
        return get_declaration_of(*t, look_beyond_current_function, include_implicit_this);
    }

    auto get_declaration_of(
        token const& t,
        bool         look_beyond_current_function = false,
        bool         include_implicit_this        = false
    ) const
        -> declaration_sym const*
    {
        auto timer  = scope_timer("get_declaration_of");

        //  First find the position the query is coming from
        //  and remember its depth
        auto i = symbols.cbegin();

        //{
        //auto timer1 = scope_timer("get_declaration_of step 1, initial find loop");

        //  Check the cache first to avoid repeated computations
        if (auto it = token_to_symbol_iterator.find(&t);
            it != token_to_symbol_iterator.end()
            )
        {
            i = it->second;
        }
        else
        {
            while (
                i != symbols.cend()
                && i->get_global_token_order() < t.get_global_token_order()
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
            token_to_symbol_iterator[&t] = i;
        }
        //}

        auto depth = i->depth;

        //auto timer2 = scope_timer("get_declaration_of step 2, rest of lookup");

        //  Then look backward to find the first declaration of
        //  this name that is not deeper (in a nested scope)
        //  and is in the same function
        using I = cpp2::stable_vector<symbol>::const_iterator;
        auto advance = [](I& i, int n, I bound) {  // TODO Use `std::ranges::advance`
            auto in = i;
            if (std::abs(n) >= std::abs(bound - i)) {
                i = bound;
            }
            else {
                std::advance(i, n);
            }
            return n - (i - in);
        };
        advance(i, -int(i->position() > t.position()), symbols.cbegin());
        advance(i, 1, symbols.cend());
        while (advance(i, -1, symbols.begin()) == 0)
        {
            if (
                i->sym.index() == symbol::active::declaration
                && i->depth <= depth
                )
            {
                auto const& decl = std::get<symbol::active::declaration>(i->sym);

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

                //  If we reached a 'move this' parameter, look it up in the type members
                if (
                    include_implicit_this
                    && decl.identifier
                    && *decl.identifier == "this"
                    )
                {
                    if (auto n = decl.declaration;
                        decl.parameter
                        && decl.parameter->pass == passing_style::move
                        && n
                        && n->parent_is_function()
                        && (n = n->parent_declaration)->parent_is_type()
                        && n->my_statement
                        && n->my_statement->compound_parent
                        && std::any_of(
                               n->my_statement->compound_parent->statements.begin(),
                               n->my_statement->compound_parent->statements.end(),
                               [&t, n](std::unique_ptr<statement_node> const& s) mutable {
                                   return s
                                          && s->statement.index() == statement_node::declaration
                                          && (n = &*std::get<statement_node::declaration>(s->statement))->identifier
                                          && n->identifier->to_string() == t;
                               })
                        )
                    {
                        return &decl;
                    }
                    return nullptr;
                }

                depth = i->depth;
            }
        }

        return nullptr;
    }

    auto is_captured(token const& t) const
        -> bool
    {
        //  TODO Use 'std::lower_bound' by filtering final positions of 0.
        auto it = std::find_if(
            symbols.begin(),
            symbols.end(),
            [&](symbol const& s) -> bool {
                return s.get_global_token_order() == t.get_global_token_order();
            });

        if (identifier_sym const* sym = nullptr;
            it != symbols.end()
            && (sym = std::get_if<symbol::active::identifier>(&it->sym))
            && sym->is_use()
            )
        {
            return sym->is_captured;
        }
        return false;
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
                    o << sym.identifier->to_string();
                }

                if (is_uninitialized_decl(sym)) {
                    o << " *** UNINITIALIZED";
                }
            }

            break;case symbol::active::identifier: {
                auto const& sym = std::get<symbol::active::identifier>(s.sym);
                assert (sym.identifier);
                if (last_use const* use = nullptr;
                    sym.is_use()
                    && (use = is_definite_last_use(sym.identifier))
                    )
                {
                    o << "*** " << sym.identifier->position().to_string()
                      << " DEFINITE LAST "
                      << (use->is_forward ? "FORWARDING" : "POTENTIALLY MOVING")
                      << " USE OF ";
                }

                if (
                    sym.is_use()
                    && is_definite_initialization(sym.identifier)
                    )
                {
                    o << "*** " << sym.identifier->position().to_string()
                      << " DEFINITE INITIALIZATION OF ";
                }
                else if (sym.standalone_assignment_to) {
                    o << "*** assignment to ";
                }
                else {
                    o << "*** use of ";
                }
                o << sym.identifier->to_string();
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
        auto is_local_declaration = [&](symbol const& s)
            -> declaration_sym const*
        {
            if (auto const* sym = std::get_if<symbol::active::declaration>(&s.sym)) {
                if (
                    sym->start
                    && sym->declaration->is_object()
                    )
                {
                    //  Must be in function scope
                    if (sym->declaration->parent_is_function()) {
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
        for (auto sympos = unsafe_narrow<int>(std::ssize(symbols) - 1); sympos >= 0; --sympos)
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
            //  If it's some other parameter, just check that it is used
            //
            if (auto decl = is_local_declaration(symbols[sympos])) {
                assert (decl->identifier);
                find_definite_last_uses(
                    decl->identifier,
                    sympos,
                    decl->parameter ? std::optional{decl->parameter->pass} : std::optional<passing_style>{},
                    decl->parameter
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
        token const*                 id,
        int                          pos,
        std::optional<passing_style> pass,
        bool                         is_parameter
    ) const
        -> void
    {
        auto is_a_use = [&](identifier_sym const* sym) -> bool {
            assert(!sym || sym->identifier);
            declaration_sym const* decl = nullptr;
            return sym
                   && sym->is_use()
                   && (
                       *sym->identifier == *id
                       //  For 'this', do include member names with implicit 'this.'
                       || (
                           *id == "this"
                           && (decl = get_declaration_of(sym->get_token(), false, true))
                           && decl->identifier
                           && *decl->identifier == "this"
                           )
                       );
        };

        auto i = pos + 1;

        struct pos_range
        {
            bool is_loop;
            int  first;
            int  last = 0;

            pos_range  (bool l, int f) : is_loop{l}, first{f} { }
            bool within(int x)   const { return first <= x && x <= last; }
            bool skip  ()        const { return !is_loop; }
        };

        //  Ranges of positions which includes non-nested
        //  1. Iteration statements (a use isn't a last use)
        //  2. Ranges to skip (a last use can't be found in these)
        //    - Function expressions (except in a capture)
        //    - Where id is hidden by another declaration
        auto pos_ranges = std::vector<pos_range>{{false, 0}}; // Keep sentinel for simpler code

        auto skip_hidden_name = [&](bool record_pos_range) -> bool {
            auto skip_to = [&](token const* identifier_end)
            {
                //  Can afford to just skip id and not member names
                //  because in Cpp2 you can't shadow member names
                //
                //  TODO When local types are supported
                //  consider where 'this' is implicitly declared
                //  For example, see https://cpp2.godbolt.org/z/onfW6hns1

                if (record_pos_range) {
                    pos_ranges.emplace_back(false, i - 1);
                }
                ++i;
                identifier_sym const* sym = nullptr;
                while (
                    i < std::ssize(symbols)
                    && (
                        !(sym = std::get_if<symbol::active::identifier>(&symbols[i].sym))
                        || sym->identifier != identifier_end
                        )
                    )
                {
                    ++i;
                }
                assert(sym->identifier == identifier_end && sym->is_deactivation());
                if (record_pos_range) {
                    pos_ranges.back().last = i;
                }
            };

            if (auto decl = std::get_if<symbol::active::declaration>(&symbols[i].sym);
                decl
                && decl->start
                && decl->identifier
                && *decl->identifier == *id
                && *decl->identifier != "_"
                )
            {
                skip_to(decl->identifier);
                return true;
            }
            else if (auto sym = std::get_if<symbol::active::identifier>(&symbols[i].sym);
                     sym
                     && sym->is_using_declaration()
                     && sym->identifier
                     && *sym->identifier == *id
                     )
            {
                skip_to(sym->identifier);
                return true;
            }
            return false;
        };

        auto skip_function_expression = [&]() -> bool {
            if (auto decl = std::get_if<symbol::active::declaration>(&symbols[i].sym);
                decl
                && decl->start
                && decl->declaration->is_function_expression()
                )
            {
                //  Record the skipped subranges without captures
                auto function_expression_end = decl->declaration;
                pos_ranges.emplace_back(false, i - 1);
                ++i;
                while (
                    i < std::ssize(symbols)
                    && (
                        !(decl = std::get_if<symbol::active::declaration>(&symbols[i].sym))
                        || decl->declaration != function_expression_end
                        )
                    )
                {
                    if (skip_hidden_name(false)) {
                        continue;
                    }
                    else if (
                        auto sym = std::get_if<symbol::active::identifier>(&symbols[i].sym);
                        is_a_use(sym)
                        && sym->is_captured
                        )
                    {
                        pos_ranges.back().last = i - 1;
                        pos_ranges.emplace_back(false, i + 1);
                    }
                    ++i;
                }
                assert(decl && decl->declaration == function_expression_end && !decl->start);
                pos_ranges.back().last = i;
                return true;
            }
            return false;
        };

        //  Scan forward to the end of this scope
        auto found_end_of_our_initialization = false;
        for (auto start_depth = symbols[pos].depth;
            i < std::ssize(symbols)
            && symbols[i].depth >= start_depth;
            ++i
            )
        {
            //  While we're here, if this is a non-parameter local, check for
            //  any uses before the end of the initializer
            if (
                !is_parameter
                && !found_end_of_our_initialization
                )
            {
                if (symbols[i].depth == start_depth)
                {
                    if (auto decl = std::get_if<symbol::active::declaration>(&symbols[i].sym);
                        decl
                        && decl->declaration->is_object()
                        && decl->declaration->has_name(*id)
                        && !decl->start
                        )
                    {
                        found_end_of_our_initialization = true;
                    }
                }

                if (auto sym = std::get_if<symbol::active::identifier>(&symbols[i].sym);
                    sym
                    && !sym->is_after_dot
                    && is_a_use(sym)
                    )
                {
                    assert(sym->identifier);
                    errors.emplace_back(
                        sym->identifier->position(),
                        "local variable " + sym->identifier->to_string()
                            + " cannot be used in its own initializer");
                }
            }

            if (
                skip_function_expression()
                || skip_hidden_name(true)
                )
            {
                continue;
            }

            //  Record the loops
            else if (auto sym = std::get_if<symbol::active::identifier>(&symbols[i].sym);
                sym
                && sym->identifier
                && (
                    *sym->identifier == "for"
                    || *sym->identifier == "while"
                    || *sym->identifier == "do"
                    )
                )
            {
                auto loop_depth = symbols[i].depth;
                auto loop_id = sym->identifier;

                //  If id is the loop parameter, this is its end
                if (
                    *loop_id == "for"
                    && sym->is_deactivation()
                    )
                {
                    assert(symbols[i].depth == start_depth && "Messed up in a nested loop");
                    ++i;
                    break;
                }
                assert(symbols[i].start);

                pos_ranges.emplace_back(true, i);

                //  Scan forward to the end of this loop
                ++i;
                while (
                    i < std::ssize(symbols)
                    && (
                        symbols[i].depth > loop_depth
                        || !(sym = std::get_if<symbol::active::identifier>(&symbols[i].sym))
                        || sym->identifier != loop_id
                        )
                    )
                {
                    if (
                        skip_function_expression()
                        || skip_hidden_name(true)
                        )
                    {
                        continue;
                    }
                    ++i;
                }
                assert(sym && sym->identifier == loop_id && sym->is_deactivation());
                pos_ranges.back().last = i;
            }
        }

        //  i is now at the end of id's scope, so start scanning backwards
        //  until we find the first definite last uses
        --i;
        //bool found = false;
        auto branch_depth = 0;
        while (i > pos)
        {
            //  Drop skipped ranges
            while (pos_ranges.back().first >= i) {
                pos_ranges.pop_back();
            }
            //  Skip ranges where a use of id would name another declaration
            while (
                pos_ranges.back().within(i)
                && pos_ranges.back().skip()
                )
            {
                i = pos_ranges.back().first;
                pos_ranges.pop_back();
            }

            //  If found in a branch and we are at its start,
            //  pop out of any containing scope of the branch
            if (compound_sym const* comp = nullptr;
                branch_depth != 0
                && (comp = std::get_if<symbol::active::compound>(&symbols[i].sym))
                && comp->kind_ == compound_sym::is_true
                && branch_depth + 1 == symbols[i].depth
                )
            {
                while (
                    i > pos
                    && (
                        !(comp = std::get_if<symbol::active::compound>(&symbols[i].sym))
                        || branch_depth <= symbols[i].depth
                        )
                    )
                {
                    --i;
                }

                //  If found in a branch,
                //  keep popping to its sibling (false branch)
                //  or to its containing scope (true branch)
                if (
                    i > pos
                    && comp
                    && (
                        comp->kind_ == compound_sym::is_false
                        || comp->kind_ == compound_sym::is_true
                        )
                    )
                {
                    branch_depth = symbols[i].depth - 1;
                }
                else
                {
                    branch_depth = 0;
                }
                continue;
            }

            auto sym = std::get_if<symbol::active::identifier>(&symbols[i].sym);

            if (!is_a_use(sym))
            {
                --i;
                continue;
            }

            //  If found in a loop, it wasn't a last use
            //  Set up to pop out of the scope containing the loop
            if (pos_ranges.back().within(i))
            {
                assert(pos_ranges.back().is_loop && "Other ranges are skipped.");
                i = pos_ranges.back().first; // The scope to pop is the scope of the loop
                pos_ranges.pop_back();
            }
            else
            {
                definite_last_uses.emplace_back(
                    sym->identifier,
                    pass == passing_style::forward,
                    sym->safe_to_move
                    && (
                        !pass
                        || pass == passing_style::copy
                        || pass == passing_style::move
                        || pass == passing_style::forward
                        )
                    );
            }
            //found = true;

            compound_sym const* comp = nullptr;

            //  Pop out of any containing scope of the last use
            for (auto found_depth = symbols[i--].depth;
                i > pos
                && (
                    !(comp = std::get_if<symbol::active::compound>(&symbols[i].sym))
                    || comp->kind_ == compound_sym::is_scope
                    || found_depth <= symbols[i].depth
                    );
                --i
                )
            {
            }
            assert(!comp || symbols[i].start);

            //  If found in a branch, record its depth
            if (
                i > pos
                && comp
                && comp->kind_ != compound_sym::is_scope
                )
            {
                branch_depth = symbols[i].depth - 1;
            }
        }

        //  This warning is noisy until we fix a couple of bugs,
        //  so disable it at least temporarily
        // 
        ////  If we arrived back at the declaration without finding a use
        ////  and this is a user-named object (not 'this', 'that', or '_')
        //if (
        //    !found
        //    && *id != "this"
        //    && *id != "that"
        //    && *id != "_"
        //    )
        //{
        //    errors.emplace_back(
        //        id->position(),
        //        "local variable '" + id->to_string() + "' is not used; consider changing its name to '_' to make it explicitly anonymous, or removing it entirely if its side effects are not needed"
        //    );
        //}
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
        auto name = decl->identifier->to_string();

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
                        "local variable " + sym.identifier->to_string()
                            + " cannot have the same name as an uninitialized"
                              " variable in the same function");
                }
            }

            break;case symbol::active::identifier: {
                auto const& sym = std::get<symbol::active::identifier>(symbols[pos].sym);
                assert (sym.identifier);

                if (
                    sym.is_use()
                    && is_definite_initialization(sym.identifier)
                    )
                {
                    errors.emplace_back(
                        sym.identifier->position(),
                        "local variable " + name
                            + " must be initialized before " + sym.identifier->to_string()
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
                            "\"" + sym.selection->identifier->to_string()
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
                    "use '" + decl->identifier->to_string() + ".' to refer to an object member"
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
                    "use '" + decl->identifier->to_string() + "::' to refer to a type member"
                );
                return false;
            }
        }

        return true;
    }


    auto check(parameter_declaration_node const& n)
        -> bool
    {
        auto type_name = std::string{};
        if (n.declaration->has_declared_return_type()) {
            type_name = n.declaration->get_object_type()->to_string();
        }

        if (
            n.ordinal == 2
            && !n.has_name("that")
            && n.declaration->parent_declaration
            && n.declaration->parent_declaration->has_name("operator=")
            && n.declaration->parent_declaration->parent_declaration
            && n.declaration->parent_declaration->parent_declaration->name()
            && type_name == *n.declaration->parent_declaration->parent_declaration->name()
            )
        {
            errors.emplace_back(
                n.position(),
                "if an 'operator=' second parameter is of the same type (here '" + type_name + "'), it must be named 'that'"
            );
            return false;
        }

        return true;
    }

    auto check(declaration_node const& n)
        -> bool
    {
        if (n.has_name("operator")) {
            errors.emplace_back(
                n.position(),
                "the name 'operator' is incomplete - did you mean to write an overloaded operator name like 'operator*' or 'operator++'?"
            );
            return false;
        }

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
                n.is_template_parameter()
                || (
                    !n.is_parameter()
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
            && !n.is_object_alias()
            )
        {
            errors.emplace_back(
                n.identifier->position(),
                "'_' (wildcard) may not be the name of a function or type - it may only be used as the name of an anonymous object, object alias, or namespace"
            );
            return false;
        }

        if (
            n.has_name("this")
            && n.parent_is_type()
            )
        {
            if (!n.is_object()) {
                errors.emplace_back(
                    n.position(),
                    "a member named 'this' declares a base subobject, and must be followed by a base type name"
                );
                return false;
            }

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
            auto name = n.identifier->get_token()->to_string();
            errors.emplace_back(
                n.position(),
                "(temporary alpha limitation) local functions like '" + name + ": (/*params*/) = {/*body*/}' are not currently supported - write a local variable initialized with an unnamed function like '" + name + " := :(/*params*/) = {/*body*/};' instead (add '=' and ';')"
            );
            return false;
        }

        //  Ban overloading operators &&, ||, and , (comma)
        if (
            n.identifier
            && n.is_function()
            && (
                n.has_name("operator&&")
                || n.has_name("operator||")
                || (n.has_name("operator&") && n.parameter_count() < 2)
                || n.has_name("operator,")
                )
            )
        {
            errors.emplace_back(
                n.position(),
                "overloading '" + n.name()->to_string() + "' is not allowed"
            );
            return false;
        }

        //  Require that ~/comparison/assignment operators must be members
        if (
            n.identifier
            && !n.is_function_with_this()
            && (
                //  Note re comparisons: The reason I'm restricting comparisons to be members
                //  is because with comparison symmetry (since C++20, derived from Cpp2)
                //  there's no longer a need for a type author to write them as nonmembers,
                //  and I want to discourage that habit by banning nonmembers. However, there
                //  could be a motivation to write them as nonmembers in the case where the
                //  type author doesn't provide them -- if that turns out to be important we
                //  can remove the restriction on nonmember comparisons here
                n.is_comparison()

                //  The following would be rejected anyway by the Cpp1 compiler,
                //  but including them here gives nicer and earlier error messages
                || n.has_name("operator~")
                || n.is_compound_assignment()
                )
            )
        {
            errors.emplace_back(
                n.position(),
                n.name()->to_string() + " must have 'this' as the first parameter"
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
            auto& params = func->parameters->parameters;

            //  It's more readable to express this as positive condition here...
            if (
                //  There are no parameters
                params.empty()
                //  Or there's a single wildcard in-param named 'args'
                || (
                    params.size() == 1
                    && params[0]->has_name("args")
                    && params[0]->pass == passing_style::in
                    && params[0]->declaration->is_object()
                    && std::get<declaration_node::an_object>(params[0]->declaration->type)->is_wildcard()
                    )
                )
            {
                ;   // ok
            }
            //  ... and if it isn't that, then complain
            else
            {
                errors.emplace_back(
                    params[0]->position(),
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
                n.name()->to_string() + " must return bool"
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
                if (
                    !stmt->is_declaration()
                    && !stmt->is_using()
                    )
                {
                    errors.emplace_back(
                        stmt->position(),
                        "a user-defined type body must contain only declarations or 'using' statements, not other code"
                    );
                    return false;
                }
            }
        }

        return true;
    }


    auto check(function_type_node const& n)
        -> bool
    {
        assert(n.parameters);

        //  An increment/decrement function must have a single 'inout' parameter,
        //  and if it's a member flag it if we know the type is not copyable
        if (
            n.my_decl->has_name("operator++")
            || n.my_decl->has_name("operator--")
            )
        {
            if (
                (*n.parameters).ssize() != 1
                || (*n.parameters)[0]->direction() != passing_style::inout
                )
            {
                errors.emplace_back(
                    n.position(),
                    "a user-defined " + n.my_decl->name()->to_string() + " must have a single 'inout' parameter"
                );
                return false;
            }

            if (n.has_deduced_return_type()) {
                errors.emplace_back(
                    n.position(),
                    "a user-defined " + n.my_decl->name()->to_string() + " must have a specific (not deduced) return type"
                );
                return false;
            }

            if (
                n.my_decl->parent_declaration
                && n.my_decl->parent_declaration->cannot_be_a_copy_constructible_type()
                )
            {
                errors.emplace_back(
                    n.position(),
                    "a user-defined " + n.my_decl->name()->to_string() + " in type scope must be a member of a copyable type"
                );
                return false;
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
    int                               scope_depth                              = 0;
    int                               safe_to_move_context                     = 1;
    bool                              started_standalone_assignment_expression = false;
    bool                              started_postfix_expression               = false;
    std::vector<bool>                 started_postfix_operators_               = {false};
    bool                              started_prefix_operators                 = false;
    bool                              is_out_expression                        = false;
    bool                              inside_next_expression                   = false;
    bool                              inside_parameter_list                    = false;
    bool                              inside_parameter_identifier              = false;
    bool                              inside_returns_list                      = false;
    bool                              just_entered_for                         = false;
    token const*                      prev_token                               = nullptr;
    token const*                      prev2_token                              = nullptr;
    token const*                      accessed_member_for_ufcs                 = nullptr;
    parameter_declaration_node const* inside_out_parameter                     = {};
    std::vector<std::pair<int, int>>  uses_in_expression                       = {};
    std::vector<std::pair<int, int>>  uses_at_postfix_expression               = {};
    std::vector<std::vector<int>>     indices_of_uses_per_scope                = {{}};
    std::vector<std::vector<int>>     indices_of_activations_per_scope         = {{}};

    auto started_postfix_operators() -> bool
    {
        assert(!started_postfix_operators_.empty());
        return started_postfix_operators_.back();
    }

    auto push(std::vector<std::pair<int, int>>& uses) -> void
    {
        uses.emplace_back(
            unsafe_narrow<int>(std::ssize(indices_of_uses_per_scope) - 1),
            unsafe_narrow<int>(std::ssize(indices_of_uses_per_scope.back()))
        );
    }

    auto get(std::vector<std::pair<int, int>>& uses) -> std::span<const int>
    {
        assert(!uses.empty());
        auto [i, j] = uses.back();
        return std::span{indices_of_uses_per_scope[i]}.subspan(j);
    }

    //  Mark uses that are not safe to move
    auto pop_uses_in_expression() -> void
    {
        auto identifier = [](symbol& s) { return &std::get<symbol::active::identifier>(s.sym); };

        auto range = get(uses_in_expression);
        for (auto i : range)
        {
            auto x = identifier(symbols[i]);
            for (auto j : range)
            {
                auto y = identifier(symbols[j]);
                if (
                    i != j
                    && *x->identifier == *y->identifier
                    && x->safe_to_move_context != y->safe_to_move_context
                    && !x->is_captured
                    && !y->is_captured
                    )
                {
                    x->safe_to_move = false;
                    y->safe_to_move = false;
                }
            }
        }

        uses_in_expression.pop_back();
    }

    auto push_lifetime_scope() -> void
    {
        indices_of_uses_per_scope.emplace_back();
        indices_of_activations_per_scope.emplace_back();
    }

    auto push_use(identifier_sym sym) -> void
    {
        assert(!indices_of_uses_per_scope.empty());
        assert(sym.is_use());
        assert(sym.identifier);

        indices_of_uses_per_scope.back().push_back(cpp2::unsafe_narrow<int>(std::ssize(symbols)));
        symbols.emplace_back(scope_depth, sym);
    }

    auto push_activation(declaration_sym decl) -> void
    {
        assert(!indices_of_activations_per_scope.empty());
        assert(decl.start);

        if (
            decl.identifier
            && *decl.identifier != "_"
            )
        {
            indices_of_activations_per_scope.back().push_back(cpp2::unsafe_narrow<int>(std::ssize(symbols)));
        }
        symbols.emplace_back(scope_depth, decl);
    }

    auto push_activation(identifier_sym sym) -> void
    {
        assert(!indices_of_activations_per_scope.empty());
        assert(sym.is_using_declaration());
        assert(sym.identifier);

        indices_of_activations_per_scope.back().push_back(cpp2::unsafe_narrow<int>(std::ssize(symbols)));
        symbols.emplace_back(scope_depth, sym);
    }

    auto pop_lifetime_scope() -> void
    {
        assert(!indices_of_uses_per_scope.empty());
        assert(!indices_of_activations_per_scope.empty());

        for (auto i : indices_of_activations_per_scope.back()) {
            if (auto decl = std::get_if<symbol::active::declaration>(&symbols[i].sym))
            {
                symbols.emplace_back( scope_depth, identifier_sym( false, decl->identifier, identifier_sym::deactivation ) );
            }
            else if (auto sym = std::get_if<symbol::active::identifier>(&symbols[i].sym))
            {
                symbols.emplace_back( scope_depth, identifier_sym( false, sym->identifier, identifier_sym::deactivation ) );
            }
        }

        indices_of_uses_per_scope.pop_back();
        indices_of_activations_per_scope.pop_back();
    }

    auto end(translation_unit_node const&, int) -> void
    {
        assert(uses_in_expression.empty());
        assert(uses_at_postfix_expression.empty());
        assert(started_postfix_operators_.size() == 1);
        assert(indices_of_uses_per_scope.size() == 1);
        assert(indices_of_activations_per_scope.size() == 1);
    }

    auto start(next_expression_tag const&, int) -> void
    {
        inside_next_expression = true;
    }

    auto end(next_expression_tag  const&, int) -> void
    {
        inside_next_expression = false;
    }

    auto start(parameter_declaration_list_node const&, int) -> void
    {
        inside_parameter_list = true;
        push_lifetime_scope();
    }

    auto end(parameter_declaration_list_node const&, int) -> void
    {
        inside_parameter_list = false;
    }

    auto start(declaration_identifier_tag const&, int) -> void
    {
        inside_parameter_identifier = inside_parameter_list;
    }

    auto end(declaration_identifier_tag const&, int) -> void
    {
        inside_parameter_identifier = false;
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

        if (n.pass != passing_style::out) {
            push_activation( declaration_sym( true, n.declaration.get(), n.declaration->name(), n.declaration->initializer.get(), &n));
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
        if (*n.identifier != "for") {
             symbols.emplace_back( scope_depth, identifier_sym( false, n.identifier ) );
        }
    }

    auto end(iteration_statement_node const& n, int) -> void
    {
        symbols.emplace_back( scope_depth, identifier_sym( false, n.identifier, identifier_sym::deactivation ) );
    }

    auto start(loop_body_tag const& n, int) -> void
    {
        assert(*n.n->identifier == "for");
        symbols.emplace_back( scope_depth, identifier_sym( false, n.n->identifier ) );
        push_lifetime_scope();
        just_entered_for = true;
    }

    auto end(loop_body_tag const&, int) -> void
    {
        pop_lifetime_scope();
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
            && (
                n.identifier
                || n.is_function_expression()
                )
            //  Skip non-out parameters
            && (
                !inside_parameter_list
                || inside_out_parameter
                )
            )
        {
            push_activation( declaration_sym( true, &n, n.name(), n.initializer.get(), inside_out_parameter ) );
            if (!n.is_object()) {
                ++scope_depth;
            }
        }
    }

    auto end(declaration_node const& n, int) -> void
    {
        if (auto f = std::get_if<declaration_node::a_function>(&n.type)) {
            if (std::get_if<function_type_node::list>(&(*f)->returns)) {
                pop_lifetime_scope();
            }
            pop_lifetime_scope();
        }

        if (
            !n.is_alias()
            //  Skip type scope (member) variables
            && !(n.parent_is_type() && n.is_object())
            //  Skip unnamed variables
            && (
                n.identifier
                || n.is_function_expression()
                )
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

    auto is_binary_operator(lexeme l) -> bool {
        switch (l) {
        break;case lexeme::PlusPlus:
              case lexeme::MinusMinus:
              case lexeme::Arrow:
              case lexeme::Tilde:
              case lexeme::Not:         return false;
        break;case lexeme::Plus:
              case lexeme::Minus:       return !started_prefix_operators;
        break;case lexeme::Multiply:
              case lexeme::Ampersand:   return !started_postfix_operators();
        break;default:                  return is_operator(l);
        }
    }

    auto start(token const& t, int) -> void
    {
        auto guard = finally([&]() {
            prev2_token = prev_token;
            prev_token = &t;
        });

        if (
            is_binary_operator(t.type())
            || (
                t.type() == cpp2::lexeme::Keyword
                && (
                    t == "is"
                    || t == "as"
                    )
                )
            )
        {
            ++safe_to_move_context;
        }

        //  Mark captures
        if (t.type() == lexeme::Dollar)
        {
            for (auto i : get(uses_at_postfix_expression))
            {
                auto& sym = std::get<symbol::active::identifier>(symbols[i].sym);
                assert(sym.is_use());
                sym.is_captured = true;
            }
        }

        //  Further look at variable identifiers only
        if (
            t.type() != lexeme::Identifier
            && t != "this"
            && !accessed_member_for_ufcs
            )
        {
            return;
        }

        //  By giving tokens an order during sema
        //  generated code can be equally checked
        static index_t global_token_counter = 1;            // TODO static
        t.set_global_token_order( global_token_counter++ );

        auto started_member_access =
            prev_token
            && prev_token->type() == lexeme::Dot;
        auto started_this_member_access =
            started_member_access
            && prev2_token
            && *prev2_token == "this";

        //  If this is the first identifier since we started a new assignment,
        //  expression, then it's the left-hand side (target) of the assignment
        if (started_standalone_assignment_expression)
        {
            push_use( identifier_sym( true, &t ) );
            started_standalone_assignment_expression = false;   // we were the consumer for this information
        }

        //  If this is the first identifier since we saw an `out` expression,
        //  then it's the argument of the `out` expression
        //  TODO: for now we just take the first identifier, and we should make
        //  this an id-expression and add a sema rule to disallow complex expressions
        else if (is_out_expression)
        {
            push_use( identifier_sym( true, &t ) );
            is_out_expression = false;
        }

        //  Otherwise it's just an identifier use (if it's not a parameter name) and
        //  it's the first identifier of a postfix_expressions
        //  or the function name in a UFCS expression
        else if (
            started_postfix_expression
            || started_member_access
            || started_this_member_access
            || accessed_member_for_ufcs
            )
        {
            started_postfix_expression = false;
            if (!inside_parameter_identifier)
            {
                //  Put this into the table if it's a use of an object in scope
                //  or it's a 'copy' parameter (but to be a use it must be after
                //  the declaration, not the token in the decl's name itself)
                //  including an implicit 'this' access of a member name
                auto push_use = [&](token const* u, bool is_dot_access = false) {
                    this->push_use( identifier_sym(
                        false,
                        u,
                        {},
                        !inside_next_expression,
                        safe_to_move_context,
                        is_dot_access
                    ) );
                };
                if (accessed_member_for_ufcs) {
                    if (t == "(") {
                        push_use(accessed_member_for_ufcs, true);
                    }
                    accessed_member_for_ufcs = nullptr;
                }
                else if (auto decl = get_declaration_of(t, false, !started_this_member_access);
                    decl
                    && decl->declaration->name() != &t
                    )
                {
                    if (!started_member_access) {
                        push_use(&t);
                    }
                    else {
                        accessed_member_for_ufcs = &t;
                    }
                }
            }
        }
    }

    auto end(statement_node const& n, int) -> void
    {
        if (n.parameters) {
            pop_lifetime_scope();
        }
    }

    auto start(using_statement_node const& n, int) -> void
    {
        if (auto id = get_if<id_expression_node::qualified>(&n.id->id);
            !n.for_namespace
            && id
            )
        {
            push_activation( identifier_sym( false, (*id)->ids.back().id->identifier, identifier_sym::using_declaration ) );
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
        push_lifetime_scope();
    }

    auto end(compound_statement_node const& n, int) -> void
    {
        pop_lifetime_scope();
        symbols.emplace_back(
            scope_depth,
            compound_sym{ false, &n, kind_of(n) }
        );
        --scope_depth;
    }

    template<typename T> auto start(T const&, int) -> void
        requires std::is_same_v<T, expression_node>
                 || std::is_same_v<T, logical_or_expression_node>
    {
        push(uses_in_expression);
    }

    template<typename T> auto end(T const&, int) -> void
        requires std::is_same_v<T, expression_node>
                 || std::is_same_v<T, logical_or_expression_node>
    {
        pop_uses_in_expression();
    }

    auto start(assignment_expression_node const& n, int) -> void
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

    auto start(bit_and_expression_node const&, int) -> void
    {
        started_postfix_operators_.push_back(false);
    }

    auto end(bit_and_expression_node const&, int) -> void
    {
        started_postfix_operators_.pop_back();
    }

    auto start(prefix_expression_node const&, int) -> void
    {
        started_prefix_operators = true;
    }

    auto start(postfix_expression_node const& n, int) -> void
    {
        started_prefix_operators = false;
        started_postfix_operators_.push_back(true);
        if (auto id = std::get_if<primary_expression_node::id_expression>(&n.expr->expr)) {
            started_postfix_expression = (*id)->is_unqualified();
        }
        push(uses_at_postfix_expression);
    }

    auto end(postfix_expression_node const&, int) -> void
    {
        started_postfix_operators_.pop_back();
        uses_at_postfix_expression.pop_back();
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
