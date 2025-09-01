#line 2 "regression-tests/mixed-multiple-return-values.cpp2"
#include <iostream>
#include <random>
#include <string>


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regression-tests/mixed-multiple-return-values.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "regression-tests/mixed-multiple-return-values.cpp2"


struct f_ret { int i; std::string s; };

#line 6 "regression-tests/mixed-multiple-return-values.cpp2"
[[nodiscard]] auto f() -> f_ret;

#line 22 "regression-tests/mixed-multiple-return-values.cpp2"
auto do_print(cpp2::impl::in<std::string> name, auto const& value) -> void;
#line 25 "regression-tests/mixed-multiple-return-values.cpp2"

int main() {
    auto [a,b] = f();
    do_print("a", a);
    do_print("b", b);
}

bool flip_a_coin() {
    // Change std::mt19937 to std::random_device for non-deterministic PRNG
    static std::mt19937 rand;
    return rand() % 2 == 0;
}


//=== Cpp2 function definitions =================================================

#line 1 "regression-tests/mixed-multiple-return-values.cpp2"

#line 6 "regression-tests/mixed-multiple-return-values.cpp2"
[[nodiscard]] auto f() -> f_ret{
        cpp2::impl::deferred_init<int> i;
        cpp2::impl::deferred_init<std::string> s;
    //  note: i and s are uninitialized!

#line 9 "regression-tests/mixed-multiple-return-values.cpp2"
    i.construct(10);

    // the standard mandates that std::mt19937()() == 3499211612
    if (flip_a_coin()) {
        s.construct("xyzzy");
    }
    else {
        s.construct("plugh");
    }

    return  { std::move(i.value()), std::move(s.value()) }; 
}

#line 22 "regression-tests/mixed-multiple-return-values.cpp2"
auto do_print(cpp2::impl::in<std::string> name, auto const& value) -> void{
    std::cout << name << " is " << value << "\n";
}

