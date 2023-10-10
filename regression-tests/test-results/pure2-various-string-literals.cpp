
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

auto main() -> int;
    

//=== Cpp2 function definitions =================================================

auto main() -> int{
    auto s1 {u"u\""}; 
    auto s2 {U"U\""}; 
    auto s3 {u8"u8\""}; 
    auto s4 {L"L\""}; 
    auto s5 {R"(R")"}; 
    auto s6 {uR"(uR")"}; 
    auto s7 {u8R"(u8R")"}; 
    auto s8 {UR"(UR")"}; 
    auto s9 {LR"(LR")"}; 
}

