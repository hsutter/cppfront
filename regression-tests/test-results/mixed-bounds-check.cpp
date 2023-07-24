

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


#include <vector>

#line 4 "mixed-bounds-check.cpp2"
[[nodiscard]] auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 4 "mixed-bounds-check.cpp2"
[[nodiscard]] auto main() -> int{
    std::set_terminate(std::abort);

    std::vector v {1, 2, 3, 4, 5, -999}; 
    CPP2_UFCS_0(pop_back, v);
    std::cout << cpp2::assert_in_bounds(std::move(v), 5) << "\n";
}

