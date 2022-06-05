
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0


//===========================================================================
//  Parser
//===========================================================================

#ifndef __CPP2_PARSE
#define __CPP2_PARSE

#include "lex.h"
#include <memory>
#include <map>
#include <variant>
#include <iostream>
#include <algorithm>


namespace cpp2 {

//-----------------------------------------------------------------------
//  Operator categorization
//

//G prefix-operator:
//G     one of  !
//G
auto is_prefix_operator(lexeme l) -> bool
{ 
    switch (l) {
    break;case lexeme::Not:
        return true;
    }
    return false;
}


//G postfix-operator:
//G     one of  .  ++  --  [  (  *  &  ~  $
//G
auto is_postfix_operator(lexeme l)  -> bool
{ 
    switch (l) {
    break;case lexeme::Dot:
          case lexeme::PlusPlus:
          case lexeme::MinusMinus:
          case lexeme::LeftBracket:
          case lexeme::LeftParen:
          case lexeme::Star:
          case lexeme::Ampersand:
          case lexeme::Tilde:
          case lexeme::Dollar:
        return true;
    }
    return false;
}


//G assignment-operator:
//G     one of  = *= /= %= += -= >>= <<= &= ^= |=
//G
auto is_assignment_operator(lexeme l) -> bool
{ 
    switch (l) {
    break;case lexeme::Assignment:
          case lexeme::StarEq:
          case lexeme::SlashEq:
          case lexeme::ModuloEq:
          case lexeme::PlusEq:
          case lexeme::MinusEq:
          case lexeme::RightShiftEq:
          case lexeme::LeftShiftEq:
          case lexeme::AmpersandEq:
          case lexeme::XorEq:
          case lexeme::PipeEq:
        return true;
    }
    return false;
}


//-----------------------------------------------------------------------
// 
//  Parse tree node types
// 
//-----------------------------------------------------------------------
//

struct primary_expression_node
{
    // TODO
    token const* identifier;

    primary_expression_node( token const* tok) 
        : identifier{ tok }
    {
    }

    auto position() const -> source_position
    {
        assert (identifier);
        return identifier->position();
    }

    auto visit(auto& v, int depth) -> void {
        v.start(*this, depth);
        assert (identifier);
        v.start(*identifier, depth+1);
        v.end(*this, depth);
    }
};


struct postfix_expression_node;

struct unary_expression_node
{
    std::vector<token const*> ops;
    std::unique_ptr<postfix_expression_node> expr;

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

using is_as_expression_node          = binary_expression_node< "is-as"          , unary_expression_node          >;
using multiplicative_expression_node = binary_expression_node< "multiplicative" , is_as_expression_node          >;
using additive_expression_node       = binary_expression_node< "additive"       , multiplicative_expression_node >;
using shift_expression_node          = binary_expression_node< "shift"          , additive_expression_node       >;
using compare_expression_node        = binary_expression_node< "compare"        , shift_expression_node          >;
using relational_expression_node     = binary_expression_node< "relational"     , compare_expression_node        >;
using equality_expression_node       = binary_expression_node< "equality"       , relational_expression_node     >;
using logical_and_expression_node    = binary_expression_node< "logical-and"    , equality_expression_node       >;
using logical_or_expression_node     = binary_expression_node< "logical-or"     , logical_and_expression_node    >;
using expression_node                = binary_expression_node< "expression"     , logical_or_expression_node     >;
using expression_list_node           = binary_expression_node< "expression-list", expression_node                >;

struct expression_statement_node
{
    std::unique_ptr<expression_node> expr;

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
        std::unique_ptr<expression_list_node> expr_list;    // used if *op is [ or ( - can be null
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

auto unary_expression_node::position() const -> source_position
{
    if (std::ssize(ops) > 0) {
        return ops.front()->position();
    }
    assert (expr);
    return expr->position();
}

auto unary_expression_node::visit(auto& v, int depth) -> void
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
    enum active { empty=0, qualified, unqualified };
    std::variant<
        std::monostate,
        std::unique_ptr<qualified_id_node>,
        std::unique_ptr<unqualified_id_node>
    > id;

