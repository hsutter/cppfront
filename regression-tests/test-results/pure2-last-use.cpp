
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use.cpp2"

#line 168 "pure2-last-use.cpp2"
class issue_857;
  

#line 256 "pure2-last-use.cpp2"
class issue_857_2;
  

#line 261 "pure2-last-use.cpp2"
class issue_857_3;
  

#line 265 "pure2-last-use.cpp2"
class issue_857_6;
  

#line 271 "pure2-last-use.cpp2"
template<typename T> class move_only_function;
  

#line 277 "pure2-last-use.cpp2"
class issue_857_4;
   

#line 337 "pure2-last-use.cpp2"
class issue_857_5;
  

#line 342 "pure2-last-use.cpp2"
class issue_857_7;
  

#line 348 "pure2-last-use.cpp2"
class issue_857_8;
  

#line 354 "pure2-last-use.cpp2"
class issue_857_9;
  

#line 371 "pure2-last-use.cpp2"
class issue_869_0;
  

class issue_869_1;
  

#line 843 "pure2-last-use.cpp2"
class cpp2_union;
  

#line 851 "pure2-last-use.cpp2"
class my_string;
  

#line 910 "pure2-last-use.cpp2"
namespace captures {

#line 924 "pure2-last-use.cpp2"
class t;
  

#line 953 "pure2-last-use.cpp2"
}

#line 983 "pure2-last-use.cpp2"
class types;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use.cpp2"
auto f_inout([[maybe_unused]] auto& unnamed_param_1) -> void;
#line 2 "pure2-last-use.cpp2"
auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void;
[[nodiscard]] auto pred([[maybe_unused]] auto const& ...unnamed_param_1) -> auto;
[[nodiscard]] auto pred_copy([[maybe_unused]] auto ...unnamed_param_1) -> auto;
template<typename T> [[nodiscard]] constexpr auto identity(T&& x) -> auto&&
CPP2_REQUIRES (std::is_reference_v<T>) ;
#line 6 "pure2-last-use.cpp2"
[[nodiscard]] auto identity_copy(auto x) -> auto;

auto issue_313() -> void;

#line 72 "pure2-last-use.cpp2"
auto issue_313_1(std::unique_ptr<int> x) -> void;

auto issue_350() -> void;

#line 85 "pure2-last-use.cpp2"
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

#line 113 "pure2-last-use.cpp2"
auto issue_825() -> void;

#line 119 "pure2-last-use.cpp2"
auto issue_832() -> void;

#line 124 "pure2-last-use.cpp2"
[[nodiscard]] auto make_copy(auto x) -> auto;

auto issue_847_4(std::vector<int> v) -> void;

#line 132 "pure2-last-use.cpp2"
auto issue_847_0(std::vector<std::unique_ptr<int>> v) -> void;

#line 138 "pure2-last-use.cpp2"
auto issue_847_1(std::vector<std::unique_ptr<int>>&& v) -> void;

#line 144 "pure2-last-use.cpp2"
auto issue_847_5(auto&& v) -> void;

#line 150 "pure2-last-use.cpp2"
auto issue_847_2(auto&& v) -> void;

#line 155 "pure2-last-use.cpp2"
auto issue_847_3(int x) -> void;

auto issue_850() -> void;

