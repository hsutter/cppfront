
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use.cpp2"

#line 40 "pure2-last-use.cpp2"
class issue_857;
  

#line 53 "pure2-last-use.cpp2"
class issue_857_2;
  

#line 58 "pure2-last-use.cpp2"
class issue_857_3;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use.cpp2"
[[nodiscard]] auto f_inout(auto& x) -> auto;

#line 6 "pure2-last-use.cpp2"
auto issue_350() -> void;

#line 18 "pure2-last-use.cpp2"
auto issue_683(auto const& args) -> void;

#line 27 "pure2-last-use.cpp2"
auto issue_825() -> void;

#line 33 "pure2-last-use.cpp2"
auto issue_832() -> void;

#line 38 "pure2-last-use.cpp2"
auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void;

class issue_857 {
  public: std::unique_ptr<int> a; 
  public: std::unique_ptr<int> b; 
  public: auto f() && -> void;
  public: auto f(issue_857&& that) && -> void;
  public: auto g() && -> void;
  public: auto g(issue_857&& that) && -> void;
//h: (move this) = f_copy(this.a, this.b);
  public: auto i() && -> void;
  public: auto j() && -> void;
  public: auto k() && -> void;
};

class issue_857_2 {
  public: std::unique_ptr<int> a; // OK: No error about 'a' being unused.
};

extern int gi;
class issue_857_3 {
  public: std::pair<std::unique_ptr<int>,std::add_lvalue_reference_t<int>> p {
    cpp2_new<int>(0), gi}; 
  public: auto f() && -> void;

#line 65 "pure2-last-use.cpp2"
};

//draw: () = {
//  pos       := 0;
//  vertex    := :(_) = { };
//  _ = (pos).vertex();
//}

auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-last-use.cpp2"
[[nodiscard]] auto f_inout(auto& x) -> auto{
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

auto f_copy([[maybe_unused]] auto ...unnamed_param_1) -> void{}

#line 43 "pure2-last-use.cpp2"
  auto issue_857::f() && -> void { f_copy(std::move((*this)));  }
  auto issue_857::f(issue_857&& that) && -> void { f_copy(std::move((*this)), std::move(that));  }
  auto issue_857::g() && -> void { f_copy(std::move((*this)).a);  }
  auto issue_857::g(issue_857&& that) && -> void { f_copy(std::move((*this)).a, std::move(that).a);  }

  auto issue_857::i() && -> void { f_copy(std::move(*this).a);  }
  auto issue_857::j() && -> void { f_copy(std::move(*this).a);  }
  auto issue_857::k() && -> void { f_copy(std::move(*this).a, std::move(*this).b);  }

#line 57 "pure2-last-use.cpp2"
int gi {0}; 

#line 61 "pure2-last-use.cpp2"
  auto issue_857_3::f() && -> void{
    // f_copy(p.first);
    static_cast<void>(f_inout(std::move(*this).p.second));
  }

#line 73 "pure2-last-use.cpp2"
auto main(int const argc_, char** argv_) -> int{
  auto const args = cpp2::make_args(argc_, argv_); 
#line 74 "pure2-last-use.cpp2"
  issue_683(args);
}

