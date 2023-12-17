
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use.cpp2"

#line 67 "pure2-last-use.cpp2"
class issue_857;
  

#line 154 "pure2-last-use.cpp2"
class issue_857_2;
  

#line 159 "pure2-last-use.cpp2"
class issue_857_3;
  

#line 163 "pure2-last-use.cpp2"
class issue_857_6;
  

#line 169 "pure2-last-use.cpp2"
template<typename T> class move_only_function;
  

#line 175 "pure2-last-use.cpp2"
class issue_857_4;
   

#line 233 "pure2-last-use.cpp2"
class issue_857_5;
  

#line 238 "pure2-last-use.cpp2"
class issue_857_7;
  

#line 244 "pure2-last-use.cpp2"
class issue_857_8;
  

#line 249 "pure2-last-use.cpp2"
class issue_857_9;
  

#line 256 "pure2-last-use.cpp2"
class issue_869_0;
  

class issue_869_1;
  

#line 440 "pure2-last-use.cpp2"
class cpp2_union;
  

#line 448 "pure2-last-use.cpp2"
class my_string;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use.cpp2"
[[nodiscard]] auto f_inout(int& x) -> auto;

#line 6 "pure2-last-use.cpp2"
auto issue_350() -> void;

#line 17 "pure2-last-use.cpp2"
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

#line 45 "pure2-last-use.cpp2"
auto issue_825() -> void;

#line 51 "pure2-last-use.cpp2"
auto issue_832() -> void;

#line 56 "pure2-last-use.cpp2"
[[nodiscard]] auto make_copy(auto x) -> auto;

auto issue_847_0(std::vector<std::unique_ptr<int>> v) -> void;
auto issue_847_1(std::vector<std::unique_ptr<int>>&& v) -> void;
auto issue_847_2(auto&& v) -> void;
auto issue_847_3(int x) -> void;

auto f_inout([[maybe_unused]] std::unique_ptr<int>& unnamed_param_1) -> void;
auto f_inout([[maybe_unused]] auto& unnamed_param_1) -> void;
auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void;

class issue_857 {
  private: std::unique_ptr<int> a; 
  private: std::unique_ptr<int> b; 
  public: issue_857(issue_857&& that) noexcept;
#line 70 "pure2-last-use.cpp2"
  public: auto operator=(issue_857&& that) noexcept -> issue_857& ;
  public: ~issue_857() noexcept;

#line 75 "pure2-last-use.cpp2"
  public: auto f() && -> void;
  public: auto f(issue_857&& that) && -> void;
  public: auto g() && -> void;
  public: auto g(issue_857&& that) && -> void;
  public: auto h() & -> void;
  public: auto i() && -> void;
  public: auto j() && -> void;
  public: auto k() && -> void;

#line 86 "pure2-last-use.cpp2"
  public: auto l() && -> void;
  public: auto m() && -> void;
  public: static auto n([[maybe_unused]] auto const& unnamed_param_1) -> void;
  public: auto n() && -> void;
  public: auto o0() && -> void;
  public: auto o1() && -> void;
  public: auto o2() && -> void;
  public: auto o3() && -> void;
  public: auto o4() && -> void;
  public: auto p0() && -> void;

#line 99 "pure2-last-use.cpp2"
  public: auto p1() && -> void;

#line 103 "pure2-last-use.cpp2"
  public: auto p2() && -> void;

#line 107 "pure2-last-use.cpp2"
  public: auto p3() && -> void;

#line 111 "pure2-last-use.cpp2"
  public: auto q() && -> void;

#line 115 "pure2-last-use.cpp2"
// FIXME Lack of implicit moves in sibling selections.
// Not a `this` problem: <https://cpp2.godbolt.org/z/hbeje4c3M>.
//z: (move this, move that) = {
///*f */      if true { f_copy(this); }
///*f */ else if true { f_copy(this, that); }
///*g */ else if true { f_copy(this.a); }
///*g */ else if true { f_copy(this.a, that.a); }
///*i */ else if true { f_copy(a); }
///*j */ else if true { f_copy(a); }
///*k */ else if true { f_copy(a, b); }
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
  public: std::unique_ptr<int> a; // OK: No error about 'a' being unused.
};

extern int gi;
class issue_857_3 {
  public: std::add_lvalue_reference_t<int> i {gi}; 
  public: auto f() && -> void;
};
class issue_857_6 {
  public: auto f() && -> void;
  public: std::add_lvalue_reference_t<int> i {gi}; 
};

