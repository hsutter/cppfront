
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-utf8-byte-order-mark.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-utf8-byte-order-mark.cpp2"
//  A UTF-8 byte order mark starts this file. cppfront drops it rather than
//  reading its bytes as source (they used to fail a debug CRT assertion)

#line 4 "pure2-utf8-byte-order-mark.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-utf8-byte-order-mark.cpp2"

#line 4 "pure2-utf8-byte-order-mark.cpp2"
auto main() -> int
{
    std::cout << "The byte order mark was skipped\n";
}

