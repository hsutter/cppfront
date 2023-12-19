
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-inspect-expression-with-as-in-generic-function.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-inspect-expression-with-as-in-generic-function.cpp2"
[[nodiscard]] auto main() -> int;

#line 7 "pure2-inspect-expression-with-as-in-generic-function.cpp2"
auto print_an_int(auto const& x) -> void;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-inspect-expression-with-as-in-generic-function.cpp2"
[[nodiscard]] auto main() -> int{
#line 2 "pure2-inspect-expression-with-as-in-generic-function.cpp2"
    print_an_int("syzygy");
    print_an_int(1);
    print_an_int(1.1);
}

auto print_an_int(auto const& x) -> void{
    std::cout 
        << std::setw(30) << cpp2::to_string(x) 
        << " value is " 
        << [&] () -> std::string { auto&& _expr = x;
            if (cpp2::is<int>(_expr)) { if constexpr( requires{std::to_string(cpp2::as<int>(x));} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((std::to_string(cpp2::as<int>(x)))),std::string> ) return std::to_string(cpp2::as<int>(x)); else return std::string{}; else return std::string{}; }
            else return "not an int"; }
        () 
        << "\n";
}

