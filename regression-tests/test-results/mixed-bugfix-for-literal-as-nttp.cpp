

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-bugfix-for-literal-as-nttp.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-bugfix-for-literal-as-nttp.cpp2"
#include <chrono>
using namespace std::chrono_literals;
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-bugfix-for-literal-as-nttp.cpp2"

#line 3 "mixed-bugfix-for-literal-as-nttp.cpp2"
auto main() -> int{
  if (cpp2::Default.has_handler() && !(cpp2::as_<cpp2::i32, 10>() == 10) ) { cpp2::Default.report_violation(""); }
  if (cpp2::Default.has_handler() && !(cpp2::as_<cpp2::i32, 10LL>() == 10) ) { cpp2::Default.report_violation(""); }
  if (cpp2::Default.has_handler() && !(cpp2::as_<std::chrono::seconds>(10s) == 10s) ) { cpp2::Default.report_violation(""); }
}

