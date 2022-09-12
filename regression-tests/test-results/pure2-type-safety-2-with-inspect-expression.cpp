// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 1 "pure2-type-safety-2-with-inspect-expression.cpp2"
[[nodiscard]] auto main() -> int;
#line 20 "pure2-type-safety-2-with-inspect-expression.cpp2"
auto test_generic(auto const& x) -> void;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-type-safety-2-with-inspect-expression.cpp2"
[[nodiscard]] auto main() -> int{
    std::variant<int,double> v { 42.0 }; 
    std::any a { "xyzzy" }; 
    std::optional<int> o {  }; 

    test_generic(3.14);
    test_generic(v);
    test_generic(a);
    test_generic(o);

    v = 1;
    a = 2;
    o = 3;
    test_generic(42);
    test_generic(v);
    test_generic(a);
    test_generic(o);
}

auto test_generic(auto const& x) -> void{
    std::cout 
        << std::setw(30) << typeid(x).name() 
        << " value is " 
        << [&] () -> std::string { auto&& __expr = x;
            if (cpp2::is<int>(__expr)) { if constexpr( requires{std::to_string(cpp2::as<int>(x));} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(std::to_string(cpp2::as<int>(x))),std::string> ) return std::to_string(cpp2::as<int>(x)); else return std::string{}; else return std::string{}; }
            else return "not an int"; }
        ()
        << "\n";
}
