
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-more-wildcards.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-more-wildcards.cpp2"

#line 2 "pure2-more-wildcards.cpp2"
[[nodiscard]] auto less_than(auto const& value) -> decltype(auto);

[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-more-wildcards.cpp2"

#line 2 "pure2-more-wildcards.cpp2"
[[nodiscard]] auto less_than(auto const& value) -> decltype(auto) { return [_0 = value](auto const& x) mutable -> decltype(auto) { return cpp2::impl::cmp_less(x,_0);  };  }

#line 4 "pure2-more-wildcards.cpp2"
[[nodiscard]] auto main() -> int
{
    auto const x {2}; 
    auto* p {&x}; 
    auto const* q {&p}; 
    if (cpp2::cpp2_default.is_active() && !(cpp2::move(q)) ) { cpp2::cpp2_default.report_violation(""); }

    if (cpp2::impl::is(x, (less_than(20)))) {
        std::cout << "yes, less\n";
    }

    if (true) {
        std::cout << "yes, always\n";
    }
}

