
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0


//===========================================================================
//  Lowering to Cpp1 syntax
//===========================================================================

#ifndef __CPP2_TOCPP1
#define __CPP2_TOCPP1

#include "sema.h"


namespace cpp2 {

//-----------------------------------------------------------------------
// 
//  Stringingizing helpers
// 
//-----------------------------------------------------------------------

auto to_string_view(unqualified_id_node const& n) -> std::string_view
{
    return *n.identifier;
}

auto to_string(qualified_id_node const& n) -> std::string
{
    std::string s;
    for (bool first = true; auto const& id : n.ids)
    {
        if (!first) {
            s += "::";
        }
        s += *id->identifier;
        first = false;
    }
    return s;
}

auto to_string(id_expression_node const& n) -> std::string
{
    using enum id_expression_node::active;
    switch (n.id.index()) {
    break;case qualified:
        return to_string( *std::get<qualified>(n.id) );
    break;case unqualified:
        return std::string( to_string_view( *std::get<unqualified>(n.id) ) );
    }

    assert(!"invalid id_expression");
    return "INVALID ID_EXPRESSION"; // to shut up the compiler
}


//-----------------------------------------------------------------------
// 
//  Visitor for emitting a parse tree in Cpp1 syntax
// 
//-----------------------------------------------------------------------
//
class to_cpp1_printer : printing_visitor<>
{
    using printing_visitor::printing_visitor;

    using enum declaration_node::active;
    using enum symbol::active;

    std::vector<comment> const& comments;
    int next_comment = 0;   // index of the next comment not yet printed

    bool            declarations_only  = true;
    source_position prev_token_pos;

    bool            in_parameter_list  = false;
    bool            in_first_parameter = false;
    bool            in_parameter_init  = true;

    int curr_column = 0;

    expression_list_node::term const* current_expression_list_term = nullptr;

public:
    to_cpp1_printer(
        std::ostream&               out,
        std::vector<comment> const& comments
    )
        : printing_visitor{out}
        , comments{comments}
    {
    }

    //  In the first pass we will print only declarations (the default).
    //  For the second pass this funciton enables printing definitions.
    //
    auto enable_definitions() -> void {
        declarations_only = false;
    }


    //  Printing helpers so we can track number of chars emitted so far in current line
    //
    void print_newline() {
        o << "\n";
        curr_column = 0;
    }

    void print(std::string_view s) {
        o << s;
        curr_column += s.length();
    }


    //  To catch up with displaying comments
    //
    auto flush_comments( source_position pos )
    {
        //  Remember position so we can know at the end whether we consumed any comments
        auto old_next_comment = next_comment;

        while (
            next_comment < comments.size() &&
            comments[next_comment].position < pos
            )
        {
            if (comments[next_comment].kind == comment::comment_kind::line_comment)
            {
                //  If this comment was not on the same line as the previous token
                //  we saw, move to a new line with the original indent level
                //
                if (comments[next_comment].position.lineno != prev_token_pos.lineno) {
                    print_newline();
                    print( pad(comments[next_comment].position.colno) );
                }

                //  Otherwise, move to later on the current line corresponding to the
                //  comment's original column position, if we haven't passed that already
                else {
                    print( pad( comments[next_comment].position.colno - curr_column ) );
                }

                //  Emit the comment text and finish the line
                print( comments[next_comment].text );
            }

            else
            {
                // For a stream comment, just emit it where we are with a little whitespace
                print( "  " );
                print( comments[next_comment].text );
                print( "  " );
            }

            ++next_comment;
        };

        //  If we've emitted any comments, now catch up on vertical whitespace...
        //  emit extra blank lines corresponding to the lineno of the last emitted
        //  comment and the lineno of the current position
        //
        if (old_next_comment < next_comment) {

            auto lines_to_add = pos.lineno - comments[next_comment - 1].position.lineno;
            while (lines_to_add--) {
                print_newline();
            }
        }
    }

    auto start(token const& n, int) -> void
    {
        prev_token_pos = n.position();
    }

    //auto start(expression_node const& n, int) -> void
    //{
    //    o << pre(indent) << "expression\n";
    //    //  If we are in an expression-list
    //    if (current_expression_list_term) {
    //        if (current_expression_list_term->pass == passing_style::out) {
    //            o << pre(indent+1) << "out\n";
    //        }
    //        ++current_expression_list_term;
    //    }
    //}

