
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-template-argument.cpp2"
auto main() -> int;
    

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-template-argument.cpp2"
auto main() -> int { 
    std::cout 
        << std::boolalpha 
        << (std::is_void_v<cpp2::i32*> && std::is_void_v<cpp2::i32 const>) 
        << "\n"; }

