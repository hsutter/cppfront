

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

auto main() -> int;


//=== Cpp2 function definitions =================================================

auto main() -> int
{
    using T = int;
    auto b {bool(cpp2::is<T*, int*>())}; 
    cpp2::Default.expects(b, "");

    b = bool(cpp2::is<bool, T>());
    cpp2::Default.expects(!(b), "");

    b = bool(cpp2::is<T, long>());
    cpp2::Default.expects(!(b), "");

    b = bool(cpp2::is<std::runtime_error, std::exception>());
    cpp2::Default.expects(b, "");

    b = bool(cpp2::is<std::exception, std::runtime_error>());
    cpp2::Default.expects(!(std::move(b)), "");
}

