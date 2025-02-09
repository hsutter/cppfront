
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-expected-is-as.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-expected-is-as.cpp2"
// `std::expected` requires C++23 so a dedicated test file is needed
// since only MSVC supports it at time of writing, and there's no #ifdef
// or `static if` support in Cpp2 (yet?).

#line 5 "pure2-expected-is-as.cpp2"
[[nodiscard]] auto main() -> int;

#line 75 "pure2-expected-is-as.cpp2"
auto test_inspect(auto const& x, auto const& msg) -> void;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-expected-is-as.cpp2"

#line 5 "pure2-expected-is-as.cpp2"
[[nodiscard]] auto main() -> int{

    std::expected<int,int> ex1 {123}; 
    std::expected<int,int> ex2 {std::unexpected(-1)}; 
    std::expected<std::string,size_t> ex3 {"Expect the unexpected"}; 

    if (cpp2::impl::is<int>(ex1)) {
        std::cout << "ex1 is int\n";
    }

    if (cpp2::impl::is<bool>(ex1)) {
        std::cout << "BUG - ex1 is not a bool\n";
        return -1; 
    }

    if (cpp2::impl::is<void>(ex1)) {
        std::cout << "BUG - ex1 is not 'empty'\n";
        return -1; 
    }

    if (cpp2::impl::is<std::unexpected<int>>(ex1)) {
        std::cout << "BUG - ex1 is not unexpected\n";
        return -1; 
    }

    if (cpp2::impl::is(ex1, 123)) {
        std::cout << "ex1 is 123\n";
    }

    if (cpp2::impl::is(ex1, 100)) {
        std::cout << "BUG - ex1's value is not 100\n";
        return -1; 
    }

    auto val1 {cpp2::impl::as_<int>(ex1)}; 
    std::cout << "ex1 as int = " << cpp2::move(val1) << "\n";

    if (cpp2::impl::is<int>(ex2)) {
        std::cout << "BUG - ex2 is not an int\n";
        return -1; 
    }

    if (cpp2::impl::is<bool>(ex2)) {
        std::cout << "BUG - ex2 is not a bool\n";
        return -1; 
    }

    if (cpp2::impl::is(ex2, 123)) {
        std::cout << "BUG - ex2 does not have a value\n";
        return -1; 
    }

    if (cpp2::impl::is<std::unexpected<int>>(ex2)) {
        std::cout << "ex2 is unexpected<int> and error is: " << CPP2_UFCS(error)(ex2) << "\n";
    }

    if (cpp2::impl::is<void>(ex2)) {
        std::cout << "ex2 is 'empty' aka unexpected<int> and error is: " << CPP2_UFCS(error)(ex2) << "\n";
    }

    auto ex2_err {cpp2::impl::as_<std::unexpected<int>>(ex2)}; 
    std::cout << "ex2 as std::unexpected<int> and error = " << CPP2_UFCS(error)(cpp2::move(ex2_err)) << "\n";

    test_inspect(cpp2::move(ex1), "expected<int, int> with value");
    test_inspect(cpp2::move(ex2), "expected<int, int> with unexpected");
    test_inspect(cpp2::move(ex3), "expected<string, size_t> with value");

    return 0; 
}

#line 75 "pure2-expected-is-as.cpp2"
auto test_inspect(auto const& x, auto const& msg) -> void{

    auto unwrap {[](cpp2::impl::in<std::unexpected<int>> unexp) -> auto{
        return CPP2_UFCS(error)(unexp); 
    }}; 

    std::cout 
        << "\n" << msg << "\n    ..." 
        << [&] () -> std::string { auto&& _expr = x;
            if (cpp2::impl::is<int>(_expr)) { if constexpr( requires{"integer " + std::to_string(cpp2::impl::as<int>(x));} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("integer " + std::to_string(cpp2::impl::as<int>(x)))),std::string> ) return "integer " + std::to_string(cpp2::impl::as<int>(x)); else return std::string{}; else return std::string{}; }
            else if (cpp2::impl::is<std::unexpected<int>>(_expr)) { if constexpr( requires{"unexpected<int> " + std::to_string(cpp2::move(unwrap)(cpp2::impl::as<std::unexpected<int>>(x)));} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("unexpected<int> " + std::to_string(cpp2::move(unwrap)(cpp2::impl::as<std::unexpected<int>>(x))))),std::string> ) return "unexpected<int> " + std::to_string(cpp2::move(unwrap)(cpp2::impl::as<std::unexpected<int>>(x))); else return std::string{}; else return std::string{}; }
            else if (cpp2::impl::is<std::string>(_expr)) { if constexpr( requires{"string " + cpp2::impl::as<std::string>(x);} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("string " + cpp2::impl::as<std::string>(x))),std::string> ) return "string " + cpp2::impl::as<std::string>(x); else return std::string{}; else return std::string{}; }
            else return " no match"; }
        () 
        << "\n";
}

