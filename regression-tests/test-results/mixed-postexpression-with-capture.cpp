// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-postexpression-with-capture.cpp2"
#include <vector>
#include <ranges>
#include <string>
#include <span>
#include <algorithm>
#include <iostream>

[[nodiscard]] auto main() -> int;
#line 12 "mixed-postexpression-with-capture.cpp2"
#line 14 "mixed-postexpression-with-capture.cpp2"
auto insert_at(cpp2::in<int> where, cpp2::in<int> val) -> void;

//=== Cpp2 definitions ==========================================================

#line 7 "mixed-postexpression-with-capture.cpp2"

[[nodiscard]] auto main() -> int{
    insert_at( 0, 42 );
}

std::vector<int> vec {  }; 

auto insert_at(cpp2::in<int> where, cpp2::in<int> val) -> void
{   
    cpp2::Default.expects(0 <= where && where <= CPP2_UFCS_0(ssize, vec), "");
    auto post_16_5 = cpp2::finally_success([_0 = CPP2_UFCS_0(size, vec)]{cpp2::Default.expects(CPP2_UFCS_0(size, vec) == _0 + 1, "");} );
#line 16 "mixed-postexpression-with-capture.cpp2"


    CPP2_UFCS(push_back, vec, val);
}
