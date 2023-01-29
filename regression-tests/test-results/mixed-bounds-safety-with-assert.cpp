

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
    std::vector<int> v {1, 2, 3, 4, 5}; 
    print_subrange(std::move(v), 1, 13);
}

auto print_subrange(auto const& rng, cpp2::in<int> start, cpp2::in<int> end) -> void{
    cpp2::Bounds.expects(cpp2::cmp_less_eq(0,start), "");
    cpp2::Bounds.expects(cpp2::cmp_less_eq(end,CPP2_UFCS_0(ssize, rng)), "");

    auto count {0}; 
    for ( auto const& cpp2_range = rng;  

          auto const& i : cpp2_range )  { do 
        if (cpp2::cmp_less_eq(start,count) && cpp2::cmp_less_eq(count,end)) {
            std::cout << i << "\n";
        } while (false); ++count; }
}

