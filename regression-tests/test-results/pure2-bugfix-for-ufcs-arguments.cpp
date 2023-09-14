
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 7 "pure2-bugfix-for-ufcs-arguments.cpp2"
class t;
  

//=== Cpp2 type definitions and function declarations ===========================

[[nodiscard]] auto print_res(cpp2::in<cpp2::i32> x) -> cpp2::i32;
  

#line 7 "pure2-bugfix-for-ufcs-arguments.cpp2"
class t {
  public: [[nodiscard]] auto f() & -> cpp2::i32;
  public: [[nodiscard]] auto f([[maybe_unused]] auto const& param2) & -> cpp2::i32;
  public: template<typename _> [[nodiscard]] auto f() & -> cpp2::i32;
  public: template<typename _> [[nodiscard]] auto f([[maybe_unused]] auto const& param2) & -> cpp2::i32;
  public: template<typename _, typename U> [[nodiscard]] auto f([[maybe_unused]] auto const& param2, [[maybe_unused]] auto const& param3) & -> cpp2::i32;
};

[[nodiscard]] auto f([[maybe_unused]] cpp2::in<t> param1) -> cpp2::i32;
[[nodiscard]] auto f([[maybe_unused]] cpp2::in<t> param1, [[maybe_unused]] auto const& param2) -> cpp2::i32;
template<typename _> [[nodiscard]] auto f([[maybe_unused]] cpp2::in<t> param1) -> cpp2::i32;
template<typename _> [[nodiscard]] auto f([[maybe_unused]] cpp2::in<t> param1, [[maybe_unused]] auto const& param2) -> cpp2::i32;
template<typename _, typename U> [[nodiscard]] auto f([[maybe_unused]] cpp2::in<t> param1, [[maybe_unused]] auto const& param2, [[maybe_unused]] auto const& param3) -> cpp2::i32;

extern t m;
extern t const n;
template<typename _, typename U> auto inline constexpr a = n;

extern cpp2::i32 auto_25_1;
extern cpp2::i32 auto_26_1;
extern cpp2::i32 auto_27_1;
extern cpp2::i32 auto_28_1;
extern cpp2::i32 auto_29_1;
extern cpp2::i32 auto_30_1;
extern cpp2::i32 auto_31_1;
extern cpp2::i32 auto_32_1;
extern cpp2::i32 auto_33_1;
extern cpp2::i32 auto_34_1;
extern cpp2::i32 auto_35_1;

auto main() -> int;
  

//=== Cpp2 function definitions =================================================

[[nodiscard]] auto print_res(cpp2::in<cpp2::i32> x) -> cpp2::i32{
  std::cout << x;
  if (x == 9) {std::cout << '\n'; }
  return x; 
}

#line 8 "pure2-bugfix-for-ufcs-arguments.cpp2"
  [[nodiscard]] auto t::f() & -> cpp2::i32 { return print_res(0);  }
  [[nodiscard]] auto t::f([[maybe_unused]] auto const& param2) & -> cpp2::i32 { return print_res(1);  }
  template<typename _> [[nodiscard]] auto t::f() & -> cpp2::i32 { return print_res(2);  }
  template<typename _> [[nodiscard]] auto t::f([[maybe_unused]] auto const& param2) & -> cpp2::i32 { return print_res(3);  }
  template<typename _, typename U> [[nodiscard]] auto t::f([[maybe_unused]] auto const& param2, [[maybe_unused]] auto const& param3) & -> cpp2::i32 { return print_res(4);  }

#line 15 "pure2-bugfix-for-ufcs-arguments.cpp2"
[[nodiscard]] auto f([[maybe_unused]] cpp2::in<t> param1) -> cpp2::i32 { return print_res(5);  }
[[nodiscard]] auto f([[maybe_unused]] cpp2::in<t> param1, [[maybe_unused]] auto const& param2) -> cpp2::i32 { return print_res(6);  }
template<typename _> [[nodiscard]] auto f([[maybe_unused]] cpp2::in<t> param1) -> cpp2::i32 { return print_res(7);  }
template<typename _> [[nodiscard]] auto f([[maybe_unused]] cpp2::in<t> param1, [[maybe_unused]] auto const& param2) -> cpp2::i32 { return print_res(8);  }
template<typename _, typename U> [[nodiscard]] auto f([[maybe_unused]] cpp2::in<t> param1, [[maybe_unused]] auto const& param2, [[maybe_unused]] auto const& param3) -> cpp2::i32 { return print_res(9);  }

t m {}; 
t const n {}; 

#line 25 "pure2-bugfix-for-ufcs-arguments.cpp2"
cpp2::i32 auto_25_1 {CPP2_UFCS_NONLOCAL(f)(m)}; 
cpp2::i32 auto_26_1 {CPP2_UFCS_NONLOCAL(f)(m, 0)}; 
cpp2::i32 auto_27_1 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t>)(m)}; 
cpp2::i32 auto_28_1 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t>)(m, 0)}; 
cpp2::i32 auto_29_1 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t,t>)(m, 0, 0)}; 
cpp2::i32 auto_30_1 {CPP2_UFCS_NONLOCAL(f)(n)}; 
cpp2::i32 auto_31_1 {CPP2_UFCS_NONLOCAL(f)(n, 0)}; 
cpp2::i32 auto_32_1 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t>)(n)}; 
cpp2::i32 auto_33_1 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t>)(n, 0)}; 
cpp2::i32 auto_34_1 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t,t>)(n, 0, 0)}; 
cpp2::i32 auto_35_1 {CPP2_UFCS_TEMPLATE_NONLOCAL(f<t,t>)(a<t,t>, 0, 0)}; 

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

  static_cast<void>([](auto const& a, auto const& f) -> void{static_cast<void>(CPP2_UFCS(f)(CPP2_UFCS(f)(a, a))); });
}

