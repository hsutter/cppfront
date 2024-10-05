
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use.cpp2"

#line 169 "pure2-last-use.cpp2"
class issue_857;
  

#line 257 "pure2-last-use.cpp2"
class issue_857_2;
  

#line 262 "pure2-last-use.cpp2"
class issue_857_3;
  

#line 266 "pure2-last-use.cpp2"
class issue_857_6;
  

#line 271 "pure2-last-use.cpp2"
class issue_857_4;
   

#line 331 "pure2-last-use.cpp2"
class issue_857_5;
  

#line 336 "pure2-last-use.cpp2"
class issue_857_7;
  

#line 342 "pure2-last-use.cpp2"
class issue_857_8;
  

#line 348 "pure2-last-use.cpp2"
class issue_857_9;
  

#line 365 "pure2-last-use.cpp2"
class issue_869_0;
  

class issue_869_1;
  

#line 838 "pure2-last-use.cpp2"
class cpp2_union;
  

#line 846 "pure2-last-use.cpp2"
class my_string;
  

#line 905 "pure2-last-use.cpp2"
namespace captures {

#line 919 "pure2-last-use.cpp2"
class t;
  

#line 948 "pure2-last-use.cpp2"
}

#line 978 "pure2-last-use.cpp2"
class types;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use.cpp2"
auto f_inout([[maybe_unused]] auto& unnamed_param_1) -> void;
#line 2 "pure2-last-use.cpp2"
auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void;
[[nodiscard]] auto pred([[maybe_unused]] auto const& ...unnamed_param_1) -> decltype(auto);
[[nodiscard]] auto pred_copy([[maybe_unused]] auto ...unnamed_param_1) -> decltype(auto);
template<typename T> [[nodiscard]] constexpr auto identity(T&& x) -> decltype(auto)
CPP2_REQUIRES (std::is_reference_v<T>) ;
#line 6 "pure2-last-use.cpp2"
[[nodiscard]] auto identity_copy(auto x) -> auto
CPP2_REQUIRES (std::copyable<decltype(x)>) ;
#line 7 "pure2-last-use.cpp2"
[[nodiscard]] auto identity_copy(auto&& x) -> auto
CPP2_REQUIRES (!(std::copyable<decltype(x)>)) ;

#line 9 "pure2-last-use.cpp2"
auto issue_313() -> void;

#line 73 "pure2-last-use.cpp2"
auto issue_313_1(std::unique_ptr<int> x) -> void;

auto issue_350() -> void;

#line 86 "pure2-last-use.cpp2"
/*
issue_440_0: () -> int = {
  i: int;
  if true {
    i = 1;
    return i;
  }
  i = 2;
  return i;
}

issue_440_1: () -> (i: int) = {
  if true {
    i = 1;
    return;
  }
  i = 2;
}
*/
auto issue_683(auto const& args) -> void;

#line 114 "pure2-last-use.cpp2"
auto issue_825() -> void;

#line 120 "pure2-last-use.cpp2"
auto issue_832() -> void;

#line 125 "pure2-last-use.cpp2"
[[nodiscard]] auto make_copy(auto x) -> auto;

auto issue_847_4(std::vector<int> v) -> void;

#line 133 "pure2-last-use.cpp2"
auto issue_847_0(std::vector<std::unique_ptr<int>> v) -> void;

#line 139 "pure2-last-use.cpp2"
// issue_847_1: (move v: std::vector<std::unique_ptr<int>>) = {
//   for v.make_copy()
//   do (move x) {
//     f_inout(x);  // error, can't pass rvalue to inout param
//   }
// }
auto issue_847_5(auto&& v) -> void;

#line 151 "pure2-last-use.cpp2"
auto issue_847_2(auto&& v) -> void;

#line 156 "pure2-last-use.cpp2"
auto issue_847_3(int x) -> void;

auto issue_850() -> void;

#line 169 "pure2-last-use.cpp2"
class issue_857 {
  private: std::unique_ptr<int> a; 
  private: std::unique_ptr<int> b; 
  public: issue_857(issue_857&& that) noexcept;
#line 172 "pure2-last-use.cpp2"
  public: auto operator=(issue_857&& that) noexcept -> issue_857& ;
//   operator=: (move this) = {
//     f_inout(a);      // error, can't pass rvalue to inout param
//     f_inout(this.b); // error, can't pass rvalue to inout param
//   }
  //f: (move this) = f_copy(this);
  //f: (move this, move that) = f_copy(this, that);
  //g: (move this) = f_copy(this.a);
  //g: (move this, move that) = f_copy(this.a, that.a);
  public: [[nodiscard]] auto h() & -> decltype(auto);
  //i: (move this) = f_copy(a);
  //j: (move this) = f_copy(a);
  //k: (move this) = {
  //  f_inout(a);
  //  f_copy(b);
  //}
  //l: (move this) = k();
  //m: (move this) = this.k();
  //n: (_) = { }
  //n: (move this) = { }
  //o0:(move this) = n();
  //o1:(move this) = this.n();
  //o2:(move this) = 0.n();
  //o3:(move this) = n(0);
  //o4:(move this) = n(this);
  //p0: (move this) = {
  //  f_inout(a);
  //  f_copy(this.a);
  //}
  //p1: (move this) = {
  //  f_inout(this.a);
  //  f_copy(a);
  //}
  //p2: (move this) = {
  //  f_inout(a);
  //  f_copy(this);
  //}
  //p3: (move this) = {
  //  f_inout(this);
  //  f_copy(a);
  //}
  //q: (move this) = {
  //  h();
  //  n();
  //}
  //z: (move this, move that) = {
  ///*f */      if true { f_copy(this); }
  ///*f */ else if true { f_copy(this, that); }
  ///*g */ else if true { f_copy(this.a); }
  ///*g */ else if true { f_copy(this.a, that.a); }
  ///*i */ else if true { f_copy(a); }
  ///*j */ else if true { f_copy(a); }
  ///*k */ else if true {
  ///*k */   f_inout(a);
  ///*k */   f_copy(b);
  ///*k */ }
  ///*l */ else if true { k(); }
  ///*m */ else if true { this.k(); }
  ///*o1*/ else if true { n(); }
  ///*o2*/ else if true { this.n(); }
  ///*o3*/ else if true { n(0); }
  ///*o4*/ else if true { n(this); }
  ///*p0*/ else if true {
  ///*p0*/   f_inout(a);
  ///*p0*/   f_copy(this.a);
  ///*p0*/ }
  ///*p1*/ else if true {
  ///*p1*/   f_inout(this.a);
  ///*p1*/   f_copy(a);
  ///*p1*/ }
  ///*p2*/ else if true {
  ///*p2*/   f_inout(a);
  ///*p2*/   f_copy(this);
  ///*p2*/ }
  ///*p3*/ else if true {
  ///*p3*/   f_inout(this);
  ///*p3*/   f_copy(a);
  ///*p3*/ }
  ///*q */ else {
  ///*q */   h();
  ///*q */   n();
  ///*q */ }
  //}
};

