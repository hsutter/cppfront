
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-concept-definition-no-pitfall-1.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-concept-definition-no-pitfall-1.cpp2"
// https://youtu.be/CXn02MPkn8Y?t=2337
#line 2 "pure2-concept-definition-no-pitfall-1.cpp2"
template<typename T> concept negatable = requires(T const& t) {

  cpp2::impl::is<T>(-t);
};             // Hopefully obviously wrong. Should be `{ -t } is T;`.

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-concept-definition-no-pitfall-1.cpp2"

#line 7 "pure2-concept-definition-no-pitfall-1.cpp2"
auto main() -> int { static_assert(negatable<char>);  }

