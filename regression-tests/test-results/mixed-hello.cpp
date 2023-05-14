

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


#include <iostream>
#include <string>

#line 5 "mixed-hello.cpp2"
[[nodiscard]] auto name() -> std::string;
    

#line 11 "mixed-hello.cpp2"
auto decorate(std::string& s) -> void;
    
#line 14 "mixed-hello.cpp2"

auto main() -> int {
    // name();
    std::cout << "Hello " << name() << "\n";
}


//=== Cpp2 function definitions =================================================


#line 5 "mixed-hello.cpp2"
[[nodiscard]] auto name() -> std::string{
    std::string s {"world"}; 
    decorate(s);
    return s; 
}

auto decorate(std::string& s) -> void{
    s = "[" + s + "]";
}

