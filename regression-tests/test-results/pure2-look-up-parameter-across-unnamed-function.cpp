
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-look-up-parameter-across-unnamed-function.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-look-up-parameter-across-unnamed-function.cpp2"

using f_ret = int;
#line 2 "pure2-look-up-parameter-across-unnamed-function.cpp2"
[[nodiscard]] auto f() -> f_ret;
using g_ret = int;


#line 9 "pure2-look-up-parameter-across-unnamed-function.cpp2"
[[nodiscard]] auto g() -> g_ret;

#line 17 "pure2-look-up-parameter-across-unnamed-function.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-look-up-parameter-across-unnamed-function.cpp2"

#line 2 "pure2-look-up-parameter-across-unnamed-function.cpp2"
[[nodiscard]] auto f() -> f_ret{
    int ri {0};
#line 3 "pure2-look-up-parameter-across-unnamed-function.cpp2"
    auto pred {[](auto const& e) mutable -> auto { return e == 1;  }}; 
    ri = 42;
    std::move(pred)(ri);
    return std::move(ri); // "return;" is implicit"
}

[[nodiscard]] auto g() -> g_ret{
        cpp2::deferred_init<int> ri;
#line 10 "pure2-look-up-parameter-across-unnamed-function.cpp2"
    ri.construct(0);
    auto pred {[](auto const& e) mutable -> auto { return e == 1;  }}; 
    ri.value() = 42;
    std::move(pred)(ri.value());
    return std::move(ri.value()); 
}

[[nodiscard]] auto main() -> int{
    std::cout << f() + g() << "\n";
}

