

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-default-arguments.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-default-arguments.cpp2"
auto cxx(int x, std::string y) -> void {}

#line 3 "mixed-default-arguments.cpp2"
auto cxx2(cpp2::impl::in<int> x, cpp2::impl::in<std::string> y) -> void;

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-default-arguments.cpp2"

#line 3 "mixed-default-arguments.cpp2"
auto cxx2(cpp2::impl::in<int> x, cpp2::impl::in<std::string> y) -> void{}

#line 5 "mixed-default-arguments.cpp2"
auto main() -> int{
 cxx(1, "test");
 cxx({}, {});
 cxx2(1, "test");
 cxx2({}, {});
}

