
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-non-local-initialization.cpp2"
template<auto L, auto R> class pair;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-non-local-initialization.cpp2"
template<auto L, auto R> class pair {
      public: pair() = default;
      public: pair(pair const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(pair const&) -> void = delete;

#line 1 "pure2-bugfix-for-non-local-initialization.cpp2"
};
auto g(cpp2::in<pair<cpp2::i32{0},cpp2::i32{0}>> x) -> void;
auto main() -> int;


//=== Cpp2 function definitions =================================================


#line 2 "pure2-bugfix-for-non-local-initialization.cpp2"
auto g(cpp2::in<pair<cpp2::i32{0},cpp2::i32{0}>> x) -> void{}
auto main() -> int{}

