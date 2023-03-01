
#line 1 "mixed-fixed-type-aliases.cpp2"
#include <typeinfo>
#include <iostream>

namespace my {
    using u16 = float;
}

#include "cpp2util.h"


#line 8 "mixed-fixed-type-aliases.cpp2"
auto test(auto const& x) -> void;
#line 15 "mixed-fixed-type-aliases.cpp2"
[[nodiscard]] auto main(int argc, char **argv) -> int;

//=== Cpp2 definitions ==========================================================

#line 7 "mixed-fixed-type-aliases.cpp2"

auto test(auto const& x) -> void{
    std::cout 
        << std::boolalpha 
        << std::is_floating_point_v<CPP2_TYPEOF(x)> 
        << "\n";
}

[[nodiscard]] auto main(int argc, char **argv) -> int{
    auto args = cpp2::args(argc, argv); 
#line 16 "mixed-fixed-type-aliases.cpp2"
    my::u16 y {42}; 
    test(std::move(y));

    cpp2::u16 z {42}; 
    test(std::move(z));

    for ( auto const& cpp2_range = args;  auto const& arg : cpp2_range ) 
        std::cout << arg << "\n";
}

