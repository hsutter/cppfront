
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-parameter-named-after-contextual-keyword.cpp2"
class t;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-parameter-named-after-contextual-keyword.cpp2"
class t {
  public: [[nodiscard]] static auto f(auto const& in) -> auto;

  public: t() = default;
  public: t(t const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(t const&) -> void = delete;
#line 3 "pure2-bugfix-for-parameter-named-after-contextual-keyword.cpp2"
};
[[nodiscard]] auto g(auto const& final) -> auto;
[[nodiscard]] auto h(auto const& out, auto const& x) -> auto;
auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 2 "pure2-bugfix-for-parameter-named-after-contextual-keyword.cpp2"
  [[nodiscard]] auto t::f(auto const& in) -> auto { return in;  }

[[nodiscard]] auto g(auto const& final) -> auto { return final.first;  }
[[nodiscard]] auto h(auto const& out, auto const& x) -> auto { return out(x);  }
auto main() -> int{
  cpp2::Default.expects(t::f(0)==0, "");
  cpp2::Default.expects(g(std::make_pair(1, 2))==1, "");
  cpp2::Default.expects(h([](auto const& y) -> auto { return y;  }, 3)==3, "");
}

