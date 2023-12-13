

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-function-expression-and-std-ranges-for-each.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-function-expression-and-std-ranges-for-each.cpp2"
#include <vector>
#include <ranges>
#include <string>
#include <span>
#include <algorithm>
#include <iostream>

#line 8 "mixed-function-expression-and-std-ranges-for-each.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-function-expression-and-std-ranges-for-each.cpp2"

#line 8 "mixed-function-expression-and-std-ranges-for-each.cpp2"
[[nodiscard]] auto main() -> int{
    std::vector<std::string> vec {
            "hello", "2022"}; 

    std::ranges::for_each
        (vec, [](auto const& x) mutable -> void { std::cout << x << "\n";  });

    auto callback {[](auto& x) mutable -> void { x += "-ish";  }}; 
    std::ranges::for_each(vec, std::move(callback));

    for ( auto const& str : vec ) 
        std::cout << str << "\n";
}

