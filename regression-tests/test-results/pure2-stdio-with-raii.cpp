// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 4 "pure2-stdio-with-raii.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-stdio-with-raii.cpp2"

//  "A better C than C" ... ?
//
[[nodiscard]] auto main() -> int{
    std::string s { "Freddy" }; 
    auto myfile { cpp2::fopen("xyzzy", "w") }; 
    CPP2_UFCS(fprintf, myfile, "Hello %s with UFCS!", CPP2_UFCS_0(c_str, s));
}
