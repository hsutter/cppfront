
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-requires-clause-unbraced-function-initializer.cpp2"
template<typename T> auto f() -> void
CPP2_REQUIRES (std::regular<T>)
#line 1 "pure2-bugfix-for-requires-clause-unbraced-function-initializer.cpp2"
;
auto main() -> int;


//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-requires-clause-unbraced-function-initializer.cpp2"
template<typename T> auto f() -> void
requires (std::regular<T>)
#line 1 "pure2-bugfix-for-requires-clause-unbraced-function-initializer.cpp2"
 { g(T());  }
auto main() -> int                 {}

