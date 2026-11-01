
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-deferred-init-narrowing-literals.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-deferred-init-narrowing-literals.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-deferred-init-narrowing-literals.cpp2"
[[nodiscard]] auto main() -> int{
#line 2 "pure2-bugfix-for-deferred-init-narrowing-literals.cpp2"
    cpp2::u8 a0 {'a'}; 
    cpp2::impl::deferred_init<cpp2::u8> a; 
    a.construct_from([&]() -> typename CPP2_TYPEOF(a)::value_type { return typename CPP2_TYPEOF(a)::value_type{'a'}; });

    cpp2::i8 b0 {1}; 
    cpp2::impl::deferred_init<cpp2::i8> b; 
    b.construct_from([&]() -> typename CPP2_TYPEOF(b)::value_type { return typename CPP2_TYPEOF(b)::value_type{1}; });

    cpp2::u8 c0 {2}; 
    cpp2::impl::deferred_init<cpp2::u8> c; 
    c.construct_from([&]() -> typename CPP2_TYPEOF(c)::value_type { return typename CPP2_TYPEOF(c)::value_type{2}; });

    cpp2::i16 d0 {3}; 
    cpp2::impl::deferred_init<cpp2::i16> d; 
    d.construct_from([&]() -> typename CPP2_TYPEOF(d)::value_type { return typename CPP2_TYPEOF(d)::value_type{3}; });

    cpp2::u16 e0 {4}; 
    cpp2::impl::deferred_init<cpp2::u16> e; 
    e.construct_from([&]() -> typename CPP2_TYPEOF(e)::value_type { return typename CPP2_TYPEOF(e)::value_type{4}; });

    std::array<cpp2::i8,3> f0 {5, 6, 7}; 
    cpp2::impl::deferred_init<std::array<cpp2::i8,3>> f; 
    f.construct_from([&]() -> typename CPP2_TYPEOF(f)::value_type { return typename CPP2_TYPEOF(f)::value_type{5, 6, 7}; });

    return 0; 
}

