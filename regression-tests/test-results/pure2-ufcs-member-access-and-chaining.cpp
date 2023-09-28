
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

[[nodiscard]] auto main() -> int;
    

#line 24 "pure2-ufcs-member-access-and-chaining.cpp2"
auto no_return([[maybe_unused]] auto const& param1) -> void;

[[nodiscard]] auto ufcs(cpp2::in<int> i) -> int;
    struct fun_ret { int i; };



#line 30 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto fun() -> fun_ret;
    

#line 35 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto get_i(auto const& r) -> int;
    

#line 39 "pure2-ufcs-member-access-and-chaining.cpp2"
//  And a test for non-local UFCS, which shouldn't do a [&] capture
[[nodiscard]] auto f([[maybe_unused]] auto const& param1) -> int;
extern int y;

//=== Cpp2 function definitions =================================================

[[nodiscard]] auto main() -> int{
    auto i {42}; 
    static_cast<void>(CPP2_UFCS_0(ufcs, std::move(i)));

    auto j {fun()}; 
    static_cast<void>(CPP2_UFCS_0(ufcs, j.i));

    static_cast<void>(CPP2_UFCS_0(ufcs, fun().i));

    auto k {fun().i}; 
    static_cast<void>(CPP2_UFCS_0(ufcs, std::move(k)));

    static_cast<void>(CPP2_UFCS_0(ufcs, get_i(j)));

    static_cast<void>(CPP2_UFCS_0(ufcs, get_i(fun())));

    auto res {CPP2_UFCS_0(ufcs, (42))}; 

    static_cast<void>(CPP2_UFCS_0(ufcs, (std::move(j).i)));

    CPP2_UFCS_0(no_return, 42);
}

auto no_return([[maybe_unused]] auto const& param1) -> void{}

[[nodiscard]] auto ufcs(cpp2::in<int> i) -> int{
    return i + 2; 
}

[[nodiscard]] auto fun() -> fun_ret{
        cpp2::deferred_init<int> i;
#line 31 "pure2-ufcs-member-access-and-chaining.cpp2"
    i.construct(42);
    return  { std::move(i.value()) }; 
}

[[nodiscard]] auto get_i(auto const& r) -> int{
    return r.i; 
}

#line 40 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto f([[maybe_unused]] auto const& param1) -> int { return 0;  }
int y {CPP2_UFCS_0_NONLOCAL(f, 0)}; 

