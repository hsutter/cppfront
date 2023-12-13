
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-types-down-upcast.cpp2"
class A;
#line 2 "pure2-types-down-upcast.cpp2"
  

#line 8 "pure2-types-down-upcast.cpp2"
class B;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-types-down-upcast.cpp2"
class A {
#line 2 "pure2-types-down-upcast.cpp2"
  public: int i {0}; 

 public: virtual auto const_foo() const -> void;
 public: auto mut_foo() & -> void;
  public: A() = default;
  public: A(A const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(A const&) -> void = delete;

#line 6 "pure2-types-down-upcast.cpp2"
};

class B: public A {

  public: double d {0.0}; 
  public: B() = default;
  public: B(B const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(B const&) -> void = delete;

#line 11 "pure2-types-down-upcast.cpp2"
};

auto func_mut(A& a) -> void;
auto func_mut(B& b) -> void;
auto func_const(cpp2::in<A> a) -> void;
auto func_const(cpp2::in<B> b) -> void;

auto test_const_foo() -> void;

#line 29 "pure2-types-down-upcast.cpp2"
auto test_mut_foo() -> void;

#line 36 "pure2-types-down-upcast.cpp2"
auto test_up() -> void;

#line 55 "pure2-types-down-upcast.cpp2"
auto test_down() -> void;

#line 77 "pure2-types-down-upcast.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-types-down-upcast.cpp2"

#line 4 "pure2-types-down-upcast.cpp2"
 auto A::const_foo() const -> void{std::cout << "const foo \n"; }
 auto A::mut_foo() & -> void{std::cout << "foo \n"; }

#line 13 "pure2-types-down-upcast.cpp2"
auto func_mut(A& a) -> void     {std::cout << "Call A mut: " + cpp2::to_string(a.i) << std::endl;}
auto func_mut(B& b) -> void     {std::cout << "Call B mut: " + cpp2::to_string(b.d) << std::endl;}
auto func_const(cpp2::in<A> a) -> void{std::cout << "Call A const: " + cpp2::to_string(a.i) << std::endl;}
auto func_const(cpp2::in<B> b) -> void{std::cout << "Call B const: " + cpp2::to_string(b.d) << std::endl;}

auto test_const_foo() -> void{
 A s {}; 
  A const* sC {&s}; 
  CPP2_UFCS(const_foo)(s);
  CPP2_UFCS(const_foo)((*cpp2::assert_not_null(sC)));
 CPP2_UFCS(const_foo)((cpp2::as_<A>(s)));
  CPP2_UFCS(const_foo)((cpp2::as_<A>(*cpp2::assert_not_null(sC))));
  static_cast<void>(std::move(s));
  static_cast<void>(std::move(sC));
}

auto test_mut_foo() -> void{
 A s {}; 
  CPP2_UFCS(mut_foo)(s);
 CPP2_UFCS(mut_foo)((cpp2::as_<A>(s)));
  static_cast<void>(std::move(s));
}

auto test_up() -> void{
  B b {}; 
  B const* bC {&b}; 

  func_const(b);
  func_const(cpp2::as_<B>(b));
  func_const(cpp2::as_<A>(b));
  func_const(*cpp2::assert_not_null(bC));
  func_const(cpp2::as_<B>(*cpp2::assert_not_null(bC)));
  func_const(cpp2::as_<A>(*cpp2::assert_not_null(bC)));

  func_mut(b);
  func_mut(cpp2::as_<B>(b));
  func_mut(cpp2::as_<A>(b));

  static_cast<void>(std::move(b));
  static_cast<void>(std::move(bC));
}

auto test_down() -> void{
  B b {}; 
  B const* bC {&b}; 
  A* a {&(cpp2::as_<A>(b))}; 
  A const* aC {&(cpp2::as_<A>(b))}; 

  func_const(*cpp2::assert_not_null(a));
  func_const(cpp2::as_<B>(*cpp2::assert_not_null(a)));
  func_const(cpp2::as_<A>(*cpp2::assert_not_null(a)));
  func_const(*cpp2::assert_not_null(aC));
  func_const(cpp2::as_<B>(*cpp2::assert_not_null(aC)));
  func_const(cpp2::as_<A>(*cpp2::assert_not_null(aC)));
  func_mut(*cpp2::assert_not_null(a));
  func_mut(cpp2::as_<B>(*cpp2::assert_not_null(a)));
  func_mut(cpp2::as_<A>(*cpp2::assert_not_null(a)));

  static_cast<void>(std::move(b));
  static_cast<void>(std::move(bC));
  static_cast<void>(std::move(a));
  static_cast<void>(std::move(aC));
}

[[nodiscard]] auto main() -> int{

  test_const_foo();
  test_mut_foo();
  test_up();
  test_down();

  return 0; 
}

