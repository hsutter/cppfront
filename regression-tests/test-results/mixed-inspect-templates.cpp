

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#include <vector>
#include <array>
#include <string>

template <typename A, typename B>
struct my_type {};

#line 8 "mixed-inspect-templates.cpp2"
[[nodiscard]] auto fun(auto const& v) -> std::string;
    

#line 18 "mixed-inspect-templates.cpp2"
[[nodiscard]] auto fun2(auto const& v) -> std::string;

#line 26 "mixed-inspect-templates.cpp2"
[[nodiscard]] auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 8 "mixed-inspect-templates.cpp2"
[[nodiscard]] auto fun(auto const& v) -> std::string{
    return [&] () -> std::string { auto&& __expr = v;
        if (cpp2::is<std::vector>(__expr)) { if constexpr( requires{"std::vector";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("std::vector")),std::string> ) return "std::vector"; cpp2::Type.expects(false, "Statement of chosen alternative is invalid."); }
        else if (cpp2::is<std::array>(__expr)) { if constexpr( requires{"std::array";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("std::array")),std::string> ) return "std::array"; cpp2::Type.expects(false, "Statement of chosen alternative is invalid."); }
        else if (cpp2::is<std::variant>(__expr)) { if constexpr( requires{"std::variant";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("std::variant")),std::string> ) return "std::variant"; cpp2::Type.expects(false, "Statement of chosen alternative is invalid."); }
        else if (cpp2::is<my_type>(__expr)) { if constexpr( requires{"my_type";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("my_type")),std::string> ) return "my_type"; cpp2::Type.expects(false, "Statement of chosen alternative is invalid."); }
        return "unknown"; }
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
    std::vector<int> vec {1, 2, 3}; 
    std::array<int,4> arr {1, 2, 3, 4}; 
    std::variant<int,double,std::string> var {"C++ rulez"}; 
    my_type<int,double> myt {}; 

    std::cout << "inspected vec : " + cpp2::to_string(fun(vec)) << std::endl;
    std::cout << "inspected arr : " + cpp2::to_string(fun(arr)) << std::endl;
    std::cout << "inspected var : " + cpp2::to_string(fun(var)) << std::endl;
    std::cout << "inspected myt : " + cpp2::to_string(fun(myt)) << std::endl;

    std::cout << "inspected vec : " + cpp2::to_string(fun2(std::move(vec))) << std::endl;
    std::cout << "inspected arr : " + cpp2::to_string(fun2(std::move(arr))) << std::endl;
    std::cout << "inspected var : " + cpp2::to_string(fun2(std::move(var))) << std::endl;
    std::cout << "inspected myt : " + cpp2::to_string(fun2(std::move(myt))) << std::endl;
}

