
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-assign-expression-list.cpp2"
auto main() -> int;
  

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-assign-expression-list.cpp2"
auto main() -> int{
  using vec = std::vector<int>;
  vec v {0}; 
  v                   = {  };
  cpp2::Default.expects(v == vec{}, "");
  v                   = { 1 };
  cpp2::Default.expects(v == vec{1}, "");
  v                   = { 2, 3 };
  cpp2::Default.expects(std::move(v) == vec{2, 3}, "");
}

