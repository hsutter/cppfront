
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


//  "A better C than C" ... ?
//
#line 4 "pure2-stdio.cpp2"
[[nodiscard]] auto main() -> int;
    
#line 10 "pure2-stdio.cpp2"


//=== Cpp2 function definitions =================================================


#line 4 "pure2-stdio.cpp2"
[[nodiscard]] auto main() -> int{
    std::string s {"Fred"}; 
    auto myfile {fopen("xyzzy", "w")}; 
    static_cast<void>(CPP2_UFCS(fprintf, myfile, "Hello %s with UFCS!", CPP2_UFCS_0(c_str, std::move(s))));
    static_cast<void>(CPP2_UFCS_0(fclose, std::move(myfile)));
}

