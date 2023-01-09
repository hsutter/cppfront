// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-function-expression-and-std-ranges-for-each-with-capture.cpp2"
#include <vector>
#include <ranges>
#include <string>
#include <span>
#include <algorithm>
#include <iostream>

[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 7 "mixed-function-expression-and-std-ranges-for-each-with-capture.cpp2"

[[nodiscard]] auto main() -> int{
    std::vector<std::string> vec {
               "hello", "2022"}; 
    std::span view {vec}; 

    auto y {"\n"}; 
    std::ranges::for_each
        ( view, [_0 = std::move(y)](auto const& x){std::cout << x << _0;});

    auto callback {[](auto& x) { return x += "-ish"; }}; 
    std::ranges::for_each( view, std::move(callback));

    for ( auto&& cpp2_range = view;  auto const& str : cpp2_range ) 
        std::cout << str << "\n";
}

