
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
//  Parser
//===========================================================================

#ifndef CPP2_PARSE_H
#define CPP2_PARSE_H

#include "lex.h"


namespace cpp2 {

auto violates_lifetime_safety = false;

//-----------------------------------------------------------------------
//  Operator categorization
//

//G prefix-operator:
//G     one of  '!' '-' '+'
//GT     parameter-direction
//G
auto is_prefix_operator(token const& tok)
    -> bool
{
    switch (tok.type()) {
    break;case lexeme::Not:
          case lexeme::Minus:
          case lexeme::Plus:
        return true;
    break;default:
        return false;
    }
}


//G postfix-operator:
//G     one of  '++' '--' '*' '&' '~' '$' '...'
//G
auto is_postfix_operator(lexeme l)
    -> bool
{
    switch (l) {
    break;case lexeme::PlusPlus:
          case lexeme::MinusMinus:
          case lexeme::Multiply:
          case lexeme::Ampersand:
          case lexeme::Tilde:
          case lexeme::Dollar:
          case lexeme::Ellipsis:
        return true;
    break;default:
        return false;
    }
}


//G assignment-operator:
//G     one of  '=' '*=' '/=' '%=' '+=' '-=' '>>=' '<<=' '&=' '^=' '|='
//G
auto is_assignment_operator(lexeme l)
    -> bool
{
    switch (l) {
    break;case lexeme::Assignment:
          case lexeme::MultiplyEq:
          case lexeme::SlashEq:
          case lexeme::ModuloEq:
          case lexeme::PlusEq:
          case lexeme::MinusEq:
          case lexeme::RightShiftEq:
          case lexeme::LeftShiftEq:
          case lexeme::AmpersandEq:
          case lexeme::CaretEq:
          case lexeme::PipeEq:
        return true;
    break;default:
        return false;
    }
}


//-----------------------------------------------------------------------
//
//  Parse tree node types
//
//-----------------------------------------------------------------------
//

//-----------------------------------------------------------------------
//  try_visit
//
//  Helper to visit whatever is in a variant where each
//  alternative is a smart pointer
//
template <int I>
auto try_visit(auto& variant, auto& visitor, int depth)
    -> void
{
    if (variant.index() == I) {
        auto const& s = std::get<I>(variant);
        assert (s);
        s->visit(visitor, depth+1);
    }
}


struct expression_list_node;
struct id_expression_node;
struct declaration_node;
struct inspect_expression_node;
struct literal_node;
struct template_argument;


struct primary_expression_node
{
    enum active { empty=0, identifier, expression_list, id_expression, declaration, inspect, literal };
    std::variant<
        std::monostate,
        token const*,
        std::unique_ptr<expression_list_node>,
        std::unique_ptr<id_expression_node>,
        std::unique_ptr<declaration_node>,
        std::unique_ptr<inspect_expression_node>,
        std::unique_ptr<literal_node>
    > expr;
    // Cache to work around <https://github.com/llvm/llvm-project/issues/73336>.
    bool expression_list_is_fold_expression = false;

    // Out-of-line definition of the dtor is necessary due to the forward-declared
    // type(s) used in a std::unique_ptr as a member
    ~primary_expression_node();

    //  API
    //
    auto is_fold_expression() const
        -> bool;

    auto is_identifier() const
        -> bool;

    auto is_id_expression() const
        -> bool;

    auto is_unqualified_id() const
        -> bool;

    auto is_expression_list() const
        -> bool;

    auto get_expression_list() const
        -> expression_list_node const*;

    auto is_literal() const
        -> bool;

    auto get_literal() const
        -> literal_node const*;

    auto template_arguments() const -> std::vector<template_argument> const&;

    auto get_token() const -> token const*;

    auto to_string() const
        -> std::string;

    //  Internals
    //
    auto position() const -> source_position;
    auto visit(auto& v, int depth) -> void;
};


struct literal_node {
    //  A literal is represented as a sequence of tokens:
    //      - length 1: a literal (most common)
    //      - length 2: a literal and a user-defined suffix
    //      - length >= 2: a series of one or more of either of the above for string literals
    std::vector <token const*> pieces = {};

    //  API
    //
    auto get_token() const
        -> token const*
    {
        assert(!pieces.empty());
        return pieces.front();
    }

    auto to_string() const
        -> std::string
    {
        assert(!pieces.empty());
        auto ret = std::string{};

        for (bool first = true; auto p : pieces)
        {
            assert(p);

            //  Add a space to non-first pieces that start with " (i.e., not a UDL suffix)
            if (
                !std::exchange(first, false)
                && p->as_string_view().starts_with("\"")
                ) 
            {
                ret += " ";
            }

            ret += *p;
        }

        return ret;
    }

    auto has_user_defined_suffix()
        -> bool
    {
        return
            std::ssize(pieces) > 1
            && !pieces[1]->as_string_view().starts_with("\"")
            ;
    }