class issue_857_2 {
  public: std::unique_ptr<int> a; 
  public: issue_857_2(auto&& a_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<std::unique_ptr<int>>&>) ;

public: auto operator=(auto&& a_) -> issue_857_2& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<std::unique_ptr<int>>&>) ;

#line 258 "pure2-last-use.cpp2"
                           // OK: No error about 'a' being unused.
#line 259 "pure2-last-use.cpp2"
};

extern int gi;
class issue_857_3 {
  public: std::add_lvalue_reference_t<int> i {gi}; 
  public: [[nodiscard]] auto f() && -> decltype(auto);
  public: issue_857_3(auto&& i_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) ;

public: auto operator=(auto&& i_) -> issue_857_3& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) ;
public: issue_857_3();

#line 265 "pure2-last-use.cpp2"
};
class issue_857_6 {
  public: [[nodiscard]] auto f() && -> decltype(auto);
  public: std::add_lvalue_reference_t<int> i {gi}; 
  public: issue_857_6(auto&& i_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) ;

public: auto operator=(auto&& i_) -> issue_857_6& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) ;
public: issue_857_6();

#line 269 "pure2-last-use.cpp2"
};

class issue_857_4 {
   public: std::add_pointer_t<int()> f; 
   public: std::add_pointer_t<int([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1)> g; 
  public: std::move_only_function<int()> mf; 
  public: std::move_only_function<int([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1)> mg; 
  public: issue_857_4(auto&& f_, auto&& g_, auto&& mf_, auto&& mg_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(f_), std::add_const_t<std::add_pointer_t<int()>>&> && std::is_convertible_v<CPP2_TYPEOF(g_), std::add_const_t<std::add_pointer_t<int(cpp2::impl::in<int> in_)>>&> && std::is_convertible_v<CPP2_TYPEOF(mf_), std::add_const_t<std::move_only_function<int()>>&> && std::is_convertible_v<CPP2_TYPEOF(mg_), std::add_const_t<std::move_only_function<int(cpp2::impl::in<int> in_)>>&>) ;

//   h0: (move this) = _ = mf();
//   h1: (move this) = _ = this.mf();
//   h2: (move this, that) = _ = that.mf();
//   h3: (move this, that) = _ = that.f;
//   h4: (move this, x: int) = _ = x.mg();
//   h5: (move this, x: int) = _ = f() + x.g();      // FIXME #313.
//   h6: (move this, x: int) = _ = x.g() + f();      // FIXME #313.
//   h7: (move this, x: int) = _ = this.f() + x.g(); // FIXME #313.
//   h8: (move this, x: int) = _ = x.g() + this.f(); // FIXME #313.
//   i0: (move this, x: int) = {
//     _ = f();
//     _ = x.mg();
//   }
//   i1: (move this, x: int) = {
//     _ = x.g();
//     _ = mf();
//   }
//   i2: (move this, x: int) = {
//     _ = this.f();
//     _ = x.mg();
//   }
//   i3: (move this, x: int) = {
//     _ = x.g();
//     _ = this.mf();
//   }
//   z: (move this, that) = {
//   x := 0;
//   /*h0*/      if true { _ = mf(); }
//   /*h1*/ else if true { _ = this.mf(); }
//   /*h2*/ else if true { _ = that.mf(); }
//   /*h3*/ else if true { _ = that.f; }
//   /*h4*/ else if true { _ = x.mg(); }
//   /*h5*/ else if true { _ = f() + x.g(); }
//   /*h6*/ else if true { _ = x.g() + f(); }
//   /*h7*/ else if true { _ = this.f() + x.g(); }
//   /*h8*/ else if true { _ = x.g() + this.f(); }
//   /*i0*/ else if true {
//   /*i0*/   _ = f();
//   /*i0*/   _ = x.mg();
//   /*i0*/ }
//   /*i1*/ else if true {
//   /*i1*/   _ = x.g();
//   /*i1*/   _ = mf();
//   /*i1*/ }
//   /*i2*/ else if true {
//   /*i2*/   _ = this.f();
//   /*i2*/   _ = x.mg();
//   /*i2*/ }
//   /*i3*/ else {
//   /*i3*/   _ = x.g();
//   /*i3*/   _ = this.mf();
//   /*i3*/ }
//   }
#line 329 "pure2-last-use.cpp2"
};

class issue_857_5 {
  public: [[nodiscard]] auto f() && -> decltype(auto);
  public: std::unique_ptr<int> a; 
  public: issue_857_5(auto&& a_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<std::unique_ptr<int>>&>) ;

public: auto operator=(auto&& a_) -> issue_857_5& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<std::unique_ptr<int>>&>) ;

#line 334 "pure2-last-use.cpp2"
};

struct issue_857_7_A_as_base { std::add_lvalue_reference_t<int> A; };
#line 336 "pure2-last-use.cpp2"
class issue_857_7: public issue_857_7_A_as_base, public std::monostate {

#line 339 "pure2-last-use.cpp2"
  public: [[nodiscard]] auto F() && -> decltype(auto);
  public: issue_857_7(auto&& A_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(A_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) ;

#line 340 "pure2-last-use.cpp2"
};

class issue_857_8 {
  public: std::unique_ptr<int> a; 
  public: std::move_only_function<int()> b; 
  public: std::add_lvalue_reference_t<int> c; 
  public: auto d() && -> void;
  public: issue_857_8(auto&& a_, auto&& b_, auto&& c_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<std::unique_ptr<int>>&> && std::is_convertible_v<CPP2_TYPEOF(b_), std::add_const_t<std::move_only_function<int()>>&> && std::is_convertible_v<CPP2_TYPEOF(c_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) ;

#line 347 "pure2-last-use.cpp2"
};
class issue_857_9: public issue_857_8 {

#line 351 "pure2-last-use.cpp2"
  // Error: Cppfront limitation:
  // <https://eel.is/c++draft/class.mfct.non.static#2.sentence-1>.
//f0: (move this) = f_copy(a);
//f1: (move this) = _ = b();
  public: [[nodiscard]] auto f2() && -> decltype(auto);
//f3: (move this) = d();

