// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-lifetime-safety-pointer-init-4.cpp2"

#include <cstdlib>
#include <iostream>

[[nodiscard]] auto main() -> int;
#line 21 "mixed-lifetime-safety-pointer-init-4.cpp2"
auto print_and_decorate(auto const& thing) -> void;
#line 23 "mixed-lifetime-safety-pointer-init-4.cpp2"


//=== Cpp2 definitions ==========================================================

#line 4 "mixed-lifetime-safety-pointer-init-4.cpp2"

[[nodiscard]] auto main() -> int{
    int x { 42 }; 
    int y { 43 }; 
    cpp2::deferred_init<int*> p; 

    // ... more code ...
    if (std::rand() % 2) {
        p.construct(&y);
    }
    else {
        p.construct(&x);
    }

    print_and_decorate( *p.value());
}

auto print_and_decorate(auto const& thing) -> void { 
    std::cout << ">> " << thing << "\n"; }
