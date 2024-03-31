#ifndef CPP2_UTILITY_FUNCTIONS_H
#define CPP2_UTILITY_FUNCTIONS_H

#include "../parse.h"

namespace cpp2 {
    auto check_sourcefile_extension(std::string const& sourcefile, std::vector<error_entry>& errors) 
        -> bool
    {
        //  "Constraints enable creativity in the right directions"
        //  sort of applies here
        //
        if (
            !sourcefile.ends_with(".cpp2")
            && !sourcefile.ends_with(".h2")
            )
        {
            errors.emplace_back(
                source_position(-1, -1),
                "source filename must end with .cpp2 or .h2: " + sourcefile
            );
            return false;
        }
        return true;
    }

    auto load_sourcefile(std::string const& sourcefile, cpp2::source& source, std::vector<error_entry>& errors)
        -> bool
    {
        if (!source.load(sourcefile))
        {
            if (errors.empty()) {
                errors.emplace_back(
                    source_position(-1, -1),
                    "file not found: " + sourcefile
                );
            }
            return false;
        }
        return true;
    }
} // namespace cpp2

#endif