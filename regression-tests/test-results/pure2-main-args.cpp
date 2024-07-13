
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-main-args.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-main-args.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-main-args.cpp2"
auto main(int const argc_, char** argv_) -> int{
    auto const args = cpp2::make_args(argc_, argv_); 
    // Explicit call to string is necessary
    // std::filesystem::path is base on and implicitly convertible to
    // - std::string (on POSIX systems)
    // - std::wstring (on Windows)
#line 6 "pure2-main-args.cpp2"
    auto exe {CPP2_UFCS(string)(CPP2_UFCS(filename)(std::filesystem::path(CPP2_ASSERT_IN_BOUNDS_LITERAL(args.argv, 0))))}; 
    std::cout 
        << "args.argc            is " + cpp2::to_string(args.argc) + "\n" 
        << "args.argv[0]         is " + cpp2::to_string(cpp2::move(exe)) + "\n";

}

