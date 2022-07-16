
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0


//===========================================================================
//  cppfront
//===========================================================================

#include "tocpp1.h"
#include <iostream>


namespace cpp2 {

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

    source source;
    tokens tokens;
    parser parser;
    sema   sema;
    bool   source_present = true;

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
            errors.emplace_back(
                source_position{-1, -1}, 
                "file not found: " + sourcefile
            );
            source_present = false;
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
    //  lower_to_cpp1
    // 
    //  Emits the target file with the last '2' stripped -> .cpp
    //
    auto lower_to_cpp1() -> void
    {
        auto out = std::ofstream{ sourcefile.substr(0, sourcefile.size()-1) };

        //  First, echo the non-Cpp2 parts
        for (bool first = true; auto const& line : source.get_lines())
        {
            //  Skip dummy line we added to make 0-vs-1-based offsets readable
            if (first) { first = false; continue; }

            if (line.cat != source_line::category::cpp2) {
                out << line.text << "\n";
            }
        }

        //  Next, bring in the Cpp2 helpers
        out << "\n\n//=== Cpp2 ======================================================================"
            << "\n\n#include \"cpp2util.h\"\n\n";

        ////  Next, emit the Cpp2 forward declarations
        auto cpp1_printer = to_cpp1_printer{ out, tokens.get_comments() };
        parser.visit( cpp1_printer );

        ////  Next, emit the Cpp2 definitions
        //cpp1_printer.enable_definitions();
        //parser.visit( cpp1_printer );
    }


    //-----------------------------------------------------------------------
    //  debug_print
    //
    auto debug_print() -> void
    {
        for (auto&& error : errors) {
            error.print(std::cerr, strip_path(sourcefile));
        }

        //  Only create debug output files for an actual source file.
        //
        if (source_present)
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
