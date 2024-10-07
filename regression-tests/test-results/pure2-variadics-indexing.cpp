
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-variadics-indexing.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-variadics-indexing.cpp2"
template<typename ...T> [[nodiscard]] constexpr auto f0() -> decltype(auto);
// f1: <T...> () == :T...[0]::value_type = 4; // Pending #533.
// 'V...[0]' needs to be made an _id-expression_.
// f2: <V...: _> () == V...[0];
// f3: <V...: _> () == V...[0].front();
#line 6 "pure2-variadics-indexing.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-variadics-indexing.cpp2"
template<typename ...T> [[nodiscard]] constexpr auto f0() -> decltype(auto) { return T...[0]{32};  }

#line 6 "pure2-variadics-indexing.cpp2"
auto main() -> int{
  static_assert(f0<cpp2::i64>() == 32);
  // static_assert(f1<std::integral_constant<i16, 8>>() == 4);
  // static_assert(f2<2>() == 2);
  // static_assert(f3<(:std::array = (1))>() == 1);
}