    auto position() const -> source_position
    {
        switch (id.index())
        {
        break;case empty:
            return { 0, 0 };

        break;case qualified: {
            auto const& s = std::get<qualified>(id);
            assert (s);
            return s->position();
        }

        break;case unqualified: {
            auto const& s = std::get<unqualified>(id);
            assert (s);
            return s->position();
        }

        break;default:
            assert (!"illegal id_expression_node state");
            return { 0, 0 };
        }
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        visit<qualified  >(v, depth);
        visit<unqualified>(v, depth);
        v.end(*this, depth);
    }

    template <int I>
    auto visit(auto& v, int depth) -> void 
    {
        if (id.index() == I) 
        {
            auto const& s = std::get<I>(id);
            assert (s);
            s->visit(v, depth+1);
        }
    }
};

struct statement_node;

struct compound_statement_node
{
    source_position pos;
    std::vector<std::unique_ptr<statement_node>> statements;

    compound_statement_node(source_position pos)
        : pos{ pos }
    {
    }

    auto position() const -> source_position
    {
        return pos;
    }

    auto visit(auto& v, int depth) -> void;
};

struct selection_statement_node
{
    bool                                     is_constexpr = false;
    token const*                             identifier;
    std::unique_ptr<expression_node>         expression;
    std::unique_ptr<compound_statement_node> true_branch;
    std::unique_ptr<compound_statement_node> false_branch;

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

struct declaration_node;
struct statement_node
{
    enum active { expression=0, compound, selection, declaration };
    std::variant<
        std::unique_ptr<expression_statement_node>,
        std::unique_ptr<compound_statement_node>,
        std::unique_ptr<selection_statement_node>,
        std::unique_ptr<declaration_node>
    > statement;

    auto position() const -> source_position;

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        visit<expression >(v, depth);
        visit<compound   >(v, depth);
        visit<selection  >(v, depth);
        visit<declaration>(v, depth);
        v.end(*this, depth);
    }

    template <int I>
    auto visit(auto& v, int depth) -> void 
    {
        if (statement.index() == I) 
        {
            auto const& s = std::get<I>(statement);
            assert (s);
            s->visit(v, depth+1);
        }
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
    enum class style { in=0, inout, out, move, forward };
    style pass = style::in;
    std::unique_ptr<declaration_node> declaration;

    auto position() const -> source_position;

    auto visit(auto& v, int depth) -> void;
};


struct parameter_declaration_list_node
{
    std::vector<std::unique_ptr<parameter_declaration_node>> parameters;

    auto position() const -> source_position
    {
        assert (std::ssize(parameters) && parameters.front());
        return parameters.front()->position();
    }

    auto visit(auto& v, int depth) -> void
    {
        v.start(*this, depth);
        for (auto const& x : parameters) {
            assert(x);
            v.start(*x, depth);
        }
        v.end(*this, depth);
    }
};


struct declaration_node
{
    std::unique_ptr<unqualified_id_node> identifier;

    enum active { function, variable };
    std::variant<
        std::unique_ptr<parameter_declaration_list_node>,
        std::unique_ptr<id_expression_node>
    > type;

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
        visit<function>(v, depth+1);
        visit<variable>(v, depth+1);
        if (initializer) {
            initializer->visit(v, depth+1);
        }
        v.end(*this, depth);
    }

    template <int I>
    auto visit(auto& v, int depth) -> void 
    {
        if (type.index() == I) 
        {
            auto const& s = std::get<I>(type);
            assert (s);
            s->visit(v, depth+1);
        }
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
    return declaration->position();
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
        assert (std::ssize(declarations) > 0 && declarations.front());
        return declarations.front()->position();
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
    std::vector<error>& errors;

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
        std::vector<error>& errors
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
        if (pos + num < std::ssize(*tokens_)) {
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
    //GT     TODO
    //G
    auto primary_expression() 
        -> std::unique_ptr<primary_expression_node>
    {
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
            auto n = std::make_unique<primary_expression_node>( &curr() );
            next();
            return n;
        }
        return {};
    }


    //G postfix-expression:
    //G     primary-expression { primary-postfix-operator | [ expression-list ] | ( {expression-list}? ) }*
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

        while (is_postfix_operator(curr().type())) {
            auto term = postfix_expression_node::term(&curr());
            next();

            switch (term.op->type()) {
            break;case lexeme::LeftBracket:
                term.expr_list = expression_list();
                if (!term.expr_list) {
                    error("subscript expression [ ] must not be empty");
                }
                if (curr().type() != lexeme::RightBracket) {
                    error("unexpected text - [ is not followed by a closing ]");
                }
                next();

            break;case lexeme::LeftParen:
                term.expr_list = expression_list();
                if (curr().type() != lexeme::RightParen) {
                    error("unexpected text - ( is not followed by a closing )");
                }
                next();
            }

            n->ops.push_back( std::move(term) );
        }
        return n;
    }


