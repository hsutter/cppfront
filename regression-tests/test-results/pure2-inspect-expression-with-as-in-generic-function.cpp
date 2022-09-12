// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 1 "pure2-inspect-expression-with-as-in-generic-function.cpp2"
[[nodiscard]] auto main() -> int;
#line 7 "pure2-inspect-expression-with-as-in-generic-function.cpp2"
auto print_an_int(auto const& x) -> void;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-inspect-expression-with-as-in-generic-function.cpp2"
[[nodiscard]] auto main() -> int{
    print_an_int("syzygy");
    print_an_int(1);
    print_an_int(1.1);
}

auto print_an_int(auto const& x) -> void{
    std::cout 
        << std::setw(30) << typeid(x).name() 
        << " value is " 
        << [&] () -> std::string { auto&& __expr = x;
            if (cpp2::is<int>(__expr)) { if constexpr( requires{std::to_string(cpp2::as<int>(x));} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(std::to_string(cpp2::as<int>(x))),std::string> ) return std::to_string(cpp2::as<int>(x)); else return std::string{}; else return std::string{}; }
            else return "not an int"; }
        ()
        << "\n";
}
