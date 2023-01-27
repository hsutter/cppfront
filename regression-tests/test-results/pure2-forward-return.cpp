// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-forward-return.cpp2"
[[nodiscard]] auto first(auto&& rng) -> decltype(auto);
#line 7 "pure2-forward-return.cpp2"
#line 8 "pure2-forward-return.cpp2"
[[nodiscard]] auto f() -> int const&;
#line 10 "pure2-forward-return.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-forward-return.cpp2"

[[nodiscard]] auto first(auto&& rng) -> decltype(auto) { 


    return *cpp2::assert_not_null(std::begin(CPP2_FORWARD(rng))); }

int const global {42}; 
[[nodiscard]] auto f() -> int const&{return global; }

[[nodiscard]] auto main() -> int{
    std::vector v {1, 2, 3}; 
    first(v) = 4;
    std::cout << first(std::move(v)) << std::endl;// prints: 4
    std::cout << f() << std::endl; // prints: 42
}