#line 168 "pure2-last-use.cpp2"
class issue_857 {
  private: std::unique_ptr<int> a; 
  private: std::unique_ptr<int> b; 
  public: issue_857(issue_857&& that) noexcept;
#line 171 "pure2-last-use.cpp2"
  public: auto operator=(issue_857&& that) noexcept -> issue_857& ;
  public: ~issue_857() noexcept;

#line 176 "pure2-last-use.cpp2"
  public: auto f() && -> void;
  public: auto f(issue_857&& that) && -> void;
  public: auto g() && -> void;
  public: auto g(issue_857&& that) && -> void;
  public: auto h() & -> void;
  public: auto i() && -> void;
  public: auto j() && -> void;
  public: auto k() && -> void;

#line 187 "pure2-last-use.cpp2"
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

#line 200 "pure2-last-use.cpp2"
  public: auto p1() && -> void;

#line 204 "pure2-last-use.cpp2"
  public: auto p2() && -> void;

#line 208 "pure2-last-use.cpp2"
  public: auto p3() && -> void;

#line 212 "pure2-last-use.cpp2"
  public: auto q() && -> void;

#line 216 "pure2-last-use.cpp2"
  public: auto z(issue_857&& that) && -> void;

#line 254 "pure2-last-use.cpp2"
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
#line 273 "pure2-last-use.cpp2"
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
  public: auto h4(cpp2::impl::in<int> x) && -> void;
  public: auto h5(cpp2::impl::in<int> x) && -> void;
  public: auto h6(cpp2::impl::in<int> x) && -> void;
  public: auto h7(cpp2::impl::in<int> x) && -> void;
  public: auto h8(cpp2::impl::in<int> x) && -> void;
  public: auto i0(cpp2::impl::in<int> x) && -> void;

#line 295 "pure2-last-use.cpp2"
  public: auto i1(cpp2::impl::in<int> x) && -> void;

#line 299 "pure2-last-use.cpp2"
  public: auto i2(cpp2::impl::in<int> x) && -> void;

#line 303 "pure2-last-use.cpp2"
  public: auto i3(cpp2::impl::in<int> x) && -> void;

#line 307 "pure2-last-use.cpp2"
  public: auto z(issue_857_4 const& that) && -> void;

#line 335 "pure2-last-use.cpp2"
};

class issue_857_5 {
  public: auto f() && -> void;
  public: std::unique_ptr<int> a; 
};

struct issue_857_7_A_as_base { std::add_lvalue_reference_t<int> A; };
#line 342 "pure2-last-use.cpp2"
class issue_857_7: public issue_857_7_A_as_base, public std::monostate {

#line 345 "pure2-last-use.cpp2"
  public: auto F() && -> void;
};

