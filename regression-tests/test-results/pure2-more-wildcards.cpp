// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-more-wildcards.cpp2"
[[nodiscard]] auto less_than(auto const& value) -> auto;
#line 5 "pure2-more-wildcards.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-more-wildcards.cpp2"

[[nodiscard]] auto less_than(auto const& value) -> auto { 
    return [_0 = value](auto const& x) { return cpp2::cmp_less(x,_0); }; }

[[nodiscard]] auto main() -> int
{
    auto const x {2}; 
    auto* p {&x}; 
    auto const* q {&p}; 

    if (cpp2::is(x, (less_than(20)))) {
        std::cout << "yes, less\n";
    }

    if (true)   {
        std::cout << "yes, always\n";
    }
}