  // OK: Explicit 'this' for base members, like in templates.
  //g0: (move this) = f_inout(this.a);  // error, can't pass rvalue to inout param
  //g1: (move this) = _ = this.b();
  public: [[nodiscard]] auto g2() && -> decltype(auto);
  //g3: (move this) = this.d();
};

class issue_869_0 {
  public: explicit issue_869_0([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2);
#line 366 "pure2-last-use.cpp2"
  public: auto operator=([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2) -> issue_869_0& ;
  public: [[nodiscard]] auto operator<=>([[maybe_unused]] issue_869_0 const& that) const& -> std::strong_ordering = default;
public: issue_869_0([[maybe_unused]] issue_869_0 const& that);

public: auto operator=([[maybe_unused]] issue_869_0 const& that) -> issue_869_0& ;
public: issue_869_0([[maybe_unused]] issue_869_0&& that) noexcept;
public: auto operator=([[maybe_unused]] issue_869_0&& that) noexcept -> issue_869_0& ;
public: explicit issue_869_0();

#line 367 "pure2-last-use.cpp2"
};
class issue_869_1 {
private: cpp2::aligned_storage<cpp2::max(sizeof(issue_869_0)),cpp2::max(alignof(issue_869_0))> _storage {}; private: cpp2::i8 _discriminator {-1}; public: [[nodiscard]] auto is_i() const& -> bool;
public: [[nodiscard]] auto i() const& -> issue_869_0 const&;
public: [[nodiscard]] auto i() & -> issue_869_0&;
public: auto set_i(cpp2::impl::in<issue_869_0> _value) & -> void;
public: auto set_i(auto&& ..._args) & -> void;
private: auto _destroy() & -> void;
public: ~issue_869_1() noexcept;
public: explicit issue_869_1();
public: issue_869_1(issue_869_1 const& that);

public: issue_869_1(issue_869_1&& that) noexcept;
public: auto operator=(issue_869_1 const& that) -> issue_869_1& ;
public: auto operator=(issue_869_1&& that) noexcept -> issue_869_1& ;

#line 370 "pure2-last-use.cpp2"
};

using issue_869_2_ret = issue_869_1;
[[nodiscard]] auto issue_869_2() -> issue_869_2_ret;

#line 373 "pure2-last-use.cpp2"
auto issue_884() -> void;

#line 770 "pure2-last-use.cpp2"
auto issue_888_0(std::string r, int size) -> void;

#line 773 "pure2-last-use.cpp2"
auto issue_888_1([[maybe_unused]] std::string unnamed_param_1, std::move_only_function<int([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1)> size) -> void;

#line 777 "pure2-last-use.cpp2"
auto issue_890() -> void;

#line 783 "pure2-last-use.cpp2"
auto issue_962(cpp2::impl::in<::std::string> s) -> void;

#line 788 "pure2-last-use.cpp2"
auto draw() -> void;

#line 794 "pure2-last-use.cpp2"
auto enum_0() -> void;

#line 799 "pure2-last-use.cpp2"
auto enum_1() -> void;

#line 828 "pure2-last-use.cpp2"
auto enum_2() -> void;

#line 838 "pure2-last-use.cpp2"
class cpp2_union {
  public: auto destroy() & -> void;
  public: ~cpp2_union() noexcept;
  public: cpp2_union() = default;
  public: cpp2_union(cpp2_union const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(cpp2_union const&) -> void = delete;


#line 844 "pure2-last-use.cpp2"
};

class my_string {
  public: std::string string; 
  public: std::size_t size {CPP2_UFCS(size)(string)}; 
  public: my_string(auto&& string_, auto&& size_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(string_), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(size_), std::add_const_t<std::size_t>&>) ;

#line 849 "pure2-last-use.cpp2"
};

using no_pessimizing_move_ret = std::unique_ptr<int>;
#line 851 "pure2-last-use.cpp2"
[[nodiscard]] auto no_pessimizing_move() -> no_pessimizing_move_ret;

auto deferred_non_copyable_0() -> void;

#line 859 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_1() -> auto;
using deferred_non_copyable_2_ret = std::unique_ptr<int>;


#line 865 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_2() -> deferred_non_copyable_2_ret;

#line 869 "pure2-last-use.cpp2"
auto loops() -> void;

#line 905 "pure2-last-use.cpp2"
namespace captures {

// Skip non captured name in function expression

auto f() -> void;

#line 917 "pure2-last-use.cpp2"
int inline constexpr x{ 0 };

class t {
  public: std::unique_ptr<int> x; 
  public: auto operator()() && -> void;
  public: t(auto&& x_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<std::unique_ptr<int>>&>) ;

public: auto operator=(auto&& x_) -> t& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<std::unique_ptr<int>>&>) ;

#line 932 "pure2-last-use.cpp2"
};

auto g() -> void;

#line 948 "pure2-last-use.cpp2"
}

auto loops_and_captures() -> void;

#line 978 "pure2-last-use.cpp2"
class types {
  public: std::unique_ptr<int> x; 
  public: types(auto&& x_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<std::unique_ptr<int>>&>) ;

public: auto operator=(auto&& x_) -> types& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<std::unique_ptr<int>>&>) ;

#line 980 "pure2-last-use.cpp2"
//   f: (move this) = _ = :() x$*;
//   g: (move this) = {
//     for (:() x$*)
//     do (_)
//     { }
//   }
#line 986 "pure2-last-use.cpp2"
};

auto skip_hidden_names() -> void;

#line 1038 "pure2-last-use.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-last-use.cpp2"
auto f_inout([[maybe_unused]] auto& unnamed_param_1) -> void{}
#line 2 "pure2-last-use.cpp2"
auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void{}
#line 3 "pure2-last-use.cpp2"
[[nodiscard]] auto pred([[maybe_unused]] auto const& ...unnamed_param_1) -> decltype(auto) { return true; }
#line 4 "pure2-last-use.cpp2"
[[nodiscard]] auto pred_copy([[maybe_unused]] auto ...unnamed_param_1) -> decltype(auto) { return true;  }
#line 5 "pure2-last-use.cpp2"
template<typename T> [[nodiscard]] constexpr auto identity(T&& x) -> decltype(auto)
requires (std::is_reference_v<T>) {return CPP2_FORWARD(x); }
#line 6 "pure2-last-use.cpp2"
[[nodiscard]] auto identity_copy(auto x) -> auto
requires (std::copyable<decltype(x)>)  { return cpp2::move(x); }
#line 7 "pure2-last-use.cpp2"
[[nodiscard]] auto identity_copy(auto&& x) -> auto
requires (!(std::copyable<decltype(x)>))  { return std::move(cpp2::move(x));  }

#line 9 "pure2-last-use.cpp2"
auto issue_313() -> void{
//   _ = :() -> std::vector<int> = {
//     a := new<int>(0);
//     return (a*, identity_copy(a)*);
//   };
//   _ = :() -> std::vector<int> = {
//     a := new<int>(0);
//     return (a&**, identity_copy(a)*);
//   };
  static_cast<void>([]() -> int{
    auto a {cpp2_new<int>(0)}; 
    return *cpp2::impl::assert_not_null(identity(a)) + *cpp2::impl::assert_not_null(identity(a)); 

    auto b {cpp2_new<int>(0)}; 
    return *cpp2::impl::assert_not_null(identity(b)) = *cpp2::impl::assert_not_null(identity(b)); 

    auto c {cpp2_new<int>(0)}; 
    return *cpp2::impl::assert_not_null(identity(c)) ^ *cpp2::impl::assert_not_null(identity(c)); 
  });
  {
    auto a {cpp2_new<int>(0)}; 
    *cpp2::impl::assert_not_null(identity(a)) = *cpp2::impl::assert_not_null(identity(a));

    auto b {cpp2_new<int>(0)}; 
    int auto_1 {*cpp2::impl::assert_not_null(identity(b)) = *cpp2::impl::assert_not_null(identity(b))}; 

    auto c {cpp2_new<int>(0)}; 
    if (*cpp2::impl::assert_not_null(identity(c)) * *cpp2::impl::assert_not_null(identity(c))) {}

    auto d {cpp2_new<int>(0)}; 
    if ((*cpp2::impl::assert_not_null(identity(d)) - *cpp2::impl::assert_not_null(identity(d)))) {}

    auto e {cpp2_new<int>(0)}; 
    static_cast<void>(cpp2::impl::is(e, (e)));

    auto f {cpp2_new<int>(0)}; 
    static_cast<void>(cpp2::impl::is<decltype(f)>(f));// OK?

    auto g {cpp2_new<int>(0)}; 
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { *cpp2::impl::assert_not_null(identity(g)) + *cpp2::impl::assert_not_null(identity(g)) } ) 
    {}

    auto h {cpp2_new<int>(0)}; 
    while( *cpp2::impl::assert_not_null(identity(h)) + *cpp2::impl::assert_not_null(identity(h)) ) 
    {}

    auto i {cpp2_new<int>(0)}; 
    do {} while ( 
    *cpp2::impl::assert_not_null(identity(i)) + *cpp2::impl::assert_not_null(identity(i)));

    auto j {cpp2_new<int>(0)}; 
    auto k {cpp2_new<int>(0)}; 
    static_cast<void>([&] () -> int { auto&& _expr = *cpp2::impl::assert_not_null(identity(j)) + *cpp2::impl::assert_not_null(identity(j));
        if (cpp2::impl::is(_expr, (*cpp2::impl::assert_not_null(identity(k)) + *cpp2::impl::assert_not_null(identity(k))))) { if constexpr( requires{0;} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((0)),int> ) return 0; else return int{}; else return int{}; }
        else return 0; }
    ());

  }
//   {
//     a := new<int>(0);
//     _ = :() identity(a$)* + identity(a$)*;
//   }
}
#line 73 "pure2-last-use.cpp2"
auto issue_313_1(std::unique_ptr<int> x) -> void{
                                                                                 if (cpp2::cpp2_default.is_active() && !(*cpp2::impl::assert_not_null(identity(x)) + *cpp2::impl::assert_not_null(identity(x))) ) { cpp2::cpp2_default.report_violation(""); }}

#line 75 "pure2-last-use.cpp2"
auto issue_350() -> void{
    auto x {21}; 

    auto l1 {[](auto&& x) -> void{
        f_inout(CPP2_FORWARD(x));
    }}; 

    cpp2::move(l1)(x);

    ++x;
}

#line 105 "pure2-last-use.cpp2"
auto issue_683(auto const& args) -> void{
    for ( auto const& n : args ) {
        static_cast<void>(n);
    }

    cpp2::impl::deferred_init<int> n; 
    n.construct(0);
}

#line 114 "pure2-last-use.cpp2"
auto issue_825() -> void{
  static_cast<void>([](std::unique_ptr<int> b) -> decltype(auto) { return f_copy(std::move(cpp2::move(b)));  });
  static_cast<void>([](std::unique_ptr<int>&& c) -> decltype(auto) { return f_copy(std::move(cpp2::move(c)));  });
  static_cast<void>([](auto&& d) -> decltype(auto) { return f_copy(CPP2_FORWARD(d));  }(cpp2_new<int>(0)));
}

#line 120 "pure2-last-use.cpp2"
auto issue_832() -> void{
  auto i {0}; 
  while( i ) {}
}

#line 125 "pure2-last-use.cpp2"
[[nodiscard]] auto make_copy(auto x) -> auto { return cpp2::move(x);  }

#line 127 "pure2-last-use.cpp2"
auto issue_847_4(std::vector<int> v) -> void{
  for ( 
  auto x : CPP2_UFCS(make_copy)(cpp2::move(v)) ) {
    f_copy(cpp2::move(x));
  }
}
#line 133 "pure2-last-use.cpp2"
auto issue_847_0(std::vector<std::unique_ptr<int>> v) -> void{
  // TODO Use 'std::views::as_rvalue`
  for ( 
  [[maybe_unused]] auto const& unnamed_param_1 : CPP2_UFCS(make_copy)(cpp2::move(v)) ) {
  }
}

#line 145 "pure2-last-use.cpp2"
auto issue_847_5(auto&& v) -> void{
  for ( 
  auto&& x : CPP2_UFCS(make_copy)(CPP2_FORWARD(v)) ) {
    f_copy(CPP2_FORWARD(x));
  }
}
#line 151 "pure2-last-use.cpp2"
auto issue_847_2(auto&& v) -> void{
  for ( 
  [[maybe_unused]] auto&& unnamed_param_1 : CPP2_UFCS(make_copy)(CPP2_FORWARD(v)) ) {
  }
}
#line 156 "pure2-last-use.cpp2"
auto issue_847_3(int x) -> void{for ( [[maybe_unused]] auto const& unnamed_param_1 : { cpp2::move(x) } ) {}}

#line 158 "pure2-last-use.cpp2"
auto issue_850() -> void{
    std::vector v {1, 2, 3, 4, 5}; 

    //  Definite last use of v => move-capture v into f's closure
    auto f {[_0 = cpp2::move(v)]() mutable -> auto&&{return _0; }}; 

    //  Now we can access the vector captured inside f()...
    CPP2_UFCS(push_back)(f(), 6);
    for ( auto const& e : cpp2::move(f)() ) std::cout << e; // prints 123456
}

#line 172 "pure2-last-use.cpp2"
  issue_857::issue_857(issue_857&& that) noexcept
                                       : a{ std::move(that).a }
                                       , b{ std::move(that).b }{}
#line 172 "pure2-last-use.cpp2"
  auto issue_857::operator=(issue_857&& that) noexcept -> issue_857& {
                                       a = std::move(that).a;
                                       b = std::move(that).b;
                                       return *this; }

#line 181 "pure2-last-use.cpp2"
  [[nodiscard]] auto issue_857::h() & -> decltype(auto) { return f_inout(a);  }