    //G unary-expression:
    //G     { prefix-operator }* postfix-expression
    //GT     await-expression
    //GT     sizeof unary-expression
    //GT     sizeof ( type-id )
    //GT     sizeof ... ( identifier )
    //GT     alignof ( type-id )
    //GT     noexcept-expression
    //G
    auto unary_expression() 
        -> std::unique_ptr<unary_expression_node>
    {
        auto n = std::make_unique<unary_expression_node>();
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
    //G     unary-expression { { "is" "as" } unary-expression }*
    //G
    auto is_as_expression() {
        return binary_expression<is_as_expression_node> (
            [](token const& t){ 
                std::string_view s{t};
                return t.type() == lexeme::Keyword && (s == "is" || s == "as");
            },
            [this]{ return unary_expression(); }
        );
    }

    //G multiplicative-expression:
    //G     is-as-expression { { * / % } is-as-expression }*
    //G
    auto multiplicative_expression() {
        return binary_expression<multiplicative_expression_node> (
            [](token const& t){ return t.type() == lexeme::Star || t.type() == lexeme::Slash || t.type() == lexeme::Modulo; },
            [this]{ return is_as_expression(); }
            );
    }

    //G additive-expression:
    //G     multiplicative-expression { { + - } multiplicative-expression }*
    //G
    auto additive_expression() {
        return binary_expression<additive_expression_node> (
            [](token const& t){ return t.type() == lexeme::Plus || t.type() == lexeme::Minus; },
            [this]{ return multiplicative_expression(); }
        );
    }

    //G shift-expression:
    //G     additive-expression { { << >> } additive-expression }*
    //G
    auto shift_expression() {
        return binary_expression<shift_expression_node> (
            [](token const& t){ return t.type() == lexeme::LeftShift || t.type() == lexeme::RightShift; },
            [this]{ return additive_expression(); }
        );
    }

    //G compare-expression:
    //G     shift-expression { { <=> } shift-expression }*
    //G
    auto compare_expression() {
        return binary_expression<compare_expression_node> (
            [](token const& t){ return t.type() == lexeme::Spaceship; },
            [this]{ return shift_expression(); }
        );
    }

    //G relational-expression:
    //G     compare-expression { { < <= > >= } compare-expression }*
    //G
    auto relational_expression() {
        return binary_expression<relational_expression_node> (
            [](token const& t){ return t.type() == lexeme::Less || t.type() == lexeme::LessEq || t.type() == lexeme::Greater || t.type() == lexeme::GreaterEq; },
            [this]{ return compare_expression(); }
        );
    }

    //G equality-expression:
    //G     relational-expression { { == != } relational-expression }*
    //G
    auto equality_expression() {
        return binary_expression<equality_expression_node> (
            [](token const& t){ return t.type() == lexeme::EqualComparison || t.type() == lexeme::NotEqualComparison; },
            [this]{ return relational_expression(); }
        );
    }

    //G logical_and-expression:
    //G     equality-expression { && equality-expression }*
    //G
    auto logical_and_expression() {
        return binary_expression<logical_and_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalAnd; },
            [this]{ return equality_expression(); }
        );
    }

    //  constant-expression:    // don't need intermediate production, just use:
    //  conditional-expression: // don't need intermediate production, just use:
    //G logical_or-expression:
    //G     logical_and-expression { || logical_and-expression }*
    //G
    auto logical_or_expression() {
        return binary_expression<logical_or_expression_node> (
            [](token const& t){ return t.type() == lexeme::LogicalOr; },
            [this]{ return logical_and_expression(); }
        );
    }

    //  condition:  // don't need intermediate production, just use:
    //G  expression:
    //G     logical_or-expression { assignment-operator logical_or-expression }*
    //G
    // TODO: add support for parenthesized expressions
    //GT    ( expression )
    auto expression() {
        return binary_expression<expression_node> (
            [](token const& t){ return is_assignment_operator(t.type()); },
            [this]{ return logical_or_expression(); }
        );
    }