    //  Internals
    //
    auto position() const
        -> source_position
    {
        assert(!pieces.empty());
        return get_token()->position();
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        for (auto p : pieces) {
            assert(p);
            p->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};


struct postfix_expression_node;

struct prefix_expression_node
{
    std::vector<token const*> ops;
    std::unique_ptr<postfix_expression_node> expr;

    // Out-of-line definition of the dtor is necessary due to the forward-declared
    // type(s) used in a std::unique_ptr as a member
    ~prefix_expression_node();

    //  API
    //
    auto is_fold_expression() const
        -> bool;

    auto is_identifier() const
        -> bool;

    auto is_id_expression() const
        -> bool;

    auto is_unqualified_id() const
        -> bool;

    auto is_expression_list() const
        -> bool;

    auto get_expression_list() const
        -> expression_list_node const*;

    auto get_postfix_expression_node() const
        -> postfix_expression_node *
    {
        assert(expr);
        return expr.get();
    }

    auto is_literal() const
        -> bool;

    auto get_literal() const
        -> literal_node const*;

    auto is_result_a_temporary_variable() const -> bool;

    auto to_string() const
        -> std::string;

    //  Internals
    //
    auto position() const -> source_position;
    auto visit(auto& v, int depth) -> void;
};


struct expression_node;


template<
    String   Name,
    typename Term
>
struct binary_expression_node
{
    std::unique_ptr<Term>  expr;
    expression_node const* my_expression = {};

    binary_expression_node();

    // Out-of-line definition of the dtor is necessary due to the forward-declared
    // type(s) used as Term in a std::unique_ptr as a member
    ~binary_expression_node();

    struct term
    {
        token const* op;
        std::unique_ptr<Term> expr;
    };
    std::vector<term> terms;


    //  API
    //
    auto is_fold_expression() const
        -> bool
    {
        //  This is a fold-expression if any subexpression
        //  has an identifier named "..."
        auto ret = expr->is_fold_expression();
        for (auto& x : terms) {
            ret |= x.expr->is_fold_expression();
        }
        return ret;
    }

    auto lhs_is_id_expression() const
        -> bool
    {
        return expr->is_id_expression();
    }

    auto is_standalone_expression() const
        -> bool;

    auto terms_size() const
        -> int
    {
        return unsafe_narrow<int>(std::ssize(terms));
    }

    auto is_identifier() const
        -> bool
    {
        return terms.empty() && expr->is_identifier();
    }

    auto is_id_expression() const
        -> bool
    {
        return terms.empty() && expr->is_id_expression();
    }

    auto is_unqualified_id() const
        -> bool
    {
        return terms.empty() && expr->is_unqualified_id();
    }

    auto is_expression_list() const
        -> bool
    {
        return terms.empty() && expr->is_expression_list();
    }

    auto get_expression_list() const
        -> expression_list_node const*
    {
        if (is_expression_list()) {
            return expr->get_expression_list();
        }
        return {};
    }

    auto is_literal() const
        -> bool
    {
        return get_literal();
    }

    auto get_literal() const
        -> literal_node const*
    {
        if (!terms.empty()) {
            return nullptr;
        }
        //  Else
        return expr->get_literal();
    }

    //  Get left-hand postfix-expression
    auto get_postfix_expression_node() const
        -> postfix_expression_node *
    {
        assert(expr);
        return expr->get_postfix_expression_node();
    }

    //  Get first right-hand postfix-expression, if there is one
    auto get_second_postfix_expression_node() const
        -> postfix_expression_node *
    {
        if (!terms.empty()) {
            assert(terms.front().expr);
            return terms.front().expr->get_postfix_expression_node();
        }
        //  else
        return {};
    }

    //  "Simple" means binary (size>0) and not chained (size<2)
    struct get_lhs_rhs_if_simple_binary_expression_with_ret {
        postfix_expression_node* lhs;
        Term*                    rhs;
    };
    auto get_lhs_rhs_if_simple_binary_expression_with(lexeme op) const
        -> get_lhs_rhs_if_simple_binary_expression_with_ret
    {
        if (
            std::ssize(terms) == 1
            && terms[0].op->type() == op
            )
        {
            return {
                get_postfix_expression_node(),
                terms.front().expr.get()
            };
        }
        //  Else
        return { nullptr, nullptr };
    }

    auto is_result_a_temporary_variable() const -> bool {
        if constexpr (std::string_view(Name.value) == "assignment") {
            assert(expr);
            return expr->is_result_a_temporary_variable();
        } else {
            if (terms.empty()) {
                assert(expr);
                return expr->is_result_a_temporary_variable();
            } else {
                return true;
            }
        }
    }

    auto to_string() const
        -> std::string
    {
        assert (expr);
        auto ret = expr->to_string();
        for (auto const& x : terms) {
            assert (x.op);
            ret += " " + x.op->to_string();
            assert (x.expr);
            ret += " " + x.expr->to_string();
        }
        return ret;
    }


    //  Internals
    //
    auto position() const
        -> source_position
    {
        assert (expr);
        return expr->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        assert (expr);
        expr->visit(v, depth+1);
        for (auto const& x : terms) {
            assert (x.op);
            v.start(*x.op, depth+1);
            assert (x.expr);
            x.expr->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};


struct is_as_expression_node;

using multiplicative_expression_node = binary_expression_node< "multiplicative" , is_as_expression_node          >;
using additive_expression_node       = binary_expression_node< "additive"       , multiplicative_expression_node >;
using shift_expression_node          = binary_expression_node< "shift"          , additive_expression_node       >;
using compare_expression_node        = binary_expression_node< "compare"        , shift_expression_node          >;
using relational_expression_node     = binary_expression_node< "relational"     , compare_expression_node        >;
using equality_expression_node       = binary_expression_node< "equality"       , relational_expression_node     >;
using bit_and_expression_node        = binary_expression_node< "bit-and"        , equality_expression_node       >;
using bit_xor_expression_node        = binary_expression_node< "bit-xor"        , bit_and_expression_node        >;
using bit_or_expression_node         = binary_expression_node< "bit-or"         , bit_xor_expression_node        >;
using logical_and_expression_node    = binary_expression_node< "logical-and"    , bit_or_expression_node         >;
using logical_or_expression_node     = binary_expression_node< "logical-or"     , logical_and_expression_node    >;
using assignment_expression_node     = binary_expression_node< "assignment"     , logical_or_expression_node     >;


struct assignment_expression_lhs_rhs {
    postfix_expression_node*    lhs;
    logical_or_expression_node* rhs;
};


struct expression_statement_node;

struct expression_node
{
    static inline std::vector<expression_node*> current_expressions = {};   // TODO: static ?

    std::unique_ptr<assignment_expression_node> expr;
    int num_subexpressions = 0;
    expression_statement_node const* my_statement = {};

    expression_node();

    // API
    //
    auto is_fold_expression() const
        -> bool
    {
        //  This is a fold-expression if any subexpression
        //  has an identifier named "..."
        return expr->is_fold_expression();
    }

    auto is_standalone_expression() const
        -> bool;

    auto subexpression_count() const
        -> int
    {
        return num_subexpressions;
    }

    auto is_identifier() const
        -> bool
    {
        return expr->is_identifier();
    }

    auto is_id_expression() const
        -> bool
    {
        return expr->is_id_expression();
    }

    auto is_unqualified_id() const
        -> bool
    {
        return expr->is_unqualified_id();
    }

    auto is_expression_list() const
        -> bool
    {
        return expr->is_expression_list();
    }

    auto get_expression_list() const
        -> expression_list_node const*
    {
        if (is_expression_list()) {
            return expr->get_expression_list();
        }
        return {};
    }

    auto is_literal() const
        -> bool
    {
        return get_literal();
    }

    auto get_literal() const
        -> literal_node const*
    {
        return expr->get_literal();
    }

    auto get_lhs_rhs_if_simple_assignment() const
        -> assignment_expression_lhs_rhs;

    auto to_string() const
        -> std::string
    {
        assert (expr);
        return expr->to_string();
    }

    //  Internals
    //
    auto position() const -> source_position
    {
        assert (expr);
        return expr->position();
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        assert (expr);
        expr->visit(v, depth+1);
        v.end(*this, depth);
    }
};


template<
    String   Name,
    typename Term
>
binary_expression_node<Name, Term>::binary_expression_node() {
    if (!expression_node::current_expressions.empty()) {
        my_expression = expression_node::current_expressions.back();
    }
}


template<
    String   Name,
    typename Term
>
auto binary_expression_node<Name, Term>::is_standalone_expression() const
    -> bool
{
    return
        my_expression
        && my_expression->is_standalone_expression()
        ;
}


enum class passing_style { in=0, copy, inout, out, move, forward, invalid };
auto to_passing_style(token const& t) -> passing_style {
    if (t.type() == lexeme::Identifier) {
        if (t == "in"     ) { return passing_style::in; }
        if (t == "copy"   ) { return passing_style::copy; }
        if (t == "inout"  ) { return passing_style::inout; }
        if (t == "out"    ) { return passing_style::out; }
        if (t == "move"   ) { return passing_style::move; }
        if (t == "forward") { return passing_style::forward; }
    }
    return passing_style::invalid;
}
auto to_string_view(passing_style pass) -> std::string_view {
    switch (pass) {
    break;case passing_style::in     : return "in";
    break;case passing_style::copy   : return "copy";
    break;case passing_style::inout  : return "inout";
    break;case passing_style::out    : return "out";
    break;case passing_style::move   : return "move";
    break;case passing_style::forward: return "forward";
    break;default                    : return "INVALID passing_style";
    }
}


struct expression_list_node
{
    token const* open_paren  = {};
    token const* close_paren = {};
    bool inside_initializer  = false;
    bool default_initializer = false;

    struct term {
        passing_style                    pass = {};
        std::unique_ptr<expression_node> expr;

        auto visit(auto& v, int depth) -> void
        {
            v.start(*this, depth);
            assert(expr);
            expr->visit(v, depth+1);
            v.end(*this, depth);
        }
    };
    std::vector< term > expressions;


    //  API
    //
    auto is_fold_expression() const
        -> bool
    {
        //  This is a fold-expression if any subexpression
        //  has an identifier named "..."
        auto ret = false;
        for (auto& x : expressions) {
            ret |= x.expr->is_fold_expression();
        }
        return ret;
    }

    auto to_string() const
        -> std::string
    {
        auto ret = std::string{};

        if (open_paren) {
            ret += *open_paren;
        }

        for (auto& term : expressions) {
            ret += term.expr->to_string();
        }

        if (open_paren) {
            ret += *open_paren;
        }

        return ret;
    }


    //  Internals
    //
    auto position() const
        -> source_position
    {
        //  Make sure this got set
        assert (open_paren);
        return open_paren->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        for (auto& x : expressions) {
            x.visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};

auto primary_expression_node::is_identifier() const
    -> bool
{
    return expr.index() == identifier;
}

auto primary_expression_node::is_id_expression() const
    -> bool
{
    return expr.index() == id_expression;
}

auto primary_expression_node::is_expression_list() const
    -> bool
{
    return expr.index() == expression_list;
}

auto primary_expression_node::get_expression_list() const
    -> expression_list_node const*
{
    if (is_expression_list()) {
        return std::get<expression_list>(expr).get();
    }
    return {};
}

auto primary_expression_node::is_literal() const
    -> bool
{
    return get_literal();
}

auto primary_expression_node::get_literal() const
    -> literal_node const*
{
    if (auto lit = std::get_if<literal>(&expr)) {
        return (*lit).get();
    }
    //  Else
    return nullptr;
}


struct expression_statement_node
{
    static inline std::vector<expression_statement_node*> current_expression_statements = {};   // TODO: static ?

    std::unique_ptr<expression_node> expr;
    bool has_semicolon = false;

    //  API
    //
    auto subexpression_count() const
        -> int
    {
        assert (expr);
        return expr->subexpression_count();
    }

    auto to_string() const
        -> std::string
    {
        assert (expr);
        return expr->to_string();
    }

    //  Internals
    //
    auto position() const
        -> source_position
    {
        assert (expr);
        return expr->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        assert (expr);
        expr->visit(v, depth+1);
        v.end(*this, depth);
    }
};


auto expression_node::is_standalone_expression() const
    -> bool
{
    return
        my_statement
        && my_statement->subexpression_count() == subexpression_count()
        ;
}


struct capture {
    postfix_expression_node* capture_expr;
    std::string              cap_sym = {};
    std::string              str = {};
    std::string              str_suppressed_move = {};
    auto operator==(postfix_expression_node* p) { return capture_expr == p; }
};

struct capture_group {
    std::vector<capture> members;

    auto add(postfix_expression_node* p)
        -> void
    {
        members.push_back({p});
    }

    auto remove(postfix_expression_node* p)
        -> void;

    ~capture_group();
};


struct postfix_expression_node
{
    std::unique_ptr<primary_expression_node> expr;

    struct term
    {
        token const* op;

        //  This is used if *op is . - can be null
        std::unique_ptr<id_expression_node> id_expr = {};

        //  These are used if *op is [ or ( - can be null
        std::unique_ptr<expression_list_node> expr_list = {};
        token const* op_close = {};
    };
    std::vector<term> ops;
    capture_group* cap_grp = {};

    ~postfix_expression_node();

    //  API
    //
    auto is_fold_expression() const
        -> bool
    {
        //  This is a fold-expression if any subexpression
        //  has an identifier named "..."
        return expr->is_fold_expression();
    }

    auto is_identifier() const
        -> bool
    {
        return ops.empty() && expr->is_identifier();
    }

    auto is_id_expression() const
        -> bool
    {
        return ops.empty() && expr->is_id_expression();
    }

    auto is_unqualified_id() const
        -> bool
    {
        return ops.empty() && expr->is_unqualified_id();
    }

    auto is_expression_list() const
        -> bool
    {
        return ops.empty() && expr->is_expression_list();
    }

    auto get_expression_list() const
        -> expression_list_node const*
    {
        if (is_expression_list()) {
            return expr->get_expression_list();
        }
        return {};
    }

    auto is_literal() const
        -> bool
    {
        return get_literal();
    }

    auto get_literal() const
        -> literal_node const*
    {
        if (!ops.empty()) {
            return nullptr;
        }
        //  Else
        return expr->get_literal();
    }

    auto get_first_token_ignoring_this() const
        -> token const*;

    auto is_result_a_temporary_variable() const -> bool {
        if (ops.empty()) {
            return false;
        } else {
            return (ops.front().op->type() == lexeme::Ampersand
                    || ops.front().op->type() == lexeme::Tilde);
        }
    }

    auto to_string() const
        -> std::string;

    //  Internals
    //
    auto position() const -> source_position
    {
        assert (expr);
        return expr->position();
    }

    auto visit(auto& v, int depth) -> void;
};

auto prefix_expression_node::is_fold_expression() const
    -> bool
{
    //  This is a fold-expression if any subexpression
    //  has an identifier named "..."
    return expr->is_fold_expression();
}

auto prefix_expression_node::is_identifier() const
    -> bool
{
    return ops.empty() && expr->is_identifier();
}

auto prefix_expression_node::is_id_expression() const
    -> bool
{
    return ops.empty() && expr->is_id_expression();
}

auto prefix_expression_node::is_unqualified_id() const
    -> bool
{
    return ops.empty() && expr->is_unqualified_id();
}

auto prefix_expression_node::is_expression_list() const
    -> bool
{
    return ops.empty() && expr->is_expression_list();
}

auto prefix_expression_node::get_expression_list() const
    -> expression_list_node const*
{
    if (is_expression_list()) {
        return expr->get_expression_list();
    }
    return {};
}

auto prefix_expression_node::is_literal() const
    -> bool
{
    return get_literal();
}

auto prefix_expression_node::get_literal() const
    -> literal_node const*
{
    if (!ops.empty()) {
        return nullptr;
    }
    //  Else
    return expr->get_literal();
}

auto prefix_expression_node::is_result_a_temporary_variable() const -> bool {
    if (ops.empty()) {
        return expr->is_result_a_temporary_variable();
    } else {
        return true;
    }
}


auto expression_node::get_lhs_rhs_if_simple_assignment() const
    -> assignment_expression_lhs_rhs
{
    auto ret = expr->get_lhs_rhs_if_simple_binary_expression_with(lexeme::Assignment);
    return { ret.lhs, ret.rhs };
}


auto capture_group::remove(postfix_expression_node* p)
    -> void
{
    p->cap_grp = {};
    auto old_size = members.size();
    std::erase(members, p);
    assert (members.size() == old_size-1);
}


capture_group::~capture_group()
{
    assert (members.empty());
    //  We shouldn't need to do this:
    //      while (!members.empty()) {
    //          remove(members.front().capture_expr);
    //      }
    //  if the capture_group outlives the tree of things that can point to it
    //   => each node with a capture_group should declare it as the first member
    //      before any other node that could own a postfix_expression that could
    //      point back up to that capture_group
}


auto prefix_expression_node::to_string() const
    -> std::string
{
    auto ret = std::string{};

    for (auto const& x : ops) {
        assert (x);
        ret += x->as_string_view();
    }

    assert (expr);
    return ret + expr->to_string();
}


auto prefix_expression_node::position() const
    -> source_position
{
    if (std::ssize(ops) > 0) {
        return ops.front()->position();
    }
    assert (expr);
    return expr->position();
}


auto prefix_expression_node::visit(auto& v, int depth)
    -> void
{
    v.start(*this, depth);
    for (auto const& x : ops) {
        assert (x);
        v.start(*x, depth+1);
    }
    assert (expr);
    expr->visit(v, depth+1);
    v.end(*this, depth);
}


struct type_id_node;
struct template_args_tag { };

struct template_argument
{
    enum active { empty=0, expression, type_id };
    source_position comma;
    std::variant<
        std::monostate,
        std::unique_ptr<expression_node>,
        std::unique_ptr<type_id_node>
    > arg;

    // The type needs to be movable
    // The copy ctor+operator are implicitly deleted due to the std::unique_ptr member
    // Because a forward-declared type is used in a std::unique_ptr as a member an out-of-line dtor is necessary
    // Because of the OOL dtor together with the fact that the copy ctor+operator are deleted
    // the move ctor+operator need to be explicitly defaulted
    // As a result the default constructor also needs to be explicitly defaulted
    template_argument() = default;
    template_argument(template_argument&&) = default;
    template_argument& operator=(template_argument&&) = default;

    ~template_argument();

    auto to_string() const
        -> std::string;
};

// Used by functions that must return a reference to an empty arg list
inline std::vector<template_argument> const no_template_args;

struct unqualified_id_node
{
    token const* identifier      = {};  // required

    // These are used only if it's a template-id
    source_position open_angle  = {};
    source_position close_angle = {};

    std::vector<template_argument> template_args;

    auto template_arguments() const
        -> std::vector<template_argument> const&
    {
        return template_args;
    }

    auto get_token() const
        -> token const*
    {
        if (open_angle == source_position{}) {
            assert (identifier);
            return identifier;
        }
        // else
        return {};
    }

    auto to_string() const
        -> std::string;

    auto position() const
        -> source_position
    {
        assert (identifier);
        return identifier->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        assert (identifier);
        v.start(*identifier, depth+1);

        if (open_angle != source_position{}) {
            //  Inform the visitor that this is a template args list
            v.start(template_args_tag{}, depth);
            assert(open_angle  != source_position{});
            assert(close_angle != source_position{});
            assert(template_args.empty()
                   || template_args.front().comma == source_position{});
            for (auto& a : template_args) {
                try_visit<template_argument::expression>(a.arg, v, depth+1);
                try_visit<template_argument::type_id   >(a.arg, v, depth+1);
            }
            v.end(template_args_tag{}, depth);
        }

        v.end(*this, depth);
    }
};


struct qualified_id_node
{
    struct term {
        token const* scope_op;
        std::unique_ptr<unqualified_id_node> id = {};

        term( token const* o ) : scope_op{o} { }
    };
    std::vector<term> ids;

    auto template_arguments() const
        -> std::vector<template_argument> const&
    {
        return ids.back().id->template_arguments();
    }

    auto get_token() const
        -> token const*
    {
        if (
            std::ssize(ids) == 1
            && !ids.front().scope_op
            )
        {
            assert (ids.front().id);
            return ids.front().id->get_token();
        }
        // else
        return {};
    }

    auto to_string() const
        -> std::string
    {
        auto ret = std::string{};
        for (auto& term : ids) {
            if (term.scope_op) {
                ret += term.scope_op->as_string_view();
            }
            assert (term.id);
            ret += term.id->to_string();
        }
        return ret;
    }

    auto get_first_token() const
        -> token const*
    {
        assert (
            !ids.empty()
            && ids.front().id
        );
        return ids.front().id->get_token();
    }

    auto position() const
        -> source_position
    {
        assert (!ids.empty());
        if (ids.front().scope_op) {
            return ids.front().scope_op->position();
        }
        else {
            assert (ids.front().id);
            return ids.front().id->position();
        }
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        for (auto const& x : ids) {
            if (x.scope_op) {
                x.scope_op->visit(v, depth+1);
            }
            assert(x.id);
            x.id->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};


struct type_id_node
{
    source_position pos;

    std::vector<token const*> pc_qualifiers;
    token const* address_of                 = {};
    token const* dereference_of             = {};
    int dereference_cnt                     = {};
    token const* suspicious_initialization  = {};

    enum active { empty=0, qualified, unqualified, keyword };
    std::variant<
        std::monostate,
        std::unique_ptr<qualified_id_node>,
        std::unique_ptr<unqualified_id_node>,
        token const*
    > id;

    auto is_wildcard() const
        -> bool
    {
        return
            id.index() == type_id_node::empty
            || (get_token() && *get_token() == "_")
            ;
    }

    auto is_pointer_qualified() const
        -> bool
    {
        for (auto q : pc_qualifiers) {
            if (q->type() == lexeme::Multiply) {
                return true;
            }
        }
        return false;
    }

    auto is_concept() const
        -> bool
    {
        auto tok = get_token();
        return tok && *tok == "concept";
    }

    auto template_arguments() const
        -> std::vector<template_argument> const&
    {
        if (id.index() == unqualified) {
            return std::get<unqualified>(id)->template_arguments();
        }
        // else
        return std::get<qualified>(id)->template_arguments();
    }

    auto to_string() const
        -> std::string
    {
        switch (id.index()) {
        break;case empty:
            return {};
        break;case qualified:
            return std::get<qualified>(id)->to_string();
        break;case unqualified:
            return std::get<unqualified>(id)->to_string();
        break;case keyword:
            return std::get<keyword>(id)->to_string();
        break;default:
            assert(!"ICE: invalid type_id state");
        }
        // else
        return {};
    }

    auto get_token() const
        -> token const*
    {
        switch (id.index()) {
        break;case empty:
            return {};
        break;case qualified:
            return {};
        break;case unqualified:
            return get<unqualified>(id)->get_token();
        break;case keyword:
            return get<keyword>(id);
        break;default:
            assert(!"ICE: invalid type_id state");
        }
        // else
        return {};
    }

    auto position() const
        -> source_position
    {
        return pos;
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        for (auto q : pc_qualifiers) {
            v.start(*q, depth+1);
        }
        try_visit<qualified  >(id, v, depth);
        try_visit<unqualified>(id, v, depth);
        try_visit<keyword    >(id, v, depth);
        v.end(*this, depth);
    }
};

auto unqualified_id_node::to_string() const
    -> std::string
{
    assert(identifier);
    auto ret = identifier->to_string();
    if (open_angle != source_position{}) {
        auto separator = std::string{"<"};
        for (auto& t : template_args) {
            ret += separator;
            assert(t.arg.index() != template_argument::empty);
            if (t.arg.index() == template_argument::expression) {
                ret += std::get<template_argument::expression>(t.arg)->to_string();
            }
            else if (t.arg.index() == template_argument::type_id) {
                ret += std::get<template_argument::type_id>(t.arg)->to_string();
            }
            separator = ",";
        }
        if (std::ssize(template_args) > 0) {
            ret += ">";
        }
    }
    return ret;
}

auto template_argument::to_string() const
    -> std::string
{
    switch (arg.index()) {
    break;case empty:
        return {};
    break;case expression:
        return std::get<expression>(arg)->to_string();
    break;case type_id:
        return std::get<type_id>(arg)->to_string();
    break;default:
        assert(!"ICE: invalid template_argument state");
    }
    // else
    return {};
}


struct is_as_expression_node
{
    std::unique_ptr<prefix_expression_node> expr;

    struct term
    {
        token const* op = {};

        //  This is used if *op is a type - can be null
        std::unique_ptr<type_id_node> type = {};

        //  This is used if *op is an expression - can be null
        std::unique_ptr<expression_node> expr = {};
    };
    std::vector<term> ops;


    //  API
    //
    auto is_fold_expression() const
        -> bool
    {
        //  This is a fold-expression if any subexpression
        //  has an identifier named "..."
        return expr->is_fold_expression();
    }

    auto is_identifier() const
        -> bool
    {
        return ops.empty() && expr->is_identifier();
    }

    auto is_id_expression() const
        -> bool
    {
        return ops.empty() && expr->is_id_expression();
    }

    auto is_unqualified_id() const
        -> bool
    {
        return ops.empty() && expr->is_unqualified_id();
    }

    auto is_expression_list() const
        -> bool
    {
        return ops.empty() && expr->is_expression_list();
    }

    auto get_expression_list() const
        -> expression_list_node const*
    {
        if (is_expression_list()) {
            return expr->get_expression_list();
        }
        return {};
    }

    auto is_literal() const
        -> bool
    {
        return get_literal();
    }

    auto get_literal() const
        -> literal_node const*
    {
        if (!ops.empty()) {
            return nullptr;
        }
        //  Else
        return expr->get_literal();
    }

    auto get_postfix_expression_node() const
        -> postfix_expression_node *
    {
        assert(expr);
        return expr->get_postfix_expression_node();
    }

    auto is_result_a_temporary_variable() const -> bool {
        if (ops.empty()) {
            assert(expr);
            return expr->is_result_a_temporary_variable();
        } else {
            return true;
        }
    }

    auto to_string() const
        -> std::string
    {
        assert (expr);
        auto ret = expr->to_string();
        for (auto const& x : ops) {
            assert (x.op);
            ret += " " + x.op->to_string();
            if (x.type) {
                ret += " " + x.type->to_string();
            }
            if (x.expr) {
                ret += " " + x.expr->to_string();
            }
        }
        return ret;
    }

    //  Internals
    //
    auto position() const
        -> source_position
    {
        assert (expr);
        return expr->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        assert (expr);
        expr->visit(v, depth+1);
        for (auto const& x : ops) {
            assert (x.op);
            v.start(*x.op, depth+1);
            if (x.type) {
                x.type->visit(v, depth+1);
            }
            if (x.expr) {
                x.expr->visit(v, depth+1);
            }
        }
        v.end(*this, depth);
    }
};


expression_node::expression_node()
{
    if (!expression_statement_node::current_expression_statements.empty()) {
        my_statement = expression_statement_node::current_expression_statements.back();
    }
}


struct id_expression_node
{
    source_position pos;

    enum active { empty=0, qualified, unqualified };
    std::variant<
        std::monostate,
        std::unique_ptr<qualified_id_node>,
        std::unique_ptr<unqualified_id_node>
    > id;

    auto template_arguments() const
        -> std::vector<template_argument> const&
    {
        if (is_unqualified()) {
            return std::get<unqualified>(id)->template_arguments();
        }
        // else
        return std::get<qualified>(id)->template_arguments();
    }

    auto is_fold_expression() const
        -> bool
    {
        //  This is a fold-expression if any subexpression has
        //  has an identifier named "..."
        auto tok = get_token();
        return tok && *tok == "...";
    }

    auto is_empty() const
        -> bool
    {
        return id.index() == empty;
    }

    auto is_qualified() const
        -> bool
    {
        return id.index() == qualified;
    }

    auto is_unqualified() const
        -> bool
    {
        return id.index() == unqualified;
    }

    auto get_token() const
        -> token const*
    {
        if (id.index() == unqualified) {
            return std::get<unqualified>(id)->get_token();
        }
        // else
        return {};
    }

    auto to_string() const
        -> std::string
    {
        if (id.index() == qualified) {
            return std::get<qualified>(id)->to_string();
        }
        else if (id.index() == unqualified) {
            return std::get<unqualified>(id)->to_string();
        }
        // else
        return {};
    }

    auto position() const
        -> source_position
    {
        return pos;
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        try_visit<qualified  >(id, v, depth);
        try_visit<unqualified>(id, v, depth);
        v.end(*this, depth);
    }
};


postfix_expression_node::~postfix_expression_node()
{
    if (cap_grp) {
        cap_grp->remove(this);
    }
}


auto primary_expression_node::is_unqualified_id() const
    -> bool
{
    if (is_identifier()) {
        return true;
    }
    if (is_id_expression()) {
        return std::get<id_expression>(expr)->is_unqualified();
    }
    return false;
}


auto primary_expression_node::is_fold_expression() const
    -> bool
{
    //  This is a fold-expression if any subexpression has
    //  has an identifier named "..."
    switch (expr.index()) {
    break;case identifier:
        return *std::get<identifier>(expr) == "...";
    break;case expression_list:
        return expression_list_is_fold_expression;
    break;case id_expression:
        return std::get<id_expression>(expr)->is_fold_expression();
    break;default: ; // the others can't contain folds
    }
    return false;
}


auto postfix_expression_node::get_first_token_ignoring_this() const
    -> token const*
{
    if (
        expr->get_token()
        && *expr->get_token() == "this"
        && std::ssize(ops) == 1
        && (ops[0].op->type() == lexeme::Dot || ops[0].op->type() == lexeme::DotDot)
        )
    {
        return ops[0].id_expr->get_token();
    }
    return expr->get_token();
}


auto postfix_expression_node::to_string() const
    -> std::string
{
    assert (expr);
    auto ret = expr->to_string();

    for (auto const& x : ops) {
        assert (x.op);
        ret += x.op->as_string_view();
        if (x.id_expr) {
            ret += x.id_expr->to_string();
        }
        if (x.expr_list) {
            ret += x.expr_list->to_string();
        }
    }

    return ret;
}


auto postfix_expression_node::visit(auto& v, int depth)
    -> void
{
    v.start(*this, depth);
    assert (expr);
    expr->visit(v, depth+1);
    for (auto const& x : ops) {
        assert (x.op);
        v.start(*x.op, depth+1);
        if (x.id_expr) {
            x.id_expr->visit(v, depth+1);
        }
        if (x.expr_list) {
            x.expr_list->visit(v, depth+1);
        }
    }
    v.end(*this, depth);
}


struct statement_node;

struct compound_statement_node
{
    source_position open_brace;
    source_position close_brace;
    std::vector<std::unique_ptr<statement_node>> statements;

    colno_t body_indent = 0;

    compound_statement_node(source_position o = source_position{});

    auto position() const
        -> source_position
    {
        return open_brace;
    }

    auto visit(auto& v, int depth) -> void;
};


struct selection_statement_node
{
    bool                                        is_constexpr = false;
    token const*                                identifier   = {};
    source_position                             else_pos;
    std::unique_ptr<logical_or_expression_node> expression;
    std::unique_ptr<compound_statement_node>    true_branch;
    std::unique_ptr<compound_statement_node>    false_branch;
    bool                                        has_source_false_branch = false;

    auto position() const
        -> source_position
    {
        assert (identifier);
        return identifier->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        assert (identifier);
        v.start(*identifier, depth+1);
        assert (expression);
        expression->visit(v, depth+1);
        assert (true_branch);
        true_branch->visit(v, depth+1);
        if (false_branch) {
            false_branch->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};


struct parameter_declaration_node;

struct iteration_statement_node
{
    token const*                                label      = {};
    token const*                                identifier = {};
    std::unique_ptr<assignment_expression_node> next_expression;    // if used, else null
    std::unique_ptr<logical_or_expression_node> condition;          // used for "do" and "while", else null
    std::unique_ptr<compound_statement_node>    statements;         // used for "do" and "while", else null
    std::unique_ptr<expression_node>            range;              // used for "for", else null
    std::unique_ptr<parameter_declaration_node> parameter;          // used for "for", else null
    std::unique_ptr<statement_node>             body;               // used for "for", else null
    bool                                        for_with_in = false;// used for "for," says whether loop variable is 'in'

    // Out-of-line definition of the dtor is necessary due to the forward-declared
    // type(s) used in a std::unique_ptr as a member
    ~iteration_statement_node();

    auto position() const
        -> source_position
    {
        if (label) {
            return label->position();
        }
        assert(identifier);
        return identifier->position();
    }

    auto visit(auto& v, int depth)
        -> void;
};


struct return_statement_node
{
    token const*                     identifier = {};
    std::unique_ptr<expression_node> expression;

    auto position() const
        -> source_position
    {
        assert(identifier);
        return identifier->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        if (expression) {
            expression->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};


struct alternative_node
{
    std::unique_ptr<unqualified_id_node> name;
    token const*                         is_as_keyword = {};

    //  One of these will be used
    std::unique_ptr<type_id_node>            type_id;
    std::unique_ptr<postfix_expression_node> value;

    source_position                      equal_sign;
    std::unique_ptr<statement_node>      statement;

    // Out-of-line definition of the dtor is necessary due to the forward-declared
    // type(s) used in a std::unique_ptr as a member
    ~alternative_node();

    auto position() const
        -> source_position
    {
        assert(is_as_keyword);
        return is_as_keyword->position();
    }

    auto visit(auto& v, int depth)
        -> void;
};


struct inspect_expression_node
{
    bool                                     is_constexpr = false;
    token const*                             identifier   = {};
    std::unique_ptr<expression_node>         expression;
    std::unique_ptr<type_id_node>            result_type;
    source_position                          open_brace;
    source_position                          close_brace;

    std::vector<std::unique_ptr<alternative_node>> alternatives;

    // Out-of-line definition of the dtor is necessary due to the forward-declared
    // type(s) used in a std::unique_ptr as a member
    ~inspect_expression_node();

    auto position() const
        -> source_position
    {
        assert(identifier);
        return identifier->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        assert (identifier);
        v.start(*identifier, depth+1);
        assert (expression);
        expression->visit(v, depth+1);
        if (result_type) {
            result_type->visit(v, depth+1);
        }
        for (auto&& alt : alternatives) {
            alt->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};


struct contract_node
{
    //  Declared first, because it should outlive any owned
    //  postfix_expressions that could refer to it
    capture_group captures;

    source_position                                  open_bracket;
    token const*                                     kind = {};
    std::unique_ptr<id_expression_node>              group;
    std::vector<std::unique_ptr<id_expression_node>> flags;
    std::unique_ptr<logical_or_expression_node>      condition;
    std::unique_ptr<expression_node>                 message = {};

    contract_node( source_position pos )
        : open_bracket{pos}
    { }

    auto position() const
        -> source_position
    {
        return open_bracket;
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);

        assert(kind);
        kind->visit(v, depth+1);

        if (group) {
            group->visit(v, depth+1);
        }

        for (auto const& f : flags) {
            f->visit(v, depth+1);
        }

        assert(condition);
        condition->visit(v, depth+1);

        if (message) {
            message->visit(v, depth+1);
        }

        v.end(*this, depth);
    }
};


struct jump_statement_node
{
    token const* keyword;
    token const* label;

    auto position() const
        -> source_position
    {
        assert(keyword);
        return keyword->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        if (keyword) {
            keyword->visit(v, depth+1);
        }
        if (label) {
            label->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};


struct using_statement_node
{
    token const*                        keyword = {};
    bool                                for_namespace = false;
    std::unique_ptr<id_expression_node> id;

    auto position() const
        -> source_position
    {
        assert(keyword);
        return keyword->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        assert(id);
        id->visit(v, depth+1);
        v.end(*this, depth);
    }
};


struct parameter_declaration_list_node;

struct statement_node
{
    std::unique_ptr<parameter_declaration_list_node> parameters;
    compound_statement_node* compound_parent = nullptr;

    statement_node(compound_statement_node* compound_parent_ = nullptr);

    // Out-of-line definition of the dtor is necessary due to the forward-declared
    // type(s) used in a std::unique_ptr as a member
    ~statement_node();

    enum active { expression=0, compound, selection, declaration, return_, iteration, using_, contract, inspect, jump };
    std::variant<
        std::unique_ptr<expression_statement_node>,
        std::unique_ptr<compound_statement_node>,
        std::unique_ptr<selection_statement_node>,
        std::unique_ptr<declaration_node>,
        std::unique_ptr<return_statement_node>,
        std::unique_ptr<iteration_statement_node>,
        std::unique_ptr<using_statement_node>,
        std::unique_ptr<contract_node>,
        std::unique_ptr<inspect_expression_node>,
        std::unique_ptr<jump_statement_node>
    > statement;

    bool emitted = false;               // a note field that's used during lowering to Cpp1

    bool marked_for_removal = false;    // for use during metafunctions which may replace members

    //  API
    //
    auto is_expression () const -> bool { return statement.index() == expression;  }
    auto is_compound   () const -> bool { return statement.index() == compound;    }
    auto is_selection  () const -> bool { return statement.index() == selection;   }
    auto is_declaration() const -> bool { return statement.index() == declaration; }
    auto is_return     () const -> bool { return statement.index() == return_;     }
    auto is_iteration  () const -> bool { return statement.index() == iteration;   }
    auto is_using      () const -> bool { return statement.index() == using_;      }
    auto is_contract   () const -> bool { return statement.index() == contract;    }
    auto is_inspect    () const -> bool { return statement.index() == inspect;     }
    auto is_jump       () const -> bool { return statement.index() == jump;        }

    template<typename Node>
    auto get_if()
        -> Node*
    {
        auto pnode = std::get_if<std::unique_ptr<Node>>(&statement);
        if (pnode) {
            return pnode->get();
        }
        //  else
        return nullptr;
    }

    template<typename Node>
    auto get_if() const
        -> Node const*
    {
        auto pnode = std::get_if<std::unique_ptr<Node>>(&statement);
        if (pnode) {
            return pnode->get();
        }
        //  else
        return nullptr;
    }

    auto get_lhs_rhs_if_simple_assignment() const
        -> assignment_expression_lhs_rhs
    {
        if (is_expression()) {
            return std::get<expression>(statement)->expr->get_lhs_rhs_if_simple_assignment();
        }
        //  Else
        return {};
    }

    auto to_string() const
        -> std::string
    {
        switch (statement.index()) {
        break;case expression:
            return std::get<expression>(statement)->to_string();
        break;default:
            return "(*ERROR*) temporary alpha limitation: type metafunctions cannot stringize expressions that involve initializer statements other than expression-statements";
        }
    }

    //  Internals
    //
    auto position() const
        -> source_position;

    auto visit(auto& v, int depth)
        -> void;
};


auto alternative_node::visit(auto& v, int depth)
    -> void
{
    v.start(*this, depth);
    if (name) {
        v.start(*name, depth+1);
    }
    assert (is_as_keyword);
    v.start(*is_as_keyword, depth+1);
    if (type_id) {
        type_id->visit(v, depth+1);
    }
    else {
        assert (value);
        value->visit(v, depth+1);
    }
    assert (statement);
    statement->visit(v, depth+1);
    v.end(*this, depth);
}


auto compound_statement_node::visit(auto& v, int depth)
    -> void
{
    v.start(*this, depth);
    for (auto const& x : statements) {
        assert(x);
        x->visit(v, depth+1);
    }
    v.end(*this, depth);
}


struct parameter_declaration_node
{
    source_position pos = {};
    passing_style pass  = passing_style::in;
    int ordinal = 1;

    enum class modifier { none=0, implicit, virtual_, override_, final_ };
    modifier mod = modifier::none;

    std::unique_ptr<declaration_node> declaration;

    //  API
    //
    auto has_name() const
        -> bool;

    auto name() const
        -> token const*;

    auto has_name(std::string_view) const
        -> bool;

    auto direction() const
        -> passing_style
    {
        return pass;
    }

    auto is_implicit() const
        -> bool
    {
        return mod == modifier::implicit;
    }

    auto is_virtual() const
        -> bool
    {
        return mod == modifier::virtual_;
    }

    auto make_virtual()
        -> void
    {
        mod = modifier::virtual_;
    }

    auto is_override() const
        -> bool
    {
        return mod == modifier::override_;
    }

    auto is_final() const
        -> bool
    {
        return mod == modifier::final_;
    }

    auto is_polymorphic() const
        -> bool
    {
        switch (mod) {
        break;case modifier::virtual_:
              case modifier::override_:
              case modifier::final_:
            return true;
        break;default:
            return false;
        }
    }

    //  Internals
    //
    auto position() const
        -> source_position;

    auto visit(auto& v, int depth)
        -> void;
};


struct parameter_declaration_list_node
{
    token const* open_paren  = {};
    token const* close_paren = {};

    std::vector<std::unique_ptr<parameter_declaration_node>> parameters;

    //  API
    //
    auto ssize() const -> auto {
        return std::ssize(parameters);
    }

    auto operator[](int i)
        -> parameter_declaration_node*
    {
        return parameters[i].get();
    }

    auto operator[](int i) const
        -> parameter_declaration_node const*
    {
        return parameters[i].get();
    }

    //  Internals
    //
    auto position() const
        -> source_position
    {
        assert(open_paren);
        return open_paren->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        for (auto const& x : parameters) {
            assert(x);
            x->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};


auto statement_node::visit(auto& v, int depth)
    -> void
{
    v.start(*this, depth);
    if (parameters) {
        parameters->visit(v, depth+1);
    }
    try_visit<expression >(statement, v, depth);
    try_visit<compound   >(statement, v, depth);
    try_visit<selection  >(statement, v, depth);
    try_visit<declaration>(statement, v, depth);
    try_visit<return_    >(statement, v, depth);
    try_visit<iteration  >(statement, v, depth);
    try_visit<using_     >(statement, v, depth);
    try_visit<contract   >(statement, v, depth);
    try_visit<inspect    >(statement, v, depth);
    try_visit<jump       >(statement, v, depth);
    v.end(*this, depth);
}


struct function_returns_tag { };

struct function_type_node
{
    declaration_node* my_decl;

    std::unique_ptr<parameter_declaration_list_node> parameters;
    bool throws = false;

    struct single_type_id {
        std::unique_ptr<type_id_node> type;
        passing_style pass = passing_style::move;
    };

    enum active { empty = 0, id, list };
    std::variant<
        std::monostate,
        single_type_id,
        std::unique_ptr<parameter_declaration_list_node>
    > returns;

    std::vector<std::unique_ptr<contract_node>> contracts;

    function_type_node(declaration_node* decl);

    //  API
    //
    auto has_postconditions() const
        -> bool;

    auto is_function_with_this() const
        -> bool;

    auto is_virtual_function() const
        -> bool;

    auto make_function_virtual()
        -> bool;

    auto is_defaultable() const
        -> bool;

    auto is_constructor() const
        -> bool;

    auto is_default_constructor() const
        -> bool;

    auto is_move() const
        -> bool;

    auto is_swap() const
        -> bool;

    auto is_constructor_with_that() const
        -> bool;

    auto is_constructor_with_in_that() const
        -> bool;

    auto is_constructor_with_move_that() const
        -> bool;

    auto is_comparison() const
        -> bool;

    auto is_increment_or_decrement() const
        -> bool;

    auto is_compound_assignment() const
        -> bool;

    auto is_assignment() const
        -> bool;

    auto is_assignment_with_that() const
        -> bool;

    auto is_assignment_with_in_that() const
        -> bool;

    auto is_assignment_with_move_that() const
        -> bool;

    auto is_destructor() const
        -> bool;

    auto has_declared_return_type() const
        -> bool
    {
        return returns.index() != empty;
    }

    auto has_deduced_return_type() const
        -> bool
    {
        return
            returns.index() == empty
            || (
                returns.index() == id
                && std::get<function_type_node::id>(returns).type->is_wildcard()
                )
            ;
    }

    auto unnamed_return_type_to_string() const
        -> std::string
    {
        if (auto id = std::get_if<function_type_node::id>(&returns)) {
            return (*id).type->to_string();
        }
        return {};
    }

    auto has_bool_return_type() const
        -> bool
    {
        if (auto id = std::get_if<function_type_node::id>(&returns)) {
            if (auto name = (*id).type->get_token()) {
                return *name == "bool";
            }
        }
        return false;
    }

    auto has_non_void_return_type() const
        -> bool
    {
        if (auto id = std::get_if<function_type_node::id>(&returns)) {
            if (auto name = (*id).type->get_token()) {
                return *name != "void";
            }
        }
        return returns.index() != empty;
    }

    auto parameter_count() const
        -> int
    {
        return unsafe_narrow<int>(std::ssize(parameters->parameters));
    }

    auto index_of_parameter_named(std::string_view s) const
        -> int
    {
        auto ret = 0;
        for (auto& param : parameters->parameters) {
            if (param->has_name(s)) {
                return ret;
            }
            ++ret;
        }
        return -1;
    }

    auto has_parameter_named(std::string_view s) const
        -> bool
    {
        for (auto& param : parameters->parameters) {
            if (param->has_name(s)) {
                return true;
            }
        }
        return false;
    }

    auto has_parameter_with_name_and_pass(
        std::string_view s,
        passing_style    pass
    ) const
        -> bool
    {
        for (auto& param : parameters->parameters) {
            if (
                param->has_name(s)
                && param->pass == pass
                )
            {
                return true;
            }
        }
        return false;
    }

    auto first_parameter_name() const
        -> std::string;

    auto nth_parameter_type_name(int n) const
        -> std::string;

    auto has_in_parameter_named(std::string_view s) const
        -> bool
    {
        return has_parameter_with_name_and_pass(s, passing_style::in);
    }

    auto has_copy_parameter_named(std::string_view s) const
        -> bool
    {
        return has_parameter_with_name_and_pass(s, passing_style::copy);
    }

    auto has_inout_parameter_named(std::string_view s) const
        -> bool
    {
        return has_parameter_with_name_and_pass(s, passing_style::inout);
    }

    auto has_out_parameter_named(std::string_view s) const
        -> bool
    {
        return has_parameter_with_name_and_pass(s, passing_style::out);
    }

    auto has_move_parameter_named(std::string_view s) const
        -> bool
    {
        return has_parameter_with_name_and_pass(s, passing_style::move);
    }

    auto has_forward_parameter_named(std::string_view s) const
        -> bool
    {
        return has_parameter_with_name_and_pass(s, passing_style::forward);
    }

    //  Internals
    //
    auto position() const
        -> source_position
    {
        assert (parameters);
        return parameters->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        assert(parameters);
        parameters->visit(v, depth+1);

        if (returns.index() == id) {
            auto& r = std::get<id>(returns);
            assert(r.type);
            r.type->visit(v, depth+1);
        }
        else if (returns.index() == list) {
            auto& r = std::get<list>(returns);
            assert(r);
            //  Inform the visitor that this is a returns list
            v.start(function_returns_tag{}, depth);
            r->visit(v, depth+1);
            v.end(function_returns_tag{}, depth);
        }

        for (auto const& c : contracts) {
            c->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};


struct type_node
{
    token const* type;
    bool         final = false;

    type_node(
        token const* t,
        bool         final_ = false
    )
        : type{t}
        , final{final_}
    { }

    //  API
    //
    auto is_final() const
        -> bool
    {
        return final;
    }

    auto make_final()
        -> void
    {
        final = true;
    }

    //  Internals
    //
    auto position() const
        -> source_position
    {
        assert(type);
        return type->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        v.end(*this, depth);
    }
};


struct namespace_node
{
    token const* namespace_;

    namespace_node(token const* ns) : namespace_{ns} { }

    auto position() const
        -> source_position
    {
        assert(namespace_);
        return namespace_->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);
        v.end(*this, depth);
    }
};


struct alias_node
{
    token const* type = {};
    std::unique_ptr<type_id_node> type_id;   // for objects

    enum active : std::uint8_t { a_type, a_namespace, an_object };
    std::variant<
        std::unique_ptr<type_id_node>,
        std::unique_ptr<id_expression_node>,
        std::unique_ptr<expression_node>
    > initializer;

    alias_node( token const* t ) : type{t} { }

    //  API
    //
    auto is_type_alias     () const -> bool
        { return initializer.index() == a_type;      }
    auto is_namespace_alias() const -> bool
        { return initializer.index() == a_namespace; }
    auto is_object_alias   () const -> bool
        { return initializer.index() == an_object;   }

    //  Internals
    //
    auto position() const
        -> source_position
    {
        assert (type);
        return type->position();
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);

        try_visit<a_type     >(initializer, v, depth+1);
        try_visit<a_namespace>(initializer, v, depth+1);
        try_visit<an_object  >(initializer, v, depth+1);

        v.end(*this, depth);
    }
};


enum class accessibility { default_ = 0, public_, protected_, private_ };

auto to_string(accessibility a)
    -> std::string
{
    switch (a) {
    break;case accessibility::public_   : return "public";
    break;case accessibility::protected_: return "protected";
    break;case accessibility::private_  : return "private";
    break;default: assert(a == accessibility::default_);
    }
    return "default";
}


struct declaration_identifier_tag { };

struct declaration_node
{
    //  The capture_group is declared first, because it should outlive
    //  any owned postfix_expressions that could refer to it
    capture_group                        captures;
    source_position                      pos;
    bool                                 is_variadic = false;
    bool                                 is_constexpr = false;
    bool                                 terse_no_equals = false;
    std::unique_ptr<unqualified_id_node> identifier;
    accessibility                        access = accessibility::default_;

    enum active : std::uint8_t { a_function, an_object, a_type, a_namespace, an_alias };
    std::variant<
        std::unique_ptr<function_type_node>,
        std::unique_ptr<type_id_node>,
        std::unique_ptr<type_node>,
        std::unique_ptr<namespace_node>,
        std::unique_ptr<alias_node>
    > type;

    std::vector<std::unique_ptr<id_expression_node>> metafunctions;
    std::unique_ptr<parameter_declaration_list_node> template_parameters;
    source_position                                  requires_pos = {};
    std::unique_ptr<logical_or_expression_node>      requires_clause_expression;

    source_position                 equal_sign = {};
    std::unique_ptr<statement_node> initializer;

    declaration_node*               parent_declaration = {};
    statement_node*                 my_statement = {};

    //  Attributes currently configurable only via metafunction API,
    //  not directly in the base language grammar
    bool member_function_generation = true;

    //  Cache some context
    bool is_a_template_parameter = false;
    bool is_a_parameter          = false;

    //  Constructor
    //
    declaration_node(declaration_node* parent)
        : parent_declaration{parent}
    { }

    //  API
    //

    auto is_template_parameter() const
        -> bool
    {
        return is_a_template_parameter;
    }

    auto is_parameter() const
        -> bool
    {
        return is_a_parameter;
    }

    auto type_member_mark_for_removal()
        -> bool
    {
        if (my_statement) {
            my_statement->marked_for_removal = true;
            return true;
        }
        return false;
    }

    auto type_remove_marked_members()
        -> void
    {
        assert (is_type() && initializer && initializer->is_compound());
        auto compound_stmt = initializer->get_if<compound_statement_node>();
        assert (compound_stmt);

        //  Note: This loop is a careful use of the brittle STL "erase" idiom. Do not change this
        //        loop without carefully ensuring it remains safe against iterator invalidation.
        //        (Especially don't change this to a for loop with a "++i" iteration-expression.)
        auto i = compound_stmt->statements.begin();
        while (i != compound_stmt->statements.end())
        {
            if ((*i)->marked_for_removal) {
                i = compound_stmt->statements.erase(i); // these two branches ...
            }
            else {
                ++i;                                    // ... must stay together
            }
        }
    }

    auto type_remove_all_members()
        -> void
    {
        assert (is_type() && initializer && initializer->is_compound());
        auto body = initializer->get_if<compound_statement_node>();
        assert (body);

        //  Drop all statements in the body, which should self-deregister all our 'captures'
        //  - (only) statements in the body should have been able to refer to 'captures'
        body->statements.clear();
        assert(captures.members.empty());
    }

    auto type_disable_member_function_generation()
        -> void
    {
        member_function_generation = false;
    }

    auto object_type() const
        -> std::string
    {
        if (!is_object()) {
            return "(*ERROR*) not an object";
        }
        //  Else
        return std::get<an_object>(type)->to_string();
    }

    auto object_initializer() const
        -> std::string
    {
        if (!is_object()) {
            return "(*ERROR*) not an object";
        }
        else if (initializer) {
            return initializer->to_string();
        }
        //  Else
        return "";
    }

    auto get_parent() const
        -> declaration_node*
    {
        return parent_declaration;
    }

    auto is_public() const
        -> bool
    {
        return access == accessibility::public_;
    }

    auto is_protected() const
        -> bool
    {
        return access == accessibility::protected_;
    }

    auto is_private() const
        -> bool
    {
        return access == accessibility::private_;
    }

    auto is_default_access() const
        -> bool
    {
        return access == accessibility::default_;
    }

private:
    auto set_access(accessibility a)
        -> bool
    {
        if (is_default_access()) {
            access = a;
        }
        return access == a;
    }

public:
    auto make_public()
        -> bool
    {
        return set_access( accessibility::public_ );
    }

    auto make_protected()
        -> bool
    {
        return set_access( accessibility::protected_ );
    }

    auto make_private()
        -> bool
    {
        return set_access( accessibility::private_ );
    }

    auto has_name() const
        -> bool
    {
        return
            identifier
            && identifier->identifier
            ;
    }

    auto name() const
        -> token const*
    {
        if (!identifier) {
            return nullptr;
        }
        //  Else
        return identifier->identifier;
    }

    auto has_name(std::string_view s) const
        -> bool
    {
        return
            has_name()
            && *name() == s
            ;
    }

    auto has_initializer() const
        -> bool
    {
        return initializer != nullptr;
    }

    auto parameter_count() const
        -> int
    {
        if (!is_function()) {
            return -1;
        }
        return std::get<a_function>(type)->parameter_count();
    }

    auto index_of_parameter_named(std::string_view s) const
        -> int
    {
        if (!is_function()) {
            return -1;
        }
        return std::get<a_function>(type)->index_of_parameter_named(s);
    }

    auto has_parameter_named(std::string_view s) const
        -> bool
    {
        if (!is_function()) {
            return false;
        }
        return std::get<a_function>(type)->has_parameter_named(s);
    }

    auto has_in_parameter_named(std::string_view s) const
        -> bool
    {
        if (!is_function()) {
            return false;
        }
        return std::get<a_function>(type)->has_in_parameter_named(s);
    }

    auto has_copy_parameter_named(std::string_view s) const
        -> bool
    {
        if (!is_function()) {
            return false;
        }
        return std::get<a_function>(type)->has_copy_parameter_named(s);
    }

    auto has_inout_parameter_named(std::string_view s) const
        -> bool
    {
        if (!is_function()) {
            return false;
        }
        return std::get<a_function>(type)->has_inout_parameter_named(s);
    }

    auto has_out_parameter_named(std::string_view s) const
        -> bool
    {
        if (!is_function()) {
            return false;
        }
        return std::get<a_function>(type)->has_out_parameter_named(s);
    }

    auto has_move_parameter_named(std::string_view s) const
        -> bool
    {
        if (!is_function()) {
            return false;
        }
        return std::get<a_function>(type)->has_move_parameter_named(s);
    }

    auto has_forward_parameter_named(std::string_view s) const
        -> bool
    {
        if (!is_function()) {
            return false;
        }
        return std::get<a_function>(type)->has_forward_parameter_named(s);
    }

    auto nth_parameter_type_name(int n) const
        -> std::string
    {
        if (!is_function()) {
            return "";
        }
        return std::get<a_function>(type)->nth_parameter_type_name(n);
    }

    auto is_global   () const -> bool
        { return !parent_declaration;         }

    auto is_function () const -> bool
        { return type.index() == a_function;  }
    auto is_object   () const -> bool
        { return type.index() == an_object;   }
    auto is_base_object() const -> bool
        { return is_object() && has_name("this"); }
    auto is_member_object() const -> bool
        { return is_object() && !has_name("this"); }
    auto is_concept  () const -> bool
        { return type.index() == an_object && get<an_object>(type)->is_concept();   }
    auto is_type     () const -> bool
        { return type.index() == a_type;      }
    auto is_namespace() const -> bool
        { return type.index() == a_namespace; }
    auto is_alias() const -> bool
        { return type.index() == an_alias;    }

    auto is_type_alias     () const -> bool
        { return is_alias() && std::get<an_alias>(type)->is_type_alias(); }
    auto is_namespace_alias() const -> bool
        { return is_alias() && std::get<an_alias>(type)->is_namespace_alias(); }
    auto is_object_alias   () const -> bool
        { return is_alias() && std::get<an_alias>(type)->is_object_alias(); }

    auto is_function_expression () const -> bool
        { return is_function() && !identifier;  }

    auto is_polymorphic() const // has base types or virtual functions
        -> bool
    {
        for (auto& decl : get_type_scope_declarations()) {
            if (
                decl->has_name("this")
                || decl->is_virtual_function()
                )
            {
                return true;
            }
        }
        return false;
    }

    //  Do we know that this cannot be a copy constructible type?
    auto cannot_be_a_copy_constructible_type() const
        -> bool
    {
        //  If we're not a type, we're not a copyable type
        if (!is_type()) {
            return true;
        }

        //  Else if we're letting Cpp1 generate SMFs, we're likely copyable
        if (!member_function_generation) {
            return false;
        }

        //  Else if we have a copy constructor, we're copyable
        for (auto& decl : get_type_scope_declarations())
        if  (decl->is_constructor_with_that())
        {
            return false;
        }

        //  Else there can't be a copy constructor
        return true;
    }

    auto parent_is_function   () const -> bool
        { return  parent_declaration && parent_declaration->type.index() == a_function;  }
    auto parent_is_object     () const -> bool
        { return  parent_declaration && parent_declaration->type.index() == an_object;   }
    auto parent_is_type       () const -> bool
        { return  parent_declaration && parent_declaration->type.index() == a_type;      }
    auto parent_is_namespace  () const -> bool
        { return !parent_declaration || parent_declaration->type.index() == a_namespace; }
    auto parent_is_alias      () const -> bool
        { return  parent_declaration && parent_declaration->type.index() == an_alias;    }

    auto parent_is_type_alias     () const -> bool
        { return parent_declaration && parent_declaration->is_alias() && std::get<an_alias>(parent_declaration->type)->is_type_alias(); }
    auto parent_is_namespace_alias() const -> bool
        { return parent_declaration && parent_declaration->is_alias() && std::get<an_alias>(parent_declaration->type)->is_namespace_alias(); }
    auto parent_is_object_alias   () const -> bool
        { return parent_declaration && parent_declaration->is_alias() && std::get<an_alias>(parent_declaration->type)->is_object_alias(); }

    auto is_inside_global_unnamed_function() const -> bool {
        auto parent = parent_declaration;
        //  Get outside all nested function expressions
        while (parent && parent->is_function() && !parent->has_name()) {
            parent = parent->parent_declaration;
        }
        return !parent;
    }

    auto parent_is_polymorphic() const -> bool
        { return  parent_declaration && parent_declaration->is_polymorphic(); }

    enum which {
        functions = 1,
        objects   = 2,
        types     = 4,
        aliases   = 8,
        all       = functions|objects|types|aliases
    };

private:
    //  This helper is a const function that delivers pointers
    //  to non-const... because this is the best way I can
    //  think of right now to write the following two get_
    //  functions (without duplicating their bodies, and
    //  without resorting to const_casts)
    auto gather_type_scope_declarations(which w) const
        -> std::vector<declaration_node*>
    {
        if (
            !is_type()
            || !initializer
            || !initializer->is_compound()
            )
        {
            return {};
        }

        auto compound_stmt = initializer->get_if<compound_statement_node>();
        assert (compound_stmt);

        auto ret = std::vector<declaration_node*>{};
        for (auto& o : compound_stmt->statements)
        {
            auto decl = o->get_if<declaration_node>();
            if (decl)
            {
                assert(
                    !decl->is_namespace()
                    && "ICE: a type shouldn't be able to contain a namespace"
                );
                if (
                    (w & functions  && decl->is_function())
                    || (w & objects && decl->is_object()  )
                    || (w & types   && decl->is_type()    )
                    || (w & aliases && decl->is_alias()   )
                    )
                {
                    ret.push_back(decl);
                }
            }
        }

        return ret;
    }

public:
    auto get_type_scope_declarations(which w = all)
        -> std::vector<declaration_node*>
    {
        //  Only want to return the gather_ results as
        //  non-const* in a non-const function
        return gather_type_scope_declarations(w);
    }

    auto get_type_scope_declarations(which w = all) const
        -> std::vector<declaration_node const*>
    {
        //  Convert the gather_ results to const*
        auto tmp = gather_type_scope_declarations(w);
        return std::vector<declaration_node const*>(tmp.begin(), tmp.end());
    }


    auto add_type_member( std::unique_ptr<statement_node>&& statement )
        -> bool
    {
        if (
            !is_type()
            || !initializer
            || !initializer->is_compound()
            || !statement->is_declaration()
            )
        {
            return false;
        }

        //  Tell this declaration statement that we are its new parent
        //  and check to ensure that it doesn't already have a parent
        //  (that shouldn't happen because we should only get here for a
        //  generated statement that hasn't been added elsewhere yet)
        auto decl = statement->get_if<declaration_node>();
        assert(
            decl
            && !decl->parent_declaration
        );
        decl->parent_declaration = this;

        //  And actually adopt it into our list of statements
        auto compound_stmt = initializer->get_if<compound_statement_node>();
        assert (compound_stmt);
        compound_stmt->statements.push_back(std::move(statement));
        return true;
    }


    auto add_function_initializer( std::unique_ptr<statement_node>&& statement )
        -> bool
    {
        if (
            !is_function()
            || initializer
            )
        {
            return false;
        }

        //  Adopt it as our initializer statement
        initializer = std::move( statement );
        return true;
    }


    auto get_decl_if_type_scope_object_name_before_a_base_type( std::string_view s ) const
        -> declaration_node const*
    {
        declaration_node const* ret = {};

        //  If it's 'this' then it can't be an object name
        if (s == "this") {
            return {};
        }

        //  Navigate to the nearest enclosing type
        auto decl = this;
        while (
            !decl->is_type()
            && decl->parent_declaration
            )
        {
            decl = decl->parent_declaration;
        }

        if (!decl->is_type()) {
            return {};
        }

        //  Look for a name match and if so remember the type,
        //  and look for a base type after that match
        auto objects               = decl->get_type_scope_declarations();
        auto found_name            = false;
        auto found_later_base_type = false;

        for (auto& o : objects) {
            if (o->is_alias()) {
                continue;
            }
            if (o->has_name(s)) {
                found_name = true;
                ret        = o;
            }
            if (o->has_name("this")) {
                if (found_name) {
                    found_later_base_type = true;
                    break;
                }
            }
        }

        //  If we didn't find a later base type, discard any name match
        if (!found_later_base_type) {
            ret = {};
        }

        return ret;
    }


    auto get_initializer_statements() const
        -> std::vector<statement_node*>
    {
        if (!initializer) {
            return {};
        }

        auto ret = std::vector<statement_node*>{};
        //  For non-compound initializers, we want just that statement
        if (!initializer->is_compound())
        {
            ret.push_back(initializer.get());
        }

        //  Else for compound initializers, we want the compound_statement's statements
        else
        {
            auto compound_stmt = initializer->get_if<compound_statement_node>();
            assert (compound_stmt);
            for (auto& o : compound_stmt->statements) {
                ret.push_back(o.get());
            }
        }

        return ret;
    }

    auto is_function_with_this() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_function_with_this();
        }
        //  else
        return false;
    }

    auto is_virtual_function() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_virtual_function();
        }
        //  else
        return false;
    }

    auto is_type_final() const
        -> bool
    {
        if (auto t = std::get_if<a_type>(&type)) {
            return (*t)->is_final();
        }
        //  else
        return false;
    }

    auto make_type_final()
        -> bool
    {
        if (auto t = std::get_if<a_type>(&type)) {
            (*t)->make_final();
            return true;
        }
        //  else
        return false;
    }

    auto make_function_virtual()
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->make_function_virtual();
        }
        //  else
        return false;
    }

    auto is_defaultable_function() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_defaultable();
        }
        //  else
        return false;
    }

    auto is_constructor() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_constructor();
        }
        //  else
        return false;
    }

    auto is_default_constructor() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_default_constructor();
        }
        //  else
        return false;
    }

    auto is_move() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_move();
        }
        //  else
        return false;
    }

    auto is_swap() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_swap();
        }
        //  else
        return false;
    }

    auto is_constructor_with_that() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_constructor_with_that();
        }
        //  else
        return false;
    }

