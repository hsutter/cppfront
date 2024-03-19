
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-statement-scope-parameters.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-statement-scope-parameters.cpp2"

#line 2 "pure2-statement-scope-parameters.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-statement-scope-parameters.cpp2"

#line 2 "pure2-statement-scope-parameters.cpp2"
auto main(int const argc_, char** argv_) -> int{
    auto const args = cpp2::make_args(argc_, argv_); 
#line 3 "pure2-statement-scope-parameters.cpp2"
    auto local_int {42}; 
{
auto const& i{local_int};

    //  'in' (read-only) statement scope variable
#line 6 "pure2-statement-scope-parameters.cpp2"
    for ( [[maybe_unused]] auto const& unnamed_param_1 : args ) {
        std::cout << i << "\n";     // prints 42
    }
}
{
auto& i{local_int};

    //  'inout' (read-write) statement scope variable
#line 11 "pure2-statement-scope-parameters.cpp2"
    {
        ++i;
    }
}
#line 14 "pure2-statement-scope-parameters.cpp2"
    std::cout << cpp2::move(local_int) << "\n";// prints 43

    std::chrono::duration<cpp2::i32> auto_1 {0}; 
{
[[maybe_unused]] std::chrono::duration<cpp2::i32> unnamed_param_1{0};
#line 17 "pure2-statement-scope-parameters.cpp2"
    {}
}
#line 18 "pure2-statement-scope-parameters.cpp2"
    std::in_place_t auto_2 {}; 
{
[[maybe_unused]] std::in_place_t unnamed_param_1{};
#line 19 "pure2-statement-scope-parameters.cpp2"
    {}
}
#line 20 "pure2-statement-scope-parameters.cpp2"
}

