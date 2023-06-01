
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-empty-index.cpp2"
class t;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-empty-index.cpp2"
class t {
  public: [[nodiscard]] auto operator[]() -> cpp2::i32;
  public: [[nodiscard]] auto operator[](auto const& x) -> cpp2::i32;
  public: [[nodiscard]] auto operator[](auto const& x, auto const& y) -> cpp2::i32;

  public: t() = default;
  public: t(t const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(t const&) -> void = delete;
#line 5 "pure2-bugfix-for-empty-index.cpp2"
};
auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 2 "pure2-bugfix-for-empty-index.cpp2"
  [[nodiscard]] auto t::operator[]() -> cpp2::i32 { return 1;  }
  [[nodiscard]] auto t::operator[](auto const& x) -> cpp2::i32 { return 2;  }
  [[nodiscard]] auto t::operator[](auto const& x, auto const& y) -> cpp2::i32 { return 3;  }

auto main() -> int{
  cpp2::Default.expects(t()[]==1, "");
  cpp2::Default.expects(cpp2::assert_in_bounds(t(), 1)==2, "");
  cpp2::Default.expects(t()[1, 2]==3, "");
}

