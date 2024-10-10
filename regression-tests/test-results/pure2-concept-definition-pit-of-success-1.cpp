
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-concept-definition-pit-of-success-1.cpp2"

#line 8 "pure2-concept-definition-pit-of-success-1.cpp2"
class s1;
class s2;

class s3;

class s4;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-concept-definition-pit-of-success-1.cpp2"
// https://quuxplusone.github.io/blog/2021/06/09/another-concepts-chest-mimic/
#line 2 "pure2-concept-definition-pit-of-success-1.cpp2"
template<typename T> concept has_a_but_not_b = requires(T const& t) {

                a(t);
  requires !requires { b(t);  };
};                    // In Cpp2, this works and does the correct thing.

class s1 {};
class s2 {};
auto a([[maybe_unused]] cpp2::impl::in<s2> unnamed_param_1) -> void;
class s3 {};
auto b([[maybe_unused]] cpp2::impl::in<s3> unnamed_param_1) -> void;
class s4 {};
auto a([[maybe_unused]] cpp2::impl::in<s4> unnamed_param_1) -> void;
auto b([[maybe_unused]] cpp2::impl::in<s4> unnamed_param_1) -> void;

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-concept-definition-pit-of-success-1.cpp2"

#line 10 "pure2-concept-definition-pit-of-success-1.cpp2"
auto a([[maybe_unused]] cpp2::impl::in<s2> unnamed_param_1) -> void{}

#line 12 "pure2-concept-definition-pit-of-success-1.cpp2"
auto b([[maybe_unused]] cpp2::impl::in<s3> unnamed_param_1) -> void{}

#line 14 "pure2-concept-definition-pit-of-success-1.cpp2"
auto a([[maybe_unused]] cpp2::impl::in<s4> unnamed_param_1) -> void{}
#line 15 "pure2-concept-definition-pit-of-success-1.cpp2"
auto b([[maybe_unused]] cpp2::impl::in<s4> unnamed_param_1) -> void{}

#line 17 "pure2-concept-definition-pit-of-success-1.cpp2"
auto main() -> int{
  static_assert(!(has_a_but_not_b<s1>));// as expected
  static_assert(has_a_but_not_b<s2>);  // as expected
  static_assert(!(has_a_but_not_b<s3>));// as expected
  static_assert(!(has_a_but_not_b<s4>));// pit of success!
}

