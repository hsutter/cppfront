
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-dependent-types-recursion.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-dependent-types-recursion.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-dependent-types-recursion.cpp2"
auto main() -> int{
#line 2 "pure2-bugfix-for-dependent-types-recursion.cpp2"
  using a = b;
  using b = a;
  static_cast<void>(a::t);
  static_cast<void>(b::t);
}

