// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-bounds-check.cpp2"

#include <vector>


//=== Cpp2 definitions ==========================================================

#line 3 "mixed-bounds-check.cpp2"

auto cpp2__main() -> void{
    std::vector v { 1, 2, 3, 4, 5 }; 
    std::cout << v[5] << "\n";
}
CPP2_MAIN_VOID_NO_ARGS

