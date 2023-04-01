
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-repeated-call.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================


#line 2 "pure2-repeated-call.cpp2"
[[nodiscard]] auto main() -> int{
    std::cout << std::hash<int>()(0) << std::endl;
    return 0; 
}

