// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-function-expression-and-std-ranges-for-each.cpp2"
#include <vector>
#include <ranges>
#include <string>
#include <span>
#include <algorithm>
#include <iostream>

[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 7 "mixed-function-expression-and-std-ranges-for-each.cpp2"

[[nodiscard]] auto main() -> int{
    std::vector<std::string> vec { 
               "hello", "2022" }; 
    std::span view { vec }; 

    std::ranges::for_each
        ( view, [](auto const& x){std::cout << x << "\n";});

    auto callback { [](auto& x) { return x += "-ish"; } }; 
    std::ranges::for_each( view, callback );

    for ( auto&& cpp2_range = view;  auto const& str : cpp2_range ) 
        std::cout << str << "\n";
}
