
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-variable-template.cpp2"
template<auto V> extern int const v0;
[[nodiscard]] auto main() -> int;


//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-variable-template.cpp2"
template<auto V> int const v0 {0}; 
[[nodiscard]] auto main() -> int { return v0<0>; }

