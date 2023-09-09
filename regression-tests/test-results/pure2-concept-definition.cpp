
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

template<typename T> concept arithmetic = std::integral<T> || std::floating_point<T>; 
auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 2 "pure2-concept-definition.cpp2"
  auto main() -> int    {
  cpp2::Testing.expects(arithmetic<cpp2::i32>, "");
  cpp2::Testing.expects(arithmetic<float>, "");
}

