
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-runtime-invalid-alternative.cpp2"
auto f(auto const& x) -> void;
  

#line 7 "pure2-bugfix-for-runtime-invalid-alternative.cpp2"
auto main() -> int;


//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-runtime-invalid-alternative.cpp2"
auto f(auto const& x) -> void{
  cpp2::Default.expects([&] () -> cpp2::i32 { auto&& __expr = x;
    if (cpp2::is(__expr, 1)) { if constexpr( requires{[]() -> bool { return 2; }("");} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(([]() -> bool { return 2; }(""))),cpp2::i32> ) return []() -> bool { return 2; }(""); cpp2::Type.expects(false, "Statement of chosen alternative is invalid."); }
    else return 1; }
  ()==1, "");
}
auto main() -> int { f(1);  }