  issue_857_2::issue_857_2(auto&& a_)
requires (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<std::unique_ptr<int>>&>) 
                                                                            : a{ CPP2_FORWARD(a_) }{}

auto issue_857_2::operator=(auto&& a_) -> issue_857_2& 
requires (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<std::unique_ptr<int>>&>) {
                                                                            a = CPP2_FORWARD(a_);
                                                                            return *this;}
#line 261 "pure2-last-use.cpp2"
int gi {0}; 

#line 264 "pure2-last-use.cpp2"
  [[nodiscard]] auto issue_857_3::f() && -> decltype(auto) { return f_inout(cpp2::move(*this).i);  }

  issue_857_3::issue_857_3(auto&& i_)
requires (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) 
                                                                                        : i{ CPP2_FORWARD(i_) }{}

auto issue_857_3::operator=(auto&& i_) -> issue_857_3& 
requires (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) {
                                                                                        i = CPP2_FORWARD(i_);
                                                                                        return *this;}
issue_857_3::issue_857_3(){}
#line 264 "pure2-last-use.cpp2"
                               // OK: The implicit `this` is moved, not `i`.

#line 267 "pure2-last-use.cpp2"
  [[nodiscard]] auto issue_857_6::f() && -> decltype(auto) { return f_inout(cpp2::move(*this).i);  }

