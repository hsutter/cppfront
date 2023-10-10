
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

template<typename T> auto inline constexpr v = 0;
auto main() -> int;


//=== Cpp2 function definitions =================================================


#line 2 "pure2-bugfix-for-max-munch.cpp2"
auto main() -> int { static_cast<void>(v<cpp2::i32> == v<cpp2::i64>);  }

