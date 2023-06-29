
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-inspect-fallback-with-variant-any-optional.cpp2"
[[nodiscard]] auto main() -> int;
    

#line 14 "pure2-inspect-fallback-with-variant-any-optional.cpp2"
auto test_generic(auto const& x, auto const& msg) -> void;
    

//=== Cpp2 function definitions =================================================


#line 2 "pure2-inspect-fallback-with-variant-any-optional.cpp2"
[[nodiscard]] auto main() -> int{
    std::variant<int,int,std::string> v {cpp2::as_<std::string>("xyzzy")}; 
    std::any a {cpp2::as_<std::string>("xyzzy")}; 
    std::optional<std::string> o {cpp2::as_<std::string>("xyzzy")}; 

    std::cout << "\nAll these cases satisfy \"matches std::string\"\n";

    test_generic(std::move(v), "variant<int, int, string>");
    test_generic(std::move(a), "string");
    test_generic(std::move(o), "optional<string>");
}

auto test_generic(auto const& x, auto const& msg) -> void{
    std::cout 
        << "\n" << msg << "\n    ..." 
        << [&] () -> std::string { auto&& __expr = x;
            if constexpr (requires { cpp2::is<std::string>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::string>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::string>(__expr)), std::true_type>) { return " matches std::string";  } else { if (cpp2::is<std::string>(__expr)) { return " matches std::string";  } } } }
            if constexpr (requires { cpp2::is<std::variant<int,std::string>>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::variant<int,std::string>>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::variant<int,std::string>>(__expr)), std::true_type>) { return " matches std::variant<int, std::string>";  } else { if (cpp2::is<std::variant<int,std::string>>(__expr)) { return " matches std::variant<int, std::string>";  } } } }
            if constexpr (requires { cpp2::is<std::any>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::any>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::any>(__expr)), std::true_type>) { return " matches std::any";  } else { if (cpp2::is<std::any>(__expr)) { return " matches std::any";  } } } }
            if constexpr (requires { cpp2::is<std::optional<std::string>>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::optional<std::string>>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::optional<std::string>>(__expr)), std::true_type>) { return " matches std::optional<std::string>";  } else { if (cpp2::is<std::optional<std::string>>(__expr)) { return " matches std::optional<std::string>";  } } } }
            return " no match";
        }() 
        << "\n";
}

