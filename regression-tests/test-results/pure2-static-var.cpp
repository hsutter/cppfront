// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 1 "pure2-static-var.cpp2"
[[nodiscard]] auto green_bottles() -> int;
#line 7 "pure2-static-var.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-static-var.cpp2"
[[nodiscard]] auto green_bottles() -> int{
    auto static n {10}; 
    std::cout << n << std::endl;
    return --n; 
}

[[nodiscard]] auto main() -> int{
    while( green_bottles() >= 0 ) {}
}

