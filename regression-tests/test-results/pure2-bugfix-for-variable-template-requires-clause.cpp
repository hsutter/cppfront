
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-variable-template-requires-clause.cpp2"
template<typename T> 
CPP2_REQUIRES (std::same_as<T,cpp2::i32>)
#line 1 "pure2-bugfix-for-variable-template-requires-clause.cpp2"
extern T const v;

auto main() -> int;
  

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-variable-template-requires-clause.cpp2"
template<typename T> 
requires (std::same_as<T,cpp2::i32>)
#line 1 "pure2-bugfix-for-variable-template-requires-clause.cpp2"
T const v {0}; 

auto main() -> int { 
  static_assert(!(std::invocable<decltype([]<typename T>([[maybe_unused]] T const& param1) -> std::type_identity_t<decltype(v<T>)>{return v<T>; }),cpp2::i16>));  }

