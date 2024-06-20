
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-trailing-comma-assert.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-trailing-comma-assert.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-trailing-comma-assert.cpp2"
auto main() -> int{
#line 2 "pure2-trailing-comma-assert.cpp2"
    if (cpp2::cpp2_default.is_active() && !(true) ) { cpp2::cpp2_default.report_violation(CPP2_CONTRACT_MSG("some_potentially_long_string")); }
}

