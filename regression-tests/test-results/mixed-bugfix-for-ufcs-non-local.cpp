

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-bugfix-for-ufcs-non-local.cpp2"

#line 9 "mixed-bugfix-for-ufcs-non-local.cpp2"
namespace ns {

#line 39 "mixed-bugfix-for-ufcs-non-local.cpp2"
class u;
  

#line 45 "mixed-bugfix-for-ufcs-non-local.cpp2"
}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-bugfix-for-ufcs-non-local.cpp2"
namespace ns {

template<bool> struct t { };
constexpr bool f(const t<true>&) { return true; }
constexpr t<true> o{};

} // namespace ns

#line 9 "mixed-bugfix-for-ufcs-non-local.cpp2"
namespace ns {

// Variables.

template<t<CPP2_UFCS_NONLOCAL(f)(o)> UnnamedTypeParam1_1> bool inline constexpr v0{ false };// Fails on GCC ([GCC109781][]) and Clang 12 (a lambda expression cannot appear in this context)

t<CPP2_UFCS_NONLOCAL(f)(o)> inline constexpr v1{ t<true>() };// Fails on Clang 12 (lambda in unevaluated context).

bool inline constexpr v2{ CPP2_UFCS_NONLOCAL(f)(o) };

// Functions.

template<t<CPP2_UFCS_NONLOCAL(f)(o)> UnnamedTypeParam1_2> auto g() -> void;

auto g([[maybe_unused]] cpp2::impl::in<t<CPP2_UFCS_NONLOCAL(f)(o)>> unnamed_param_1) -> void;

auto g() -> void;

[[nodiscard]] auto h() -> t<CPP2_UFCS_NONLOCAL(f)(o)>;

// Aliases.

template<t<CPP2_UFCS_NONLOCAL(f)(o)> UnnamedTypeParam1_3> using a = bool;// Fails on GCC ([GCC109781][]) and Clang 12 (a lambda expression cannot appear in this context)

template<t<CPP2_UFCS_NONLOCAL(f)(o)> UnnamedTypeParam1_4> auto inline constexpr b{ false };// Fails on GCC ([GCC109781][]).

using c = t<CPP2_UFCS_NONLOCAL(f)(o)>;// Fails on Clang 12 (lambda in unevaluated context) and Clang 12 (a lambda expression cannot appear in this context)

auto inline constexpr d{ t<CPP2_UFCS_NONLOCAL(f)(o)>() };// Fails on Clang 12 (lambda in unevaluated context).

class u {
  public: static const bool b;
  public: static const bool c;
  public: static auto g(auto const& s, auto const& sz) -> void;
};

} // namespace ns

auto main() -> int;

// [GCC109781]: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=109781


//=== Cpp2 function definitions =================================================

#line 1 "mixed-bugfix-for-ufcs-non-local.cpp2"

#line 9 "mixed-bugfix-for-ufcs-non-local.cpp2"
namespace ns {

#line 21 "mixed-bugfix-for-ufcs-non-local.cpp2"
template<t<CPP2_UFCS_NONLOCAL(f)(o)> UnnamedTypeParam1_2> auto g() -> void{}// Fails on GCC ([GCC109781][]) and Clang 12 (a lambda expression cannot appear in this context)

#line 23 "mixed-bugfix-for-ufcs-non-local.cpp2"
auto g([[maybe_unused]] cpp2::impl::in<t<CPP2_UFCS_NONLOCAL(f)(o)>> unnamed_param_1) -> void{}// Fails on Clang 12 (lambda in unevaluated context).

#line 25 "mixed-bugfix-for-ufcs-non-local.cpp2"
auto g() -> void{
                     if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(f)(o)) ) { cpp2::cpp2_default.report_violation(""); }}

#line 27 "mixed-bugfix-for-ufcs-non-local.cpp2"
[[nodiscard]] auto h() -> t<CPP2_UFCS_NONLOCAL(f)(o)> { return o;  }// Fails on Clang 12 (lambda in unevaluated context).

#line 40 "mixed-bugfix-for-ufcs-non-local.cpp2"
  inline CPP2_CONSTEXPR bool u::b{ CPP2_UFCS_NONLOCAL(f)(o) };
  inline CPP2_CONSTEXPR bool u::c{ [](cpp2::impl::in<std::type_identity_t<decltype(CPP2_UFCS_NONLOCAL(f)(o))>> x) mutable -> auto { return x; }(true) };// Fails on Clang 12 (lambda in unevaluated context).
  auto u::g(auto const& s, auto const& sz) -> void{
                                  if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(sz)(s) != 0) ) { cpp2::cpp2_default.report_violation(""); }}

#line 45 "mixed-bugfix-for-ufcs-non-local.cpp2"
}

#line 47 "mixed-bugfix-for-ufcs-non-local.cpp2"
auto main() -> int{}

