
#define CPP2_USE_MODULES         Yes

#include "cpp2util.h"

#line 1 "pure2-function-multiple-forward-arguments.cpp2"
auto fun(auto&& s1,             auto&&   s2,              auto&&   s3) -> void;

#line 5 "pure2-function-multiple-forward-arguments.cpp2"
auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-function-multiple-forward-arguments.cpp2"
auto fun(auto&& s1,             auto&&   s2,              auto&&   s3) -> void
requires (std::is_same_v<CPP2_TYPEOF(s1), std::string> && std::is_same_v<CPP2_TYPEOF(s2), std::string> && std::is_same_v<CPP2_TYPEOF(s3), std::string>)
#line 1 "pure2-function-multiple-forward-arguments.cpp2"
                                                                                    {
    std::cout << CPP2_FORWARD(s1) << CPP2_FORWARD(s2) << CPP2_FORWARD(s3) << std::endl;
}

auto main() -> int{
    std::string b {"b"}; 
    std::string c {"c"}; 
    fun(std::string("a"), b, std::move(c));
    b = "";
}

