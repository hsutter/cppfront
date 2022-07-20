
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0


//===========================================================================
//  cppfront
//===========================================================================

#include "sema.h"
#include <iostream>


namespace cpp2 {

//-----------------------------------------------------------------------
// 
//  Stringingizing helpers
// 
//-----------------------------------------------------------------------

auto pad(int padding) -> std::string_view
{
    static std::string indent_str = std::string( 1024, ' ' );    // "1K should be enough for everyone"

    if (padding < 1) { 
        return "";
    }

    return {
        indent_str.c_str(),
        as<size_t>( std::min( padding, as<int>(std::ssize(indent_str))) )
    };
}


//-----------------------------------------------------------------------
// 
//  cppfront: a compiler instance
// 
//-----------------------------------------------------------------------
//
class cppfront
{
    std::string sourcefile;
    std::vector<error> errors;

    //  For building
    //
    source source;
    tokens tokens;
    parser parser;
    sema   sema;
    bool   source_loaded = true;

    //  For lowering
    //    
    bool            declarations_only  = true;  // print declarations only in first pass
    std::ofstream   out                = {};    // Cpp1 syntax output file
    int             next_comment       = 0;     // index of the next comment not yet printed
    source_position last_pos           = {};
    source_position preempt_pos        = {};

public:
    //-----------------------------------------------------------------------
    //  Constructor
    // 
    //  filename    the source file to be processed
    //
    cppfront(std::string const& filename)
        : sourcefile{filename}
        , source{errors}
        , tokens{errors}
        , parser{errors}
        , sema  {errors}
    {
        //  "Constraints enable creativity in the right directions"
        //  sort of applies here
        //
        if (!sourcefile.ends_with(".cpp2"))
        {
            errors.emplace_back(
                source_position{-1, -1}, 
                "source filename must end with .cpp2: " + sourcefile
            );
        }

        //  Load the program file into memory
        //
        else if (!source.load(sourcefile))
        {
            if (errors.empty()) {
                errors.emplace_back(
                    source_position{-1, -1}, 
                    "file not found: " + sourcefile
                );
            }
            source_loaded = false;
        }

        else
        {
            //  Tokenize
            //
            tokens.lex( source.get_lines() );

            //  Parse
            //
            for (auto const& [line, entry] : tokens.get_map()) {
                if (!parser.parse(entry)) {
                    errors.emplace_back(
                        source_position{line, 0}, 
                        "parse failed for section starting here"
                    );
                }
            }

            //  Sema
            parser.visit( sema );

            //debug_print();

            if (!sema.apply_local_rules()) {
                errors.emplace_back(
                    source_position{-1, -1}, 
                    "error encountered while applying local initialization rules"
                );
            }
        }
    }


    //-----------------------------------------------------------------------
    //  In the first pass we will print only declarations (the default).
    //  For the second pass this function enables printing definitions.
    //
    auto enable_definitions() -> void {
        declarations_only = false;
    }


    //-----------------------------------------------------------------------
    //  Printing helpers so we can track number of chars emitted so far in current line
    //
    auto print_newline() -> void {
        out << "\n";
        ++last_pos.lineno;
        last_pos.colno = 1;
    }

    auto print(std::string_view s) -> void {
        out << s;

        auto last_newline = std::string::npos;
        auto newline_pos  = 0;
        while ((newline_pos = s.find('\n', newline_pos)) != std::string::npos) {
            ++last_pos.lineno;
            last_newline = newline_pos;
            ++newline_pos;
        }

        if (last_newline != std::string::npos) {
            last_pos.colno = s.length() - last_newline;
        }
        else {
            last_pos.colno += s.length();
        }
    }

    auto preempt_position(source_position pos) -> void {
        preempt_pos = pos;
    }

    auto print(std::string_view s, source_position pos) -> void {
        align_to( preempt_pos == source_position{} ? pos : preempt_pos );
        print(s);
        preempt_pos = {};
    }


