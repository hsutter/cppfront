

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-default-arguments.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-default-arguments.cpp2"
auto cxx(int x, std::string y) -> void {
    std::cout << x << " \"" << y << "\"" << "\n";
}

#line 5 "mixed-default-arguments.cpp2"
auto cxx2(cpp2::impl::in<int> x, cpp2::impl::in<std::string> y) -> void;

#line 9 "mixed-default-arguments.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-default-arguments.cpp2"

#line 5 "mixed-default-arguments.cpp2"
auto cxx2(cpp2::impl::in<int> x, cpp2::impl::in<std::string> y) -> void{
    std::cout << (cpp2::to_string(x) + " \"" + cpp2::to_string(y) + "\"\n");
}

#line 9 "mixed-default-arguments.cpp2"
auto main() -> int{
 cxx(1, "test");
 cxx({}, {});
 cxx2(1, "test");
 cxx2({}, {});
}

