
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-function-multiple-forward-arguments.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-function-multiple-forward-arguments.cpp2"
auto fun(auto&& s1, auto&& s2, auto&& s3) -> void
CPP2_REQUIRES (std::is_convertible_v<CPP2_TYPEOF(s1), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(s2), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(s3), std::add_const_t<std::string>&>) ;

#line 5 "pure2-function-multiple-forward-arguments.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-function-multiple-forward-arguments.cpp2"
auto fun(auto&& s1, auto&& s2, auto&& s3) -> void
requires (std::is_convertible_v<CPP2_TYPEOF(s1), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(s2), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(s3), std::add_const_t<std::string>&>) {
#line 2 "pure2-function-multiple-forward-arguments.cpp2"
    std::cout << CPP2_FORWARD(s1) << CPP2_FORWARD(s2) << CPP2_FORWARD(s3) << std::endl;
}

#line 5 "pure2-function-multiple-forward-arguments.cpp2"
auto main() -> int{
    std::string b {"b"}; 
    std::string c {"c"}; 
    fun(std::string("a"), b, cpp2::move(c));
    b = "";
}

