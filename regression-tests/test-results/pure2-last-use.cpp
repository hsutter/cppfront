
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use.cpp2"

#line 57 "pure2-last-use.cpp2"
class issue_857;
  

#line 123 "pure2-last-use.cpp2"
class issue_857_2;
  

#line 128 "pure2-last-use.cpp2"
class issue_857_3;
  

#line 133 "pure2-last-use.cpp2"
class issue_857_4;
  

#line 147 "pure2-last-use.cpp2"
class issue_869;
  

#line 205 "pure2-last-use.cpp2"
class cpp2_union;
  

#line 213 "pure2-last-use.cpp2"
class my_string;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use.cpp2"
[[nodiscard]] auto f_inout(int& x) -> auto;

#line 6 "pure2-last-use.cpp2"
auto issue_350() -> void;

#line 18 "pure2-last-use.cpp2"
auto issue_440() -> void;

#line 26 "pure2-last-use.cpp2"
auto issue_683(auto const& args) -> void;

#line 35 "pure2-last-use.cpp2"
auto issue_825() -> void;

#line 41 "pure2-last-use.cpp2"
auto issue_832() -> void;

#line 46 "pure2-last-use.cpp2"
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
#line 60 "pure2-last-use.cpp2"
  public: auto operator=(issue_857&& that) noexcept -> issue_857& ;
  public: ~issue_857() noexcept;

#line 65 "pure2-last-use.cpp2"
  public: auto f() && -> void;
  public: auto f(issue_857&& that) && -> void;
  public: auto g() && -> void;
  public: auto g(issue_857&& that) && -> void;
  public: auto h() & -> void;
  public: auto i() && -> void;
  public: auto j() && -> void;
  public: auto k() && -> void;

#line 76 "pure2-last-use.cpp2"
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

#line 89 "pure2-last-use.cpp2"
  public: auto p1() && -> void;

#line 93 "pure2-last-use.cpp2"
  public: auto p2() && -> void;

#line 97 "pure2-last-use.cpp2"
  public: auto p3() && -> void;

#line 101 "pure2-last-use.cpp2"
  public: auto q() && -> void;

#line 105 "pure2-last-use.cpp2"
// FIXME
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
///*o4*/ else         { n(this); }
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

class issue_857_4 {
  public: std::add_pointer_t<int()> f; // TODO Use `std::move_only_function`.
  public: std::add_pointer_t<int(int)> g; // Ditto.
  public: auto h0() && -> void;
  public: auto h1() && -> void;
  public: auto h2(issue_857_4 const& that) && -> void;
  public: auto h3(issue_857_4 const& that) && -> void;
  public: auto h4(cpp2::in<int> x) && -> void;
  public: auto h5(cpp2::in<int> x) && -> void;
  public: auto h6(cpp2::in<int> x) && -> void;
  public: auto h7(cpp2::in<int> x) && -> void;
  public: auto h8(cpp2::in<int> x) && -> void;
};

class issue_869 {
private: std::aligned_storage_t<cpp2::max(sizeof(int))> _storage {}; private: cpp2::i8 _discriminator {-1}; public: [[nodiscard]] auto is_i() const& -> bool;
public: [[nodiscard]] auto i() const& -> int const&;
public: [[nodiscard]] auto i() & -> int&;
public: auto set_i(cpp2::in<int> _value) & -> void;
public: auto set_i(auto&& ..._args) & -> void;
private: auto _destroy() & -> void;
public: ~issue_869() noexcept;
public: explicit issue_869();
public: issue_869(issue_869 const& that);

public: issue_869(issue_869&& that) noexcept;
public: auto operator=(issue_869 const& that) -> issue_869& ;
public: auto operator=(issue_869&& that) noexcept -> issue_869& ;

#line 149 "pure2-last-use.cpp2"
};

auto issue_884_3() -> void;

#line 161 "pure2-last-use.cpp2"
auto issue_884() -> void;

#line 170 "pure2-last-use.cpp2"
auto issue_884_2() -> void;

#line 179 "pure2-last-use.cpp2"
auto issue_888(std::string r, int size) -> void;

#line 185 "pure2-last-use.cpp2"
auto draw() -> void;

#line 191 "pure2-last-use.cpp2"
auto enum_0() -> void;

#line 197 "pure2-last-use.cpp2"
auto enum_1() -> void;

#line 205 "pure2-last-use.cpp2"
class cpp2_union {
  public: auto destroy() & -> void;
  public: ~cpp2_union() noexcept;
  public: cpp2_union() = default;
  public: cpp2_union(cpp2_union const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(cpp2_union const&) -> void = delete;


#line 211 "pure2-last-use.cpp2"
};

class my_string {
  public: std::string string; 
  public: std::size_t size {CPP2_UFCS(size)(string)}; 
};

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

auto issue_440() -> void{
  cpp2::deferred_init<int> i; 
  if (true) {
    i.construct(1);
  }
  i.construct(2);
}

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

#line 60 "pure2-last-use.cpp2"
  issue_857::issue_857(issue_857&& that) noexcept
                                       : a{ std::move(that).a }
                                       , b{ std::move(that).b }{}
#line 60 "pure2-last-use.cpp2"
  auto issue_857::operator=(issue_857&& that) noexcept -> issue_857& {
                                       a = std::move(that).a;
                                       b = std::move(that).b;
                                       return *this; }
#line 61 "pure2-last-use.cpp2"
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

#line 127 "pure2-last-use.cpp2"
int gi {0}; 

#line 130 "pure2-last-use.cpp2"
  auto issue_857_3::f() && -> void { static_cast<void>(f_inout(std::move(*this).i));  }

#line 136 "pure2-last-use.cpp2"
  auto issue_857_4::h0() && -> void { static_cast<void>(std::move(*this).f());  }
  auto issue_857_4::h1() && -> void { static_cast<void>(CPP2_UFCS(f)(std::move((*this))));  }
  auto issue_857_4::h2(issue_857_4 const& that) && -> void { static_cast<void>(CPP2_UFCS_MOVE(f)(that));  }
  auto issue_857_4::h3(issue_857_4 const& that) && -> void { static_cast<void>(that.f);  }
  auto issue_857_4::h4(cpp2::in<int> x) && -> void { static_cast<void>(CPP2_UFCS_MOVE(g)(x));  }
  auto issue_857_4::h5(cpp2::in<int> x) && -> void { static_cast<void>(f() + CPP2_UFCS_MOVE(g)(x));  }
  auto issue_857_4::h6(cpp2::in<int> x) && -> void { static_cast<void>(CPP2_UFCS(g)(x) + std::move(*this).f());  }
  auto issue_857_4::h7(cpp2::in<int> x) && -> void { static_cast<void>(CPP2_UFCS(f)(std::move((*this))) + CPP2_UFCS(g)(x));  }// FIXME Moves `this` instead of `g`.
  auto issue_857_4::h8(cpp2::in<int> x) && -> void { static_cast<void>(CPP2_UFCS(g)(x) + CPP2_UFCS(f)(std::move((*this))));  }



