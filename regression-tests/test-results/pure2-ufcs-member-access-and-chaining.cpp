
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-ufcs-member-access-and-chaining.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto main() -> int;

#line 26 "pure2-ufcs-member-access-and-chaining.cpp2"
auto no_return([[maybe_unused]] auto const& unnamed_param_1) -> void;

[[nodiscard]] auto ufcs(cpp2::in<int> i) -> int;
using fun_ret = int;


#line 32 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto fun() -> fun_ret;

#line 37 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto get_i(auto const& r) -> int;

#line 41 "pure2-ufcs-member-access-and-chaining.cpp2"
//  And a test for non-local UFCS, which shouldn't do a [&] capture
[[nodiscard]] auto f([[maybe_unused]] auto const& unnamed_param_1) -> int;
extern int y;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto main() -> int{
#line 2 "pure2-ufcs-member-access-and-chaining.cpp2"
    auto i {42}; 
    static_cast<void>(CPP2_UFCS(ufcs)(std::move(i)));

    auto j {fun()}; 
    static_cast<void>(CPP2_UFCS(ufcs)(j));

    static_cast<void>(CPP2_UFCS(ufcs)(fun()));

    auto k {fun()}; 
    static_cast<void>(CPP2_UFCS(ufcs)(std::move(k)));

    static_cast<void>(CPP2_UFCS(ufcs)(get_i(j)));

    static_cast<void>(CPP2_UFCS(ufcs)(get_i(fun())));

    auto res {CPP2_UFCS(ufcs)((42))}; 

    static_cast<void>(CPP2_UFCS(ufcs)((std::move(j))));

    CPP2_UFCS(no_return)(42);

    CPP2_UFCS(no_return)(std::move(res));
}

auto no_return([[maybe_unused]] auto const& unnamed_param_1) -> void{}

[[nodiscard]] auto ufcs(cpp2::in<int> i) -> int{
    return i + 2; 
}

[[nodiscard]] auto fun() -> fun_ret{
        cpp2::deferred_init<int> i;
#line 33 "pure2-ufcs-member-access-and-chaining.cpp2"
    i.construct(42);
    return std::move(i.value()); 
}

[[nodiscard]] auto get_i(auto const& r) -> int{
    return r; 
}

#line 42 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto f([[maybe_unused]] auto const& unnamed_param_1) -> int { return 0;  }
int y {CPP2_UFCS_NONLOCAL(f)(0)}; 

