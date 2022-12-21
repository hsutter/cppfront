// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 1 "pure2-inspect-values.cpp2"
[[nodiscard]] auto main() -> int;
#line 23 "pure2-inspect-values.cpp2"
auto test(auto const& x) -> void;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-inspect-values.cpp2"
[[nodiscard]] auto main() -> int{
    std::variant<double,std::string,double> v {  }; 
    test(v);
    v = "rev dodgson";
    test(std::move(v));

    std::optional<int> o {  }; 
    test(o);
    o = 42;
    test(std::move(o));

    std::any a { 0 }; 
    test(a);
    a = cpp2::as<  std::string>("plugh");
    test(std::move(a));

    test(0);
    test(-42);
    test(cpp2::as<  std::string>("xyzzy"));
    test(3.14);
}

auto test(auto const& x) -> void{
    auto forty_two { 42 }; 
    std::cout << [&] () -> std::string { auto&& __expr = x;
        if (cpp2::is(__expr, 0)) { if constexpr( requires{"zero";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("zero")),std::string> ) return "zero"; else return std::string{}; else return std::string{}; }
        else if (cpp2::is(__expr, (std::move(forty_two)))) { if constexpr( requires{"the answer";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("the answer")),std::string> ) return "the answer"; else return std::string{}; else return std::string{}; }
        else if (cpp2::is<int>(__expr)) { if constexpr( requires{"integer " + cpp2::to_string(x);} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("integer " + cpp2::to_string(x))),std::string> ) return "integer " + cpp2::to_string(x); else return std::string{}; else return std::string{}; }
        else if (cpp2::is<std::string>(__expr)) { if constexpr( requires{cpp2::as<std::string>(x);} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((cpp2::as<std::string>(x))),std::string> ) return cpp2::as<std::string>(x); else return std::string{}; else return std::string{}; }
        else return "(no match)"; }
    ()
 << "\n";}

