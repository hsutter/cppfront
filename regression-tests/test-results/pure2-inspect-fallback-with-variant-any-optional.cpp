// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-inspect-fallback-with-variant-any-optional.cpp2"
[[nodiscard]] auto main() -> int;
#line 14 "pure2-inspect-fallback-with-variant-any-optional.cpp2"
auto test_generic(auto const& x) -> void;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-inspect-fallback-with-variant-any-optional.cpp2"

[[nodiscard]] auto main() -> int{
    std::variant<int,std::string> v { cpp2::as<std::string>("xyzzy") }; 
    std::any a { cpp2::as<std::string>("xyzzy") }; 
    std::optional<std::string> o { cpp2::as<std::string>("xyzzy") }; 

    std::cout << "\nAll these cases satisfy \"matches std::string\"\n";

    test_generic(v);
    test_generic(a);
    test_generic(o);
}

auto test_generic(auto const& x) -> void{
    std::cout 
        << "\n" << typeid(x).name() << "\n    ..." 
        << [&] () -> std::string { auto&& __expr = x;
            if (cpp2::is<std::string>(__expr)) { if constexpr( requires{" matches std::string";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(" matches std::string"),std::string> ) return " matches std::string"; else return std::string{}; else return std::string{}; }
            else if (cpp2::is<std::variant<int,std::string>>(__expr)) { if constexpr( requires{" matches std::variant<int, std::string>";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(" matches std::variant<int, std::string>"),std::string> ) return " matches std::variant<int, std::string>"; else return std::string{}; else return std::string{}; }
            else if (cpp2::is<std::any>(__expr)) { if constexpr( requires{" matches std::any";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(" matches std::any"),std::string> ) return " matches std::any"; else return std::string{}; else return std::string{}; }
            else if (cpp2::is<std::optional<std::string>>(__expr)) { if constexpr( requires{" matches std::optional<std::string>";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(" matches std::optional<std::string>"),std::string> ) return " matches std::optional<std::string>"; else return std::string{}; else return std::string{}; }
            else return " no match"; }
        ()
        << "\n";
}
