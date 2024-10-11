

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-function-expression-with-repeated-capture.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-function-expression-with-repeated-capture.cpp2"
#include <vector>
#include <ranges>
#include <string>
#include <span>
#include <algorithm>
#include <iostream>

#line 8 "mixed-function-expression-with-repeated-capture.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-function-expression-with-repeated-capture.cpp2"

#line 8 "mixed-function-expression-with-repeated-capture.cpp2"
[[nodiscard]] auto main() -> int{
    std::vector<std::string> vec {
            "hello", "2022"}; 

    auto y {"\n"}; 
    std::ranges::for_each
        (vec, [_0 = cpp2::move(y)](auto const& x) mutable -> decltype(auto) { return std::cout << _0 << x << _0;  });

    auto callback {[](auto& x) -> decltype(auto) { return x += "-ish";  }}; 
    std::ranges::for_each(vec, cpp2::move(callback));

    for ( auto const& str : cpp2::move(vec) ) 
        std::cout << str << "\n";
}

