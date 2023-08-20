
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-function-type-id.cpp2"
auto main() -> int;
  

#line 80 "pure2-function-type-id.cpp2"
// As non-local function parameter.
auto g(cpp2::in<cpp2::fn_t<void()>> f) -> void;
auto g(cpp2::fn_t<void()>* f) -> void;
auto g(cpp2::fn_t<cpp2::fn_t<void()>*()>* f) -> void;
// As template parameter.
template<cpp2::fn_t<void()>* V> auto g() -> void;
template<cpp2::fn_t<cpp2::fn_t<void()>*()>* V> auto g() -> void;

// In non-local function return type.
[[nodiscard]] auto g1() -> cpp2::fn_t<void()>*;
template<bool V> [[nodiscard]] auto g1() -> cpp2::fn_t<void()>*;
[[nodiscard]] auto g2() -> cpp2::fn_t<cpp2::fn_t<void()>*()>*;

// clang-format off
// Test case from #343.
[[nodiscard]] auto f2() -> std::function<cpp2::fn_t<std::string(cpp2::in<std::string>)>>;
  

#line 99 "pure2-function-type-id.cpp2"
// Adapted from <https://github.com/hsutter/cppfront/wiki/Design-note%3A-Postfix-operators>.
            [[nodiscard]] auto f(cpp2::in<cpp2::i32> x) -> cpp2::fn_t<std::string(cpp2::in<cpp2::i32>)>*;
auto postfix_operators() -> void;
  

//=== Cpp2 function definitions =================================================

#line 1 "pure2-function-type-id.cpp2"
auto main() -> int{
  postfix_operators();

  // Variables with type of a mix of `*`/`const` to `() -> void`.
  cpp2::fn_t<void()>* f0 {[]() -> void{}}; 
  cpp2::fn_t<void()>* const f1 {f0}; 
  cpp2::fn_t<void()> const* f2 {f0}; 
  cpp2::fn_t<void()> const* const f3 {f0}; 

  // Uninitialized.
  cpp2::deferred_init<cpp2::fn_t<void()>*> f4; 
  f4.construct(f0);

  cpp2::fn_t<void()>** f10 {&f0}; 
  cpp2::fn_t<void()>** const f11 {f10}; 
  cpp2::fn_t<void()>* const* f12 {f10}; 
  cpp2::fn_t<void()>* const* const f13 {f10}; 

  cpp2::i32 i {0}; 
  cpp2::i32* i0 {&i}; 
  cpp2::i32* const i1 {i0}; 
  cpp2::i32 const* i2 {i0}; 
  cpp2::i32 const* const i3 {i0}; 

  // Assert consistent '*'/'const' with non-function type variables.
  static_assert((std::is_const_v<decltype(f10)>)==std::is_const_v<decltype(i0)>);
  static_assert((std::is_const_v<decltype(f11)>)==std::is_const_v<decltype(i1)>);
  static_assert((std::is_const_v<decltype(f12)>)==std::is_const_v<decltype(i2)>);
  static_assert((std::is_const_v<decltype(f13)>)==std::is_const_v<decltype(i3)>);
  (void) std::move(f10);
  (void) std::move(f11);
  (void) std::move(f12);
  (void) std::move(f13);
  (void) std::move(i0);
  (void) std::move(i1);
  (void) std::move(i2);
  (void) std::move(i3);

  // Variables with various kinds of parameter.
  cpp2::fn_t<void(cpp2::in<cpp2::i32>)>* f5 {[](cpp2::in<cpp2::i32> x) -> void{}}; 
  cpp2::fn_t<void(cpp2::in<std::any>)>* f6 {[](cpp2::in<std::any> x) -> void{}}; 
  cpp2::fn_t<void(cpp2::i32&&)>* f7 {[](cpp2::i32&& x) -> void{}}; 
  cpp2::fn_t<void(cpp2::out<cpp2::i32>)>* f8 {[](auto x) -> void{}}; 

  // In alternative.
  cpp2::Default.expects([&] () -> bool { auto&& __expr = f0;
    if (cpp2::is<cpp2::fn_t<void() noexcept>>(__expr)) { if constexpr( requires{std::terminate(), false;} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((std::terminate(), false)),bool> ) return std::terminate(), false; else return bool{}; else return bool{}; }
    else if (cpp2::is<cpp2::fn_t<void()>>(__expr)) { if constexpr( requires{std::terminate(), false;} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((std::terminate(), false)),bool> ) return std::terminate(), false; else return bool{}; else return bool{}; }
    else if (cpp2::is<cpp2::fn_t<void()>*>(__expr)) { if constexpr( requires{true;} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((true)),bool> ) return true; else return bool{}; else return bool{}; }
    else return false; }
  (), "");
  cpp2::Default.expects([&] () -> bool { auto&& __expr = *cpp2::assert_not_null(f0);
    if (cpp2::is<cpp2::fn_t<void()>>(__expr)) { if constexpr( requires{true;} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((true)),bool> ) return true; else return bool{}; else return bool{}; }
    else return false; }
  (), "");
{
cpp2::fn_t<void()>* f = f0;

  // As block variable.
#line 58 "pure2-function-type-id.cpp2"
  {}
}
{
cpp2::in<cpp2::fn_t<void()>> f = *cpp2::assert_not_null(f0);
#line 59 "pure2-function-type-id.cpp2"
                  { }
}

  // As local function parameter.
#line 62 "pure2-function-type-id.cpp2"
  (void) [](cpp2::in<cpp2::fn_t<void()>> f) -> void{};
  (void) [](cpp2::fn_t<void()>* f) -> void{};
  (void) [](cpp2::fn_t<cpp2::fn_t<void()>*()>* f) -> void{};
  (void) [](cpp2::fn_t<cpp2::fn_t<cpp2::fn_t<void()>*()>*()>* f) -> void{};

  // In local function return type.
  (void) [_0 = f0]() -> cpp2::fn_t<void()>& { return *cpp2::assert_not_null(_0);  };
  (void) []() -> cpp2::fn_t<void()>* { return nullptr;  };
  (void) []() -> cpp2::fn_t<cpp2::fn_t<void()>*()>* { return nullptr;  };

  // With `!throws`.
  (void) std::type_identity_t<cpp2::fn_t<void(std::string_view, CPP2_MESSAGE_PARAM) noexcept>*>{cpp2::report_and_terminate};

  // As template argument.
  (void) std::type_identity_t<cpp2::fn_t<void()>*>{std::move(f0)};
  static_assert(std::is_function_v<cpp2::fn_t<void()>>);
}

