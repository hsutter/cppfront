// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-function-expression-and-std-for-each.cpp2"
#include <vector>
#include <string>
#include <span>
#include <algorithm>
#include <iostream>

[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 6 "mixed-function-expression-and-std-for-each.cpp2"

[[nodiscard]] auto main() -> int{
    std::vector<std::string> vec { 
               "hello", "2022" }; 
    std::span view { vec }; 

    //  Passing a function expression
    std::for_each(
        CPP2_UFCS_0(begin, view), 
        CPP2_UFCS_0(end, view), 
        [](auto& x) {  return x += "-ish"; }
    );

    //  Initializating from a function expression
    auto callback { [](auto& x) { return x += " maybe"; } }; 
    std::for_each(
        CPP2_UFCS_0(begin, view), 
        CPP2_UFCS_0(end, view), 
        callback
    );

    for ( auto&& cpp2_range = view;  auto const& str : cpp2_range ) {
        std::cout << str << "\n";
    }
}
