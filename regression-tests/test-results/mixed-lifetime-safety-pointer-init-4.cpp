

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-lifetime-safety-pointer-init-4.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-lifetime-safety-pointer-init-4.cpp2"

#include <iostream>
#include <random>

#line 5 "mixed-lifetime-safety-pointer-init-4.cpp2"
[[nodiscard]] auto main() -> int;

#line 21 "mixed-lifetime-safety-pointer-init-4.cpp2"
auto print_and_decorate(auto const& x) -> void;
#line 24 "mixed-lifetime-safety-pointer-init-4.cpp2"

bool flip_a_coin() {
    // Change std::mt19937 to std::random_device for non-deterministic PRNG
    static std::mt19937 rand; 
    return rand() % 2 == 1;
}


//=== Cpp2 function definitions =================================================

#line 1 "mixed-lifetime-safety-pointer-init-4.cpp2"

#line 5 "mixed-lifetime-safety-pointer-init-4.cpp2"
[[nodiscard]] auto main() -> int{
    int x {42}; 
    int y {43}; 
    cpp2::impl::deferred_init<int*> p; 

    // ... more code ...
    if (flip_a_coin()) {
        p.construct(&y);
    }
    else {
        p.construct(&x);
    }

    print_and_decorate(*cpp2::impl::assert_not_null(cpp2::move(p.value())));
}

#line 21 "mixed-lifetime-safety-pointer-init-4.cpp2"
auto print_and_decorate(auto const& x) -> void{
    std::cout << ">> " << x << "\n";
}

