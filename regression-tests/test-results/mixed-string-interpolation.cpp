// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-string-interpolation.cpp2"
#include <iostream>
#include <string_view>
#include <utility> // std::pair
#include <tuple>

const char carr[] = "carray test";

[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 7 "mixed-string-interpolation.cpp2"

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

    std::tuple<double,std::optional<std::pair<std::string_view,int>>,std::optional<std::tuple<int,int,int>>> t { 3.14, std::nullopt, std::nullopt }; 
    std::cout << "t = " + cpp2::to_string(t) + "\n";
    std::get<1>(t) = std::pair(std::string_view("answer"), 42);
    std::cout << "t = " + cpp2::to_string(t) + "\n";
    std::get<2>(t) = std::make_tuple(2022, 10, 1);
    std::cout << "t = " + cpp2::to_string(t) + "\n";
}
