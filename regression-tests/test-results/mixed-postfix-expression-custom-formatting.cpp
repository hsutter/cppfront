

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


#line 2 "mixed-postfix-expression-custom-formatting.cpp2"
auto call([[maybe_unused]] auto const& param1, [[maybe_unused]] auto const& param2, [[maybe_unused]] auto const& param3, [[maybe_unused]] auto const& param4, [[maybe_unused]] auto const& param5) -> void;

[[nodiscard]] auto test(auto const& a) -> std::string;
    

#line 15 "mixed-postfix-expression-custom-formatting.cpp2"
[[nodiscard]] auto main() -> int;


//=== Cpp2 function definitions =================================================


#line 2 "mixed-postfix-expression-custom-formatting.cpp2"
auto call([[maybe_unused]] auto const& param1, [[maybe_unused]] auto const& param2, [[maybe_unused]] auto const& param3, [[maybe_unused]] auto const& param4, [[maybe_unused]] auto const& param5) -> void{}

[[nodiscard]] auto test(auto const& a) -> std::string{
    return call(a, 
        ++*cpp2::assert_not_null(CPP2_UFCS(b, a, a.c)), "hello", /* polite
                          greeting
                          goes here */" there", 
        CPP2_UFCS(e, a.d, ++CPP2_UFCS_0(g, *cpp2::assert_not_null(a.f)), // because f is foobar
              CPP2_UFCS_0(i, a.h), 
              CPP2_UFCS(j, a, a.k, a.l))
        ); 
}

[[nodiscard]] auto main() -> int{}

