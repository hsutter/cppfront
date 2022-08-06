
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0


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

//-----------------------------------------------------------------------
//  Operator categorization
//

//G prefix-operator:
//G     one of  !
//G
auto is_prefix_operator(lexeme l) -> bool
{ 
    return l == lexeme::Not;
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

struct primary_expression_node
{
    enum active { empty=0, identifier, expression_list, id_expression };
    std::variant<
        std::monostate,
        token const*,
        std::unique_ptr<expression_list_node>,
        std::unique_ptr<id_expression_node>
    > expr;

    auto position() const -> source_position;
    auto visit(auto& v, int depth) -> void;
};


struct postfix_expression_node;

struct prefix_expression_node
{
    std::vector<token const*> ops;
    std::unique_ptr<postfix_expression_node> expr;

    auto position() const -> source_position;
    auto visit(auto& v, int depth) -> void;
};


template<
//#ifdef __clang__
//        //  Odd, Clang doesn't support C++ NTTI in 2022
//
//#else
    String   Name,
//#endif
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
    break;default:                     return "INVALID passing_tyle";
    }

}

struct expression_list_node
{
    source_position open_paren  = {};
    source_position close_paren = {};
    struct term {
        passing_style                    pass = {}; // for `out`
        std::unique_ptr<expression_node> expr;
    };
    std::vector< term > expressions;

