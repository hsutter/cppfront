
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

struct vals_ret { int i; };

[[nodiscard]] auto vals() -> vals_ret;
    

#line 6 "pure2-bugfix-for-name-lookup-and-value-decoration.cpp2"
[[nodiscard]] auto main() -> int;
    

//=== Cpp2 function definitions =================================================

[[nodiscard]] auto vals() -> vals_ret{
        cpp2::deferred_init<int> i;
#line 2 "pure2-bugfix-for-name-lookup-and-value-decoration.cpp2"
    i.construct(42);
    return  { std::move(i.value()) }; 
}

[[nodiscard]] auto main() -> int{
    auto v {vals()}; 
    std::move(v).i;
}

