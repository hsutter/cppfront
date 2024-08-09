
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-default-arguments.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-default-arguments.cpp2"

//  Note: Using source_location requires GCC 11 or higher,
//        Clang 16 or higher, MSVC 2019 16.10 or higher.
//        Older compilers will emit failures for this test case.
#line 5 "pure2-default-arguments.cpp2"
auto my_function_name(
    char const* fn = CPP2_UFCS_NONLOCAL(function_name)(std::source_location::current())
    ) -> void;

#line 12 "pure2-default-arguments.cpp2"
auto f(cpp2::impl::in<cpp2::i32> x = 0) -> void;

auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-default-arguments.cpp2"

#line 5 "pure2-default-arguments.cpp2"
auto my_function_name(
    char const* fn
    ) -> void
{
    std::cout << "calling: " + cpp2::to_string(fn) + "\n";
}

#line 12 "pure2-default-arguments.cpp2"
auto f(cpp2::impl::in<cpp2::i32> x) -> void{std::cout << x; }

#line 14 "pure2-default-arguments.cpp2"
auto main(int const argc_, char** argv_) -> int{
    auto const args = cpp2::make_args(argc_, argv_); 
#line 15 "pure2-default-arguments.cpp2"
    my_function_name();
    f();
    f(1);
    f(2);
}

