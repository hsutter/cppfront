

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-bounds-safety-with-assert.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-bounds-safety-with-assert.cpp2"

#line 2 "mixed-bounds-safety-with-assert.cpp2"
[[nodiscard]] auto main() -> int;

#line 9 "mixed-bounds-safety-with-assert.cpp2"
auto print_subrange(auto const& rng, cpp2::in<int> start, cpp2::in<int> end) -> void;
#line 21 "mixed-bounds-safety-with-assert.cpp2"

#include <vector>
#include <span>
#include <iostream>


//=== Cpp2 function definitions =================================================

#line 1 "mixed-bounds-safety-with-assert.cpp2"

#line 2 "mixed-bounds-safety-with-assert.cpp2"
[[nodiscard]] auto main() -> int{
    std::set_terminate(std::abort);

    std::vector<int> v {1, 2, 3, 4, 5}; 
    print_subrange(std::move(v), 1, 13);
}

auto print_subrange(auto const& rng, cpp2::in<int> start, cpp2::in<int> end) -> void{
    if (cpp2::Bounds.has_handler() && !(cpp2::cmp_less_eq(0,start)) ) { cpp2::Bounds.report_violation(""); }
    if (cpp2::Bounds.has_handler() && !(cpp2::cmp_less_eq(end,CPP2_UFCS(ssize)(rng))) ) { cpp2::Bounds.report_violation(""); }

    auto count {0}; 
    for ( 

          auto const& i : rng )  { do 
        if (cpp2::cmp_less_eq(start,count) && cpp2::cmp_less_eq(count,end)) {
            std::cout << i << "\n";
        } while (false); ++count; }
}

