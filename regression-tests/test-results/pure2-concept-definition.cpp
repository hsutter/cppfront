
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-concept-definition.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-concept-definition.cpp2"
template<typename T> concept arithmetic = std::integral<T> || std::floating_point<T>; 

#line 3 "pure2-concept-definition.cpp2"
template<typename T> using number_difference_t = std::type_identity_t<decltype(T() - T())>;
template<typename T> concept number = std::regular<T> && requires(T const& c) {

  requires !requires { typename std::iter_reference_t<T>;  };// Negative requirement.
  { c + c } -> std::common_with<T>;                     // Compound requirement.
  typename number_difference_t<T>;                      // Type requirement.
  c - c;                                                // Expression requirement.
  requires std::common_with<number_difference_t<T>,T>;
};                                                      // Nested requirement.

template<typename T> concept test_nonthrowing_requirements = requires {
  // clang-format off
  { T() } noexcept;
  { -T() } noexcept -> std::same_as<T>;
}; // clang-format on

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-concept-definition.cpp2"

#line 19 "pure2-concept-definition.cpp2"
auto main() -> int{
  static_assert(arithmetic<cpp2::i32>);
  static_assert(arithmetic<float>);
  static_assert(number<cpp2::i32>);
  static_assert(number<float>);
  static_assert(number<std::chrono::seconds>);
  static_assert(!(number<cpp2::i32*>));
  static_assert(!(number<std::reverse_iterator<cpp2::i32*>>));
  static_assert(test_nonthrowing_requirements<cpp2::i32>);
  static_assert(!(test_nonthrowing_requirements<std::chrono::seconds>));
}

