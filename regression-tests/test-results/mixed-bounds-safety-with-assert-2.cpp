// ----- Cpp2 support -----
#include "cpp2util.h"


#line 2 "mixed-bounds-safety-with-assert-2.cpp2"
[[nodiscard]] auto main() -> int;
#line 10 "mixed-bounds-safety-with-assert-2.cpp2"
auto add_42_to_subrange(auto& rng, cpp2::in<int> start, cpp2::in<int> end) -> void;
#line 23 "mixed-bounds-safety-with-assert-2.cpp2"

#include <vector>
#include <span>
#include <iostream>

//=== Cpp2 definitions ==========================================================

#line 1 "mixed-bounds-safety-with-assert-2.cpp2"

[[nodiscard]] auto main() -> int{
    std::vector<int> v { 1, 2, 3, 4, 5 }; 
    add_42_to_subrange(v, 1, 3);

    for ( auto&& cpp2_range = v;  auto const& i : cpp2_range ) 
        std::cout << i << "\n";
}

auto add_42_to_subrange(auto& rng, cpp2::in<int> start, cpp2::in<int> end) -> void
{
    cpp2::Bounds.expects(0 <= start, "");
    cpp2::Bounds.expects(end <= CPP2_UFCS_0(size, rng), "");

    auto count { 0 }; 
    for ( auto&& cpp2_range = rng;  

          auto&  i : cpp2_range )  { do 
        if (start <= count && count <= end) {
            i += 42;
        } while (false); ++count; }
}
