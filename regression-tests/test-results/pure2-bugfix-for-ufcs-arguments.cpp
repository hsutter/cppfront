
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-ufcs-arguments.cpp2"

#line 7 "pure2-bugfix-for-ufcs-arguments.cpp2"
class t;
  

#line 58 "pure2-bugfix-for-ufcs-arguments.cpp2"
namespace ns {
template<int T, int U> class t;
  

}

class A;
  

#line 68 "pure2-bugfix-for-ufcs-arguments.cpp2"
class B;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-ufcs-arguments.cpp2"
[[nodiscard]] auto print_res(cpp2::impl::in<cpp2::i32> x) -> cpp2::i32;

#line 7 "pure2-bugfix-for-ufcs-arguments.cpp2"
class t {
  public: [[nodiscard]] auto f() & -> cpp2::i32;
  public: [[nodiscard]] auto f([[maybe_unused]] auto const& unnamed_param_2) & -> cpp2::i32;
  public: template<typename UnnamedTypeParam1_1> [[nodiscard]] auto f() & -> cpp2::i32;
  public: template<typename UnnamedTypeParam1_2> [[nodiscard]] auto f([[maybe_unused]] auto const& unnamed_param_2) & -> cpp2::i32;
  public: template<typename UnnamedTypeParam1_3, typename U> [[nodiscard]] auto f([[maybe_unused]] auto const& unnamed_param_2, [[maybe_unused]] auto const& unnamed_param_3) & -> cpp2::i32;
};

[[nodiscard]] auto f([[maybe_unused]] cpp2::impl::in<t> unnamed_param_1) -> cpp2::i32;
[[nodiscard]] auto f([[maybe_unused]] cpp2::impl::in<t> unnamed_param_1, [[maybe_unused]] auto const& unnamed_param_2) -> cpp2::i32;
template<typename UnnamedTypeParam1_4> [[nodiscard]] auto f([[maybe_unused]] cpp2::impl::in<t> unnamed_param_1) -> cpp2::i32;
template<typename UnnamedTypeParam1_5> [[nodiscard]] auto f([[maybe_unused]] cpp2::impl::in<t> unnamed_param_1, [[maybe_unused]] auto const& unnamed_param_2) -> cpp2::i32;
template<typename UnnamedTypeParam1_6, typename U> [[nodiscard]] auto f([[maybe_unused]] cpp2::impl::in<t> unnamed_param_1, [[maybe_unused]] auto const& unnamed_param_2, [[maybe_unused]] auto const& unnamed_param_3) -> cpp2::i32;

extern t m;
extern t const n;
template<typename UnnamedTypeParam1_7, typename U> auto inline constexpr a{ n };

extern cpp2::i32 auto_8;
extern cpp2::i32 auto_9;
extern cpp2::i32 auto_10;
extern cpp2::i32 auto_11;
extern cpp2::i32 auto_12;
extern cpp2::i32 auto_13;
extern cpp2::i32 auto_14;
extern cpp2::i32 auto_15;
extern cpp2::i32 auto_16;
extern cpp2::i32 auto_17;
extern cpp2::i32 auto_18;

auto main() -> int;

#line 55 "pure2-bugfix-for-ufcs-arguments.cpp2"
// _: i32 = 0.std::min<int>(0);
extern cpp2::i32 auto_19;

