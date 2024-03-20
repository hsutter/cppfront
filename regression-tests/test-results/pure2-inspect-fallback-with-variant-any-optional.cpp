
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-inspect-fallback-with-variant-any-optional.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-inspect-fallback-with-variant-any-optional.cpp2"

#line 2 "pure2-inspect-fallback-with-variant-any-optional.cpp2"
[[nodiscard]] auto main() -> int;

#line 14 "pure2-inspect-fallback-with-variant-any-optional.cpp2"
auto test_generic(auto const& x, auto const& msg) -> void;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-inspect-fallback-with-variant-any-optional.cpp2"

#line 2 "pure2-inspect-fallback-with-variant-any-optional.cpp2"
[[nodiscard]] auto main() -> int{
    std::variant<int,int,std::string> v {cpp2::impl::as_<std::string>("xyzzy")}; 
    std::any a {cpp2::impl::as_<std::string>("xyzzy")}; 
    std::optional<std::string> o {cpp2::impl::as_<std::string>("xyzzy")}; 

    std::cout << "\nAll these cases satisfy \"matches std::string\"\n";

    test_generic(cpp2::move(v), "variant<int, int, string>");
    test_generic(cpp2::move(a), "string");
    test_generic(cpp2::move(o), "optional<string>");
}

#line 14 "pure2-inspect-fallback-with-variant-any-optional.cpp2"
auto test_generic(auto const& x, auto const& msg) -> void{
    std::cout 
        << "\n" << msg << "\n    ..." 
        << [&] () -> std::string { auto&& _expr = x;
            if (cpp2::impl::is<std::string>(_expr)) { if constexpr( requires{" matches std::string";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((" matches std::string")),std::string> ) return " matches std::string"; else return std::string{}; else return std::string{}; }
            else if (cpp2::impl::is<std::variant<int,std::string>>(_expr)) { if constexpr( requires{" matches std::variant<int, std::string>";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((" matches std::variant<int, std::string>")),std::string> ) return " matches std::variant<int, std::string>"; else return std::string{}; else return std::string{}; }
            else if (cpp2::impl::is<std::any>(_expr)) { if constexpr( requires{" matches std::any";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((" matches std::any")),std::string> ) return " matches std::any"; else return std::string{}; else return std::string{}; }
            else if (cpp2::impl::is<std::optional<std::string>>(_expr)) { if constexpr( requires{" matches std::optional<std::string>";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((" matches std::optional<std::string>")),std::string> ) return " matches std::optional<std::string>"; else return std::string{}; else return std::string{}; }
            else return " no match"; }
        () 
        << "\n";
}

