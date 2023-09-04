
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-max-munch.cpp2"
template<typename T> auto static constexpr v = 0;
auto main() -> int;


//=== Cpp2 function definitions =================================================


#line 2 "pure2-bugfix-for-max-munch.cpp2"
auto main() -> int { static_cast<void>(v<cpp2::i32> == v<cpp2::i64>);  }