  issue_857_6::issue_857_6(auto&& i_)
requires (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) 
                                                                                        : i{ CPP2_FORWARD(i_) }{}

auto issue_857_6::operator=(auto&& i_) -> issue_857_6& 
requires (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) {
                                                                                        i = CPP2_FORWARD(i_);
                                                                                        return *this;}
issue_857_6::issue_857_6(){}
issue_857_4::issue_857_4(auto&& f_, auto&& g_, auto&& mf_, auto&& mg_)
requires (std::is_convertible_v<CPP2_TYPEOF(f_), std::add_const_t<std::add_pointer_t<int()>>&> && std::is_convertible_v<CPP2_TYPEOF(g_), std::add_const_t<std::add_pointer_t<int(cpp2::impl::in<int> in_)>>&> && std::is_convertible_v<CPP2_TYPEOF(mf_), std::add_const_t<std::move_only_function<int()>>&> && std::is_convertible_v<CPP2_TYPEOF(mg_), std::add_const_t<std::move_only_function<int(cpp2::impl::in<int> in_)>>&>) 
                                                                                                                                                                                                                                                                             : f{ CPP2_FORWARD(f_) }
                                                                                                                                                                                                                                                                             , g{ CPP2_FORWARD(g_) }
                                                                                                                                                                                                                                                                             , mf{ CPP2_FORWARD(mf_) }
                                                                                                                                                                                                                                                                             , mg{ CPP2_FORWARD(mg_) }{}
#line 267 "pure2-last-use.cpp2"
                               // OK: The implicit `this` is moved, not `i`.

#line 332 "pure2-last-use.cpp2"
  [[nodiscard]] auto issue_857_5::f() && -> decltype(auto) { return f_copy(std::move(cpp2::move(*this).a));  }

  issue_857_5::issue_857_5(auto&& a_)
requires (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<std::unique_ptr<int>>&>) 
                                                                            : a{ CPP2_FORWARD(a_) }{}

auto issue_857_5::operator=(auto&& a_) -> issue_857_5& 
requires (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<std::unique_ptr<int>>&>) {
                                                                            a = CPP2_FORWARD(a_);
                                                                            return *this;}
#line 339 "pure2-last-use.cpp2"
  [[nodiscard]] auto issue_857_7::F() && -> decltype(auto) { return f_inout(cpp2::move(*this).A);  }

