
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 3 "pure2-bugfix-for-ufcs-sfinae.cpp2"
class B;


//=== Cpp2 type definitions and function declarations ===========================

template<typename T> [[nodiscard]] auto f() -> std::type_identity_t<decltype(CPP2_UFCS_NONLOCAL(a)(T()))>;

class B {
      public: B() = default;
      public: B(B const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(B const&) -> void = delete;

#line 3 "pure2-bugfix-for-ufcs-sfinae.cpp2"
};

auto main() -> int;
  

//=== Cpp2 function definitions =================================================

template<typename T> [[nodiscard]] auto f() -> std::type_identity_t<decltype(CPP2_UFCS_NONLOCAL(a)(T()))>{}// Fails on Clang 12 (lambda in unevaluated context).

#line 5 "pure2-bugfix-for-ufcs-sfinae.cpp2"
auto main() -> int{
  auto g {[]<typename T>([[maybe_unused]] T const& param1) -> std::void_t<decltype(f<T>())>{}}; 
  static_assert(!(std::is_invocable_v<decltype(std::move(g)),B>));
}

