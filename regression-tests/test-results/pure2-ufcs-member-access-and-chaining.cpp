
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto main() -> int;

#line 22 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto ufcs(cpp2::in<int> i) -> int;
struct fun__ret {
    int i;
    };

#line 26 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto fun() -> fun__ret;

#line 31 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto get_i(auto const& r) -> int;

#line 35 "pure2-ufcs-member-access-and-chaining.cpp2"
//  And a test for non-local UFCS, which shouldn't do a [&] capture
[[nodiscard]] auto f(auto const& x) -> int;
extern int y;
//=== Cpp2 function definitions =================================================

#line 1 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto main() -> int{
    auto i {42}; 
    CPP2_UFCS_0(ufcs, std::move(i));

    auto j {fun()}; 
    CPP2_UFCS_0(ufcs, j.i);

    CPP2_UFCS_0(ufcs, fun().i);

    auto k {fun().i}; 
    CPP2_UFCS_0(ufcs, std::move(k));

    CPP2_UFCS_0(ufcs, get_i(j));

    CPP2_UFCS_0(ufcs, get_i(fun()));

    auto res {CPP2_UFCS_0(ufcs, (42))}; 

    CPP2_UFCS_0(ufcs, (std::move(j).i));
}

[[nodiscard]] auto ufcs(cpp2::in<int> i) -> int{
    return i + 2; 
}

[[nodiscard]] auto fun() -> fun__ret{
        cpp2::deferred_init<int> i;
#line 27 "pure2-ufcs-member-access-and-chaining.cpp2"
    i.construct(42);
    return  { std::move(i.value()) }; 
}

[[nodiscard]] auto get_i(auto const& r) -> int{
    return r.i; 
}

#line 36 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto f(auto const& x) -> int { return 0;  }
int y {CPP2_UFCS_0_NONLOCAL(f, 0)}; 

