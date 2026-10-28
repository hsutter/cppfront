
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-deferred-init-narrowing-negative-literals.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-deferred-init-narrowing-negative-literals.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-deferred-init-narrowing-negative-literals.cpp2"
[[nodiscard]] auto main() -> int{
#line 2 "pure2-bugfix-for-deferred-init-narrowing-negative-literals.cpp2"
    cpp2::i8 a0 {-1}; 
    cpp2::impl::deferred_init<cpp2::i8> a; 
    a.construct_from([&]() -> typename CPP2_TYPEOF(a)::value_type { return typename CPP2_TYPEOF(a)::value_type{-1}; });

    cpp2::i16 b0 {-2}; 
    cpp2::impl::deferred_init<cpp2::i16> b; 
    b.construct_from([&]() -> typename CPP2_TYPEOF(b)::value_type { return typename CPP2_TYPEOF(b)::value_type{-2}; });

    std::array<cpp2::i8,3> c0 {-3, -4, -5}; 
    cpp2::impl::deferred_init<std::array<cpp2::i8,3>> c; 
    c.construct_from([&]() -> typename CPP2_TYPEOF(c)::value_type { return typename CPP2_TYPEOF(c)::value_type{-3, -4, -5}; });

    return 0; 
}

