// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-multiple-return-values.cpp2"

#include <string>
#include <iostream>
#include <ctime>

struct f__ret {
    int i;
    std::string s;
    };
#line 7 "mixed-multiple-return-values.cpp2"
[[nodiscard]] auto f() -> f__ret;
#line 21 "mixed-multiple-return-values.cpp2"
auto print(cpp2::in<std::string> name, auto const& value) -> void;
#line 23 "mixed-multiple-return-values.cpp2"

int main() {
    auto [a,b] = f();
    print("a", a);
    print("b", b);
}

//=== Cpp2 definitions ==========================================================

#line 5 "mixed-multiple-return-values.cpp2"

[[nodiscard]] auto f() -> f__ret{
        cpp2::deferred_init<int> i;
        cpp2::deferred_init<std::string> s;
#line 7 "mixed-multiple-return-values.cpp2"
    //  note: i and s are uninitialized!

    i.construct(10);

    if (std::time(nullptr) % 2 == 0) {
        s.construct("xyzzy");
    }
    else {
        s.construct("plugh");
    }

    return  { std::move(i.value()), std::move(s.value()) }; 
}

auto print(cpp2::in<std::string> name, auto const& value) -> void { 
      std::cout << name << " is " << value << "\n"; }
