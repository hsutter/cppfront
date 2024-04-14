
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-is-with-unnamed-predicates.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-is-with-unnamed-predicates.cpp2"
auto fun(auto const& v) -> void;

#line 15 "pure2-is-with-unnamed-predicates.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-is-with-unnamed-predicates.cpp2"
auto fun(auto const& v) -> void{
#line 2 "pure2-is-with-unnamed-predicates.cpp2"
    if (cpp2::impl::is(v, ([](cpp2::impl::in<int> x) mutable -> auto { return cpp2::impl::cmp_greater(x,3); }))) {
        std::cout << (cpp2::to_string(v) + " is integer bigger than 3") << std::endl;
    }

    if (cpp2::impl::is(v, ([](cpp2::impl::in<double> x) mutable -> auto { return cpp2::impl::cmp_greater(x,3); }))) {
        std::cout << (cpp2::to_string(v) + " is double bigger than 3") << std::endl;
    }

    if (cpp2::impl::is(v, ([](auto const& x) mutable -> auto { return cpp2::impl::cmp_greater(x,3); }))) {
        std::cout << (cpp2::to_string(v) + " is bigger than 3") << std::endl;
    }
}

#line 15 "pure2-is-with-unnamed-predicates.cpp2"
[[nodiscard]] auto main() -> int{
    fun(3.14);
    fun(42);
    fun('a');
}