    auto is_constructor_with_in_that() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_constructor_with_in_that();
        }
        //  else
        return false;
    }

    auto is_constructor_with_move_that() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_constructor_with_move_that();
        }
        //  else
        return false;
    }

    auto is_comparison() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_comparison();
        }
        //  else
        return false;
    }

    auto is_increment_or_decrement() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_increment_or_decrement();
        }
        //  else
        return false;
    }

    auto is_compound_assignment() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_compound_assignment();
        }
        //  else
        return false;
    }

    auto is_assignment() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_assignment();
        }
        //  else
        return false;
    }

    auto is_assignment_with_that() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_assignment_with_that();
        }
        //  else
        return false;
    }

    auto is_assignment_with_in_that() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_assignment_with_in_that();
        }
        //  else
        return false;
    }

    auto is_assignment_with_move_that() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_assignment_with_move_that();
        }
        //  else
        return false;
    }

    struct declared_value_set_funcs {
        declaration_node const*  out_this_in_that     = {};
        declaration_node const*  out_this_move_that   = {};
        declaration_node const*  inout_this_in_that   = {};
        declaration_node const*  inout_this_move_that = {};
        std::vector<std::string> assignments_from     = {};
    };

    auto find_declared_value_set_functions() const
        -> declared_value_set_funcs
    {
        if (!initializer) {
            return {};
        }

        auto compound_stmt = initializer->get_if<compound_statement_node>();
        assert (compound_stmt);

        auto ret = declared_value_set_funcs{};
        for (auto& o : compound_stmt->statements)
        {
            auto decl = o->get_if<declaration_node>();
            if (decl)
            {
                if (decl->is_constructor_with_in_that()) {
                    ret.out_this_in_that = decl;
                }
                if (decl->is_constructor_with_move_that()) {
                    ret.out_this_move_that = decl;
                }
                if (decl->is_assignment_with_in_that()) {
                    ret.inout_this_in_that = decl;
                }
                if (decl->is_assignment_with_move_that()) {
                    ret.inout_this_move_that = decl;
                }
                if (decl->is_assignment() && !decl->is_assignment_with_that()) {
                    ret.assignments_from.emplace_back( decl->nth_parameter_type_name(2) );
                }
            }
        }

        return ret;
    }

    auto find_parent_declared_value_set_functions() const
        -> declared_value_set_funcs
    {
        if (parent_is_type()) {
            return parent_declaration->find_declared_value_set_functions();
        }
        //  else
        return {};
    }


    auto is_destructor() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->is_destructor();
        }
        //  else
        return false;
    }

    auto has_declared_return_type() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->has_declared_return_type();
        }
        //  else
        return false;
    }

    auto has_deduced_return_type() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->has_deduced_return_type();
        }
        //  else
        return false;
    }

    auto get_function_parameters()
        -> std::vector<parameter_declaration_node const*>
    {
        if (!is_function()) {
            return {};
        }
        // else
        auto ret = std::vector<parameter_declaration_node const*>{};
        for (auto& param : std::get<a_function>(type)->parameters->parameters) {
            ret.push_back( param.get() );
        }
        return ret;
    }

    auto unnamed_return_type_to_string() const
        -> std::string
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->unnamed_return_type_to_string();
        }
        //  else
        return {};
    }

    auto has_bool_return_type() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->has_bool_return_type();
        }
        //  else
        return false;
    }

    auto has_non_void_return_type() const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->has_non_void_return_type();
        }
        //  else
        return false;
    }

    auto has_parameter_with_name_and_pass(
        std::string_view s,
        passing_style    pass
    ) const
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->has_parameter_with_name_and_pass(s, pass);
        }
        //  else
        return false;
    }

    auto first_parameter_name() const
        -> std::string
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->first_parameter_name();
        }
        //  else
        return "";
    }

    auto is_binary_comparison_function() const
        -> bool
    {
        return
            is_function()
            && (
                has_name("operator==")
                || has_name("operator!=")
                || has_name("operator<")
                || has_name("operator<=")
                || has_name("operator>")
                || has_name("operator>=")
                );
    }

    auto is_const() const
        -> bool
    {
        return
            type.index() == an_object
            && !std::get<an_object>(type)->pc_qualifiers.empty()
            && *std::get<an_object>(type)->pc_qualifiers.front() == "const"
            ;
    }

    auto has_wildcard_type() const
        -> bool
    {
        return
            type.index() == an_object
            && std::get<an_object>(type)->is_wildcard()
            ;
    }

    auto get_object_type() const
        -> type_id_node const*
    {
        if (type.index() == an_object) {
            return std::get<an_object>(type).get();
        }
        //  Else
        return {};
    }

    //  Internals
    //
    auto position() const
        -> source_position
    {
        if (identifier) {
            return identifier->position();
        }
        return pos;
    }

    auto visit(auto& v, int depth)
        -> void
    {
        v.start(*this, depth);

        v.start(declaration_identifier_tag{}, depth);
        if (identifier) {
            identifier->visit(v, depth+1);
        }
        v.end(declaration_identifier_tag{}, depth);

        try_visit<a_function >(type, v, depth+1);
        try_visit<an_object  >(type, v, depth+1);
        try_visit<a_type     >(type, v, depth+1);
        try_visit<a_namespace>(type, v, depth+1);
        try_visit<an_alias   >(type, v, depth+1);

        for (auto& m : metafunctions) {
            assert(m);
            m->visit(v, depth+1);
        }

        if (initializer) {
            initializer->visit(v, depth+1);
        }

        v.end(*this, depth);
    }
};


compound_statement_node::compound_statement_node(source_position o)
    : open_brace{o}
{ }


statement_node::statement_node(compound_statement_node* compound_parent_)
    : compound_parent{ compound_parent_ }
{ }


function_type_node::function_type_node(declaration_node* decl)
    : my_decl{decl}
{ }


auto parameter_declaration_node::has_name() const
    -> bool
{
    return declaration->has_name();
}


auto parameter_declaration_node::name() const
    -> token const*
{
    return declaration->name();
}


auto parameter_declaration_node::has_name(std::string_view s) const
    -> bool
{
    return declaration->has_name(s);
}


auto function_type_node::first_parameter_name() const
    -> std::string
{
    if (std::ssize(parameters->parameters) > 0)
    {
        assert (parameters->parameters[0]->declaration->name());
        return parameters->parameters[0]->declaration->name()->to_string();
    }
    //  Else
    return "";
}

auto function_type_node::nth_parameter_type_name(int n) const
    -> std::string
{
    if (std::ssize(parameters->parameters) >= n)
    {
        return parameters->parameters[n-1]->declaration->get_object_type()->to_string();
    }
    //  Else
    return "";
}


auto function_type_node::has_postconditions() const
    -> bool
{
    return
        std::find_if(
            contracts.begin(),
            contracts.end(),
            [](auto const& e){ return *e->kind == "post"; }
        ) != contracts.end();
}

