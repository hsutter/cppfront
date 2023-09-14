
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-type-safety-2-with-inspect-expression.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-type-safety-2-with-inspect-expression.cpp2"
[[nodiscard]] auto main() -> int;

#line 20 "pure2-type-safety-2-with-inspect-expression.cpp2"
auto test_generic(auto const& x, auto const& msg) -> void;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-type-safety-2-with-inspect-expression.cpp2"
[[nodiscard]] auto main() -> int{
#line 2 "pure2-type-safety-2-with-inspect-expression.cpp2"
    std::variant<int,double,int> v {42.0}; 
    std::any a {"xyzzy"}; 
    std::optional<int> o {}; 

    test_generic(3.14, "double");
    test_generic(v,    "variant<int, double, int>");
    test_generic(a,    "any");
    test_generic(o,    "optional<int>");

    static_cast<void>(CPP2_UFCS_TEMPLATE(emplace<2>)(v, 1));
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
        << [&] () -> std::string { auto&& _expr = x;
            if (cpp2::is<int>(_expr)) { if constexpr( requires{std::to_string(cpp2::as<int>(x));} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((std::to_string(cpp2::as<int>(x)))),std::string> ) return std::to_string(cpp2::as<int>(x)); else return std::string{}; else return std::string{}; }
            else return "not an int"; }
        () 
        << "\n";
}

