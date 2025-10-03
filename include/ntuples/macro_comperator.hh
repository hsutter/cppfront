#pragma once
#include "ntuples/ntuples.hh"


#define nt_lessthan(...) [](){ using T = decltype(             \
                    nt::comparators::nt_compare( __VA_ARGS__ ) ); \
                    static constexpr T t{};                 \
                    return [&](const auto& x,const auto &y) {return t.__isLessthen(x,y);}; }()

#define nt_equal(...) [](){ using T = decltype(             \
                    nt::comparators::nt_compare( __VA_ARGS__ ) ); \
                    static constexpr T t{};                 \
                    return [&](const auto& x,const auto &y) {return t.__isEequal(x,y);}; }()

                    