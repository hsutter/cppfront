
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-more-wildcards.cpp2"
[[nodiscard]] auto less_than(auto const& value) -> auto;

[[nodiscard]] auto main() -> int;


//=== Cpp2 function definitions =================================================


#line 2 "pure2-more-wildcards.cpp2"
[[nodiscard]] auto less_than(auto const& value) -> auto { return [_0 = value](auto const& x) -> auto { return cpp2::cmp_less(x,_0); }; }

[[nodiscard]] auto main() -> int
{
    auto const x {2}; 
    auto* p {&x}; 
    auto const* q {&p}; 

    if (cpp2::is((x), (less_than(20)))) {
        std::cout << "yes, less\n";
    }

    if (true) {
        std::cout << "yes, always\n";
    }
}

