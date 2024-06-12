

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-bounds-check.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-bounds-check.cpp2"

#include <vector>

#line 4 "mixed-bounds-check.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-bounds-check.cpp2"

#line 4 "mixed-bounds-check.cpp2"
[[nodiscard]] auto main() -> int{
    std::set_terminate(std::abort);

    std::vector v {1, 2, 3, 4, 5, -999}; 
    CPP2_UFCS(pop_back)(v);
    std::cout << CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(v), 5) << "\n";
}

