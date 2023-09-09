
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

auto fun(auto&& s1, auto&& s2, auto&& s3) -> void
CPP2_REQUIRES (std::is_same_v<CPP2_TYPEOF(s1), std::string> && std::is_same_v<CPP2_TYPEOF(s2), std::string> && std::is_same_v<CPP2_TYPEOF(s3), std::string>);
    

#line 5 "pure2-function-multiple-forward-arguments.cpp2"
auto main() -> int;
    

//=== Cpp2 function definitions =================================================

auto fun(auto&& s1, auto&& s2, auto&& s3) -> void
requires (std::is_same_v<CPP2_TYPEOF(s1), std::string> && std::is_same_v<CPP2_TYPEOF(s2), std::string> && std::is_same_v<CPP2_TYPEOF(s3), std::string>){
    std::cout << CPP2_FORWARD(s1) << CPP2_FORWARD(s2) << CPP2_FORWARD(s3) << std::endl;
}

auto main() -> int{
    std::string b {"b"}; 
    std::string c {"c"}; 
    fun(std::string("a"), b, std::move(c));
    b = "";
}

