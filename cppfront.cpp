
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

    expression_list_node::term const* current_expression_list_term = nullptr;

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
    //  For the second pass this funciton enables printing definitions.
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
        last_pos.colno = 0;
    }

    auto print(std::string_view s) -> void {
        out << s;

        auto last_newline = std::string::npos;
        auto newline_pos  = std::string::npos;
        while ((newline_pos = s.find('\n')) != std::string::npos) {
            ++last_pos.lineno;
            last_newline = newline_pos;
        }

        if (last_newline != std::string::npos) {
            last_pos.colno = s.length() - last_newline;
        }
        else {
            last_pos.colno += s.length();
        }
    }

    auto print(std::string_view s, source_position pos) -> void {
        align_to(pos);
        print(s);
    }


    //-----------------------------------------------------------------------
    //  To position ourselves as close to the programmer's original location
    //  as possible, and to catch up with displaying comments
    //
    auto align_to( source_position pos ) -> void
    {
        auto& comments = tokens.get_comments(); // for readability

        //  Flush all comments that we've passed by
        //
        for ( ;
            next_comment < std::ssize(comments) && comments[next_comment].start < pos;
            ++next_comment
            )
        {
            //  For line comments
            if (comments[next_comment].kind == comment::comment_kind::line_comment)
            {
                //  First repeat any blank lines before the comment
                while (last_pos.lineno < comments[next_comment].start.lineno) {
                    print_newline();
                }

                ////  If this comment didn't have whitespace earlier on the start line,
                ////  start it on its own new line
                //if (comments[next_comment].all_whitespace_before_on_start_line) {
                //    //  Then start a new line and repeat the comment
                //    print_newline();
                //    print( pad( comments[next_comment].start.colno ) );
                //    print( comments[next_comment].text );
                //}

                ////  Otherwise, pad out to its column (if we haven't passed it already)
                ////  and emit it there
                //else {
                    print( pad( last_pos.colno - comments[next_comment].start.colno ) );
                    print( comments[next_comment].text );
                    print_newline();
                //}
            }

            // For a stream comment, pad out to its column (if we haven't passed it already)
            //  and emit it there
            else
            {
                print( pad( last_pos.colno - comments[next_comment].start.colno ) );
                print( comments[next_comment].text );
                ++next_comment;
            }
        };

        //  Now that comments are done, add any additional blank lines
        //  needed to get to the target vertical position
        //
        while (last_pos.lineno < pos.lineno) {
            print_newline();
        }

        //  Finally, align to the target column
        //
        print( pad( pos.colno - last_pos.colno - 1 ) );

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
    //
    auto emit(parameter_declaration_node const& n) -> void
    {
        //  Can't declare functions as parameters -- only pointers to functions which are objects
        assert( n.declaration );
        assert( n.declaration->is(declaration_node::object) );

        auto const& id_expr = *std::get<declaration_node::object>(n.declaration->type);
        print( to_string( id_expr ), n.position() );

        switch (n.pass) {
        using enum passing_style;
        break;case in     : print ( " const&" );
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

        print( ")", n.pos_close_paren);
    }


    //-----------------------------------------------------------------------
    //
    auto emit(declaration_node const& n) -> void
    {
        if (n.is(declaration_node::function)) {
            print( "auto ", n.position() );
            print( *n.identifier->identifier );

            emit( *std::get<declaration_node::function>(n.type) );

            if (declarations_only) {
                print( ";");
                print_newline();
            }
        }

        else if (n.is(declaration_node::object)) {

            // TODO

        }






    }


    //-----------------------------------------------------------------------
    //
    auto emit(translation_unit_node const& n) -> void
    {
        auto next_map_section = tokens.get_map().cbegin();

        for (auto const& x : n.declarations)
        {
            //  Check to see if we have entered a new Cpp2 code section
            if (next_map_section != tokens.get_map().cend() &&
                next_map_section->first /*lineno*/ < n.position().lineno)
            {
                //  If so, adjust our anchor position to be relative to
                //  the start of that section
                last_pos = {next_map_section->first, 0};
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
