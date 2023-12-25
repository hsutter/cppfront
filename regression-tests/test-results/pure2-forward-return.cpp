
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-forward-return.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-forward-return.cpp2"

#line 2 "pure2-forward-return.cpp2"
[[nodiscard]] auto first(auto&& rng) -> auto&&;

#line 7 "pure2-forward-return.cpp2"
extern int const global;
[[nodiscard]] auto f() -> int const&;

[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-forward-return.cpp2"

#line 2 "pure2-forward-return.cpp2"
[[nodiscard]] auto first(auto&& rng) -> auto&& { 
    if (cpp2::Bounds.has_handler() && !(!(std::empty(rng))) ) { cpp2::Bounds.report_violation(""); }

#line 5 "pure2-forward-return.cpp2"
    return *cpp2::assert_not_null(std::begin(CPP2_FORWARD(rng)));  }

int const global {42}; 
[[nodiscard]] auto f() -> int const&{return global; }

[[nodiscard]] auto main() -> int{
    std::vector v {1, 2, 3}; 
    first(v) = 4;
    std::cout << first(std::move(v)) << std::endl;// prints: 4
    std::cout << f() << std::endl; // prints: 42
}

