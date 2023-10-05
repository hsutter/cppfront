//
// Created by root on 05.10.23.
//

#ifndef CPPFRONT_SOURCE_POSITION_H
#define CPPFRONT_SOURCE_POSITION_H

#include <cstdint>
#include <string>

namespace cpp2{
    using lineno_t = int32_t;
    using colno_t  = int32_t;   // not int16_t... encountered >80,000 char line during testing

    struct source_position
    {
        lineno_t    lineno;     // one-based offset into program source
        colno_t     colno;      // one-based offset into line

        source_position(lineno_t l = 1, colno_t  c = 1 )
                : lineno{ l }, colno{ c }
        {
        }

        auto operator<=>(source_position const&) const = default;

        auto to_string() const
        -> std::string
        {
            return "(" + std::to_string(lineno) + "," + std::to_string(colno) + ")";
        }
    };
};
#endif //CPPFRONT_SOURCE_POSITION_H
