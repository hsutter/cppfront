
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-concept-definition-no-pitfall-3.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-concept-definition-no-pitfall-3.cpp2"
// https://youtu.be/CXn02MPkn8Y?t=2455
#line 2 "pure2-concept-definition-no-pitfall-3.cpp2"
template<typename T> concept nothrow_incrementable = requires(T& t) {

  noexcept(++t);
};                   // Hopefully obviously wrong. Should be `requires noexcept(t++);` or `{ t++ } !throws;`.

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-concept-definition-no-pitfall-3.cpp2"

#line 7 "pure2-concept-definition-no-pitfall-3.cpp2"
auto main() -> int{static_assert(nothrow_incrementable<char>); }

