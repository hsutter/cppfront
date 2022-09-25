// ----- Cpp2 support -----
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
        ++*a.b(a.c), "hello", /* polite
                          greeting
                          goes here */ " there", 
        a.d.e( ++(*a.f).g(), // because f is foobar
              a.h.i(), 
              CPP2_UFCS(j, a, a.k, a.l))
        ); 
}

[[nodiscard]] auto main() -> int{}
