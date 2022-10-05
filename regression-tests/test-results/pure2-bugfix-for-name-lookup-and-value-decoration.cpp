// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 1 "pure2-bugfix-for-name-lookup-and-value-decoration.cpp2"
struct vals__ret {
    int i;
    };
#line 2 "pure2-bugfix-for-name-lookup-and-value-decoration.cpp2"
[[nodiscard]] auto vals() -> vals__ret;
#line 6 "pure2-bugfix-for-name-lookup-and-value-decoration.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-bugfix-for-name-lookup-and-value-decoration.cpp2"
[[nodiscard]] auto vals() -> vals__ret{
        cpp2::deferred_init<int> i;
#line 2 "pure2-bugfix-for-name-lookup-and-value-decoration.cpp2"
    i.construct(42);
    return  { std::move(i.value()) }; 
}

[[nodiscard]] auto main() -> int{
    auto v { vals() }; 
    v.i;
}