class issue_857_8 {
  public: std::unique_ptr<int> a; 
  public: move_only_function<int()> b; 
  public: std::add_lvalue_reference_t<int> c; 
  public: auto d() && -> void;
};
class issue_857_9: public issue_857_8 {

#line 357 "pure2-last-use.cpp2"
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
#line 372 "pure2-last-use.cpp2"
  public: auto operator=([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2) -> issue_869_0& ;
  public: [[nodiscard]] auto operator<=>([[maybe_unused]] issue_869_0 const& that) const& -> std::strong_ordering = default;
public: issue_869_0([[maybe_unused]] issue_869_0 const& that);

public: auto operator=([[maybe_unused]] issue_869_0 const& that) -> issue_869_0& ;
public: issue_869_0([[maybe_unused]] issue_869_0&& that) noexcept;
public: auto operator=([[maybe_unused]] issue_869_0&& that) noexcept -> issue_869_0& ;
public: explicit issue_869_0();

#line 373 "pure2-last-use.cpp2"
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

#line 376 "pure2-last-use.cpp2"
};

using issue_869_2_ret = issue_869_1;
[[nodiscard]] auto issue_869_2() -> issue_869_2_ret;

#line 379 "pure2-last-use.cpp2"
auto issue_884() -> void;

#line 776 "pure2-last-use.cpp2"
auto issue_888_0(std::string r, int size) -> void;

#line 779 "pure2-last-use.cpp2"
auto issue_888_1([[maybe_unused]] std::string unnamed_param_1, move_only_function<int(int)> size) -> void;

#line 783 "pure2-last-use.cpp2"
auto issue_890() -> void;

#line 789 "pure2-last-use.cpp2"
auto issue_962(cpp2::impl::in<::std::string> s) -> void;

#line 794 "pure2-last-use.cpp2"
auto draw() -> void;

#line 800 "pure2-last-use.cpp2"
auto enum_0() -> void;

#line 805 "pure2-last-use.cpp2"
auto enum_1() -> void;

#line 833 "pure2-last-use.cpp2"
auto enum_2() -> void;

#line 843 "pure2-last-use.cpp2"
class cpp2_union {
  public: auto destroy() & -> void;
  public: ~cpp2_union() noexcept;
  public: cpp2_union() = default;
  public: cpp2_union(cpp2_union const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(cpp2_union const&) -> void = delete;


#line 849 "pure2-last-use.cpp2"
};

class my_string {
  public: std::string string; 
  public: std::size_t size {CPP2_UFCS(size)(string)}; 
};

using no_pessimizing_move_ret = std::unique_ptr<int>;
#line 856 "pure2-last-use.cpp2"
[[nodiscard]] auto no_pessimizing_move() -> no_pessimizing_move_ret;

auto deferred_non_copyable_0() -> void;

#line 864 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_1() -> auto;
using deferred_non_copyable_2_ret = std::unique_ptr<int>;


#line 870 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_2() -> deferred_non_copyable_2_ret;

#line 874 "pure2-last-use.cpp2"
auto loops() -> void;

#line 910 "pure2-last-use.cpp2"
namespace captures {

// Skip non captured name in function expression

auto f() -> void;

#line 922 "pure2-last-use.cpp2"
int inline constexpr x = 0;

class t {
  public: std::unique_ptr<int> x; 
  public: auto operator()() && -> void;

#line 937 "pure2-last-use.cpp2"
};

auto g() -> void;

#line 953 "pure2-last-use.cpp2"
}

auto loops_and_captures() -> void;

#line 983 "pure2-last-use.cpp2"
class types {
  public: std::unique_ptr<int> x; 
  public: auto f() && -> void;
  public: auto g() && -> void;

#line 991 "pure2-last-use.cpp2"
};

auto skip_hidden_names() -> void;

#line 1043 "pure2-last-use.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-last-use.cpp2"
auto f_inout([[maybe_unused]] auto& unnamed_param_1) -> void{}
#line 2 "pure2-last-use.cpp2"
auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void{}
#line 3 "pure2-last-use.cpp2"
[[nodiscard]] auto pred([[maybe_unused]] auto const& ...unnamed_param_1) -> auto { return true;  }
#line 4 "pure2-last-use.cpp2"
[[nodiscard]] auto pred_copy([[maybe_unused]] auto ...unnamed_param_1) -> auto { return true;  }
#line 5 "pure2-last-use.cpp2"
template<typename T> [[nodiscard]] constexpr auto identity(T&& x) -> auto&&
requires (std::is_reference_v<T>) {return CPP2_FORWARD(x); }
#line 6 "pure2-last-use.cpp2"
[[nodiscard]] auto identity_copy(auto x) -> auto { return std::move(x);  }

#line 8 "pure2-last-use.cpp2"
auto issue_313() -> void{
  static_cast<void>([]() mutable -> std::vector<int>{
    auto a {cpp2_new<int>(0)}; 
    return { *cpp2::impl::assert_not_null(a), *cpp2::impl::assert_not_null(identity_copy(std::move(a))) }; 
  });
  static_cast<void>([]() mutable -> std::vector<int>{
    auto a {cpp2_new<int>(0)}; 
    return { *cpp2::impl::assert_not_null(*cpp2::impl::assert_not_null(&a)), *cpp2::impl::assert_not_null(identity_copy(std::move(a))) }; 
  });
  static_cast<void>([]() mutable -> int{
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
    static_cast<void>(cpp2::impl::is<std::type_identity_t<decltype(f)>>(f));// OK?

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
  {
    auto a {cpp2_new<int>(0)}; 
    static_cast<void>([_0 = std::move(a)]() mutable -> auto { return *cpp2::impl::assert_not_null(identity(_0)) + *cpp2::impl::assert_not_null(identity(_0));  });
  }
}
#line 72 "pure2-last-use.cpp2"
auto issue_313_1(std::unique_ptr<int> x) -> void{
                                                                                 if (cpp2::cpp2_default.is_active() && !(*cpp2::impl::assert_not_null(identity(x)) + *cpp2::impl::assert_not_null(identity(x))) ) { cpp2::cpp2_default.report_violation(""); }}

#line 74 "pure2-last-use.cpp2"
auto issue_350() -> void{
    auto x {21}; 

    auto l1 {[](auto&& x) mutable -> void{
        f_inout(CPP2_FORWARD(x));
    }}; 

    std::move(l1)(x);

    ++x;
}

#line 104 "pure2-last-use.cpp2"
auto issue_683(auto const& args) -> void{
    for ( auto const& n : args ) {
        static_cast<void>(n);
    }

    cpp2::impl::deferred_init<int> n; 
    n.construct(0);
}

#line 113 "pure2-last-use.cpp2"
auto issue_825() -> void{
  static_cast<void>([](std::unique_ptr<int> b) mutable -> auto { return f_copy(std::move(b));  });
  static_cast<void>([](std::unique_ptr<int>&& c) mutable -> auto { return f_copy(std::move(c));  });
  static_cast<void>([](auto&& d) mutable -> auto { return f_copy(CPP2_FORWARD(d));  }(cpp2_new<int>(0)));
}

#line 119 "pure2-last-use.cpp2"
auto issue_832() -> void{
  auto i {0}; 
  while( i ) {}
}

#line 124 "pure2-last-use.cpp2"
[[nodiscard]] auto make_copy(auto x) -> auto { return std::move(x);  }

#line 126 "pure2-last-use.cpp2"
auto issue_847_4(std::vector<int> v) -> void{
  for ( 
  auto x : CPP2_UFCS(make_copy)(std::move(v)) ) {
    f_copy(std::move(x));
  }
}
#line 132 "pure2-last-use.cpp2"
auto issue_847_0(std::vector<std::unique_ptr<int>> v) -> void{
  // TODO Use 'std::views::as_rvalue`
  for ( 
  [[maybe_unused]] auto const& unnamed_param_1 : CPP2_UFCS(make_copy)(std::move(v)) ) {
  }
}
#line 138 "pure2-last-use.cpp2"
auto issue_847_1(std::vector<std::unique_ptr<int>>&& v) -> void{
  for ( 
  auto&& x : CPP2_UFCS(make_copy)(std::move(v)) ) {
    f_copy(std::move(x));
  }
}
#line 144 "pure2-last-use.cpp2"
auto issue_847_5(auto&& v) -> void{
  for ( 
  auto&& x : CPP2_UFCS(make_copy)(CPP2_FORWARD(v)) ) {
    f_copy(CPP2_FORWARD(x));
  }
}
#line 150 "pure2-last-use.cpp2"
auto issue_847_2(auto&& v) -> void{
  for ( 
  [[maybe_unused]] auto&& unnamed_param_1 : CPP2_UFCS(make_copy)(CPP2_FORWARD(v)) ) {
  }
}
#line 155 "pure2-last-use.cpp2"
auto issue_847_3(int x) -> void{for ( [[maybe_unused]] auto const& unnamed_param_1 : { std::move(x) } ) {}}

#line 157 "pure2-last-use.cpp2"
auto issue_850() -> void{
    std::vector v {1, 2, 3, 4, 5}; 

    //  Definite last use of v => move-capture v into f's closure
    auto f {[_0 = std::move(v)]() mutable -> auto&&{return _0; }}; 

    //  Now we can access the vector captured inside f()...
    CPP2_UFCS(push_back)(f(), 6);
    for ( auto const& e : std::move(f)() ) std::cout << e; // prints 123456
}

#line 171 "pure2-last-use.cpp2"
  issue_857::issue_857(issue_857&& that) noexcept
                                       : a{ std::move(that).a }
                                       , b{ std::move(that).b }{}
#line 171 "pure2-last-use.cpp2"
  auto issue_857::operator=(issue_857&& that) noexcept -> issue_857& {
                                       a = std::move(that).a;
                                       b = std::move(that).b;
                                       return *this; }
#line 172 "pure2-last-use.cpp2"
  issue_857::~issue_857() noexcept{
    f_inout(a);
    f_copy(std::move((*this)).b);
  }
#line 176 "pure2-last-use.cpp2"
  auto issue_857::f() && -> void { f_copy(std::move((*this)));  }
#line 177 "pure2-last-use.cpp2"
  auto issue_857::f(issue_857&& that) && -> void { f_copy(std::move((*this)), std::move(that));  }
#line 178 "pure2-last-use.cpp2"
  auto issue_857::g() && -> void { f_copy(std::move((*this)).a);  }
#line 179 "pure2-last-use.cpp2"
  auto issue_857::g(issue_857&& that) && -> void { f_copy(std::move((*this)).a, std::move(that).a);  }
#line 180 "pure2-last-use.cpp2"
  auto issue_857::h() & -> void { f_inout(a);  }
#line 181 "pure2-last-use.cpp2"
  auto issue_857::i() && -> void { f_copy(std::move(*this).a);  }
#line 182 "pure2-last-use.cpp2"
  auto issue_857::j() && -> void { f_copy(std::move(*this).a);  }
#line 183 "pure2-last-use.cpp2"
  auto issue_857::k() && -> void{
    f_inout(a);
    f_copy(std::move(*this).b);
  }
#line 187 "pure2-last-use.cpp2"
  auto issue_857::l() && -> void { std::move(*this).k();  }
#line 188 "pure2-last-use.cpp2"
  auto issue_857::m() && -> void { CPP2_UFCS(k)(std::move((*this)));  }
#line 189 "pure2-last-use.cpp2"
  auto issue_857::n([[maybe_unused]] auto const& unnamed_param_1) -> void{}
#line 190 "pure2-last-use.cpp2"
  auto issue_857::n() && -> void{}
#line 191 "pure2-last-use.cpp2"
  auto issue_857::o0() && -> void { std::move(*this).n();  }
#line 192 "pure2-last-use.cpp2"
  auto issue_857::o1() && -> void { CPP2_UFCS(n)(std::move((*this)));  }
#line 193 "pure2-last-use.cpp2"
  auto issue_857::o2() && -> void { std::move(*this).n(0);  }
#line 194 "pure2-last-use.cpp2"
  auto issue_857::o3() && -> void { std::move(*this).n(0);  }
#line 195 "pure2-last-use.cpp2"
  auto issue_857::o4() && -> void { n(std::move((*this)));  }
#line 196 "pure2-last-use.cpp2"
  auto issue_857::p0() && -> void{
    f_inout(a);
    f_copy(std::move((*this)).a);
  }
#line 200 "pure2-last-use.cpp2"
  auto issue_857::p1() && -> void{
    f_inout((*this).a);
    f_copy(std::move(*this).a);
  }
#line 204 "pure2-last-use.cpp2"
  auto issue_857::p2() && -> void{
    f_inout(a);
    f_copy(std::move((*this)));
  }
#line 208 "pure2-last-use.cpp2"
  auto issue_857::p3() && -> void{
    f_inout((*this));
    f_copy(std::move(*this).a);
  }
#line 212 "pure2-last-use.cpp2"
  auto issue_857::q() && -> void{
    h();
    std::move(*this).n();
  }
#line 216 "pure2-last-use.cpp2"
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

#line 260 "pure2-last-use.cpp2"
int gi {0}; 

#line 263 "pure2-last-use.cpp2"
  auto issue_857_3::f() && -> void { f_inout(std::move(*this).i);  }// OK: The implicit `this` is moved, not `i`.

#line 266 "pure2-last-use.cpp2"
  auto issue_857_6::f() && -> void { f_inout(std::move(*this).i);  }// OK: The implicit `this` is moved, not `i`.

#line 272 "pure2-last-use.cpp2"
  template <typename T> move_only_function<T>::move_only_function(){}
#line 273 "pure2-last-use.cpp2"
  template <typename T> move_only_function<T>::move_only_function([[maybe_unused]] move_only_function&& that) noexcept{}
#line 273 "pure2-last-use.cpp2"
  template <typename T> auto move_only_function<T>::operator=([[maybe_unused]] move_only_function&& that) noexcept -> move_only_function& {
                                       return *this; }
#line 274 "pure2-last-use.cpp2"
  template <typename T> [[nodiscard]] auto move_only_function<T>::operator()([[maybe_unused]] auto const& ...unnamed_param_2) && -> int { return 0;  }

#line 282 "pure2-last-use.cpp2"
  auto issue_857_4::h0() && -> void { static_cast<void>(std::move(*this).mf());  }
#line 283 "pure2-last-use.cpp2"
  auto issue_857_4::h1() && -> void { static_cast<void>(CPP2_UFCS(mf)(std::move((*this))));  }
#line 284 "pure2-last-use.cpp2"
  auto issue_857_4::h2(issue_857_4 const& that) && -> void { static_cast<void>(CPP2_UFCS_MOVE(mf)(that));  }
#line 285 "pure2-last-use.cpp2"
  auto issue_857_4::h3(issue_857_4 const& that) && -> void { static_cast<void>(that.f);  }
#line 286 "pure2-last-use.cpp2"
  auto issue_857_4::h4(cpp2::impl::in<int> x) && -> void { static_cast<void>(CPP2_UFCS_MOVE(mg)(x));  }
#line 287 "pure2-last-use.cpp2"
  auto issue_857_4::h5(cpp2::impl::in<int> x) && -> void { static_cast<void>(f() + CPP2_UFCS_MOVE(g)(x));  }// FIXME #313.
#line 288 "pure2-last-use.cpp2"
  auto issue_857_4::h6(cpp2::impl::in<int> x) && -> void { static_cast<void>(CPP2_UFCS(g)(x) + std::move(*this).f());  }// FIXME #313.
#line 289 "pure2-last-use.cpp2"
  auto issue_857_4::h7(cpp2::impl::in<int> x) && -> void { static_cast<void>(CPP2_UFCS(f)((*this)) + CPP2_UFCS_MOVE(g)(x));  }// FIXME #313.
#line 290 "pure2-last-use.cpp2"
  auto issue_857_4::h8(cpp2::impl::in<int> x) && -> void { static_cast<void>(CPP2_UFCS(g)(x) + CPP2_UFCS(f)(std::move((*this))));  }// FIXME #313.
#line 291 "pure2-last-use.cpp2"
  auto issue_857_4::i0(cpp2::impl::in<int> x) && -> void{
    static_cast<void>(f());
    static_cast<void>(CPP2_UFCS_MOVE(mg)(x));
  }
#line 295 "pure2-last-use.cpp2"
  auto issue_857_4::i1(cpp2::impl::in<int> x) && -> void{
    static_cast<void>(CPP2_UFCS(g)(x));
    static_cast<void>(std::move(*this).mf());
  }
#line 299 "pure2-last-use.cpp2"
  auto issue_857_4::i2(cpp2::impl::in<int> x) && -> void{
    static_cast<void>(CPP2_UFCS(f)((*this)));
    static_cast<void>(CPP2_UFCS_MOVE(mg)(x));
  }
#line 303 "pure2-last-use.cpp2"
  auto issue_857_4::i3(cpp2::impl::in<int> x) && -> void{
    static_cast<void>(CPP2_UFCS(g)(x));
    static_cast<void>(CPP2_UFCS(mf)(std::move((*this))));
  }
#line 307 "pure2-last-use.cpp2"
  auto issue_857_4::z(issue_857_4 const& that) && -> void{
  auto x {0}; 
  if (true) {static_cast<void>(std::move(*this).mf()); }/*h0*/
  else {if (true) {static_cast<void>(CPP2_UFCS(mf)(std::move((*this)))); }/*h1*/
  else {if (true) {static_cast<void>(CPP2_UFCS_MOVE(mf)(that)); }/*h2*/
  else {if (true) {static_cast<void>(that.f); }/*h3*/
  else {if (true) {static_cast<void>(CPP2_UFCS_MOVE(mg)(std::move(x))); }/*h4*/
  else {if (true) {static_cast<void>(f() + CPP2_UFCS_MOVE(g)(std::move(x))); }/*h5*/
  else {if (true) {static_cast<void>(CPP2_UFCS(g)(std::move(x)) + std::move(*this).f()); }/*h6*/
  else {if (true) {static_cast<void>(CPP2_UFCS(f)((*this)) + CPP2_UFCS_MOVE(g)(std::move(x))); }/*h7*/
  else {if (true) {static_cast<void>(CPP2_UFCS(g)(std::move(x)) + CPP2_UFCS(f)(std::move((*this)))); }/*h8*/
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

#line 338 "pure2-last-use.cpp2"
  auto issue_857_5::f() && -> void { f_copy(std::move(*this).a);  }

#line 345 "pure2-last-use.cpp2"
  auto issue_857_7::F() && -> void { f_inout(std::move(*this).A);  }

#line 352 "pure2-last-use.cpp2"
  auto issue_857_8::d() && -> void{}

#line 361 "pure2-last-use.cpp2"
  auto issue_857_9::f2() && -> void { f_inout(c);  }// OK: Happens to work, like non-'move' 'this' parameters.

#line 365 "pure2-last-use.cpp2"
  auto issue_857_9::g0() && -> void { f_copy(std::move((*this)).a);  }
#line 366 "pure2-last-use.cpp2"
  auto issue_857_9::g1() && -> void { static_cast<void>(CPP2_UFCS(b)(std::move((*this))));  }
#line 367 "pure2-last-use.cpp2"
  auto issue_857_9::g2() && -> void { f_inout(std::move((*this)).c);  }
#line 368 "pure2-last-use.cpp2"
  auto issue_857_9::g3() && -> void { CPP2_UFCS(d)(std::move((*this)));  }

#line 372 "pure2-last-use.cpp2"
  issue_869_0::issue_869_0([[maybe_unused]] std::unique_ptr<int>&& unnamed_param_2){}
#line 372 "pure2-last-use.cpp2"
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
#line 377 "pure2-last-use.cpp2"
[[nodiscard]] auto issue_869_2() -> issue_869_2_ret{
                                               issue_869_1 res {}; CPP2_UFCS(set_i)(res, cpp2_new<int>(0));
#line 378 "pure2-last-use.cpp2"
return res; }
#line 379 "pure2-last-use.cpp2"
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

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 

    if (true) {
      f_inout(x);
    }

    if (true) {
      if (true) {
        f_copy(std::move(x));
      }
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    if (true) {
      if (true) {
        f_inout(x);
        if (true) {
        }
        else {
          f_copy(std::move(x));
        }
      }
      else {
        if (true) {
        }
        else {
          f_inout(x);
        }
        f_copy(std::move(x));
      }
    }
    else {
      if (true) {
        if (true) {
          f_inout(x);
          f_copy(std::move(x));
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
            f_copy(std::move(x));
          }
          else {
          }
        }
        else {
          if (true) {
            f_copy(std::move(x));
          }
          else {
            f_copy(std::move(x));
          }
        }
      }
    }
  });
}

#line 776 "pure2-last-use.cpp2"
auto issue_888_0(std::string r, int size) -> void{
  static_cast<void>(CPP2_UFCS_MOVE(size)(std::move(r)));
}
#line 779 "pure2-last-use.cpp2"
auto issue_888_1([[maybe_unused]] std::string unnamed_param_1, move_only_function<int(int)> size) -> void{
  static_cast<void>(CPP2_UFCS_MOVE(size)(0));
}

#line 783 "pure2-last-use.cpp2"
auto issue_890() -> void{
  auto x {cpp2_new<int>(0)}; 
  if (cpp2::cpp2_default.is_active() && !(*cpp2::impl::assert_not_null(identity_copy(std::move(x))) == 0) ) { cpp2::cpp2_default.report_violation(""); }
{
auto const& x{cpp2_new<int>(0)};
#line 786 "pure2-last-use.cpp2"
  if (cpp2::cpp2_default.is_active() && !(*cpp2::impl::assert_not_null(identity(x)) == 0) ) { cpp2::cpp2_default.report_violation(""); }
}
#line 787 "pure2-last-use.cpp2"
}

#line 789 "pure2-last-use.cpp2"
auto issue_962(cpp2::impl::in<::std::string> s) -> void{
  using ::std::string;
  std::cout << ("A: " + cpp2::to_string(s)) << std::endl;
}

#line 794 "pure2-last-use.cpp2"
auto draw() -> void{
  auto pos {0}; 
  move_only_function<int(int)> vertex {}; 
  static_cast<void>(CPP2_UFCS_MOVE(vertex)((std::move(pos))));
}

#line 800 "pure2-last-use.cpp2"
auto enum_0() -> void{
    cpp2::impl::deferred_init<std::string> underlying_type; 
    if (true) {}
    underlying_type.construct("");
}
#line 805 "pure2-last-use.cpp2"
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
    while( *cpp2::impl::assert_not_null(identity(y)) ) {
        auto v {cpp2_new<int>(0)}; 
        f_copy(std::move(v));
    }

    auto z {cpp2_new<bool>(false)}; 
    do {
        auto v {cpp2_new<int>(0)}; 
        f_copy(std::move(v));
    } while ( *cpp2::impl::assert_not_null(identity(z)));
}
#line 833 "pure2-last-use.cpp2"
auto enum_2() -> void{
    auto umax {cpp2_new<int>(0)}; 
    if (pred(umax)) {
    }
    else {if (pred(umax)) {
    }
    else {if (pred_copy(std::move(umax))) {
    }}}
}

#line 844 "pure2-last-use.cpp2"
  auto cpp2_union::destroy() & -> void{}
#line 845 "pure2-last-use.cpp2"
  cpp2_union::~cpp2_union() noexcept{
    destroy();
    static_cast<void>(std::move((*this)));
  }

#line 856 "pure2-last-use.cpp2"
[[nodiscard]] auto no_pessimizing_move() -> no_pessimizing_move_ret{
                                                                std::unique_ptr<int> ret {};
#line 857 "pure2-last-use.cpp2"
return ret; }
#line 858 "pure2-last-use.cpp2"
auto deferred_non_copyable_0() -> void{
  cpp2::impl::deferred_init<std::unique_ptr<int>> p; 
  p.construct();
  f_copy(std::move(p.value()));
}

#line 864 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_1() -> auto{
  cpp2::impl::deferred_init<std::unique_ptr<int>> p; 
  p.construct();
  return std::move(p.value()); 
}

#line 870 "pure2-last-use.cpp2"
[[nodiscard]] auto deferred_non_copyable_2() -> deferred_non_copyable_2_ret{
      cpp2::impl::deferred_init<std::unique_ptr<int>> p;
#line 871 "pure2-last-use.cpp2"
  p.construct();
return std::move(p.value()); }

#line 874 "pure2-last-use.cpp2"
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

    [[maybe_unused]] auto const& unnamed_param_1 : { 0 } )  { do 
    {} while (false); f_inout(x); }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { 0 } ) 
    if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(get)(x)) ) { cpp2::cpp2_default.report_violation(""); }
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

#line 914 "pure2-last-use.cpp2"
auto f() -> void{
  auto x {cpp2_new<int>(0)}; 
  f_copy(std::move(x));
  auto id {[](auto const& x) mutable -> auto&& { return x;  }}; 
  auto y {cpp2_new<int>(0)}; 
  if (cpp2::cpp2_default.is_active() && !(&std::move(id)(y) == &y) ) { cpp2::cpp2_default.report_violation(""); }
}

#line 926 "pure2-last-use.cpp2"
  auto t::operator()() && -> void{
    f_copy(std::move(*this).x);
    static_cast<void>([&]() mutable -> void{
      // Should this move?
      // I.e., don't skip non-captured names, just rely on skipping hiding names.
      // An odr-use still requires capturing at Cpp1-time, and capturing would move.
      static_assert(std::is_same_v<decltype(x),std::unique_ptr<int>>);
      using captures::x;
      static_cast<void>(identity(x));
    });
  }

#line 939 "pure2-last-use.cpp2"
auto g() -> void{
  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(x));
    static_cast<void>([_0 = std::array<int,[](auto const& x) mutable -> auto { return identity(x); }(0)>()]() mutable -> auto { return _0;  });// Fails on Clang 12 (lambda in unevaluated context).
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    static_cast<void>([_0 = ([_0 = std::move(x)]() mutable -> auto { return *cpp2::impl::assert_not_null(_0); })]() mutable -> int { return _0();  });
  });
}

}