  issue_857_7::issue_857_7(auto&& A_)
requires (std::is_convertible_v<CPP2_TYPEOF(A_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) 
                                                                                        : issue_857_7_A_as_base{ CPP2_FORWARD(A_) }
                                                                                        , std::monostate{  }{}

#line 346 "pure2-last-use.cpp2"
  auto issue_857_8::d() && -> void{}

  issue_857_8::issue_857_8(auto&& a_, auto&& b_, auto&& c_)
requires (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<std::unique_ptr<int>>&> && std::is_convertible_v<CPP2_TYPEOF(b_), std::add_const_t<std::move_only_function<int()>>&> && std::is_convertible_v<CPP2_TYPEOF(c_), std::add_const_t<std::add_lvalue_reference_t<int>>&>) 
                                                                                                                                                                                 : a{ CPP2_FORWARD(a_) }
                                                                                                                                                                                 , b{ CPP2_FORWARD(b_) }
                                                                                                                                                                                 , c{ CPP2_FORWARD(c_) }{}

#line 355 "pure2-last-use.cpp2"
  [[nodiscard]] auto issue_857_9::f2() && -> decltype(auto) { return f_inout(c);  }// OK: Happens to work, like non-'move' 'this' parameters.

#line 361 "pure2-last-use.cpp2"
  [[nodiscard]] auto issue_857_9::g2() && -> decltype(auto) { return f_inout(cpp2::move((*this)).c);  }

#line 366 "pure2-last-use.cpp2"
  issue_869_0::issue_869_0([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2){}
#line 366 "pure2-last-use.cpp2"
  auto issue_869_0::operator=([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2) -> issue_869_0& {
                                                          return *this; }


  issue_869_0::issue_869_0([[maybe_unused]] issue_869_0 const& that){}

auto issue_869_0::operator=([[maybe_unused]] issue_869_0 const& that) -> issue_869_0& {
                                return *this;}
issue_869_0::issue_869_0([[maybe_unused]] issue_869_0&& that) noexcept{}
auto issue_869_0::operator=([[maybe_unused]] issue_869_0&& that) noexcept -> issue_869_0& {
                                return *this;}
issue_869_0::issue_869_0(){}
[[nodiscard]] auto issue_869_1::is_i() const& -> bool { return _discriminator == 0; }
[[nodiscard]] auto issue_869_1::i() const& -> issue_869_0 const& { 
                                                   if (cpp2::cpp2_default.is_active() && !(is_i()) ) { cpp2::cpp2_default.report_violation(""); }return *cpp2::impl::assert_not_null(reinterpret_cast<issue_869_0 const*>(&_storage)); }
[[nodiscard]] auto issue_869_1::i() & -> issue_869_0& { 
                                                         if (cpp2::cpp2_default.is_active() && !(is_i()) ) { cpp2::cpp2_default.report_violation(""); }return *cpp2::impl::assert_not_null(reinterpret_cast<issue_869_0*>(&_storage)); }
auto issue_869_1::set_i(cpp2::impl::in<issue_869_0> _value) & -> void{if (!(is_i())) {_destroy();std::construct_at(reinterpret_cast<issue_869_0*>(&_storage), _value);}else {*cpp2::impl::assert_not_null(reinterpret_cast<issue_869_0*>(&_storage)) = _value;}_discriminator = 0;}
auto issue_869_1::set_i(auto&& ..._args) & -> void{if (!(is_i())) {_destroy();std::construct_at(reinterpret_cast<issue_869_0*>(&_storage), CPP2_FORWARD(_args)...);}else {*cpp2::impl::assert_not_null(reinterpret_cast<issue_869_0*>(&_storage)) = issue_869_0{CPP2_FORWARD(_args)...};}_discriminator = 0;}
auto issue_869_1::_destroy() & -> void{
  if (_discriminator == 0) {std::destroy_at(reinterpret_cast<issue_869_0*>(&_storage));}
  _discriminator = -1;
  }

  issue_869_1::~issue_869_1() noexcept{_destroy();static_cast<void>(cpp2::move((*this)));}
issue_869_1::issue_869_1(){}
issue_869_1::issue_869_1(issue_869_1 const& that)
        : _storage{  }
        , _discriminator{ -1 }{
  if (CPP2_UFCS(is_i)(that)) {set_i(CPP2_UFCS(i)(that));}
  }

  issue_869_1::issue_869_1(issue_869_1&& that) noexcept
        : _storage{  }
        , _discriminator{ -1 }{
  if (CPP2_UFCS(is_i)(cpp2::move(that))) {set_i(CPP2_UFCS(i)(cpp2::move(that)));}
  }

  auto issue_869_1::operator=(issue_869_1 const& that) -> issue_869_1& {
  if (CPP2_UFCS(is_i)(that)) {set_i(CPP2_UFCS(i)(that));}
        return *this;
  }

  auto issue_869_1::operator=(issue_869_1&& that) noexcept -> issue_869_1& {
  if (CPP2_UFCS(is_i)(cpp2::move(that))) {set_i(CPP2_UFCS(i)(cpp2::move(that)));}
        return *this;
  }
#line 371 "pure2-last-use.cpp2"
[[nodiscard]] auto issue_869_2() -> issue_869_2_ret{
                                               issue_869_1 res {}; CPP2_UFCS(set_i)(res, cpp2_new<int>(0));
#line 372 "pure2-last-use.cpp2"
return res; }
#line 373 "pure2-last-use.cpp2"
auto issue_884() -> void{
  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {}
    {
      {f_inout(x); }
      f_copy(std::move(cpp2::move(x)));
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      f_copy(std::move(cpp2::move(x)));
    }
    else {
      {f_inout(x); }
      f_copy(std::move(cpp2::move(x)));
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      f_inout(x);
    }
    else {
      {f_inout(x); }
      f_inout(x);
    }
    f_copy(std::move(cpp2::move(x)));
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(cpp2::move(x)));
    if (true) {
      static_cast<void>(0);
    }
    else {
      {static_cast<void>(0); }
      static_cast<void>(0);
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      f_copy(std::move(cpp2::move(x)));
    }
    else {
      {static_cast<void>(0); }
      static_cast<void>(0);
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      static_cast<void>(0);
    }
    else {
      {f_copy(std::move(cpp2::move(x))); }
      static_cast<void>(0);
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      static_cast<void>(0);
    }
    else {
      {static_cast<void>(0); }
      f_copy(std::move(cpp2::move(x)));
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      static_cast<void>(0);
    }
    else {
      {static_cast<void>(0); }
      static_cast<void>(0);
    }
    f_copy(std::move(cpp2::move(x)));
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      f_copy(std::move(cpp2::move(x)));
    }
    else {
      {f_copy(std::move(cpp2::move(x))); }
      static_cast<void>(0);
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      f_copy(std::move(cpp2::move(x)));
    }
    else {
      {f_inout(x); }
      f_copy(std::move(cpp2::move(x)));
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      f_inout(x);
    }
    else {
      {f_inout(x); }
      f_inout(x);
    }
    f_inout(x);
    if (true) {
      f_copy(std::move(cpp2::move(x)));
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      f_inout(x);
    }
    else {
      {f_inout(x); }
      f_inout(x);
    }
    if (true) {
      f_inout(x);
    }
    f_copy(std::move(cpp2::move(x)));
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      f_copy(std::move(cpp2::move(x)));
    }
    else {
      {f_inout(x); }
      f_inout(x);
      if (true) {
        f_copy(std::move(cpp2::move(x)));
      }
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      if (true) {
        if (true) {
          f_copy(std::move(cpp2::move(x)));
        }
      }
    }
    else {
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      if (true) {
        if (true) {
          f_copy(std::move(cpp2::move(x)));
        }
      }
    }
    else {
      f_copy(std::move(cpp2::move(x)));
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
    }
    else {
      if (true) {
        if (true) {
          f_copy(std::move(cpp2::move(x)));
        }
      }
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      f_copy(std::move(cpp2::move(x)));
    }
    else {
      if (true) {
        if (true) {
          f_copy(std::move(cpp2::move(x)));
        }
      }
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      auto y {cpp2_new<int>(0)}; 
      f_copy(std::move(cpp2::move(x)));
      f_copy(std::move(cpp2::move(y)));
    }
    else {
      if (true) {
        if (true) {
          f_inout(x);
        }
        f_copy(std::move(cpp2::move(x)));
      }
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      auto y {cpp2_new<int>(0)}; 
      if (true) {}
      else {
        f_copy(std::move(cpp2::move(x)));
        f_copy(std::move(cpp2::move(y)));
      }
    }
    else {
      if (true) {
        if (true) {
          auto y {cpp2_new<int>(0)}; 
          f_copy(std::move(cpp2::move(y)));
          f_inout(x);
        }
        f_copy(std::move(cpp2::move(x)));
      }
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      auto y {cpp2_new<int>(0)}; 
      if (true) {}
      else {
        f_copy(std::move(cpp2::move(x)));
        f_copy(std::move(cpp2::move(y)));
      }
    }
    else {
      auto y {cpp2_new<int>(0)}; 
      if (true) {
        if (true) {
          f_copy(std::move(cpp2::move(x)));
        }
        else {
          f_copy(std::move(cpp2::move(x)));
        }
        f_copy(std::move(cpp2::move(y)));
      }
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      f_copy(std::move(cpp2::move(x)));
    }
    else {
      if (true) {
        auto x {cpp2_new<int>(0)}; 
        if (true) {
          f_inout(x);
        }
        else {
        }
        f_copy(std::move(cpp2::move(x)));
      }
      f_copy(std::move(cpp2::move(x)));
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      if (true) {
        auto x {cpp2_new<int>(0)}; 
        if (true) {
          f_inout(x);
        }
        else {
        }
        f_copy(std::move(cpp2::move(x)));
      }
      f_copy(std::move(cpp2::move(x)));
    }
    else {
      f_copy(std::move(cpp2::move(x)));
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 

    if (true) {
      f_inout(x);
    }

    if (true) {
      if (true) {
        f_copy(std::move(cpp2::move(x)));
      }
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      if (true) {
        f_inout(x);
        if (true) {
        }
        else {
          f_copy(std::move(cpp2::move(x)));
        }
      }
      else {
        if (true) {
        }
        else {
          f_inout(x);
        }
        f_copy(std::move(cpp2::move(x)));
      }
    }
    else {
      if (true) {
        if (true) {
          f_inout(x);
          f_copy(std::move(cpp2::move(x)));
        }
        else {
        }
      }
      else {
        if (true) {
        }
        else {
          f_inout(x);
        }
        if (true) {
          f_inout(x);
          if (true) {
            f_copy(std::move(cpp2::move(x)));
          }
          else {
          }
        }
        else {
          if (true) {
            f_copy(std::move(cpp2::move(x)));
          }
          else {
            f_copy(std::move(cpp2::move(x)));
          }
        }
      }
    }
  });
}

#line 770 "pure2-last-use.cpp2"
auto issue_888_0(std::string r, int size) -> void{
  static_cast<void>(CPP2_UFCS_MOVE(size)(cpp2::move(r)));
}
#line 773 "pure2-last-use.cpp2"
auto issue_888_1([[maybe_unused]] std::string unnamed_param_1, std::move_only_function<int([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1)> size) -> void{
  static_cast<void>(CPP2_UFCS_MOVE(size)(0));
}

#line 777 "pure2-last-use.cpp2"
auto issue_890() -> void{
  auto x {cpp2_new<int>(0)}; 
{
auto const& x{cpp2_new<int>(0)};
//   assert(identity_copy(x)* == 0);
#line 780 "pure2-last-use.cpp2"
  if (cpp2::cpp2_default.is_active() && !(*cpp2::impl::assert_not_null(identity(x)) == 0) ) { cpp2::cpp2_default.report_violation(""); }
}
#line 781 "pure2-last-use.cpp2"
}

#line 783 "pure2-last-use.cpp2"
auto issue_962(cpp2::impl::in<::std::string> s) -> void{
  using ::std::string;
  std::cout << "A: " + cpp2::to_string(s) + "" << std::endl;
}

#line 788 "pure2-last-use.cpp2"
auto draw() -> void{
  auto pos {0}; 
  std::move_only_function<int([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1)> vertex {}; 
  static_cast<void>(CPP2_UFCS_MOVE(vertex)((cpp2::move(pos))));
}

#line 794 "pure2-last-use.cpp2"
auto enum_0() -> void{
    cpp2::impl::deferred_init<std::string> underlying_type; 
    if (true) {}
    underlying_type.construct("");
}
#line 799 "pure2-last-use.cpp2"
auto enum_1() -> void{
    auto max_value {cpp2_new<int>(0)}; 
    std::reference_wrapper<std::unique_ptr<int> const> min_value {max_value}; 
    static_cast<void>(cpp2::move(max_value));

    // for  (0)
    // do   (copy x)
    // {
    //     v := new<int>(identity_copy(x));
    //     if pred(v, min_value) {
    //         min_value = std::ref(identity(v)); // Not using 'else' will never move 'v'.
    //     }
    //     if pred(v, max_value) {
    //         max_value = identity_copy(v);
    //     }
    // }

    auto y {cpp2_new<bool>(false)}; 
    while( *cpp2::impl::assert_not_null(identity(y)) ) {
        auto v {cpp2_new<int>(0)}; 
        f_copy(std::move(cpp2::move(v)));
    }

    auto z {cpp2_new<bool>(false)}; 
    do {
        auto v {cpp2_new<int>(0)}; 
        f_copy(std::move(cpp2::move(v)));
    } while ( *cpp2::impl::assert_not_null(identity(z)));
}
#line 828 "pure2-last-use.cpp2"
auto enum_2() -> void{
    auto umax {cpp2_new<int>(0)}; 
    if (pred(umax)) {
    }
    else {if (pred(umax)) {
    }
    else {if (pred_copy(std::move(cpp2::move(umax)))) {
    }}}
}

#line 839 "pure2-last-use.cpp2"
  auto cpp2_union::destroy() & -> void{}
#line 840 "pure2-last-use.cpp2"
  cpp2_union::~cpp2_union() noexcept{
    destroy();
    static_cast<void>(cpp2::move((*this)));
  }

  my_string::my_string(auto&& string_, auto&& size_)
requires (std::is_convertible_v<CPP2_TYPEOF(string_), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(size_), std::add_const_t<std::size_t>&>) 
                                                                                                     : string{ CPP2_FORWARD(string_) }
                                                                                                     , size{ CPP2_FORWARD(size_) }{}

#line 851 "pure2-last-use.cpp2"
[[nodiscard]] auto no_pessimizing_move() -> no_pessimizing_move_ret{
                                                                std::unique_ptr<int> ret {};
#line 852 "pure2-last-use.cpp2"
return ret; }
#line 853 "pure2-last-use.cpp2"
auto deferred_non_copyable_0() -> void{
  cpp2::impl::deferred_init<std::unique_ptr<int>> p; 
  p.construct();
  f_copy(std::move(cpp2::move(p.value())));
}

#line 859 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_1() -> auto{
  cpp2::impl::deferred_init<std::unique_ptr<int>> p; 
  p.construct();
  return std::move(cpp2::move(p.value())); 
}

#line 865 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_2() -> deferred_non_copyable_2_ret{
      cpp2::impl::deferred_init<std::unique_ptr<int>> p;
#line 866 "pure2-last-use.cpp2"
  p.construct();
return std::move(p.value()); }

#line 869 "pure2-last-use.cpp2"
auto loops() -> void{
  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { 0 } ) 
    f_inout(x);
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    for ( 

    [[maybe_unused]] auto const& unnamed_param_1 : { 0 } )  { do 
    {} while (false); f_inout(x); }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { 0 } ) 
    if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(get)(x)) ) { cpp2::cpp2_default.report_violation(""); }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      f_copy(std::move(cpp2::move(x)));
    }
    else {
      while( true ) {
        f_inout(x);
      }
    }
  });
}

