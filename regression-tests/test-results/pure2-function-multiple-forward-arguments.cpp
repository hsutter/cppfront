
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-function-multiple-forward-arguments.cpp2"
auto fun(auto&& s1, auto&& s2, auto&& s3) -> void
CPP2_REQUIRES (cpp2::is<CPP2_TYPEOF(s1), std::string>() && cpp2::is<CPP2_TYPEOF(s2), std::string>() && cpp2::is<CPP2_TYPEOF(s3), std::string>())
#line 1 "pure2-function-multiple-forward-arguments.cpp2"
;
    

#line 5 "pure2-function-multiple-forward-arguments.cpp2"
auto main() -> int;
    

//=== Cpp2 function definitions =================================================

#line 1 "pure2-function-multiple-forward-arguments.cpp2"
auto fun(auto&& s1, auto&& s2, auto&& s3) -> void
requires (cpp2::is<CPP2_TYPEOF(s1), std::string>() && cpp2::is<CPP2_TYPEOF(s2), std::string>() && cpp2::is<CPP2_TYPEOF(s3), std::string>())
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

