
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use.cpp2"

#line 103 "pure2-last-use.cpp2"
class issue_857;
  

#line 191 "pure2-last-use.cpp2"
class issue_857_2;
  

#line 196 "pure2-last-use.cpp2"
class issue_857_3;
  

#line 200 "pure2-last-use.cpp2"
class issue_857_6;
  

#line 206 "pure2-last-use.cpp2"
template<typename T> class move_only_function;
  

#line 212 "pure2-last-use.cpp2"
class issue_857_4;
   

#line 272 "pure2-last-use.cpp2"
class issue_857_5;
  

#line 277 "pure2-last-use.cpp2"
class issue_857_7;
  

#line 283 "pure2-last-use.cpp2"
class issue_857_8;
  

#line 289 "pure2-last-use.cpp2"
class issue_857_9;
  

#line 306 "pure2-last-use.cpp2"
class issue_869_0;
  

class issue_869_1;
  

#line 698 "pure2-last-use.cpp2"
class cpp2_union;
  

#line 706 "pure2-last-use.cpp2"
class my_string;
  

#line 764 "pure2-last-use.cpp2"
namespace captures {

#line 778 "pure2-last-use.cpp2"
class t;
  

#line 789 "pure2-last-use.cpp2"
}

#line 819 "pure2-last-use.cpp2"
class types;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use.cpp2"
auto f_inout([[maybe_unused]] auto& unnamed_param_1) -> void;
#line 2 "pure2-last-use.cpp2"
auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void;
[[nodiscard]] auto pred([[maybe_unused]] auto const& ...unnamed_param_1) -> auto;
[[nodiscard]] auto pred_copy([[maybe_unused]] auto ...unnamed_param_1) -> auto;
[[nodiscard]] constexpr auto identity(auto const& x) -> auto&&;
auto identity([[maybe_unused]] auto&& unnamed_param_1) -> void
CPP2_REQUIRES (false) ;
#line 7 "pure2-last-use.cpp2"
[[nodiscard]] auto identity_copy(auto x) -> auto;

auto issue_350() -> void;

#line 20 "pure2-last-use.cpp2"
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

#line 48 "pure2-last-use.cpp2"
auto issue_825() -> void;

#line 54 "pure2-last-use.cpp2"
auto issue_832() -> void;

#line 59 "pure2-last-use.cpp2"
[[nodiscard]] auto make_copy(auto x) -> auto;

auto issue_847_4(std::vector<int> v) -> void;

#line 67 "pure2-last-use.cpp2"
auto issue_847_0(std::vector<std::unique_ptr<int>> v) -> void;

#line 73 "pure2-last-use.cpp2"
auto issue_847_1(std::vector<std::unique_ptr<int>>&& v) -> void;

#line 79 "pure2-last-use.cpp2"
auto issue_847_5(auto&& v) -> void;

#line 85 "pure2-last-use.cpp2"
auto issue_847_2(auto&& v) -> void;

#line 90 "pure2-last-use.cpp2"
auto issue_847_3(int x) -> void;

auto issue_850() -> void;

