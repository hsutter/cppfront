// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-test-parens.cpp2"
#include <vector>

template<bool>
auto f(auto, auto) -> void { }

[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 5 "mixed-test-parens.cpp2"

[[nodiscard]] auto main() -> int{
    std::vector<int> v { 1, 2, 3 }; 
    std::cout << (1 + 2) * (3 + v[0]);
    f<(1 > 2)>(3, 4);
}
