
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

struct f__ret { int ri; };

#line 2 "pure2-look-up-parameter-across-unnamed-function.cpp2"
[[nodiscard]] auto f() -> f__ret;
    struct g__ret { int ri; };



#line 8 "pure2-look-up-parameter-across-unnamed-function.cpp2"
[[nodiscard]] auto g() -> g__ret;
    

#line 15 "pure2-look-up-parameter-across-unnamed-function.cpp2"
[[nodiscard]] auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 2 "pure2-look-up-parameter-across-unnamed-function.cpp2"
[[nodiscard]] auto f() -> f__ret{
    int ri {0};
#line 3 "pure2-look-up-parameter-across-unnamed-function.cpp2"
    auto pred {[](auto const& e) -> bool{return e == 1; }}; 
    ri = 42;
    return  { std::move(ri) }; // "return;" is implicit"
}

[[nodiscard]] auto g() -> g__ret{
        cpp2::deferred_init<int> ri;
#line 9 "pure2-look-up-parameter-across-unnamed-function.cpp2"
    ri.construct(0);
    auto pred {[](auto const& e) -> bool{return e == 1; }}; 
    ri.value() = 42;
    return  { std::move(ri.value()) }; 
}

[[nodiscard]] auto main() -> int{
    std::cout << f().ri + g().ri << "\n";
}

