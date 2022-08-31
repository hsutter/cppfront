// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-initialization-safety-3.cpp2"
#include <string>
#include <vector>
#include <ctime>

[[nodiscard]] auto main() -> int;
#line 16 "mixed-initialization-safety-3.cpp2"
auto fill(
    cpp2::out<std::string> x, 
    cpp2::in<std::string> value, 
    cpp2::in<int> count
    ) -> void;
#line 26 "mixed-initialization-safety-3.cpp2"
auto print_decorated(auto const& x) -> void;
#line 28 "mixed-initialization-safety-3.cpp2"
[[nodiscard]] auto flip_a_coin() -> bool;

//=== Cpp2 definitions ==========================================================

#line 4 "mixed-initialization-safety-3.cpp2"

[[nodiscard]] auto main() -> int{
    cpp2::deferred_init<std::string> x; // note: uninitialized!

    if (flip_a_coin()) {
        x.construct("xyzzy");
    } else {
        fill(&    x, "plugh", 40 ); // note: constructs x!
    }
    print_decorated(x.value());
}

auto fill(
    cpp2::out<std::string> x, 
    cpp2::in<std::string> value, 
    cpp2::in<int> count
    ) -> void
{   
    cpp2::Default.expects(CPP2_UFCS_0(size, value) >= count, "fill: value must contain at least count elements");
#line 22 "mixed-initialization-safety-3.cpp2"

    x.construct(CPP2_UFCS(substr, value, 0, count));
}

auto print_decorated(auto const& x) -> void { std::cout << ">> [" << x << "]\n"; }

[[nodiscard]] auto flip_a_coin() -> bool { return std::time(nullptr) % 2 == 0; }