// TODO Alias `std::move_only_function`.
template<typename T> class move_only_function {
  public: explicit move_only_function();
  public: move_only_function([[maybe_unused]] move_only_function&& that) noexcept;
#line 171 "pure2-last-use.cpp2"
  public: auto operator=([[maybe_unused]] move_only_function&& that) noexcept -> move_only_function& ;
  public: [[nodiscard]] auto operator()([[maybe_unused]] auto const& ...unnamed_param_2) && -> int;
};

class issue_857_4 {
   public: std::add_pointer_t<int()> f; 
   public: std::add_pointer_t<int(int)> g; 
  public: move_only_function<int()> mf; 
  public: move_only_function<int(int)> mg; 
  public: auto h0() && -> void;
  public: auto h1() && -> void;
  public: auto h2(issue_857_4 const& that) && -> void;
  public: auto h3(issue_857_4 const& that) && -> void;
  public: auto h4(cpp2::in<int> x) && -> void;
  public: auto h5(cpp2::in<int> x) && -> void;
  public: auto h6(cpp2::in<int> x) && -> void;
  public: auto h7(cpp2::in<int> x) && -> void;
  public: auto h8(cpp2::in<int> x) && -> void;
  public: auto i0(cpp2::in<int> x) && -> void;

#line 193 "pure2-last-use.cpp2"
  public: auto i1(cpp2::in<int> x) && -> void;

#line 197 "pure2-last-use.cpp2"
  public: auto i2(cpp2::in<int> x) && -> void;

#line 201 "pure2-last-use.cpp2"
  public: auto i3(cpp2::in<int> x) && -> void;

#line 205 "pure2-last-use.cpp2"
//z: (move this, that, x: int) = {
///*h0*/      if true { mf(); }
///*h1*/ else if true { this.mf(); }
///*h2*/ else if true { that.mf(); }
///*h3*/ else if true { that.f; }
///*h4*/ else if true { x.mg(); }
///*h5*/ else if true { f() + x.g(); }
///*h6*/ else if true { x.g() + f(); }
///*h7*/ else if true { this.f() + x.g(); }
///*h8*/ else if true { x.g() + this.f(); }
///*i0*/ else if true {
///*i0*/   _ = f();
///*i0*/   _ = x.mg();
///*i0*/ }
///*i1*/ else if true {
///*i1*/   _ = x.g();
///*i1*/   _ = mf();
///*i1*/ }
///*i2*/ else if true {
///*i2*/   _ = this.f();
///*i2*/   _ = x.mg();
///*i2*/ }
///*i3*/ else {
///*i3*/   _ = x.g();
///*i3*/   _ = this.mf();
///*i3*/ }
};

class issue_857_5 {
  public: auto f() && -> void;
  public: std::unique_ptr<int> a; 
};

struct issue_857_7_A_as_base { std::add_lvalue_reference_t<int> A; };
#line 238 "pure2-last-use.cpp2"
class issue_857_7: public issue_857_7_A_as_base, public std::monostate {

#line 241 "pure2-last-use.cpp2"
  public: auto F() && -> void;
};

class issue_857_8 {
  public: std::unique_ptr<int> a; 
  public: move_only_function<int()> b; 
  public: std::add_lvalue_reference_t<int> c; 
};
class issue_857_9: public issue_857_8 {

//f: (move this) = f_copy(a); // Error: Cppfront limitation:
//g: (move this) = b();       // <https://eel.is/c++draft/class.mfct.non.static#2.sentence-1>.
  public: auto h() && -> void;
};

