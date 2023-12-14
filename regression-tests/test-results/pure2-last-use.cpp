
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use.cpp2"

#line 57 "pure2-last-use.cpp2"
class issue_857;
  

#line 97 "pure2-last-use.cpp2"
class issue_857_2;
  

#line 102 "pure2-last-use.cpp2"
class issue_857_3;
  

#line 148 "pure2-last-use.cpp2"
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
  public: auto f() && -> void;
  public: auto f(issue_857&& that) && -> void;
  public: auto g() && -> void;
  public: auto g(issue_857&& that) && -> void;
  public: auto h() & -> void;
  public: auto i() && -> void;
  public: auto j() && -> void;
  public: auto k() && -> void;
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

#line 83 "pure2-last-use.cpp2"
  public: auto p1() && -> void;

#line 87 "pure2-last-use.cpp2"
  public: auto p2() && -> void;

#line 91 "pure2-last-use.cpp2"
  public: auto p3() && -> void;

#line 95 "pure2-last-use.cpp2"
};

class issue_857_2 {
  public: std::unique_ptr<int> a; // OK: No error about 'a' being unused.
};

extern int gi;
class issue_857_3 {
  public: std::add_lvalue_reference_t<int> i {gi}; 
  public: auto f() && -> void;
};

#line 108 "pure2-last-use.cpp2"
auto issue_884_3() -> void;

#line 118 "pure2-last-use.cpp2"
auto issue_884() -> void;

#line 127 "pure2-last-use.cpp2"
auto issue_884_2() -> void;

#line 136 "pure2-last-use.cpp2"
auto issue_888(std::string r, int size) -> void;

#line 142 "pure2-last-use.cpp2"
auto draw() -> void;

#line 148 "pure2-last-use.cpp2"
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
  issue_857::~issue_857() noexcept { f_copy(std::move(*this).a, std::move((*this)).b);  }
  auto issue_857::f() && -> void { f_copy(std::move((*this)));  }
  auto issue_857::f(issue_857&& that) && -> void { f_copy(std::move((*this)), std::move(that));  }
  auto issue_857::g() && -> void { f_copy(std::move((*this)).a);  }
  auto issue_857::g(issue_857&& that) && -> void { f_copy(std::move((*this)).a, std::move(that).a);  }
  auto issue_857::h() & -> void { f_inout(a);  }
  auto issue_857::i() && -> void { f_copy(std::move(*this).a);  }
  auto issue_857::j() && -> void { f_copy(std::move(*this).a);  }
  auto issue_857::k() && -> void { f_copy(std::move(*this).a, std::move(*this).b);  }
  auto issue_857::l() && -> void { std::move(*this).k();  }
  auto issue_857::m() && -> void { CPP2_UFCS(k)(std::move((*this)));  }
  auto issue_857::n([[maybe_unused]] auto const& unnamed_param_1) -> void{}
  auto issue_857::n() && -> void{}
  auto issue_857::o0() && -> void { std::move(*this).n();  }
  auto issue_857::o1() && -> void { CPP2_UFCS(n)(std::move((*this)));  }
  auto issue_857::o2() && -> void { CPP2_UFCS(n)(0);  }
  auto issue_857::o3() && -> void { std::move(*this).n(0);  }
  auto issue_857::o4() && -> void { std::move(*this).n(std::move((*this)));  }
  auto issue_857::p0() && -> void{
    f_inout(a);
    f_copy(std::move((*this)).a);
  }
  auto issue_857::p1() && -> void{
  //f_inout(this.a); // FIXME Moves `a`.
    f_copy(std::move(*this).a);
  }
  auto issue_857::p2() && -> void{
  //f_inout(a); // FIXME Moves `a`.
    f_copy(std::move((*this)));
  }
  auto issue_857::p3() && -> void{
  //f_inout(this); // FIXME Moves `this`.
    f_copy(std::move(*this).a);
  }

#line 101 "pure2-last-use.cpp2"
int gi {0}; 

#line 104 "pure2-last-use.cpp2"
  auto issue_857_3::f() && -> void { static_cast<void>(f_inout(std::move(*this).i));  }

#line 108 "pure2-last-use.cpp2"
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

#line 153 "pure2-last-use.cpp2"
auto main(int const argc_, char** argv_) -> int{
  auto const args = cpp2::make_args(argc_, argv_); 
#line 154 "pure2-last-use.cpp2"
  issue_683(args);
  issue_847_2(std::vector<std::unique_ptr<int>>());
}

