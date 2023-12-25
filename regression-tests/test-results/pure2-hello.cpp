
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-hello.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-hello.cpp2"

#line 2 "pure2-hello.cpp2"
[[nodiscard]] auto main() -> int;

#line 6 "pure2-hello.cpp2"
[[nodiscard]] auto name() -> std::string;

#line 12 "pure2-hello.cpp2"
auto decorate(std::string& s) -> void;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-hello.cpp2"

#line 2 "pure2-hello.cpp2"
[[nodiscard]] auto main() -> int{
    std::cout << "Hello " << name() << "\n";
}

[[nodiscard]] auto name() -> std::string{
    std::string s {"world"}; 
    decorate(s);
    return s; 
}

auto decorate(std::string& s) -> void{
    s = "[" + s + "]";
}