    //-----------------------------------------------------------------------
    //  To position ourselves as close to the programmer's original location
    //  as possible, and to catch up with displaying comments
    //
    auto align_to( source_position pos ) -> void
    {
        auto& comments = tokens.get_comments(); // for readability

        //  Add unprinted comments and blank lines as needed to catch up vertically
        //
        while (last_pos.lineno < pos.lineno) {

            //  If a comment goes on this line, print it
            if (next_comment < std::ssize(comments) && comments[next_comment].start.lineno == last_pos.lineno) {

                //  For a line comment, start it at the right indentation and print it
                //  with a newline end
                if (comments[next_comment].kind == comment::comment_kind::line_comment) {
                    print( pad( comments[next_comment].start.colno - last_pos.colno ) );
                    print( comments[next_comment].text );
                    assert( comments[next_comment].text.find("\n") == std::string::npos );  // we shouldn't have newlines
                    print_newline();
                }

                //  For a stream comment, pad out to its column (if we haven't passed it already)
                //  and emit it there
                else {
                    print( pad( comments[next_comment].start.colno - last_pos.colno ) );
                    print( comments[next_comment].text );
                    assert(last_pos.lineno <= pos.lineno);  // we shouldn't have overshot
                }

                ++next_comment;
            }

            //  Otherwise, just print a blank line
            else {
                print_newline();
            }
        }
        
        //  Finally, align to the target column
        //
        print( pad( pos.colno - last_pos.colno ) );

        //  Remember our new relative anchor reference point
        //  (always in terms of original source coordinates)
        //
        last_pos = pos;
    }


    //-----------------------------------------------------------------------
    //  lower_to_cpp1
    // 
    //  Emits the target file with the last '2' stripped -> .cpp
    //
    auto lower_to_cpp1() -> void
    {
        out.open( sourcefile.substr(0, std::ssize(sourcefile) - 1) );

        //  First, echo the non-Cpp2 parts
        //
        auto cpp2_found    = false;
        auto prev_line_cat = source_line::category::cpp1;

        for (lineno_t curr_lineno = 0; auto const& line : source.get_lines())
        {
            //  Skip dummy line we added to make 0-vs-1-based offsets readable
            if (curr_lineno != 0) {

                //  If it's a non-Cpp2 line, emit it
                if (line.cat != source_line::category::cpp2) {
                    //  If the previous line was Cpp2, emit a #line directive
                    if (prev_line_cat == source_line::category::cpp2) {
                        out << "#line " << curr_lineno << "\n";
                    }

                    //  Emit the original line
                    out << line.text << "\n";
                }
                else {
                    cpp2_found = true;
                }

                prev_line_cat = line.cat;
            }
            ++curr_lineno;
        }

        //  We can stop here if there's no Cpp2 code -- a file with no Cpp2
        //  should have perfect passthrough verifiable with diff, including
        //  that we didn't misidentify anything as Cpp2 including in the
        //  presence of nonstandard vendor extensions
        //
        if (!cpp2_found) {
            return;
        }

        //  If there is Cpp2 code, we have more to do...
        //  Next, bring in the Cpp2 helpers
        //
        out << "\n\n//=== Cpp2 ======================================================================"
            << "\n\n#include \"cpp2util.h\"\n";

        //  Next, emit the Cpp2 forward declarations
        //
        emit( parser.get_parse_tree() );  // starts at translation_unit_node

        out << "\n//-------------------------------------------------------------------------------\n\n";

        //  Next, emit the Cpp2 definitions
        //
        enable_definitions();
        emit( parser.get_parse_tree() );  // starts at translation_unit_node
    }


    //-----------------------------------------------------------------------
    //
    //  emit() functions - each emits a kind of node
    // 
    //  The body often mirrors the node's visit() function, unless customization
    //  is needed where Cpp1 and Cpp2 have different grammar orders
    //

