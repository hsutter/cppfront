// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-inspect-templates.cpp2"
#include <vector>
#include <array>
#include <string>

template <typename A, typename B>
struct my_type {};

[[nodiscard]] auto fun(auto const& v) -> std::string;
#line 18 "mixed-inspect-templates.cpp2"
[[nodiscard]] auto fun2(auto const& v) -> std::string;
#line 26 "mixed-inspect-templates.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 7 "mixed-inspect-templates.cpp2"

[[nodiscard]] auto fun(auto const& v) -> std::string{
    return [&] () -> std::string { auto&& __expr = v;
        if (cpp2::is<std::vector>(__expr)) { if constexpr( requires{"std::vector";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("std::vector")),std::string> ) return "std::vector"; else return std::string{}; else return std::string{}; }
        else if (cpp2::is<std::array>(__expr)) { if constexpr( requires{"std::array";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("std::array")),std::string> ) return "std::array"; else return std::string{}; else return std::string{}; }
        else if (cpp2::is<std::variant>(__expr)) { if constexpr( requires{"std::variant";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("std::variant")),std::string> ) return "std::variant"; else return std::string{}; else return std::string{}; }
        else if (cpp2::is<my_type>(__expr)) { if constexpr( requires{"my_type";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("my_type")),std::string> ) return "my_type"; else return std::string{}; else return std::string{}; }
        else return "unknown"; }
    (); 
}

[[nodiscard]] auto fun2(auto const& v) -> std::string{
    if (cpp2::is<std::vector>(v)) {return "std::vector"; }
    if (cpp2::is<std::array>(v)) {return "std::array"; }
    if (cpp2::is<std::variant>(v)) {return "std::variant"; }
    if (cpp2::is<my_type>(v)) {return "my_type";    }
    return "unknown"; 
}

[[nodiscard]] auto main() -> int{
    std::vector<int> vec { 1, 2, 3 }; 
    std::array<int,4> arr { 1, 2, 3, 4 }; 
    std::variant<int,double,std::string> var { "cpp2 rulez" }; 
    my_type      <int, double> myt {  }; 

    std::cout << "inspected vec : " + cpp2::to_string(fun(vec)) << std::endl;
    std::cout << "inspected arr : " + cpp2::to_string(fun(arr)) << std::endl;
    std::cout << "inspected var : " + cpp2::to_string(fun(var)) << std::endl;
    std::cout << "inspected myt : " + cpp2::to_string(fun(myt)) << std::endl;

    std::cout << "inspected vec : " + cpp2::to_string(fun2(vec)) << std::endl;
    std::cout << "inspected arr : " + cpp2::to_string(fun2(arr)) << std::endl;
    std::cout << "inspected var : " + cpp2::to_string(fun2(var)) << std::endl;
    std::cout << "inspected myt : " + cpp2::to_string(fun2(myt)) << std::endl;
}