auto function_type_node::is_function_with_this() const
    -> bool
{
    if (
        (*parameters).ssize() > 0
        && (*parameters)[0]->has_name("this")
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_virtual_function() const
    -> bool
{
    if (
        (*parameters).ssize() > 0
        && (*parameters)[0]->has_name("this")
        && (*parameters)[0]->is_virtual()
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::make_function_virtual()
    -> bool
{
    if (is_function_with_this()) {
        (*parameters)[0]->make_virtual();
        return true;
    }
    return false;
}


auto function_type_node::is_defaultable() const
    -> bool
{
    if (
        my_decl->has_name("operator==")
        || my_decl->has_name("operator<=>")
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_constructor() const
    -> bool
{
    if (
        (*parameters).ssize() > 0
        && (*parameters)[0]->has_name("this")
        && (*parameters)[0]->direction() == passing_style::out
        )
    {
        assert(my_decl->has_name("operator="));
        return true;
    }
    return false;
}


auto function_type_node::is_default_constructor() const
    -> bool
{
    if (
        is_constructor()
        && (*parameters).ssize() == 1
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_move() const
    -> bool
{
    if (
        (is_constructor() || is_assignment())
        && (*parameters).ssize() == 2
        && (*parameters)[1]->has_name("that")
        && (*parameters)[1]->direction() == passing_style::move
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_swap() const
    -> bool
{
    assert (my_decl);
    if (
        my_decl->has_name("swap")
        && (*parameters).ssize() == 2
        && (*parameters)[1]->has_name("that")
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_constructor_with_that() const
    -> bool
{
    if (
        is_constructor()
        && (*parameters).ssize() == 2
        && (*parameters)[1]->has_name("that")
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_assignment_with_that() const
    -> bool
{
    if (
        is_assignment()
        && (*parameters).ssize() == 2
        && (*parameters)[1]->has_name("that")
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_constructor_with_in_that() const
    -> bool
{
    if (
        is_constructor()
        && (*parameters).ssize() == 2
        && (*parameters)[1]->has_name("that")
        && (*parameters)[1]->direction() == passing_style::in
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_constructor_with_move_that() const
    -> bool
{
    if (
        is_constructor()
        && (*parameters).ssize() == 2
        && (*parameters)[1]->has_name("that")
        && (*parameters)[1]->direction() == passing_style::move
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_comparison() const
    -> bool
{
    if (
        (
            my_decl->has_name("operator==")
            || my_decl->has_name("operator!=")
            || my_decl->has_name("operator<")
            || my_decl->has_name("operator<=")
            || my_decl->has_name("operator>")
            || my_decl->has_name("operator>=")
            || my_decl->has_name("operator<=>")
        )
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_increment_or_decrement() const
    -> bool
{
    if (
        my_decl->has_name("operator++")
        || my_decl->has_name("operator--")
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_compound_assignment() const
    -> bool
{
    if (
        (
            my_decl->has_name("operator+=")
            || my_decl->has_name("operator-=")
            || my_decl->has_name("operator*=")
            || my_decl->has_name("operator/=")
            || my_decl->has_name("operator%=")
            || my_decl->has_name("operator&=")
            || my_decl->has_name("operator|=")
            || my_decl->has_name("operator^=")
            || my_decl->has_name("operator<<=")
            || my_decl->has_name("operator>>=")
        )
        && (*parameters).ssize() > 1
        && (*parameters)[0]->has_name("this")
        && (*parameters)[0]->direction() == passing_style::inout
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_assignment() const
    -> bool
{
    if (
        my_decl->has_name("operator=")
        && (*parameters).ssize() > 1
        && (*parameters)[0]->has_name("this")
        && (*parameters)[0]->direction() == passing_style::inout
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_assignment_with_in_that() const
    -> bool
{
    if (
        is_assignment()
        && (*parameters).ssize() == 2
        && (*parameters)[1]->has_name("that")
        && (*parameters)[1]->direction() == passing_style::in
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_assignment_with_move_that() const
    -> bool
{
    if (
        is_assignment()
        && (*parameters).ssize() == 2
        && (*parameters)[1]->has_name("that")
        && (*parameters)[1]->direction() == passing_style::move
        )
    {
        return true;
    }
    return false;
}


auto function_type_node::is_destructor() const
    -> bool
{
    if (
        my_decl->has_name("operator=")
        && (*parameters).ssize() == 1
        && (*parameters)[0]->has_name("this")
        && (*parameters)[0]->direction() == passing_style::move
        )
    {
        return true;
    }
    return false;
}


auto primary_expression_node::template_arguments() const
    -> std::vector<template_argument> const&
{
    if (expr.index() == id_expression) {
        return std::get<id_expression>(expr)->template_arguments();
    }
    // else
    return no_template_args;
}


auto primary_expression_node::get_token() const
    -> token const*
{
    if (expr.index() == identifier) {
        return std::get<identifier>(expr);
    }
    else if (expr.index() == id_expression) {
        return std::get<id_expression>(expr)->get_token();
    }
    else if (expr.index() == literal) {
        return std::get<literal>(expr)->get_token();
    }
    // else (because we're deliberately ignoring the other
    //       options which are more than a single token)
    return {};
}


auto primary_expression_node::position() const
    -> source_position
{
    switch (expr.index())
    {
    break;case empty:
        return { 0, 0 };

    break;case identifier: {
        auto const& s = std::get<identifier>(expr);
        assert (s);
        return s->position();
    }

    break;case expression_list: {
        auto const& s = std::get<expression_list>(expr);
        assert (s);
        return s->position();
    }

    break;case id_expression: {
        auto const& s = std::get<id_expression>(expr);
        assert (s);
        return s->position();
    }

    break;case declaration: {
        auto const& s = std::get<declaration>(expr);
        assert (s);
        return s->position();
    }

    break;case inspect: {
        auto const& i = std::get<inspect>(expr);
        assert (i);
        return i->position();
    }

    break;case literal: {
        auto const& i = std::get<literal>(expr);
        assert (i);
        return i->position();
    }

    break;default:
        assert (!"illegal primary_expression_node state");
        return { 0, 0 };
    }
}


auto primary_expression_node::visit(auto& v, int depth)
    -> void
{
    v.start(*this, depth);
    try_visit<identifier     >(expr, v, depth);
    try_visit<expression_list>(expr, v, depth);
    try_visit<id_expression  >(expr, v, depth);
    try_visit<declaration    >(expr, v, depth);
    try_visit<inspect        >(expr, v, depth);
    try_visit<literal        >(expr, v, depth);
    v.end(*this, depth);
}


struct next_expression_tag { };
struct loop_body_tag { iteration_statement_node const* n; };

auto iteration_statement_node::visit(auto& v, int depth)
    -> void
{
    v.start(*this, depth);
    if (label) {
        label->visit(v, depth+1);
    }
    if (identifier) {
        identifier->visit(v, depth+1);
    }
    if (statements) {
        statements->visit(v, depth+1);
    }
    if (next_expression) {
        v.start(next_expression_tag{}, depth);
        next_expression->visit(v, depth+1);
        v.end(next_expression_tag{}, depth);
    }
    if (condition) {
        assert(!range && !body);
        condition->visit(v, depth+1);
    }
    else {
        assert(range && parameter && body);
        range->visit(v, depth+1);
        v.start(loop_body_tag{this}, depth);
        parameter->visit(v, depth+1);
        body->visit(v, depth+1);
        v.end(loop_body_tag{this}, depth);
    }
    v.end(*this, depth);
}


auto statement_node::position() const
    -> source_position
{
    switch (statement.index())
    {
    break;case expression: {
        auto const& s = std::get<expression>(statement);
        assert (s);
        return s->position();
    }

    break;case compound: {
        auto const& s = std::get<compound>(statement);
        assert (s);
        return s->position();
    }

    break;case selection: {
        auto const& s = std::get<selection>(statement);
        assert (s);
        return s->position();
    }

    break;case declaration: {
        auto const& s = std::get<declaration>(statement);
        assert (s);
        return s->position();
    }

    break;case return_: {
        auto const& s = std::get<return_>(statement);
        assert (s);
        return s->position();
    }

    break;case iteration: {
        auto const& s = std::get<iteration>(statement);
        assert (s);
        return s->position();
    }

    break;case using_: {
        auto const& s = std::get<using_>(statement);
        assert (s);
        return s->position();
    }

    break;case contract: {
        auto const& s = std::get<contract>(statement);
        assert (s);
        return s->position();
    }

    break;case inspect: {
        auto const& s = std::get<inspect>(statement);
        assert (s);
        return s->position();
    }

    break;case jump: {
        auto const& s = std::get<jump>(statement);
        assert (s);
        return s->position();
    }

    break;default:
        assert (!"illegal statement_node state");
        return { 0, 0 };
    }
}


auto parameter_declaration_node::position() const
    -> source_position
{
    assert (declaration);
    return pos;
}


auto parameter_declaration_node::visit(auto& v, int depth)
    -> void
{
    v.start(*this, depth);
    assert(declaration);
    declaration->visit(v, depth + 1);
    v.end(*this, depth);
}


struct translation_unit_node
{
    std::vector< std::unique_ptr<declaration_node> > declarations;

    auto position() const -> source_position
    {
        if (std::ssize(declarations) > 0) {
            return declarations.front()->position();
        }
        return {};
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        for (auto const& x : declarations) {
            assert(x);
            x->visit(v, depth + 1);
        }
        v.end(*this, depth);
    }
};

// Definitions of out-of-line dtors for nodes with unique_ptr members of forward-declared types
primary_expression_node::~primary_expression_node() = default;

prefix_expression_node::~prefix_expression_node() = default;

template<
    String   Name,
    typename Term
>
binary_expression_node<Name, Term>::~binary_expression_node() = default;

alternative_node::~alternative_node() = default;

iteration_statement_node::~iteration_statement_node() = default;

template_argument::~template_argument() = default;

inspect_expression_node::~inspect_expression_node() = default;

statement_node::~statement_node() = default;


//-----------------------------------------------------------------------
//
//  pretty_print_visualize: pretty-prints Cpp2 ASTs
//
//-----------------------------------------------------------------------
//
auto pretty_print_visualize(token const& n, int indent)
    -> std::string;
auto pretty_print_visualize(primary_expression_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(literal_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(prefix_expression_node const& n, int indent)
    -> std::string;
template<
    String   Name,
    typename Term
>
auto pretty_print_visualize(binary_expression_node<Name,Term> const& n, int indent)
    -> std::string;
auto pretty_print_visualize(expression_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(expression_list_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(expression_statement_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(postfix_expression_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(unqualified_id_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(qualified_id_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(type_id_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(is_as_expression_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(id_expression_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(compound_statement_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(selection_statement_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(iteration_statement_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(return_statement_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(alternative_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(inspect_expression_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(contract_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(jump_statement_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(using_statement_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(statement_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(parameter_declaration_node const& n, int indent, bool is_template_param = false)
    -> std::string;
auto pretty_print_visualize(parameter_declaration_list_node const& n, int indent, bool is_template_param_list = false)
    -> std::string;
auto pretty_print_visualize(function_type_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(type_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(namespace_node const& n, int indent)
    -> std::string;
auto pretty_print_visualize(declaration_node const& n, int indent, bool include_metafunctions_list = false)
    -> std::string;


auto primary_expression_node::to_string() const
-> std::string
{
    switch (expr.index())
    {
    break; case empty:
        return {};

    break; case identifier: {
        auto const& s = std::get<identifier>(expr);
        assert(s);
        return s->to_string();
    }

    break; case expression_list: {
        auto const& s = std::get<expression_list>(expr);
        assert(s);
        return s->to_string();
    }

    break; case id_expression: {
        auto const& s = std::get<id_expression>(expr);
        assert(s);
        return s->to_string();
    }

    break; case declaration: {
        auto const& s = std::get<declaration>(expr);
        assert(s);
        return pretty_print_visualize(*s, 0);
    }

    break; case literal: {
        auto const& i = std::get<literal>(expr);
        assert(i);
        return i->to_string();
    }

    break; default:
        return "(*ERROR*) temporary alpha limitation: type metafunctions cannot stringize expressions that involve nested inspect expressions";
    }
}



//-----------------------------------------------------------------------
//  pre: Get an indentation prefix
//
inline static int         indent_spaces  = 2;
inline static std::string indent_str     = std::string( 1024, ' ' );    // "1K should be enough for everyone"

auto pre(int indent)
    -> std::string_view
{
    assert (indent >= 0);
    return {
        indent_str.c_str(),
        impl::as<size_t>( std::min( indent*indent_spaces, _as<int>(std::ssize(indent_str))) )
    };
}


//-----------------------------------------------------------------------
//  try_pretty_print_visualize
//
//  Helper to emit whatever is in a variant where each
//  alternative is a smart pointer
//
template <int I>
auto try_pretty_print_visualize(
    auto&     v,
    auto&&... more
)
    -> std::string
{
    if (v.index() == I) {
        auto const& alt = std::get<I>(v);
        assert (alt);
        return pretty_print_visualize (*alt, CPP2_FORWARD(more)...);
    }
    return "";
}


auto pretty_print_visualize(token const& t, int)
    -> std::string
{
    return t.to_string();
}


auto pretty_print_visualize(primary_expression_node const& n, int indent)
    -> std::string
{
    auto ret = std::string{};

    ret += try_pretty_print_visualize<primary_expression_node::identifier     >(n.expr, indent);
    ret += try_pretty_print_visualize<primary_expression_node::expression_list>(n.expr, indent);
    ret += try_pretty_print_visualize<primary_expression_node::id_expression  >(n.expr, indent);
    ret += try_pretty_print_visualize<primary_expression_node::declaration    >(n.expr, indent);
    ret += try_pretty_print_visualize<primary_expression_node::inspect        >(n.expr, indent);
    ret += try_pretty_print_visualize<primary_expression_node::literal        >(n.expr, indent);

    return ret;
}


auto pretty_print_visualize(literal_node const& n, int)
    -> std::string
{
    return n.to_string();
}


auto pretty_print_visualize(prefix_expression_node const& n, int indent)
    -> std::string
{
    assert(n.expr);

    auto ret = std::string{};

    for (auto& op : n.ops) {
        assert(op);
        ret += op->as_string_view();
    }

    ret += pretty_print_visualize(*n.expr, indent);

    return ret;
}


template<
    String   Name,
    typename Term
>
auto pretty_print_visualize(binary_expression_node<Name,Term> const& n, int indent)
    -> std::string
{
    assert(n.expr);

    auto ret = pretty_print_visualize(*n.expr, indent);
    for (auto& term : n.terms) {
        assert(term.op && term.expr);
        ret += " " + term.op->to_string()
            + " " + pretty_print_visualize(*term.expr, indent);
    }
    return ret;
}


auto pretty_print_visualize(expression_node const& n, int indent)
    -> std::string
{
    assert(n.expr);
    return pretty_print_visualize(*n.expr, indent);
}


auto pretty_print_visualize(expression_list_node const& n, int indent)
    -> std::string
{
    assert(n.open_paren && n.close_paren);

    auto ret = n.open_paren->to_string();

    for (auto i = 0; auto& expr : n.expressions) {
        assert(expr.expr);
        if (
            expr.pass == passing_style::out
            || expr.pass == passing_style::move
            || expr.pass == passing_style::forward
            )
        {
            ret += to_string_view(expr.pass) + std::string{" "};
        }
        ret += pretty_print_visualize(*expr.expr, indent);
        if (++i < std::ssize(n.expressions)) {
            ret += ", ";
        }
    }

    ret += n.close_paren->as_string_view();

    return ret;
}


auto pretty_print_visualize(expression_statement_node const& n, int indent)
    -> std::string
{
    assert(n.expr);

    auto ret = pretty_print_visualize(*n.expr, indent);

    if (n.has_semicolon && ret.back() != ';') {
        ret += ";";
    }

    return ret;
}


auto pretty_print_visualize(postfix_expression_node const& n, int indent)
    -> std::string
{
    assert(n.expr);

    auto ret = pretty_print_visualize(*n.expr, indent);

    for (auto& op : n.ops)
    {
        assert(op.op);
        if (op.expr_list) {
            assert (op.op_close);
            ret += pretty_print_visualize(*op.expr_list, indent);
        }
        else {
            ret += op.op->as_string_view();
            if (op.id_expr) {
                ret += pretty_print_visualize(*op.id_expr, indent);
            }
        }
    }

    return ret;
}


auto pretty_print_visualize(unqualified_id_node const& n, int indent)
    -> std::string
{
    assert(n.identifier);

    auto ret = n.identifier->to_string();

    if (n.open_angle != source_position{})
    {
        ret += "<";
        for (bool first = true; auto& arg : n.template_args)
        {
            if (!first) {
                ret += ", ";
            }
            first = false;
            ret += try_pretty_print_visualize<template_argument::expression>(arg.arg, indent);
            ret += try_pretty_print_visualize<template_argument::type_id   >(arg.arg, indent);
        }
        ret += ">";
    }

    return ret;
}


auto pretty_print_visualize(qualified_id_node const& n, int indent)
    -> std::string
{
    auto ret = std::string{};

    for (auto& id : n.ids) {
        if (id.scope_op) { ret += id.scope_op->as_string_view(); }
        assert (id.id);
        ret += pretty_print_visualize(*id.id, indent);
    }

    return ret;
}


auto pretty_print_visualize(type_id_node const& n, int indent)
    -> std::string
{
    auto ret = std::string{};

    for (auto& qual : n.pc_qualifiers) {
        assert(qual);
        ret += qual->as_string_view();
        ret += " ";
    }

    if (n.id.index() == type_id_node::empty) { ret += "_"; }
    ret += try_pretty_print_visualize<type_id_node::qualified  >(n.id, indent);
    ret += try_pretty_print_visualize<type_id_node::unqualified>(n.id, indent);
    ret += try_pretty_print_visualize<type_id_node::keyword    >(n.id, indent);

    return ret;
}


auto pretty_print_visualize(is_as_expression_node const& n, int indent)
    -> std::string
{
    assert (n.expr);

    auto ret = pretty_print_visualize(*n.expr, indent);

    for (auto& op : n.ops) {
        if (op.op)   { ret += " " + op.op->to_string() + " "; }
        if (op.type) { ret += pretty_print_visualize(*op.type, indent); }
        if (op.expr) { ret += pretty_print_visualize(*op.expr, indent); }
    }

    return ret;
}


auto pretty_print_visualize(id_expression_node const& n, int indent)
    -> std::string
{
    auto ret = std::string{};

    ret += try_pretty_print_visualize<id_expression_node::qualified  >(n.id, indent);
    ret += try_pretty_print_visualize<id_expression_node::unqualified>(n.id, indent);

    return ret;
}


auto pretty_print_visualize(compound_statement_node const& n, int indent)
    -> std::string
{
    auto ret = std::string{"\n"} + pre(indent) + "{";

    for (auto& stmt : n.statements) {
        assert (stmt);
        ret += pretty_print_visualize(*stmt, indent+1);
    }

    ret += std::string{"\n"} + pre(indent) + "}";

    return ret;
}


auto pretty_print_visualize(selection_statement_node const& n, int indent)
    -> std::string
{
    assert (n.identifier && n.expression && n.true_branch && n.false_branch);

    auto ret = std::string{};

    ret += std::string{"\n"} + pre(indent) + n.identifier->as_string_view() + " ";

    if (n.is_constexpr) {
        ret += "constexpr ";
    }

    ret += pretty_print_visualize(*n.expression, indent)
        + pretty_print_visualize(*n.true_branch, indent);

    if (n.has_source_false_branch) {
        ret += std::string{"\n"} + pre(indent) + "else "
            + pretty_print_visualize(*n.false_branch, indent);
    }

    return ret;
}


auto pretty_print_visualize(iteration_statement_node const& n, int indent)
    -> std::string
{
    //  First compute the common parts

    auto next_expr = std::string{};
    if (n.next_expression) {
        next_expr += std::string{"\n"} + pre(indent) + "next " + pretty_print_visualize(*n.next_expression, indent);
    }

    auto stmts = std::string{};
    if (n.statements) {
        stmts += pretty_print_visualize(*n.statements, indent+1);
    }

    //  Then slot them in where appropriate

    auto ret = std::string{};
    assert (n.identifier);

    ret += std::string{"\n"} + pre(indent);
    if (n.label) {
        ret += n.label->to_string()
            + ": ";
    }

    if (*n.identifier == "while") {
        assert (n.condition);
        ret += "while "
            + pretty_print_visualize(*n.condition, indent) + next_expr + stmts;
    }
    else if (*n.identifier == "do") {
        assert (n.condition);
        ret += "do "
            + stmts
            + next_expr
            + "\n" + pre(indent) + "while "
            + pretty_print_visualize(*n.condition, indent);
        if (ret.back() != ';') {
            ret += ";";
        }
    }
    else {
        assert (n.range && n.parameter && n.body);
        ret += "for "
            + pretty_print_visualize(*n.range, indent)
            + next_expr
            + "\n" + pre(indent) + "do (" + pretty_print_visualize(*n.parameter, indent + 1) + ")"
            + pretty_print_visualize(*n.body, indent+1);
    }

    return ret;
}


auto pretty_print_visualize(return_statement_node const& n, int indent)
    -> std::string
{
    auto ret = std::string{"\n"} + pre(indent) + "return";

    if (n.expression) {
        ret += " " + pretty_print_visualize(*n.expression, indent);
    }

    if (ret.back() != ';') {
        ret += ";";
    }

    return ret;
}


auto pretty_print_visualize(alternative_node const& n, int indent)
    -> std::string
{
    auto ret = std::string{};
    assert (n.is_as_keyword);
    ret += std::string{"\n"} + pre(indent);
    if (n.name) {
        ret += pretty_print_visualize(*n.name, indent) + ": ";
    }
    ret += n.is_as_keyword->as_string_view();
    if (n.type_id) {
        ret += " " + pretty_print_visualize(*n.type_id, indent);
    }
    if (n.value) {
        ret += " " + pretty_print_visualize(*n.value, indent);
    }
    ret += " = " + pretty_print_visualize(*n.statement, indent+1);
    return ret;
}


auto pretty_print_visualize(inspect_expression_node const& n, int indent)
    -> std::string
{
    assert (n.expression);

    auto ret = std::string{"inspect"};

    if (n.is_constexpr) {
        ret += " constexpr";
    }

    ret += " " + pretty_print_visualize(*n.expression, indent);

    if (n.result_type) {
        ret += " -> " + pretty_print_visualize(*n.result_type, indent);
    }

    ret += " {";

    for (auto& alt : n.alternatives) {
        assert(alt);
        ret += pretty_print_visualize(*alt, indent+1);
    }

    ret += std::string{"\n"} + pre(indent) + "}";

    return ret;
}


auto pretty_print_visualize(contract_node const& n, int indent)
    -> std::string
{
    assert (n.kind && n.condition);

    auto ret = std::string{"\n"} + pre(indent) + n.kind->as_string_view();

    if (n.group) {
        ret += "<" + pretty_print_visualize(*n.group, indent);
        for (auto const& flag : n.flags) {
            ret += "," + pretty_print_visualize(*flag, indent);
        }
        ret += ">";
    }

    ret += "( " + pretty_print_visualize(*n.condition, indent);

    if (n.message) {
        ret += ", " + pretty_print_visualize(*n.message, indent);
    }

    ret += " )";

    if (*n.kind == "assert" && ret.back() != ';') {
        ret += ";";
    }

    return ret;
}


auto pretty_print_visualize(jump_statement_node const& n, int indent)
    -> std::string
{
    assert (n.keyword);

    auto ret = std::string{"\n"} + pre(indent) + n.keyword->as_string_view();

    if (n.label) {
        ret += " " + n.label->to_string();
    }

    if (ret.back() != ';') {
        ret += ";";
    }

    return ret;
}


auto pretty_print_visualize(using_statement_node const& n, int indent)
    -> std::string
{
    assert (n.keyword);

    auto ret = std::string{"\n"} + pre(indent) + n.keyword->as_string_view() + " ";

    if (n.for_namespace) {
        ret += "namespace ";
    }

    ret += pretty_print_visualize(*n.id, indent);
    if (ret.back() != ';') {
        ret += ";";
    }

    return ret;
}


auto pretty_print_visualize(statement_node const& n, int indent)
    -> std::string
{
    auto ret = std::string{};

    if (n.is_expression())
    {
        if (n.compound_parent) {
            ret += std::string{"\n"} + pre(indent);
        }
        auto& expr = std::get<statement_node::expression>(n.statement);
        assert (expr);
        ret += pretty_print_visualize(*expr, indent);
    }
    else
    {
        if (n.parameters) {
            ret += std::string{"\n"} + pre(indent) + pretty_print_visualize(*n.parameters, indent);
        }

        ret += try_pretty_print_visualize<statement_node::compound   >(n.statement, indent);
        ret += try_pretty_print_visualize<statement_node::selection  >(n.statement, indent);
        ret += try_pretty_print_visualize<statement_node::declaration>(n.statement, indent);
        ret += try_pretty_print_visualize<statement_node::return_    >(n.statement, indent);
        ret += try_pretty_print_visualize<statement_node::iteration  >(n.statement, indent);
        ret += try_pretty_print_visualize<statement_node::using_     >(n.statement, indent);
        ret += try_pretty_print_visualize<statement_node::contract   >(n.statement, indent);
        ret += try_pretty_print_visualize<statement_node::inspect    >(n.statement, indent);
        ret += try_pretty_print_visualize<statement_node::jump       >(n.statement, indent);
    }

    return ret;
}


auto pretty_print_visualize(parameter_declaration_node const& n, int indent, bool is_template_param_list /* = false */ )
    -> std::string
{
    assert (n.declaration);

    auto ret = std::string{};

    if (!is_template_param_list) {
        switch (n.mod) {
        break;case parameter_declaration_node::modifier::implicit : ret += "implicit ";
        break;case parameter_declaration_node::modifier::virtual_ : ret += "virtual ";
        break;case parameter_declaration_node::modifier::override_: ret += "override ";
        break;case parameter_declaration_node::modifier::final_   : ret += "final ";
        break;default: ; // none
        }

        ret += to_string_view(n.pass);
        ret += " ";
    }

    ret += pretty_print_visualize(*n.declaration, indent);

    return ret;
}


auto pretty_print_visualize(parameter_declaration_list_node const& n, int indent, bool is_template_param_list /* = false */)
    -> std::string
{
    assert(n.open_paren && n.close_paren);

    auto ret = n.open_paren->to_string();

    auto space = std::string{};
    if (std::ssize(n.parameters) > 1) {
        space += std::string{"\n"} + pre(indent+1);
    }

    for (auto& param : n.parameters) {
        ret += space + pretty_print_visualize(*param, indent+1, is_template_param_list) + ", ";
    }

    if (std::ssize(n.parameters) > 1) {
        ret += std::string{"\n"} + pre(indent);
    }
    ret += n.close_paren->to_string();

    return ret;
}


auto pretty_print_visualize(function_type_node const& n, int indent)
    -> std::string
{
    assert (n.parameters);

    auto ret = pretty_print_visualize(*n.parameters, indent);

    if (n.throws) {
        ret += " throws";
    }

    if (n.has_non_void_return_type()) {
        ret += " -> ";
        ret += try_pretty_print_visualize<function_type_node::list>(n.returns, indent+1);
        if (n.returns.index() == function_type_node::id) {
            auto& single = std::get<function_type_node::id>(n.returns);
            ret += to_string_view(single.pass)
                + std::string{" "} + pretty_print_visualize(*single.type, indent+1);
        }
    }

    for (auto& contract: n.contracts) {
        assert(contract);
        ret += pretty_print_visualize(*contract, indent+1);
    }

    return ret;
}


auto pretty_print_visualize(type_node const& n)
    -> std::string
{
    assert (n.type);

    auto ret = std::string{};

    if (n.final) {
        ret += "final ";
    }

    ret += "type";

    return ret;
}


auto pretty_print_visualize(namespace_node const&)
    -> std::string
{
    return "namespace";
}


auto pretty_print_visualize(declaration_node const& n, int indent, bool include_metafunctions_list /* = false */ )
    -> std::string
{
    indent_spaces = 4;

    //  First compute the common parts

    auto metafunctions = std::string{};
    {
    auto as_comment =
        !n.metafunctions.empty()
        && !include_metafunctions_list;
    if (as_comment) {
        metafunctions += "/*";
    }
    for (auto& meta : n.metafunctions) {
        metafunctions += " @" + pretty_print_visualize(*meta, indent);
    }
    if (as_comment) {
        metafunctions += " */";
    }
    }

    auto template_params = std::string{};
    if (n.template_parameters) {
        template_params += " " + pretty_print_visualize(*n.template_parameters, indent + 1, true);
    }

    auto requires_clause = std::string{};
    if (n.requires_clause_expression) {
        requires_clause += " requires (" + pretty_print_visualize(*n.requires_clause_expression, indent) + ")";
    }

    auto initializer = std::string{};
    if (n.initializer) {
        auto adjusted_indent = indent;
        if (!n.name()) {
            ++adjusted_indent;
        }
        initializer = " =";
        if (n.is_function() && n.is_constexpr) {
            initializer += "=";
        }
        initializer += " " + pretty_print_visualize(*n.initializer, adjusted_indent);
        if (initializer.ends_with(";;")) {
            initializer.pop_back();
        }
    }
    else if (!n.is_parameter()) {
        initializer = ";";
    }

    //  Then slot them in where appropriate

    auto ret = std::string{""};

    //  Add an extra newline for spacing, unless this declaration
    //  is within a function body or is the first member of a type
    if (
        !n.parent_is_function()
        && !n.parent_is_object()
        && !n.is_parameter()
        )
    {
        static declaration_node const* last_parent_type = {};
        if (n.parent_is_type()) {
            if (last_parent_type != n.get_parent()) {
                last_parent_type = n.get_parent();
            }
            else {
                ret += "\n";
            }
        }
        else {
            ret += "\n";
        }
    }
    if (!n.is_parameter() && n.name()) {
        ret += std::string{"\n"} + pre(indent);
    }

    switch (n.access) {
    break;case accessibility::public_    : ret += "public ";
    break;case accessibility::protected_ : ret += "protected ";
    break;case accessibility::private_   : ret += "private ";
    break;default: ; // default accessibility
    }

    if (n.identifier) {
        ret += pretty_print_visualize(*n.identifier, indent);
    }

    if (n.is_parameter() && (n.has_name("this") || n.has_name("that"))) {
        return ret;
    }

    if (n.is_variadic) {
        ret += "...";
    }

    ret += ":";

    if (n.is_function()) {
        auto& func = std::get<declaration_node::a_function>(n.type);
        assert(func);
        ret += metafunctions
            + template_params
            + pretty_print_visualize(*func, indent)
            + requires_clause
            + initializer;
    }
    else if (n.is_object()) {
        auto& type_id = std::get<declaration_node::an_object>(n.type);
        assert(type_id);
        ret += metafunctions
            + template_params
            + " " + pretty_print_visualize(*type_id, indent)
            + requires_clause
            + initializer;
    }
    else if (n.is_type()) {
        auto& t = std::get<declaration_node::a_type>(n.type);
        assert(t);
        ret += metafunctions
            + template_params
            + " " + pretty_print_visualize(*t)
            + initializer;
    }
    else if (n.is_namespace()) {
        auto& t = std::get<declaration_node::a_type>(n.type);
        assert(t);
        ret += "namespace = "
            + initializer;
    }
    else if (n.is_alias()) {
        auto& a = std::get<declaration_node::an_alias>(n.type);
        assert(a);

        auto object_type_id = std::string{};
        if (a->type_id) {
            object_type_id += " " + pretty_print_visualize(*a->type_id, indent);
        }

        ret += template_params;
        if (a->is_type_alias()) {
            auto& t = std::get<alias_node::a_type>(a->initializer);
            ret += " type"
                + requires_clause
                + " == "
                + pretty_print_visualize(*t, indent);
            if (ret.back() != ';') {
                ret += ";";
            }
        }
        else if (a->is_namespace_alias()) {
            auto& id = std::get<alias_node::a_namespace>(a->initializer);
            assert(id);
            ret += " namespace == "
                + pretty_print_visualize(*id, indent);
            if (ret.back() != ';') {
                ret += ";";
            }
        }
        else if (a->is_object_alias()) {
            auto& expr = std::get<alias_node::an_object>(a->initializer);
            assert(expr);
            ret += object_type_id
                + requires_clause
                + " == "
                + pretty_print_visualize(*expr, indent);
            if (ret.back() != ';') {
                ret += ";";
            }
        }
    }

    return ret;
}


auto pretty_print_visualize(translation_unit_node const& n)
    -> std::string
{
    auto ret = std::string{};

    for (auto& decl : n.declarations) {
        assert(decl);
        ret += pretty_print_visualize(*decl, 0);
    }

    return ret;
}


//-----------------------------------------------------------------------
//
//  parser: parses a section of Cpp2 code
//
//-----------------------------------------------------------------------
//
class parser
{
    std::vector<error_entry>& errors;

    std::unique_ptr<translation_unit_node> parse_tree = {};

    //  Keep a stack of current capture groups (contracts/decls still being parsed)
    std::vector<capture_group*> current_capture_groups = {};

    struct capture_groups_stack_guard
    {
        parser* pars;

        capture_groups_stack_guard(parser* p, capture_group* cg)
            : pars{ p }
        {
            assert(p);
            assert(cg);
            pars->current_capture_groups.push_back(cg);
        }

        ~capture_groups_stack_guard()
        {
            pars->current_capture_groups.pop_back();
        }
    };

    //  Keep a stack of currently active declarations (still being parsed)
    std::vector<declaration_node*> current_declarations = { nullptr };

    struct current_declarations_stack_guard
    {
        parser* pars;

        current_declarations_stack_guard(parser* p, declaration_node* decl)
            : pars{ p }
        {
            assert(p);
            assert(decl);
            pars->current_declarations.push_back(decl);
        }

        ~current_declarations_stack_guard()
        {
            pars->current_declarations.pop_back();
        }
    };

    std::vector<token> const* tokens = {};
    stable_vector<token>*     generated_tokens = {};
    int pos = 0;
    std::string parse_kind = {};

    //  Keep track of the function bodies' locations - used to emit comments
    //  in the right pass (decide whether it's a comment that belongs with
    //  the declaration or is part of the definition)
    struct function_body_extent {
        lineno_t first;
        lineno_t last;
        auto operator<=>(function_body_extent const&) const = default;
        auto operator<=>(int i) const { return first <=> i; }

        function_body_extent( lineno_t f, lineno_t l ): first{f}, last{l} { }
    };
    mutable std::vector<function_body_extent> function_body_extents;
    mutable bool                              is_function_body_extents_sorted = false;
    bool                                      is_inside_call_expr = false;

public:
    auto is_within_function_body(source_position p) const
    {
        //  Short circuit the empty case, so that the rest of the function
        //  can unconditionally decrement any non-.begin() iterator once
        if (function_body_extents.empty()) {
            return false;
        }

        //  Ensure we are sorted
        if (!is_function_body_extents_sorted) {
            std::sort(
                function_body_extents.begin(),
                function_body_extents.end()
            );
            is_function_body_extents_sorted = true;
        }

        //  Find the first entry that is beyond pos, and back up one to
        //  the last that could be a match; this also ensures iter is
        //  dereferenceable, not .end()
        auto iter = std::lower_bound(
            function_body_extents.begin(),
            function_body_extents.end(),
            p.lineno+1
        );
        if (iter != function_body_extents.begin()) {
            --iter;
        }

        //  Now go backwards through the preceding entries until
        //  one includes pos or we move before pos
        while (
            iter->first <= p.lineno
            )
        {
            if (
                iter->first <= p.lineno
                && p.lineno <= iter->last
                )
            {
                return true;
            }
            if (iter == function_body_extents.begin()) {
                break;
            }
            --iter;
        }
        return false;
    }


public:
    //-----------------------------------------------------------------------
    //  Constructors - the copy constructor constructs a new instance with
    //                 the same errors reference but otherwise a clean slate
    //
    //  errors      error list
    //
    parser( std::vector<error_entry>& errors_ )
        : errors{ errors_ }
        , parse_tree{std::make_unique<translation_unit_node>()}
    { }

    parser( parser const& that )
        : errors{ that.errors }
        , parse_tree{std::make_unique<translation_unit_node>()}
    { }


    //-----------------------------------------------------------------------
    //  parse
    //
    //  tokens              input tokens for this section of Cpp2 source code
    //  generated_tokens    a shared place to store generated tokens
    //
    //  Each call parses this section's worth of tokens and adds the
    //  result to the stored parse tree. Call this repeatedly for the Cpp2
    //  sections in a TU to build the whole TU's parse tree
    //
    auto parse(
        std::vector<token> const&  tokens_,
        stable_vector<token>&      generated_tokens_
    )
        -> bool
    {
        parse_kind = "source file";

        //  Set per-parse state for the duration of this call
        tokens           = &tokens_;
        generated_tokens = &generated_tokens_;

        //  Generate parse tree for this section as if a standalone TU
        pos     = 0;
        auto tu = translation_unit();

        //  Then add it to the complete parse tree
        parse_tree->declarations.insert(
            parse_tree->declarations.end(),
            std::make_move_iterator(tu->declarations.begin()),
            std::make_move_iterator(tu->declarations.end())
        );
        if (!done()) {
            error("unexpected text at end of Cpp2 code section", true, {}, true);
            return false;
        }
        return true;
    }


    //-----------------------------------------------------------------------
    //  parse_one_statement
    //
    //  tokens              input tokens for this section of Cpp2 source code
    //  generated_tokens    a shared place to store generated tokens
    //
    //  Each call parses one statement and returns its parse tree.
    //
    auto parse_one_declaration(
        std::vector<token> const& tokens_,
        stable_vector<token>&     generated_tokens_
    )
        -> std::unique_ptr<statement_node>
    {
        parse_kind = "source string during code generation";

        //  Set per-parse state for the duration of this call
        tokens           = &tokens_;
        generated_tokens = &generated_tokens_;

        try {
            //  Parse one declaration - we succeed if the parse succeeded,
            //  and there were no new errors, and all tokens were consumed
            auto errors_size = std::ssize(errors);
            pos = 0;
            if (auto d = statement();
                d
                && std::ssize(errors) == errors_size
                && done()
                )
            {
                return d;
            }
        }
        catch(std::runtime_error& e) {
            error(e.what(), true, {}, true);
        }

        return {};
    }


    //-----------------------------------------------------------------------
    //  Get a set of pointers to just the declarations in the given token map section
    //
    auto get_parse_tree_declarations_in_range(std::vector<token> const& token_range) const
        -> std::vector< declaration_node const* >
    {
        assert (parse_tree);
        assert (!token_range.empty());
        auto first_line = token_range.front().position().lineno;
        auto last_line  = token_range.back().position().lineno;

        auto ret = std::vector< declaration_node const* >{};
        for (auto& decl : parse_tree->declarations)
        {
            assert(decl);

            //  The grammar and the tokens are in lineno order, so we don't
            //  need to look further once we pass the last lineno
            if (decl->position().lineno > last_line) {
                break;
            }
            if (decl->position().lineno >= first_line) {
                ret.push_back( decl.get() );
            }
        }

        return ret;
    }


    //-----------------------------------------------------------------------
    //  visit
    //
    auto visit(auto& v) const -> void
    {
        parse_tree->visit(v, 0);
    }

private:
    //-----------------------------------------------------------------------
    //  Error reporting: Fed into the supplied this->errors object
    //
    //  msg                 message to be printed
    //
    //  include_curr_token  in this file (during parsing), we normally want
    //                      to show the current token as the unexpected text
    //                      we encountered, but some sema rules are applied
    //                      early during parsing and for those it doesn't
    //                      make sense to show the next token (e.g., when
    //                      we detect and reject a "std::move" qualified-id,
    //                      it's not relevant to add "at LeftParen: ("
    //                      just because ( happens to be the next token)
    //
    auto error(
        char const*     msg,
        bool            include_curr_token = true,
        source_position err_pos            = {},
        bool            fallback           = false
    ) const
        -> void
    {
        auto m = std::string{msg};
        auto i = done() ? -1 : 0;
        assert (peek(i));
        if (include_curr_token) {
            m += std::string(" (at '") + peek(i)->to_string() + "')";
        }
        if (
            err_pos == source_position{}
        ) {
            err_pos = peek(i)->position();
        }
        errors.emplace_back( err_pos, m, false, fallback );
    }

    auto error(
        std::string const& msg,
        bool               include_curr_token = true,
        source_position    err_pos            = {},
        bool               fallback           = false
    ) const
        -> void
    {
        error( msg.c_str(), include_curr_token, err_pos, fallback );
    }

    bool has_error() {
        return !errors.empty();
    }


    //-----------------------------------------------------------------------
    //  Token navigation: Only these functions should access this->token_
    //
    auto curr() const
        -> token const&
    {
        if (done()) {
            throw std::runtime_error("unexpected end of " + parse_kind);
        }

        return (*tokens)[pos];
    }

    auto peek(int num) const
        -> token const*
    {
        assert (tokens);
        if (
            pos + num >= 0
            && pos + num < std::ssize(*tokens)
            )
        {
            return &(*tokens)[pos + num];
        }
        return {};
    }

    auto done() const
        -> bool
    {
        assert (tokens);
        assert (pos <= std::ssize(*tokens));
        return pos == std::ssize(*tokens);
    }

    auto next(int num = 1)
        -> void
    {
        assert (tokens);
        pos = std::min( pos+num, _as<int>(std::ssize(*tokens)) );
    }


    //-----------------------------------------------------------------------
    //  Parsers for unary expressions
    //

    //G primary-expression:
    //G     inspect-expression
    //G     id-expression
    //G     literal
    //G     '(' expression-list ','? ')'
    //G     unnamed-declaration
    //G
    auto primary_expression()
        -> std::unique_ptr<primary_expression_node>
    {
        auto n = std::make_unique<primary_expression_node>();

        if (auto inspect = inspect_expression(true))
        {
            n->expr = std::move(inspect);
            return n;
        }

        if (auto id = id_expression()) {
            n->expr = std::move(id);
            return n;
        }

        if (auto lit = literal()) {
            n->expr = std::move(lit);
            return n;
        }

        if (curr().type() == lexeme::LeftParen
            //  If in the future (not now) we decide to allow braced-expressions
            //      || curr().type() == lexeme::LeftBrace
            )
        {
            bool inside_initializer = (
                peek(-1) && peek(-1)->type() == lexeme::Assignment
            );
            auto open_paren = &curr();
            auto close = close_paren_type(open_paren->type());
            auto close_text = [&] () -> std::string { if (close == lexeme::RightParen) { return ")"; } return "}"; }();
            next();
            auto expr_list = expression_list(open_paren, lexeme::RightParen, inside_initializer);
            if (!expr_list) {
                error("unexpected text - ( is not followed by an expression-list");
                next();
                return {};
            }
            if (curr().type() != close_paren_type(open_paren->type())) {
                error("unexpected text - expression-list is not terminated by " + close_text);
                next();
                return {};
            }
            expr_list->close_paren = &curr();
            next();
            if (
                   curr().type() != lexeme::Semicolon
                && curr().type() != lexeme::RightParen
                && curr().type() != lexeme::RightBracket
                && curr().type() != lexeme::Greater
                && curr().type() != lexeme::Comma
            ) {
                expr_list->inside_initializer = false;
            }
            n->expression_list_is_fold_expression = expr_list->is_fold_expression();
            expr_list->default_initializer =
                is_inside_call_expr && std::empty(expr_list->expressions);
            n->expr = std::move(expr_list);
            return n;
        }

        if (auto decl = unnamed_declaration(curr().position(), false, true)) // captures are allowed
        {
            assert (
                !decl->has_name()
                && "ICE: declaration should have been unnamed"
            );

            if (auto obj = std::get_if<declaration_node::an_object>(&decl->type)) {
                if ((*obj)->is_wildcard()) {
                    error("an unnamed object at expression scope currently cannot have a deduced type (the reason to create an unnamed object is typically to create a temporary of a named type)");
                    next();
                    return {};
                }
            }
            else if (auto func = std::get_if<declaration_node::a_function>(&decl->type)) {
                if ((*func)->returns.index() == function_type_node::list) {
                    error("an unnamed function at expression scope currently cannot return multiple values");
                    next();
                    return {};
                }
                if ( // check if a single-expression function is followed by an extra second semicolon
                    decl->initializer && decl->initializer->is_expression()
                    && !done() && curr().type() == lexeme::Semicolon
                ) {
                    error("a single-expression function should end with a single semicolon");
                }
                if (!(*func)->contracts.empty()) {
                    error("an unnamed function at expression scope currently cannot have contracts");
                    next();
                    return {};
                }
            }
            else {
                error("(temporary alpha limitation) an unnamed declaration at expression scope must be a function or an object");
                next();
                return {};
            }

            if (
                peek(-1) && peek(-1)->type() != lexeme::RightBrace  // it is not a braced function expression
                && curr().type() != lexeme::LeftParen               // not imediatelly called
                && curr().type() != lexeme::RightParen              // not as a last argument to function
                && curr().type() != lexeme::Comma                   // not as first or in-the-middle, function argument
                && curr().type() != lexeme::Greater                 // not as the last argument to template
                && curr().type() != lexeme::RightBracket            // not as the last index argument
                && curr() != "is"                                   // not as the argument to is
                && curr() != "as"                                   // not as the argument to as
                && curr() != "do"                                   // not as `for`'s `next`.
            ) {
                // this is a fix for a short function syntax that should have double semicolon used
                // (check comment in expression_statement(bool semicolon_required))
                // We simulate double semicolon by moving back to single semicolon.
                next(-1);
            }

            n->expr = std::move(decl);
            return n;
        }

        return {};
    }


    //G postfix-expression:
    //G     primary-expression
    //G     postfix-expression postfix-operator
    //G     postfix-expression '[' expression-list? ','? ']'
    //G     postfix-expression '(' expression-list? ','? ')'
    //G     postfix-expression '.' id-expression
    //G     postfix-expression '..' id-expression
    //G
    auto postfix_expression()
        -> std::unique_ptr<postfix_expression_node>
    {
        auto n = std::make_unique<postfix_expression_node>();
        n->expr = primary_expression();
        if (!(n->expr)) {
            return {};
        }

        while (
            !done()
            && (
                is_postfix_operator(curr().type())
                || curr().type() == lexeme::LeftBracket
                || curr().type() == lexeme::LeftParen
                || curr().type() == lexeme::Dot
                || curr().type() == lexeme::DotDot
                )
            )
        {
            //  * and & can't be unary operators if followed by a (, identifier, or literal
            if (
                (
                    curr().type() == lexeme::Multiply
                    || curr().type() == lexeme::Ampersand
                    )
                && peek(1)
                && (
                    peek(1)->type() == lexeme::LeftParen
                    || peek(1)->type() == lexeme::Identifier
                    || is_literal(peek(1)->type())
                    )
                )
            {
                break;
            }

            if (curr().type() == lexeme::Dollar) {
                //  cap_grp must not already be set, or this is a multi-$ postfix-expression
                if (n->cap_grp) {
                    error("$ (capture) can appear at most once in a single postfix-expression");
                    return {};
                }
                if (current_capture_groups.empty()) {
                    error("$ (capture) cannot appear here - it must appear in an anonymous expression function, a postcondition, or an interpolated string literal");
                    return {};
                }
                n->cap_grp = current_capture_groups.back();
                n->cap_grp->add(n.get());
            }

            //  Remember current position, in case we need to backtrack
            auto term_pos = pos;

            auto term = postfix_expression_node::term{&curr()};
            next();

            if (term.op->type() == lexeme::LeftBracket)
            {
                term.expr_list = expression_list(term.op, lexeme::RightBracket);
                if (!term.expr_list)
                {
                    error("[ is not followed by a valid expression list");
                    return {};
                }
                if (curr().type() != lexeme::RightBracket)
                {
                    error("unexpected text - [ is not properly matched by ]", true, {}, true);
                    return {};
                }
                term.expr_list->close_paren = &curr();
                term.op_close = &curr();
                next();
            }
            else if (term.op->type() == lexeme::LeftParen)
            {
                //  Next should be an expression-list followed by a ')'
                //  If not, then this wasn't a call expression so backtrack to
                //  the '(' which will be part of the next grammar production
		        is_inside_call_expr = true;
                term.expr_list = expression_list(term.op, lexeme::RightParen);
		        is_inside_call_expr = false;

                if (
                    term.expr_list
                    && curr().type() == lexeme::RightParen
                )
                {
                    term.expr_list->close_paren = &curr();
                    term.op_close = &curr();
                    next();
                }
                else
                {
                    pos = term_pos;    // backtrack
                    break;
                }
            }
            else if (
                term.op->type() == lexeme::Dot
                || term.op->type() == lexeme::DotDot
                )
            {
                term.id_expr = id_expression();
                if (!term.id_expr) {
                    error("'.' must be followed by a valid member name");
                    return {};
                }
            }

            n->ops.push_back( std::move(term) );
        }

        if (auto tok = n->expr->get_token();
            tok
            && *tok == "this"
            && curr().type() == lexeme::Arrow
            )
        {
            auto next_word = std::string{};
            if (peek(1)) {
                next_word = peek(1)->to_string();
            }
            error("'this' is not a pointer - write 'this." + next_word + "' instead of 'this->" + next_word + "'");
            return {};
        }

        for (auto& e : expression_node::current_expressions) {
            e->num_subexpressions += unsafe_narrow<int>(std::ssize(n->ops));
        }

        return n;
    }


    //G prefix-expression:
    //G     postfix-expression
    //G     prefix-operator prefix-expression
    //GTODO     await-expression
    //GTODO     'sizeof' '(' type-id ')'
    //GTODO     'sizeof' '...' ( identifier ')'
    //GTODO     'alignof' '(' type-id ')'
    //GTODO     throws-expression
    //G
    auto prefix_expression()
        -> std::unique_ptr<prefix_expression_node>
    {
        auto n = std::make_unique<prefix_expression_node>();
        for ( ;
            is_prefix_operator(curr());
            next()
            )
        {
            n->ops.push_back(&curr());
        }
        if ((n->expr = postfix_expression())) {
            return n;
        }
        switch (curr().type())
        {
        break; case lexeme::PlusPlus:
            error("prefix '++var' is not valid Cpp2; use postfix 'var++' instead", false);
        break; case lexeme::MinusMinus:
            error("prefix '--var' is not valid Cpp2; use postfix 'var--' instead", false);
        break; case lexeme::Multiply:
            error("prefix '*ptr' dereference is not valid Cpp2; use postfix 'ptr*' instead", false);
        break; case lexeme::Ampersand:
            error("prefix '&var' address-of is not valid Cpp2; use postfix 'var&' instead", false);
        break; case lexeme::Tilde:
            error("prefix '~var' is not valid Cpp2; use postfix 'var~' instead", false);
        break; default: ;
        }
        return {};
    }


    //-----------------------------------------------------------------------
    //  Parsers for binary expressions
    //

    //  The general /*binary*/-expression:
    //     /*term*/-expression { { /* operators at this precedence level */ } /*term*/-expression }*
    //
    template<
        typename Binary,
        typename ValidateOp,
        typename TermFunc
    >
    auto binary_expression(
        ValidateOp validate_op,
        TermFunc   term
    )
        -> std::unique_ptr<Binary>
    {
        auto n = std::make_unique<Binary>();
        if ( (n->expr = term()) )
        {
            while (!done())
            {
                typename Binary::term t{};

                //  Remember current position, because we may need to backtrack if this next
                //  t.op might be valid but isn't followed by a valid term and so isn't for us
                auto term_pos = pos;

                //  Most of these predicates only look at the current token and return
                //  true/false == whether this is a valid operator for this production
                if constexpr( requires{ bool{ validate_op(curr()) }; } ) {
                    if (!validate_op(curr())) {
                        break;
                    }
                    t.op = &curr();
                    next();
                }

                //  But for shift-expression we may synthesize >> from > >
                //  which will return a token* == a valid operator for this production
                //  (possibly a synthesized new token) or nullptr otherwise
                else if constexpr( requires{ validate_op(curr(), *peek(1)); } ) {
                    if (
                        peek(1) == nullptr
                        || (t.op = validate_op(curr(), *peek(1))) == nullptr
                    )
                    {
                        break;
                    }
                    //  If we didn't consume the next token, we consumed the next two
                    if (t.op != &curr()) {
                        next();
                    }
                    next();
                }

                //  And it shouldn't be anything else
                else {
                    assert (!"ICE: validate_op should take one token and return bool, or two tokens and return token const* ");
                }

                //  At this point we may have a valid t.op, so try to parse the next term...
                //  If it's not a valid term, then this t.op wasn't for us, pop it and return
                //  what we found (e.g., with "requires expression = {...}" the = is a grammar
                //  element and not an operator, it isn't and can't be part of the expression)
                if ( !(t.expr = term()) ) {
                    pos = term_pos;    // backtrack
                    return n;
                }

                //  We got a term, so this op + term was for us
                n->terms.push_back( std::move(t) );
            }
            return n;
        }
        return {};
    }

    //G multiplicative-expression:
    //G     is-as-expression
    //G     multiplicative-expression '*' is-as-expression
    //G     multiplicative-expression '/' is-as-expression
    //G     multiplicative-expression '%' is-as-expression
    //G
    auto multiplicative_expression()
        -> auto
    {
        return binary_expression<multiplicative_expression_node> (
            [](token const& t){ return t.type() == lexeme::Multiply || t.type() == lexeme::Slash || t.type() == lexeme::Modulo; },
            [this]{ return is_as_expression(); }
            );
    }

    //G additive-expression:
    //G     multiplicative-expression
    //G     additive-expression '+' multiplicative-expression
    //G     additive-expression '-' multiplicative-expression
    //G
    auto additive_expression()
        -> auto
    {
        return binary_expression<additive_expression_node> (
            [](token const& t){ return t.type() == lexeme::Plus || t.type() == lexeme::Minus; },
            [this]{ return multiplicative_expression(); }
        );
    }

    //G shift-expression:
    //G     additive-expression
    //G     shift-expression '<<' additive-expression
    //G     shift-expression '>>' additive-expression
    //G
    auto shift_expression(bool allow_angle_operators = true)
        -> auto
    {
        if (allow_angle_operators) {
            return binary_expression<shift_expression_node> (
                [this](token const& t, token const& next) -> token const* {
                    if (t.type() == lexeme::LeftShift) {
                        return &t;
                    }
                    if (
                        t.type() == lexeme::Greater
                        && next.type() == lexeme::Greater
                        && t.position() == source_position{ next.position().lineno, next.position().colno-1 }
                        )
                    {
                        generated_tokens->emplace_back( ">>", t.position(), lexeme::RightShift);
                        return &generated_tokens->back();
                    }
                    return nullptr;
                },
                [this]{ return additive_expression(); }
            );
        }
        else {
            return binary_expression<shift_expression_node> (
                [](token const&, token const&) -> token const* { return nullptr; },
                [this]{ return additive_expression(); }
            );
        }
    }

    //G compare-expression:
    //G     shift-expression
    //G     compare-expression '<=>' shift-expression
    //G
    auto compare_expression(bool allow_angle_operators = true)
        -> auto
    {
        return binary_expression<compare_expression_node> (
            [](token const& t){ return t.type() == lexeme::Spaceship; },
            [=,this]{ return shift_expression(allow_angle_operators); }
        );
    }

    //G relational-expression:
    //G     compare-expression
    //G     relational-expression '<'  compare-expression
    //G     relational-expression '>'  compare-expression
    //G     relational-expression '<=' compare-expression
    //G     relational-expression '>=' compare-expression
    //G
    auto relational_expression(bool allow_angle_operators = true)
        -> auto
    {
        if (allow_angle_operators) {
            return binary_expression<relational_expression_node> (
                [](token const& t, token const& next) -> token const* {
                    if (
                        t.type() == lexeme::Less
                        || t.type() == lexeme::LessEq
                        || (t.type() == lexeme::Greater && next.type() != lexeme::GreaterEq)
                        || t.type() == lexeme::GreaterEq
                        ) {
                        return &t;
                    }
                    return nullptr;
                },
                [=,this]{ return compare_expression(allow_angle_operators); }
            );
        }
        else {
            return binary_expression<relational_expression_node> (
                [](token const&, token const&) -> token const* { return nullptr; },
                [=,this]{ return compare_expression(allow_angle_operators); }
            );
        }
    }

    //G equality-expression:
    //G     relational-expression
    //G     equality-expression '==' relational-expression
    //G     equality-expression '!=' relational-expression
    //G
    auto equality_expression(bool allow_angle_operators = true, bool allow_equality = true)
        -> auto
    {
        if (allow_equality) {
            return binary_expression<equality_expression_node> (
                [](token const& t){ return t.type() == lexeme::EqualComparison || t.type() == lexeme::NotEqualComparison; },
                [=,this]{ return relational_expression(allow_angle_operators); }
            );
        }
        else {
            return binary_expression<equality_expression_node> (
                [](token const& t){ return t.type() == lexeme::NotEqualComparison; },
                [=,this]{ return relational_expression(allow_angle_operators); }
            );
        }
    }

    //G bit-and-expression:
    //G     equality-expression
    //G     bit-and-expression '&' equality-expression
    //G
    auto bit_and_expression(bool allow_angle_operators = true, bool allow_equality = true)
        -> auto
    {
        return binary_expression<bit_and_expression_node> (
            [](token const& t){ return t.type() == lexeme::Ampersand; },
            [=,this]{ return equality_expression(allow_angle_operators, allow_equality); }
        );
    }

    //G bit-xor-expression:
    //G     bit-and-expression
    //G     bit-xor-expression '^' bit-and-expression
    //G
    auto bit_xor_expression(bool allow_angle_operators = true, bool allow_equality = true)
        -> auto
    {
        return binary_expression<bit_xor_expression_node> (
            [](token const& t){ return t.type() == lexeme::Caret; },
            [=,this]{ return bit_and_expression(allow_angle_operators, allow_equality); }
        );
    }

    //G bit-or-expression:
    //G     bit-xor-expression
    //G     bit-or-expression '|' bit-xor-expression
    //G
    auto bit_or_expression(bool allow_angle_operators = true, bool allow_equality = true)
        -> auto
    {
        return binary_expression<bit_or_expression_node> (
            [](token const& t){ return t.type() == lexeme::Pipe; },
            [=,this]{ return bit_xor_expression(allow_angle_operators, allow_equality); }
        );
    }

    //G logical-and-expression:
    //G     bit-or-expression
    //G     logical-and-expression '&&' bit-or-expression
    //G
    auto logical_and_expression(bool allow_angle_operators = true, bool allow_equality = true)
        -> auto
    {
        return binary_expression<logical_and_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalAnd; },
            [=,this]{ return bit_or_expression(allow_angle_operators, allow_equality); }
        );
    }

    //  constant-expression:    // don't need intermediate production, just use:
    //  conditional-expression: // don't need intermediate production, just use:
    //G logical-or-expression:
    //G     logical-and-expression
    //G     logical-or-expression '||' logical-and-expression
    //G
    auto logical_or_expression(bool allow_angle_operators = true, bool allow_equality = true)
        -> auto
    {
        return binary_expression<logical_or_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalOr; },
            [=,this]{ return logical_and_expression(allow_angle_operators, allow_equality); }
        );
    }

    //G assignment-expression:
    //G     logical-or-expression
    //G     assignment-expression assignment-operator logical-or-expression
    //G
    auto assignment_expression(
        bool allow_angle_operators = true
    )
        -> std::unique_ptr<assignment_expression_node>
    {
        auto ret = std::unique_ptr<assignment_expression_node>{};

        if (allow_angle_operators)
        {
            ret = binary_expression<assignment_expression_node> (
                [this](token const& t, token const& next) -> token const* {
                    if (is_assignment_operator(t.type())) {
                        return &t;
                    }
                    if (
                        t.type() == lexeme::Greater
                        && next.type() == lexeme::GreaterEq
                        && t.position() == source_position{ next.position().lineno, next.position().colno-1 }
                        )
                    {
                        generated_tokens->emplace_back( ">>=", t.position(), lexeme::RightShiftEq);
                        return &generated_tokens->back();
                    }
                    return nullptr;
                },
                [=,this]{
                    return logical_or_expression(allow_angle_operators);
                }
            );
        }
        else
        {
            ret = binary_expression<assignment_expression_node> (
                [](token const&, token const&) -> token const* { return nullptr; },
                [=,this]{
                    return logical_or_expression(allow_angle_operators);
                }
            );
        }

        if (ret && ret->terms_size() > 1) {
            error("assignment cannot be chained - instead of 'c = b = a;', write 'b = a; c = b;'", false);
            return {};
        }

        return ret;
    }

    //G expression:               // eliminated 'condition:' - just use 'expression:'
    //G     assignment-expression
    //GTODO    try expression
    //G
    auto expression(
        bool allow_angle_operators = true,
        bool check_arrow           = true
    )
        -> std::unique_ptr<expression_node>
    {
        auto n = std::make_unique<expression_node>();

        {
        expression_node::current_expressions.push_back(n.get());
        auto guard = finally([&]{ expression_node::current_expressions.pop_back(); });

        if (!(n->expr = assignment_expression(allow_angle_operators))) {
            return {};
        }

        if (
            check_arrow
            && !done()
            && curr().type() == lexeme::Arrow
            )
        {
            error("'->' is not Cpp2 deference syntax - write '*.' instead");
            return {};
        }
        }

        for (auto& e : expression_node::current_expressions) {
            ++e->num_subexpressions;
        }
        return n;
    }

    //G expression-list:
    //G     parameter-direction? expression
    //G     expression-list ',' parameter-direction? expression
    //G
    auto expression_list(
        token const* open_paren,
        lexeme       closer,
        bool         inside_initializer = false
    )
        -> std::unique_ptr<expression_list_node>
    {
        auto pass = passing_style::in;
        auto n = std::make_unique<expression_list_node>();
        n->open_paren = open_paren;
        n->inside_initializer = inside_initializer;

        if (auto dir = to_passing_style(curr());
            (
                dir == passing_style::out
                || dir == passing_style::move
                || dir == passing_style::forward
                )
            && peek(1)
            && peek(1)->type() == lexeme::Identifier
            )
        {
            pass = dir;
            next();
        }
        auto x = expression();

        //  If this is an empty expression_list, we're done
        if (!x) {
            return n;
        }

        //  Otherwise remember the first expression
        n->expressions.push_back( { pass, std::move(x) } );
        //  and see if there are more...
        while (curr().type() == lexeme::Comma) {
            next();

            //  Allow a trailing comma in the list
            if (curr().type() == closer) {
                break;
            }

            pass = passing_style::in;
            if (auto dir = to_passing_style(curr());
                dir == passing_style::out
                || dir == passing_style::move
                || dir == passing_style::forward
                )
            {
                pass = dir;
                next();
            }
            auto expr = expression();
            if (!expr) {
                error("invalid text in expression list", true, {}, true);
                return {};
            }
            n->expressions.push_back( { pass, std::move(expr) } );
        }

        return n;
    }


    //G type-id:
    //G     type-qualifier-seq? qualified-id
    //G     type-qualifier-seq? unqualified-id
    //G
    //G type-qualifier-seq:
    //G     type-qualifier
    //G     type-qualifier-seq type-qualifier
    //G
    //G type-qualifier:
    //G     'const'
    //G     '*'
    //G
    auto type_id()
        -> std::unique_ptr<type_id_node>
    {
        auto n = std::make_unique<type_id_node>();

        while (
            (curr().type() == lexeme::Keyword && curr() == "const")
            || curr().type() == lexeme::Multiply
            )
        {
            if (
                curr() == "const"
                && !n->pc_qualifiers.empty()
                && *n->pc_qualifiers.back() == "const"
                )
            {
                error("consecutive 'const' not allowed");
                return {};
            }
            n->pc_qualifiers.push_back( &curr() );
            next();
        }

        if (auto id = qualified_id()) {
            n->pos = id->position();
            n->id  = std::move(id);
            assert (n->id.index() == type_id_node::qualified);
        }
        else if (auto id = unqualified_id()) {
            n->pos = id->position();
            n->id  = std::move(id);
            assert (n->id.index() == type_id_node::unqualified);
        }
        else {
            return {};
        }
        if (curr().type() == lexeme::Multiply) {
            error("'T*' is not a valid Cpp2 type; use '*T' for a pointer instead", false);
            return {};
        }

        return n;
    }


    //G is-as-expression:
    //G     prefix-expression
    //G     is-as-expression is-type-constraint
    //G     is-as-expression is-value-constraint
    //G     is-as-expression as-type-cast
    //GTODO     type-id is-type-constraint
    //G
    //G is-type-constraint:
    //G     'is' type-id
    //G
    //G is-value-constraint:
    //G     'is' expression
    //G
    //G as-type-cast:
    //G     'as' type-id
    //G
    auto is_as_expression()
        -> std::unique_ptr<is_as_expression_node>
    {
        auto n = std::make_unique<is_as_expression_node>();
        n->expr = prefix_expression();
        if (!(n->expr)) {
            return {};
        }

        auto is_found = false;
        auto as_found = false;

        while (
            !done()
            && (curr() == "is" || curr() == "as")
            )
        {
            if (curr() == "is") {
                if (is_found) {
                    error("repeated 'is' are not allowed");
                    return {};
                }
                is_found = true;
            }
            else {
                as_found = true;
            }

            if (is_found && as_found) {
                error("mixed 'is' and 'as' are not allowed");
                return {};
            }

            auto term = is_as_expression_node::term{};
            term.op = &curr();
            next();

            if ((term.type = type_id()) != nullptr) {
                ;
            }
            else if ((term.expr = expression()) != nullptr) {
                ;
            }

            if (
                *term.op == "as"
                && term.expr
                )
            {
                error("'as' must be followed by a type-id, not an expression", false);
                return {};
            }
            if (
                !term.type
                && !term.expr
                )
            {
                if (*term.op == "is") {
                    error( "'is' must be followed by a type-id or an expression", false);
                }
                else {
                    error( "'as' must be followed by a type-id", false);
                }
                return {};
            }

            n->ops.push_back( std::move(term) );
        }

        return n;
    }


    //G unqualified-id:
    //G     identifier
    //G     keyword
    //G     template-id
    //GTODO     operator-function-id
    //G     ...
    //G
    //G template-id:
    //G     identifier '<' template-arguments? '>'
    //G
    //G template-arguments:
    //G     template-arguments ',' template-argument
    //G
    //G template-argument:
    //G     # note: < > << >> are not allowed in expressions until new ( is opened
    //G     'const' type-id
    //G     expression
    //G     type-id
    //G
    auto unqualified_id()
        -> std::unique_ptr<unqualified_id_node>
    {
        //  Handle the identifier
        if (
            curr().type() != lexeme::Identifier
            && curr().type() != lexeme::Keyword
            && curr().type() != lexeme::Cpp2FixedType
            && curr().type() != lexeme::Ellipsis
            )
        {
            return {};
        }

        auto n = std::make_unique<unqualified_id_node>();

        n->identifier = &curr();
        auto one_past_identifier_end_pos = curr().position();
        one_past_identifier_end_pos.colno += curr().length();
        next();

        //  Handle the template-arguments if there is one
        if (
            curr().type() == lexeme::Less
            && curr().position() == one_past_identifier_end_pos
            )
        {
            //  Remember current position, in case this < is isn't a template argument list
            auto start_pos = pos;

            n->open_angle = curr().position();
            next();

            auto term = template_argument{};

            do {
                //  If it doesn't start with * or const (which can only be a type id),
                //  try parsing it as an expression
                if (auto e = [&]{
                        if (
                            curr().type() == lexeme::Multiply // '*'
                            || curr() == "const"              // 'const'
                        )
                        {
                            return decltype(expression()){};
                        }
                        return expression(false);   // false == disallow unparenthesized relational comparisons in template args
                    }()
                )
                {
                    term.arg = std::move(e);
                }

                //  Else try parsing it as a type id
                else if (auto i = type_id()) {
                    term.arg = std::move(i);
                }

                //  Else if we already got at least one template-argument, this is a
                //  ',' followed by something that isn't a valid template-arg
                else if (std::ssize(n->template_args) > 0) {
                    error( "expected a template argument after ','", false);
                    return {};
                }

                //  Else this is an empty '<>' list which is okay
                else {
                    break;
                }

                n->template_args.push_back( std::move(term) );
            }
            //  Use the lambda trick to jam in a "next" clause
            while (
                curr().type() == lexeme::Comma
                && [&]{term.comma = curr().position(); next(); return true;}()
            );
                //  When this is rewritten in Cpp2, it will be:
                //      while curr().type() == lexeme::Comma
                //      next  term.comma = curr().position();

            if (curr().type() != lexeme::Greater) {
                //  Aha, this wasn't a template argument list after all,
                //  so back out just that part and return the identifier
                n->open_angle = source_position{};
                n->template_args.clear();
                pos = start_pos;
                return n;
            }
            n->close_angle = curr().position();
            next();
        }

        else {
             if (*n->identifier == "co_await" || *n->identifier == "co_yield") {
                error( "(temporary alpha limitation) coroutines are not yet supported in Cpp2", false);
                return {};
            }
        }

        return n;
    }


    //G qualified-id:
    //G     nested-name-specifier unqualified-id
    //G     member-name-specifier unqualified-id
    //G
    //G nested-name-specifier:
    //G     '::'
    //G     unqualified-id '::'
    //G
    //G member-name-specifier:
    //G     unqualified-id '.'
    //G
    auto qualified_id()
        -> std::unique_ptr<qualified_id_node>
    {
        auto n = std::make_unique<qualified_id_node>();

        auto term = qualified_id_node::term{nullptr};

        //  Handle initial :: if present, else the first scope_op will be null
        if (curr().type() == lexeme::Scope) {
            term.scope_op = &curr();
            next();
        }

        //  Remember current position, because we need to look ahead to the next ::
        auto start_pos = pos;

        //  If we don't get a first id, or if we didn't have a leading :: and
        //  the next thing isn't :: or ., back out and report unsuccessful
        term.id = unqualified_id();
        if (
            !term.id
            || (!term.scope_op && curr().type() != lexeme::Scope)
            )
        {
            pos = start_pos;    // backtrack
            return {};
        }

        //  Reject "std" :: "move" / "forward"
        assert (term.id->identifier);
        auto first_uid_was_std = (*term.id->identifier == "std");
        auto first_time_through_loop = true;

        n->ids.push_back( std::move(term) );

        while (curr().type() == lexeme::Scope)
        {
            auto term = qualified_id_node::term{ &curr() };
            next();
            term.id = unqualified_id();
            if (!term.id) {
                error("invalid text in qualified name", true, {}, true);
                return {};
            }
            assert (term.id->identifier);
            if (
                first_time_through_loop
                && first_uid_was_std
                && term.scope_op->type() == lexeme::Scope
                )
            {
                if (*term.id->identifier == "move") {
                    error("std::move is not needed in Cpp2 - use 'move' parameters/arguments instead", false);
                    return {};
                }
                else if (*term.id->identifier == "forward") {
                    error("std::forward is not needed in Cpp2 - use 'forward' parameters/arguments instead", false);
                    return {};
                }
                first_time_through_loop = false;
            }
            n->ids.push_back( std::move(term) );
        }

        return n;
    }


    //G id-expression:
    //G     qualified-id
    //G     unqualified-id
    //G
    auto id_expression()
        -> std::unique_ptr<id_expression_node>
    {
        auto n = std::make_unique<id_expression_node>();
        if (auto id = qualified_id()) {
            n->pos = id->position();
            n->id  = std::move(id);
            assert (n->id.index() == id_expression_node::qualified);
            return n;
        }
        if (auto id = unqualified_id()) {
            n->pos = id->position();
            n->id  = std::move(id);
            assert (n->id.index() == id_expression_node::unqualified);
            return n;
        }
        return {};
    }

    //G literal:
    //G     integer-literal ud-suffix?
    //G     character-literal ud-suffix?
    //G     floating-point-literal ud-suffix?
    //G     string-literal ud-suffix?
    //G     boolean-literal ud-suffix?
    //G     pointer-literal ud-suffix?
    //G     user-defined-literal ud-suffix?
    //G
    auto literal()
        -> std::unique_ptr<literal_node>
    {
        if (is_literal(curr().type())) {
            auto n = std::make_unique<literal_node>();
            n->pieces.push_back( &curr() );
            next();
            if (curr().type() == lexeme::UserDefinedLiteralSuffix) {
                n->pieces.push_back(&curr());
                next();
            }

            //  String literals can have multiple chunks, such as "xyzzy" "plugh"
            //  (in Cpp1 these are merged in the preprocessor, in Cpp2 they're in the grammar)
            if (n->pieces.front()->type() == lexeme::StringLiteral) {
                while (curr().type() == lexeme::StringLiteral) {
                    n->pieces.push_back(&curr());
                    next();
                    if (curr().type() == lexeme::UserDefinedLiteralSuffix) {
                        n->pieces.push_back(&curr());
                        next();
                    }
                }
            }

            return n;
        }
        return {};
    }

    //G expression-statement:
    //G     expression ';'
    //G     expression
    //G
    auto expression_statement(
        bool semicolon_required
    )
        -> std::unique_ptr<expression_statement_node>
    {
        auto n = std::make_unique<expression_statement_node>();

        expression_statement_node::current_expression_statements.push_back(n.get());
        auto guard = finally([&]{ expression_statement_node::current_expression_statements.pop_back(); });

        if (!(n->expr = expression(true, true))) {
            return {};
        }

        if (
            semicolon_required
            && (done() || curr().type() != lexeme::Semicolon)
            && peek(-1)->type() != lexeme::Semicolon
                //  this last peek(-1)-condition is a hack (? or is it just
                //  maybe elegant? I'm torn) so that code like
                //
                //      callback := :(inout x:_) = x += "suffix"; ;
                //
                //  doesn't need the redundant semicolon at the end of a decl...
                //  there's probably a cleaner way to do it, but this works and
                //  it doesn't destabilize any regression tests
            )
        {
            return {};
        }
        if (
            !done()
            && curr().type() == lexeme::Semicolon
            )
        {
            n->has_semicolon = true;
            next();
        }
        return n;
    }


    //G selection-statement:
    //G     'if' 'constexpr'? logical-or-expression compound-statement
    //G     'if' 'constexpr'? logical-or-expression compound-statement 'else' compound-statement
    //G
    auto selection_statement()
        -> std::unique_ptr<selection_statement_node>
    {
        if (
            curr().type() != lexeme::Keyword
            || curr() != "if"
            )
        {
            return {};
        }
        auto n = std::make_unique<selection_statement_node>();
        n->identifier = &curr();
        next();

        if (
            curr().type() == lexeme::Keyword
            && curr() == "constexpr"
            )
        {
            n->is_constexpr = true;
            next();
        }

        if (auto e = logical_or_expression()) {
            n->expression = std::move(e);
        }
        else {
            error("invalid if condition", true, {}, true);
            return {};
        }

        if (curr().type() != lexeme::LeftBrace) {
            error("an if branch body must be enclosed with { }");
            return {};
        }

        if (auto s = compound_statement()) {
            n->true_branch = std::move(s);
        }
        else {
            error("invalid if branch body", true, {}, true);
            return {};
        }

        if (
            curr().type() != lexeme::Keyword
            || curr() != "else"
            )
        {
            //  Add empty else branch to simplify processing elsewhere
            //  Note: Position (0,0) signifies it's implicit (no source location)
            n->false_branch =
                std::make_unique<compound_statement_node>( source_position(0,0) );
        }
        else {
            n->else_pos = curr().position();
            next();

            if (
                curr().type() != lexeme::LeftBrace
                && curr() != "if"
                )
            {
                error("an else branch body must be enclosed with { }");
                return {};
            }

            if (auto s = compound_statement( source_position{}, true )) {
                n->false_branch = std::move(s);
                n->has_source_false_branch = true;
            }
            else {
                error("invalid else branch body", true, {}, true);
                return {};
            }
        }

        return n;
    }


    //G return-statement:
    //G     return expression? ';'
    //G
    auto return_statement()
        -> std::unique_ptr<return_statement_node>
    {
        if (
            curr().type() != lexeme::Keyword
            || curr() != "return"
            )
        {
            return {};
        }

        auto n = std::make_unique<return_statement_node>();
        n->identifier = &curr();
        next();

        //  If there's no optional return expression, we're done
        if (curr().type() == lexeme::Semicolon) {
            next();
            return n;
        }

        //  Handle the return expression
        auto x = expression();
        if (!x) {
            error("invalid return expression", true, {}, true);
            return {};
        }
        n->expression = std::move(x);

        //  Final semicolon
        if (curr().type() != lexeme::Semicolon) {
            error("missing ; after return");
            next();
            return {};
        }

        next();
        return n;
    }


    //G iteration-statement:
    //G     label? 'while' logical-or-expression next-clause? compound-statement
    //G     label? 'do' compound-statement next-clause? 'while' logical-or-expression ';'
    //G     label? 'for' expression next-clause? 'do' unnamed-declaration
    //G
    //G label:
    //G     identifier ':'
    //G
    //G next-clause:
    //G     'next' assignment-expression
    //G
    auto iteration_statement()
        -> std::unique_ptr<iteration_statement_node>
    {
        auto n = std::make_unique<iteration_statement_node>();

        //  If the next three tokens are:
        //      identifier ':' 'for/while/do'
        //  then it's a labeled iteration statement
        if (
            curr().type() == lexeme::Identifier
            && peek(1)
            && peek(1)->type() == lexeme::Colon
            && peek(2)
            && peek(2)->type() == lexeme::Keyword
            && (*peek(2) == "while" || *peek(2) == "do" || *peek(2) == "for")
            )
        {
            n->label = &curr();
            next();
            next();
        }

        if (
            curr().type() != lexeme::Keyword
            || (curr() != "while" && curr() != "do" && curr() != "for")
            )
        {
            return {};
        }

        n->identifier = &curr();
        next();

        //-----------------------------------------------------------------
        //  We'll do these same things in different orders,
        //  so extract them into local functions...
        auto handle_optional_next_clause = [&]() -> bool {
            if (curr() != "next") {
                return true; // absent next clause is okay
            }
            next(); // don't bother remembering "next" token, shouldn't need its position info
            auto next = assignment_expression();
            if (!next) {
                error("invalid expression after 'next'", true, {}, true);
                return false;
            }
            n->next_expression = std::move(next);
            return true;
        };

        auto handle_logical_expression = [&]() -> bool {
            auto x = logical_or_expression();
            if (!x) {
                error("a loop must have a valid conditional expression");
                return false;
            }
            n->condition = std::move(x);
            return true;
        };

        auto handle_compound_statement = [&]() -> bool {
            auto s = compound_statement();
            if (!s) {
                error("invalid while loop body", true, {}, true);
                return false;
            }
            n->statements = std::move(s);
            return true;
        };
        //-----------------------------------------------------------------

        //  Handle "while"
        //
        if (*n->identifier == "while")
        {
            if (!handle_logical_expression  ()) { return {}; }
            if (!handle_optional_next_clause()) { return {}; }
            if (!handle_compound_statement  ()) { return {}; }
            if (!done() && curr().type() == lexeme::Semicolon) {
                error("a loop body may not be followed by a semicolon (empty statements are not allowed)");
                return {};
            }
            return n;
        }

        //  Handle "do"
        //
        else if (*n->identifier == "do")
        {
            if (!handle_compound_statement  ()) { return {}; }
            if (!handle_optional_next_clause()) { return {}; }
            if (curr() != "while") {
                error("do loop body must be followed by 'while'");
                return {};
            }
            next();
            if (!handle_logical_expression  ()) { return {}; }
            if (curr().type() != lexeme::Semicolon) {
                error("missing ; after do..while loop condition");
                next();
                return {};
            }
            next();
            return n;
        }

        //  Handle "for"
        //
        else if (*n->identifier == "for")
        {
            n->range = expression();
            if (!n->range) {
                error("expected valid range expression after 'for'", true, {}, true);
                return {};
            }

            if (!handle_optional_next_clause()) { return {}; }

            if (
                curr() != "do"
                || !peek(1)
                || peek(1)->type() != lexeme::LeftParen
                )
            {
                next();
                if (curr().type() == lexeme::Colon) {
                    error("alpha design change note: 'for range' syntax has changed - please remove ':' and '=', for example: for args do (arg) std::cout << arg;");
                }
                else {
                    error("'for range' must be followed by 'do ( parameter )'");
                }
                return {};
            }
            next(2);    // eat 'do' and '('

            n->parameter = parameter_declaration(false, false, false);
            if (!n->parameter) {
                error("'for range do (' must be followed by a parameter declaration", false, source_position{}, true);
                return {};
            }

            if (curr().type() != lexeme::RightParen) {
                error("expected ')' after 'for' parameter");
                return {};
            }
            next();     // eat ')'

            n->body = statement();
            if (!n->body) {
                error("invalid for..do loop body", false, source_position{}, true);
                return {};
            }
            //  else
            if (n->parameter->pass == passing_style::in) {
                n->for_with_in = true;
            }

            if (!done() && curr().type() == lexeme::Semicolon) {
                error("a loop body may not be followed by a semicolon (empty statements are not allowed)");
                return {};
            }

            return n;
        }

        assert(!"compiler bug: unexpected case");
        return {};
    }


    //G alternative:
    //G     alt-name? is-type-constraint '=' statement
    //G     alt-name? is-value-constraint '=' statement
    //G     alt-name? as-type-cast '=' statement
    //G
    //GTODO alt-name:
    //G     unqualified-id ':'
    //G
    auto alternative()
        -> std::unique_ptr<alternative_node>
    {
        auto n = std::make_unique<alternative_node>();

        if (
            curr().type() == lexeme::Identifier
            && peek(1)
            && peek(1)->type() == lexeme::Colon
            )
        {
            error("(temporary alpha limitation) declaring an identifier is not supported yet");
            return {};
        }

        //  Now we should be as "is" or "as"
        //  (initial partial implementation, just "is/as id-expression")
        if (
            curr() != "is"
            && curr() != "as"
            )
        {
            return {};
        }

        n->is_as_keyword = &curr();
        next();

        if (auto id = type_id()) {
            n->type_id = std::move(id);
        }
        else if (auto e = postfix_expression()) {
            n->value = std::move(e);
        }
        else {
            error("expected type-id or value after 'is' in inspect alternative", true, {}, true);
            return {};
        }

        if (curr().type() != lexeme::Assignment) {
            error("expected = at start of inspect alternative body", true, {}, true);
            return {};
        }
        n->equal_sign = curr().position();
        next();

        if (auto s = statement(true, n->equal_sign)) {
            n->statement = std::move(s);
        }
        else {
            error("expected statement after = in inspect alternative", true, {}, true);
            return {};
        }

        return n;
    }


    //G inspect-expression:
    //G     'inspect' 'constexpr'? expression '{' alternative-seq? '}'
    //G     'inspect' 'constexpr'? expression '->' type-id '{' alternative-seq? '}'
    //G
    //G alternative-seq:
    //G     alternative
    //G     alternative-seq alternative
    //G
    auto inspect_expression(bool is_expression)
        -> std::unique_ptr<inspect_expression_node>
    {
        if (curr() != "inspect") {
            return {};
        }

        if (!is_expression) {
            errors.emplace_back(
                curr().position(),
                "(temporary alpha limitation) cppfront is still learning 'inspect' - only inspect expressions are currently supported"
            );
            return {};
        }

        auto n = std::make_unique<inspect_expression_node>();
        n->identifier = &curr();
        next();

        if (curr() == "constexpr") {
            n->is_constexpr = true;
            next();
        }

        if (auto e = expression(true, false)) {
            n->expression = std::move(e);
        }
        else {
            error("invalid inspect expression", true, {}, true);
            return {};
        }

        //  Handle the optional explicit return type
        if (curr().type() == lexeme::Arrow)
        {
            if (!is_expression) {
                error("an inspect statement cannot have an explicit return type (whereas an inspect expression must have one)");
                return {};
            }
            next();
            if (curr().type() == lexeme::LeftParen) {
                error("multiple/named returns are not currently allowed for inspect");
                return {};
            }

            auto type = type_id();
            if (!type) {
                error("expected a valid inspect return type after ->");
                return {};
            }
            n->result_type = std::move(type);
        }
        else if (is_expression) {
            error("an inspect expression must have an explicit '-> result_type'");
            return {};
        }

        //  Now do the inspect body
        if (curr().type() != lexeme::LeftBrace) {
            error("expected { at start of inspect body");
            return {};
        }
        n->open_brace = curr().position();
        next();

        while (curr().type() != lexeme::RightBrace)
        {
            auto a = alternative();
            if (!a) {
                error("invalid alternative in inspect", true, {}, true);
                return {};
            }
            if (
                is_expression
                && !a->statement->is_expression()
                )
            {
                error("an inspect expression alternative must be just an expression "
                    "(not a braced block) that will be used as the value of the inspect expression");
                return {};
            }
            n->alternatives.push_back( std::move(a) );
        }

        n->close_brace = curr().position();
        next();

        if (n->alternatives.empty()) {
            error("inspect body cannot be empty - add at least one alternative");
            return {};
        }

        return n;
    }


    //G jump-statement:
    //G     'break' identifier? ';'
    //G     'continue' identifier? ';'
    //G
    auto jump_statement()
        -> std::unique_ptr<jump_statement_node>
    {
        auto n = std::make_unique<jump_statement_node>();

        if (
            curr() != "break"
            && curr() != "continue"
            )
        {
            return {};
        }

        n->keyword = &curr();
        next();

        if (curr().type() == lexeme::Identifier) {
            n->label = &curr();
            next();
        }

        if (curr().type() != lexeme::Semicolon) {
            error("expected ';' at end of '" + n->keyword->to_string() + "' statement");
            return {};
        }
        next();

        return n;
    }


    //G using-statement:
    //G     'using' qualified-id ';'
    //G     'using' 'namespace' id-expression ';'
    //G
    auto using_statement()
        -> std::unique_ptr<using_statement_node>
    {
        auto n = std::make_unique<using_statement_node>();

        if (curr() != "using") {
            return {};
        }
        n->keyword = &curr();
        next();

        if (curr() == "namespace") {
            n->for_namespace = true;
            next();
        }

        auto id = id_expression();
        if (!id) {
            error(std::string{"expected valid id-expression after 'using"} + (n->for_namespace ? " namespace" : "") + "'");
            return {};
        }
        if (!n->for_namespace && !id->is_qualified()) {
            error("'using' for a specific name (not 'using namespace') must specify a qualified name", false);
            return {};
        }

        n->id = std::move(id);

        if (curr().type() != lexeme::Semicolon) {
            error("expected ; at end of using-statement");
            return {};
        }
        next();

        return n;
    }


    //G statement:
    //G     selection-statement
    //G     using-statement
    //G     inspect-expression
    //G     return-statement
    //G     jump-statement
    //G     iteration-statement
    //G     compound-statement
    //G     contract-statement
    //G     declaration
    //G     expression-statement
    //G
    //G contract-statement:
    //G     contract ';'
    //
    //GTODO     try-block
    //G
    auto statement(
        bool                     semicolon_required = true,
        source_position          equal_sign         = source_position{},
        bool                     parameters_allowed = false,
        compound_statement_node* compound_parent    = nullptr
    )
        -> std::unique_ptr<statement_node>
    {
        if (!done() && curr().type() == lexeme::Semicolon) {
            error("empty statement is not allowed - remove extra semicolon");
            return {};
        }

        auto n = std::make_unique<statement_node>(compound_parent);

        //  If a parameter list is allowed here, try to parse one
        if (parameters_allowed) {
            n->parameters = parameter_declaration_list(false, true, false, true);
            if (n->parameters) {
                for (auto& param : n->parameters->parameters) {
                    if (
                        param->direction() != passing_style::in
                        && param->direction() != passing_style::inout
                        && param->direction() != passing_style::copy
                        )
                    {
                        error("(temporary alpha limitation) parameters scoped to a block/statement must be 'in' (the default), 'copy', or 'inout'", false);
                        return {};
                    }
                }
            }
        }

        //  Now handle the rest of the statement

        if (auto s = selection_statement()) {
            n->statement = std::move(s);
            assert (n->is_selection());
            return n;
        }

        else if (auto s = using_statement()) {
            n->statement = std::move(s);
            assert (n->is_using());
            return n;
        }

        else if (auto i = inspect_expression(false)) {
            n->statement = std::move(i);
            assert (n->is_inspect());
            return n;
        }

        else if (auto s = return_statement()) {
            n->statement = std::move(s);
            assert (n->is_return());
            return n;
        }

        else if (auto s = jump_statement()) {
            n->statement = std::move(s);
            assert (n->is_jump());
            return n;
        }

        else if (auto s = iteration_statement()) {
            n->statement = std::move(s);
            assert (n->is_iteration());
            return n;
        }

        else if (auto s = compound_statement(equal_sign)) {
            n->statement = std::move(s);
            assert (n->is_compound());
            return n;
        }

        else if (auto s = contract()) {
            if (*s->kind != "assert") {
                error("only 'assert' contracts are allowed at statement scope");
                return {};
            }
            if (curr().type() != lexeme::Semicolon) {
                error("missing ';' after contract-statement");
                return {};
            }
            next();
            n->statement = std::move(s);
            assert (n->is_contract());
            return n;
        }

        else if (auto s = declaration(true, false, false, n.get())) {
            n->statement = std::move(s);
            assert (n->is_declaration());
            return n;
        }

        else if (auto s = expression_statement(semicolon_required)) {
            n->statement = std::move(s);
            assert (n->is_expression());
            return n;
        }

        else {
            return {};
        }
    }


    //G compound-statement:
    //G     '{' statement-seq? '}'
    //G
    //G statement-seq:
    //G     statement
    //G     statement-seq statement
    //G
    auto compound_statement(
        source_position equal_sign                      = source_position{},
        bool            allow_single_unbraced_statement = false
    )
        -> std::unique_ptr<compound_statement_node>
    {
        bool is_braced = curr().type() == lexeme::LeftBrace;
        if (
            !is_braced
            && !allow_single_unbraced_statement
            )
        {
            return {};
        }

        auto n = std::make_unique<compound_statement_node>();
        if (!is_braced) {
            n->body_indent = curr().position().colno-1;
        }
        else if (peek(1)) {
            n->body_indent = peek(1)->position().colno-1;
        }

        //  Remember current position, in case this isn't a valid statement
        auto start_pos = pos;

        //  In the case where this is a declaration initializer with
        //      = {
        //  on the same line, we want to remember our start position
        //  as where the = was, not where the { was
        if (equal_sign.lineno == curr().position().lineno) {
            n->open_brace = equal_sign;
        }
        else {
            n->open_brace = curr().position();
        }

        if (is_braced) {
            next();
        }

        while (
            curr().type() != lexeme::RightBrace
            && (
                is_braced
                || std::ssize(n->statements) < 1
                )
            )
        {
            //  Only inside a compound-statement, a
            //  contained statement() may have parameters
            auto s = statement(true, source_position{}, true, n.get());
            if (!s) {

                // Only add error when no specific one already exist
                if(!has_error()) {
                    error("invalid statement encountered inside a compound-statement", true);
                }
                pos = start_pos;    // backtrack
                return {};
            }
            n->statements.push_back( std::move(s) );
        }

        if (is_braced) {
            assert(curr().type() == lexeme::RightBrace);
            n->close_brace = curr().position();
            next();
        }
        return n;
    }


    //G parameter-declaration:
    //G     this-specifier? parameter-direction? declaration
    //G
    //G parameter-direction: one of
    //G     'in' 'copy' 'inout' 'out' 'move' 'forward'
    //G
    //G this-specifier:
    //G     'implicit'
    //G     'virtual'
    //G     'override'
    //G     'final'
    //G
    auto parameter_declaration(
        bool is_returns   = false,
        bool is_named     = true,
        bool is_template  = true,
        bool is_statement = false
    )
        -> std::unique_ptr<parameter_declaration_node>
    {
        //  Remember current position, because we may need to backtrack if this is just
        //  a parenthesized expression statement, not a statement parameter list
        auto start_pos = pos;

        auto n = std::make_unique<parameter_declaration_node>();
        n->pass =
            is_returns ? passing_style::out  :
            passing_style::in;
        n->pos  = curr().position();

        //  Handle optional this-specifier
        //
        if (curr() == "implicit") {
            n->mod = parameter_declaration_node::modifier::implicit;
            next();
        }
        else if (curr() == "virtual") {
            n->mod = parameter_declaration_node::modifier::virtual_;
            next();
        }
        else if (curr() == "override") {
            n->mod = parameter_declaration_node::modifier::override_;
            next();
        }
        else if (curr() == "final") {
            n->mod = parameter_declaration_node::modifier::final_;
            next();
        }

        //  Handle optional parameter-direction
        //
        if (auto dir = to_passing_style(curr());
            dir != passing_style::invalid
            )
        {
            if (is_template) {
                error("a template parameter cannot have a passing style (it is always implicitly 'in')");
                return {};
            }

            if (is_returns)
            {
                if (dir == passing_style::in) {
                    error("a return value cannot be 'in'");
                    return {};
                }
                if (dir == passing_style::copy) {
                    error("a return value cannot be 'copy'");
                    return {};
                }
                if (dir == passing_style::inout) {
                    error("a return value cannot be 'inout'");
                    return {};
                }
                if (dir == passing_style::move) {
                    error("a return value cannot be 'move' (it is implicitly 'move'-out)");
                    return {};
                }
            }
            if (
                !is_named
                && dir == passing_style::out
                )
            {
                error("(temporary alpha limitation) an unnamed function cannot have an 'out' parameter");
                return {};
            }
            n->pass = dir;
            next();
        }

        //  Now the main declaration
        //
        if (!(n->declaration = declaration(false, true, is_template, {}, false))) {
            pos = start_pos;    // backtrack
            return {};
        }

        //  And some error checks
        //
        if (
            n->mod != parameter_declaration_node::modifier::none
            && !n->declaration->has_name("this")
            )
        {
            error( "only a 'this' parameter may be declared implicit, virtual, override, or final", false );
        }

        if (
            n->declaration->has_name("this")
            && n->pass != passing_style::in
            && n->pass != passing_style::inout
            && n->pass != passing_style::out
            && n->pass != passing_style::move
            )
        {
            error( "a 'this' parameter must be in, inout, out, or move", false );
        }

        if (
            n->declaration->has_name("that")
            && n->pass != passing_style::in
            && n->pass != passing_style::move
            )
        {
            error( "a 'that' parameter must be in or move", false );
        }

        //  The only parameter type that could be const-qualified is a 'copy' parameter, because
        //  only it is always truly its own variable, so it makes sense to let the user qualify it;
        //  all the other parameter types are conceptually (usually actually) bound to their args
        if (
            !is_returns
            && n->declaration->is_const()
            && n->pass != passing_style::copy
            && n->pass != passing_style::inout
            )
        {
            switch (n->pass) {
            break;case passing_style::in:
                error( "an 'in' parameter is always const, 'const' isn't needed and isn't allowed", false );
            break;case passing_style::inout:
                // error( "an 'inout' parameter can't be const, if you do want it to be const then use 'in' instead", false );
            break;case passing_style::out:
                error( "an 'out' parameter can't be const, otherwise it can't be initialized in the function body", false );
            break;case passing_style::move:
                error( "a 'move' parameter can't be const, otherwise it can't be moved from in the function body", false );
            break;case passing_style::forward:
                error( "a 'forward' parameter shouldn't be const, because it passes along the argument's actual const-ness (and actual value category)", false );
            break;default:
                assert (!"ICE: missing case");
            }
            return {};
        }

        if (
            !is_returns
            && !is_statement
            && n->declaration->initializer
            )
        {
            error("Cpp2 is currently exploring the path of not allowing default arguments - use overloading instead", false);
            return {};
        }
        if (is_named && is_returns) {
            auto tok = n->name();
            assert(tok);
            if (tok->type() != lexeme::Identifier) {
                error("expected identifier, not '" + tok->to_string() + "'",
                    false, tok->position());
            }
            else if (n->declaration->has_wildcard_type()) {
                error("return parameter '" + tok->to_string() + "' must have a type",
                    false, tok->position());
            }
        }
        return n;
    }


    //G parameter-declaration-list:
    //G     '(' parameter-declaration-seq? ','? ')'
    //G
    //G parameter-declaration-seq:
    //G     parameter-declaration
    //G     parameter-declaration-seq ',' parameter-declaration
    //G
    auto parameter_declaration_list(
        bool is_returns    = false,
        bool is_named      = true,
        bool is_template   = false,
        bool is_statement  = false
    )
        -> std::unique_ptr<parameter_declaration_list_node>
    {
        //  Remember current position, because we need to look ahead in
        //  the case of seeing whether a local statement starts with a
        //  parameter list, since finding that it doesn't (it's some other
        //  parenthesized expression) is not an error, just backtrack
        auto start_pos = pos;

        auto opener = lexeme::LeftParen;
        auto closer = lexeme::RightParen;
        if (is_template) {
            opener = lexeme::Less;
            closer = lexeme::Greater;
        }

        if (curr().type() != opener) {
            return {};
        }

        auto n = std::make_unique<parameter_declaration_list_node>();
        n->open_paren = &curr();
        next();

        auto param = std::make_unique<parameter_declaration_node>();

        auto count = 1;

        while ((param = parameter_declaration(is_returns, is_named, is_template, is_statement)) != nullptr)
        {
            param->ordinal = count;
            ++count;

            if (
                std::ssize(n->parameters) > 1
                && n->parameters.back()->has_name("that")
                )
            {
                error("'that' may not be followed by any additional parameters", false);
            }

            n->parameters.push_back( std::move(param) );

            if (curr().type() == closer) {
                break;
            }

            //  Allow a trailing comma in the list
            else if (
                curr().type() == lexeme::Comma
                && peek(1)
                && peek(1)->type() == closer
                )
            {
                next();
                break;
            }

            else if (curr().type() != lexeme::Comma) {
                if (is_statement) {
                    pos = start_pos;    // backtrack
                }
                else {
                    error("expected ',' in parameter list", true, {}, true);
                }
                return {};
            }

            next();
        }

        if (curr().type() != closer) {
            if (is_statement) {
                pos = start_pos;    // backtrack
            }
            else {
                error("invalid parameter list", true, {}, true);
            }
            return {};
        }

        n->close_paren = &curr();
        next();
        return n;
    }


    //G contract:
    //G     contract-kind contract-group? ':' '(' logical-or-expression ')'
    //G     contract-kind contract-group? ':' '(' logical-or-expression ',' expression ')'
    //G
    //G contract-group:
    //G     '<' id-expression contract-flags?'>'
    //G
    //G contract-flags:
    //G     ',' id-expression contract-flags?
    //G
    //G contract-kind: one of
    //G     'pre' 'post' 'assert'
    //G
    auto contract()
        -> std::unique_ptr<contract_node>
    {
        auto n = std::make_unique<contract_node>(curr().position());
        auto guard = capture_groups_stack_guard(this, &n->captures);

        if (
            curr() != "pre"
            && curr() != "post"
            && curr() != "assert"
            )
        {
            return {};
        }
        n->kind = &curr();
        next();

        //  Check if there's a <group,flags>
        if (curr().type() == lexeme::Less) {
            next();
            if (auto id = id_expression()) {
                n->group = std::move(id);
            }
            else {
                error("invalid contract group after '<'");
                return {};
            }

            //  Now check if there's a list of flags
            while (curr().type() == lexeme::Comma) {
                next();
                if (auto id = id_expression()) {
                    n->flags.push_back( std::move(id) );
                }
                else {
                    error("invalid contract tag in list");
                    return {};
                }
            }

            if (curr().type() != lexeme::Greater) {
                error("expected '>' after contract group");
                return {};
            }
            next();
        }

        if (curr().type() != lexeme::LeftParen) {
            error("expected '(' before the contract condition");
            return {};
        }
        next();

        auto condition = logical_or_expression();
        if (!condition) {
            error("invalid contract condition", true, {}, true);
            return {};
        }
        n->condition = std::move(condition);

        //  Now check for the optional string message
        if (curr().type() == lexeme::Comma) {
            next();
            n->message = expression();
            if (!n->message) {
                error("a contract violation message must be a valid string expression", true, {}, true);
                return {};
            }
        }

        //  Consume trailing comma
        if (curr().type() == lexeme::Comma) {
            next();
        }

        if (curr().type() != lexeme::RightParen) {
            error("expected ')' at the end of the contract");
            return {};
        }
        next();

        return n;
    }


    //G function-type:
    //G     parameter-declaration-list throws-specifier? return-list? contract-seq?
    //G
    //G throws-specifier:
    //G     'throws'
    //G
    //G return-list:
    //G     expression-statement
    //G     '->' parameter-direction? type-id
    //G     '->' parameter-declaration-list
    //G
    //G contract-seq:
    //G     contract
    //G     contract-seq contract
    //G
    auto function_type(
        declaration_node* my_decl,
        bool              is_named = true
        )
        -> std::unique_ptr<function_type_node>
    {
        auto n = std::make_unique<function_type_node>( my_decl );

        //  Parameters
        auto parameters = parameter_declaration_list(false, is_named, false);
        if (!parameters) {
            return {};
        }
        n->parameters = std::move(parameters);

        //  Optional "throws"
        if (
            curr().type() == lexeme::Keyword
            && curr() == "throws"
            )
        {
            if (
                n->is_move()
                || n->is_swap()
                || n->is_destructor()
                )
            {
                error( "(experimental restriction) Cpp2 currently does not allow a move, swap, or destructor function to be designated 'throws'" );
                return {};
            }

            n->throws = true;
            next();
        }


        //  If we're not at a '->' or 'requires' or contract and what follows is
        //  an expression, this is a ":(params) expr" shorthand function syntax
        if (
            curr().type() != lexeme::Arrow
            && curr() != "requires"
            && (curr() != "pre" && curr() != "post")
            )
        {
            auto start_pos = pos;
            auto at_an_expression = expression() != nullptr;
            pos = start_pos;    // backtrack no matter what, we're just peeking here

            if (at_an_expression) {
                n->returns = function_type_node::single_type_id{ std::make_unique<type_id_node>() };
                assert(n->returns.index() == function_type_node::id);
                n->my_decl->terse_no_equals = true;
                return n;
            }
        }


        //  Optional returns
        if (curr().type() == lexeme::Arrow)
        {
            next();

            if (auto pass = to_passing_style(curr());
                pass != passing_style::invalid
                )
            {
                if (
                    pass != passing_style::forward
                    && pass != passing_style::move
                    )
                {
                    error("only 'forward' and 'move' return passing style are allowed from functions");
                }
                next();
                if (auto t = type_id()) {
                    n->returns = function_type_node::single_type_id{ std::move(t), pass };
                    assert(n->returns.index() == function_type_node::id);
                }
                else {
                    auto msg = std::string("'");
                    msg += to_string_view(pass);
                    error(msg + "' must be followed by a type-id");
                }
            }

            else if (auto t = type_id())
            {
                if (
                    t->get_token()
                    && t->get_token()->to_string() == "auto"
                    )
                {
                    auto name = std::string{"v"};
                    if (my_decl && my_decl->name()) {
                        name = my_decl->name()->to_string();
                    }
                    errors.emplace_back(
                        curr().position(),
                        "to define a function " + name + " with deduced return type, write '" + name + ": ( /* arguments */ ) -> _ = { /* function body */ }'"
                    );
                    return {};
                }
                n->returns = function_type_node::single_type_id{ std::move(t), passing_style::move };
                assert(n->returns.index() == function_type_node::id);
            }

            else if (auto returns_list = parameter_declaration_list(true, is_named))
            {
                if (std::ssize(returns_list->parameters) < 1) {
                    error("an explicit return value list cannot be empty");
                    return {};
                }
                n->returns = std::move(returns_list);
                assert(n->returns.index() == function_type_node::list);
            }

            else
            {
                error("missing function return after ->");
                return {};
            }
        }

        //  Pre/post conditions
        while (auto c = contract())
        {
            if (
                *c->kind != "pre"
                && *c->kind != "post"
                )
            {
                error("only 'pre' and 'post' contracts are allowed on functions");
                return {};
            }
            n->contracts.push_back( std::move(c) );
        }

        return n;
    }


    auto apply_type_metafunctions( declaration_node& decl )
        -> bool;


    //G unnamed-declaration:
    //G     ':' meta-functions? template-parameters? function-type requires-clause? '=' statement
    //G     ':' meta-functions? template-parameters? function-type statement
    //G     ':' meta-functions? template-parameters? type-id? requires-clause? '=' statement
    //G     ':' meta-functions? template-parameters? type-id
    //G     ':' meta-functions? template-parameters? 'final'? 'type' requires-clause? '=' statement
    //G     ':' 'namespace' '=' statement
    //G
    //G meta-functions:
    //G     '@' id-expression
    //G     meta-functions '@' id-expression
    //G
    //G requires-clause:
    //G      # note: for aliases, == is not allowed in expressions until new ( is opened
    //G      'requires' logical-or-expression
    //G
    //G template-parameters:
    //G     '<' parameter-declaration-seq '>'
    //G
    auto unnamed_declaration(
        source_position                      start,
        bool                                 semicolon_required    = true,
        bool                                 captures_allowed      = false,
        bool                                 named                 = false,
        bool                                 is_parameter          = false,
        bool                                 is_template_parameter = false,
        std::unique_ptr<unqualified_id_node> id                    = {},
        accessibility                        access                = {},
        bool                                 is_variadic           = false,
        statement_node*                      my_stmt               = {},
        bool                                 semicolon_allowed     = true
    )
        -> std::unique_ptr<declaration_node>
    {
        auto n = std::make_unique<declaration_node>( current_declarations.back() );
        n->pos = start;

        n->identifier   = std::move(id);
        n->access       = access;
        n->is_variadic  = is_variadic;
        n->my_statement = my_stmt;

        //  If we're in a type scope and the next token is ';', treat this as if
        //  ': _;' without an initializer.
        //  This is for type metafunctions that want to use the incomplete name-only
        //  declaration, and transform it to something else. If unchanged the
        //  incomplete declaration will be rejected later by sema.check rule.
        if (
            n->parent_is_type()
            && curr().type() == lexeme::Semicolon
            )
        {
            n->type = std::make_unique<type_id_node>();
            assert (n->is_object());
            next();
            return n;
        }

        //  For a template parameter, ':' is not required and
        //  we default to ': type'
        if (
            is_template_parameter
            && curr().type() != lexeme::Colon
            )
        {
            //  So invent the "type" token
            generated_text.push_back("type");
            generated_tokens->push_back({
                generated_text.back().c_str(),
                std::ssize(generated_text.back()),
                start,
                lexeme::Identifier
            });

            //  So we can create the type_node

            auto t = std::make_unique<type_node>( &generated_tokens->back() );

            n->type = std::move(t);
            assert (n->is_type());

            //  That's it, we're done here
            return n;
        }

        //  For 'this' and 'that' parameters ':' is not allowed and we'll use the default ': _'
        if (
            n->identifier
            && is_parameter
            && (
                *n->identifier->identifier == "this"
                || *n->identifier->identifier == "that"
                )
            && curr().type() == lexeme::Colon
            )
        {
            error("a 'this' or 'that' parameter knows its type, no ':' is allowed here", false);
            return {};
        }

        //  For an ordinary parameter, ':' is not required and
        //  we default to ': _' - i.e., deduced with no initializer
        if (
            is_parameter
            && curr().type() != lexeme::Colon
            )
        {
            //  So invent the "_" token
            generated_text.push_back("_");
            generated_tokens->push_back({
                generated_text.back().c_str(),
                std::ssize(generated_text.back()),
                start,
                lexeme::Identifier
            });

            //  So we can create the typeid_id_node and its unqualified_id_node

            auto gen_id = std::make_unique<unqualified_id_node>();
            gen_id->identifier = &generated_tokens->back();

            auto type = std::make_unique<type_id_node>();
            type->pos = start;
            type->id = std::move(gen_id);

            n->type = std::move(type);
            assert (n->is_object());

            //  That's it, we're done here
            return n;
        }

        //  Otherwise, the next token must be ':'
        if (curr().type() != lexeme::Colon) {
            return {};
        }
        next();

        if (curr() == "union") {
            error("unsafe 'union' is not supported in Cpp2 - write '@union' to apply Cpp2's safe 'union' type metafunction instead, or use std::variant");
        }

        //  Next is an optional metafunctions clause
        while (curr() == "@") {
            next();
            auto idx = id_expression();
            if (!idx) {
                error("'@' must be followed by a metafunction name", false);
                return {};
            }
            n->metafunctions.push_back( std::move(idx) );
        }

        //  Next is an optional template parameter list
        if (curr().type() == lexeme::Less) {
            auto template_parameters = parameter_declaration_list(false, false, true);
            if (!template_parameters) {
                error("invalid template parameter list");
                return {};
            }
            n->template_parameters = std::move(template_parameters);
        }

        auto guard =
            captures_allowed
            ? std::make_unique<capture_groups_stack_guard>(this, &n->captures)
            : std::unique_ptr<capture_groups_stack_guard>()
            ;

        auto guard2 = current_declarations_stack_guard(this, n.get());

        //  Next is an an optional type

        auto deduced_type = false;

        //  It could be "type", declaring a user-defined type
        if (
            curr() == "type"
            || (
                curr() == "final"
                && peek(1) && *peek(1) == "type"
                )
            )
        {
            n->type = std::make_unique<type_node>( &curr(), curr() == "final" );

            if (curr() == "final") {
                next();
            }
            next();

            if (
                is_parameter
                && !is_template_parameter
                )
            {
                error("a normal parameter cannot be a 'type' - did you mean to put this in a < > template parameter list?");
                return {};
            }
            assert (n->is_type());
        }

        //  Or a function type, declaring a function - and tell the function whether it's in a user-defined type
        else if (auto t = function_type(n.get(), named))
        {
            n->type = std::move(t);
            assert (n->is_function());

            if (!n->metafunctions.empty()) {
                errors.emplace_back(
                    n->metafunctions.front()->position(),
                    "(temporary alpha limitation) metafunctions are currently not supported on functions, only on types"
                );
                return {};
            }
        }

        //  Or a namespace
        else if (curr() == "namespace")
        {
            n->type = std::make_unique<namespace_node>( &curr() );
            assert (n->type.index() == declaration_node::a_namespace);
            next();

            if (!n->metafunctions.empty()) {
                errors.emplace_back(
                    n->metafunctions.front()->position(),
                    "(temporary alpha limitation) metafunctions are currently not supported on namespaces, only on types"
                );
                return {};
            }
        }

        //  Or just a type-id, declaring a non-pointer object
        else if (auto t = type_id())
        {
            if (
                t->get_token()
                && t->get_token()->to_string() == "auto"
                )
            {
                auto name = std::string{"v"};
                if (n->name()) {
                    name = n->name()->to_string();
                }
                errors.emplace_back(
                    curr().position(),
                    "to define a variable " + name + " with deduced type, write '" + name + " := /* initializer */;'"
                );
                return {};
            }

            n->type = std::move(t);
            assert (n->is_object());

            if (!n->metafunctions.empty()) {
                errors.emplace_back(
                    n->metafunctions.front()->position(),
                    "(temporary alpha limitation) metafunctions are currently not supported on objects, only on types"
                );
                return {};
            }

            if (curr().type() == lexeme::LeftBracket) {
                error("C-style array types are not allowed, use std::array instead");
                return {};
            }
        }

        //  Or nothing, declaring an object of deduced type,
        //  which we'll represent using an empty type-id
        else {
            n->type = std::make_unique<type_id_node>();
            assert (n->is_object());
            deduced_type = true;
        }

        //  If we've already validated that this is a function where the parameter
        //  list is followed by a valid expression-statement, parse that again
        //  (requiring a semicolon as we validated when determining terse_no_equals)
        if (n->terse_no_equals)
        {
            n->equal_sign = curr().position();
            n->initializer = statement(/*ignore semicolon_required*/ false, n->equal_sign);
            assert( n->initializer && "ICE: should have already validated that there's a valid expression-statement here" );
        }

        else
        {
            //  Next is optionally a requires clause (if not using the "-> expr;" syntax)
            if (curr() == "requires")
            {
                if (
                    n->is_type()
                    && !n->template_parameters
                    )
                {
                    error("'requires' is not allowed on a type that does not have a template parameter list");
                    return {};
                }

                if (n->is_namespace())
                {
                    error("'requires' is not allowed on a namespace");
                    return {};
                }

                n->requires_pos = curr().position();
                next();
                auto e = logical_or_expression(true, false);
                if (!e) {
                    error("'requires' must be followed by an expression");
                    return {};
                }
                n->requires_clause_expression = std::move(e);
            }

            //  Next is optionally = or == followed by an initializer

            //  If there is no = or ==
            if (
                !done()
                && curr().type() != lexeme::Assignment
                && curr().type() != lexeme::EqualComparison
                )
            {
                if (
                    n->is_type()
                    && !is_template_parameter
                    )
                {
                    error("a user-defined type must have an = initializer");
                    return {};
                }

                //  Then there may be a semicolon
                //  If there is a semicolon...
                if (!done() && curr().type() == lexeme::Semicolon) {
                    //  If it's allowed, eat it
                    if (semicolon_allowed) {
                        next();
                    }
                    // Otherwise, diagnose an error
                    else {
                        error("unexpected semicolon after declaration", {}, {}, {});
                    }
                }
                //  Otherwise if there isn't one and it was required, diagnose an error
                else if (semicolon_required) {
                    if (curr().type() == lexeme::LeftBrace) {
                        error("expected '=' before '{' - did you mean '= {' ?", true, {}, true);
                    }
                    else {
                        error("missing ';' at end of declaration or '=' at start of initializer", true, {}, true);
                    }
                    return {};
                }
            }

            //  There was an = or ==, so eat it and continue
            else
            {
                n->equal_sign = curr().position();

                if (curr().type() == lexeme::EqualComparison) {
                    if (!n->is_function()) {
                        error("syntax error at '==' - did you mean '='?");
                    }
                    n->is_constexpr = true;
                }

                next();

                if (auto t = std::get_if<declaration_node::an_object>(&n->type);
                    t
                    && (*t)->is_pointer_qualified()
                    )
                {
                    if (
                        curr() == "nullptr"
                        || isdigit(std::string_view(curr())[0])
                        || (
                            curr() == "("
                            && peek(1)
                            && *peek(1) == ")"
                            )
                        )
                    {
                        error("pointer cannot be initialized to null or int - leave it uninitialized and then set it to a non-null value when you have one");
                        violates_lifetime_safety = true;
                        throw std::runtime_error("null initialization detected");
                    }
                }

                //  deduced_type == true means that the type will be deduced,
                //  represented using an empty type-id
                if (
                    deduced_type
                    && peek(1)
                    )
                {
                    auto& type = std::get<declaration_node::an_object>(n->type);
                    // object initialized by the address of the curr() object
                    if (peek(1)->type() == lexeme::Ampersand)
                    {
                        type->address_of = &curr();
                    }
                    // object initialized by (potentially multiple) dereference of the curr() object
                    else if (peek(1)->type() == lexeme::Multiply)
                    {
                        type->dereference_of = &curr();
                        for (int i = 1; peek(i) && peek(i)->type() == lexeme::Multiply; ++i) {
                            type->dereference_cnt += 1;
                        }
                    }
                    else if (
                        // object initialized by the result of the function call (and it is not unnamed function)
                        (peek(1)->type() == lexeme::LeftParen && curr().type() != lexeme::Colon)
                        || curr().type() == lexeme::Identifier // or by the object (variable that the type need to be checked)
                    )
                    {
                        type->suspicious_initialization = &curr();
                    }
                }

                if (!(n->initializer = statement(semicolon_required, n->equal_sign))) {
                    error(
                        "ill-formed initializer",
                        true, {}, true
                    );
                    next();
                    return {};
                }
            }

        }

        //  If this is a non-local named function with a single-statement body,
        //  followed by a non-declaration statement, they probably forgot { }
        //  so give a nicer diagnostic
        if (
            !done()
            && n->is_function()
            && n->has_name()
            && !n->parent_is_function()
            && n->initializer
            && !n->initializer->is_compound()
            )
        {
            auto start_pos = pos;
            auto stmt = statement();
            auto at_a_statement = stmt != nullptr && !stmt->is_declaration();
            pos = start_pos;    // backtrack no matter what, we're just peeking here

            if (at_a_statement) {
                error("in this scope, a single-statement function body cannot be immediately followed by a statement - did you forget to put { } braces around a multi-statement function body?", false);
                return n;
            }
        }

        if (
            n->is_type()
            && n->initializer
            && !done() && curr().type() == lexeme::Semicolon
            )
        {
            if (n->initializer->is_compound() && n->has_name()) {
                error("Cpp2 does not allow a semicolon after the closing brace of a type definition");
                return {};
            }
        }

        //  A type initializer must be a compound expression
        if (
            n->is_type()
            && !is_parameter
            && (
                !n->initializer
                || !n->initializer->is_compound()
                )
            )
        {
            errors.emplace_back(
                n->position(),
                "a user-defined type initializer must be a compound-expression consisting of declarations"
            );
            return {};
        }

        //  If this is a type with metafunctions, apply those
        if (n->is_type()) {
            if (!apply_type_metafunctions(*n)) {
                error(
                    "error encountered while applying type metafunctions",
                    false, {}, true
                );
                return {};
            }
        }

        if (
            n->is_function()
            && n->initializer
            && !done() && curr().type() == lexeme::Semicolon
            )
        {
            if (n->initializer->is_compound() && n->has_name()) {
                error("a braced function body may not be followed by a semicolon (empty statements are not allowed)");
                return {};
            } else if (n->initializer->is_expression()) {
                error("a single-expression function should end with a single semicolon");
                return {};
            }
        }

        //  If this is a function with a list of multiple/named return values,
        //  and the function body's end doesn't already have "return" as the
        //  last statement, then generate "return;" as the last statement
        if (auto func = std::get_if<declaration_node::a_function>(&n->type);
            func
            && n->initializer
            && (*func)->returns.index() == function_type_node::list
            )
        {
            if (!n->initializer->is_compound()) {
                error(
                    "a function with named return value(s) must have a full { } body",
                    false,
                    {},
                    true
                );
                return {};
            }

            auto& body = std::get<statement_node::compound>(n->initializer->statement);

            if (
                body->statements.empty()
                || !body->statements.back()->is_return()
                )
            {
                auto last_pos = n->position();
                if (!body->statements.empty()) {
                    last_pos = body->statements.back()->position();
                }
                ++last_pos.lineno;
                generated_tokens->emplace_back( "return", last_pos, lexeme::Keyword);

                auto ret = std::make_unique<return_statement_node>();
                ret->identifier = &generated_tokens->back();

                auto stmt = std::make_unique<statement_node>();
                stmt->statement = std::move(ret);

                body->statements.push_back(std::move(stmt));
            }
        }

        //  If this is a function, record its extents
        if (n->is_function()) {
            function_body_extents.emplace_back(
                n->equal_sign.lineno,
                peek(-1)->position().lineno
            );
        }

        return n;
    }


    //G alias:
    //G     ':' template-parameters? 'type' requires-clause? '==' type-id ';'
    //G     ':' 'namespace' '==' id-expression ';'
    //G     ':' template-parameters? type-id? requires-clause? '==' expression ';'
    //G
    //GT     ':' function-type '==' expression ';'
    //GT        # See commit 63efa6ed21c4d4f4f136a7a73e9f6b2c110c81d7 comment
    //GT        # for why I don't see a need to enable this yet
    //
    auto alias()
        -> std::unique_ptr<declaration_node>
    {
        //  Remember current position, because we need to look ahead
        auto start_pos = pos;

        auto n = std::make_unique<declaration_node>( current_declarations.back() );

        if (curr().type() != lexeme::Colon) {
            return {};
        }
        next();

        //  Next is an optional template parameter list
        if (curr().type() == lexeme::Less) {
            auto template_parameters = parameter_declaration_list(false, false, true);
            if (!template_parameters) {
                pos = start_pos;    // backtrack
                return {};
            }
            n->template_parameters = std::move(template_parameters);
        }

        auto a = std::make_unique<alias_node>( &curr() );

        //  Next must be 'type', 'namespace', a type-id, or we're at the 'requires' or '=='
        if (curr() == "type")
        {
            next();
        }
        else if (curr() == "namespace")
        {
            next();
            if (n->template_parameters) {
                errors.emplace_back(
                    curr().position(),
                    "a namespace or namespace alias cannot have template parameters"
                );
                return {};
            }
        }
        else if (curr().type() != lexeme::EqualComparison && curr() != "requires")
        {
            a->type_id = type_id();
            if (!a->type_id) {
                pos = start_pos;    // backtrack
                return {};
            }
        }

        //  Next is optionally a requires clause
        if (curr() == "requires")
        {
            if (
                n->is_type_alias()
                && !n->template_parameters
                )
            {
                error("'requires' is not allowed on a type alias that does not have a template parameter list");
                return {};
            }

            if (n->is_namespace_alias())
            {
                error("'requires' is not allowed on a namespace alias");
                return {};
            }

            n->requires_pos = curr().position();
            next();
            auto e = logical_or_expression(true, false);
            if (!e) {
                error("'requires' must be followed by an expression");
                return {};
            }
            n->requires_clause_expression = std::move(e);
        }

        //  Now we should be at the '==' if this is an alias

        if (curr().type() == lexeme::EqualComparison) {
            next();
        }
        else {
            if (a->type->type() != lexeme::EqualComparison) {
                pos = start_pos;    // backtrack
                return {};
            }
        }
        assert(peek(-1)->type() == lexeme::EqualComparison);

        if (
            n->parent_is_type()
            && *a->type == "namespace"
            )
        {
            errors.emplace_back(
                curr().position(),
                "a namespace alias cannot appear in a type scope"
            );
            return {};
        }

        //  Finally, pick up the initializer

        //  Type alias
        if (*a->type == "type")
        {
            auto t = type_id();
            if (!t) {
                errors.emplace_back(
                    curr().position(),
                    "a 'type ==' alias declaration must be followed by a type name"
                );
                return {};
            }
            if (
                t->is_wildcard()
                || ( t->get_token() && t->get_token()->to_string() == "auto" )
            ) {
                errors.emplace_back(
                    curr().position(),
                    "a 'type ==' alias declaration must be followed by a type name (not a wildcard _ nor auto)"
                );
                return {};
            }
            a->initializer = std::move(t);
        }

        //  Namespace alias
        else if (*a->type == "namespace")
        {
            if (auto qid = id_expression()) {
                a->initializer = std::move(qid);
            }
            else {
                errors.emplace_back(
                    curr().position(),
                    "a 'namespace ==' alias declaration must be followed by a namespace name (id-expression)"
                );
                return {};
            }
        }

        //  Object alias
        else if (
            a->type_id
            || a->type->type() == lexeme::EqualComparison
            )
        {
            auto e = expression();
            if (!e) {
                errors.emplace_back(
                    curr().position(),
                    "an object '==' alias declaration must be followed by an expression"
                );
                return {};
            }
            a->initializer = std::move(e);
        }

        //  Anything else shouldn't be possible
        else {
            assert(!"ICE: should be unreachable - invalid alias declaration");
            return {};
        }

        //  And the final ceremonial semicolon
        if (curr() != ";") {
            errors.emplace_back(
                curr().position(),
                "';' expected at end of alias declaration"
            );
            return {};
        }
        next();

        n->type = std::move(a);

        return n;
    }


    //G declaration:
    //G     access-specifier? identifier '...'? unnamed-declaration
    //G     access-specifier? identifier alias
    //G
    //G access-specifier:
    //G     public
    //G     protected
    //G     private
    //G
    auto declaration(
        bool            semicolon_required    = true,
        bool            is_parameter          = false,
        bool            is_template_parameter = false,
        statement_node* my_stmt               = {},
        bool            semicolon_allowed     = true
    )
        -> std::unique_ptr<declaration_node>
    {
        if (done()) { return {}; }

        //  Remember current position, because we need to look ahead
        auto start_pos = pos;

        auto n = std::unique_ptr<declaration_node>{};

        //  This scope is to ensure that once we've moved 'id' into the
        //  declaration_node, we don't access the moved-from local name
        //  (and similar hygiene for 'access' though that one doesn't matter as much)
        //  The reason to move 'id' into unnamed_declaration() is so that
        //  it can conveniently perform some checks that refer to the name
        {
            auto access = accessibility::default_;
            if (curr() == "public") {
                access = accessibility::public_;
                next();
            }
            else if (curr() == "protected") {
                access = accessibility::protected_;
                next();
            }
            else if (curr() == "private") {
                access = accessibility::private_;
                next();
            }

            //  If they wrote an access-specifier, see if they put a ':'
            //  after it out of Cpp1 habit (there's no colon in Cpp2)
            if (
                access != accessibility::default_
                && curr().type() == lexeme::Colon
                )
            {
                errors.emplace_back(
                    curr().position(),
                    "':' is not allowed after an access-specifier"
                );
                return {};
            }

            auto id = unqualified_id();
            if (!id) {
                return {};
            }

            if (id->to_string() == "...") {
                errors.emplace_back(
                    curr().position(),
                    "a variadic declaration must have a name - did you forget to write a name before '...'?"
                );
                pos = start_pos;    // backtrack
            }

            auto is_variadic = false;
            if (curr().type() == lexeme::Ellipsis) {
                is_variadic = true;
                next();
            }

            //  Provide some useful Cpp1->Cpp2 migration diagnostics for common mistakes
            //
            if (
                id->get_token()
                && *id->get_token() == "auto"
                && curr().type() != lexeme::Colon
                )
            {
                auto name = std::string{"v"};
                if (peek(0) && peek(0)->type() == lexeme::Identifier) {
                    name = peek(0)->to_string();
                }
                errors.emplace_back(
                    curr().position(),
                    "to define a variable " + name + " of type T, write '" + name + ": T = /* initializer */'"
                );
                return {};
            }
            if (
                id->get_token()
                && *id->get_token() == "namespace"
                && curr().type() != lexeme::Colon
                )
            {
                auto name = std::string{"N"};
                if (peek(0)) {
                    name = peek(0)->to_string();
                }
                errors.emplace_back(
                    curr().position(),
                    "to define a namespace " + name + ", write '" + name + " : namespace = { /*contents*/ }'"
                );
                return {};
            }
            if (
                id->get_token()
                && (
                    *id->get_token() == "class"
                    || *id->get_token() == "struct"
                    )
                && curr().type() != lexeme::Colon
                )
            {
                auto name = std::string{"C"};
                if (peek(0)) {
                    name = peek(0)->to_string();
                }
                errors.emplace_back(
                    curr().position(),
                    "to define a type " + name + ", write '" + name + " : type = { /*body*/ }'"
                );
                return {};
            }

            //  Now proceed...
            //

            //  First see if it's an alias declaration
            n = alias();
            if (n) {
                if (is_parameter) {
                    errors.emplace_back(
                        curr().position(),
                        "a parameter declaration may not be an alias declaration"
                    );
                    return {};
                }

                if (is_variadic) {
                    errors.emplace_back(
                        curr().position(),
                        "an alias declaration may not be variadic"
                    );
                    return {};
                }

                n->pos        = start_pos;
                n->identifier = std::move(id);
                n->access     = access;
                return n;
            }

            //  Otherwise, this is a normal declaration
            n = unnamed_declaration(
                start_pos,
                semicolon_required,
                false,
                true,
                is_parameter,
                is_template_parameter,
                std::move(id),
                access,
                is_variadic,
                my_stmt,
                semicolon_allowed
            );
            if (!n) {
                pos = start_pos;    // backtrack
                return {};
            }
        }

        //  Note: Do this after trying to parse this as a declaration, for parse backtracking

        if (
            *n->identifier->identifier == "that"
            && (
                !is_parameter
                || is_template_parameter
                )
            )
        {
            errors.emplace_back(
                n->identifier->position(),
                "'that' may only be declared as an ordinary function parameter"
            );
            return {};
        }

        //  Cache some context
        n->is_a_template_parameter = is_template_parameter;
        n->is_a_parameter          = is_parameter;

        return n;
    }


    //G declaration-seq:
    //G     declaration
    //G     declaration-seq declaration
    //G
    //G translation-unit:
    //G     declaration-seq?
    //
    auto translation_unit()
        -> std::unique_ptr<translation_unit_node>
    {
        auto n = std::make_unique<translation_unit_node>();
        for (auto d = declaration(); d; d = declaration()) {
            n->declarations.push_back( std::move(d) );
        }
        return n;
    }

public:
    //-----------------------------------------------------------------------
    //  debug_print
    //
    auto debug_print(std::ostream& o) const
        -> void;
};


//-----------------------------------------------------------------------
//
//  Common parts for printing visitors
//
//-----------------------------------------------------------------------
//
struct printing_visitor
{
    //-----------------------------------------------------------------------
    //  Constructor: remember a stream to write to
    //
    std::ostream& o;

    printing_visitor(std::ostream& out) : o{out} { indent_spaces = 2; }
};


//-----------------------------------------------------------------------
//
//  Visitor for printing a parse tree
//
//-----------------------------------------------------------------------
//
class parse_tree_printer : printing_visitor
{
    using printing_visitor::printing_visitor;

public:
    auto start(token const& n, int indent) -> void
    {
        o << pre(indent) << _as<std::string>(n.type()) << ": " << n.to_string() << "\n";
    }

    auto start(literal_node const&, int indent) -> void
    {
        o << pre(indent) << "literal" << "\n";
    }

    auto start(expression_node const& n, int indent) -> void
    {
        o << pre(indent) << "expression - "
            << n.num_subexpressions << " subexpressions, my_statement ["
            << static_cast<void const*>(n.my_statement) << "]\n";
    }

    auto start(expression_list_node::term const&n, int indent) -> void
    {
        o << pre(indent) << "expression-list term\n";
        if (n.pass == passing_style::out) {
            o << pre(indent+1) << "out\n";
        }
    }

    auto start(expression_list_node const&, int indent) -> void
    {
        o << pre(indent) << "expression-list\n";
    }

    auto start(primary_expression_node const&, int indent) -> void
    {
        o << pre(indent) << "primary-expression\n";
    }

    auto start(prefix_expression_node const&, int indent) -> void
    {
        o << pre(indent) << "prefix-expression\n";
    }

    auto start(is_as_expression_node const&, int indent) -> void
    {
        o << pre(indent) << "is-as-expression\n";
    }

    template<String Name, typename Term>
    auto start(binary_expression_node<Name, Term> const&, int indent) -> void
    {
        o << pre(indent) << Name.value << "-expression\n";
    }

    auto start(expression_statement_node const& n, int indent) -> void
    {
        o << pre(indent) << "expression-statement - [" << static_cast<void const*>(&n) << "]\n";
    }

    auto start(postfix_expression_node const&, int indent) -> void
    {
        o << pre(indent) << "postfix-expression\n";
    }

    auto start(unqualified_id_node const&, int indent) -> void
    {
        o << pre(indent) << "unqualified-id\n";
    }

    auto start(qualified_id_node const&, int indent) -> void
    {
        o << pre(indent) << "qualified-id\n";
    }

    auto start(type_id_node const&, int indent) -> void
    {
        o << pre(indent) << "type-id\n";
    }

    auto start(id_expression_node const&, int indent) -> void
    {
        o << pre(indent) << "id-expression\n";
    }

    auto start(statement_node const&, int indent) -> void
    {
        o << pre(indent) << "statement\n";
    }

    auto start(compound_statement_node const&, int indent) -> void
    {
        o << pre(indent) << "compound-statement\n";
    }

    auto start(selection_statement_node const& n, int indent) -> void
    {
        o << pre(indent) << "selection-statement\n";
        o << pre(indent+1) << "is_constexpr: " << _as<std::string>(n.is_constexpr) << "\n";
    }

    auto start(alternative_node const&, int indent) -> void
    {
        o << pre(indent) << "alternative\n";
    }

    auto start(jump_statement_node const&, int indent) -> void
    {
        o << pre(indent) << "jump\n";
    }

    auto start(using_statement_node const& n, int indent) -> void
    {
        o << pre(indent) << "using" << (n.for_namespace? " namespace" : "") << "\n";
    }

    auto start(inspect_expression_node const& n, int indent) -> void
    {
        o << pre(indent) << "inspect-expression\n";
        o << pre(indent+1) << "is_constexpr: " << _as<std::string>(n.is_constexpr) << "\n";
    }

    auto start(return_statement_node const&, int indent) -> void
    {
        o << pre(indent) << "return-statement\n";
    }

    auto start(iteration_statement_node const& n, int indent) -> void
    {
        o << pre(indent) << "iteration-statement\n";
        assert(n.identifier);
        o << pre(indent+1) << "identifier: " << std::string_view(*n.identifier) << "\n";
    }

    auto start(contract_node const& n, int indent) -> void
    {
        o << pre(indent) << "contract\n";
        assert(n.kind);
        o << pre(indent+1) << "kind: " << std::string_view(*n.kind) << "\n";
        if (!n.captures.members.empty()) {
            o << pre(indent+1) << "captures: " << n.captures.members.size() << "\n";
        }
    }

    auto start(type_node const&, int indent) -> void
    {
        o << pre(indent) << "user-defined type\n";
    }

    auto start(namespace_node const&, int indent) -> void
    {
        o << pre(indent) << "namespace\n";
    }

    auto start(function_type_node const& n, int indent) -> void
    {
        o << pre(indent) << "function\n";
        o << pre(indent+1) << "throws: " << _as<std::string>(n.throws) << "\n";
        if (n.returns.index() == function_type_node::id) {
            auto& r = std::get<function_type_node::id>(n.returns);
            if (r.pass != passing_style::invalid) {
                o << pre(indent+1) << "returns by: " << to_string_view(r.pass) << "\n";
            }
        }
    }

    auto start(function_returns_tag const&, int indent) -> void
    {
        o << pre(indent) << "function returns\n";
    }

    auto start(template_args_tag const&, int indent) -> void
    {
        o << pre(indent) << "template arguments\n";
    }

    auto start(declaration_identifier_tag const&, int indent) -> void
    {
        o << pre(indent) << "declaration identifier\n";
    }

    auto start(next_expression_tag const&, int indent) -> void
    {
        o << pre(indent) << "next expression\n";
    }

    auto start(alias_node const& n, int indent) -> void
    {
        o << pre(indent) << "alias\n";
        switch (n.initializer.index()) {
        break;case alias_node::a_type:
            o << pre(indent+1) << "type\n";
        break;case alias_node::a_namespace:
            o << pre(indent+1) << "namespace\n";
        break;case alias_node::an_object:
            o << pre(indent+1) << "object\n";
        break;default:
            o << pre(indent+1) << "ICE - invalid variant state\n";
        }
    }

    auto start(declaration_node const& n, int indent) -> void
    {
        o << pre(indent) << "declaration [" << &n << "]\n";
        o << pre(indent+1) << "parent: [" << n.parent_declaration << "]\n";
        o << pre(indent+1) << "is_variadic: [" << std::boolalpha << n.is_variadic << "]\n";
        o << pre(indent+1) << "is_constexpr: " << _as<std::string>(n.is_constexpr) << "\n";
        switch (n.type.index()) {
        break;case declaration_node::a_function:
            o << pre(indent+1) << "function\n";
        break;case declaration_node::an_object:
            o << pre(indent+1) << "object\n";
        break;case declaration_node::a_type:
            o << pre(indent+1) << "type\n";
        break;case declaration_node::a_namespace:
            o << pre(indent+1) << "namespace\n";
        break;case declaration_node::an_alias:
            o << pre(indent+1) << "alias\n";
        break;default:
            o << pre(indent+1) << "ICE - invalid variant state\n";
        }
        if (!n.is_default_access()) {
            o << pre(indent+1) << "access: " << to_string(n.access) << "\n";
        }
        if (!n.captures.members.empty()) {
            o << pre(indent+1) << "captures: " << n.captures.members.size() << "\n";
        }
    }

    auto start(parameter_declaration_node const& n, int indent) -> void
    {
        o << pre(indent) << "parameter-declaration\n";

        o << pre(indent+1);
        switch (n.pass) {
        break;case passing_style::in     : o << "in";
        break;case passing_style::copy   : o << "copy";
        break;case passing_style::inout  : o << "inout";
        break;case passing_style::out    : o << "out";
        break;case passing_style::move   : o << "move";
        break;case passing_style::forward: o << "forward";
        break;default: ;
        }

        o << pre(indent+1);
        switch (n.mod) {
        break;case parameter_declaration_node::modifier::implicit  : o << "implicit";
        break;case parameter_declaration_node::modifier::virtual_  : o << "virtual";
        break;case parameter_declaration_node::modifier::override_ : o << "override";
        break;case parameter_declaration_node::modifier::final_    : o << "final";
        break;default: ;
        }
        o << "\n";

        assert( n.declaration );
    }

    auto start(parameter_declaration_list_node const&, int indent) -> void
    {
        o << pre(indent) << "parameter-declaration-list\n";
    }

    auto start(translation_unit_node const&, int indent) -> void
    {
        o << pre(indent) << "translation-unit\n";
    }

    auto start(auto const&, int indent) -> void
    {
        o << pre(indent) << "UNRECOGNIZED -- FIXME\n";
    }

    auto end(auto const&, int) -> void
    {
        //  Ignore other node types
    }
};


auto parser::debug_print(std::ostream& o) const

    -> void
{
    o << "\n\n--- Parse tree\n";

    auto tree_printer = parse_tree_printer{o};
    visit( tree_printer );

    o << "\n\n--- Function body extents\n";

    for (auto const& f : function_body_extents) {
        o << "    " << f.first << "-" << f.last << "\n";
    }
}


}

#endif
