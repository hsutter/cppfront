
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-contracts.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-contracts.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-contracts.cpp2"
auto main() -> int{
#line 2 "pure2-contracts.cpp2"
    cpp2::Default.expects(1 != 2, "ack, arithmetic is buggy");
    cpp2::Type.expects(typeid(int) != typeid(double), "ack, C types are broken");

}

