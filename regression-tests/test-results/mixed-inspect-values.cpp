

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
        if constexpr (requires { cpp2::is(__expr, 0); }) { if constexpr (!std::is_same_v<decltype(cpp2::is(__expr, 0)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is(__expr, 0)), std::true_type>) { return "zero"; } else { if (cpp2::is(__expr, 0)) { return "zero"; } } } }
        if constexpr (requires { cpp2::is(__expr, (in(1, 2))); }) { if constexpr (!std::is_same_v<decltype(cpp2::is(__expr, (in(1, 2)))), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is(__expr, (in(1, 2)))), std::true_type>) { return "1 or 2"; } else { if (cpp2::is(__expr, (in(1, 2)))) { return "1 or 2"; } } } }
        if constexpr (requires { cpp2::is(__expr, in_2_3); }) { if constexpr (!std::is_same_v<decltype(cpp2::is(__expr, in_2_3)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is(__expr, in_2_3)), std::true_type>) { return "3"; } else { if (cpp2::is(__expr, in_2_3)) { return "3"; } } } }
        if constexpr (requires { cpp2::is(__expr, std::move(forty_two)); }) { if constexpr (!std::is_same_v<decltype(cpp2::is(__expr, std::move(forty_two))), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is(__expr, std::move(forty_two))), std::true_type>) { return "the answer";  } else { if (cpp2::is(__expr, std::move(forty_two))) { return "the answer";  } } } }
        if constexpr (requires { cpp2::is<int>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<int>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<int>(__expr)), std::true_type>) { return "integer " + cpp2::to_string(x); } else { if (cpp2::is<int>(__expr)) { return "integer " + cpp2::to_string(x); } } } }
        if constexpr (requires { cpp2::is<std::string>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::string>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::string>(__expr)), std::true_type>) { return cpp2::as<std::string>(x);  } else { if (cpp2::is<std::string>(__expr)) { return cpp2::as<std::string>(x);  } } } }
        return "(no match)";
    }() << "\n";
}