    //-----------------------------------------------------------------------
    //  try_emit
    // 
    //  Helper to emit whatever is in a variant where each
    //  alternative is a smart pointer
    //
    template <int I>
    auto try_emit(auto& v) -> void {
        if (v.index() == I) {
            auto const& alt = std::get<I>(v);
            assert (alt);
            emit (*alt);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(token const& n) -> void
    {
        print(n, n.position());
    }


    //-----------------------------------------------------------------------
    //
    auto emit(unqualified_id_node const& n) -> void
    {
        print( *n.identifier, n.position() );
    }


    //-----------------------------------------------------------------------
    //
    auto emit(qualified_id_node const& n) -> void
    {
        for (bool first = true; auto const& id : n.ids)
        {
            if (first) {
                print( *id->identifier, id->identifier->position() );
                first = false;
            }
            else {
                print( "::" );
                print( *id->identifier );   // no position, we don't want to create gaps
            }
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(id_expression_node const& n) -> void
    {
        try_emit<id_expression_node::qualified  >(n.id);
        try_emit<id_expression_node::unqualified>(n.id);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(compound_statement_node const& n) -> void
    {
        print( "{", n.open_brace );

        for (auto const& x : n.statements) {
            assert(x);
            emit(*x);
        }

        print( "}", n.close_brace );
    }


    //-----------------------------------------------------------------------
    //
    auto emit(selection_statement_node const& n) -> void
    {
        assert(n.identifier);
        emit(*n.identifier);

        print ("(");
        assert(n.expression);
        emit(*n.expression);
        print (")");

        assert(n.true_branch);
        emit(*n.true_branch);

        if(n.false_branch) {
            print ("else ", n.else_pos);
            emit(*n.false_branch);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(primary_expression_node const& n) -> void
    {
        try_emit<primary_expression_node::identifier     >(n.expr);
        try_emit<primary_expression_node::expression_list>(n.expr);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(postfix_expression_node const& n) -> void
    {
        assert(n.expr);
        emit(*n.expr);

        for (auto const& x : n.ops) {
            assert(x.op);
            emit(*x.op);
            if (x.expr_list) {
                emit(*x.expr_list);
            }
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(prefix_expression_node const& n) -> void
    {
        for (auto const& x : n.ops) {
            assert(x);
            emit(*x);
        }
        assert(n.expr);
        emit(*n.expr);
    }


    //-----------------------------------------------------------------------
    //
    template<
        String   Name,
        typename Term
    >
    auto emit(binary_expression_node<Name,Term> const& n) -> void
    {
        assert(n.expr);
        emit(*n.expr);

        for (auto const& x : n.terms) {
            assert(x.op);
            emit(*x.op);
            assert(x.expr);
            emit(*x.expr);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_node const& n) -> void
    {
        assert(n.expr);
        emit(*n.expr);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_list_node const& n) -> void
    {
        for (auto const& x : n.expressions) {
            if (x.pass != passing_style::in) {
                assert(to_string_view(x.pass) == "out");
                print( "out ");
            }
            assert(x.expr);
            emit(*x.expr);
        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(expression_statement_node const& n) -> void
    {
        assert(n.expr);
        emit(*n.expr);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(statement_node const& n) -> void
    {
        try_emit<statement_node::expression >(n.statement);
        try_emit<statement_node::compound   >(n.statement);
        try_emit<statement_node::selection  >(n.statement);
        try_emit<statement_node::declaration>(n.statement);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(parameter_declaration_node const& n) -> void
    {
        //  Can't declare functions as parameters -- only pointers to functions which are objects
        assert( n.declaration );
        assert( n.declaration->is(declaration_node::object) );

        auto const& id_expr = *std::get<declaration_node::object>(n.declaration->type);
        preempt_position( n.position() );
        emit( id_expr );

        switch (n.pass) {
        using enum passing_style;
        break;case in     : print ( " const&" );
        break;case inout  : print ( "&" );
        break;case out    : print ( "&" );
        break;case move   : print ( "&&" );
        break;case forward: assert(false); // TODO: support forward parameters
        }

        print( " " );
        emit( *n.declaration->identifier );

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
    }


    //-----------------------------------------------------------------------
    //
    auto emit(parameter_declaration_list_node const& n) -> void
    {
        print( "(", n.pos_open_paren );

        for (auto first = true; auto const& x : n.parameters) {
            if (!first) {
                print( ", " );
            }
            assert(x);
            emit(*x);
            first = false;
        }

        //  If the ) is on the same line as the previous token
        auto adjusted_pos = n.pos_close_paren;
        if (last_pos.lineno == n.pos_close_paren.lineno) {
            //  Then ignore the original column number - this is so that when
            //  the Cpp2 source is longer than the Cpp1 source (which can
            //  happen when we change `inout` to `&`) we don't needlessly
            //  space the ) too far right visually
            adjusted_pos.colno = 0;
        }
        print( ")", adjusted_pos );
    }


    //-----------------------------------------------------------------------
    //
    auto emit(declaration_node const& n) -> void
    {
        print( "auto ", n.position() );
        print( *n.identifier->identifier );

        //  Function
        if (n.is(declaration_node::function)) {

            //  Function declaration
            emit( *std::get<declaration_node::function>(n.type) );
            if (declarations_only) {
                print( ";" );
                last_pos = n.decl_end;
                print_newline();
                return;
            }

            //  Function body
            assert( n.initializer );
            preempt_position(n.equal_sign);
            emit( *n.initializer );
        }

        //  Object
        else if (n.is(declaration_node::object)) {

            //  We shouldn't get to any objects in the first declarations-only pass
            assert (!declarations_only);

            print( " = ", n.equal_sign );
            emit( *std::get<declaration_node::object>(n.type) );
            print( " { ", n.equal_sign );

            assert( n.initializer );
            emit( *n.initializer );

            print( " };" );

        }
    }


    //-----------------------------------------------------------------------
    //
    auto emit(translation_unit_node const& n) -> void
    {
        //  Restart positioning info for this pass
        //
        next_comment = 0;
        last_pos     = {};
        auto next_map_section = tokens.get_map().cbegin();

        //  Emit each declaration
        //
        for (auto const& x : n.declarations)
        {
            //  If we're entering a new Cpp2 code section, we need to
            //  reanchor last_pos to be relative to that section
            //
            if (next_map_section != tokens.get_map().cend() &&
                last_pos.lineno < next_map_section->first /*lineno*/)
            {
                last_pos = { next_map_section->first, 0 };
                ++next_map_section;
            }

            //  And then emit this declaration
            //
            assert(x);
            emit(*x);
        }
    }


    //-----------------------------------------------------------------------
    //  debug_print
    //
    auto debug_print() -> void
    {
        for (auto&& error : errors) {
            error.print(std::cerr, strip_path(sourcefile));
        }

        //  Only create debug output files if we managed to load the source file.
        //
        if (source_loaded)
        {
            auto out_source     = std::ofstream{ sourcefile+"-source"  };
            source.debug_print( out_source     );

            auto out_tokens     = std::ofstream{ sourcefile+"-tokens"  };
            tokens.debug_print( out_tokens     );

            auto out_parse      = std::ofstream{ sourcefile+"-parse"   };
            auto tree_printer   = parse_tree_printer{out_parse  };
            parser.visit      ( tree_printer   );

            auto out_symbols    = std::ofstream{ sourcefile+"-symbols" };
            sema.debug_print  ( out_symbols    );
        }
    }
};

}


//===========================================================================
//  main - driver
//===========================================================================

using namespace std;
using namespace cpp2;

int main(int argc, char* argv[]) 
{
    for (auto i = 1; i < argc; ++i) {
        cppfront c(argv[i]);
        c.debug_print();
        c.lower_to_cpp1();
    }
}
