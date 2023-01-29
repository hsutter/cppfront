
#line 1 "mixed-lifetime-safety-pointer-init-4.cpp2"

#include <iostream>
#include <random>

#include "cpp2util.h"


#line 5 "mixed-lifetime-safety-pointer-init-4.cpp2"
[[nodiscard]] auto main() -> int;
#line 21 "mixed-lifetime-safety-pointer-init-4.cpp2"
auto print_and_decorate(auto const& thing) -> void;
#line 23 "mixed-lifetime-safety-pointer-init-4.cpp2"

bool flip_a_coin() {
    // Change std::mt19937 to std::random_device for non-deterministic PRNG
    static std::mt19937 rand; 
    return rand() % 2 == 1;
}

//=== Cpp2 definitions ==========================================================

#line 4 "mixed-lifetime-safety-pointer-init-4.cpp2"

[[nodiscard]] auto main() -> int{
    int x {42}; 
    int y {43}; 
    cpp2::deferred_init<int*> p; 

    // ... more code ...
    if (flip_a_coin()) {
        p.construct(&y);
    }
    else {
        p.construct(&x);
    }

    print_and_decorate( *cpp2::assert_not_null(std::move(p.value())));
}

auto print_and_decorate(auto const& thing) -> void { 
    std::cout << ">> " << thing << "\n"; }

