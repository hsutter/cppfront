// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 1 "pure2-type-safety-2-with-inspect-expression.cpp2"
[[nodiscard]] auto main() -> int;
#line 20 "pure2-type-safety-2-with-inspect-expression.cpp2"
auto test_generic(auto const& x, auto const& msg) -> void;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-type-safety-2-with-inspect-expression.cpp2"
[[nodiscard]] auto main() -> int{
    std::variant<int,double,int> v {42.0}; 
    std::any a {"xyzzy"}; 
    std::optional<int> o {}; 

    test_generic(3.14, "double");
    test_generic(v,    "variant<int, double, int>");
    test_generic(a,    "any");
    test_generic(o,    "optional<int>");

    CPP2_UFCS_TEMPLATE(emplace, (<2>), v, 1);
    a = 2;
    o = 3;
    test_generic(42,   "int");
    test_generic(std::move(v), "variant<int, double, int>");
    test_generic(std::move(a), "any");
    test_generic(std::move(o), "optional<int>");
}

auto test_generic(auto const& x, auto const& msg) -> void{
    std::cout 
        << std::setw(30) << msg 
        << " value is " 
        << [&] () -> std::string { auto&& __expr = x;
            if (cpp2::is<int>(__expr)) { if constexpr( requires{std::to_string(cpp2::as<int>(x));} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((std::to_string(cpp2::as<int>(x)))),std::string> ) return std::to_string(cpp2::as<int>(x)); else return std::string{}; else return std::string{}; }
            else return "not an int"; }
        () 
        << "\n";
}

