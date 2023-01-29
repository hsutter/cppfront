
#define CPP2_USE_MODULES         Yes

#include "cpp2util.h"


#line 2 "pure2-repeated-call.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-repeated-call.cpp2"

[[nodiscard]] auto main() -> int{
    std::cout << std::hash<int>()(0) << std::endl;
    return 0; 
}