#line 103 "pure2-last-use.cpp2"
class issue_857 {
  private: std::unique_ptr<int> a; 
  private: std::unique_ptr<int> b; 
  public: issue_857(issue_857&& that) noexcept;
#line 106 "pure2-last-use.cpp2"
  public: auto operator=(issue_857&& that) noexcept -> issue_857& ;
  public: ~issue_857() noexcept;

#line 111 "pure2-last-use.cpp2"
  public: auto f() && -> void;
  public: auto f(issue_857&& that) && -> void;
  public: auto g() && -> void;
  public: auto g(issue_857&& that) && -> void;
  public: auto h() & -> void;
  public: auto i() && -> void;
  public: auto j() && -> void;
  public: auto k() && -> void;

#line 122 "pure2-last-use.cpp2"
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

#line 135 "pure2-last-use.cpp2"
  public: auto p1() && -> void;

#line 139 "pure2-last-use.cpp2"
  public: auto p2() && -> void;

#line 143 "pure2-last-use.cpp2"
  public: auto p3() && -> void;

#line 147 "pure2-last-use.cpp2"
  public: auto q() && -> void;

#line 151 "pure2-last-use.cpp2"
  public: auto z(issue_857&& that) && -> void;

#line 189 "pure2-last-use.cpp2"
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
#line 208 "pure2-last-use.cpp2"
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

#line 230 "pure2-last-use.cpp2"
  public: auto i1(cpp2::in<int> x) && -> void;

#line 234 "pure2-last-use.cpp2"
  public: auto i2(cpp2::in<int> x) && -> void;

#line 238 "pure2-last-use.cpp2"
  public: auto i3(cpp2::in<int> x) && -> void;

#line 242 "pure2-last-use.cpp2"
  public: auto z(issue_857_4 const& that) && -> void;

#line 270 "pure2-last-use.cpp2"
};

class issue_857_5 {
  public: auto f() && -> void;
  public: std::unique_ptr<int> a; 
};

struct issue_857_7_A_as_base { std::add_lvalue_reference_t<int> A; };
#line 277 "pure2-last-use.cpp2"
class issue_857_7: public issue_857_7_A_as_base, public std::monostate {

#line 280 "pure2-last-use.cpp2"
  public: auto F() && -> void;
};

class issue_857_8 {
  public: std::unique_ptr<int> a; 
  public: move_only_function<int()> b; 
  public: std::add_lvalue_reference_t<int> c; 
  public: auto d() && -> void;
};
class issue_857_9: public issue_857_8 {

#line 292 "pure2-last-use.cpp2"
  // Error: Cppfront limitation:
  // <https://eel.is/c++draft/class.mfct.non.static#2.sentence-1>.
//f0: (move this) = f_copy(a);
//f1: (move this) = _ = b();
  public: auto f2() && -> void;
//f3: (move this) = d();

  // OK: Explicit 'this' for base members, like in templates.
  public: auto g0() && -> void;
  public: auto g1() && -> void;
  public: auto g2() && -> void;
  public: auto g3() && -> void;
};

