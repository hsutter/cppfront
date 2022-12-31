// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-cpp1-multitoken-fundamental-types.cpp2"
[[nodiscard]] auto main(cpp2::in<int> argc, cpp2::in<char**> argv) -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-cpp1-multitoken-fundamental-types.cpp2"

[[nodiscard]] auto main(cpp2::in<int> argc, cpp2::in<char**> argv) -> int{
    signed short int a { 1 }; 
    short int signed b { 2 }; 
    long long unsigned int c { 3 }; 
    long double d { 4.0 }; 
    unsigned char e { '5' }; 
    std::cout << cpp2::to_string(a * b + c / d - e) + "\n";
}