namespace ns {
template<int T, int U> class t {
  public: template<int V> [[nodiscard]] static auto f([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1) -> cpp2::i32;
};
} // namespace ns

class A {
  public: auto f() const& -> void;
};

class B {
  public: A m; 
  public: auto f() const& -> void;
};


//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-ufcs-arguments.cpp2"
[[nodiscard]] auto print_res(cpp2::impl::in<cpp2::i32> x) -> cpp2::i32{
#line 2 "pure2-bugfix-for-ufcs-arguments.cpp2"
  std::cout << x;
  if (x == 9) {std::cout << '\n'; }
  return x; 
}

#line 8 "pure2-bugfix-for-ufcs-arguments.cpp2"
  [[nodiscard]] auto t::f() & -> cpp2::i32 { return print_res(0);  }
#line 9 "pure2-bugfix-for-ufcs-arguments.cpp2"
  [[nodiscard]] auto t::f([[maybe_unused]] auto const& unnamed_param_2) & -> cpp2::i32 { return print_res(1);  }
#line 10 "pure2-bugfix-for-ufcs-arguments.cpp2"
  template<typename UnnamedTypeParam1_1> [[nodiscard]] auto t::f() & -> cpp2::i32 { return print_res(2);  }
#line 11 "pure2-bugfix-for-ufcs-arguments.cpp2"
  template<typename UnnamedTypeParam1_2> [[nodiscard]] auto t::f([[maybe_unused]] auto const& unnamed_param_2) & -> cpp2::i32 { return print_res(3);  }
#line 12 "pure2-bugfix-for-ufcs-arguments.cpp2"
  template<typename UnnamedTypeParam1_3, typename U> [[nodiscard]] auto t::f([[maybe_unused]] auto const& unnamed_param_2, [[maybe_unused]] auto const& unnamed_param_3) & -> cpp2::i32 { return print_res(4);  }

#line 15 "pure2-bugfix-for-ufcs-arguments.cpp2"
[[nodiscard]] auto f([[maybe_unused]] cpp2::impl::in<t> unnamed_param_1) -> cpp2::i32 { return print_res(5);  }
#line 16 "pure2-bugfix-for-ufcs-arguments.cpp2"
[[nodiscard]] auto f([[maybe_unused]] cpp2::impl::in<t> unnamed_param_1, [[maybe_unused]] auto const& unnamed_param_2) -> cpp2::i32 { return print_res(6);  }
#line 17 "pure2-bugfix-for-ufcs-arguments.cpp2"
template<typename UnnamedTypeParam1_4> [[nodiscard]] auto f([[maybe_unused]] cpp2::impl::in<t> unnamed_param_1) -> cpp2::i32 { return print_res(7);  }
#line 18 "pure2-bugfix-for-ufcs-arguments.cpp2"
template<typename UnnamedTypeParam1_5> [[nodiscard]] auto f([[maybe_unused]] cpp2::impl::in<t> unnamed_param_1, [[maybe_unused]] auto const& unnamed_param_2) -> cpp2::i32 { return print_res(8);  }
#line 19 "pure2-bugfix-for-ufcs-arguments.cpp2"
template<typename UnnamedTypeParam1_6, typename U> [[nodiscard]] auto f([[maybe_unused]] cpp2::impl::in<t> unnamed_param_1, [[maybe_unused]] auto const& unnamed_param_2, [[maybe_unused]] auto const& unnamed_param_3) -> cpp2::i32 { return print_res(9);  }

t m {}; 
t const n {}; 

#line 25 "pure2-bugfix-for-ufcs-arguments.cpp2"
cpp2::i32 auto_8 {CPP2_UFCS_NONLOCAL(f)(m)}; 
cpp2::i32 auto_9 {CPP2_UFCS_NONLOCAL(f)(m, 0)}; 
cpp2::i32 auto_10 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t>)(m)}; 
cpp2::i32 auto_11 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t>)(m, 0)}; 
cpp2::i32 auto_12 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t,t>)(m, 0, 0)}; 
cpp2::i32 auto_13 {CPP2_UFCS_NONLOCAL(f)(n)}; 
cpp2::i32 auto_14 {CPP2_UFCS_NONLOCAL(f)(n, 0)}; 
cpp2::i32 auto_15 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t>)(n)}; 
cpp2::i32 auto_16 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t>)(n, 0)}; 
cpp2::i32 auto_17 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t,t>)(n, 0, 0)}; 
cpp2::i32 auto_18 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t,t>)(a<t,t>, 0, 0)}; 

#line 37 "pure2-bugfix-for-ufcs-arguments.cpp2"
auto main() -> int{
  static_cast<void>(CPP2_UFCS(f)(m));
  static_cast<void>(CPP2_UFCS(f)(m, 0));
  static_cast<void>(CPP2_UFCS_TEMPLATE(f<t>)(m));
  static_cast<void>(CPP2_UFCS_TEMPLATE(f<t>)(m, 0));
  static_cast<void>(CPP2_UFCS_TEMPLATE(f<t,t>)(m, 0, 0));
  static_cast<void>(CPP2_UFCS(f)(n));
  static_cast<void>(CPP2_UFCS(f)(n, 0));
  static_cast<void>(CPP2_UFCS_TEMPLATE(f<t>)(n));
  static_cast<void>(CPP2_UFCS_TEMPLATE(f<t>)(n, 0));
  static_cast<void>(CPP2_UFCS_TEMPLATE(f<t,t>)(n, 0, 0));
  static_cast<void>(CPP2_UFCS_TEMPLATE(f<t,t>)(a<t,t>, 0, 0));

  static_cast<void>([](auto const& a, auto const& f) mutable -> void{static_cast<void>(CPP2_UFCS(f)(CPP2_UFCS(f)(a, a))); });
  // _ = 0.std::min<int>(0);
  static_cast<void>(CPP2_UFCS_QUALIFIED_TEMPLATE((ns::t<0,0>::),f<0>)(0));
}

#line 56 "pure2-bugfix-for-ufcs-arguments.cpp2"
cpp2::i32 auto_19 {CPP2_UFCS_QUALIFIED_TEMPLATE_NONLOCAL((ns::t<0,0>::),f<0>)(0)}; 

namespace ns {

#line 60 "pure2-bugfix-for-ufcs-arguments.cpp2"
  template <int T, int U> template<int V> [[nodiscard]] auto t<T,U>::f([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1) -> cpp2::i32 { return 0;  }

}

#line 65 "pure2-bugfix-for-ufcs-arguments.cpp2"
  auto A::f() const& -> void{}

#line 70 "pure2-bugfix-for-ufcs-arguments.cpp2"
  auto B::f() const& -> void { CPP2_UFCS(f)(m);  }

