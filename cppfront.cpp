
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
        //  Load the program file into memory
        //
        if (!source.load(sourcefile))
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

            debug_print();

            if (!sema.apply_local_rules()) {
                errors.emplace_back(
                    source_position{-1, -1}, 
                    "error encountered while applying local initialization rules"
                );
            }
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
    }
}
