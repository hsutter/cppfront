// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-inspect-with-typeof-of-template-arg-list.cpp2"

template <int i, int j>
auto calc() {
    return i + j;
}

[[nodiscard]] auto fun(auto const& v) -> int;
#line 14 "mixed-inspect-with-typeof-of-template-arg-list.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 6 "mixed-inspect-with-typeof-of-template-arg-list.cpp2"

[[nodiscard]] auto fun(auto const& v) -> int{
    return [&] () -> int { auto&& __expr = v;
        if (cpp2::is<int>(__expr)) { if constexpr( requires{calc<1,2>();} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF((calc<1,2>())),int> ) return calc<1,2>(); else return int{}; else return int{}; }
        else return 0; }
    ()
; }

[[nodiscard]] auto main() -> int{
    return fun(42); 
}
