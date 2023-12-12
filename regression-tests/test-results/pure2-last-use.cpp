
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use.cpp2"

#line 40 "pure2-last-use.cpp2"
class issue_857;
  

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
auto f_copy([[maybe_unused]] auto unnamed_param_1) -> void;

class issue_857 {
  public: std::unique_ptr<int> i; 
  public: auto f() && -> void;
  public: auto g() && -> void;
//h: (move this) = f_copy(i);
};

auto draw() -> void;

#line 53 "pure2-last-use.cpp2"
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

auto f_copy([[maybe_unused]] auto unnamed_param_1) -> void{}

#line 42 "pure2-last-use.cpp2"
  auto issue_857::f() && -> void { f_copy(std::move((*this)));  }
  auto issue_857::g() && -> void { f_copy(std::move((*this)).i);  }

#line 47 "pure2-last-use.cpp2"
auto draw() -> void{
  auto pos {0}; 
  auto vertex {[]([[maybe_unused]] auto const& unnamed_param_1) mutable -> void{}}; 
  static_cast<void>(CPP2_UFCS(std::move(vertex))((std::move(pos))));
}

auto main(int const argc_, char** argv_) -> int{
  auto const args = cpp2::make_args(argc_, argv_); 
#line 54 "pure2-last-use.cpp2"
  issue_683(args);
}

