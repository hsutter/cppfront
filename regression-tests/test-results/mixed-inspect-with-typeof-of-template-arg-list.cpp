

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
        if (cpp2::is<int>(__expr)) { if constexpr( requires{calc<1,2>();} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((calc<1,2>())),int> ) return calc<1,2>(); else return int{}; else return int{}; }
        return 0; }
    (); 
}

[[nodiscard]] auto main() -> int{
    return fun(42); 
}

