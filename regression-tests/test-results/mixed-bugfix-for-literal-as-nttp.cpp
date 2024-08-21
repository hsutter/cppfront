

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-bugfix-for-literal-as-nttp.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-bugfix-for-literal-as-nttp.cpp2"
#include <chrono>
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-bugfix-for-literal-as-nttp.cpp2"

#line 2 "mixed-bugfix-for-literal-as-nttp.cpp2"
auto main() -> int{
  using namespace std::chrono_literals;
  if (cpp2::cpp2_default.is_active() && !(cpp2::impl::as_<cpp2::i32, 10>() == 10) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(cpp2::impl::as_<cpp2::i32, 10LL>() == 10) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(cpp2::impl::as_<std::chrono::seconds>(10s) == 10s) ) { cpp2::cpp2_default.report_violation(""); }
}

