
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

auto main() -> int;
  

//=== Cpp2 function definitions =================================================

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

