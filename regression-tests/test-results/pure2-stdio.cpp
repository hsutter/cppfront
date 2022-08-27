// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 4 "pure2-stdio.cpp2"
[[nodiscard]] auto main() -> int;
#line 10 "pure2-stdio.cpp2"


//=== Cpp2 definitions ==========================================================

#line 1 "pure2-stdio.cpp2"

//  "A better C than C" ... ?
//
[[nodiscard]] auto main() -> int{
    std::string s { "Fred" }; 
    auto myfile { fopen("xyzzy", "w") }; 
    CPP2_UFCS(fprintf, myfile, "Hello %s with UFCS!", CPP2_UFCS_0(c_str, s));
    CPP2_UFCS_0(fclose, myfile);
}
