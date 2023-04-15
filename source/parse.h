
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

#ifndef __CPP2_PARSE
#define __CPP2_PARSE

#include "lex.h"
#include <memory>
#include <variant>
#include <iostream>


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
    //if (to_passing_style(tok) != passing_style::invalid) {
    //    return true;
    //}

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
//G     one of  '++' '--' '*' '&' '~' '$'
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

    auto template_args_count() -> int;
    auto get_token() const -> token const*;
    auto position() const -> source_position;
    auto visit(auto& v, int depth) -> void;
};


struct literal_node {
    token const* literal             = {};
    token const* user_defined_suffix = {};

    auto position() const
        -> source_position
    {
        assert (literal);
        return literal->position();
    }

    auto get_token() const
        -> token const*
    {
        return literal;
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        assert (literal);
        literal->visit(v, depth+1);
        if (user_defined_suffix) {
            user_defined_suffix->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};


struct postfix_expression_node;

struct prefix_expression_node
{
    std::vector<token const*> ops;
    std::unique_ptr<postfix_expression_node> expr;

    auto get_postfix_expression_node() const
        -> postfix_expression_node *
    {
        assert(expr);
        return expr.get();
    }

    auto position() const -> source_position;
    auto visit(auto& v, int depth) -> void;
};


template<
    String   Name,
    typename Term
>
struct binary_expression_node
{
    std::unique_ptr<Term> expr;

    struct term
    {
        token const* op;
        std::unique_ptr<Term> expr;
    };
    std::vector<term> terms;

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


struct expression_node
{
    std::unique_ptr<assignment_expression_node> expr;

    // API
    //
    auto get_lhs_rhs_if_simple_assignment() const
        -> assignment_expression_lhs_rhs;

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


struct expression_statement_node
{
    std::unique_ptr<expression_node> expr;
    bool has_semicolon = false;

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

    ~postfix_expression_node()
    {
        if (cap_grp) {
            cap_grp->remove(this);
        }
    }

    //  API
    //
    auto get_first_token_ignoring_this() const
        -> token const*;

    //  Internals
    //
    auto position() const -> source_position
    {
        assert (expr);
        return expr->position();
    }

    auto visit(auto& v, int depth) -> void;
};


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


struct unqualified_id_node
{
    token const* identifier      = {};  // required

    enum active { empty=0, expression, type_id };

    // These are used only if it's a template-id
    source_position open_angle  = {};
    source_position close_angle = {};
    struct term {
        source_position comma;
        std::variant<
            std::monostate,
            std::unique_ptr<expression_node>,
            std::unique_ptr<type_id_node>
        > arg;
    };
    std::vector<term> template_args;

    auto template_args_count()
        -> int
    {
        return std::ssize(template_args);
    }

    auto get_token() const
        -> token const*
    {
        if (template_args.empty()) {
            assert (identifier);
            return identifier;
        }
        // else
        return {};
    }

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

        if (!template_args.empty()) {
            //  Inform the visitor that this is a template args list
            v.start(template_args_tag{}, depth);
            assert(open_angle  != source_position{});
            assert(close_angle != source_position{});
            assert(template_args.front().comma == source_position{});
            for (auto& a : template_args) {
                try_visit<expression>(a.arg, v, depth+1);
                try_visit<type_id   >(a.arg, v, depth+1);
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

    auto template_args_count() const
        -> int
    {
        if (id.index() == unqualified) {
            return std::get<unqualified>(id)->template_args_count();
        }
        // else
        return 0;
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

    auto get_postfix_expression_node() const
        -> postfix_expression_node *
    {
        assert(expr);
        return expr->get_postfix_expression_node();
    }

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


struct id_expression_node
{
    source_position pos;

    enum active { empty=0, qualified, unqualified };
    std::variant<
        std::monostate,
        std::unique_ptr<qualified_id_node>,
        std::unique_ptr<unqualified_id_node>
    > id;

    auto template_args_count()
        -> int
    {
        if (id.index() == unqualified) {
            return std::get<unqualified>(id)->template_args_count();
        }
        // else
        return 0;
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


auto postfix_expression_node::get_first_token_ignoring_this() const
    -> token const*
{
    if (
        expr->get_token()
        && *expr->get_token() == "this"
        && std::ssize(ops) == 1
        && ops[0].op->type() == lexeme::Dot
        )
    {
        return ops[0].id_expr->get_token();
    }
    return expr->get_token();
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

    compound_statement_node(source_position o = source_position{})
        : open_brace{o}
    { }

    auto position() const
        -> source_position
    {
        return open_brace;
    }

    auto visit(auto& v, int depth) -> void;
};


struct selection_statement_node
{
    bool                                     is_constexpr = false;
    token const*                             identifier   = {};
    source_position                          else_pos;
    std::unique_ptr<expression_node>         expression;
    std::unique_ptr<compound_statement_node> true_branch;
    std::unique_ptr<compound_statement_node> false_branch;
    bool                                     has_source_false_branch = false;

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
    std::unique_ptr<compound_statement_node>    statement;          // used for "do" and "while", else null
    std::unique_ptr<expression_node>            range;              // used for "for", else null
    std::unique_ptr<declaration_node>           body;               // used for "for", else null
    bool                                        for_with_in = false;// usse for "for," says whether loop variable is 'in'

    auto get_for_parameter() const
        -> parameter_declaration_node const*;

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

    source_position                             open_bracket;
    token const*                                kind = {};
    std::unique_ptr<id_expression_node>         group;
    std::unique_ptr<logical_or_expression_node> condition;
    token const*                                message = {};

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

        assert(condition);
        condition->visit(v, depth+1);

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


struct parameter_declaration_list_node;

struct statement_node
{
    enum active { expression=0, compound, selection, declaration, return_, iteration, contract, inspect, jump };
    std::variant<
        std::unique_ptr<expression_statement_node>,
        std::unique_ptr<compound_statement_node>,
        std::unique_ptr<selection_statement_node>,
        std::unique_ptr<declaration_node>,
        std::unique_ptr<return_statement_node>,
        std::unique_ptr<iteration_statement_node>,
        std::unique_ptr<contract_node>,
        std::unique_ptr<inspect_expression_node>,
        std::unique_ptr<jump_statement_node>
    > statement;

    bool emitted = false;   // note field used during lowering

    //  API
    //
    auto is_expression () const -> bool { return statement.index() == expression;  }
    auto is_compound   () const -> bool { return statement.index() == compound;    }
    auto is_selection  () const -> bool { return statement.index() == selection;   }
    auto is_declaration() const -> bool { return statement.index() == declaration; }
    auto is_return     () const -> bool { return statement.index() == return_;     }
    auto is_iteration  () const -> bool { return statement.index() == iteration;   }
    auto is_contract   () const -> bool { return statement.index() == contract;    }
    auto is_inspect    () const -> bool { return statement.index() == inspect;     }
    auto is_jump       () const -> bool { return statement.index() == jump;        }

    template<typename Node>
    auto get_if()
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
    try_visit<expression >(statement, v, depth);
    try_visit<compound   >(statement, v, depth);
    try_visit<selection  >(statement, v, depth);
    try_visit<declaration>(statement, v, depth);
    try_visit<return_    >(statement, v, depth);
    try_visit<iteration  >(statement, v, depth);
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

    function_type_node(declaration_node* decl)
        : my_decl{decl}
    { }

    //  API
    //
    auto is_function_with_this() const
        -> bool;

    auto is_virtual_function() const
        -> bool;

    auto make_function_virtual()
        -> bool;

    auto is_constructor() const
        -> bool;

    auto is_constructor_with_that() const
        -> bool;

    auto is_constructor_with_in_that() const
        -> bool;

    auto is_constructor_with_move_that() const
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

    auto has_in_parameter_named(std::string_view s) const
        -> bool
    {
        return has_parameter_with_name_and_pass(s, passing_style::in);
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
        v.end(*this, depth);
    }
};


struct type_node
{
    token const* type;
    std::vector<id_expression_node> metaclass_names;

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
        for (auto& m : metaclass_names) {
            m.visit(v, depth+1);
        }
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


struct declaration_node
{
    //  The capture_group is declared first, because it should outlive
    //  any owned postfix_expressions that could refer to it
    capture_group captures;

    source_position pos;
    std::unique_ptr<unqualified_id_node> identifier;
    token const* access = {};

    enum active : std::uint8_t { a_function, an_object, a_type, a_namespace, an_alias };
    std::variant<
        std::unique_ptr<function_type_node>,
        std::unique_ptr<type_id_node>,
        std::unique_ptr<type_node>,
        std::unique_ptr<namespace_node>,
        std::unique_ptr<alias_node>
    > type;

    std::unique_ptr<parameter_declaration_list_node> template_parameters;
    source_position                                  requires_pos = {};
    std::unique_ptr<expression_node>                 requires_clause_expression;

    source_position                 equal_sign = {};
    std::unique_ptr<statement_node> initializer;

    declaration_node*               parent_declaration = {};

    declaration_node(declaration_node* parent)
        : parent_declaration{parent}
    { }

    //  API
    //
    auto is_public() const
        -> bool
    {
        return access && *access == "public";
    }

    auto is_protected() const
        -> bool
    {
        return access && *access == "protected";
    }

    auto is_private() const
        -> bool
    {
        return access && *access == "private";
    }

    auto is_default_access() const
        -> bool
    {
        return !access;
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

    auto is_global   () const -> bool
        { return !parent_declaration;         }

    auto is_function () const -> bool
        { return type.index() == a_function;  }
    auto is_object   () const -> bool
        { return type.index() == an_object;   }
    auto is_type     () const -> bool
        { return type.index() == a_type;      }
    auto is_namespace() const -> bool
        { return type.index() == a_namespace; }
    auto is_alias() const -> bool
        { return type.index() == an_alias;    }

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
    auto parent_is_polymorphic() const -> bool
        { return  parent_declaration && parent_declaration->is_polymorphic(); }

    enum which {
        functions = 1,
        objects   = 2,
        types     = 4,
        all       = functions|objects|types
    };

    auto get_type_scope_declarations(which w = all) const
        -> std::vector<declaration_node const*>
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

        auto ret = std::vector<declaration_node const*>{};
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
                    (w & functions && decl->is_function())
                    || (w & objects && decl->is_object())
                    || (w & types && decl->is_type())
                    )
                {
                    ret.push_back(decl);
                }
            }
        }

        return ret;
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

    auto make_function_virtual()
        -> bool
    {
        if (auto func = std::get_if<a_function>(&type)) {
            return (*func)->make_function_virtual();
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

    struct declared_that_funcs {
        declaration_node const* out_this_in_that     = {};
        declaration_node const* out_this_move_that   = {};
        declaration_node const* inout_this_in_that   = {};
        declaration_node const* inout_this_move_that = {};
    };

    auto find_declared_that_functions() const
        -> declared_that_funcs
    {
        if (!initializer) {
            return {};
        }

        auto compound_stmt = initializer->get_if<compound_statement_node>();
        assert (compound_stmt);

        auto ret = declared_that_funcs{};
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
            }
        }

        return ret;
    }

    auto find_parent_declared_that_functions() const
        -> declared_that_funcs
    {
        if (parent_is_type()) {
            return parent_declaration->find_declared_that_functions();
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

        if (identifier) {
            identifier->visit(v, depth+1);
        }

        try_visit<a_function >(type, v, depth+1);
        try_visit<an_object  >(type, v, depth+1);
        try_visit<a_type     >(type, v, depth+1);
        try_visit<a_namespace>(type, v, depth+1);
        try_visit<an_alias   >(type, v, depth+1);

        if (initializer) {
            initializer->visit(v, depth+1);
        }

        v.end(*this, depth);
    }
};


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


auto primary_expression_node::template_args_count()
    -> int
{
    if (expr.index() == id_expression) {
        return std::get<id_expression>(expr)->template_args_count();
    }
    // else
    return 0;
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


auto iteration_statement_node::get_for_parameter() const
    -> parameter_declaration_node const*
{
    assert(*identifier == "for");
    auto func = std::get_if<declaration_node::a_function>(&body->type);
    assert(
        func
        && *func
        && std::ssize((**func).parameters->parameters) == 1
    );
    return (**func).parameters->parameters[0].get();
}


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
    if (statement) {
        statement->visit(v, depth+1);
    }
    if (next_expression) {
        next_expression->visit(v, depth+1);
    }
    if (condition) {
        assert(!range && !body);
        condition->visit(v, depth+1);
    }
    else {
        assert(range && body);
        range->visit(v, depth+1);
        body->visit(v, depth+1);
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

    break;case contract: {
        auto const& s = std::get<contract>(statement);
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


//-----------------------------------------------------------------------
//
//  parser: parses a section of Cpp2 code
//
//-----------------------------------------------------------------------
//
class parser
{
    std::vector<error_entry>& errors;

    std::unique_ptr<translation_unit_node> parse_tree;

    //  Keep a stack of current capture groups (contracts/decls still being parsed)
    std::vector<capture_group*> current_capture_groups;

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

    //  Used only for the duration of each parse() call
    //struct parse_state {
        std::vector<token> const* tokens_ = {};
        std::deque<token>* generated_tokens_ = {};
        int pos = 0;
    //};
    //std::vector<parse_state> state_stack;

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
    //  Constructor
    //
    //  errors      error list
    //
    parser(
        std::vector<error_entry>& errors_
    )
        : errors{ errors_ }
        , parse_tree{std::make_unique<translation_unit_node>()}
    {
    }


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
        std::vector<token> const& tokens,
        std::deque<token>&        generated_tokens
    )
        -> bool
    {
        //  Generate parse tree for this section as if a standalone TU
        tokens_ = &tokens;
        generated_tokens_ = &generated_tokens;
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
    //  get_parse_tree
    //
    //  Get the entire parse tree, from the root (translation_unit_node)
    //
    auto get_parse_tree()
        -> translation_unit_node&
    {
        assert (parse_tree);
        return *parse_tree;
    }

    //  Get a set of pointers to just the declarations in the given token map section
    //
    auto get_parse_tree(std::vector<token> const& tokens)
        -> std::vector< declaration_node const* >
    {
        assert (parse_tree);
        assert (!tokens.empty());
        auto first_line = tokens.front().position().lineno;
        auto last_line  = tokens.back().position().lineno;

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
    auto visit(auto& v) -> void
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
        if (include_curr_token) {
            m += std::string(" (at '") + curr().to_string(true) + "')";
        }
        if (
            err_pos == source_position{}
            && peek(0)
            )
        {
            err_pos = peek(0)->position();
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


    //-----------------------------------------------------------------------
    //  Token navigation: Only these functions should access this->token_
    //
    auto curr() const
        -> token const&
    {
        if (done()) {
            throw std::runtime_error("unexpected end of source file");
        }

        return (*tokens_)[pos];
    }

    auto peek(int num) const
        -> token const*
    {
        assert (tokens_);
        if (
            pos + num >= 0
            && pos + num < std::ssize(*tokens_)
            )
        {
            return &(*tokens_)[pos + num];
        }
        return {};
    }

    auto done() const
        -> bool
    {
        assert (tokens_);
        assert (pos <= std::ssize(*tokens_));
        return pos == std::ssize(*tokens_);
    }

    auto next(int num = 1)
        -> void
    {
        assert (tokens_);
        pos = std::min( pos+num, __as<int>(std::ssize(*tokens_)) );
    }


    //-----------------------------------------------------------------------
    //  Parsers for unary expressions
    //

    //G primary-expression:
    //G     inspect-expression
    //G     id-expression
    //G     literal
    //G     '(' expression-list ')'
    //G     '{' expression-list '}'
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
            auto expr_list = expression_list(open_paren, inside_initializer);
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
                && curr().type() != lexeme::Comma
            ) {
                expr_list->inside_initializer = false;
            } 
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
                if (!(*func)->contracts.empty()) {
                    error("an unnamed function at expression scope currently cannot have contracts");
                    next();
                    return {};
                }
                if (
                    peek(-1) && peek(-1)->type() != lexeme::RightBrace  // it is short function syntax
                    && curr().type() != lexeme::LeftParen               // not imediatelly called
                    && curr().type() != lexeme::RightParen              // not as a last argument to function
                    && curr().type() != lexeme::Comma                   // not as first or in-the-middle, function argument
                ) {
                    // this is a fix for a short function syntax that should have double semicolon used
                    // (check comment in expression_statement(bool semicolon_required))
                    // We simulate double semicolon by moving back to single semicolon.
                    next(-1);
                }
            }
            else {
                error("(temporary alpha limitation) an unnamed declaration at expression scope must be a function or an object");
                next();
                return {};
            }

            n->expr = std::move(decl);
            return n;
        }

        return {};
    }


    //G postfix-expression:
    //G     primary-expression
    //G     postfix-expression postfix-operator     [Note: without whitespace before the operator]
    //G     postfix-expression '[' expression-list ']'
    //G     postfix-expression '(' expression-list? ')'
    //G     postfix-expression '.' id-expression
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
                (is_postfix_operator(curr().type())
                    //  Postfix operators must be lexically adjacent
                    && curr().position().lineno == peek(-1)->position().lineno
                    && curr().position().colno == peek(-1)->position().colno + peek(-1)->length()
                )
                || curr().type() == lexeme::LeftBracket
                || curr().type() == lexeme::LeftParen
                || curr().type() == lexeme::Dot
            )
            )
        {
            //  these can't be unary operators if followed by a (, identifier, or literal
            if (
                (
                    curr().type() == lexeme::Multiply
                    || curr().type() == lexeme::Ampersand
                    || curr().type() == lexeme::Tilde
                    )
                && peek(1)
                && (
                    peek(1)->type() == lexeme::LeftParen
                    || peek(1)->type() == lexeme::Identifier
                    || is_literal(peek(1)->type())
                    )
                )
            {
                auto op  = curr().to_string(true);
                auto msg = "postfix unary " + op;
                if      (curr().type() == lexeme::Multiply ) { msg += " (dereference)"         ; }
                else if (curr().type() == lexeme::Ampersand) { msg += " (address-of)"          ; }
                else if (curr().type() == lexeme::Tilde    ) { msg += " (unary bit-complement)"; }
                msg += " cannot be immediately followed by a (, identifier, or literal - add whitespace before "
                    + op + " here if you meant binary " + op;
                if      (curr().type() == lexeme::Multiply ) { msg += " (multiplication)"      ; }
                else if (curr().type() == lexeme::Ampersand) { msg += " (bitwise and)"         ; }
                else if (curr().type() == lexeme::Tilde    ) { msg += " (binarybit-complement)"; }

                error(msg, false);
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

            auto term = postfix_expression_node::term{&curr()};
            next();

            if (term.op->type() == lexeme::LeftBracket)
            {
                term.expr_list = expression_list(term.op);
                if (
                    !term.expr_list
                    || term.expr_list->expressions.empty()
                    )
                {
                    error("subscript expression [ ] must not be empty (if you were trying to name a C-style array type, use 'std::array' instead)");
                    next();
                    return {};
                }
                if (curr().type() != lexeme::RightBracket)
                {
                    error("unexpected text - [ is not properly matched by ]");
                    return {};
                }
                term.expr_list->close_paren = &curr();
                term.op_close = &curr();
                next();
            }
            else if (term.op->type() == lexeme::LeftParen)
            {
                term.expr_list = expression_list(term.op);
                if (!term.expr_list) {
                    error("( is not followed by a valid expression list");
                    return {};
                }
                if (curr().type() != lexeme::RightParen) {
                    error("unexpected text - ( is not properly matched by )");
                    return {};
                }
                term.expr_list->close_paren = &curr();
                term.op_close = &curr();
                next();
            }
            else if (term.op->type() == lexeme::Dot)
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
                next_word = peek(1)->to_string(true);
            }
            error("'this' is not a pointer - write 'this." + next_word + "' instead of 'this->" + next_word + "'");
            return {};
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
        return {};
    }


    //-----------------------------------------------------------------------
    //  Parsers for binary expressions
    //

    //  The general /*binary*/-expression:
    //     /*term*/-expression { { /* operators at this predecence level */ } /*term*/-expression }*
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
                        generated_tokens_->emplace_back( ">>", t.position(), lexeme::RightShift);
                        return &generated_tokens_->back();
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
    auto equality_expression(bool allow_angle_operators = true) 
        -> auto
    {
        return binary_expression<equality_expression_node> (
            [](token const& t){ return t.type() == lexeme::EqualComparison || t.type() == lexeme::NotEqualComparison; },
            [=,this]{ return relational_expression(allow_angle_operators); }
        );
    }

    //G bit-and-expression:
    //G     equality-expression
    //G     bit-and-expression '&' equality-expression
    //G
    auto bit_and_expression(bool allow_angle_operators = true) 
        -> auto
    {
        return binary_expression<bit_and_expression_node> (
            [](token const& t){ return t.type() == lexeme::Ampersand; },
            [=,this]{ return equality_expression(allow_angle_operators); }
        );
    }

    //G bit-xor-expression:
    //G     bit-and-expression
    //G     bit-xor-expression '^' bit-and-expression
    //G
    auto bit_xor_expression(bool allow_angle_operators = true) 
        -> auto
    {
        return binary_expression<bit_xor_expression_node> (
            [](token const& t){ return t.type() == lexeme::Caret; },
            [=,this]{ return bit_and_expression(allow_angle_operators); }
        );
    }

    //G bit-or-expression:
    //G     bit-xor-expression
    //G     bit-or-expression '|' bit-xor-expression
    //G
    auto bit_or_expression(bool allow_angle_operators = true) 
        -> auto
    {
        return binary_expression<bit_or_expression_node> (
            [](token const& t){ return t.type() == lexeme::Pipe; },
            [=,this]{ return bit_xor_expression(allow_angle_operators); }
        );
    }

    //G logical-and-expression:
    //G     bit-or-expression
    //G     logical-and-expression '&&' bit-or-expression
    //G
    auto logical_and_expression(bool allow_angle_operators = true) 
        -> auto
    {
        return binary_expression<logical_and_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalAnd; },
            [=,this]{ return bit_or_expression(allow_angle_operators); }
        );
    }

    //  constant-expression:    // don't need intermediate production, just use:
    //  conditional-expression: // don't need intermediate production, just use:
    //G logical-or-expression:
    //G     logical-and-expression
    //G     logical-or-expression '||' logical-and-expression
    //G
    auto logical_or_expression(bool allow_angle_operators = true) 
        -> auto
    {
        return binary_expression<logical_or_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalOr; },
            [=,this]{ return logical_and_expression(allow_angle_operators); }
        );
    }

    //G assignment-expression:
    //G     logical-or-expression
    //G     assignment-expression assignment-operator logical-or-expression
    //G
    auto assignment_expression(bool allow_angle_operators = true)
        -> std::unique_ptr<assignment_expression_node>
    {
        if (allow_angle_operators)
        {
            return binary_expression<assignment_expression_node> (
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
                        generated_tokens_->emplace_back( ">>=", t.position(), lexeme::RightShiftEq);
                        return &generated_tokens_->back();
                    }
                    return nullptr;
                },
                [=,this]{ return logical_or_expression(allow_angle_operators); }
            );
        }
        else
        {
            return binary_expression<assignment_expression_node> (
                [](token const&, token const&) -> token const* { return nullptr; },
                [=,this]{ return logical_or_expression(allow_angle_operators); }
            );
        }
    }

    //G  expression:                // eliminated condition: - use expression:
    //G     assignment-expression
    //GTODO    try expression
    //G
    auto expression(bool allow_angle_operators = true)
        -> std::unique_ptr<expression_node>
    {
        auto n = std::make_unique<expression_node>();
        if (!(n->expr = assignment_expression(allow_angle_operators))) {
            return {};
        }
        return n;
    }

    //G expression-list:
    //G     parameter-direction? expression
    //G     expression-list ',' parameter-direction? expression
    //G
    auto expression_list(
        token const* open_paren,
        bool inside_initializer = false
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
            if (!n->pc_qualifiers.empty()) {
            error("'*'/'const' type qualifiers must be followed by a type name or '_' wildcard");
            }
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
    //G is-type-constraint
    //G     'is' type-id
    //G
    //G is-value-constraint
    //G     'is' expression
    //G
    //G as-type-cast
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
    //G     template-id
    //GTODO     operator-function-id
    //G
    //G template-id:
    //G     identifier '<' template-argument-list? '>'
    //G
    //G template-argument-list:
    //G     template-argument-list ',' template-argument
    //G
    //G template-argument:
    //G     # note: < > << >> are not allowed in expressions until new ( is opened
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
            )
        {
            return {};
        }

        auto n = std::make_unique<unqualified_id_node>();

        n->identifier = &curr();
        next();

        //  Handle the template-argument-list if there is one
        if (curr().type() == lexeme::Less)
        {
            //  Remember current position, in case this < is isn't a template argument list
            auto start_pos = pos;

            //  And since we'll do this in two places, factor it into a local function
            auto back_out_template_arg_list = [&]{
                //  Aha, this wasn't a template argument list after all,
                //  so back out just that part and return the identifier
                n->open_angle = source_position{};
                n->template_args.clear();
                pos = start_pos;
            };

            n->open_angle = curr().position();
            next();

            auto term = unqualified_id_node::term{};

            do {
                // disallow unparenthesized relational comparisons in template args
                if (auto e = expression(false)) {
                    term.arg = std::move(e);
                }
                else if (auto i = type_id()) {
                    term.arg = std::move(i);
                }
                else {
                    back_out_template_arg_list();
                    return n;
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
                back_out_template_arg_list();
                return n;
            }
            n->close_angle = curr().position();
            next();
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


    //G id-expression
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
            n->literal = &curr();
            next();
            if (curr().type() == lexeme::UserDefinedLiteralSuffix) {
                n->user_defined_suffix = &curr();
                next();
            }
            return n;
        }
        return {};
    }

    //G expression-statement:
    //G     expression ';'
    //G     expression
    //G
    auto expression_statement(bool semicolon_required)
        -> std::unique_ptr<expression_statement_node>
    {
        auto n = std::make_unique<expression_statement_node>();
        if (!(n->expr = expression())) {
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
    //G     'if' 'constexpr'? expression compound-statement
    //G     'if' 'constexpr'? expression compound-statement 'else' compound-statement
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

        if (auto e = expression()) {
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

            if (curr().type() != lexeme::LeftBrace) {
                error("an else branch body must be enclosed with { }");
                return {};
            }

            if (auto s = compound_statement()) {
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
    //G     label? 'do' compound-statement 'while' logical-or-expression next-clause? ';'
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

        //  If the next three tokens are: identifier ':' 'for/while/do', it's a labeled iteration statement
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
            n->statement= std::move(s);
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
            return n;
        }

        //  Handle "do"
        //
        else if (*n->identifier == "do")
        {
            if (!handle_compound_statement  ()) { return {}; }
            if (curr() != "while") {
                error("do loop body must be followed by 'while'");
                return {};
            }
            next();
            if (!handle_logical_expression  ()) { return {}; }
            if (!handle_optional_next_clause()) { return {}; }
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

            if (curr() != "do") {
                error("'for condition' must be followed by 'do'");
                return {};
            }
            next();

            n->body = unnamed_declaration(curr().position());
            auto func = n->body ? std::get_if<declaration_node::a_function>(&n->body->type) : nullptr;
            if (
                !n->body
                || n->body->identifier
                || !func
                || !*func
                || std::ssize((**func).parameters->parameters) != 1
                || (**func).returns.index() != function_type_node::empty
                )
            {
                error("for..do loop body must be an unnamed function taking a single parameter and returning nothing", false);
                return {};
            }
            //  else
            assert(func && *func);
            if ((**func).parameters->parameters.front()->pass == passing_style::in) {
                n->for_with_in = true;
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
    //G alt-name:
    //G     unqualified-id :
    //G
    auto alternative()
        -> std::unique_ptr<alternative_node>
    {
        auto n = std::make_unique<alternative_node>();

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

        if (auto e = expression()) {
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
            error("expected ; at end of jump-statement");
            return {};
        }
        next();

        return n;
    }


    //G statement:
    //G     selection-statement
    //G     inspect-expression
    //G     return-statement
    //G     jump-statement
    //G     iteration-statement
    //G     compound-statement
    //G     declaration
    //G     expression-statement
    //G     contract
    //
    //GTODO     try-block
    //G
    auto statement(
        bool            semicolon_required,
        source_position equal_sign          = source_position{}
    )
        -> std::unique_ptr<statement_node>
    {
        auto n = std::make_unique<statement_node>();

        //  Now handle the rest of the statement

        if (auto s = selection_statement()) {
            n->statement = std::move(s);
            assert (n->is_selection());
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

        else if (auto s = declaration()) {
            n->statement = std::move(s);
            assert (n->is_declaration());
            return n;
        }

        else if (auto s = expression_statement(semicolon_required)) {
            n->statement = std::move(s);
            assert (n->is_expression());
            return n;
        }

        else if (auto s = contract()) {
            if (*s->kind != "assert") {
                error("only 'assert' contracts are allowed at statement scope");
                return {};
            }
            n->statement = std::move(s);
            assert (n->is_contract());
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
        source_position equal_sign = source_position{}
    )
        -> std::unique_ptr<compound_statement_node>
    {
        if (curr().type() != lexeme::LeftBrace) {
            return {};
        }

        auto n = std::make_unique<compound_statement_node>();
        if (peek(1)) {
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
        next();
        auto s = std::unique_ptr<statement_node>();

        while (curr().type() != lexeme::RightBrace) {
            auto s = statement(true);
            if (!s) {
                pos = start_pos;    // backtrack
                return {};
            }
            n->statements.push_back( std::move(s) );
        }

        n->close_brace = curr().position();
        next();
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
        bool is_returns  = false,
        bool is_named    = true,
        bool is_template = true
    )
        -> std::unique_ptr<parameter_declaration_node>
    {
        auto n = std::make_unique<parameter_declaration_node>();
        n->pass = is_returns ? passing_style::out : passing_style::in;
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
        if (!(n->declaration = declaration(false, true, is_template))) {
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
            )
        {
            switch (n->pass) {
            break;case passing_style::in:
                error( "an 'in' parameter is always const, 'const' isn't needed and isn't allowed", false );
            break;case passing_style::inout:
                error( "an 'inout' parameter can't be const, if you do want it to be const then use 'in' instead", false );
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
            && n->declaration->initializer
            )
        {
            error("Cpp2 is currently exploring the path of not allowing default arguments - use overloading instead", false);
            return {};
        }

        return n;
    }


    //G parameter-declaration-list
    //G     '(' parameter-declaration-seq? ')'
    //G
    //G parameter-declaration-seq:
    //G     parameter-declaration
    //G     parameter-declaration-seq ',' parameter-declaration
    //G
    auto parameter_declaration_list(
        bool is_returns    = false,
        bool is_named      = true,
        bool is_template   = false,
        bool is_type_scope = false
    )
        -> std::unique_ptr<parameter_declaration_list_node>
    {
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

        while ((param = parameter_declaration(is_returns, is_named, is_template)) != nullptr)
        {
            if (param->declaration->has_name("this")) {
                if (
                    !n->parameters.empty()
                    || !is_type_scope
                    )
                {
                    error("'this' must be the first parameter of a type-scope function", false);
                }
            }

            if (param->declaration->has_name("that")) {
                if (
                    std::ssize(n->parameters) != 1
                    || !n->parameters.front()->has_name("this")
                    || !is_type_scope
                    )
                {
                    error("'that' must be the second parameter of a type-scope function (after the initial 'this' parameter)", false);
                }
            }

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
            else if (curr().type() != lexeme::Comma) {
                error("expected , in parameter list", true, {}, true);
                return {};
            }
            next();
        }

        if (curr().type() != closer) {
            error("invalid parameter list", true, {}, true);
            next();
            return {};
        }

        n->close_paren = &curr();
        next();
        return n;
    }


    //G contract:
    //G     '[' '[' contract-kind id-expression? ':' logical-or-expression ']' ']'
    //G     '[' '[' contract-kind id-expression? ':' logical-or-expression ',' string-literal ']' ']'
    //G
    //G contract-kind: one of
    //G     'pre' 'post' 'assert'
    //G
    auto contract()
        -> std::unique_ptr<contract_node>
    {
        //  Note: For now I'm using [[ ]] mainly so that existing Cpp1 syntax highlighters
        //        don't get confused... I initially implemented single [ ], but then
        //        my editor's default Cpp1 highlighter didn't colorize the following
        //        multiline // comment correctly as a comment

        //  If there's no [ [ then this isn't a contract
        if (
            curr().type() != lexeme::LeftBracket
            || !peek(1)
            || peek(1)->type() != lexeme::LeftBracket
            )
        {
            return {};
        }

        auto n = std::make_unique<contract_node>(curr().position());
        auto guard = capture_groups_stack_guard(this, &n->captures);
        next();
        next();

        if (
            curr() != "pre"
            && curr() != "post"
            && curr() != "assert"
            )
        {
            error("[ begins a contract and must be followed by 'pre', 'post', or 'assert'");
            return {};
        }
        n->kind = &curr();
        next();

        if (auto id = id_expression()) {
            n->group = std::move(id);
        }

        if (curr().type() != lexeme::Colon) {
            error("expected : before the contract condition");
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
            if (curr().type() != lexeme::StringLiteral) {
                error("expected contract message string");
                return {};
            }
            n->message = &curr();
            next();
        }

        if (
            curr().type() != lexeme::RightBracket
            || !peek(1)
            || peek(1)->type() != lexeme::RightBracket
            )
        {
            error("expected ]] at the end of the contract");
            return {};
        }
        next();
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
    //G     '->' type-id
    //G     '->' parameter_declaration_list
    //G
    //G contract-seq:
    //G     contract
    //G     contract-seq contract
    //G
    auto function_type(
        declaration_node* my_decl,
        bool              is_named      = true,
        bool              is_type_scope = false
        )
        -> std::unique_ptr<function_type_node>
    {
        auto n = std::make_unique<function_type_node>( my_decl );

        //  Parameters
        auto parameters = parameter_declaration_list(false, is_named, false, is_type_scope);
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
            n->throws = true;
            next();
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
                    error( + "'' must be followed by a type-id");
                }
            }
            else if (auto t = type_id()) {
                if (
                    t->get_token()
                    && t->get_token()->to_string(true) == "auto"
                    )
                {
                    auto name = std::string{"v"};
                    if (my_decl && my_decl->name()) {
                        name = my_decl->name()->to_string(true);
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
            else if (auto returns_list = parameter_declaration_list(true, is_named)) {
                if (std::ssize(returns_list->parameters) < 1) {
                    error("an explicit return value list cannot be empty");
                    return {};
                }
                n->returns = std::move(returns_list);
                assert(n->returns.index() == function_type_node::list);
            }
            else {
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


    //G meta-constraints:
    //G     'is' id-expression
    //G     meta-constraints ',' id-expression
    //G
    auto a_type()
        -> std::unique_ptr<type_node>
    {
        auto n = std::make_unique<type_node>();

        //  "type" introducer
        if (curr() != "type") {
            return {};
        }

        n->type = &curr();
        next();

        return n;
    }


    //G unnamed-declaration:
    //G     ':' template-parameter-declaration-list? function-type requires-clause? '=' statement
    //G     ':' template-parameter-declaration-list? type-id? requires-clause? '=' statement
    //G     ':' template-parameter-declaration-list? type-id
    //G     ':' template-parameter-declaration-list? 'type' meta-constraints? requires-clause? '=' statement
    //G     ':' 'namespace' '=' statement
    //G
    //G requires-clause:
    //G     'requires' expression
    //G
    //G template-parameter-declaration-list
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
        token const*                         access                = {}
    )
        -> std::unique_ptr<declaration_node>
    {
        auto n = std::make_unique<declaration_node>( current_declarations.back() );
        n->pos = start;

        n->identifier = std::move(id);
        n->access     = access;

        //  For a template parameter, ':' is not required and
        //  we default to ': type'
        if (
            is_template_parameter
            && curr().type() != lexeme::Colon
            )
        {
            //  So invent the "type" token
            generated_text.push_back("type");
            generated_tokens_->push_back({
                generated_text.back().c_str(),
                std::ssize(generated_text.back()),
                start,
                lexeme::Identifier
            });

            //  So we can create the type_node

            auto t = std::make_unique<type_node>();
            t->type = &generated_tokens_->back();

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
            generated_tokens_->push_back({
                generated_text.back().c_str(),
                std::ssize(generated_text.back()),
                start,
                lexeme::Identifier
            });

            //  So we can create the typeid_id_node and its unqualified_id_node

            auto gen_id = std::make_unique<unqualified_id_node>();
            gen_id->identifier = &generated_tokens_->back();

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
        if (auto t = a_type()) {
            if (
                is_parameter
                && !is_template_parameter
                )
            {
                error("a normal parameter cannot be a 'type' - did you mean to put this in a < > template parameter list?");
                return {};
            }
            n->type = std::move(t);
            assert (n->is_type());
        }
        
        //  Or a function type, declaring a function - and tell the function whether it's in a user-defined type
        else if (auto t = function_type(n.get(), named, n->parent_is_type())) {
            n->type = std::move(t);
            assert (n->is_function());
        }

        //  Or a namespace
        else if (curr() == "namespace") {
            n->type = std::make_unique<namespace_node>( &curr() );
            assert (n->type.index() == declaration_node::a_namespace);
            next();
        }

        //  Or just a type-id, declaring a non-pointer object
        else if (auto t = type_id()) {
            if (
                t->get_token()
                && t->get_token()->to_string(true) == "auto"
                )
            {
                auto name = std::string{"v"};
                if (n->name()) {
                    name = n->name()->to_string(true);
                }
                errors.emplace_back(
                    curr().position(),
                    "to define a variable " + name + " with deduced type, write '" + name + " := /* initializer */;'"
                );
                return {};
            }

            n->type = std::move(t);
            assert (n->is_object());

            if (curr().type() == lexeme::LeftBracket) {
                error("C-style array types are not allowed, use std::array instead");
                return {};
            }
        }

        //  Or nothing, declaring an object of deduced type,
        //  which we'll represent using an empty type-id
        else {
            if (n->parent_is_type()) {
                error("a type scope variable must have a declared type");
                return {};
            }

            n->type = std::make_unique<type_id_node>();
            assert (n->is_object());
            deduced_type = true;
        }

        //  Next is optionally a requires clause
        if (curr() == "requires") {
            n->requires_pos = curr().position();
            next();
            auto e = expression();
            if (!e) {
                error("'requires' must be followed by an expression");
                return {};
            }
            n->requires_clause_expression = std::move(e);
        }

        //  Next is optionally = followed by an initializer

        //  If there is no =
        if (curr().type() != lexeme::Assignment)
        {
            if (deduced_type) {
                error("a variable with a deduced type must have an = initializer");
                return {};
            }

            if (
                n->is_function()
                && !n->is_virtual_function()
                )
            {
                error("missing = before nonvirtual function body");
                return {};
            }

            if (
                n->is_type()
                && !is_template_parameter
                )
            {
                error("a user-defined type must have an = initializer");
                return {};
            }

            //  Then there may be a semicolon
            //  If there is a semicolon, eat it
            if (curr().type() == lexeme::Semicolon) {
                next();
            }
            // But if there isn't one and it was required, diagnose an error
            else if (semicolon_required) {
                error("missing semicolon at end of declaration", true, {}, true);
                return {};
            }
        }

        //  There was an =, so eat it and continue
        else {
            n->equal_sign = curr().position();
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
                if (peek(1)->type() == lexeme::Ampersand) {
                    type->address_of = &curr();
                }
                // object initialized by (potentially multiple) dereference of the curr() object 
                else if (peek(1)->type() == lexeme::Multiply) {
                    type->dereference_of = &curr();
                    for (int i = 1; peek(i)->type() == lexeme::Multiply; ++i)
                        type->dereference_cnt += 1;
                }
                else if (
                    // object initialized by the result of the function call (and it is not unnamed function)
                    (peek(1)->type() == lexeme::LeftParen && curr().type() != lexeme::Colon)
                    || curr().type() == lexeme::Identifier // or by the object (variable that the type need to be checked)
                ) {
                    type->suspicious_initialization = &curr();
                }
            }

            if (!(n->initializer = statement(semicolon_required, n->equal_sign))) {
                error("ill-formed initializer", true, {}, true);
                next();
                return {};
            }
        }

        //  If this is an object with an initializer, the initializer must be an expression
        if (
            n->is_object()
            && n->initializer
            && !n->initializer->is_expression()
            )
        {
            error(
                "an object initializer must be an expression",
                false,
                {},
                true
            );
            return {};
        }

        //  If this is a user-defined type with an initializer, the initializer must be a compound expression
        if (
            n->is_type()
            && n->initializer
            && !n->initializer->is_compound()
            )
        {
            error(
                "a user-defined type initializer must be a compound-expression consisting of declarations",
                false,
                {},
                true
            );
            return {};
        }

        //  If this is a namespace, it must have an initializer, which must be a compound expression
        if (
            n->is_namespace()
            && (
                !n->initializer
                || !n->initializer->is_compound()
                )
            )
        {
            error(
                "a namespace must be = initialized with a { } body containing declarations",
                false,
                n->initializer->position(),
                true
            );
            return {};
        }

        //  If this is a function, its body must be an expression-statement or
        //  a compound-statement
        if (
            n->is_function()
            && n->initializer
            && n->initializer->is_return()
            )
        {
            error(
                "a function with a single-expression body doesn't need to say 'return' - either omit 'return' or write a full { }-enclosed function body",
                false,
                n->initializer->position()
            );
            return {};
        }

        //  If this is an implicit constructor, it must have two parameters
        if (n->is_constructor())
        {
            auto& params = std::get<declaration_node::a_function>(n->type)->parameters;
            assert(params->ssize() > 0);
            if (
                params->parameters[0]->is_implicit()
                && params->ssize() > 2
                )
            {
                error(
                    "an 'implicit' constructor must have exactly one additional parameter besides 'this'",
                    false,
                    params->parameters[2]->position()
                );
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
                generated_tokens_->emplace_back( "return", last_pos, lexeme::Keyword);

                auto ret = std::make_unique<return_statement_node>();
                ret->identifier = &generated_tokens_->back();

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


    //G alias
    //G     ':' template-parameter-declaration-list? 'type' '==' type-id ';'
    //G     ':' 'namespace' '==' qualified-id ';'
    //G     ':' template-parameter-declaration-list? '_'? '==' expression ';'
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

        if (
            curr() != "type"
            && curr() != "namespace"
            && curr() != "_"
            && curr().type() != lexeme::EqualComparison
            )
        {
            pos = start_pos;    // backtrack
            return {};
        }

        //  Pause parsing to check for some semantic diagnostics

        if (
            n->template_parameters
            && curr() == "namespace"
            )
        {
            errors.emplace_back(
                curr().position(),
                "a namespace cannot have template parameters"
            );
            return {};
        }

        //  Resume parsing

        auto a = std::make_unique<alias_node>( &curr() );
        next();

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
            && *a->type != "type"
            )
        {
            errors.emplace_back(
                curr().position(),
                "only a type alias may appear in a type scope - not a namespace or object alias"
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
            *a->type == "_"
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
    //G     access-specifier? identifier unnamed-declaration
    //G     access-specifier? identifier alias
    //G
    //G access-specifier:
    //G     public
    //G     protected
    //G     private
    //G
    auto declaration(
        bool semicolon_required    = true,
        bool is_parameter          = false,
        bool is_template_parameter = false
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
            token const* access = {};
            if (
                curr() == "public"
                || curr() == "protected"
                || curr() == "private"
                )
            {
                access = &curr();
                next();

                if (curr().type() == lexeme::Colon)
                {
                    errors.emplace_back(
                        curr().position(),
                        "':' is not allowed after " + access->to_string(true)
                    );
                    return {};
                }
            }

            auto id = unqualified_id();
            if (!id) {
                return {};
            }

            //  Provide some useful Cpp1->Cpp2 migration diagnostics for common mistakes
            //
            if (
                id->get_token()
                && *id->get_token() == "auto"
                )
            {
                auto name = std::string{"v"};
                if (peek(0) && peek(0)->type() == lexeme::Identifier) {
                    name = peek(0)->to_string(true);
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
                )
            {
                auto name = std::string{"N"};
                if (peek(0)) {
                    name = peek(0)->to_string(true);
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
                )
            {
                auto name = std::string{"C"};
                if (peek(0)) {
                    name = peek(0)->to_string(true);
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
                access
            );
            if (!n) {
                pos = start_pos;    // backtrack
                return {};
            }
        }

        //  Note: Do this after trying to parse this as a declaration, for parse backtracking

        if (
            !is_parameter
            && n->is_object()
            && n->has_wildcard_type()
            && n->parent_is_namespace()
            )
        {
            errors.emplace_back(
                n->identifier->position(),
                "namespace scope objects must have a concrete type, not a deduced type"
            );
            return {};
        }

        if (
            n->has_name("_")
            && !n->is_object()
            && !n->is_namespace()
            )
        {
            errors.emplace_back(
                n->identifier->position(),
                "'_' (wildcard) may not be the name of a function or type - it may only be used as the name of an anonymous object or anonymous namespace"
            );
            return {};
        }

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

        if (*n->identifier->identifier == "this")
        {
            if (
                is_template_parameter
                || (
                    !is_parameter
                    && !n->parent_is_type()
                    )
                )
            {
                errors.emplace_back(
                    n->identifier->position(),
                    "'this' may only be declared as an ordinary function parameter or type-scope (base) object"
                );
                return {};
            }

            if (
                !is_parameter
                && n->access
                && *n->access != "public"
                )
            {
                errors.emplace_back(
                    n->access->position(),
                    "a base type must be public (the default)"
                );
                return {};
            }

            if (
                !is_parameter
                && n->has_wildcard_type()
                )
            {
                errors.emplace_back(
                    n->position(),
                    "a base type must be a specific type, not a deduced or '_' wildcard type"
                );
                return {};
            }
        }

        if (
            n->access
            && !n->parent_is_type()
            )
        {
            errors.emplace_back(
                n->access->position(),
                "an access-specifier is only allowed on a type-scope (member) declaration"
            );
            return {};
        }

        if (n->is_constructor())
        {
            auto& func = std::get<declaration_node::a_function>(n->type);
            assert(
                func->parameters->ssize() > 0
                && (*func->parameters)[0]->has_name("this")
            );
            if ((*func->parameters)[0]->is_polymorphic()) {
                error( "a constructor may not be declared virtual, override, or final", false );
            }
        }

        if (
            n->is_function()
            && n->parent_is_function()
            )
        {
            assert (n->identifier->get_token());
            auto name = n->identifier->get_token()->to_string(true);
            errors.emplace_back(
                curr().position(),
                "(temporary alpha limitation) local functions like '" + name + ": (/*params*/) = {/*body*/}' are not currently supported - write a local variable initialized with an unnamed function like '" + name + " := :(/*params*/) = {/*body*/};' instead (add ':=' and ';')"
            );
            return {};
        }

        //  If this is the main function, it must be 'main: ()' or 'main: (args)'
        if (
            n->identifier
            && n->has_name("main")
            && n->is_function()
            && n->is_global()
            )
        {
            auto& func = std::get<declaration_node::a_function>(n->type);

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
                return {};
            }
        }

        if (n->has_name("operator="))
        {
            if (!n->is_function())
            {
                errors.emplace_back(
                    n->position(),
                    "'operator=' must be a function"
                );
                return {};
            }
            auto& func = std::get<declaration_node::a_function>(n->type);

            if (func->has_declared_return_type())
            {
                errors.emplace_back(
                    func->parameters->parameters[0]->position(),
                    "'operator=' may not have a declared return type"
                );
                return {};
            }

            if (func->parameters->ssize() == 0)
            {
                error( "an operator= function must have a parameter", false );
            }
            else if (
                (*func->parameters)[0]->has_name("this")
                && (*func->parameters)[0]->pass != passing_style::inout
                && (*func->parameters)[0]->pass != passing_style::out
                && (*func->parameters)[0]->pass != passing_style::move
                )
            {
                error( "an operator= function's 'this' parameter must be inout, out, or move", false );
                return {};
            }

            if (
                func->parameters->ssize() > 1
                && (*func->parameters)[1]->has_name("that")
                && (*func->parameters)[1]->pass != passing_style::in
                && (*func->parameters)[1]->pass != passing_style::move
                )
            {
                error( "an operator= function's 'that' parameter must be in or move", false );
                return {};
            }

            if (
                func->parameters->ssize() > 1
                && (*func->parameters)[0]->has_name("this")
                && (*func->parameters)[0]->pass == passing_style::move
                )
            {
                error( "a destructor may not have other parameters besides 'this'", false );
                return {};
            }
        }

        for (auto& decl : n->get_type_scope_declarations())
        {
            if (decl->has_name("that"))
            {
                error( "'that' may not be used as a type scope name", false );
                return {};
            }
        }

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
    auto debug_print(std::ostream& o)
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

    printing_visitor(std::ostream& out) : o{out} { }

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
            as<size_t>( std::min( indent*indent_spaces, __as<int>(std::ssize(indent_str))) )
        };
    }
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
        o << pre(indent) << n.to_string() << "\n";
    }

    auto start(literal_node const&, int indent) -> void
    {
        o << pre(indent) << "literal" << "\n";
    }

    auto start(expression_node const&, int indent) -> void
    {
        o << pre(indent) << "expression\n";
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

    auto start(expression_statement_node const&, int indent) -> void
    {
        o << pre(indent) << "expression-statement\n";
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
        o << pre(indent+1) << "is_constexpr: " << __as<std::string>(n.is_constexpr) << "\n";
    }

    auto start(alternative_node const&, int indent) -> void
    {
        o << pre(indent) << "alternative\n";
    }

    auto start(jump_statement_node const&, int indent) -> void
    {
        o << pre(indent) << "jump\n";
    }

    auto start(inspect_expression_node const& n, int indent) -> void
    {
        o << pre(indent) << "inspect-expression\n";
        o << pre(indent+1) << "is_constexpr: " << __as<std::string>(n.is_constexpr) << "\n";
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
        if (n.message) {
            o << pre(indent+1) << "message: " << std::string_view(*n.message) << "\n";
        }
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
        o << pre(indent+1) << "throws: " << __as<std::string>(n.throws) << "\n";
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

    auto start(declaration_node const& n, int indent) -> void
    {
        o << pre(indent) << "declaration [" << &n << "]\n";
        o << pre(indent+1) << "parent: [" << n.parent_declaration << "]\n";
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
        if (n.access) {
            o << pre(indent+1) << "access: " << *n.access << "\n";
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


auto parser::debug_print(std::ostream& o)

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
