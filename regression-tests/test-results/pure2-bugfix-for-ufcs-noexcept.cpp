
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-ufcs-noexcept.cpp2"
class t;
#line 2 "pure2-bugfix-for-ufcs-noexcept.cpp2"
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-ufcs-noexcept.cpp2"
class t {
#line 2 "pure2-bugfix-for-ufcs-noexcept.cpp2"
  public: virtual auto swap([[maybe_unused]] t const& that) noexcept -> void;
  public: t() = default;
  public: t(t const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(t const&) -> void = delete;

#line 3 "pure2-bugfix-for-ufcs-noexcept.cpp2"
};
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-ufcs-noexcept.cpp2"

#line 2 "pure2-bugfix-for-ufcs-noexcept.cpp2"
  auto t::swap([[maybe_unused]] t const& that) noexcept -> void{}// Non-`virtual` blocked on #508, idiomatic form on #507.

auto main() -> int{
  static_assert(noexcept(CPP2_UFCS(swap)(t(), t())));// Fails on Clang 12 (lambda in unevaluated context) and GCC 10 (static assertion failed)
}