    //GT expression-list
    //GT     expression { , expression }*
    auto expression_list() -> std::unique_ptr<expression_list_node> {
        return binary_expression<expression_list_node> (
            [](token const& t){ return t.type() == lexeme::Comma; },
            [this]{ return expression(); }
        );
    }


    //G unqualified-id:
    //G     identifier
    //GT     operator-function-id
    //GT     conversion-function-id
    //GT     literal-operator-id
    //GT     template-id
    auto unqualified_id() -> std::unique_ptr<unqualified_id_node> 
    {
        if (curr().type() != lexeme::Identifier &&
            curr().type() != lexeme::Keyword)
        {
            return {};
        }
        auto n = std::make_unique<unqualified_id_node>( &curr() );
        next();
        return n;
    }


    //G qualified-id:
    //G     unqualified-id { . unqualified-id }*
    //G
    auto qualified_id() -> std::unique_ptr<qualified_id_node> 
    {
        auto n = std::make_unique<qualified_id_node>();

        //  Remember current position, because we need to look ahead to the .
        auto start_pos = pos;
        auto id = unqualified_id();
        if (!id || curr().type() != lexeme::Dot) {
            pos = start_pos;    // backtrack
            return {};
        }

        n->ids.push_back( std::move(id) );

        assert (curr().type() == lexeme::Dot);
        while (curr().type() == lexeme::Dot) {
            next();
            id = unqualified_id();
            if (!id) {
                error("invalid text, . should be followed by a nested name");
            }
            n->ids.push_back( std::move(id) );
        }

        return n;
    }


    //G id-expression
    //G     unqualified-id
    //GT     qualified-id
    auto id_expression() -> std::unique_ptr<id_expression_node> 
    {
        auto n = std::make_unique<id_expression_node>();
        if (auto id = qualified_id()) {
            n->id = std::move(id);
            assert (n->id.index() == id_expression_node::qualified);
            return n;
        }
        else if (auto id = unqualified_id()) {
            n->id = std::move(id);
            assert (n->id.index() == id_expression_node::unqualified);
            return n;
        }
        else {
            return {};
        }
    }


    //G expression-statement:
    //G     expression ;
    //G
    auto expression_statement() -> std::unique_ptr<expression_statement_node> 
    {
        auto n = std::make_unique<expression_statement_node>();
        if (!(n->expr = expression())) {
            return {};
        }
        if (curr().type() != lexeme::Semicolon) {
            error("expression-statement does not end with semicolon");
            return {};
        }
        next();
        return n;
    }


    //G selection-statement:
    //G     if {constexpr}? expression compound-statement { else compound-statement }?
    //GT     switch expression compound-statement
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
            return n;
        }
        next();

        if (auto s = compound_statement()) {
            n->false_branch = std::move(s);
        }
        else {
            error("invalid else branch body");
            return {};
        }

