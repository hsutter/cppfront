

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-forwarding.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-forwarding.cpp2"
#include <iostream>
#include <utility>

struct X {
    int i;
    X(int i)         : i{     i} { std::cout << "+X "     << i << "\n"; }
    X(X const& that) : i{that.i} { std::cout << "copy X " << i << "\n"; }
    X(X &&     that) : i{that.i} { std::cout << "move X " << i << "\n"; }
};

#line 11 "mixed-forwarding.cpp2"
auto copy_from([[maybe_unused]] auto unnamed_param_1) -> void;

auto use([[maybe_unused]] auto const& unnamed_param_1) -> void;

// invoking each of these with an rvalue std::pair argument ...
auto apply_implicit_forward(auto&& t) -> void
CPP2_REQUIRES (std::is_convertible_v<CPP2_TYPEOF(t), std::add_const_t<std::pair<X,X>>&>) ;

#line 20 "mixed-forwarding.cpp2"
auto apply_explicit_forward(auto&& t) -> void
CPP2_REQUIRES (std::is_convertible_v<CPP2_TYPEOF(t), std::add_const_t<std::pair<X,X>>&>) ;

#line 25 "mixed-forwarding.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-forwarding.cpp2"

#line 11 "mixed-forwarding.cpp2"
auto copy_from([[maybe_unused]] auto unnamed_param_1) -> void{}

#line 13 "mixed-forwarding.cpp2"
auto use([[maybe_unused]] auto const& unnamed_param_1) -> void{}

#line 16 "mixed-forwarding.cpp2"
auto apply_implicit_forward(auto&& t) -> void
requires (std::is_convertible_v<CPP2_TYPEOF(t), std::add_const_t<std::pair<X,X>>&>) {
#line 17 "mixed-forwarding.cpp2"
    copy_from(t.first);             // copies
    copy_from(CPP2_FORWARD(t).second);// moves
}
#line 20 "mixed-forwarding.cpp2"
auto apply_explicit_forward(auto&& t) -> void
requires (std::is_convertible_v<CPP2_TYPEOF(t), std::add_const_t<std::pair<X,X>>&>) {
#line 21 "mixed-forwarding.cpp2"
    copy_from(CPP2_FORWARD(t).first);// moves
    copy_from(CPP2_FORWARD(t).second);// moves
}

#line 25 "mixed-forwarding.cpp2"
[[nodiscard]] auto main() -> int{
    std::pair<X,X> t1 {1, 2}; 
    apply_implicit_forward(t1);
    use(t1);
    apply_implicit_forward(cpp2::move(t1));

    std::pair<X,X> t2 {3, 4}; 
    apply_explicit_forward(t2);
    use(t2);
    apply_explicit_forward(cpp2::move(t2));
}

