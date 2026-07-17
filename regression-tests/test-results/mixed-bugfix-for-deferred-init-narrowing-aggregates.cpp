#include <cstdint>


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-bugfix-for-deferred-init-narrowing-aggregates.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-bugfix-for-deferred-init-narrowing-aggregates.cpp2"
#line 2 "mixed-bugfix-for-deferred-init-narrowing-aggregates.cpp2"

struct S {
    std::int8_t x;
    std::int8_t y;
};

struct Nested {
    S left;
    S right;
};

inline constexpr std::int16_t constexpr_i16 = 100;
inline constexpr std::int8_t  constexpr_i8  = 8;

#line 16 "mixed-bugfix-for-deferred-init-narrowing-aggregates.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-bugfix-for-deferred-init-narrowing-aggregates.cpp2"

#line 16 "mixed-bugfix-for-deferred-init-narrowing-aggregates.cpp2"
[[nodiscard]] auto main() -> int{
    cpp2::i8 runtime_i8 {8}; 

    S s_good0 {constexpr_i16, runtime_i8}; 
    cpp2::impl::deferred_init<S> s_good; 
    s_good.construct_from([&]() -> typename CPP2_TYPEOF(s_good)::value_type { return typename CPP2_TYPEOF(s_good)::value_type{constexpr_i16, runtime_i8}; });

    S s_reverse0 {runtime_i8, constexpr_i16}; 
    cpp2::impl::deferred_init<S> s_reverse; 
    s_reverse.construct_from([&]() -> typename CPP2_TYPEOF(s_reverse)::value_type { return typename CPP2_TYPEOF(s_reverse)::value_type{runtime_i8, constexpr_i16}; });

    S s_constexpr0 {constexpr_i16, constexpr_i16}; 
    cpp2::impl::deferred_init<S> s_constexpr; 
    s_constexpr.construct_from([&]() -> typename CPP2_TYPEOF(s_constexpr)::value_type { return typename CPP2_TYPEOF(s_constexpr)::value_type{constexpr_i16, constexpr_i16}; });

    S s_runtime0 {runtime_i8, runtime_i8}; 
    cpp2::impl::deferred_init<S> s_runtime; 
    s_runtime.construct_from([&]() -> typename CPP2_TYPEOF(s_runtime)::value_type { return typename CPP2_TYPEOF(s_runtime)::value_type{runtime_i8, runtime_i8}; });

    Nested nested0 {
        S{constexpr_i16, runtime_i8}, 
        S{constexpr_i8, runtime_i8}}; 

    cpp2::impl::deferred_init<Nested> nested; 
    nested.construct_from([&]() -> typename CPP2_TYPEOF(nested)::value_type { return typename CPP2_TYPEOF(nested)::value_type{
        S{constexpr_i16, runtime_i8}, 
        S{constexpr_i8, cpp2::move(runtime_i8)}}; });

#line 45 "mixed-bugfix-for-deferred-init-narrowing-aggregates.cpp2"
    if (cpp2::cpp2_default.is_active() && !(cpp2::move(s_good0).x == 100 && cpp2::move(s_good.value()).y == 8) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(cpp2::move(s_reverse0).x == 8 && cpp2::move(s_reverse.value()).y == 100) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(cpp2::move(s_constexpr0).x == 100 && cpp2::move(s_constexpr.value()).y == 100) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(cpp2::move(s_runtime0).x == 8 && cpp2::move(s_runtime.value()).y == 8) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(cpp2::move(nested0).left.x == 100 && cpp2::move(nested.value()).right.y == 8) ) { cpp2::cpp2_default.report_violation(""); }

    return 0; 
}

