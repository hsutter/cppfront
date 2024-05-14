
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-non-local-initialization.cpp2"

#line 2 "pure2-bugfix-for-non-local-initialization.cpp2"
class t;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-non-local-initialization.cpp2"
using u = std::array<cpp2::i32,2>;
#line 2 "pure2-bugfix-for-non-local-initialization.cpp2"
class t: public std::integral_constant<u,u{17, 29}> {

};
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-non-local-initialization.cpp2"

#line 5 "pure2-bugfix-for-non-local-initialization.cpp2"
auto main() -> int{
  if (cpp2::testing.is_active() && !(CPP2_ASSERT_IN_BOUNDS_LITERAL(t::value, 0) == 17) ) { cpp2::testing.report_violation(""); }
  if (cpp2::testing.is_active() && !(CPP2_ASSERT_IN_BOUNDS_LITERAL(t::value, 1) == 29) ) { cpp2::testing.report_violation(""); }
}

