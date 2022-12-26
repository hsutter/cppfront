// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-look-up-parameter-across-unnamed-function.cpp2"
struct f__ret {
    int ri;
    };
#line 3 "pure2-look-up-parameter-across-unnamed-function.cpp2"
[[nodiscard]] auto f() -> f__ret;
#line 8 "pure2-look-up-parameter-across-unnamed-function.cpp2"
struct g__ret {
    int ri;
    };
#line 9 "pure2-look-up-parameter-across-unnamed-function.cpp2"
[[nodiscard]] auto g() -> g__ret;
#line 15 "pure2-look-up-parameter-across-unnamed-function.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-look-up-parameter-across-unnamed-function.cpp2"

[[nodiscard]] auto f() -> f__ret{
    int ri = 0;
#line 3 "pure2-look-up-parameter-across-unnamed-function.cpp2"
    auto pred { [](auto const& e) -> bool{return e == 1; } }; 
    ri = 42;
    return  { std::move(ri) }; // "return;" is implicit"
}

[[nodiscard]] auto g() -> g__ret{
        cpp2::deferred_init<int> ri;
#line 9 "pure2-look-up-parameter-across-unnamed-function.cpp2"
    ri.construct(0);
    auto pred { [](auto const& e) -> bool{return e == 1; } }; 
    ri.value() = 42;
    return  { std::move(ri.value()) }; 
}

[[nodiscard]] auto main() -> int{
    std::cout << f().ri + g().ri << "\n";
}

