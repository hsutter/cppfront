
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-last-use.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-last-use.cpp2"
auto issue_683(auto const& args) -> void;

#line 10 "pure2-last-use.cpp2"
auto issue_832() -> void;

#line 15 "pure2-last-use.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-last-use.cpp2"
auto issue_683(auto const& args) -> void{
#line 2 "pure2-last-use.cpp2"
    for ( auto const& n : args ) {
        static_cast<void>(n);
    }

    cpp2::deferred_init<int> n; 
    n.construct(0);
}

auto issue_832() -> void{
  auto i {0}; 
  while( i ) {}
}

auto main(int const argc_, char** argv_) -> int{
  auto const args = cpp2::make_args(argc_, argv_); 
#line 16 "pure2-last-use.cpp2"
  issue_683(args);
}

