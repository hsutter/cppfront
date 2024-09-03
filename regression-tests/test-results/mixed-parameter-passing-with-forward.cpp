

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-parameter-passing-with-forward.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-parameter-passing-with-forward.cpp2"

#include <string>
#include <cstdlib>
#include <ctime>

#line 6 "mixed-parameter-passing-with-forward.cpp2"
auto copy_from([[maybe_unused]] auto unnamed_param_1) -> void;

auto parameter_styles(
    [[maybe_unused]] cpp2::impl::in<std::string> unnamed_param_1, // "in" is default
    std::string b, 
    [[maybe_unused]] std::string& unnamed_param_3, 
    std::string&& d, 
    auto&& e
    ) -> void
CPP2_REQUIRES (std::is_convertible_v<CPP2_TYPEOF(e), std::add_const_t<std::string>&>) 
#line 8 "mixed-parameter-passing-with-forward.cpp2"
;

#line 42 "mixed-parameter-passing-with-forward.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-parameter-passing-with-forward.cpp2"

#line 6 "mixed-parameter-passing-with-forward.cpp2"
auto copy_from([[maybe_unused]] auto unnamed_param_1) -> void{}

#line 8 "mixed-parameter-passing-with-forward.cpp2"
auto parameter_styles(
    [[maybe_unused]] cpp2::impl::in<std::string> unnamed_param_1, 
    std::string b, 
    [[maybe_unused]] std::string& unnamed_param_3, 
    std::string&& d, 
    auto&& e
    ) -> void
requires (std::is_convertible_v<CPP2_TYPEOF(e), std::add_const_t<std::string>&>) 
#line 15 "mixed-parameter-passing-with-forward.cpp2"
{
    int z {12}; 

    ++z;
    b += "plugh";

    if (std::rand() % 2) {
        ++z;
        copy_from(cpp2::move(b));// definite last use
    }
    else {
        copy_from(&b);  // NB: better not move from this (why not?)
        copy_from(cpp2::move(d));
        copy_from(++z);
        copy_from(CPP2_FORWARD(e));
    }

    // std::move(z);

    copy_from(z);

    if (std::time(nullptr) % 2 == 0) {
        copy_from(cpp2::move(z));
    }

}

#line 42 "mixed-parameter-passing-with-forward.cpp2"
[[nodiscard]] auto main() -> int{}