class issue_869_0 {
  public: explicit issue_869_0([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2);
#line 257 "pure2-last-use.cpp2"
  public: auto operator=([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2) -> issue_869_0& ;
  public: [[nodiscard]] auto operator<=>([[maybe_unused]] issue_869_0 const& that) const& -> std::strong_ordering = default;
public: issue_869_0([[maybe_unused]] issue_869_0 const& that);

public: auto operator=([[maybe_unused]] issue_869_0 const& that) -> issue_869_0& ;
public: issue_869_0([[maybe_unused]] issue_869_0&& that) noexcept;
public: auto operator=([[maybe_unused]] issue_869_0&& that) noexcept -> issue_869_0& ;
public: explicit issue_869_0();

#line 258 "pure2-last-use.cpp2"
};
class issue_869_1 {
private: std::aligned_storage_t<cpp2::max(sizeof(issue_869_0))> _storage {}; private: cpp2::i8 _discriminator {-1}; public: [[nodiscard]] auto is_i() const& -> bool;
public: [[nodiscard]] auto i() const& -> issue_869_0 const&;
public: [[nodiscard]] auto i() & -> issue_869_0&;
public: auto set_i(cpp2::in<issue_869_0> _value) & -> void;
public: auto set_i(auto&& ..._args) & -> void;
private: auto _destroy() & -> void;
public: ~issue_869_1() noexcept;
public: explicit issue_869_1();
public: issue_869_1(issue_869_1 const& that);

public: issue_869_1(issue_869_1&& that) noexcept;
public: auto operator=(issue_869_1 const& that) -> issue_869_1& ;
public: auto operator=(issue_869_1&& that) noexcept -> issue_869_1& ;

#line 261 "pure2-last-use.cpp2"
};

using issue_869_2_ret = issue_869_1;
[[nodiscard]] auto issue_869_2() -> issue_869_2_ret;

#line 264 "pure2-last-use.cpp2"
auto issue_884() -> void;

#line 421 "pure2-last-use.cpp2"
auto issue_888_0(std::string r, int size) -> void;

#line 424 "pure2-last-use.cpp2"
auto issue_888_1([[maybe_unused]] std::string unnamed_param_1, move_only_function<int(int)> size) -> void;

#line 428 "pure2-last-use.cpp2"
auto draw() -> void;

#line 434 "pure2-last-use.cpp2"
auto cpp2_enum() -> void;

#line 440 "pure2-last-use.cpp2"
class cpp2_union {
  public: auto destroy() & -> void;
  public: ~cpp2_union() noexcept;
  public: cpp2_union() = default;
  public: cpp2_union(cpp2_union const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(cpp2_union const&) -> void = delete;


#line 446 "pure2-last-use.cpp2"
};

class my_string {
  public: std::string string; 
  public: std::size_t size {CPP2_UFCS(size)(string)}; 
};

using no_pessimizing_move_ret = std::unique_ptr<int>;
#line 453 "pure2-last-use.cpp2"
[[nodiscard]] auto no_pessimizing_move() -> no_pessimizing_move_ret;

auto deferred_non_copyable_0() -> void;

#line 461 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_1() -> auto;
using deferred_non_copyable_2_ret = std::unique_ptr<int>;


#line 467 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_2() -> deferred_non_copyable_2_ret;

#line 471 "pure2-last-use.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-last-use.cpp2"
[[nodiscard]] auto f_inout(int& x) -> auto{
#line 2 "pure2-last-use.cpp2"
    x *= 2;
    return x; 
}

auto issue_350() -> void{
    auto x {21}; 

    auto l1 {[](auto&& x) mutable -> void{
        std::cout << f_inout(CPP2_FORWARD(x)) << std::endl;
    }}; 

    std::move(l1)(x);

    ++x;
}

#line 36 "pure2-last-use.cpp2"
auto issue_683(auto const& args) -> void{
    for ( auto const& n : args ) {
        static_cast<void>(n);
    }

    cpp2::deferred_init<int> n; 
    n.construct(0);
}

auto issue_825() -> void{
  static_cast<void>([](auto b) mutable -> auto { return static_cast<void>(std::move(b));  });
  static_cast<void>([](auto&& c) mutable -> auto { return static_cast<void>(std::move(c));  });
  static_cast<void>([](auto&& d) mutable -> auto { return static_cast<void>(CPP2_FORWARD(d));  });
}

auto issue_832() -> void{
  auto i {0}; 
  while( i ) {}
}

[[nodiscard]] auto make_copy(auto x) -> auto { return std::move(x);  }

auto issue_847_0(std::vector<std::unique_ptr<int>> v) -> void{for ( [[maybe_unused]] auto const& unnamed_param_1 : CPP2_UFCS(make_copy)(std::move(v)) ) {}}
auto issue_847_1(std::vector<std::unique_ptr<int>>&& v) -> void{for ( [[maybe_unused]] auto const& unnamed_param_1 : CPP2_UFCS(make_copy)(std::move(v)) ) {}}
auto issue_847_2(auto&& v) -> void{for ( [[maybe_unused]] auto const& unnamed_param_1 : CPP2_UFCS(make_copy)(CPP2_FORWARD(v)) ) {}}
auto issue_847_3(int x) -> void{for ( [[maybe_unused]] auto const& unnamed_param_1 : { std::move(x) } ) {}}

auto f_inout([[maybe_unused]] std::unique_ptr<int>& unnamed_param_1) -> void{}
auto f_inout([[maybe_unused]] auto& unnamed_param_1) -> void{}
auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void{}

#line 70 "pure2-last-use.cpp2"
  issue_857::issue_857(issue_857&& that) noexcept
                                       : a{ std::move(that).a }
                                       , b{ std::move(that).b }{}
#line 70 "pure2-last-use.cpp2"
  auto issue_857::operator=(issue_857&& that) noexcept -> issue_857& {
                                       a = std::move(that).a;
                                       b = std::move(that).b;
                                       return *this; }
#line 71 "pure2-last-use.cpp2"
  issue_857::~issue_857() noexcept{
    f_inout(a);
    f_copy(std::move((*this)).b);
  }
  auto issue_857::f() && -> void { f_copy(std::move((*this)));  }
  auto issue_857::f(issue_857&& that) && -> void { f_copy(std::move((*this)), std::move(that));  }
  auto issue_857::g() && -> void { f_copy(std::move((*this)).a);  }
  auto issue_857::g(issue_857&& that) && -> void { f_copy(std::move((*this)).a, std::move(that).a);  }
  auto issue_857::h() & -> void { f_inout(a);  }
  auto issue_857::i() && -> void { f_copy(std::move(*this).a);  }
  auto issue_857::j() && -> void { f_copy(std::move(*this).a);  }
  auto issue_857::k() && -> void{
    f_inout(a);
    f_copy(std::move(*this).b);
  }
  auto issue_857::l() && -> void { std::move(*this).k();  }
  auto issue_857::m() && -> void { CPP2_UFCS(k)(std::move((*this)));  }
  auto issue_857::n([[maybe_unused]] auto const& unnamed_param_1) -> void{}
  auto issue_857::n() && -> void{}
  auto issue_857::o0() && -> void { std::move(*this).n();  }
  auto issue_857::o1() && -> void { CPP2_UFCS(n)(std::move((*this)));  }
  auto issue_857::o2() && -> void { CPP2_UFCS(n)(0);  }
  auto issue_857::o3() && -> void { std::move(*this).n(0);  }
  auto issue_857::o4() && -> void { n(std::move((*this)));  }
  auto issue_857::p0() && -> void{
    f_inout(a);
    f_copy(std::move((*this)).a);
  }
  auto issue_857::p1() && -> void{
    f_inout((*this).a);
    f_copy(std::move(*this).a);
  }
  auto issue_857::p2() && -> void{
    f_inout(a);
    f_copy(std::move((*this)));
  }
  auto issue_857::p3() && -> void{
    f_inout((*this));
    f_copy(std::move(*this).a);
  }
  auto issue_857::q() && -> void{
    h();
    std::move(*this).n();
  }

#line 158 "pure2-last-use.cpp2"
int gi {0}; 

#line 161 "pure2-last-use.cpp2"
  auto issue_857_3::f() && -> void { static_cast<void>(f_inout(std::move(*this).i));  }// OK: The implicit `this` is moved, not `i`.

#line 164 "pure2-last-use.cpp2"
  auto issue_857_6::f() && -> void { static_cast<void>(f_inout(std::move(*this).i));  }// OK: The implicit `this` is moved, not `i`.

#line 170 "pure2-last-use.cpp2"
  template <typename T> move_only_function<T>::move_only_function(){}
  template <typename T> move_only_function<T>::move_only_function([[maybe_unused]] move_only_function&& that) noexcept{}
#line 171 "pure2-last-use.cpp2"
  template <typename T> auto move_only_function<T>::operator=([[maybe_unused]] move_only_function&& that) noexcept -> move_only_function& {
                                       return *this; }
#line 172 "pure2-last-use.cpp2"
  template <typename T> [[nodiscard]] auto move_only_function<T>::operator()([[maybe_unused]] auto const& ...unnamed_param_2) && -> int { return 0;  }

#line 180 "pure2-last-use.cpp2"
  auto issue_857_4::h0() && -> void { static_cast<void>(std::move(*this).mf());  }
  auto issue_857_4::h1() && -> void { static_cast<void>(CPP2_UFCS(mf)(std::move((*this))));  }
  auto issue_857_4::h2(issue_857_4 const& that) && -> void { static_cast<void>(CPP2_UFCS_MOVE(mf)(that));  }
  auto issue_857_4::h3(issue_857_4 const& that) && -> void { static_cast<void>(that.f);  }
  auto issue_857_4::h4(cpp2::in<int> x) && -> void { static_cast<void>(CPP2_UFCS_MOVE(mg)(x));  }
  auto issue_857_4::h5(cpp2::in<int> x) && -> void { static_cast<void>(f() + CPP2_UFCS_MOVE(g)(x));  }// FIXME #313.
  auto issue_857_4::h6(cpp2::in<int> x) && -> void { static_cast<void>(CPP2_UFCS(g)(x) + std::move(*this).f());  }// FIXME #313.
  auto issue_857_4::h7(cpp2::in<int> x) && -> void { static_cast<void>(CPP2_UFCS(f)((*this)) + CPP2_UFCS_MOVE(g)(x));  }// FIXME #313.
  auto issue_857_4::h8(cpp2::in<int> x) && -> void { static_cast<void>(CPP2_UFCS(g)(x) + CPP2_UFCS(f)(std::move((*this))));  }// FIXME #313.
  auto issue_857_4::i0(cpp2::in<int> x) && -> void{
    static_cast<void>(f());
    static_cast<void>(CPP2_UFCS_MOVE(mg)(x));
  }
  auto issue_857_4::i1(cpp2::in<int> x) && -> void{
    static_cast<void>(CPP2_UFCS(g)(x));
    static_cast<void>(std::move(*this).mf());
  }
  auto issue_857_4::i2(cpp2::in<int> x) && -> void{
    static_cast<void>(CPP2_UFCS(f)((*this)));
    static_cast<void>(CPP2_UFCS_MOVE(mg)(x));
  }
  auto issue_857_4::i3(cpp2::in<int> x) && -> void{
    static_cast<void>(CPP2_UFCS(g)(x));
    static_cast<void>(CPP2_UFCS(mf)(std::move((*this))));
  }

#line 234 "pure2-last-use.cpp2"
  auto issue_857_5::f() && -> void { f_copy(std::move(*this).a);  }

#line 241 "pure2-last-use.cpp2"
  auto issue_857_7::F() && -> void { static_cast<void>(f_inout(std::move(*this).A));  }

#line 253 "pure2-last-use.cpp2"
  auto issue_857_9::h() && -> void { static_cast<void>(f_inout(c));  }

#line 257 "pure2-last-use.cpp2"
  issue_869_0::issue_869_0([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2){}
#line 257 "pure2-last-use.cpp2"
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
                                                   cpp2::Default.expects(is_i(), "");return *cpp2::assert_not_null(reinterpret_cast<issue_869_0 const*>(&_storage)); }
[[nodiscard]] auto issue_869_1::i() & -> issue_869_0& { 
                                                         cpp2::Default.expects(is_i(), "");return *cpp2::assert_not_null(reinterpret_cast<issue_869_0*>(&_storage)); }
auto issue_869_1::set_i(cpp2::in<issue_869_0> _value) & -> void{if (!(is_i())) {_destroy();std::construct_at(reinterpret_cast<issue_869_0*>(&_storage), _value);}else {*cpp2::assert_not_null(reinterpret_cast<issue_869_0*>(&_storage)) = _value;}_discriminator = 0;}
auto issue_869_1::set_i(auto&& ..._args) & -> void{if (!(is_i())) {_destroy();std::construct_at(reinterpret_cast<issue_869_0*>(&_storage), CPP2_FORWARD(_args)...);}else {*cpp2::assert_not_null(reinterpret_cast<issue_869_0*>(&_storage)) = issue_869_0{CPP2_FORWARD(_args)...};}_discriminator = 0;}
auto issue_869_1::_destroy() & -> void{
  if (_discriminator == 0) {std::destroy_at(reinterpret_cast<issue_869_0*>(&_storage));}
  _discriminator = -1;
  }

  issue_869_1::~issue_869_1() noexcept{_destroy();static_cast<void>(std::move((*this)));}
issue_869_1::issue_869_1(){}
issue_869_1::issue_869_1(issue_869_1 const& that)
        : _storage{  }
        , _discriminator{ -1 }{
  if (CPP2_UFCS(is_i)(that)) {set_i(CPP2_UFCS(i)(that));}
  }

  issue_869_1::issue_869_1(issue_869_1&& that) noexcept
        : _storage{  }
        , _discriminator{ -1 }{
  if (CPP2_UFCS(is_i)(std::move(that))) {set_i(CPP2_UFCS(i)(std::move(that)));}
  }

  auto issue_869_1::operator=(issue_869_1 const& that) -> issue_869_1& {
  if (CPP2_UFCS(is_i)(that)) {set_i(CPP2_UFCS(i)(that));}
        return *this;
  }

  auto issue_869_1::operator=(issue_869_1&& that) noexcept -> issue_869_1& {
  if (CPP2_UFCS(is_i)(std::move(that))) {set_i(CPP2_UFCS(i)(std::move(that)));}
        return *this;
  }
#line 262 "pure2-last-use.cpp2"
[[nodiscard]] auto issue_869_2() -> issue_869_2_ret{
                                               issue_869_1 res {}; CPP2_UFCS(set_i)(res, cpp2_new<int>(0));
#line 263 "pure2-last-use.cpp2"
return res; }
auto issue_884() -> void{
  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {}
    {
      {f_inout(x); }
      f_copy(std::move(x));
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      f_copy(std::move(x));
    }
    else {
      {f_inout(x); }
      f_copy(std::move(x));
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      f_inout(x);
    }
    else {
      {f_inout(x); }
      f_inout(x);
    }
    f_copy(std::move(x));
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(x));
    if (true) {
      static_cast<void>(0);
    }
    else {
      {static_cast<void>(0); }
      static_cast<void>(0);
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      f_copy(std::move(x));
    }
    else {
      {static_cast<void>(0); }
      static_cast<void>(0);
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      static_cast<void>(0);
    }
    else {
      {f_copy(std::move(x)); }
      static_cast<void>(0);
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      static_cast<void>(0);
    }
    else {
      {static_cast<void>(0); }
      f_copy(std::move(x));
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      static_cast<void>(0);
    }
    else {
      {static_cast<void>(0); }
      static_cast<void>(0);
    }
    f_copy(std::move(x));
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      f_copy(std::move(x));
    }
    else {
      {f_copy(std::move(x)); }
      static_cast<void>(0);
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      f_copy(std::move(x));
    }
    else {
      {f_inout(x); }
      f_copy(std::move(x));
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() mutable -> void{
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
      f_copy(std::move(x));
    }
  });

