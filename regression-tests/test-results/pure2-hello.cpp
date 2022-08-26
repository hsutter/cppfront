// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-hello.cpp2"
[[nodiscard]] auto main() noexcept -> int;
#line 6 "pure2-hello.cpp2"
[[nodiscard]] auto name() noexcept -> std::string;
#line 12 "pure2-hello.cpp2"
auto decorate(std::string& s) noexcept -> void;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-hello.cpp2"

[[nodiscard]] auto main() noexcept -> int{
    std::cout << "Hello " << name() << "\n";
}

[[nodiscard]] auto name() noexcept -> std::string{
    std::string s { "world" }; 
    decorate(s);
    return s; 
}

auto decorate(std::string& s) noexcept -> void{
    s = "[" + s + "]";
}