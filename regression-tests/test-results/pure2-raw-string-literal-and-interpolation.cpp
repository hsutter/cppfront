
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-raw-string-literal-and-interpolation.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-raw-string-literal-and-interpolation.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-raw-string-literal-and-interpolation.cpp2"
[[nodiscard]] auto main() -> int{
#line 2 "pure2-raw-string-literal-and-interpolation.cpp2"
    auto i {42}; 
    std::map<std::string,int> m {}; 
    CPP2_ASSERT_IN_BOUNDS(m, "one") = 1;
    CPP2_ASSERT_IN_BOUNDS(m, "two") = 2;

    std::string str {"this is a string"}; 

    std::string raw_str {R"string(raw string without interpolation)string"}; 

    std::string raw_str_multi {R"test(this is raw string literal

that can last for multiple

lines)test"}; 

    std::string raw_str_inter {R"test(this is raw string literal
that can last for multiple
lines
)test" + cpp2::to_string(i) + R"test( R"(this can be added too)"
calculations like m["one"] + m["two"] = )test" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(m, "one") + CPP2_ASSERT_IN_BOUNDS(m, "two")) + R"test( also works
)test" + cpp2::to_string("at the beginning of the line") +  R"test(!!!)test"}; 

    std::string raw_str_inter_multi {R"(

    )" + cpp2::to_string(i) + cpp2::to_string(i)}; 

    std::cout << std::move(str) << std::endl;
    std::cout << std::move(raw_str) << std::endl;
    std::cout << std::move(raw_str_multi) << std::endl;
    std::cout << std::move(raw_str_inter) << std::endl;
    std::cout << std::move(raw_str_inter_multi) << std::endl;
    std::cout << (cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(m, "one")) + R"(.)" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(m, "two")) + R"(.)" + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(std::move(m), "three")) + R"(.)" + cpp2::to_string(std::move(i))) << std::endl;
}

