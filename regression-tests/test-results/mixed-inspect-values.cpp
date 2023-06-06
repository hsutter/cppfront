

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

auto in(int min, int max) {
    return [=](int x){ return min <= x && x <= max; };
}

#line 5 "mixed-inspect-values.cpp2"
[[nodiscard]] auto in_2_3(cpp2::in<int> x) -> bool;

[[nodiscard]] auto main() -> int;
    

#line 31 "mixed-inspect-values.cpp2"
auto test(auto const& x) -> void;
    

//=== Cpp2 function definitions =================================================


#line 5 "mixed-inspect-values.cpp2"
[[nodiscard]] auto in_2_3(cpp2::in<int> x) -> bool { return cpp2::cmp_less_eq(2,x) && cpp2::cmp_less_eq(x,3);  }

[[nodiscard]] auto main() -> int{
    std::variant<double,std::string,double> v {}; 
    v = "rev dodgson";
    test(std::move(v));

    std::optional<int> o {}; 
    test(o);
    o = 42;
    test(std::move(o));

    std::any a {0}; 
    test(a);
    a = cpp2::as_<std::string>("plugh");
    test(std::move(a));

    test(0);
    test(1);
    test(2);
    test(3);
    test(-42);
    test(cpp2::as_<std::string>("xyzzy"));
    test(3.14);
}

auto test(auto const& x) -> void{
    auto forty_two {42}; 
    std::cout << [&] () -> std::string { auto&& __expr = x;
        if (cpp2::is(__expr, 0)) { if constexpr( requires{"zero";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("zero")),std::string> ) return "zero"; cpp2::Type.expects(false, "Statement of chosen alternative is invalid."); }
        else if (cpp2::is(__expr, (in(1, 2)))) { if constexpr( requires{"1 or 2";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("1 or 2")),std::string> ) return "1 or 2"; cpp2::Type.expects(false, "Statement of chosen alternative is invalid."); }
        else if (cpp2::is(__expr, in_2_3)) { if constexpr( requires{"3";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("3")),std::string> ) return "3"; cpp2::Type.expects(false, "Statement of chosen alternative is invalid."); }
        else if (cpp2::is(__expr, std::move(forty_two))) { if constexpr( requires{"the answer";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("the answer")),std::string> ) return "the answer"; cpp2::Type.expects(false, "Statement of chosen alternative is invalid."); }
        else if (cpp2::is<int>(__expr)) { if constexpr( requires{"integer " + cpp2::to_string(x);} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("integer " + cpp2::to_string(x))),std::string> ) return "integer " + cpp2::to_string(x); cpp2::Type.expects(false, "Statement of chosen alternative is invalid."); }
        else if (cpp2::is<std::string>(__expr)) { if constexpr( requires{cpp2::as<std::string>(x);} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((cpp2::as<std::string>(x))),std::string> ) return cpp2::as<std::string>(x); cpp2::Type.expects(false, "Statement of chosen alternative is invalid."); }
        return "(no match)"; }
    () << "\n";
}

