
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-forward-return.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-forward-return.cpp2"

#line 2 "pure2-forward-return.cpp2"
[[nodiscard]] auto first(auto&& rng) -> decltype(auto);

#line 7 "pure2-forward-return.cpp2"
extern int const global;
[[nodiscard]] auto f() -> int const&;

[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-forward-return.cpp2"

#line 2 "pure2-forward-return.cpp2"
[[nodiscard]] auto first(auto&& rng) -> decltype(auto) { 
    if (cpp2::bounds_safety.is_active() && !(!(std::empty(rng))) ) { cpp2::bounds_safety.report_violation(""); }

#line 5 "pure2-forward-return.cpp2"
    return *cpp2::impl::assert_not_null(std::begin(CPP2_FORWARD(rng)));  }

int const global {42}; 
#line 8 "pure2-forward-return.cpp2"
[[nodiscard]] auto f() -> int const&{return global; }

#line 10 "pure2-forward-return.cpp2"
[[nodiscard]] auto main() -> int{
    std::vector v {1, 2, 3}; 
    first(v) = 4;
    std::cout << first(cpp2::move(v)) << std::endl;// prints: 4
    std::cout << f() << std::endl; // prints: 42
}

