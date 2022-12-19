// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-forwarding.cpp2"
#include <iostream>
#include <utility>

struct X {
    int i;
    X(int i)         : i{     i} { std::cout << "+X "     << i << "\n"; }
    X(X const& that) : i{that.i} { std::cout << "copy X " << i << "\n"; }
    X(X &&     that) : i{that.i} { std::cout << "move X " << i << "\n"; }
};

auto discard(auto x) -> void;
#line 13 "mixed-forwarding.cpp2"
auto apply_implicit_forward(auto&& t) -> void;
#line 18 "mixed-forwarding.cpp2"
auto apply_explicit_forward(auto&& t) -> void;
#line 23 "mixed-forwarding.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 10 "mixed-forwarding.cpp2"

auto discard(auto x) -> void{}

auto apply_implicit_forward(auto&& t) -> void
requires std::is_same_v<CPP2_TYPEOF(t), std::pair<X,X>>
#line 14 "mixed-forwarding.cpp2"
{   discard(t.first);
    discard(CPP2_FORWARD(t).second);
}

auto apply_explicit_forward(auto&& t) -> void
requires std::is_same_v<CPP2_TYPEOF(t), std::pair<X,X>>
#line 19 "mixed-forwarding.cpp2"
{   discard(CPP2_FORWARD(t.first));
    discard(CPP2_FORWARD(CPP2_FORWARD(t).second));
}

[[nodiscard]] auto main() -> int{
    std::pair<X,X> t1 { 1, 2 }; 
    apply_implicit_forward(std::move(t1));

    std::pair<X,X> t2 { 3, 4 }; 
    apply_explicit_forward(std::move(t2));
}

