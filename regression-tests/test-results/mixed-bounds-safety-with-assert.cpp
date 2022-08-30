// ----- Cpp2 support -----
#include "cpp2util.h"


#line 2 "mixed-bounds-safety-with-assert.cpp2"
[[nodiscard]] auto main() -> int;
#line 7 "mixed-bounds-safety-with-assert.cpp2"
auto print_subrange(auto const& rng, cpp2::in<int> start, cpp2::in<int> end) -> void;
#line 19 "mixed-bounds-safety-with-assert.cpp2"

#include <vector>
#include <span>
#include <iostream>

//=== Cpp2 definitions ==========================================================

#line 1 "mixed-bounds-safety-with-assert.cpp2"

[[nodiscard]] auto main() -> int{
    std::vector<int> v { 1, 2, 3, 4, 5 }; 
    print_subrange(v, 1, 13);
}

auto print_subrange(auto const& rng, cpp2::in<int> start, cpp2::in<int> end) -> void{
    cpp2::Bounds.expects(0 <= start, "");
    cpp2::Bounds.expects(end <= CPP2_UFCS_0(size, rng), "");

    auto count { 0 }; 
    for ( auto&& cpp2_range = rng;  

          auto const& i : cpp2_range )  { do 
        if (start <= count && count <= end) {
            std::cout << i << "\n";
        } while (false); ++count; }
}
