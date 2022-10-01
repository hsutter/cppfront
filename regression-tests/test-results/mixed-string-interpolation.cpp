// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-string-interpolation.cpp2"
#include <iostream>
#include <string_view>
#include <utility> // std::pair

const char carr[] = "carray test";

[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 6 "mixed-string-interpolation.cpp2"

[[nodiscard]] auto main() -> int{
    auto a { 2 }; 
    std::optional<int> b {  }; 
    std::cout << "a = " + cpp2::to_string(a) + ", b = " + cpp2::to_string(b) + "\n";

    b = 42;
    std::cout << "a^2 + b = " + cpp2::to_string(a * a + b.value()) + "\n";

    std::cout << "carr = " + cpp2::to_string(carr) + "\n";

    std::string_view sv { "SV works!" }; 
    std::cout << "sv = " + cpp2::to_string(sv) + "\n";

    std::optional<std::string_view> osv {  }; 
    std::cout << "osv = " + cpp2::to_string(osv) + "\n";
    osv = "It works, too";
    std::cout << "osv = " + cpp2::to_string(osv) + "\n";

    std::pair<std::string_view,std::optional<std::string>> p { "first", std::nullopt }; 
    std::cout << "p = " + cpp2::to_string(p) + "\n";
    p.second = "second";
    std::cout << "p = " + cpp2::to_string(p) + "\n";
}
