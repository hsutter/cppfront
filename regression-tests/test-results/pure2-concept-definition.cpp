
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-concept-definition.cpp2"
template    <typename T> concept arithmetic = std::integral<T> || std::floating_point<T>; 
template<typename T> requires( arithmetic<T> )
class t;

//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-concept-definition.cpp2"
template<typename T> requires( arithmetic<T> )
class t {};auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 3 "pure2-concept-definition.cpp2"
auto main() -> int                               {
  cpp2::Testing.expects(arithmetic<cpp2::i32>, "");
  cpp2::Testing.expects(arithmetic<float>, "");
  cpp2::Testing.expects(!(arithmetic<t<cpp2::i32>>), "");
}

