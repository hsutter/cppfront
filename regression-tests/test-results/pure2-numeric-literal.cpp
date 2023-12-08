

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-numeric-literal.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-numeric-literal.cpp2"
// } on same line
#line 2 "pure2-numeric-literal.cpp2"
auto niam() -> void;

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-numeric-literal.cpp2"

#line 2 "pure2-numeric-literal.cpp2"
auto niam() -> void{static_cast<void>(0'1); }

auto main() -> int{
    auto x {0'1}; // OK
    if (1) {x = 1'2; }// same
    cpp2::Default.expects(std::move(x) == 12, "");
}

