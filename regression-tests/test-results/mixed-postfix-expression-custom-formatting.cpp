

#include "cpp2util.h"


#line 2 "mixed-postfix-expression-custom-formatting.cpp2"
auto call(auto const& v, auto const& w, auto const& x, auto const& y, auto const& z) -> void;
#line 4 "mixed-postfix-expression-custom-formatting.cpp2"
[[nodiscard]] auto test(auto const& a) -> std::string;
#line 15 "mixed-postfix-expression-custom-formatting.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "mixed-postfix-expression-custom-formatting.cpp2"

auto call(auto const& v, auto const& w, auto const& x, auto const& y, auto const& z) -> void{}

[[nodiscard]] auto test(auto const& a) -> std::string{
    return call( a, 
        ++*cpp2::assert_not_null(CPP2_UFCS(b, a, a.c)), "hello", /* polite
                          greeting
                          goes here */ " there", 
        CPP2_UFCS(e, a.d, ++CPP2_UFCS_0(g, *cpp2::assert_not_null(a.f)), // because f is foobar
              CPP2_UFCS_0(i, a.h), 
              CPP2_UFCS(j, a, a.k, a.l))
        ); 
}

[[nodiscard]] auto main() -> int{}

