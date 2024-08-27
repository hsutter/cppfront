
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-ufcs-sfinae.cpp2"

#line 3 "pure2-bugfix-for-ufcs-sfinae.cpp2"
class B;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-ufcs-sfinae.cpp2"
template<typename T> [[nodiscard]] auto f() -> std::type_identity_t<decltype(CPP2_UFCS_NONLOCAL(a)(T()))>;

#line 3 "pure2-bugfix-for-ufcs-sfinae.cpp2"
class B {
      public: B() = default;
      public: B(B const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(B const&) -> void = delete;
};
#line 4 "pure2-bugfix-for-ufcs-sfinae.cpp2"

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-ufcs-sfinae.cpp2"
template<typename T> [[nodiscard]] auto f() -> std::type_identity_t<decltype(CPP2_UFCS_NONLOCAL(a)(T()))>{}// Fails on Clang 12 (lambda in unevaluated context).

#line 5 "pure2-bugfix-for-ufcs-sfinae.cpp2"
auto main() -> int{
  auto g {[]<typename T>([[maybe_unused]] T const& unnamed_param_1) -> std::void_t<decltype(f<T>())>{}}; 
  static_assert(!(std::is_invocable_v<decltype(cpp2::move(g)),B>));
}

