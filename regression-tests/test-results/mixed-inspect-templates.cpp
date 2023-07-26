

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
        if constexpr (requires { cpp2::is<std::vector>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::vector>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::vector>(__expr)), std::true_type>) { return "std::vector"; } else { if (cpp2::is<std::vector>(__expr)) { return "std::vector"; } } } }
        if constexpr (requires { cpp2::is<std::array>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::array>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::array>(__expr)), std::true_type>) { return "std::array"; } else { if (cpp2::is<std::array>(__expr)) { return "std::array"; } } } }
        if constexpr (requires { cpp2::is<std::variant>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::variant>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::variant>(__expr)), std::true_type>) { return "std::variant";  } else { if (cpp2::is<std::variant>(__expr)) { return "std::variant";  } } } }
        if constexpr (requires { cpp2::is<my_type>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<my_type>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<my_type>(__expr)), std::true_type>) { return "my_type"; } else { if (cpp2::is<my_type>(__expr)) { return "my_type"; } } } }
        return "unknown";
    }(); 
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

