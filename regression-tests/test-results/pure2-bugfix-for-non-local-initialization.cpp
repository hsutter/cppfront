
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-bugfix-for-non-local-initialization.cpp2"
class t;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-non-local-initialization.cpp2"
using u = std::array<cpp2::i32,2>;
class t: public std::integral_constant<u,u{17, 29}> {

};
auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 5 "pure2-bugfix-for-non-local-initialization.cpp2"
auto main() -> int{
  cpp2::Testing.expects(cpp2::assert_in_bounds(t::value, 0) == 17, "");
  cpp2::Testing.expects(cpp2::assert_in_bounds(t::value, 1) == 29, "");
}

