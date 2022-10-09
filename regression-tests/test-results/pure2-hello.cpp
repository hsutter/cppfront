// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-hello.cpp2"
#line 6 "pure2-hello.cpp2"
[[nodiscard]] auto name() -> std::string;
#line 12 "pure2-hello.cpp2"
auto decorate(std::string& s) -> void;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-hello.cpp2"

auto cpp2__main() -> void{
    std::cout << "Hello " << name() << "\n";
}
CPP2_MAIN_VOID_NO_ARGS
[[nodiscard]] auto name() -> std::string{
    std::string s { "world" }; 
    decorate(s);
    return s; 
}

auto decorate(std::string& s) -> void{
    s = "[" + s + "]";
}
