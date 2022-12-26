
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
//G     one of  not
//G
auto is_prefix_operator(lexeme l) -> bool
{
    switch (l) {
    break;case lexeme::Not:
          case lexeme::Minus:
          case lexeme::Plus:
        return true;
    break;default:
        return false;
    }
}


//G postfix-operator:
//G     one of  ++  --  *  &  ~  $
//G
auto is_postfix_operator(lexeme l)  -> bool
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
//G     one of  = *= /= %= += -= >>= <<=
//G
auto is_assignment_operator(lexeme l) -> bool
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
//  try_emit
//
//  Helper to visit whatever is in a variant where each
//  alternative is a smart pointer
//
template <int I>
auto try_visit(auto& variant, auto& visitor, int depth) -> void {
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

struct primary_expression_node
{
    enum active { empty=0, identifier, expression_list, id_expression, declaration, inspect };
    std::variant<
        std::monostate,
        token const*,
        std::unique_ptr<expression_list_node>,
        std::unique_ptr<id_expression_node>,
        std::unique_ptr<declaration_node>,
        std::unique_ptr<inspect_expression_node>
    > expr;

    auto template_args_count() -> int;
    auto get_token() -> token const*;
    auto position() const -> source_position;
    auto visit(auto& v, int depth) -> void;
};


struct postfix_expression_node;

struct prefix_expression_node
{
    std::vector<token const*> ops;
    std::unique_ptr<postfix_expression_node> expr;

    auto get_postfix_expression_node() const -> postfix_expression_node const* {
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
    auto get_postfix_expression_node() const -> postfix_expression_node const* {
        assert(expr);
        return expr->get_postfix_expression_node();
    }

    //  Get first right-hand postfix-expression, if there is one
    auto get_second_postfix_expression_node() const -> postfix_expression_node const* {
        if (!terms.empty()) {
            assert(terms.front().expr);
            return terms.front().expr->get_postfix_expression_node();
        }
        //  else
        return {};
    }

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
        for (auto const& x : terms) {
            assert (x.op);
            v.start(*x.op, depth+1);
            assert (x.expr);
            x.expr->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};

using is_as_expression_node          = binary_expression_node< "is-as"          , prefix_expression_node         >;
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


struct expression_node
{
    std::unique_ptr<assignment_expression_node> expr;

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

enum class passing_style { in=0, copy, inout, out, move, forward };
auto to_string_view(passing_style pass) -> std::string_view {
    switch (pass) {
    break;case passing_style::in     : return "in";
    break;case passing_style::copy   : return "copy";
    break;case passing_style::inout  : return "inout";
    break;case passing_style::out    : return "out";
    break;case passing_style::move   : return "move";
    break;case passing_style::forward: return "forward";
    break;default:                     return "INVALID passing_style";
    }
}

struct expression_list_node
{
    source_position open_paren  = {};
    source_position close_paren = {};
    bool inside_initializer     = false;

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

    auto position() const -> source_position
    {
        //  Make sure this got set
        assert (open_paren != source_position());
        return open_paren;
    }

    auto visit(auto& v, int depth) -> void
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


struct capture {
    postfix_expression_node* capture_expr;
    std::string              str = {};
    auto operator==(postfix_expression_node* p) { return capture_expr == p; }
};

struct capture_group {
    std::vector<capture> members;

    auto add(postfix_expression_node* p) -> void {
        members.push_back({p});
    }

    auto remove(postfix_expression_node* p) -> void;

    ~capture_group();
};

struct postfix_expression_node
{
    std::unique_ptr<primary_expression_node> expr;

    struct term
    {
        token const* op;

        //  This is used if *op is . - can be null
        std::unique_ptr<id_expression_node> id_expr = nullptr;

        //  These are used if *op is [ or ( - can be null
        std::unique_ptr<expression_list_node> expr_list = nullptr;
        token const* op_close = nullptr;;
    };
    std::vector<term> ops;
    capture_group* cap_grp = {};

    ~postfix_expression_node() {
        if (cap_grp) {
            cap_grp->remove(this);
        }
    }

    auto position() const -> source_position
    {
        assert (expr);
        return expr->position();
    }

    auto visit(auto& v, int depth) -> void;
};

auto capture_group::remove(postfix_expression_node* p) -> void {
    p->cap_grp = nullptr;
    auto old_size = members.size();
    std::erase(members, p);
    assert (members.size() == old_size-1);
}

capture_group::~capture_group() {
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

auto prefix_expression_node::position() const -> source_position
{
    if (std::ssize(ops) > 0) {
        return ops.front()->position();
    }
    assert (expr);
    return expr->position();
}

auto prefix_expression_node::visit(auto& v, int depth) -> void
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


struct template_args_tag { };

struct unqualified_id_node
{
    token const* identifier      = {};  // required

    enum active { empty=0, expression, id_expression };

    // These are used only if it's a template-id
    source_position open_angle  = {};
    source_position close_angle = {};
    struct term {
        source_position comma;
        std::variant<
            std::monostate,
            std::unique_ptr<expression_node>,
            std::unique_ptr<id_expression_node>
        > arg;
    };
    std::vector<term> template_args;

    auto template_args_count() -> int {
        return std::ssize(template_args);
    }

    auto get_token() -> token const* {
        if (template_args.empty()) {
            assert (identifier);
            return identifier;
        }
        // else
        return {};
    }

    auto position() const -> source_position
    {
        assert (identifier);
        return identifier->position();
    }

    auto visit(auto& v, int depth) -> void
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
                try_visit<   expression>(a.arg, v, depth+1);
                try_visit<id_expression>(a.arg, v, depth+1);
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
        std::unique_ptr<unqualified_id_node> id = nullptr;

        term( token const* o ) : scope_op{o} { }
    };
    std::vector<term> ids;

    auto position() const -> source_position
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

    auto visit(auto& v, int depth) -> void
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

    token const* const_qualifier = {};  // optional

    enum active { empty=0, qualified, unqualified };
    std::variant<
        std::monostate,
        std::unique_ptr<qualified_id_node>,
        std::unique_ptr<unqualified_id_node>
    > id;

    auto template_args_count() -> int {
        if (id.index() == unqualified) {
            return std::get<unqualified>(id)->template_args_count();
        }
        // else
        return 0;
    }

    auto get_token() -> token const* {
        if (id.index() == unqualified) {
            return std::get<unqualified>(id)->get_token();
        }
        // else
        return {};
    }

    auto position() const -> source_position
    {
        return pos;
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        if (const_qualifier) {
            v.start(*const_qualifier, depth+1);
        }
        try_visit<qualified  >(id, v, depth);
        try_visit<unqualified>(id, v, depth);
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

    auto template_args_count() -> int {
        if (id.index() == unqualified) {
            return std::get<unqualified>(id)->template_args_count();
        }
        // else
        return 0;
    }

    auto get_token() -> token const* {
        if (id.index() == unqualified) {
            return std::get<unqualified>(id)->get_token();
        }
        // else
        return {};
    }

    auto position() const -> source_position
    {
        return pos;
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        try_visit<qualified  >(id, v, depth);
        try_visit<unqualified>(id, v, depth);
        v.end(*this, depth);
    }
};

auto postfix_expression_node::visit(auto& v, int depth) -> void
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

    compound_statement_node(source_position o = source_position{}) : open_brace{o} { }

    auto position() const -> source_position
    {
        return open_brace;
    }

    auto visit(auto& v, int depth) -> void;
};

struct selection_statement_node
{
    bool                                     is_constexpr = false;
    token const*                             identifier;
    source_position                          else_pos;
    std::unique_ptr<expression_node>         expression;
    std::unique_ptr<compound_statement_node> true_branch;
    std::unique_ptr<compound_statement_node> false_branch;
    bool                                     has_source_false_branch = false;

    auto position() const -> source_position
    {
        assert (identifier);
        return identifier->position();
    }

    auto visit(auto& v, int depth) -> void
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
    token const*                                identifier;
    std::unique_ptr<assignment_expression_node> next_expression;    // if used, else null
    std::unique_ptr<logical_or_expression_node> condition;          // used for "do" and "while", else null
    std::unique_ptr<compound_statement_node>    statement;          // used for "do" and "while", else null
    std::unique_ptr<expression_node>            range;              // used for "for", else null
    std::unique_ptr<declaration_node>           body;               // used for "for", else null

    auto get_for_parameter() const -> parameter_declaration_node const*;

    auto position() const -> source_position
    {
        assert(identifier);
        return identifier->position();
    }

    auto visit(auto& v, int depth) -> void;
};


struct return_statement_node
{
    token const*                     identifier;
    std::unique_ptr<expression_node> expression;

    auto position() const -> source_position
    {
        assert(identifier);
        return identifier->position();
    }

    auto visit(auto& v, int depth) -> void
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
    token const*                         is_as_keyword;

    //  One of these will be used
    std::unique_ptr<type_id_node>            type_id;
    std::unique_ptr<postfix_expression_node> value;

    source_position                      equal_sign;
    std::unique_ptr<statement_node>      statement;

    auto position() const -> source_position
    {
        assert(is_as_keyword);
        return is_as_keyword->position();
    }

    auto visit(auto& v, int depth) -> void;
};


struct inspect_expression_node
{
    bool                                     is_constexpr = false;
    token const*                             identifier;
    std::unique_ptr<expression_node>         expression;
    std::unique_ptr<type_id_node>            result_type;
    source_position                          open_brace;
    source_position                          close_brace;

    std::vector<std::unique_ptr<alternative_node>> alternatives;

    auto position() const -> source_position
    {
        assert(identifier);
        return identifier->position();
    }

    auto visit(auto& v, int depth) -> void
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

    contract_node( source_position pos ) : open_bracket{pos} { }

    auto position() const -> source_position
    {
        return open_bracket;
    }

    auto visit(auto& v, int depth) -> void
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


struct parameter_declaration_list_node;
struct statement_node
{
    enum active { expression=0, compound, selection, declaration, return_, iteration, contract, inspect };
    std::variant<
        std::unique_ptr<expression_statement_node>,
        std::unique_ptr<compound_statement_node>,
        std::unique_ptr<selection_statement_node>,
        std::unique_ptr<declaration_node>,
        std::unique_ptr<return_statement_node>,
        std::unique_ptr<iteration_statement_node>,
        std::unique_ptr<contract_node>,
        std::unique_ptr<inspect_expression_node>
    > statement;

    auto position() const -> source_position;

    auto visit(auto& v, int depth) -> void;
};

auto alternative_node::visit(auto& v, int depth) -> void
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

auto compound_statement_node::visit(auto& v, int depth) -> void
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
    source_position pos;
    passing_style pass = passing_style::in;

    enum class modifier { none=0, implicit, virtual_, override_, final_ };
    modifier mod = modifier::none;

    std::unique_ptr<declaration_node> declaration;

    auto position() const -> source_position;

    auto visit(auto& v, int depth) -> void;
};


struct parameter_declaration_list_node
{
    source_position pos_open_paren;
    source_position pos_close_paren;

    std::vector<std::unique_ptr<parameter_declaration_node>> parameters;

    auto position() const -> source_position
    {
        return pos_open_paren;
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        for (auto const& x : parameters) {
            assert(x);
            x->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};

auto statement_node::visit(auto& v, int depth) -> void
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
    v.end(*this, depth);
}


struct function_returns_tag { };

struct function_type_node
{
    std::unique_ptr<parameter_declaration_list_node> parameters;
    bool throws = false;

    enum active { empty = 0, id, list };
    std::variant<
        std::monostate,
        std::unique_ptr<type_id_node>,
        std::unique_ptr<parameter_declaration_list_node>
    > returns;

    std::vector<std::unique_ptr<contract_node>> contracts;

    auto position() const -> source_position
    {
        assert (parameters);
        return parameters->position();
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        assert(parameters);
        parameters->visit(v, depth+1);

        if (returns.index() == id) {
            auto& r = std::get<id>(returns);
            assert(r);
            r->visit(v, depth+1);
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


struct declaration_node
{
    //  Declared first, because it should outlive any owned
    //  postfix_expressions that could refer to it
    capture_group captures;

    source_position pos;
    std::unique_ptr<unqualified_id_node> identifier;

    token const* pointer_declarator = nullptr;

    enum active : std::uint8_t { function, object };
    std::variant<
        std::unique_ptr<function_type_node>,
        std::unique_ptr<type_id_node>
    > type;

    source_position                 equal_sign = {};
    source_position                 decl_end   = {};
    std::unique_ptr<statement_node> initializer;

    declaration_node*               parent_scope = nullptr;

    declaration_node(declaration_node* parent) : parent_scope{parent} { }

    //  Shorthand for common query
    //
    auto is(active a) const
    {
        return type.index() == a;
    }

    auto position() const -> source_position
    {
        if (identifier) {
            return identifier->position();
        }
        return pos;
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);

        if (identifier) {
            identifier->visit(v, depth+1);
        }

        try_visit<function>(type, v, depth+1);
        try_visit<object  >(type, v, depth+1);

        if (initializer) {
            initializer->visit(v, depth+1);
        }

        v.end(*this, depth);
    }
};

auto primary_expression_node::template_args_count() -> int {
    if (expr.index() == id_expression) {
        return std::get<id_expression>(expr)->template_args_count();
    }
    // else
    return 0;
}

auto primary_expression_node::get_token() -> token const*
{
    if (expr.index() == identifier) {
        return std::get<identifier>(expr);
    }
    else if (expr.index() == id_expression) {
        return std::get<id_expression>(expr)->get_token();
    }
    // else (because we're deliberately ignoring the other
    //       options which are more than a single token)
    return {};
}

auto primary_expression_node::position() const -> source_position
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

    break;default:
        assert (!"illegal primary_expression_node state");
        return { 0, 0 };
    }
}

auto primary_expression_node::visit(auto& v, int depth) -> void
{
    v.start(*this, depth);
    try_visit<identifier     >(expr, v, depth);
    try_visit<expression_list>(expr, v, depth);
    try_visit<id_expression  >(expr, v, depth);
    try_visit<declaration    >(expr, v, depth);
    try_visit<inspect        >(expr, v, depth);
    v.end(*this, depth);
}


auto iteration_statement_node::get_for_parameter() const -> parameter_declaration_node const* {
    assert(*identifier == "for");
    auto func = std::get_if<declaration_node::function>(&body->type);
    assert(func && *func && std::ssize((**func).parameters->parameters) == 1);
    return (**func).parameters->parameters[0].get();
}

auto iteration_statement_node::visit(auto& v, int depth) -> void
{
    v.start(*this, depth);
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


auto statement_node::position() const -> source_position
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

auto parameter_declaration_node::position() const -> source_position
{
    assert (declaration);
    return pos;
}

auto parameter_declaration_node::visit(auto& v, int depth) -> void
{
    v.start(*this, depth);
    assert (declaration);
    declaration->visit(v, depth+1);
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
            x->visit(v, depth+1);
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
    std::vector<cpp2::error>& errors;

    std::unique_ptr<translation_unit_node> parse_tree;

    //  Keep a stack of current capture groups (contracts/decls still being parsed)
    std::vector<capture_group*> current_capture_groups;

    struct capture_groups_stack_guard {
        parser* pars;
        capture_groups_stack_guard(parser* p, capture_group* cg)
            : pars{p}
        {
            assert(p);
            assert(cg);
            pars->current_capture_groups.push_back(cg);
        }
        ~capture_groups_stack_guard() {
            pars->current_capture_groups.pop_back();
        }
    };

    //  Keep a stack of currently active declarations (still being parsed)
    std::vector<declaration_node*> current_declarations = { nullptr };

    struct current_declarations_stack_guard {
        parser* pars;
        current_declarations_stack_guard(parser* p, declaration_node* decl)
            : pars{p}
        {
            assert(p);
            assert(decl);
            pars->current_declarations.push_back(decl);
        }
        ~current_declarations_stack_guard() {
            pars->current_declarations.pop_back();
        }
    };

    //  Used only for the duration of each parse() call
    std::vector<token> const* tokens_ = nullptr;
    int pos = 0;

public:
    //-----------------------------------------------------------------------
    //  Constructor
    //
    //  errors      error list
    //
    parser(
        std::vector<cpp2::error>& errors
    )
        : errors{ errors }
        , parse_tree{std::make_unique<translation_unit_node>()}
    {
    }

    //-----------------------------------------------------------------------
    //  parse
    //
    //  tokens      input tokens for this section of Cpp2 source code
    //
    //  Each call parses this section's worth of tokens and adds the
    //  result to the stored parse tree. Call this repeatedly for the Cpp2
    //  sections in a TU to build the whole TU's parse tree
    //
    auto parse(
        std::vector<token> const& tokens
    )
        -> bool
    {
        //  Generate parse tree for this section as if a standalone TU
        tokens_ = &tokens;
        pos     = 0;
        auto tu = translation_unit();

        //  Then add it to the complete parse tree
        parse_tree->declarations.insert(
            parse_tree->declarations.end(),
            std::make_move_iterator(tu->declarations.begin()),
            std::make_move_iterator(tu->declarations.end())
        );
        if (!done()) {
            error("unexpected text at end of Cpp2 code section");
            return false;
        }
        return true;
    }


    //-----------------------------------------------------------------------
    //  get_parse_tree
    //
    //  Get the entire parse tree, from the root (translation_unit_node)
    //
    auto get_parse_tree() -> translation_unit_node&
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
    //  Error reporting: Fed into the supplied this->error object
    //
    //  msg                 message to be printed
    //
    //  include_curr_token  in this file (during parsing)_ we normally want
    //                      to show the current token as the unexpected text
    //                      we encountered, but some sema rules are applied
    //                      early during parsing and for those it doesn't
    //                      make sense to show the next token (e.g., when
    //                      we detect and reject a "std::move" qualified-id,
    //                      it's not relevant to add "at LeftParen: ("
    //                      just because ( happens to be the next token)
    //
    auto error(char const* msg, bool include_curr_token = true) const -> void
    {
        auto m = std::string{msg};
        if (include_curr_token) {
            m += std::string(" (at '") + curr().to_string(true) + "')";
        }
        errors.emplace_back( curr().position(), m );
    }

    auto error(std::string const& msg, bool = true) const -> void
    {
        error(msg.c_str());
    }


    //-----------------------------------------------------------------------
    //  Token navigation: Only these functions should access this->token_
    //
    auto curr() const -> token const&
    {
        if (done()) {
            throw std::runtime_error("unexpected end of source file");
        }

        return (*tokens_)[pos];
    }

    auto peek(int num) const -> token const*
    {
        assert (tokens_);
        if (pos + num >= 0 && pos + num < std::ssize(*tokens_)) {
            return &(*tokens_)[pos + num];
        }
        return {};
    }

    auto done() const -> bool
    {
        assert (tokens_);
        assert (pos <= std::ssize(*tokens_));
        return pos == std::ssize(*tokens_);
    }

    auto next(int num = 1) -> void
    {
        assert (tokens_);
        pos = std::min( pos+num, as<int>(std::ssize(*tokens_)) );
    }


    //-----------------------------------------------------------------------
    //  Parsers for unary expressions
    //

    //G primary-expression:
    //G     inspect-expression
    //G     id-expression
    //G     literal
    //G     ( expression-list )
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

        if (curr().type() == lexeme::Identifier ||
            curr().type() == lexeme::DecimalLiteral ||
            curr().type() == lexeme::FloatLiteral ||
            curr().type() == lexeme::StringLiteral ||
            curr().type() == lexeme::CharacterLiteral ||
            curr().type() == lexeme::BinaryLiteral ||
            curr().type() == lexeme::HexadecimalLiteral ||
            curr().type() == lexeme::Keyword
            )
        {
            n->expr = &curr();
            next();
            return n;
        }

        if (curr().type() == lexeme::LeftParen)
        {
            bool inside_initializer = (peek(-1)->type() == lexeme::Assignment);
            auto open_paren = curr().position();
            next();
            auto expr_list = expression_list(open_paren, inside_initializer);
            if (!expr_list) {
                error("unexpected text - ( is not followed by an expression-list");
                next();
                return {};
            }
            if (curr().type() != lexeme::RightParen) {
                error("unexpected text - expression-list is not terminated by )");
                next();
                return {};
            }
            expr_list->close_paren = curr().position();
            next();
            n->expr = std::move(expr_list);
            return n;
        }

        if (auto decl = unnamed_declaration(curr().position(), true, true)) // captures are allowed
        {
            assert (!decl->identifier && "ICE: declaration should have been unnamed");
            if (!decl->is(declaration_node::function)) {
                error("an unnamed declaration at expression scope must be a function");
                next();
                return {};
            }
            auto& func = std::get<declaration_node::function>(decl->type);
            assert(func);
            if (func->returns.index() == function_type_node::list) {
                error("an unnamed function at expression scope currently cannot return multiple values");
                next();
                return {};
            }
            if (!func->contracts.empty()) {
                error("an unnamed function at expression scope currently cannot have contracts");
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
    //G     postfix-expression [ expression-list ]
    //G     postfix-expression ( expression-list? )
    //G     postfix-expression . id-expression
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
            (is_postfix_operator(curr().type())
                //  Postfix operators must be lexically adjacent
                && curr().position().lineno == peek(-1)->position().lineno
                && curr().position().colno == peek(-1)->position().colno + peek(-1)->length()
            ) ||
            curr().type() == lexeme::LeftBracket ||
            curr().type() == lexeme::LeftParen ||
            curr().type() == lexeme::Dot
            )
        {
            //  * and & can't be a unary operator if followed by a (, identifier, or literal
            if ((curr().type() == lexeme::Multiply || curr().type() == lexeme::Ampersand) &&
                peek(1) &&
                (peek(1)->type() == lexeme::LeftParen || peek(1)->type() == lexeme::Identifier || is_literal(peek(1)->type())))
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

            auto term = postfix_expression_node::term{&curr()};
            next();

            if (term.op->type() == lexeme::LeftBracket)
            {
                term.expr_list = expression_list(term.op->position());
                if (!term.expr_list) {
                    error("subscript expression [ ] must not be empty");
                    return {};
                }
                if (curr().type() != lexeme::RightBracket) {
                    error("unexpected text - [ is not properly matched by ]");
                    return {};
                }
                term.expr_list->close_paren = curr().position();
                term.op_close = &curr();
                next();
            }
            else if (term.op->type() == lexeme::LeftParen)
            {
                term.expr_list = expression_list(term.op->position());
                if (!term.expr_list) {
                    error("( is not followed by a valid expression list");
                    return {};
                }
                if (curr().type() != lexeme::RightParen) {
                    error("unexpected text - ( is not properly matched by )");
                    return {};
                }
                term.expr_list->close_paren = curr().position();
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

        return n;
    }


    //G prefix-expression:
    //G     postfix-expression
    //G     prefix-operator prefix-expression
    //GTODO     await-expression
    //GTODO     sizeof ( type-id )
    //GTODO     sizeof ... ( identifier )
    //GTODO     alignof ( type-id )
    //GTODO     throws-expression
    //G
    auto prefix_expression()
        -> std::unique_ptr<prefix_expression_node>
    {
        auto n = std::make_unique<prefix_expression_node>();
        for ( ; is_prefix_operator(curr().type()); next()) {
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
        typename IsValidOp,
        typename TermFunc
    >
    auto binary_expression(
        IsValidOp is_valid_op,
        TermFunc  term
    )
        -> std::unique_ptr<Binary>
    {
        auto n = std::make_unique<Binary>();
        if ( (n->expr = term()) ) {
            while (is_valid_op(curr())) {
                typename Binary::term t{};
                t.op = &curr();
                next();

                if ( !(t.expr = term()) ) {
                    error("invalid expression after " + peek(-1)->to_string());
                    return n;
                }
                n->terms.push_back( std::move(t) );
            }
            return n;
        }
        return {};
    }

    //G is-as-expression:
    //G     prefix-expression
    //GTODO    is-as-expression is-expression-constraint
    //GTODO    is-as-expression as-type-cast
    //GTODO    type-id is-type-constraint
    //G
    auto is_as_expression() {
        return binary_expression<is_as_expression_node> (
            [](token const& t){
                std::string_view s{t};
                return t.type() == lexeme::Keyword && (s == "is" || s == "as");
            },
            [this]{ return prefix_expression(); }
        );
    }

    //G multiplicative-expression:
    //G     is-as-expression
    //G     multiplicative-expression * is-as-expression
    //G     multiplicative-expression / is-as-expression
    //G     multiplicative-expression % is-as-expression
    //G
    auto multiplicative_expression() {
        return binary_expression<multiplicative_expression_node> (
            [](token const& t){ return t.type() == lexeme::Multiply || t.type() == lexeme::Slash || t.type() == lexeme::Modulo; },
            [this]{ return is_as_expression(); }
            );
    }

    //G additive-expression:
    //G     multiplicative-expression
    //G     additive-expression + multiplicative-expression
    //G     additive-expression - multiplicative-expression
    //G
    auto additive_expression() {
        return binary_expression<additive_expression_node> (
            [](token const& t){ return t.type() == lexeme::Plus || t.type() == lexeme::Minus; },
            [this]{ return multiplicative_expression(); }
        );
    }

    //G shift-expression:
    //G     additive-expression
    //G     shift-expression << additive-expression
    //G     shift-expression >> additive-expression
    //G
    auto shift_expression() {
        return binary_expression<shift_expression_node> (
            [](token const& t){ return t.type() == lexeme::LeftShift || t.type() == lexeme::RightShift; },
            [this]{ return additive_expression(); }
        );
    }

    //G compare-expression:
    //G     shift-expression
    //G     compare-expression <=> shift-expression
    //G
    auto compare_expression() {
        return binary_expression<compare_expression_node> (
            [](token const& t){ return t.type() == lexeme::Spaceship; },
            [this]{ return shift_expression(); }
        );
    }

    //G relational-expression:
    //G     compare-expression
    //G     relational-expression <  compare-expression
    //G     relational-expression >  compare-expression
    //G     relational-expression <= compare-expression
    //G     relational-expression >= compare-expression
    //G
    auto relational_expression(bool allow_relational_comparison = true) {
        if (allow_relational_comparison) {
            return binary_expression<relational_expression_node> (
                [](token const& t){ return t.type() == lexeme::Less || t.type() == lexeme::LessEq || t.type() == lexeme::Greater || t.type() == lexeme::GreaterEq; },
                [this]{ return compare_expression(); }
            );
        }
        else {
            return binary_expression<relational_expression_node> (
                [](token const&){ return false; },
                [this]{ return compare_expression(); }
            );
        }
    }

    //G equality-expression:
    //G     relational-expression
    //G     equality-expression == relational-expression
    //G     equality-expression != relational-expression
    //G
    auto equality_expression(bool allow_relational_comparison = true) {
        return binary_expression<equality_expression_node> (
            [](token const& t){ return t.type() == lexeme::EqualComparison || t.type() == lexeme::NotEqualComparison; },
            [=,this]{ return relational_expression(allow_relational_comparison); }
        );
    }

    //G bit-and-expression:
    //G     equality-expression
    //G     bit-and-expression & equality-expression
    //G
    auto bit_and_expression(bool allow_relational_comparison = true) {
        return binary_expression<bit_and_expression_node> (
            [](token const& t){ return t.type() == lexeme::Ampersand; },
            [=,this]{ return equality_expression(allow_relational_comparison); }
        );
    }

    //G bit-xor-expression:
    //G     bit-and-expression
    //G     bit-xor-expression & bit-and-expression
    //G
    auto bit_xor_expression(bool allow_relational_comparison = true) {
        return binary_expression<bit_xor_expression_node> (
            [](token const& t){ return t.type() == lexeme::Caret; },
            [=,this]{ return bit_and_expression(allow_relational_comparison); }
        );
    }

    //G bit-or-expression:
    //G     bit-xor-expression
    //G     bit-or-expression & bit-xor-expression
    //G
    auto bit_or_expression(bool allow_relational_comparison = true) {
        return binary_expression<bit_or_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalOr; },
            [=,this]{ return bit_xor_expression(allow_relational_comparison); }
        );
    }

    //G logical-and-expression:
    //G     bit-or-expression
    //G     logical-and-expression && bit-or-expression
    //G
    auto logical_and_expression(bool allow_relational_comparison = true) {
        return binary_expression<logical_and_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalAnd; },
            [=,this]{ return bit_or_expression(allow_relational_comparison); }
        );
    }

    //  constant-expression:    // don't need intermediate production, just use:
    //  conditional-expression: // don't need intermediate production, just use:
    //G logical-or-expression:
    //G     logical-and-expression
    //G     logical-or-expression || logical-and-expression
    //G
    auto logical_or_expression(bool allow_relational_comparison = true) {
        return binary_expression<logical_or_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalOr; },
            [=,this]{ return logical_and_expression(allow_relational_comparison); }
        );
    }

    //G assignment-expression:
    //G     logical-or-expression
    //G     assignment-expression assignment-operator assignment-expression
    //G
    auto assignment_expression(bool allow_relational_comparison = true) -> std::unique_ptr<assignment_expression_node> {
        return binary_expression<assignment_expression_node> (
            [](token const& t){ return is_assignment_operator(t.type()); },
            [=,this]{ return logical_or_expression(allow_relational_comparison); }
        );
    }

    //G  expression:                // eliminated condition: - use expression:
    //G     assignment-expression
    //GTODO    try expression
    //G
    auto expression(bool allow_relational_comparison = true) -> std::unique_ptr<expression_node> {
        auto n = std::make_unique<expression_node>();
        if (!(n->expr = assignment_expression(allow_relational_comparison))) {
            return {};
        }
        return n;
    }

    //G expression-list:
    //G     parameter-direction-opt expression
    //G     expression-list , expression
    //G
    auto expression_list(source_position open_paren, bool inside_initializer = false) -> std::unique_ptr<expression_list_node> {
        auto pass = passing_style::in;
        auto n = std::make_unique<expression_list_node>();
        n->open_paren = open_paren;
        n->inside_initializer = inside_initializer;

        if (curr().type() == lexeme::Identifier && curr() == "out") {
            pass = passing_style::out;
            next();
        }
        else if (curr().type() == lexeme::Identifier && curr() == "move") {
            pass = passing_style::move;
            next();
        }
        else if (curr().type() == lexeme::Identifier && curr() == "forward") {
            pass = passing_style::forward;
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
            if (curr().type() == lexeme::Identifier && curr() == "out") {
                pass = passing_style::out;
                next();
            }
            else if (curr().type() == lexeme::Identifier && curr() == "move") {
                pass = passing_style::move;
                next();
            }
            auto expr = expression();
            if (!expr) {
                error("invalid text in expression list");
                return {};
            }
            n->expressions.push_back( { pass, std::move(expr) } );
        }
        return n;
    }


    //G type-id:
    //G     const-opt unqualified-id
    //G     const-opt qualified-id
    //G
    auto type_id() -> std::unique_ptr<type_id_node>
    {
        auto n = std::make_unique<type_id_node>();

        if (curr().type() == lexeme::Keyword && curr() == "const") {
            n->const_qualifier = &curr();
            next();
        }

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


    //G unqualified-id:
    //G     identifier
    //G     template-id
    //GTODO     operator-function-id
    //G
    //G template-id:
    //G     identifier < template-argument-list-opt >
    //G
    //G template-argument-list:
    //G     template-argument-list , template-argument
    //G
    //G template-argument:
    //G     expression
    //G     id-expression
    //G
    auto unqualified_id() -> std::unique_ptr<unqualified_id_node>
    {
        //  Handle the identifier
        if (curr().type() != lexeme::Identifier &&
            curr().type() != lexeme::Keyword)   // 'const', and fundamental types that are keywords
        {
            return {};
        }

        auto n = std::make_unique<unqualified_id_node>();

        n->identifier =  &curr();
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

            unqualified_id_node::term term;

            do {
                if (auto e = expression(false)) {   // disallow unparenthesized relational comparisons in template args
                    term.arg = std::move(e);
                }
                else if (auto i = id_expression()) {
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
                curr().type() == lexeme::Comma &&
                [&]{term.comma = curr().position(); next(); return true;}()
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
    //G     ::
    //G     unqualified-id ::
    //G
    //G member-name-specifier:
    //G     unqualified-id .
    //G
    auto qualified_id() -> std::unique_ptr<qualified_id_node>
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

        //  If we don't get a first id, or if the next thing isn't :: or .,
        //  back out and report unsuccessful
        term.id = unqualified_id();
        if (!term.id || curr().type() != lexeme::Scope) {
            pos = start_pos;    // backtrack
            return {};
        }

        //  Reject "std" :: "move" / "forward"
        assert (term.id->identifier);
        auto first_uid_was_std = (*term.id->identifier == "std");
        auto first_time_through_loop = true;

        n->ids.push_back( std::move(term) );

        assert (curr().type() == lexeme::Scope);
        while (curr().type() == lexeme::Scope)
        {
            auto term = qualified_id_node::term{ &curr() };
            next();
            term.id = unqualified_id();
            if (!term.id) {
                error("invalid text in qualified name");
                return {};
            }
            assert (term.id->identifier);
            if (first_time_through_loop && first_uid_was_std && term.scope_op->type() == lexeme::Scope) {
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
    auto id_expression() -> std::unique_ptr<id_expression_node>
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


    //G expression-statement:
    //G     expression ;
    //G     expression
    //G
    auto expression_statement(bool semicolon_required) -> std::unique_ptr<expression_statement_node>
    {
        auto n = std::make_unique<expression_statement_node>();
        if (!(n->expr = expression())) {
            return {};
        }

        if (semicolon_required && curr().type() != lexeme::Semicolon &&
            peek(-1)->type() != lexeme::Semicolon
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
            error("expected ; at end of statement");
            return {};
        }
        if (curr().type() == lexeme::Semicolon) {
            n->has_semicolon = true;
            next();
        }
        return n;
    }


    //G selection-statement:
    //G     if constexpr-opt expression compound-statement
    //G     if constexpr-opt expression compound-statement else compound-statement
    //G
    auto selection_statement() -> std::unique_ptr<selection_statement_node>
    {
        if (curr().type() != lexeme::Keyword || curr() != "if") {
            return {};
        }
        auto n = std::make_unique<selection_statement_node>();
        n->identifier = &curr();
        next();

        if (curr().type() == lexeme::Keyword && curr() == "constexpr") {
            n->is_constexpr = true;
            next();
        }

        if (auto e = expression()) {
            n->expression = std::move(e);
        }
        else {
            error("invalid if condition");
            return {};
        }

        if (auto s = compound_statement()) {
            n->true_branch = std::move(s);
        }
        else {
            error("invalid if branch body");
            return {};
        }

        if (curr().type() != lexeme::Keyword || curr() != "else") {
            //  Add empty else branch to simplify processing elsewhere
            //  Note: Position (0,0) signifies it's implicit (no source location)
            n->false_branch =
                std::make_unique<compound_statement_node>( source_position(0,0) );
        }
        else {
            n->else_pos = curr().position();
            next();
            if (auto s = compound_statement()) {
                n->false_branch = std::move(s);
                n->has_source_false_branch = true;
            }
            else {
                error("invalid else branch body");
                return {};
            }
        }

        return n;
    }


    //G return-statement:
    //G     return expression-opt ;
    //G
    auto return_statement() -> std::unique_ptr<return_statement_node>
    {
        if (curr().type() != lexeme::Keyword || curr() != "return") {
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
            error("invalid return expression");
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
    //G     while logical-or-expression next-clause-opt compound-statement
    //G     do compound-statement while logical-or-expression next-clause-opt ;
    //G     for expression next-clause-opt do unnamed-declaration
    //G
    //G next-clause:
    //G     next assignment-expression
    //G
    auto iteration_statement() -> std::unique_ptr<iteration_statement_node>
    {
        if (curr().type() != lexeme::Keyword ||
            (curr() != "while" && curr() != "do" && curr() != "for")
            )
        {
            return {};
        }

        auto n = std::make_unique<iteration_statement_node>();
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
                error("invalid expression after 'next'");
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
                error("invalid while loop body");
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
                error("expected valid range expression after 'for'");
                return {};
            }

            if (!handle_optional_next_clause()) { return {}; }

            if (curr() != "do") {
                error("'for each of' must be followed by 'do'");
                return {};
            }
            next();

            n->body = unnamed_declaration(curr().position());
            auto func = n->body ? std::get_if<declaration_node::function>(&n->body->type) : nullptr;
            if (!n->body || n->body->identifier || !func || !*func ||
                std::ssize((**func).parameters->parameters) != 1 ||
                (**func).returns.index() != function_type_node::empty
                )
            {
                error("for..do loop body must be an unnamed function taking a single parameter and returning nothing", false);
                return {};
            }

            return n;
        }

        assert(!"compiler bug: unexpected case");
        return {};
    }


    //G alternative:
    //G     alt-name-opt is-type-constraint = statement
    //G     alt-name-opt is-value-constraint = statement
    //G     alt-name-opt as-type-cast = statement
    //GTODO    alt-name-opt is-expression-constraint = statement
    //G
    //G is-type-constraint
    //G     is type-id
    //G
    //G is-value-constraint
    //G     is postfix-expression
    //G
    //G as-type-cast
    //G     as id-expression
    //G
    //G alt-name:
    //G     unqualified-id :
    //G
    auto alternative() -> std::unique_ptr<alternative_node>
    {
        auto n = std::make_unique<alternative_node>();

        ////  Check for an optional name (just one unqualified-id, no decomposition yet)
        //if (curr() != "is" && curr() != "as") {
        //    if (auto id = unqualified_id()) {
        //        n->name = std::move(id);
        //    }
        //    else {
        //        error("expected unqualified-id, 'is', or 'as' to start an inspect alternative");
        //        return {};
        //    }
        //    if (curr().type() != lexeme::Colon) {
        //        error("expected : after the introduced name in an inspect alternative");
        //        return {};
        //    }
        //    next();
        //}

        //  Now we should be as "is" or "as"
        //  (initial partial implementation, just "is/as id-expression")
        if (curr() != "is" && curr() != "as") {
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
            error("expected type-id or value after 'is' in inspect alternative");
            return {};
        }

        if (curr().type() != lexeme::Assignment) {
            error("expected = at start of inspect alternative body");
            return {};
        }
        n->equal_sign = curr().position();
        next();

        if (auto s = statement(true, n->equal_sign)) {
            n->statement = std::move(s);
        }
        else {
            error("expected statement after = in inspect alternative");
            return {};
        }

        return n;
    }


    //G inspect-expression:
    //G     inspect constexpr-opt expression { alternative-seq-opt }
    //G     inspect constexpr-opt expression -> type-id { alternative-seq-opt }
    //G
    //G alternative-seq:
    //G     alternative
    //G     alternative-seq alternative
    //G
    auto inspect_expression(bool is_expression) -> std::unique_ptr<inspect_expression_node>
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
            error("invalid inspect expression");
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
                error("invalid alternative in inspect");
                return {};
            }
            if (is_expression && a->statement->statement.index() != statement_node::expression) {
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


    //G statement:
    //G     selection-statement
    //G     inspect-expression
    //G     return-statement
    //G     iteration-statement
    //G     compound-statement
    //G     declaration-statement
    //G     expression-statement
    //G     contract
    //
    //GTODO     jump-statement
    //GTODO     try-block
    //G
    auto statement(bool semicolon_required, source_position equal_sign = source_position{})
        -> std::unique_ptr<statement_node>
    {
        auto n = std::make_unique<statement_node>();

        //  Now handle the rest of the statement

        if (auto s = selection_statement()) {
            n->statement = std::move(s);
            assert (n->statement.index() == statement_node::selection);
            return n;
        }

        else if (auto i = inspect_expression(false)) {
            n->statement = std::move(i);
            assert (n->statement.index() == statement_node::inspect);
            return n;
        }

        else if (auto s = return_statement()) {
            n->statement = std::move(s);
            assert (n->statement.index() == statement_node::return_);
            return n;
        }

        else if (auto s = iteration_statement()) {
            n->statement = std::move(s);
            assert (n->statement.index() == statement_node::iteration);
            return n;
        }

        else if (auto s = compound_statement(equal_sign)) {
            n->statement = std::move(s);
            assert (n->statement.index() == statement_node::compound);
            return n;
        }

        else if (auto s = declaration()) {
            n->statement = std::move(s);
            assert (n->statement.index() == statement_node::declaration);
            return n;
        }

        else if (auto s = expression_statement(semicolon_required)) {
            n->statement = std::move(s);
            assert (n->statement.index() == statement_node::expression);
            return n;
        }

        else if (auto s = contract()) {
            if (*s->kind != "assert") {
                error("only 'assert' contracts are allowed at statement scope");
                return {};
            }
            n->statement = std::move(s);
            assert (n->statement.index() == statement_node::contract);
            return n;
        }

        else {
            //next();
            return {};
        }
    }


    //G compound-statement:
    //G     { statement-seq-opt }
    //G
    //G statement-seq:
    //G     statement
    //G     statement-seq statement
    //G
    auto compound_statement(source_position equal_sign = source_position{})
        -> std::unique_ptr<compound_statement_node>
    {
        if (curr().type() != lexeme::LeftBrace) {
            return {};
        }

        auto n = std::make_unique<compound_statement_node>();

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
                error("invalid statement in compound-statement");
                return {};
            }
            n->statements.push_back( std::move(s) );
        }

        n->close_brace = curr().position();
        next();
        return n;
    }


    //G parameter-declaration:
    //G     parameter-direction-opt declaration
    //G
    //G parameter-direction: one of
    //G     in copy inout out move forward
    //G
    //G this-specifier:
    //G     implicit
    //G     virtual
    //G     override
    //G     final
    //G
    auto parameter_declaration(
        bool returns = false
    )
        -> std::unique_ptr<parameter_declaration_node>
    {
        auto n = std::make_unique<parameter_declaration_node>();
        n->pass = returns ? passing_style::out : passing_style::in;
        n->pos  = curr().position();

        if (curr().type() == lexeme::Identifier) {
            if (curr() == "in") {
                if (returns) {
                    error("a return value cannot be 'in'");
                    return {};
                }
                n->pass = passing_style::in;
                next();
            }
            else if (curr() == "copy") {
                if (returns) {
                    error("a return value cannot be 'copy'");
                    return {};
                }
                n->pass = passing_style::copy;
                next();
            }
            else if (curr() == "inout") {
                if (returns) {
                    error("a return value cannot be 'inout'");
                    return {};
                }
                n->pass = passing_style::inout;
                next();
            }
            else if (curr() == "out") {
                n->pass = passing_style::out;
                next();
            }
            else if (curr() == "move") {
                if (returns) {
                    error("a return value cannot be 'move' (it is implicitly 'move'-out)");
                    return {};
                }
                n->pass = passing_style::move;
                next();
            }
            else if (curr() == "forward") {
                n->pass = passing_style::forward;
                next();
            }
        }

        if (curr().type() == lexeme::Identifier) {
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
        }

        if (!(n->declaration = declaration(false))) {
            return {};
        }

        if (!returns && n->declaration->initializer) {
            error("Cpp2 is currently exploring the path of not allowing default arguments - use overloading instead", false);
            return {};
        }

        return n;
    }


    //G parameter-declaration-list
    //G     ( parameter-declaration-seq-opt )
    //G
    //G parameter-declaration-seq:
    //G     parameter-declaration
    //G     parameter-declaration-seq , parameter-declaration
    //G
    auto parameter_declaration_list(
        bool returns = false
    )
        -> std::unique_ptr<parameter_declaration_list_node>
    {
        if (curr().type() != lexeme::LeftParen) {
            return {};
        }

        auto n = std::make_unique<parameter_declaration_list_node>();
        n->pos_open_paren = curr().position();
        next();

        auto param = std::make_unique<parameter_declaration_node>();

        while ((param = parameter_declaration(returns)) != nullptr) {
            n->parameters.push_back( std::move(param) );

            if (curr().type() == lexeme::RightParen) {
                break;
            }
            else if (curr().type() != lexeme::Comma) {
                error("expected , in parameter list");
                return {};
            }
            next();
        }

        if (curr().type() != lexeme::RightParen) {
            error("invalid parameter list");
            next();
            return {};
        }

        n->pos_close_paren = curr().position();
        next();
        return n;
    }


    //G contract:
    //G     [ [ contract-kind id-expression-opt : logical-or-expression ] ]
    //G     [ [ contract-kind id-expression-opt : logical-or-expression , string-literal ] ]
    //G
    //G contract-kind: one of
    //G     pre post assert
    //G
    auto contract() -> std::unique_ptr<contract_node>
    {
        //  Note: For now I'm using [[ ]] mainly so that existing Cpp1 syntax highlighters
        //        don't get confused... I initially implemented single [ ], but then
        //        my editor's default Cpp1 highlighter didn't colorize the following
        //        multiline // comment correctly as a comment

        //  If there's no [ [ then this isn't a contract
        if (curr().type() != lexeme::LeftBracket || !peek(1) || peek(1)->type() != lexeme::LeftBracket) {
            return {};
        }

        auto n = std::make_unique<contract_node>(curr().position());
        auto guard = capture_groups_stack_guard(this, &n->captures);
        next();
        next();

        if (curr() != "pre" && curr() != "post" && curr() != "assert") {
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
            error("invalid contract condition");
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

        if (curr().type() != lexeme::RightBracket || !peek(1) || peek(1)->type() != lexeme::RightBracket) {
            error("expected ]] at the end of the contract");
            return {};
        }
        next();
        next();

        return n;
    }


    //G function-type:
    //G     parameter-declaration-list throws-specifier-opt return-list-opt contract-seq-opt
    //G
    //G throws-specifier:
    //G     throws
    //G
    //G return-list:
    //G     -> type-id
    //G     -> parameter_declaration_list
    //G
    //G contract-seq:
    //G     contract
    //G     contract-seq contract
    //G
    auto function_type() -> std::unique_ptr<function_type_node>
    {
        auto n = std::make_unique<function_type_node>();

        //  Parameters
        auto parameters = parameter_declaration_list();
        if (!parameters) {
            return {};
        }
        n->parameters = std::move(parameters);

        //  Optional "throws"
        if (curr().type() == lexeme::Keyword && curr() == "throws") {
            n->throws = true;
            next();
        }

        //  Optional returns
        if (curr().type() == lexeme::Arrow)
        {
            next();

            if (auto t = type_id()) {
                n->returns = std::move(t);
            }
            else if (auto returns_list = parameter_declaration_list(true)) {
                if (std::ssize(returns_list->parameters) < 1) {
                    error("an explicit return value list cannot be empty");
                    return {};
                }
                n->returns = std::move(returns_list);
            }
            else {
                error("missing function return after ->");
                return {};
            }
        }

        //  Pre/post conditions
        while (auto c = contract()) {
            if (*c->kind != "pre" && *c->kind != "post") {
                error("only 'pre' and 'post' contracts are allowed on functions");
                return {};
            }
            n->contracts.push_back( std::move(c) );
        }

        return n;
    }


    //G unnamed-declaration:
    //G     : function-type = statement
    //G     : type-id-opt = statement
    //G     : type-id
    //G
    auto unnamed_declaration(source_position start, bool semicolon_required = true, bool captures_allowed = false) -> std::unique_ptr<declaration_node>
    {
        auto deduced_type = false;

        //  The next token must be :
        if (curr().type() != lexeme::Colon) {
            return {};
        }
        next();

        auto n = std::make_unique<declaration_node>( current_declarations.back() );
        n->pos = start;
        auto guard =
            captures_allowed
            ? std::make_unique<capture_groups_stack_guard>(this, &n->captures)
            : std::unique_ptr<capture_groups_stack_guard>()
            ;

        auto guard2 = current_declarations_stack_guard(this, n.get());

        //  Next is an an optional type

        //  It could be a function type, declaring a function
        if (auto t = function_type()) {
            n->type = std::move(t);
            assert (n->type.index() == declaration_node::function);
        }

        //  Or a pointer to a type, declaring a pointer object
        else if (curr().type() == lexeme::Multiply) {
            n->pointer_declarator = &curr();
            next();
            if (auto t = type_id()) {
                n->type = std::move(t);
                assert (n->type.index() == declaration_node::object);
            }
        }

        //  Or just a type, declaring a non-pointer object
        else if (auto t = type_id()) {
            n->type = std::move(t);
            assert (n->type.index() == declaration_node::object);
        }

        //  Or nothing, declaring an object of deduced type,
        //  which we'll represent using an empty type-id
        else {
            n->type = std::make_unique<type_id_node>();
            assert (n->type.index() == declaration_node::object);
            deduced_type = true;
        }

        //  Next is optionally = followed by an initializer

        //  If there is no =
        if (curr().type() != lexeme::Assignment)
        {
            if (deduced_type) {
                error("a deduced type must have an = initializer");
                return {};
            }

            if (n->type.index() == declaration_node::function) {
                error("missing = before function body");
                return {};
            }

            //  Then there may be a semicolon
            //  If there is a semicolon, eat it
            if (curr().type() == lexeme::Semicolon) {
                next();
            }
            // But if there isn't one and it was required, diagnose an error
            else if (semicolon_required) {
                error("missing semicolon at end of declaration");
                return {};
            }
        }

        //  There was an =, so eat it and continue
        else {
            n->equal_sign = curr().position();
            next();

            if (n->pointer_declarator) {
                if (curr() == "nullptr" ||
                    isdigit(std::string_view(curr())[0]) ||
                    (curr() == "(" && peek(1) && *peek(1) == ")")
                    )
                {
                    error("pointer cannot be initialized to null or int - leave it uninitialized and then set it to a non-null value when you have one");
                    violates_lifetime_safety = true;
                    throw std::runtime_error("null initialization detected");
                }
            }

            if (!(n->initializer = statement(semicolon_required, n->equal_sign))) {
                error("ill-formed initializer");
                next();
                return {};
            }
        }

        n->decl_end = peek(-1)->position();
        return n;
    }


    //G declaration:
    //G     identifier unnamed-declaration
    //G
    auto declaration(bool semicolon_required = true) -> std::unique_ptr<declaration_node>
    {
        if (done()) { return {}; }

        //  Remember current position, because we need to look ahead
        auto start_pos = pos;

        auto id = unqualified_id();
        if (!id) {
            return {};
        }

        auto n = unnamed_declaration(start_pos, semicolon_required);
        if (!n) {
            pos = start_pos;    // backtrack
            return {};
        }

        n->identifier = std::move(id);
        return n;
    }


    //G declaration-seq:
    //G     declaration
    //G     declaration-seq declaration
    //G
    //G translation-unit:
    //G     declaration-seq-opt
    //
    auto translation_unit() -> std::unique_ptr<translation_unit_node>
    {
        auto n = std::make_unique<translation_unit_node>();
        for (auto d = declaration(); d; d = declaration()) {
            n->declarations.push_back( std::move(d) );
        }
        return n;
    }

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

    auto pre(int indent) -> std::string_view
    {
        assert (indent >= 0);
        return {
            indent_str.c_str(),
            as<size_t>( std::min( indent*indent_spaces, as<int>(std::ssize(indent_str))) )
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
        o << pre(indent+1) << "is_constexpr: " << as<std::string>(n.is_constexpr) << "\n";
    }

    auto start(alternative_node const&, int indent) -> void
    {
        o << pre(indent) << "alternative\n";
    }

    auto start(inspect_expression_node const& n, int indent) -> void
    {
        o << pre(indent) << "inspect-expression\n";
        o << pre(indent+1) << "is_constexpr: " << as<std::string>(n.is_constexpr) << "\n";
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

    auto start(function_type_node const& n, int indent) -> void
    {
        o << pre(indent) << "function\n";
        o << pre(indent+1) << "throws: " << as<std::string>(n.throws) << "\n";
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
        o << pre(indent) << "declaration\n";
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


//-----------------------------------------------------------------------
//
//  Visitor for moving tokens that are to the right on the same line
//  and shifting their positions left 'n' spaces - used only at the
//  end when lowering to Cpp1, as a convenient way to adjust for other
//  positions shifts we create (e.g., moving some operators to prefix
//  notation, or inserting "std::move" prefixes)
//
//-----------------------------------------------------------------------
//
class adjust_remaining_token_columns_on_this_line_visitor
{
    source_position line_to_adjust_pos;
    colno_t         col_offset;

public:
    adjust_remaining_token_columns_on_this_line_visitor(
        source_position start_pos,
        colno_t offset
    )
        : line_to_adjust_pos{start_pos}
        , col_offset{offset}
    { }

    auto start(token& n, int) -> void
    {
        if (n.position().lineno == line_to_adjust_pos.lineno &&
            n.position().colno >= line_to_adjust_pos.colno
            )
        {
            n.position_col_shift(col_offset);
        }
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
