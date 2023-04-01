
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-interpolation.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================


#line 2 "pure2-interpolation.cpp2"
[[nodiscard]] auto main() -> int{
    auto x {0}; 
    std::cout << "g" + cpp2::to_string(x) + "g" + cpp2::to_string(x) + "g"  << "\n";
    std::cout << cpp2::to_string(x) + "g" + cpp2::to_string(x) + "g"   << "\n";
    std::cout << cpp2::to_string(x) + "g" + cpp2::to_string(x)    << "\n";
    std::cout << cpp2::to_string(x) + cpp2::to_string(x)     << "\n";
    std::cout << "\"" + cpp2::to_string(x) + "\""     << "\n";
    std::cout << "\"" + cpp2::to_string(x)       << "\n";
    std::cout << "\""           << "\n";
    std::cout << ""             << "\n";
    std::cout << "pl(ug$h"      << "\n";
    std::cout << cpp2::to_string(std::move(x)) + "pl(ug$h" << "\n";
}

