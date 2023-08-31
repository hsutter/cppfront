
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-overload.cpp2"
class t;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-overload.cpp2"
class t {
  public: [[nodiscard]] auto f() const& -> cpp2::i32;
  public: [[nodiscard]] auto f() && -> cpp2::i32;
};
auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 2 "pure2-bugfix-for-overload.cpp2"
  [[nodiscard]] auto t::f() const& -> cpp2::i32 { return 1; }
  [[nodiscard]] auto t::f() && -> cpp2::i32 { return 2;  }

auto main() -> int{
  // "Can't overload with `move this` on non-`operator=` function" <https://github.com/hsutter/cppfront/issues/651>.
  t x {}; 
  cpp2::Testing.expects(CPP2_UFCS_0(f, x) == 1, "");
  cpp2::Testing.expects(CPP2_UFCS_0(f, std::move(x)) == 2, "");
}

