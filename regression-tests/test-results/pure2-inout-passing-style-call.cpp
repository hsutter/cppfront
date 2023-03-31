
#define CPP2_USE_MODULES         Yes

#include "cpp2util.h"


#line 1 "pure2-inout-passing-style-call.cpp2"
[[nodiscard]] auto f2(auto& x) -> auto;
#line 5 "pure2-inout-passing-style-call.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-inout-passing-style-call.cpp2"
[[nodiscard]] auto f2(auto& x) -> auto{
    return x * 2; 
}

[[nodiscard]] auto main() -> int{
    auto x {21}; 
    std::cout << f2(      x) << std::endl;
}

