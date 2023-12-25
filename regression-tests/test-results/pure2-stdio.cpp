
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-stdio.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-stdio.cpp2"

//  "A better C than C" ... ?
//
#line 4 "pure2-stdio.cpp2"
[[nodiscard]] auto main() -> int;
#line 10 "pure2-stdio.cpp2"

#line 1 "pure2-stdio.cpp2"

//=== Cpp2 function definitions =================================================

#line 1 "pure2-stdio.cpp2"

#line 4 "pure2-stdio.cpp2"
[[nodiscard]] auto main() -> int{
    std::string s {"Fred"}; 
    auto myfile {fopen("xyzzy", "w")}; 
    static_cast<void>(CPP2_UFCS(fprintf)(myfile, "Hello %s with UFCS!", CPP2_UFCS(c_str)(std::move(s))));
    static_cast<void>(CPP2_UFCS(fclose)(std::move(myfile)));
}

