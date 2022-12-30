// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-fixed-type-aliases.cpp2"
#include <typeinfo>
#include <iostream>

namespace my {
    using u16 = float;
}

auto test(auto const& x) -> void;
#line 15 "mixed-fixed-type-aliases.cpp2"
[[nodiscard]] auto main(cpp2::in<int> argc, cpp2::in<char**> argv) -> int;

//=== Cpp2 definitions ==========================================================

#line 7 "mixed-fixed-type-aliases.cpp2"

auto test(auto const& x) -> void{
    std::cout 
        << std::boolalpha 
        << std::is_floating_point_v<CPP2_TYPEOF(x)> 
        << "\n";
}

[[nodiscard]] auto main(cpp2::in<int> argc, cpp2::in<char**> argv) -> int{
    my::u16 y { 42 }; 
    test(std::move(y));

    cpp2::u16 z { 42 }; 
    test(std::move(z));
}

