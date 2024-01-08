

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-function-type-argument.cpp2"

#line 9 "mixed-function-type-argument.cpp2"
class t;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-function-type-argument.cpp2"
#include <cstddef>
auto main() -> int;

#line 9 "mixed-function-type-argument.cpp2"
class t {
  public: int a; 
};


//=== Cpp2 function definitions =================================================

#line 1 "mixed-function-type-argument.cpp2"

#line 2 "mixed-function-type-argument.cpp2"
auto main() -> int{
  // OK by Cpp1 semantics.
  static_cast<void>(alignof(int));
  static_cast<void>(sizeof(int));
  static_cast<void>(typeid(int));
  static_cast<void>(offsetof(t, a));
}

