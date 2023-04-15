

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


#include <iostream>
#include <random>
#include <string>
struct f__ret { int i; std::string s; };

#line 6 "mixed-multiple-return-values.cpp2"
[[nodiscard]] auto f() -> f__ret;
    

#line 22 "mixed-multiple-return-values.cpp2"
auto print(cpp2::in<std::string> name, auto const& value) -> void;
    

int main() {
    auto [a,b] = f();
    print("a", a);
    print("b", b);
}

bool flip_a_coin() {
    // Change std::mt19937 to std::random_device for non-deterministic PRNG
    static std::mt19937 rand; 
    return rand() % 2 == 0;
}


//=== Cpp2 function definitions =================================================


#line 6 "mixed-multiple-return-values.cpp2"
[[nodiscard]] auto f() -> f__ret{
        cpp2::deferred_init<int> i;
        cpp2::deferred_init<std::string> s;
    //  note: i and s are uninitialized!

#line 9 "mixed-multiple-return-values.cpp2"
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

auto print(cpp2::in<std::string> name, auto const& value) -> void { 
    std::cout << name << " is " << value << "\n";  }

