
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-max-munch.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-max-munch.cpp2"
template<typename T> auto inline constexpr v{ 0 };
#line 2 "pure2-bugfix-for-max-munch.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-max-munch.cpp2"

#line 2 "pure2-bugfix-for-max-munch.cpp2"
auto main() -> int { static_cast<void>(v<cpp2::i32> == v<cpp2::i64>);  }

