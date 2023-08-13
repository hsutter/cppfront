

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


#include <string>
#include <cstdlib>
#include <ctime>

#line 6 "mixed-parameter-passing.cpp2"
auto copy_from([[maybe_unused]] auto param1) -> void;

auto parameter_styles(
    [[maybe_unused]] cpp2::in<std::string> param1, // "in" is default
    std::string b, 
    [[maybe_unused]] std::string& param3, 
    std::string&& d
    ) -> void;

#line 40 "mixed-parameter-passing.cpp2"
[[nodiscard]] auto main() -> int;


//=== Cpp2 function definitions =================================================


#line 6 "mixed-parameter-passing.cpp2"
auto copy_from([[maybe_unused]] auto param1) -> void{}

auto parameter_styles(
    [[maybe_unused]] cpp2::in<std::string> param1, 
    std::string b, 
    [[maybe_unused]] std::string& param3, 
    std::string&& d
    ) -> void
{
    int z {12}; 

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
    }

    // std::move(z);

    copy_from(z);

    if (std::time(nullptr) % 2==0) {
        copy_from(std::move(z));
    }

}

[[nodiscard]] auto main() -> int{}

