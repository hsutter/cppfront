
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-statement-scope-parameters.cpp2"
auto main(int const argc_, char const* const* const argv_) -> int;
    

//=== Cpp2 function definitions =================================================


#line 2 "pure2-statement-scope-parameters.cpp2"
auto main(int const argc_, char const* const* const argv_) -> int{
    auto args = cpp2::make_args(argc_, argv_); 
#line 3 "pure2-statement-scope-parameters.cpp2"
    auto local_int {42}; 
{
auto const& i = local_int;

    //  'in' (read-only) statement scope variable
#line 6 "pure2-statement-scope-parameters.cpp2"
    for ( auto const& arg : args ) {
        std::cout << i << "\n";     // prints 42
    }
}
{
auto& i = local_int;

    //  'inout' (read-write) statement scope variable
#line 11 "pure2-statement-scope-parameters.cpp2"
    {
        ++i;
    }
}
#line 14 "pure2-statement-scope-parameters.cpp2"
    std::cout << std::move(local_int) << "\n";// prints 43
}

