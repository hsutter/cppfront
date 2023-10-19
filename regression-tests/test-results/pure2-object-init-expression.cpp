

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

extern std::any v;

auto main() -> int;
    

//=== Cpp2 function definitions =================================================

std::any v {12}; 

auto main() -> int{
    // object initializer must be an expression, not a statement
    // inspect only allows a result type when it is an expression
    int i {[&] () -> int { auto&& _expr = v;
        if (cpp2::is(_expr, 12)) { if constexpr( requires{12;} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((12)),int> ) return 12; else return int{}; else return int{}; }
        else return 0; }
    ()}; 
    cpp2::Default.expects(std::move(i) == 12, "");

    // inference
    auto s {[&] () -> std::string { auto&& _expr = v;
        if (cpp2::is(_expr, 5)) { if constexpr( requires{"five";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("five")),std::string> ) return "five"; else return std::string{}; else return std::string{}; }
        else if (cpp2::is<int>(_expr)) { if constexpr( requires{"some other integer";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("some other integer")),std::string> ) return "some other integer"; else return std::string{}; else return std::string{}; }
        else return "not an integer"; }
    ()}; 
    cpp2::Default.expects(std::move(s) == "some other integer", "");
}

