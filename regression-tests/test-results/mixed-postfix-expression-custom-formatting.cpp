// ----- Cpp2 support -----
#include "cpp2util.h"


#line 2 "mixed-postfix-expression-custom-formatting.cpp2"
[[nodiscard]] auto test(auto const& a) -> std::string;
#line 12 "mixed-postfix-expression-custom-formatting.cpp2"


//=== Cpp2 definitions ==========================================================

#line 1 "mixed-postfix-expression-custom-formatting.cpp2"

[[nodiscard]] auto test(auto const& a) -> std::string{
    return call( a, 
        ++*b(c), "hello", /* polite
                          greeting
                          goes here */ " there", 
        d::e( ++(*f).g(), // because f is foobar
              CPP2_UFCS_0(i, h), 
              j(k, l))
        ); 
}
