#pragma once

#include "ntuples/groupby.hh"


#define nt_group(...) [](){ using T = decltype(             \
                    nt::algorithms::group( __VA_ARGS__ ) ); \
                    static constexpr T t{};                 \
                    return t; }()

                    