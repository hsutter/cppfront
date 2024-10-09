
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-concept-definition-no-pitfall-2.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-concept-definition-no-pitfall-2.cpp2"
// https://youtu.be/CXn02MPkn8Y?t=2418
#line 2 "pure2-concept-definition-no-pitfall-2.cpp2"
template<typename T> concept int_sized = requires(T const& t) {

  sizeof(T) == 4;
};                    // Hopefully obviously wrong. Should be `requires (sizeof(T) == 4);`.
// Could also be `int_sized: <T> concept = sizeof(T) == 4;`.

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-concept-definition-no-pitfall-2.cpp2"

#line 8 "pure2-concept-definition-no-pitfall-2.cpp2"
auto main() -> int { static_assert(int_sized<char>);  }