  [[nodiscard]] auto issue_869::is_i() const& -> bool { return _discriminator == 0; }
[[nodiscard]] auto issue_869::i() const& -> int const& { 
                                           cpp2::Default.expects(is_i(), "");return *cpp2::assert_not_null(reinterpret_cast<int const*>(&_storage)); }
[[nodiscard]] auto issue_869::i() & -> int& { 
                                                 cpp2::Default.expects(is_i(), "");return *cpp2::assert_not_null(reinterpret_cast<int*>(&_storage)); }
auto issue_869::set_i(cpp2::in<int> _value) & -> void{if (!(is_i())) {_destroy();std::construct_at(reinterpret_cast<int*>(&_storage), _value);}else {*cpp2::assert_not_null(reinterpret_cast<int*>(&_storage)) = _value;}_discriminator = 0;}
auto issue_869::set_i(auto&& ..._args) & -> void{if (!(is_i())) {_destroy();std::construct_at(reinterpret_cast<int*>(&_storage), CPP2_FORWARD(_args)...);}else {*cpp2::assert_not_null(reinterpret_cast<int*>(&_storage)) = int{CPP2_FORWARD(_args)...};}_discriminator = 0;}
auto issue_869::_destroy() & -> void{
  if (_discriminator == 0) {std::destroy_at(reinterpret_cast<int*>(&_storage));}
  _discriminator = -1;
  }

  issue_869::~issue_869() noexcept{_destroy();static_cast<void>(std::move((*this)));}
issue_869::issue_869(){}
issue_869::issue_869(issue_869 const& that)
        : _storage{  }
        , _discriminator{ -1 }{
  if (CPP2_UFCS(is_i)(that)) {set_i(CPP2_UFCS(i)(that));}
  }


  issue_869::issue_869(issue_869&& that) noexcept
        : _storage{  }
        , _discriminator{ -1 }{
  if (CPP2_UFCS(is_i)(std::move(that))) {set_i(CPP2_UFCS(i)(std::move(that)));}
  }

  auto issue_869::operator=(issue_869 const& that) -> issue_869& {
  if (CPP2_UFCS(is_i)(that)) {set_i(CPP2_UFCS(i)(that));}
        return *this;
  }

  auto issue_869::operator=(issue_869&& that) noexcept -> issue_869& {
  if (CPP2_UFCS(is_i)(std::move(that))) {set_i(CPP2_UFCS(i)(std::move(that)));}
        return *this;
  }
#line 151 "pure2-last-use.cpp2"
auto issue_884_3() -> void{
  auto x {cpp2_new<int>(0)}; 
  if (true) {}
  if (true) {}
  {
    {f_inout(x); }
    f_copy(std::move(x));
  }
}

auto issue_884() -> void{
  auto x {cpp2_new<int>(0)}; 
  if (true) {}
  {
    {f_inout(x); }
    f_copy(std::move(x));
  }
}

auto issue_884_2() -> void{
  auto x {cpp2_new<int>(0)}; 
  if (true) {}
  {
    f_inout(x);
  }
  f_copy(std::move(x));
}

auto issue_888(std::string r, int size) -> void{
  // ...
  static_cast<void>(CPP2_UFCS_MOVE(size)(std::move(r)));
  // ...
}

auto draw() -> void{
  auto pos {0}; 
  auto vertex {[]([[maybe_unused]] auto const& unnamed_param_1) mutable -> void{}}; 
  static_cast<void>(CPP2_UFCS_MOVE(vertex)((std::move(pos))));
}

auto enum_0() -> void{
  cpp2::deferred_init<int> underlying_type; 
  if (true) {}
  underlying_type.construct(0);
}

auto enum_1() -> void{
  cpp2::deferred_init<int> underlying_type; 
  if (true) {
    underlying_type.construct(0);
  }
  underlying_type.construct(0);
}

#line 206 "pure2-last-use.cpp2"
  auto cpp2_union::destroy() & -> void{}
  cpp2_union::~cpp2_union() noexcept{
    destroy();
    static_cast<void>(std::move((*this)));
  }

#line 218 "pure2-last-use.cpp2"
auto main(int const argc_, char** argv_) -> int{
  auto const args = cpp2::make_args(argc_, argv_); 
#line 219 "pure2-last-use.cpp2"
  issue_683(args);
  issue_847_2(std::vector<std::unique_ptr<int>>());
}

