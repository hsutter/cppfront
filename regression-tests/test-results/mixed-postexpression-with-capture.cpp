

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#include <vector>
#include <ranges>
#include <string>
#include <span>
#include <algorithm>
#include <iostream>

#line 8 "mixed-postexpression-with-capture.cpp2"
[[nodiscard]] auto main() -> int;
    

#line 12 "mixed-postexpression-with-capture.cpp2"
extern std::vector<int> vec;

auto insert_at(cpp2::in<int> where, cpp2::in<int> val) -> void;
    

//=== Cpp2 function definitions =================================================


#line 8 "mixed-postexpression-with-capture.cpp2"
[[nodiscard]] auto main() -> int{
    insert_at(0, 42);
}

std::vector<int> vec {}; 

auto insert_at(cpp2::in<int> where, cpp2::in<int> val) -> void

#line 17 "mixed-postexpression-with-capture.cpp2"
{
    cpp2::Default.expects(cpp2::cmp_less_eq(0,where) && cpp2::cmp_less_eq(where,CPP2_UFCS_0(ssize, vec)), "");
    auto post_16_5 = cpp2::finally_success([_0 = CPP2_UFCS_0(size, vec)]{cpp2::Default.expects(CPP2_UFCS_0(size, vec) == _0 + 1, "");} );
#line 18 "mixed-postexpression-with-capture.cpp2"
    CPP2_UFCS(push_back, vec, val);
}

