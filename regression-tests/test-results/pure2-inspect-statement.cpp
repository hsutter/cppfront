

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

extern std::any v;

[[nodiscard]] auto f() -> int;
    

#line 10 "pure2-inspect-statement.cpp2"
auto main() -> int;


//=== Cpp2 function definitions =================================================

std::any v {}; 

[[nodiscard]] auto f() -> int
    { auto&& _expr = v;
        if (cpp2::is(_expr, 1)) return 1;
        else if (cpp2::is<int>(_expr)) return 2;
        else return 3;
    }

auto main() -> int
{
    v = 1;
    cpp2::Default.expects(f() == 1, "");
    v = 10;
    cpp2::Default.expects(f() == 2, "");
    v = true;
    cpp2::Default.expects(f() == 3, "");
}