#line 955 "pure2-last-use.cpp2"
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

#line 971 "pure2-last-use.cpp2"
    [[maybe_unused]] auto const& unnamed_param_1 : { []() mutable -> auto{using captures::x;return x; } } ) 
    {}
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { [_0 = std::move(x)]() mutable -> auto { return *cpp2::impl::assert_not_null(_0); } } ) 
    {}
  });
}

#line 985 "pure2-last-use.cpp2"
  auto types::f() && -> void { static_cast<void>([&, _1 = std::move(*this).x]() mutable -> auto { return *cpp2::impl::assert_not_null(_1);  });  }
#line 986 "pure2-last-use.cpp2"
  auto types::g() && -> void{
    for ( 
    [[maybe_unused]] auto const& unnamed_param_1 : { [&, _1 = std::move(*this).x]() mutable -> auto { return *cpp2::impl::assert_not_null(_1); } } ) 
    {}
  }

#line 993 "pure2-last-use.cpp2"
auto skip_hidden_names() -> void{
  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(x));
{
auto x{cpp2_new<int>(0)};

#line 998 "pure2-last-use.cpp2"
      f_copy(std::move(x));
}
#line 999 "pure2-last-use.cpp2"
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
auto x{cpp2_new<int>(0)};

#line 1019 "pure2-last-use.cpp2"
      f_copy(std::move(x));
}
#line 1020 "pure2-last-use.cpp2"
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_inout(x);
    {
      f_copy(std::move(x));
      using captures::x;
      f_inout(x);
    }
  });

  static_cast<void>([]() mutable -> void{
    auto x {cpp2_new<int>(0)}; 
    f_copy(std::move(x));
    static_cast<void>([]() mutable -> void{
      static_assert(std::is_same_v<decltype(x),std::unique_ptr<int>>);
      using captures::x;
      f_inout(x);
    });
  });
}

#line 1043 "pure2-last-use.cpp2"
auto main(int const argc_, char** argv_) -> int{
  auto const args = cpp2::make_args(argc_, argv_); 
#line 1044 "pure2-last-use.cpp2"
  issue_683(args);
  issue_847_2(std::vector<std::unique_ptr<int>>());
  issue_847_5(args);
  issue_850();
  enum_0();
}

