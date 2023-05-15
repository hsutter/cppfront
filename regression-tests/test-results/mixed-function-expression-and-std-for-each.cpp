

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#include <vector>
#include <string>
#include <span>
#include <algorithm>
#include <iostream>

#line 7 "mixed-function-expression-and-std-for-each.cpp2"
[[nodiscard]] auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 7 "mixed-function-expression-and-std-for-each.cpp2"
[[nodiscard]] auto main() -> int{
    std::vector<std::string> vec {
            "hello", "2022"}; 
    std::span view {vec}; 

    //  Passing a function expression
    std::for_each(
        CPP2_UFCS_0(begin, view), 
        CPP2_UFCS_0(end, view), 
        [](auto& x) -> void { x += "-ish";  }
    );

    //  Initializing from a function expression
    auto callback {[](auto& x) -> void { x += " maybe";  }}; 
    std::for_each(
        CPP2_UFCS_0(begin, view), 
        CPP2_UFCS_0(end, view), 
        std::move(callback)
    );

    for ( auto const& str : view ) {
        std::cout << str << "\n";
    }
}

