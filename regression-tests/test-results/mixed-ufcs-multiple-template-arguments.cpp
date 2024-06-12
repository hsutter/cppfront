

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-ufcs-multiple-template-arguments.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-ufcs-multiple-template-arguments.cpp2"
#include <string>
#include <iostream>

template <auto from, auto to>
auto substr(const std::string& input) -> std::string {
    return input.substr(from, to-from);
}

struct X {
    std::string input;
    X(const std::string& input) : input{input} { }
    template <auto from, auto to>
    auto substr() -> std::string {
        return input.substr(from, to-from);
    }
};

#line 18 "mixed-ufcs-multiple-template-arguments.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-ufcs-multiple-template-arguments.cpp2"

#line 18 "mixed-ufcs-multiple-template-arguments.cpp2"
[[nodiscard]] auto main() -> int{
    std::string test_string {"The rain in Spain flows mainly down the drain"}; 
    std::cout << substr<4,8>(test_string) << "\n";

    X x {cpp2::move(test_string)}; 
    std::cout << CPP2_UFCS_TEMPLATE(substr<4,8>)(cpp2::move(x)) << "\n";
}

