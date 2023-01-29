
#line 1 "mixed-multiple-return-values.cpp2"

#include <iostream>
#include <random>
#include <string>

#include "cpp2util.h"


#line 6 "mixed-multiple-return-values.cpp2"
struct f__ret {
    int i;
    std::string s;
    };
#line 7 "mixed-multiple-return-values.cpp2"
[[nodiscard]] auto f() -> f__ret;
#line 22 "mixed-multiple-return-values.cpp2"
auto print(cpp2::in<std::string> name, auto const& value) -> void;
#line 24 "mixed-multiple-return-values.cpp2"

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

//=== Cpp2 definitions ==========================================================

#line 5 "mixed-multiple-return-values.cpp2"

[[nodiscard]] auto f() -> f__ret{
        cpp2::deferred_init<int> i;
        cpp2::deferred_init<std::string> s;
#line 7 "mixed-multiple-return-values.cpp2"
    //  note: i and s are uninitialized!

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
      std::cout << name << " is " << value << "\n"; }