        return n;
    }


    //G statement:
    //G     selection-statement
    //G     compound-statement
    //G     declaration-statement
    //G     expression-statement
    // 
    //GT     iteration-statement
    //GT     jump-statement
    //GT     try-block
    //G
    //GT     attribute-specifier-seqopt expression-statement
    //GT     attribute-specifier-seqopt compound-statement
    //GT     attribute-specifier-seqopt selection-statement
    //GT     attribute-specifier-seqopt iteration-statement
    //GT     attribute-specifier-seqopt jump-statement
    //GT     declaration-statement
    //GT     attribute-specifier-seqopt try-block
    auto statement() -> std::unique_ptr<statement_node> 
    {
        auto n = std::make_unique<statement_node>();

        if (auto s = selection_statement()) {
            n->statement = std::move(s);
            assert (n->statement.index() == statement_node::selection);
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

        else if (auto s = expression_statement()) {
            n->statement = std::move(s);
            assert (n->statement.index() == statement_node::expression);
            return n;
        }

        else {
            return {};
        }
    }


    //G compound-statement:
    //G     {  statement*  }
    auto compound_statement() -> std::unique_ptr<compound_statement_node> 
    {
        if (curr().type() != lexeme::LeftBrace) {
            return {};
        }

        auto n = std::make_unique<compound_statement_node>( curr().position() );
        next();
        auto s = std::unique_ptr<statement_node>();

        while (curr().type() != lexeme::RightBrace) {
            auto s = statement();
            if (!s) {
                error("invalid statement in compound-statement");
                return {};
            }
            n->statements.push_back( std::move(s) );
        }

        next();
        return n;
    }


    //G parameter-declaration
    //G     { in | inout | out | move | forward }?  declaration
    //G
    auto parameter_declaration() -> std::unique_ptr<parameter_declaration_node> 
    {
        auto n = std::make_unique<parameter_declaration_node>();
        n->pass = parameter_declaration_node::style::in;    // should be redundant with default

        if (curr().type() == lexeme::Identifier) { 
            if (curr() == "in") {
                // defaulted above
                next();
            }
            else if (curr() == "inout") {
                n->pass = parameter_declaration_node::style::inout;
                next();
            }
            else if (curr() == "out") {
                n->pass = parameter_declaration_node::style::out;
                next();
            }
            else if (curr() == "move") {
                n->pass = parameter_declaration_node::style::move;
                next();
            }
            else if (curr() == "forward") {
                n->pass = parameter_declaration_node::style::forward;
                next();
            }
        }

        if (!(n->declaration = declaration())) {
            return {};
        }

        return n;
    }


    //G parameter-declaration-list
    //G     ( parameter-declaration { , parameter }* )
    //G
    auto parameter_declaration_list() -> std::unique_ptr<parameter_declaration_list_node> 
    {
        if (curr().type() != lexeme::LeftParen) {
            return {};
        }
        next();

        auto n = std::make_unique<parameter_declaration_list_node>();
        auto param = std::make_unique<parameter_declaration_node>();

        while (param = parameter_declaration()) {
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

        next();
        return n;
    }


    //G declarator:
    //GT     type
    //G     function-type
    //G     id-expression
    //G
    //G function-type:
    //G     ( {parameter-declaration-list}? ) -> {id-expression}?
    //G


    //G declaration:
    //G     identifier : {declarator}? = statement
    //
    //GT     function-definition
    //GT     block-declaration
    //GT     nodeclspec-function-declaration
    //GT     template-declaration
    //GT     deduction-guide
    //GT     explicit-instantiation
    //GT     explicit-specialization
    //GT     export-declaration
    //GT     linkage-specification
    //GT     namespace-definition
    //GT     empty-declaration
    //GT     attribute-declaration
    //GT     module-import-declaration
    //
    auto declaration() -> std::unique_ptr<declaration_node> 
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
        if (auto t = parameter_declaration_list()) {
            n->type = std::move(t);
            assert (n->type.index() == declaration_node::function);
        }
        else if (auto t = id_expression()) {
            n->type = std::move(t);
            assert (n->type.index() == declaration_node::variable);
        }
        else {
            n->type = std::make_unique<id_expression_node>();
            assert (n->type.index() == declaration_node::variable);
        }

        //  Next is optionally = followed by an initializer
        if (curr().type() != lexeme::Assignment) {
            if (curr().type() == lexeme::Semicolon) {
                next(); // declaration
            }
            return n;
        }
        next();

        if (!(n->initializer = statement())) {
            error("ill-formed initializer");
            next();
            return {};
        }

        return n;
    }


    //G translation-unit:
    //G     { declaration }*
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
    inline static std::string indent_str     = std::string( 1024, ' ' );

    auto pre(int indent) -> std::string_view
    {
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
struct parse_tree_printer : printing_visitor
{
    using printing_visitor::printing_visitor;

    auto start(token const& n, int indent) -> void
    {
        o << pre(indent) << n.to_string() << "\n";
    }

    auto start(primary_expression_node const& n, int indent) -> void
    {
        o << pre(indent) << "primary-expression\n";
    }

    auto start(unary_expression_node const& n, int indent) -> void
    {
        o << pre(indent) << "unary-expression\n";
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

    auto start(declaration_node const& n, int indent) -> void
    {
        o << pre(indent) << "declaration\n";
    }

    auto start(parameter_declaration_node const& n, int indent) -> void
    {
        using enum parameter_declaration_node::style;
        o << pre(indent) << "parameter-declaration\n";
        o << pre(indent+1);
        switch (n.pass) {
        break;case in     : o << "in";
        break;case inout  : o << "inout";
        break;case out    : o << "out";
        break;case move   : o << "move";
        break;case forward: o << "forward";
        }
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
