
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-template-argument.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-template-argument.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-template-argument.cpp2"
auto main() -> int { 
#line 2 "pure2-bugfix-for-template-argument.cpp2"
    std::cout << cpp2::to_string(std::is_void_v<cpp2::i32*> && std::is_void_v<cpp2::i32 const>) + "\n";  }

