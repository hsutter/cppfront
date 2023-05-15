

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#include <vector>
#include <ranges>
#include <string>
#include <span>
#include <algorithm>
#include <iostream>

#line 8 "mixed-function-expression-and-std-ranges-for-each.cpp2"
[[nodiscard]] auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 8 "mixed-function-expression-and-std-ranges-for-each.cpp2"
[[nodiscard]] auto main() -> int{
    std::vector<std::string> vec {
            "hello", "2022"}; 
    std::span view {vec}; 

    std::ranges::for_each
        (view, [](auto const& x) -> void{std::cout << x << "\n"; });

    auto callback {[](auto& x) -> void { x += "-ish";  }}; 
    std::ranges::for_each(view, std::move(callback));

    for ( auto const& str : view ) 
        std::cout << str << "\n";
}

