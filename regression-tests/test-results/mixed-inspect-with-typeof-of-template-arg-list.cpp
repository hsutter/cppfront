

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


template <int i, int j>
auto calc() {
    return i + j;
}

#line 7 "mixed-inspect-with-typeof-of-template-arg-list.cpp2"
[[nodiscard]] auto fun(auto const& v) -> int;
    

#line 14 "mixed-inspect-with-typeof-of-template-arg-list.cpp2"
[[nodiscard]] auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 7 "mixed-inspect-with-typeof-of-template-arg-list.cpp2"
[[nodiscard]] auto fun(auto const& v) -> int{
    return [&] () -> int { auto&& __expr = v;
        if constexpr (requires { cpp2::is<int>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<int>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<int>(__expr)), std::true_type>) { return calc<1,2>(); } else { if (cpp2::is<int>(__expr)) { return calc<1,2>(); } } } }
        return 0;
    }(); 
}

[[nodiscard]] auto main() -> int{
    return fun(42); 
}

