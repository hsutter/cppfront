
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

auto main() -> int;
    

//=== Cpp2 function definitions =================================================

auto main() -> int { 
    std::cout << cpp2::to_string(std::is_void_v<cpp2::i32*> && std::is_void_v<cpp2::i32 const>) + "\n";  }

