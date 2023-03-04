
#define CPP2_USE_MODULES         Yes

#include "cpp2util.h"


#line 1 "pure2-raw-string-literal-and-interpolation.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-raw-string-literal-and-interpolation.cpp2"
[[nodiscard]] auto main() -> int{
    auto i {42}; 
    std::map<std::string,int> m {}; 
    cpp2::assert_in_bounds(m, "one") = 1;
    cpp2::assert_in_bounds(m, "two") = 2;

    std::string str {"this is a string"}; 

    std::string raw_str {R"string(raw string without interpolation)string"}; 

    std::string raw_str_multi {R"test(this is raw string literal

that can last for multiple

lines)test"}; 

    std::string raw_str_inter {R"test(this is raw string literal
that can last for multiple
lines
)test" + cpp2::to_string(i) + R"test( R"(this can be added too)"
calculations like m["one"] + m["two"] = )test" + cpp2::to_string(cpp2::assert_in_bounds(m, "one") + cpp2::assert_in_bounds(m, "two")) + R"test( also works
)test" + cpp2::to_string("at the beginning of the line") +  R"test(!!!)test"}; 

    std::string raw_str_inter_multi {R"(

    )" + cpp2::to_string(i) + cpp2::to_string(i)}; 

    std::cout << std::move(str) << std::endl;
    std::cout << std::move(raw_str) << std::endl;
    std::cout << std::move(raw_str_multi) << std::endl;
    std::cout << std::move(raw_str_inter) << std::endl;
    std::cout << std::move(raw_str_inter_multi) << std::endl;
    std::cout << (cpp2::to_string(cpp2::assert_in_bounds(m, "one")) + R"(.)" + cpp2::to_string(cpp2::assert_in_bounds(m, "two")) + R"(.)" + cpp2::to_string(cpp2::assert_in_bounds(std::move(m), "three")) + R"(.)" + cpp2::to_string(std::move(i))) << std::endl;
}

