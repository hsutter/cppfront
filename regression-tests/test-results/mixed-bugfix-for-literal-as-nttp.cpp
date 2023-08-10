

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#include <chrono>
using namespace std::chrono_literals;
#line 3 "mixed-bugfix-for-literal-as-nttp.cpp2"
auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 3 "mixed-bugfix-for-literal-as-nttp.cpp2"
auto main() -> int{
  cpp2::Default.expects(cpp2::as_<cpp2::i32, 10>()==10, "");
  cpp2::Default.expects(cpp2::as_<cpp2::i32, 10LL>()==10, "");
  cpp2::Default.expects(cpp2::as_<std::chrono::seconds>(10s)==10s, "");
}