namespace captures {

#line 909 "pure2-last-use.cpp2"
auto f() -> void{
  auto x {cpp2_new<int>(0)}; 
  f_copy(std::move(cpp2::move(x)));
  auto id {[](auto&& x) -> decltype(auto) { return CPP2_FORWARD(x);  }}; 
  auto y {cpp2_new<int>(0)}; 
  if (cpp2::cpp2_default.is_active() && !(&cpp2::move(id)(y) == &y) ) { cpp2::cpp2_default.report_violation(""); }
}

#line 921 "pure2-last-use.cpp2"
  auto t::operator()() && -> void{
    f_copy(std::move(cpp2::move(*this).x));
    static_cast<void>([&]() -> void{
      // Should this move?
      // I.e., don't skip non-captured names, just rely on skipping hiding names.
      // An odr-use still requires capturing at Cpp1-time, and capturing would move.
      static_assert(std::is_same_v<decltype(x),std::unique_ptr<int>>);
      using captures::x;
      static_cast<void>(identity(x));
    });
  }

  t::t(auto&& x_)
requires (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<std::unique_ptr<int>>&>) 
                                                                            : x{ CPP2_FORWARD(x_) }{}

auto t::operator=(auto&& x_) -> t& 
requires (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<std::unique_ptr<int>>&>) {
                                                                            x = CPP2_FORWARD(x_);
                                                                            return *this;}
#line 934 "pure2-last-use.cpp2"
auto g() -> void{
  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(cpp2::move(x)));
    static_cast<void>([_0 = std::array<int,[](auto const& x) -> decltype(auto) { return identity(x); }(0)>()]() mutable -> decltype(auto) { return _0;  });// Fails on Clang 12 (lambda in unevaluated context).
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    static_cast<void>([_0 = ([_0 = cpp2::move(x)]() mutable -> decltype(auto) { return *cpp2::impl::assert_not_null(_0); })]() mutable -> int { return _0();  });
  });
}

}

