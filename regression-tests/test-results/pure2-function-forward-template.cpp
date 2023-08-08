
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 20 "pure2-function-forward-template.cpp2"
class my_string;
  

class my_point;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-function-forward-template.cpp2"
auto fun(
  auto&& s1, auto&& s2, auto&& s3,                                                             //
  auto&& a1, auto&& a2, auto&& a3) -> void
CPP2_REQUIRES (cpp2::is<CPP2_TYPEOF(s1), std::basic_string>() && cpp2::is<CPP2_TYPEOF(s2), std::basic_string>() && cpp2::is<CPP2_TYPEOF(s3), std::basic_string>() && cpp2::is<CPP2_TYPEOF(a1), std::array>() && cpp2::is<CPP2_TYPEOF(a2), std::array>() && cpp2::is<CPP2_TYPEOF(a3), std::array>())
#line 1 "pure2-function-forward-template.cpp2"
;
  

#line 7 "pure2-function-forward-template.cpp2"
auto main() -> int;
  

#line 20 "pure2-function-forward-template.cpp2"
class my_string: public std::string {

};
class my_point: public std::array<cpp2::i32,2> {

};


//=== Cpp2 function definitions =================================================

#line 1 "pure2-function-forward-template.cpp2"
auto fun(
  auto&& s1, auto&& s2, auto&& s3, 
  auto&& a1, auto&& a2, auto&& a3) -> void
requires (cpp2::is<CPP2_TYPEOF(s1), std::basic_string>() && cpp2::is<CPP2_TYPEOF(s2), std::basic_string>() && cpp2::is<CPP2_TYPEOF(s3), std::basic_string>() && cpp2::is<CPP2_TYPEOF(a1), std::array>() && cpp2::is<CPP2_TYPEOF(a2), std::array>() && cpp2::is<CPP2_TYPEOF(a3), std::array>())
#line 3 "pure2-function-forward-template.cpp2"
  {
  std::cout << CPP2_FORWARD(s1) << CPP2_FORWARD(s2) << CPP2_FORWARD(s3) << cpp2::assert_in_bounds(CPP2_FORWARD(a1), 0) << cpp2::assert_in_bounds(CPP2_FORWARD(a2), 0) << cpp2::assert_in_bounds(CPP2_FORWARD(a3), 0) << std::endl;
}

auto main() -> int{
  std::string b {"b"}; 
  std::string c {"c"}; 
  std::array e {"e"}; 
  std::array f {"f"}; 
  fun(std::string("a"), b, std::move(c), std::array{"d"}, e, std::move(f));
  (void) std::move(b);
  (void) std::move(e);

  static_assert(!(cpp2::is<my_string,std::basic_string>()));
  static_assert(!(cpp2::is<my_point,std::array>()));
}