#line 81 "pure2-function-type-id.cpp2"
auto g(cpp2::in<cpp2::fn_t<void()>> f) -> void{}
auto g(cpp2::fn_t<void()>* f) -> void{}
auto g(cpp2::fn_t<cpp2::fn_t<void()>*()>* f) -> void{}

template<cpp2::fn_t<void()>* V> auto g() -> void{}
template<cpp2::fn_t<cpp2::fn_t<void()>*()>* V> auto g() -> void{}

#line 89 "pure2-function-type-id.cpp2"
[[nodiscard]] auto g1() -> cpp2::fn_t<void()>* { return nullptr; }
template<bool V> [[nodiscard]] auto g1() -> cpp2::fn_t<void()>*
requires (V)
#line 90 "pure2-function-type-id.cpp2"
{return nullptr; }
[[nodiscard]] auto g2() -> cpp2::fn_t<cpp2::fn_t<void()>*()>* { return nullptr; }

#line 95 "pure2-function-type-id.cpp2"
[[nodiscard]] auto f2() -> std::function<cpp2::fn_t<std::string(cpp2::in<std::string>)>>{
  return [](cpp2::in<std::string> s) -> std::string{return s + " World!"; }; 
}

#line 100 "pure2-function-type-id.cpp2"
            [[nodiscard]] auto f(cpp2::in<cpp2::i32> x) -> cpp2::fn_t<std::string(cpp2::in<cpp2::i32>)>* { return [](cpp2::in<cpp2::i32> x) -> std::string { return ""; }; }
auto postfix_operators() -> void{
  cpp2::Default.expects(cpp2::is<cpp2::fn_t<cpp2::fn_t<std::string(cpp2::in<cpp2::i32>)>*(cpp2::in<cpp2::i32>)>>(f), "");
  //             /           |  |
  //            /            |  |
  cpp2::Default.expects(cpp2::is<cpp2::fn_t<std::string(cpp2::in<cpp2::i32>)>*>(f(42)), "");
  //               _________/   |
  //              /             |
  cpp2::Default.expects(cpp2::is<cpp2::fn_t<std::string(cpp2::in<cpp2::i32>)>>(*cpp2::assert_not_null(f(42))), "");
  //                   ________/
  //                  /
  cpp2::Default.expects(cpp2::is<std::string>((*cpp2::assert_not_null(f(42)))(1)), "");
} // clang-format on

