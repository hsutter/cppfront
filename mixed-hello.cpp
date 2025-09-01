#line 2 "regression-tests/mixed-hello.cpp2"
#include <iostream>
#include <string>


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regression-tests/mixed-hello.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "regression-tests/mixed-hello.cpp2"

#line 5 "regression-tests/mixed-hello.cpp2"
[[nodiscard]] auto name() -> std::string;

#line 11 "regression-tests/mixed-hello.cpp2"
auto decorate(std::string& s) -> void;
#line 14 "regression-tests/mixed-hello.cpp2"

auto main() -> int {
    // name();
    std::cout << "Hello " << name() << "\n";
}


//=== Cpp2 function definitions =================================================

#line 1 "regression-tests/mixed-hello.cpp2"

#line 5 "regression-tests/mixed-hello.cpp2"
[[nodiscard]] auto name() -> std::string{
    std::string s {"world"}; 
    decorate(s);
    return s; 
}

#line 11 "regression-tests/mixed-hello.cpp2"
auto decorate(std::string& s) -> void{
    s = "[" + s + "]";
}