class issue_869_0 {
  public: explicit issue_869_0([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2);
#line 307 "pure2-last-use.cpp2"
  public: auto operator=([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2) -> issue_869_0& ;
  public: [[nodiscard]] auto operator<=>([[maybe_unused]] issue_869_0 const& that) const& -> std::strong_ordering = default;
public: issue_869_0([[maybe_unused]] issue_869_0 const& that);

public: auto operator=([[maybe_unused]] issue_869_0 const& that) -> issue_869_0& ;
public: issue_869_0([[maybe_unused]] issue_869_0&& that) noexcept;
public: auto operator=([[maybe_unused]] issue_869_0&& that) noexcept -> issue_869_0& ;
public: explicit issue_869_0();

#line 308 "pure2-last-use.cpp2"
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

#line 311 "pure2-last-use.cpp2"
};

using issue_869_2_ret = issue_869_1;
[[nodiscard]] auto issue_869_2() -> issue_869_2_ret;

#line 314 "pure2-last-use.cpp2"
auto issue_884() -> void;

#line 642 "pure2-last-use.cpp2"
auto issue_888_0(std::string r, int size) -> void;

#line 645 "pure2-last-use.cpp2"
auto issue_888_1([[maybe_unused]] std::string unnamed_param_1, move_only_function<int(int)> size) -> void;

#line 649 "pure2-last-use.cpp2"
auto draw() -> void;

#line 655 "pure2-last-use.cpp2"
auto enum_0() -> void;

#line 660 "pure2-last-use.cpp2"
auto enum_1() -> void;

#line 688 "pure2-last-use.cpp2"
auto enum_2() -> void;

#line 698 "pure2-last-use.cpp2"
class cpp2_union {
  public: auto destroy() & -> void;
  public: ~cpp2_union() noexcept;
  public: cpp2_union() = default;
  public: cpp2_union(cpp2_union const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(cpp2_union const&) -> void = delete;


#line 704 "pure2-last-use.cpp2"
};

class my_string {
  public: std::string string; 
  public: std::size_t size {CPP2_UFCS(size)(string)}; 
};

using no_pessimizing_move_ret = std::unique_ptr<int>;
#line 711 "pure2-last-use.cpp2"
[[nodiscard]] auto no_pessimizing_move() -> no_pessimizing_move_ret;

auto deferred_non_copyable_0() -> void;

#line 719 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_1() -> auto;
using deferred_non_copyable_2_ret = std::unique_ptr<int>;


#line 725 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_2() -> deferred_non_copyable_2_ret;

#line 729 "pure2-last-use.cpp2"
auto loops() -> void;

#line 764 "pure2-last-use.cpp2"
namespace captures {

// Skip non captured name in function expression

auto f() -> void;

#line 776 "pure2-last-use.cpp2"
int inline constexpr x = 0;

class t {
  public: std::unique_ptr<int> x; 
  public: auto operator()() && -> void;

#line 787 "pure2-last-use.cpp2"
};

}

auto loops_and_captures() -> void;

#line 819 "pure2-last-use.cpp2"
class types {
  public: std::unique_ptr<int> x; 
  public: auto f() && -> void;
  public: auto g() && -> void;

#line 827 "pure2-last-use.cpp2"
};

auto skip_hidden_names() -> void;

#line 859 "pure2-last-use.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-last-use.cpp2"
auto f_inout([[maybe_unused]] auto& unnamed_param_1) -> void{}
#line 2 "pure2-last-use.cpp2"
auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void{}
[[nodiscard]] auto pred([[maybe_unused]] auto const& ...unnamed_param_1) -> auto { return true;  }
[[nodiscard]] auto pred_copy([[maybe_unused]] auto ...unnamed_param_1) -> auto { return true;  }
[[nodiscard]] constexpr auto identity(auto const& x) -> auto&& { return x;  }
auto identity([[maybe_unused]] auto&& unnamed_param_1) -> void
requires (false) {}
#line 7 "pure2-last-use.cpp2"
[[nodiscard]] auto identity_copy(auto x) -> auto { return std::move(x);  }

auto issue_350() -> void{
    auto x {21}; 

    auto l1 {[](auto&& x) mutable -> void{
        f_inout(CPP2_FORWARD(x));
    }}; 

    std::move(l1)(x);

    ++x;
}

#line 39 "pure2-last-use.cpp2"
auto issue_683(auto const& args) -> void{
    for ( auto const& n : args ) {
        static_cast<void>(n);
    }

    cpp2::deferred_init<int> n; 
    n.construct(0);
}

auto issue_825() -> void{
  static_cast<void>([](std::unique_ptr<int> b) mutable -> auto { return f_copy(std::move(b));  });
  static_cast<void>([](std::unique_ptr<int>&& c) mutable -> auto { return f_copy(std::move(c));  });
  static_cast<void>([](auto&& d) mutable -> auto { return f_copy(CPP2_FORWARD(d));  }(cpp2_new<int>(0)));
}

auto issue_832() -> void{
  auto i {0}; 
  while( i ) {}
}

[[nodiscard]] auto make_copy(auto x) -> auto { return std::move(x);  }

auto issue_847_4(std::vector<int> v) -> void{
  for ( 
  auto x : CPP2_UFCS(make_copy)(std::move(v)) ) {
    f_copy(std::move(x));
  }
}
auto issue_847_0(std::vector<std::unique_ptr<int>> v) -> void{
  // TODO Use 'std::views::as_rvalue`
  for ( 
  [[maybe_unused]] auto const& unnamed_param_1 : CPP2_UFCS(make_copy)(std::move(v)) ) {
  }
}
auto issue_847_1(std::vector<std::unique_ptr<int>>&& v) -> void{
  for ( 
  auto&& x : CPP2_UFCS(make_copy)(std::move(v)) ) {
    f_copy(std::move(x));
  }
}
auto issue_847_5(auto&& v) -> void{
  for ( 
  auto&& x : CPP2_UFCS(make_copy)(CPP2_FORWARD(v)) ) {
    f_copy(CPP2_FORWARD(x));
  }
}
auto issue_847_2(auto&& v) -> void{
  for ( 
  [[maybe_unused]] auto&& unnamed_param_1 : CPP2_UFCS(make_copy)(CPP2_FORWARD(v)) ) {
  }
}
auto issue_847_3(int x) -> void{for ( [[maybe_unused]] auto const& unnamed_param_1 : { std::move(x) } ) {}}

auto issue_850() -> void{
    std::vector v {1, 2, 3, 4, 5}; 

    //  Definite last use of v => move-capture v into f's closure
    auto f {[_0 = std::move(v)]() mutable -> auto&&{return _0; }}; 

    //  Now we can access the vector captured inside f()...
    CPP2_UFCS(push_back)(f(), 6);
    for ( auto const& e : std::move(f)() ) std::cout << e; // prints 123456
}

#line 106 "pure2-last-use.cpp2"
  issue_857::issue_857(issue_857&& that) noexcept
                                       : a{ std::move(that).a }
                                       , b{ std::move(that).b }{}
#line 106 "pure2-last-use.cpp2"
  auto issue_857::operator=(issue_857&& that) noexcept -> issue_857& {
                                       a = std::move(that).a;
                                       b = std::move(that).b;
                                       return *this; }
#line 107 "pure2-last-use.cpp2"
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
  auto issue_857::z(issue_857&& that) && -> void{
  if (true) {f_copy(std::move((*this))); }/*f */
  else {if (true) {f_copy(std::move((*this)), std::move(that)); }/*f */
  else {if (true) {f_copy(std::move((*this)).a); }/*g */
  else {if (true) {f_copy(std::move((*this)).a, std::move(that).a); }/*g */
  else {if (true) {f_copy(std::move(*this).a); }/*i */
  else {if (true) {f_copy(std::move(*this).a); }/*j */
  else {if (true) {/*k */
  f_inout(a);/*k */
  f_copy(std::move(*this).b);/*k */
  }/*k */
  else {if (true) {std::move(*this).k(); }/*l */
  else {if (true) {CPP2_UFCS(k)(std::move((*this))); }/*m */
  else {if (true) {std::move(*this).n(); }/*o1*/
  else {if (true) {CPP2_UFCS(n)(std::move((*this))); }/*o2*/
  else {if (true) {std::move(*this).n(0); }/*o3*/
  else {if (true) {n(std::move((*this))); }/*o4*/
  else {if (true) {/*p0*/
  f_inout(a);/*p0*/
  f_copy(std::move((*this)).a);/*p0*/
  }/*p0*/
  else {if (true) {/*p1*/
  f_inout((*this).a);/*p1*/
  f_copy(std::move(*this).a);/*p1*/
  }/*p1*/
  else {if (true) {/*p2*/
  f_inout(a);/*p2*/
  f_copy(std::move((*this)));/*p2*/
  }/*p2*/
  else {if (true) {/*p3*/
  f_inout((*this));/*p3*/
  f_copy(std::move(*this).a);/*p3*/
  }/*p3*/
  else {/*q */
  h();/*q */
  std::move(*this).n();/*q */
  }}}}}}}}}}}}}}}}}/*q */
  }

#line 195 "pure2-last-use.cpp2"
int gi {0}; 

#line 198 "pure2-last-use.cpp2"
  auto issue_857_3::f() && -> void { f_inout(std::move(*this).i);  }// OK: The implicit `this` is moved, not `i`.

#line 201 "pure2-last-use.cpp2"
  auto issue_857_6::f() && -> void { f_inout(std::move(*this).i);  }// OK: The implicit `this` is moved, not `i`.

#line 207 "pure2-last-use.cpp2"
  template <typename T> move_only_function<T>::move_only_function(){}
  template <typename T> move_only_function<T>::move_only_function([[maybe_unused]] move_only_function&& that) noexcept{}
#line 208 "pure2-last-use.cpp2"
  template <typename T> auto move_only_function<T>::operator=([[maybe_unused]] move_only_function&& that) noexcept -> move_only_function& {
                                       return *this; }
#line 209 "pure2-last-use.cpp2"
  template <typename T> [[nodiscard]] auto move_only_function<T>::operator()([[maybe_unused]] auto const& ...unnamed_param_2) && -> int { return 0;  }

#line 217 "pure2-last-use.cpp2"
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
  auto issue_857_4::z(issue_857_4 const& that) && -> void{
  auto x {0}; 
  if (true) {static_cast<void>(std::move(*this).mf()); }/*h0*/
  else {if (true) {static_cast<void>(CPP2_UFCS(mf)(std::move((*this)))); }/*h1*/
  else {if (true) {static_cast<void>(CPP2_UFCS_MOVE(mf)(that)); }/*h2*/
  else {if (true) {static_cast<void>(that.f); }/*h3*/
  else {if (true) {static_cast<void>(CPP2_UFCS_MOVE(mg)(std::move(x))); }/*h4*/
  else {if (true) {f() + CPP2_UFCS_MOVE(g)(std::move(x)); }/*h5*/
  else {if (true) {CPP2_UFCS(g)(std::move(x)) + std::move(*this).f(); }/*h6*/
  else {if (true) {CPP2_UFCS(f)((*this)) + CPP2_UFCS_MOVE(g)(std::move(x)); }/*h7*/
  else {if (true) {CPP2_UFCS(g)(std::move(x)) + CPP2_UFCS(f)(std::move((*this))); }/*h8*/
  else {if (true) {/*i0*/
  static_cast<void>(f());/*i0*/
  static_cast<void>(CPP2_UFCS_MOVE(mg)(std::move(x)));/*i0*/
  }/*i0*/
  else {if (true) {/*i1*/
  static_cast<void>(CPP2_UFCS(g)(std::move(x)));/*i1*/
  static_cast<void>(std::move(*this).mf());/*i1*/
  }/*i1*/
  else {if (true) {/*i2*/
  static_cast<void>(CPP2_UFCS(f)((*this)));/*i2*/
  static_cast<void>(CPP2_UFCS_MOVE(mg)(std::move(x)));/*i2*/
  }/*i2*/
  else {/*i3*/
  static_cast<void>(CPP2_UFCS(g)(std::move(x)));/*i3*/
  static_cast<void>(CPP2_UFCS(mf)(std::move((*this))));/*i3*/
  }}}}}}}}}}}}/*i3*/
  }

#line 273 "pure2-last-use.cpp2"
  auto issue_857_5::f() && -> void { f_copy(std::move(*this).a);  }

#line 280 "pure2-last-use.cpp2"
  auto issue_857_7::F() && -> void { f_inout(std::move(*this).A);  }

#line 287 "pure2-last-use.cpp2"
  auto issue_857_8::d() && -> void{}

#line 296 "pure2-last-use.cpp2"
  auto issue_857_9::f2() && -> void { f_inout(c);  }// OK: Happens to work, like non-'move' 'this' parameters.

#line 300 "pure2-last-use.cpp2"
  auto issue_857_9::g0() && -> void { f_copy(std::move((*this)).a);  }
  auto issue_857_9::g1() && -> void { static_cast<void>(CPP2_UFCS(b)(std::move((*this))));  }
  auto issue_857_9::g2() && -> void { f_inout(std::move((*this)).c);  }
  auto issue_857_9::g3() && -> void { CPP2_UFCS(d)(std::move((*this)));  }

#line 307 "pure2-last-use.cpp2"
  issue_869_0::issue_869_0([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2){}
#line 307 "pure2-last-use.cpp2"
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
#line 312 "pure2-last-use.cpp2"
[[nodiscard]] auto issue_869_2() -> issue_869_2_ret{
                                               issue_869_1 res {}; CPP2_UFCS(set_i)(res, cpp2_new<int>(0));
#line 313 "pure2-last-use.cpp2"
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

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    if (true) {
      f_copy(std::move(x));
    }
    else {
      {f_inout(x); }
      f_inout(x);
      if (true) {
        f_copy(std::move(x));
      }
    }
    static_cast<void>(0);
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      if (true) {
        if (true) {
          f_copy(std::move(x));
        }
      }
    }
    else {
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      if (true) {
        if (true) {
          f_copy(std::move(x));
        }
      }
    }
    else {
      f_copy(std::move(x));
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
    }
    else {
      if (true) {
        if (true) {
          f_copy(std::move(x));
        }
      }
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      f_copy(std::move(x));
    }
    else {
      if (true) {
        if (true) {
          f_copy(std::move(x));
        }
      }
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      auto y {cpp2_new<int>(0)}; 
      f_copy(std::move(x));
      f_copy(std::move(y));
    }
    else {
      if (true) {
        if (true) {
          f_inout(x);
        }
        f_copy(std::move(x));
      }
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      auto y {cpp2_new<int>(0)}; 
      if (true) {}
      else {
        f_copy(std::move(x));
        f_copy(std::move(y));
      }
    }
    else {
      if (true) {
        if (true) {
          auto y {cpp2_new<int>(0)}; 
          f_copy(std::move(y));
          f_inout(x);
        }
        f_copy(std::move(x));
      }
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      auto y {cpp2_new<int>(0)}; 
      if (true) {}
      else {
        f_copy(std::move(x));
        f_copy(std::move(y));
      }
    }
    else {
      auto y {cpp2_new<int>(0)}; 
      if (true) {
        if (true) {
          f_copy(std::move(x));
        }
        else {
          f_copy(std::move(x));
        }
        f_copy(std::move(y));
      }
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      f_copy(std::move(x));
    }
    else {
      if (true) {
        auto x {cpp2_new<int>(0)}; 
        if (true) {
          f_inout(x);
        }
        else {
        }
        f_copy(std::move(x));
      }
      f_copy(std::move(x));
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      if (true) {
        auto x {cpp2_new<int>(0)}; 
        if (true) {
          f_inout(x);
        }
        else {
        }
        f_copy(std::move(x));
      }
      f_copy(std::move(x));
    }
    else {
      f_copy(std::move(x));
    }
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

auto enum_0() -> void{
    cpp2::deferred_init<std::string> underlying_type; 
    if (true) {}
    underlying_type.construct("");
}
auto enum_1() -> void{
    auto max_value {cpp2_new<int>(0)}; 
    std::reference_wrapper<std::unique_ptr<int> const> min_value {max_value}; 

    for ( 
          auto x : { 0 } ) 
    {
        auto v {cpp2_new<int>(identity_copy(std::move(x)))}; 
        if (pred(v, min_value)) {
            min_value = std::ref(identity(v)); // Not using 'else' will never move 'v'.
        }
        if (pred(v, max_value)) {
            max_value = identity_copy(std::move(v));
        }
    }

    auto y {cpp2_new<bool>(false)}; 
    while( *cpp2::assert_not_null(identity(y)) ) {
        auto v {cpp2_new<int>(0)}; 
        f_copy(std::move(v));
    }

    auto z {cpp2_new<bool>(false)}; 
    do {
        auto v {cpp2_new<int>(0)}; 
        f_copy(std::move(v));
    } while ( *cpp2::assert_not_null(identity(z)));
}
auto enum_2() -> void{
    auto umax {cpp2_new<int>(0)}; 
    if (pred(umax)) {
    }
    else {if (pred(umax)) {
    }
    else {if (pred_copy(std::move(umax))) {
    }}}
}

#line 699 "pure2-last-use.cpp2"
  auto cpp2_union::destroy() & -> void{}
  cpp2_union::~cpp2_union() noexcept{
    destroy();
    static_cast<void>(std::move((*this)));
  }

#line 711 "pure2-last-use.cpp2"
[[nodiscard]] auto no_pessimizing_move() -> no_pessimizing_move_ret{
                                                                std::unique_ptr<int> ret {};
#line 712 "pure2-last-use.cpp2"
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
#line 726 "pure2-last-use.cpp2"
  p.construct();
return std::move(p.value()); }

auto loops() -> void{
  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { 0 } ) 
    f_inout(x);
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { 0 } ) 
    f_inout(x);
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { 0 } ) 
    cpp2::Default.expects(CPP2_UFCS(get)(x), "");
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      f_copy(std::move(x));
    }
    else {
      while( true ) {
        f_inout(x);
      }
    }
  });
}

