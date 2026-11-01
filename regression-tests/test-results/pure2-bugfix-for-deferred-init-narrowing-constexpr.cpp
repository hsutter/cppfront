
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-deferred-init-narrowing-constexpr.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-deferred-init-narrowing-constexpr.cpp2"
cpp2::i32 inline constexpr value{ 20 };
#line 2 "pure2-bugfix-for-deferred-init-narrowing-constexpr.cpp2"

[[nodiscard]] constexpr auto foo() -> cpp2::i32;

[[nodiscard]] constexpr auto add(cpp2::impl::in<cpp2::i32> x, cpp2::impl::in<cpp2::i32> y) -> cpp2::i32;

[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-deferred-init-narrowing-constexpr.cpp2"

#line 3 "pure2-bugfix-for-deferred-init-narrowing-constexpr.cpp2"
[[nodiscard]] constexpr auto foo() -> cpp2::i32 { return 20;  }

#line 5 "pure2-bugfix-for-deferred-init-narrowing-constexpr.cpp2"
[[nodiscard]] constexpr auto add(cpp2::impl::in<cpp2::i32> x, cpp2::impl::in<cpp2::i32> y) -> cpp2::i32 { return x + y;  }

#line 7 "pure2-bugfix-for-deferred-init-narrowing-constexpr.cpp2"
[[nodiscard]] auto main() -> int{
    cpp2::i8 a0 {value + 100}; 
    cpp2::impl::deferred_init<cpp2::i8> a; 
    a.construct_from([&]() -> typename CPP2_TYPEOF(a)::value_type { return typename CPP2_TYPEOF(a)::value_type{value + 100}; });

    cpp2::i8 b0 {foo() + 100}; 
    cpp2::impl::deferred_init<cpp2::i8> b; 
    b.construct_from([&]() -> typename CPP2_TYPEOF(b)::value_type { return typename CPP2_TYPEOF(b)::value_type{foo() + 100}; });

    cpp2::i16 c0 {add(value, foo()) + 100}; 
    cpp2::impl::deferred_init<cpp2::i16> c; 
    c.construct_from([&]() -> typename CPP2_TYPEOF(c)::value_type { return typename CPP2_TYPEOF(c)::value_type{add(value, foo()) + 100}; });

    cpp2::i32 constexpr local{ 10 };

    cpp2::i16 d0 {add(local, foo()) * 2 + value}; 
    cpp2::impl::deferred_init<cpp2::i16> d; 
    d.construct_from([&]() -> typename CPP2_TYPEOF(d)::value_type { return typename CPP2_TYPEOF(d)::value_type{add(local, foo()) * 2 + value}; });

    std::array<cpp2::i8,3> e0 {value + 100, foo() + 100, add(local, foo())}; 
    cpp2::impl::deferred_init<std::array<cpp2::i8,3>> e; 
    e.construct_from([&]() -> typename CPP2_TYPEOF(e)::value_type { return typename CPP2_TYPEOF(e)::value_type{value + 100, foo() + 100, add(local, foo())}; });

    return 0; 
}

