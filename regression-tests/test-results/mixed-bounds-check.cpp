// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-bounds-check.cpp2"

#include <vector>

[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 3 "mixed-bounds-check.cpp2"

[[nodiscard]] auto main() -> int{
    std::vector v { 1, 2, 3, 4, 5 }; 
    std::cout << v[5] << "\n";
}
