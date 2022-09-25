// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-parameter-passing-with-forward.cpp2"

#include <string>
#include <cstdlib>
#include <ctime>

auto copy_from(auto x) -> void;
#line 8 "mixed-parameter-passing-with-forward.cpp2"
auto parameter_styles(
    cpp2::in<std::string> a, 
    std::string b, 
    std::string& c, 
    std::string&& d, 
    auto&&  e
    ) -> void;
#line 42 "mixed-parameter-passing-with-forward.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 5 "mixed-parameter-passing-with-forward.cpp2"

auto copy_from(auto x) -> void{}

auto parameter_styles(
    cpp2::in<std::string> a, // "in" is default
    std::string b, 
    std::string& c, 
    std::string&& d, 
    auto&&  e
    ) -> void
requires std::is_same_v<CPP2_TYPEOF(e), std::string>
#line 15 "mixed-parameter-passing-with-forward.cpp2"
{
    int z { 12 }; 

    ++z;
    b += "plugh";

    if (std::rand() % 2) {
        ++z;
        copy_from(std::move(b));// definite last use
    }
    else {
        copy_from(&b);  // NB: better not move from this (why not?)
        copy_from(std::move(d));
        copy_from(++z);
        copy_from(CPP2_FORWARD(e));
    }

    // std::move(z);

    copy_from(z);

    if (std::time(nullptr) % 2 == 0) {
        copy_from(z);
    }

}

[[nodiscard]] auto main() -> int{}
