
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-synthesize-rightshift-and-rightshifteq.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-synthesize-rightshift-and-rightshifteq.cpp2"
[[nodiscard]] auto f(cpp2::in<int> a, cpp2::in<int> b) -> int;

#line 7 "pure2-synthesize-rightshift-and-rightshifteq.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-synthesize-rightshift-and-rightshifteq.cpp2"
[[nodiscard]] auto f(cpp2::in<int> a, cpp2::in<int> b) -> int{
#line 2 "pure2-synthesize-rightshift-and-rightshifteq.cpp2"
    auto x {a}; 
    x >>= b * 2;
    return std::move(x) >> 1; 
}

[[nodiscard]] auto main() -> int{
    std::cout << f(32, 1) << "\n";
}