    //auto start(expression_list_node const& n, int) -> void
    //{
    //    //  We're going to use the pointer as an iterator
    //    current_expression_list_term = &n.expressions[0];
    //    o << pre(indent) << "expression-list\n";
    //}

    //auto end(expression_list_node const& n, int) -> void
    //{
    //    //  If we're ending an expression list node, our pointer should be
    //    //  pointing to one past the end of the expressions
    //    assert( current_expression_list_term == &n.expressions[0] + n.expressions.size() );
    //    current_expression_list_term = nullptr;
    //}

    //auto start(primary_expression_node const& n, int) -> void
    //{
    //    o << pre(indent) << "primary-expression\n";
    //}

    //auto start(prefix_expression_node const& n, int) -> void
    //{
    //    o << pre(indent) << "prefix-expression\n";
    //}

    //template<String Name, typename Term>
    //auto start(binary_expression_node<Name, Term> const& n, int) -> void
    //{
    //    o << pre(indent) << Name.value << "-expression\n";
    //}

    //auto start(expression_statement_node const& n, int) -> void
    //{
    //    o << pre(indent) << "expression-statement\n";
    //}

    //auto start(postfix_expression_node const& n, int) -> void
    //{
    //    o << pre(indent) << "postfix-expression\n";
    //}

    //auto start(unqualified_id_node const& n, int) -> void
    //{
    //    o << pre(indent) << "unqualified-id\n";
    //}

    //auto start(qualified_id_node const& n, int) -> void
    //{
    //    o << pre(indent) << "qualified-id\n";
    //}

    //auto start(id_expression_node const& n, int) -> void
    //{
    //    o << pre(indent) << "id-expression\n";
    //}


    //auto start(statement_node const& n, int) -> void
    //{
    //    if (!in_parameter_list || in_parameter_init) {
    //        print( "statement_eh" );
    //    }
    //}


    //auto start(compound_statement_node const& n, int) -> void
    //{
    //    o << pre(indent) << "compound-statement\n";
    //}

    //auto start(selection_statement_node const& n, int) -> void
    //{
    //    o << pre(indent) << "selection-statement\n";
    //    o << pre(indent+1) << "is_constexpr: " << as<std::string>(n.is_constexpr) << "\n";
    //}

    auto start(declaration_node const& n, int) -> void
    {
        flush_comments( n.position() );

        if (n.is(function)) {
            print( "auto " );
            print( *n.identifier->identifier );


        }
        else if (n.is(variable)) {


        }






    }

    auto start(parameter_declaration_node const& n, int) -> void
    {
        if (!in_first_parameter) {
            print( ", " );
        }

        assert( n.declaration->is(declaration_node::active::variable ) );

        auto const& id_expr = *std::get<declaration_node::active::variable>(n.declaration->type);
        print( to_string( id_expr ) );

        print( " " );
        using enum passing_style;
        switch (n.pass) {
        break;case in     : print ( "const&" );
        break;case inout  : print ( "&" );
        break;case out    : print ( "&" );
        break;case move   : print ( "&&" );
        break;case forward: assert(false); // TODO: support forward parameters
        }

        print( " " );
        print( to_string_view( *n.declaration->identifier ) );

        // TODO: initializers
        //if (n.declaration->initializer) {
        //    print ( " = " );
        //    in_parameter_init = true;
        //    n.declaration->initializer->visit(*this, 0);    // recurse to statement_node
        //    in_parameter_init = false;
        //}


        //o << pre(indent+1);
        //using enum parameter_declaration_node::modifier;
        //switch (n.mod) {
        //break;case implicit  : o << "implicit";
        //break;case virtual_  : o << "virtual";
        //break;case override_ : o << "override";
        //break;case final_    : o << "final";
        //}
        //o << "\n";

        //assert( n.declaration );

        in_first_parameter = false; // remember that we already did a parameter
    }

    auto start(parameter_declaration_list_node const& n, int) -> void
    {
        print( "( ");
        in_parameter_list = true;
        in_first_parameter = true;
    }

    auto end(parameter_declaration_list_node const& n, int) -> void
    {
        print( " )");
        in_parameter_list = false;
    }

    auto start(translation_unit_node const& n, int) -> void
    {
        prev_token_pos = n.position();
        //current_line_start = n.declarations.front()->identifier->identifier;
    }

    auto start(auto const&, int) -> void
    {
        //o << pre(indent) << "UNRECOGNIZED -- FIXME\n";
    }

    auto end(auto const&, int) -> void
    {
        //  Ignore other node types
    }
};



}

#endif