    auto position() const -> source_position
    {
        //  Make sure this got set
        assert (open_paren != source_position());
        return open_paren;

        //  TODO this could be removed now that we're tracking position via open_paren
        //assert (std::ssize(expressions) > 0 && expressions.front().expr);
        //return expressions.front().expr->position();
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        for (auto const& x : expressions) {
            assert(x.expr);
            x.expr->visit(v, depth+1);
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


struct postfix_expression_node
{
    std::unique_ptr<primary_expression_node> expr;

    struct term 
    {
        token const* op;

        //  These are used if *op is [ or ( - can be null
        std::unique_ptr<expression_list_node> expr_list;
        token const* op_close;
    };
    std::vector<term> ops;

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
        for (auto const& x : ops) {
            assert (x.op);
            v.start(*x.op, depth+1);
            if (x.expr_list) {
                x.expr_list->visit(v, depth+1);
            }
        }
        v.end(*this, depth);
    }
};

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


struct unqualified_id_node
{
    token const* identifier;

    unqualified_id_node( token const* tok) 
        : identifier{ tok }
    {
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
        v.end(*this, depth);
    }
};

struct qualified_id_node
{
    std::vector<std::unique_ptr<unqualified_id_node>> ids;

    auto position() const -> source_position
    {
        assert (std::ssize(ids) > 0 && ids.front());
        return ids.front()->position();
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        for (auto const& x : ids) {
            assert(x);
            x->visit(v, depth+1);
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


struct declaration_node;
struct statement_node
{
    enum active { expression=0, compound, selection, declaration, return_ };
    std::variant<
        std::unique_ptr<expression_statement_node>,
        std::unique_ptr<compound_statement_node>,
        std::unique_ptr<selection_statement_node>,
        std::unique_ptr<declaration_node>,
        std::unique_ptr<return_statement_node>
    > statement;

    auto position() const -> source_position;

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        try_visit<expression >(statement, v, depth);
        try_visit<compound   >(statement, v, depth);
        try_visit<selection  >(statement, v, depth);
        try_visit<declaration>(statement, v, depth);
        try_visit<return_    >(statement, v, depth);
        v.end(*this, depth);
    }
};

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

struct function_returns_tag { };

struct function_type_node
{
    std::unique_ptr<parameter_declaration_list_node> parameters;
    bool throws = false;

    enum active { empty = 0, id, list };
    std::variant<
        std::monostate,
        std::unique_ptr<id_expression_node>,
        std::unique_ptr<parameter_declaration_list_node>
    > returns;

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
    std::unique_ptr<unqualified_id_node> identifier;

    token const* pointer_declarator = nullptr;

    enum active { function, object };
    std::variant<
        std::unique_ptr<function_type_node>,
        std::unique_ptr<id_expression_node>
    > type;

    source_position equal_sign = {};
    source_position decl_end   = {};
    std::unique_ptr<statement_node> initializer;

    //  Shorthand for common query
    //
    auto is(active a) const
    {
        return type.index() == a;
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
        identifier->visit(v, depth+1);

        if (pointer_declarator) {
            pointer_declarator->visit(v, depth+1);
        }

        try_visit<function>(type, v, depth+1);
        try_visit<object  >(type, v, depth+1);

        if (initializer) {
            initializer->visit(v, depth+1);
        }
        v.end(*this, depth);
    }
};

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
    auto error(char const* msg) const -> void 
    {
        assert (!done());
        errors.emplace_back(
            curr().position(), 
            msg + std::string(" at ") + curr().to_string()
        );
    }
    
    auto error(std::string const& msg) const -> void 
    { 
        error(msg.c_str()); 
    }


    //-----------------------------------------------------------------------
    //  Token navigation: Only these functions should access this->token_
    // 
    auto curr() const -> token const& 
    {
        assert (!done());
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
    //G     literal
    //G     ( expression-list )
    //G     id-expression
    //GT     TODO
    //G
    auto primary_expression() 
        -> std::unique_ptr<primary_expression_node>
    {
        auto n = std::make_unique<primary_expression_node>();

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

        if (curr().type() == lexeme::LeftParen) {
            auto open_paren = curr().position();
            next();
            auto expr_list = expression_list(open_paren);
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

        return {};
    }


    //G postfix-expression:
    //G     primary-expression
    //G     postfix-expression postfix-operator     [Note: without whitespace before the operator]
    //G     postfix-expression [ expression-list ]
    //G     postfix-expression ( expression-list? )
    //GT     postfix-expression . id-expression
    //GT     typeid ( expression )
    //GT     typeid ( type-id )
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
            //  Postfix operators must be lexically adjacent
            (is_postfix_operator(curr().type())
                && curr().position().lineno == peek(-1)->position().lineno
                && curr().position().colno == peek(-1)->position().colno + peek(-1)->length()
            ) ||
            curr().type() == lexeme::LeftBracket ||
            curr().type() == lexeme::LeftParen ||
            curr().type() == lexeme::Dot
            )
        {
            auto term = postfix_expression_node::term{&curr()};
            next();

            if (term.op->type() == lexeme::LeftBracket)
            {
                term.expr_list = expression_list(term.op->position());
                if (!term.expr_list) {
                    error("subscript expression [ ] must not be empty");
                }
                if (curr().type() != lexeme::RightBracket) {
                    error("unexpected text - [ is not properly matched by ]");
                }
                term.expr_list->close_paren = curr().position();
                term.op_close = &curr();
                next();
            }
            else if (term.op->type() == lexeme::LeftParen)
            {
                term.expr_list = expression_list(term.op->position());
                if (curr().type() != lexeme::RightParen) {
                    error("unexpected text - ( is not properly matched by )");
                }
                term.expr_list->close_paren = curr().position();
                term.op_close = &curr();
                next();
            }

            // TODO: lexeme::Dot

            n->ops.push_back( std::move(term) );
        }
        return n;
    }


    //G prefix-expression:
    //G     postfix-expression
    //G     prefix-operator prefix-expression
    //GT     await-expression
    //GT     sizeof prefix-expression
    //GT     sizeof ( type-id )
    //GT     sizeof ... ( identifier )
    //GT     alignof ( type-id )
    //GT     throws-expression
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
                typename Binary::term t;
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
    //GT    is-as-expression is-expression-constraint
    //GT    is-as-expression as-constraint
    //GT    type-id is-type-constraint
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
    auto relational_expression() {
        return binary_expression<relational_expression_node> (
            [](token const& t){ return t.type() == lexeme::Less || t.type() == lexeme::LessEq || t.type() == lexeme::Greater || t.type() == lexeme::GreaterEq; },
            [this]{ return compare_expression(); }
        );
    }

    //G equality-expression:
    //G     relational-expression
    //G     equality-expression == relational-expression
    //G     equality-expression != relational-expression
    //G
    auto equality_expression() {
        return binary_expression<equality_expression_node> (
            [](token const& t){ return t.type() == lexeme::EqualComparison || t.type() == lexeme::NotEqualComparison; },
            [this]{ return relational_expression(); }
        );
    }

    //G bit-and-expression:
    //G     equality-expression
    //G     bit-and-expression & equality-expression
    //G
    auto bit_and_expression() {
        return binary_expression<bit_and_expression_node> (
            [](token const& t){ return t.type() == lexeme::Ampersand; },
            [this]{ return equality_expression(); }
        );
    }

    //G bit-xor-expression:
    //G     bit-and-expression
    //G     bit-xor-expression & bit-and-expression
    //G
    auto bit_xor_expression() {
        return binary_expression<bit_xor_expression_node> (
            [](token const& t){ return t.type() == lexeme::Caret; },
            [this]{ return bit_and_expression(); }
        );
    }

    //G bit-or-expression:
    //G     bit-xor-expression
    //G     bit-or-expression & bit-xor-expression
    //G
    auto bit_or_expression() {
        return binary_expression<bit_or_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalOr; },
            [this]{ return bit_xor_expression(); }
        );
    }

    //G logical-and-expression:
    //G     bit-or-expression
    //G     logical-and-expression && bit-or-expression
    //G
    auto logical_and_expression() {
        return binary_expression<logical_and_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalAnd; },
            [this]{ return bit_or_expression(); }
        );
    }

    //  constant-expression:    // don't need intermediate production, just use:
    //  conditional-expression: // don't need intermediate production, just use:
    //G logical-or-expression:
    //G     logical-and-expression
    //G     logical-or-expression || logical-and-expression
    //G
    auto logical_or_expression() {
        return binary_expression<logical_or_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalOr; },
            [this]{ return logical_and_expression(); }
        );
    }

    //G assignment-expression:
    //G     logical-or-expression
    //G     assignment-expression assignment-operator assignment-expression
    //G
    auto assignment_expression() -> std::unique_ptr<assignment_expression_node> {
        return binary_expression<assignment_expression_node> (
            [](token const& t){ return is_assignment_operator(t.type()); },
            [this]{ return logical_or_expression(); }
        );
    }

    //G  expression:                // eliminated condition: - use expression:
    //G     assignment-expression
    //GT    try expression
    //G
    auto expression() -> std::unique_ptr<expression_node> {
        auto n = std::make_unique<expression_node>();
        if (!(n->expr = assignment_expression())) {
            return {};
        }
        return n;
    }

    //G expression-list:
    //G     expression
    //G     expression-list , expression
    //G
    auto expression_list(source_position open_paren) -> std::unique_ptr<expression_list_node> {
        auto pass = passing_style::in;
        auto n = std::make_unique<expression_list_node>();
        n->open_paren = open_paren;

        //  Remember current position, because we need to look ahead to see if there's an expression
        auto start_pos = pos;

        if (curr().type() == lexeme::Identifier && curr() == "out") {
            pass = passing_style::out;
            next();
        }
        auto x = expression();
        if (!x) {
            pos = start_pos;    // backtrack
            return {};
        }
        n->expressions.push_back( { pass, std::move(x) } );

        //  Now we have at least one expression, so see if there are more...

        while (curr().type() == lexeme::Comma) {
            next();
            pass = passing_style::in;
            if (curr().type() == lexeme::Identifier && curr() == "out") {
                pass = passing_style::out;
                next();
            }
            n->expressions.push_back( { pass, expression() } );
        }
        return n;
    }


    //G unqualified-id:
    //G     identifier
    //GT     operator-function-id
    //GT     template-id
    //G
    auto unqualified_id() -> std::unique_ptr<unqualified_id_node> 
    {
        if (curr().type() != lexeme::Identifier &&
            curr().type() != lexeme::Keyword)   // because of fundamental types like 'int' which are keywords
        {
            return {};
        }
        auto n = std::make_unique<unqualified_id_node>( &curr() );
        next();
        return n;
    }


    //G qualified-id:
    //G     nested-name-specifier unqualified-id
    //G
    //G nested-name-specifier
    //G     ::
    //G     unqualified-id ::
    //GT     type-name ::
    //GT     namespace-name ::
    //GT     nested-name-specifier identifier ::
    //G
    auto qualified_id() -> std::unique_ptr<qualified_id_node> 
    {
        auto n = std::make_unique<qualified_id_node>();

        //  Remember current position, because we need to look ahead to the .
        auto start_pos = pos;
        auto id = unqualified_id();
        if (!id || curr().type() != lexeme::Scope) {
            pos = start_pos;    // backtrack
            return {};
        }

        n->ids.push_back( std::move(id) );

        assert (curr().type() == lexeme::Scope);
        while (curr().type() == lexeme::Scope) {
            next();
            id = unqualified_id();
            if (!id) {
                error("invalid text, :: should be followed by a nested name");
                return {};
            }
            n->ids.push_back( std::move(id) );
        }

        return n;
    }


    //G id-expression
    //G     unqualified-id
    //G     qualified-id
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

        if (semicolon_required && curr().type() != lexeme::Semicolon) {
            error("expression-statement does not end with semicolon");
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
    //GT     switch expression compound-statement
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

        //  Optional return expression
        if (curr().type() != lexeme::Semicolon) {
            auto x = expression();
            if (!x) {
                error("invalid return expression");
                return {};
            }
            n->expression = std::move(x);
        }

        //  Final semicolon
        if (curr().type() != lexeme::Semicolon) {
            error("missing ; after return");
            next();
            return {};
        }

        next();
        return n;
    }


    //G statement:
    //G     expression-statement
    //G     compound-statement
    //G     selection-statement
    //G     declaration-statement
    //G     return-statement
    // 
    //GT     iteration-statement
    //GT     jump-statement
    //GT     try-block
    //G
    auto statement(bool semicolon_required) -> std::unique_ptr<statement_node> 
    {
        auto n = std::make_unique<statement_node>();

        if (auto s = selection_statement()) {
            n->statement = std::move(s);
            assert (n->statement.index() == statement_node::selection);
            return n;
        }

        else if (auto s = return_statement()) {
            n->statement = std::move(s);
            assert (n->statement.index() == statement_node::return_);
            return n;
        }

        else if (auto s = compound_statement()) {
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
    auto compound_statement() -> std::unique_ptr<compound_statement_node> 
    {
        if (curr().type() != lexeme::LeftBrace) {
            return {};
        }

        auto n = std::make_unique<compound_statement_node>();
        n->open_brace = curr().position();
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


    //G function-type:
    //G     parameter-declaration-list-opt throws-specifier-opt
    //G     parameter-declaration-list-opt throws-specifier-opt -> parameter_declaration_list
    //G
    //G throws-specifier:
    //G     throws
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

        //  If there's no -> then we're done
        if (curr().type() != lexeme::Arrow) {
            return n;
        }
        next();

        //  Returns
        if (auto t = id_expression()) {
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

        return n;
    }


    //G declaration:
    //G     identifier : function-type = statement
    //G     identifier : id-expression-opt = statement
    //G     identifier : id-expression
    //G
    auto declaration(bool semicolon_required = true) -> std::unique_ptr<declaration_node> 
    {
        if (done()) { return {}; }

        //  Remember current position, because we need to look ahead
        auto start_pos = pos;

        auto n = std::make_unique<declaration_node>();
        if (!(n->identifier = unqualified_id())) {
            return {};
        }

        //  The next token must be :
        if (curr().type() != lexeme::Colon) {
            pos = start_pos;    // backtrack
            return {};
        }
        next();

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
            if (auto t = id_expression()) {
                n->type = std::move(t);
                assert (n->type.index() == declaration_node::object);
            }
        }

        //  Or just a type, declaring a non-pointer object
        else if (auto t = id_expression()) {
            n->type = std::move(t);
            assert (n->type.index() == declaration_node::object);
        }

        //  Or nothing, declaring an object of deduced type,
        //  which we'll represent using an empty id-expression
        else {
            n->type = std::make_unique<id_expression_node>();
            assert (n->type.index() == declaration_node::object);
        }

        //  Next is optionally = followed by an initializer

        //  If there is no =
        if (curr().type() != lexeme::Assignment)
        {
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

            if (!(n->initializer = statement(semicolon_required))) {
                error("ill-formed initializer");
                next();
                return {};
            }
        }

        n->decl_end = peek(-1)->position();
        return n;
    }


    //G declaration-seq:
    //G     declaration
    //G     declaration-seq declaration
    //G
    //G translation-unit:
    //G     declaration-seq-opt
    //GT    { global-module-fragment }?  module-declaration  { declaration }*  { private-module-fragment }?
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
    
    std::vector<expression_list_node::term const*> current_expression_list_term = {};

public:
    auto start(token const& n, int indent) -> void
    {
        o << pre(indent) << n.to_string() << "\n";
    }

    auto start(expression_node const& n, int indent) -> void
    {
        o << pre(indent) << "expression\n";
        //  If we are in an expression-list
        if (!current_expression_list_term.empty()) {
            if (current_expression_list_term.back()->pass == passing_style::out) {
                o << pre(indent+1) << "out\n";
            }
            ++current_expression_list_term.back();
        }
    }

    auto start(expression_list_node const& n, int indent) -> void
    {
        //  We're going to use the pointer as an iterator
        current_expression_list_term.push_back( &n.expressions[0] );
        o << pre(indent) << "expression-list\n";
    }

    auto end(expression_list_node const& n, int indent) -> void
    {
        //  If we're ending an expression list node, our pointer should be
        //  pointing to one past the end of the expressions
        assert( !current_expression_list_term.empty() );
        assert( current_expression_list_term.back() == &n.expressions[0] + n.expressions.size());
        current_expression_list_term.pop_back();
    }

    auto start(primary_expression_node const& n, int indent) -> void
    {
        o << pre(indent) << "primary-expression\n";
    }

    auto start(prefix_expression_node const& n, int indent) -> void
    {
        o << pre(indent) << "prefix-expression\n";
    }

    template<String Name, typename Term>
    auto start(binary_expression_node<Name, Term> const& n, int indent) -> void
    {
        o << pre(indent) << Name.value << "-expression\n";
    }

    auto start(expression_statement_node const& n, int indent) -> void
    {
        o << pre(indent) << "expression-statement\n";
    }

    auto start(postfix_expression_node const& n, int indent) -> void
    {
        o << pre(indent) << "postfix-expression\n";
    }

    auto start(unqualified_id_node const& n, int indent) -> void
    {
        o << pre(indent) << "unqualified-id\n";
    }

    auto start(qualified_id_node const& n, int indent) -> void
    {
        o << pre(indent) << "qualified-id\n";
    }

    auto start(id_expression_node const& n, int indent) -> void
    {
        o << pre(indent) << "id-expression\n";
    }

    auto start(statement_node const& n, int indent) -> void
    {
        o << pre(indent) << "statement\n";
    }

    auto start(compound_statement_node const& n, int indent) -> void
    {
        o << pre(indent) << "compound-statement\n";
    }

    auto start(selection_statement_node const& n, int indent) -> void
    {
        o << pre(indent) << "selection-statement\n";
        o << pre(indent+1) << "is_constexpr: " << as<std::string>(n.is_constexpr) << "\n";
    }

    auto start(return_statement_node const& n, int indent) -> void
    {
        o << pre(indent) << "return-statement\n";
    }

    auto start(function_type_node const& n, int indent) -> void
    {
        o << pre(indent) << "function\n";
        o << pre(indent+1) << "throws: " << as<std::string>(n.throws) << "\n";
    }

    auto start(function_returns_tag const& n, int indent) -> void
    {
        o << pre(indent) << "function returns\n";
    }

    auto start(declaration_node const& n, int indent) -> void
    {
        o << pre(indent) << "declaration\n";
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

    auto start(parameter_declaration_list_node const& n, int indent) -> void
    {
        o << pre(indent) << "parameter-declaration-list\n";
    }

    auto start(translation_unit_node const& n, int indent) -> void
    {
        o << pre(indent) << "translation-unit\n";
    }

    auto start(auto const&, int indent) -> void
    {
        o << pre(indent) << "UNRECOGNIZED -- FIXME\n";
    }

    auto end(auto const&, int indent) -> void
    {
        //  Ignore other node types
    }
};


}

#endif