#line 950 "pure2-last-use.cpp2"
auto loops_and_captures() -> void{
  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(cpp2::move(x)));
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { [](auto const& x) -> auto { return x; } } ) 
    {}
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(cpp2::move(x)));
    for ( 

#line 966 "pure2-last-use.cpp2"
    [[maybe_unused]] auto const& unnamed_param_1 : { []() -> auto{using captures::x;return x; } } ) 
    {}
  });

//   _ = :() = {
//     x := new<int>(0);
//     for (:() x$*)
//     do (_)
//     { }
//   };
}

types::types(auto&& x_)
requires (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<std::unique_ptr<int>>&>) 
                                                                            : x{ CPP2_FORWARD(x_) }{}

auto types::operator=(auto&& x_) -> types& 
requires (std::is_convertible_v<CPP2_TYPEOF(x_), std::add_const_t<std::unique_ptr<int>>&>) {
                                                                            x = CPP2_FORWARD(x_);
                                                                            return *this;}
#line 988 "pure2-last-use.cpp2"
auto skip_hidden_names() -> void{
  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(cpp2::move(x)));
{
auto x{cpp2_new<int>(0)};

#line 993 "pure2-last-use.cpp2"
      f_copy(std::move(cpp2::move(x)));
}
#line 994 "pure2-last-use.cpp2"
  });

//   _ = :() = {
//     x := new<int>(0);
//     _ = :() = {
//       _ = x$;
//       x := new<int>(1);
//       _ = :() = {
//         _ = x$;
//       };
//     };
//   };

  static_cast<void>([]() -> void{
{
auto x{cpp2_new<int>(0)};
    // x := new<int>(0);
    // f_copy(x);
    // for (0)
    // do (copy x)
    // _ = identity_copy(x);

#line 1014 "pure2-last-use.cpp2"
      f_copy(std::move(cpp2::move(x)));
}
#line 1015 "pure2-last-use.cpp2"
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    {
      f_copy(std::move(cpp2::move(x)));
      using captures::x;
      f_inout(x);
    }
  });

  static_cast<void>([]() -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(cpp2::move(x)));
    static_cast<void>([]() -> void{
      static_assert(std::is_same_v<decltype(x),std::unique_ptr<int>>);
      using captures::x;
      f_inout(x);
    });
  });
}

#line 1038 "pure2-last-use.cpp2"
auto main(int const argc_, char** argv_) -> int{
  auto const args = cpp2::make_args(argc_, argv_); 
#line 1039 "pure2-last-use.cpp2"
  issue_683(args);
  issue_847_2(std::vector<std::unique_ptr<int>>());
  issue_847_5(args);
  issue_850();
  enum_0();
}

