// ----- Cpp2 support -----
#include "cpp2util.h"


#line 2 "mixed-intro-for-with-counter-include-last.cpp2"
[[nodiscard]] auto main() -> int;
#line 10 "mixed-intro-for-with-counter-include-last.cpp2"

#include <vector>
#include <span>
#include <iostream>

//=== Cpp2 definitions ==========================================================

#line 1 "mixed-intro-for-with-counter-include-last.cpp2"

[[nodiscard]] auto main() -> int
{
    std::vector<int> v { 1, 2, 3, 4, 5 }; 
    auto counter { 42 }; 
    for ( auto&& cpp2_range = v;   auto const& i : cpp2_range )  { do {
        std::cout << i << " " << counter << "\n";
    } while (false); counter *= 2; }
}
