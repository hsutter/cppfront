// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-string-interpolation.cpp2"
#include <iostream>

[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 2 "mixed-string-interpolation.cpp2"

[[nodiscard]] auto main() -> int{
    auto a { 2 }; 
    std::optional<int> b {  }; 
    std::cout << "a = " + cpp2::to_string(a) + ", b = " + cpp2::to_string(b) + "\n";

    b = 42;
    std::cout << "a^2 + b = " + cpp2::to_string(a * a + b.value()) + "\n";
}
