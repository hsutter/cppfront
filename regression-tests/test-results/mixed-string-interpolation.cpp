
#line 1 "mixed-string-interpolation.cpp2"
#include <iostream>
#include <string_view>
#include <utility>
#include <tuple>

struct custom_struct_with_no_stringize_customization { } custom;

#include "cpp2util.h"


#line 8 "mixed-string-interpolation.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 7 "mixed-string-interpolation.cpp2"

[[nodiscard]] auto main() -> int{
    auto a {2}; 
    std::optional<int> b {}; 
    std::cout << "a = " + cpp2::to_string(a) + ", b = " + cpp2::to_string(b) + "\n";

    b = 42;
    std::cout << "a^2 + b = " + cpp2::to_string(a * std::move(a) + CPP2_UFCS_0(value, std::move(b))) + "\n";

    std::string_view sv {"my string_view"}; 
    std::cout << "sv = " + cpp2::to_string(std::move(sv)) + "\n";

    std::optional<std::string_view> osv {}; 
    std::cout << "osv = " + cpp2::to_string(osv) + "\n";
    osv = "string literal bound to optional string_view";
    std::cout << "osv = " + cpp2::to_string(std::move(osv)) + "\n";

    std::variant<std::monostate,std::string,double> var {}; 
    std::cout << "var = " + cpp2::to_string(var) + "\n";
    var = "abracadabra";
    std::cout << "var = " + cpp2::to_string(var) + "\n";
    var = 2.71828;
    std::cout << "var = " + cpp2::to_string(std::move(var)) + "\n";

    std::pair<int,double> mypair {12, 3.4}; 
    std::cout << "mypair = " + cpp2::to_string(std::move(mypair)) + "\n";

    std::tuple<int> tup1 {12}; 
    std::tuple<int,double> tup2 {12, 3.4}; 
    std::tuple<int,double,std::string> tup3 {12, 3.4, "456"}; 
    std::cout << "tup1 = " + cpp2::to_string(std::move(tup1)) + "\n";
    std::cout << "tup2 = " + cpp2::to_string(std::move(tup2)) + "\n";
    std::cout << "tup3 = " + cpp2::to_string(std::move(tup3)) + "\n";

    std::pair<std::string_view,std::optional<std::string>> p {"first", std::nullopt}; 
    std::cout << "p = " + cpp2::to_string(std::move(p)) + "\n";

    std::tuple<double,std::optional<std::pair<std::string_view,int>>,std::optional<std::tuple<int,int,int>>> t {3.14, std::nullopt, std::nullopt}; 
    std::cout << "t = " + cpp2::to_string(std::move(t)) + "\n";

    std::variant<int,std::string,std::pair<int,double>> vv {}; 
    std::cout << "vv = " + cpp2::to_string(vv) + "\n";
    vv = std::make_pair(1, 2.3);
    std::cout << "vv = " + cpp2::to_string(std::move(vv)) + "\n";

    std::cout << "custom = " + cpp2::to_string(custom) + "\n";
}

