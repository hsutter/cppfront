// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-parameter-passing.cpp2"

#include <chrono>
#include <random>
#include <string>

auto copy_from(auto x) -> void;
#line 8 "mixed-parameter-passing.cpp2"
auto parameter_styles(
    cpp2::in<std::string> a, 
    std::string b, 
    std::string& c, 
    std::string&& d
    ) -> void;
#line 41 "mixed-parameter-passing.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 5 "mixed-parameter-passing.cpp2"

auto copy_from(auto x) -> void{}

auto parameter_styles(
    cpp2::in<std::string> a, // "in" is default
    std::string b, 
    std::string& c, 
    std::string&& d
    ) -> void
{
    int z { 12 }; 

    ++z;
    b += "plugh";

    // the standard mandates that std::mt19937()() == 3499211612
    if (std::mt19937()() % 2) {
        ++z;
        copy_from(std::move(b));// definite last use
    }
    else {
        copy_from(&b);  // NB: better not move from this (why not?)
        copy_from(std::move(d));
        copy_from(++z);
    }

    // std::move(z);

    copy_from(z);

    if (CPP2_UFCS_0(count, CPP2_UFCS_0(time_since_epoch, std::chrono::system_clock::now())) % 2 == 0) {
        copy_from(std::move(z));
    }

}

[[nodiscard]] auto main() -> int{}

