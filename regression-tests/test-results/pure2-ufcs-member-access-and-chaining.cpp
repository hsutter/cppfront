
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-ufcs-member-access-and-chaining.cpp2"

#line 48 "pure2-ufcs-member-access-and-chaining.cpp2"
class mytype;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto main() -> int;

#line 29 "pure2-ufcs-member-access-and-chaining.cpp2"
auto no_return([[maybe_unused]] auto const& unnamed_param_1) -> void;

[[nodiscard]] auto ufcs(cpp2::impl::in<int> i) -> int;
using fun_ret = int;


#line 35 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto fun() -> fun_ret;

#line 40 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto get_i(auto const& r) -> int;

#line 44 "pure2-ufcs-member-access-and-chaining.cpp2"
//  And a test for non-local UFCS, which shouldn't do a [&] capture
[[nodiscard]] auto f([[maybe_unused]] auto const& unnamed_param_1) -> int;
extern int y;

class mytype {
    public: static auto hun([[maybe_unused]] auto const& unnamed_param_1) -> void;
    public: mytype() = default;
    public: mytype(mytype const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(mytype const&) -> void = delete;

#line 50 "pure2-ufcs-member-access-and-chaining.cpp2"
};


//=== Cpp2 function definitions =================================================

#line 1 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto main() -> int{
#line 2 "pure2-ufcs-member-access-and-chaining.cpp2"
    auto i {42}; 
    static_cast<void>(CPP2_UFCS(ufcs)(cpp2::move(i)));

    auto j {fun()}; 
    static_cast<void>(CPP2_UFCS(ufcs)(j));

    static_cast<void>(CPP2_UFCS(ufcs)(fun()));

    auto k {fun()}; 
    static_cast<void>(CPP2_UFCS(ufcs)(cpp2::move(k)));

    static_cast<void>(CPP2_UFCS(ufcs)(get_i(j)));

    static_cast<void>(CPP2_UFCS(ufcs)(get_i(fun())));

    auto res {CPP2_UFCS(ufcs)((42))}; 

    static_cast<void>(CPP2_UFCS(ufcs)((cpp2::move(j))));

    CPP2_UFCS(no_return)(42);

    CPP2_UFCS(no_return)(cpp2::move(res));

    mytype obj {}; 
    cpp2::move(obj).hun(42);// explicit non-UFCS
}

#line 29 "pure2-ufcs-member-access-and-chaining.cpp2"
auto no_return([[maybe_unused]] auto const& unnamed_param_1) -> void{}

#line 31 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto ufcs(cpp2::impl::in<int> i) -> int{
    return i + 2; 
}

#line 35 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto fun() -> fun_ret{
        cpp2::impl::deferred_init<int> i;
#line 36 "pure2-ufcs-member-access-and-chaining.cpp2"
    i.construct(42);
    return std::move(i.value()); 
}

#line 40 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto get_i(auto const& r) -> int{
    return r; 
}

#line 45 "pure2-ufcs-member-access-and-chaining.cpp2"
[[nodiscard]] auto f([[maybe_unused]] auto const& unnamed_param_1) -> int { return 0;  }
int y {CPP2_UFCS_NONLOCAL(f)(0)}; 

#line 49 "pure2-ufcs-member-access-and-chaining.cpp2"
    auto mytype::hun([[maybe_unused]] auto const& unnamed_param_1) -> void{}

