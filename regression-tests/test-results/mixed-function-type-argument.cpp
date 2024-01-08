

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-function-type-argument.cpp2"

#line 16 "mixed-function-type-argument.cpp2"
class t;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-function-type-argument.cpp2"
#include <cstddef>
auto main() -> int;

#line 16 "mixed-function-type-argument.cpp2"
class t {
  public: int a; 
};


//=== Cpp2 function definitions =================================================

#line 1 "mixed-function-type-argument.cpp2"

#line 2 "mixed-function-type-argument.cpp2"
auto main() -> int{
  static_cast<void>(alignof(int));
  static_cast<void>(sizeof(int));
  static_cast<void>(typeid(int));
  static_cast<void>(offsetof(t, a));
  static_cast<void>([]<typename T>([[maybe_unused]] T const& unnamed_param_1) mutable -> auto { return static_cast<void>(sizeof(T::value));  }(std::true_type()));
  static_cast<void>([]<typename T>([[maybe_unused]] T const& unnamed_param_1) mutable -> auto { return static_cast<void>(sizeof(typename T::value_type));  }(std::true_type()));
  static_cast<void>(alignof(int const));
  static_cast<void>(sizeof(int const));
  static_cast<void>(typeid(int const));
  static_cast<void>(alignof(int*));
  static_cast<void>(sizeof(int*));
  static_cast<void>(typeid(int*));
}

