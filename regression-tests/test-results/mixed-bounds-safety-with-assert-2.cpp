

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


#line 2 "mixed-bounds-safety-with-assert-2.cpp2"
[[nodiscard]] auto main() -> int;
    

#line 10 "mixed-bounds-safety-with-assert-2.cpp2"
auto add_42_to_subrange(auto& rng, cpp2::in<int> start, cpp2::in<int> end) -> void;
#line 23 "mixed-bounds-safety-with-assert-2.cpp2"

#include <vector>
#include <span>
#include <iostream>


//=== Cpp2 function definitions =================================================


#line 2 "mixed-bounds-safety-with-assert-2.cpp2"
[[nodiscard]] auto main() -> int{
    std::vector<int> v {1, 2, 3, 4, 5}; 
    add_42_to_subrange(v, 1, 3);

    for ( auto const& i : v ) 
        std::cout << i << "\n";
}

auto add_42_to_subrange(auto& rng, cpp2::in<int> start, cpp2::in<int> end) -> void
{
    cpp2::Bounds.expects(cpp2::cmp_less_eq(0,start), "");
    cpp2::Bounds.expects(cpp2::cmp_less_eq(end,CPP2_UFCS_0(ssize, rng)), "");

    auto count {0}; 
    for ( 

          auto&  i : rng )  { do 
        if ([_0 = start, _1 = count, _2 = end]{ return cpp2::cmp_less_eq(_0,_1) && cpp2::cmp_less_eq(_1,_2); }()) {
            i += 42;
        } while (false); ++count; }
}

