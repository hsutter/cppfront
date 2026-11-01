#include <cstdint>
#include <array>


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-bugfix-for-out-narrowing.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-bugfix-for-out-narrowing.cpp2"
#line 3 "mixed-bugfix-for-out-narrowing.cpp2"

struct S {
    std::int8_t x;
    std::int8_t y;
};

struct Nested {
    S left;
    S right;
};

inline constexpr std::int16_t constexpr_i16 = 100;

#line 16 "mixed-bugfix-for-out-narrowing.cpp2"
auto fill_i8(cpp2::impl::out<cpp2::i8> x) -> void;

#line 20 "mixed-bugfix-for-out-narrowing.cpp2"
auto fill_array(cpp2::impl::out<std::array<cpp2::i8,3>> a) -> void;

#line 24 "mixed-bugfix-for-out-narrowing.cpp2"
auto fill_s(cpp2::impl::out<S> s, cpp2::impl::in<cpp2::i8> x) -> void;

#line 28 "mixed-bugfix-for-out-narrowing.cpp2"
auto fill_nested(cpp2::impl::out<Nested> n, cpp2::impl::in<cpp2::i8> x) -> void;

#line 35 "mixed-bugfix-for-out-narrowing.cpp2"
// out -> out forwarding still keeps brace-init in the final writer
auto fill_via_fwd(cpp2::impl::out<cpp2::i8> x) -> void;

#line 40 "mixed-bugfix-for-out-narrowing.cpp2"
// first assignment constructs; second goes through the assign path
auto refill_s(cpp2::impl::out<S> s, cpp2::impl::in<cpp2::i8> x) -> void;

#line 46 "mixed-bugfix-for-out-narrowing.cpp2"
auto overwrite_i8(cpp2::impl::out<cpp2::i8> x) -> void;

#line 50 "mixed-bugfix-for-out-narrowing.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-bugfix-for-out-narrowing.cpp2"

#line 16 "mixed-bugfix-for-out-narrowing.cpp2"
auto fill_i8(cpp2::impl::out<cpp2::i8> x) -> void{
    x.construct_from([&]() -> typename CPP2_TYPEOF(x)::value_type { return typename CPP2_TYPEOF(x)::value_type{42}; });
}

#line 20 "mixed-bugfix-for-out-narrowing.cpp2"
auto fill_array(cpp2::impl::out<std::array<cpp2::i8,3>> a) -> void{
    a.construct_from([&]() -> typename CPP2_TYPEOF(a)::value_type { return typename CPP2_TYPEOF(a)::value_type{1, 2, 3}; });
}

#line 24 "mixed-bugfix-for-out-narrowing.cpp2"
auto fill_s(cpp2::impl::out<S> s, cpp2::impl::in<cpp2::i8> x) -> void{
    s.construct_from([&]() -> typename CPP2_TYPEOF(s)::value_type { return typename CPP2_TYPEOF(s)::value_type{constexpr_i16, x}; });
}

#line 28 "mixed-bugfix-for-out-narrowing.cpp2"
auto fill_nested(cpp2::impl::out<Nested> n, cpp2::impl::in<cpp2::i8> x) -> void{
    n.construct_from([&]() -> typename CPP2_TYPEOF(n)::value_type { return typename CPP2_TYPEOF(n)::value_type{
        S{constexpr_i16, x}, 
        S{x, constexpr_i16}}; });

}

#line 36 "mixed-bugfix-for-out-narrowing.cpp2"
auto fill_via_fwd(cpp2::impl::out<cpp2::i8> x) -> void{
    fill_i8(cpp2::impl::out(&x));
}

#line 41 "mixed-bugfix-for-out-narrowing.cpp2"
auto refill_s(cpp2::impl::out<S> s, cpp2::impl::in<cpp2::i8> x) -> void{
    s.construct_from([&]() -> typename CPP2_TYPEOF(s)::value_type { return typename CPP2_TYPEOF(s)::value_type{x, constexpr_i16}; });
    s.value() = { constexpr_i16, x };
}

#line 46 "mixed-bugfix-for-out-narrowing.cpp2"
auto overwrite_i8(cpp2::impl::out<cpp2::i8> x) -> void{
    x.construct_from([&]() -> typename CPP2_TYPEOF(x)::value_type { return typename CPP2_TYPEOF(x)::value_type{100}; });
}

#line 50 "mixed-bugfix-for-out-narrowing.cpp2"
[[nodiscard]] auto main() -> int{
    cpp2::impl::deferred_init<cpp2::i8> a; 
    fill_i8(cpp2::impl::out(&a));

    cpp2::impl::deferred_init<std::array<cpp2::i8,3>> arr; 
    fill_array(cpp2::impl::out(&arr));

    cpp2::i8 runtime_i8 {8}; 

    cpp2::impl::deferred_init<S> s; 
    fill_s(cpp2::impl::out(&s), runtime_i8);

    cpp2::impl::deferred_init<Nested> n; 
    fill_nested(cpp2::impl::out(&n), runtime_i8);

    cpp2::impl::deferred_init<cpp2::i8> b; 
    fill_via_fwd(cpp2::impl::out(&b));

    cpp2::impl::deferred_init<S> s2; 
    refill_s(cpp2::impl::out(&s2), cpp2::move(runtime_i8));

    // already-initialized target: out assigns rather than constructs
    cpp2::i8 c {1}; 
    overwrite_i8(cpp2::impl::out(&c));

    if (cpp2::cpp2_default.is_active() && !(cpp2::move(a.value()) == 42) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(CPP2_ASSERT_IN_BOUNDS_LITERAL(arr.value(), 0) == 1 && CPP2_ASSERT_IN_BOUNDS_LITERAL(arr.value(), 1) == 2 && CPP2_ASSERT_IN_BOUNDS_LITERAL(arr.value(), 2) == 3) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(s.value().x == 100 && s.value().y == 8) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(n.value().left.x == 100 && n.value().left.y == 8) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(n.value().right.x == 8 && n.value().right.y == 100) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(cpp2::move(b.value()) == 42) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(s2.value().x == 100 && s2.value().y == 8) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(cpp2::move(c) == 100) ) { cpp2::cpp2_default.report_violation(""); }

    return 0; 
}

