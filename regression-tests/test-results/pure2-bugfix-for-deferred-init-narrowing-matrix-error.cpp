
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-deferred-init-narrowing-matrix-error.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-deferred-init-narrowing-matrix-error.cpp2"
// Target type is {i8, i8}. We try every pair from:
//   ce_i8, ce_i16, rt_i8, rt_i16
// = 4 x 4 = 16 combinations.
//
// Constexpr sources must appear by name in the initializer, otherwise they
// stop being constant expressions and every i16 case would fail.

#line 8 "pure2-bugfix-for-deferred-init-narrowing-matrix-error.cpp2"
cpp2::i8 inline constexpr ce_i8{ 8 };
cpp2::i16 inline constexpr ce_i16{ 8 };

auto try_all_combinations(cpp2::impl::in<cpp2::i8> rt_i8, cpp2::impl::in<cpp2::i16> rt_i16) -> void;

#line 49 "pure2-bugfix-for-deferred-init-narrowing-matrix-error.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-deferred-init-narrowing-matrix-error.cpp2"

#line 11 "pure2-bugfix-for-deferred-init-narrowing-matrix-error.cpp2"
auto try_all_combinations(cpp2::impl::in<cpp2::i8> rt_i8, cpp2::impl::in<cpp2::i16> rt_i16) -> void{
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a00; 
    a00.construct_from([&]() -> typename CPP2_TYPEOF(a00)::value_type { return typename CPP2_TYPEOF(a00)::value_type{ce_i8, ce_i8}; });
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a01; 
    a01.construct_from([&]() -> typename CPP2_TYPEOF(a01)::value_type { return typename CPP2_TYPEOF(a01)::value_type{ce_i8, ce_i16}; });
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a02; 
    a02.construct_from([&]() -> typename CPP2_TYPEOF(a02)::value_type { return typename CPP2_TYPEOF(a02)::value_type{ce_i8, rt_i8}; });
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a03; 
    a03.construct_from([&]() -> typename CPP2_TYPEOF(a03)::value_type { return typename CPP2_TYPEOF(a03)::value_type{ce_i8, rt_i16}; });// fail: runtime i16 -> i8

    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a10; 
    a10.construct_from([&]() -> typename CPP2_TYPEOF(a10)::value_type { return typename CPP2_TYPEOF(a10)::value_type{ce_i16, ce_i8}; });
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a11; 
    a11.construct_from([&]() -> typename CPP2_TYPEOF(a11)::value_type { return typename CPP2_TYPEOF(a11)::value_type{ce_i16, ce_i16}; });
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a12; 
    a12.construct_from([&]() -> typename CPP2_TYPEOF(a12)::value_type { return typename CPP2_TYPEOF(a12)::value_type{ce_i16, rt_i8}; });
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a13; 
    a13.construct_from([&]() -> typename CPP2_TYPEOF(a13)::value_type { return typename CPP2_TYPEOF(a13)::value_type{ce_i16, rt_i16}; });// fail: runtime i16 -> i8

    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a20; 
    a20.construct_from([&]() -> typename CPP2_TYPEOF(a20)::value_type { return typename CPP2_TYPEOF(a20)::value_type{rt_i8, ce_i8}; });
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a21; 
    a21.construct_from([&]() -> typename CPP2_TYPEOF(a21)::value_type { return typename CPP2_TYPEOF(a21)::value_type{rt_i8, ce_i16}; });
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a22; 
    a22.construct_from([&]() -> typename CPP2_TYPEOF(a22)::value_type { return typename CPP2_TYPEOF(a22)::value_type{rt_i8, rt_i8}; });
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a23; 
    a23.construct_from([&]() -> typename CPP2_TYPEOF(a23)::value_type { return typename CPP2_TYPEOF(a23)::value_type{rt_i8, rt_i16}; });// fail: runtime i16 -> i8

    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a30; 
    a30.construct_from([&]() -> typename CPP2_TYPEOF(a30)::value_type { return typename CPP2_TYPEOF(a30)::value_type{rt_i16, ce_i8}; });// fail: runtime i16 -> i8
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a31; 
    a31.construct_from([&]() -> typename CPP2_TYPEOF(a31)::value_type { return typename CPP2_TYPEOF(a31)::value_type{rt_i16, ce_i16}; });// fail: runtime i16 -> i8
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a32; 
    a32.construct_from([&]() -> typename CPP2_TYPEOF(a32)::value_type { return typename CPP2_TYPEOF(a32)::value_type{rt_i16, rt_i8}; });// fail: runtime i16 -> i8
    cpp2::impl::deferred_init<std::array<cpp2::i8,2>> a33; 
    a33.construct_from([&]() -> typename CPP2_TYPEOF(a33)::value_type { return typename CPP2_TYPEOF(a33)::value_type{rt_i16, rt_i16}; });// fail: runtime i16 -> i8
}

#line 49 "pure2-bugfix-for-deferred-init-narrowing-matrix-error.cpp2"
[[nodiscard]] auto main() -> int{
    cpp2::i8 rt_i8 {8}; 
    cpp2::i16 rt_i16 {8}; 
    try_all_combinations(cpp2::move(rt_i8), cpp2::move(rt_i16));
    return 0; 
}

