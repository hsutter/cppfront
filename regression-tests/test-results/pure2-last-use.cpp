
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use.cpp2"

#line 41 "pure2-last-use.cpp2"
class issue_857;
  

#line 56 "pure2-last-use.cpp2"
class issue_857_2;
  

#line 61 "pure2-last-use.cpp2"
class issue_857_3;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use.cpp2"
[[nodiscard]] auto f_inout(int& x) -> auto;

#line 6 "pure2-last-use.cpp2"
auto issue_350() -> void;

#line 18 "pure2-last-use.cpp2"
auto issue_683(auto const& args) -> void;

#line 27 "pure2-last-use.cpp2"
auto issue_825() -> void;

#line 33 "pure2-last-use.cpp2"
auto issue_832() -> void;

#line 38 "pure2-last-use.cpp2"
auto f_inout([[maybe_unused]] std::unique_ptr<int>& unnamed_param_1) -> void;
auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void;

class issue_857 {
  private: std::unique_ptr<int> a; 
  private: std::unique_ptr<int> b; 
  public: issue_857(issue_857&& that) noexcept;
#line 44 "pure2-last-use.cpp2"
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
};

class issue_857_2 {
  public: std::unique_ptr<int> a; // OK: No error about 'a' being unused.
};

extern int gi;
class issue_857_3 {
  public: std::add_lvalue_reference_t<int> i {gi}; 
  public: auto f() && -> void;
};

//draw: () = {
//  pos       := 0;
//  vertex    := :(_) = { };
//  _ = (pos).vertex();
//}

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

auto f_inout([[maybe_unused]] std::unique_ptr<int>& unnamed_param_1) -> void{}
auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void{}

#line 44 "pure2-last-use.cpp2"
  issue_857::issue_857(issue_857&& that) noexcept
                                       : a{ std::move(that).a }
                                       , b{ std::move(that).b }{}
#line 44 "pure2-last-use.cpp2"
  auto issue_857::operator=(issue_857&& that) noexcept -> issue_857& {
                                       a = std::move(that).a;
                                       b = std::move(that).b;
                                       return *this; }
#line 45 "pure2-last-use.cpp2"
  issue_857::~issue_857() noexcept { f_copy(std::move(*this).a, std::move((*this)).b);  }
  auto issue_857::f() && -> void { f_copy(std::move((*this)));  }
  auto issue_857::f(issue_857&& that) && -> void { f_copy(std::move((*this)), std::move(that));  }
  auto issue_857::g() && -> void { f_copy(std::move((*this)).a);  }
  auto issue_857::g(issue_857&& that) && -> void { f_copy(std::move((*this)).a, std::move(that).a);  }
  auto issue_857::h() & -> void { f_inout(a);  }
  auto issue_857::i() && -> void { f_copy(std::move(*this).a);  }
  auto issue_857::j() && -> void { f_copy(std::move(*this).a);  }
  auto issue_857::k() && -> void { f_copy(std::move(*this).a, std::move(*this).b);  }

#line 60 "pure2-last-use.cpp2"
int gi {0}; 

#line 63 "pure2-last-use.cpp2"
  auto issue_857_3::f() && -> void { static_cast<void>(f_inout(std::move(*this).i));  }

#line 72 "pure2-last-use.cpp2"
auto main(int const argc_, char** argv_) -> int{
  auto const args = cpp2::make_args(argc_, argv_); 
#line 73 "pure2-last-use.cpp2"
  issue_683(args);
}