  static_cast<void>([]() mutable -> void{
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
    f_copy(std::move(x));
  });
}

auto issue_888_0(std::string r, int size) -> void{
  static_cast<void>(CPP2_UFCS_MOVE(size)(std::move(r)));
}
auto issue_888_1([[maybe_unused]] std::string unnamed_param_1, move_only_function<int(int)> size) -> void{
  static_cast<void>(CPP2_UFCS_MOVE(size)(0));
}

auto draw() -> void{
  auto pos {0}; 
  move_only_function<int(int)> vertex {}; 
  static_cast<void>(CPP2_UFCS_MOVE(vertex)((std::move(pos))));
}

auto cpp2_enum() -> void{
  cpp2::deferred_init<int> underlying_type; 
  if (true) {}
  underlying_type.construct(0);
}

#line 441 "pure2-last-use.cpp2"
  auto cpp2_union::destroy() & -> void{}
  cpp2_union::~cpp2_union() noexcept{
    destroy();
    static_cast<void>(std::move((*this)));
  }

#line 453 "pure2-last-use.cpp2"
[[nodiscard]] auto no_pessimizing_move() -> no_pessimizing_move_ret{
                                                                std::unique_ptr<int> ret {};
#line 454 "pure2-last-use.cpp2"
return ret; }
auto deferred_non_copyable_0() -> void{
  cpp2::deferred_init<std::unique_ptr<int>> p; 
  p.construct();
  f_copy(std::move(p.value()));
}

[[nodiscard]] auto deferred_non_copyable_1() -> auto{
  cpp2::deferred_init<std::unique_ptr<int>> p; 
  p.construct();
  return std::move(p.value()); 
}

[[nodiscard]] auto deferred_non_copyable_2() -> deferred_non_copyable_2_ret{
      cpp2::deferred_init<std::unique_ptr<int>> p;
#line 468 "pure2-last-use.cpp2"
  p.construct();
return std::move(p.value()); }

auto main(int const argc_, char** argv_) -> int{
  auto const args = cpp2::make_args(argc_, argv_); 
#line 472 "pure2-last-use.cpp2"
  issue_683(args);
  issue_847_2(std::vector<std::unique_ptr<int>>());
  cpp2_enum();
}

