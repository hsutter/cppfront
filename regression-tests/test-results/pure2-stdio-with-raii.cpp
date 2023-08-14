
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


//  "A better C than C" ... ?
//
#line 4 "pure2-stdio-with-raii.cpp2"
[[nodiscard]] auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 4 "pure2-stdio-with-raii.cpp2"
[[nodiscard]] auto main() -> int{
    std::string s {"Fred"}; 
    auto myfile {cpp2::fopen("xyzzy", "w")}; 
    static_cast<void>(CPP2_UFCS(fprintf, std::move(myfile), "Hello %s with UFCS!", CPP2_UFCS_0(c_str, std::move(s))));
}