namespace captures {

#line 768 "pure2-last-use.cpp2"
auto f() -> void{
  auto x {cpp2_new<int>(0)}; 
  f_copy(std::move(x));
  auto id {[](auto const& x) mutable -> auto&& { return x;  }}; 
  auto y {cpp2_new<int>(0)}; 
  cpp2::Default.expects(&std::move(id)(y) == &y, "");
}

#line 780 "pure2-last-use.cpp2"
  auto t::operator()() && -> void{
    f_copy(std::move(*this).x);
    static_cast<void>([&]() mutable -> void{
      using captures::x;
      static_cast<void>(x);
    });
  }

#line 789 "pure2-last-use.cpp2"
}

auto loops_and_captures() -> void{
  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(x));
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { [](auto const& x) mutable -> auto { return x; } } ) 
    {}
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(x));
    for ( 

#line 807 "pure2-last-use.cpp2"
    [[maybe_unused]] auto const& unnamed_param_1 : { []() mutable -> auto{using captures::x;return x; } } ) 
    {}
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { [_0 = std::move(x)]() mutable -> auto { return *cpp2::assert_not_null(_0); } } ) 
    {}
  });
}

#line 821 "pure2-last-use.cpp2"
  auto types::f() && -> void { static_cast<void>([&, _1 = std::move(*this).x]() mutable -> auto { return *cpp2::assert_not_null(_1);  });  }
  auto types::g() && -> void{
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { [&, _1 = std::move(*this).x]() mutable -> auto { return *cpp2::assert_not_null(_1); } } ) 
    {}
  }

#line 829 "pure2-last-use.cpp2"
auto skip_hidden_names() -> void{
  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(x));
{
auto x = cpp2_new<int>(0);

#line 834 "pure2-last-use.cpp2"
      f_copy(std::move(x));
}
#line 835 "pure2-last-use.cpp2"
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    static_cast<void>([_0 = std::move(x)]() mutable -> void{
      static_cast<void>(_0);
      auto x {cpp2_new<int>(1)}; 
      static_cast<void>([_0 = std::move(x)]() mutable -> void{
        static_cast<void>(_0);
      });
    });
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(x));
    for ( 
    auto x : { 0 } ) 
    static_cast<void>(identity_copy(std::move(x)));
{
auto x = cpp2_new<int>(0);

#line 855 "pure2-last-use.cpp2"
      f_copy(std::move(x));
}
#line 856 "pure2-last-use.cpp2"
  });
}

auto main(int const argc_, char** argv_) -> int{
  auto const args = cpp2::make_args(argc_, argv_); 
#line 860 "pure2-last-use.cpp2"
  issue_683(args);
  issue_847_2(std::vector<std::unique_ptr<int>>());
  issue_847_5(args);
  issue_850();
  enum_0();
}

