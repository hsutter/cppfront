// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-captures-in-expressions-and-postconditions.cpp2"

#include <algorithm>
#include <vector>

[[nodiscard]] auto main() -> int;
#line 17 "mixed-captures-in-expressions-and-postconditions.cpp2"
#line 19 "mixed-captures-in-expressions-and-postconditions.cpp2"
auto insert_at(cpp2::in<int> where, cpp2::in<int> val) -> void;

//=== Cpp2 definitions ==========================================================

#line 4 "mixed-captures-in-expressions-and-postconditions.cpp2"

[[nodiscard]] auto main() -> int{
    std::vector<std::string> vec { 
               "hello", "2022" }; 

    std::string y { "\n" }; 
    auto callback { [_0 = (&y)](auto const& x){std::cout << x << *_0;} }; 

    std::ranges::for_each( vec, callback );
    y = "-ish\n";
    std::ranges::for_each( vec, callback );
}

std::vector<int> vec {  }; 

auto insert_at(cpp2::in<int> where, cpp2::in<int> val) -> void
{   
    cpp2::Default.expects(0 <= where && where <= CPP2_UFCS_0(ssize, vec), "");
    auto post_21_5 = cpp2::finally_success([_0 = CPP2_UFCS_0(ssize, vec)]{cpp2::Default.expects(CPP2_UFCS_0(ssize, vec) == _0 + 1, "");} );
#line 21 "mixed-captures-in-expressions-and-postconditions.cpp2"


    CPP2_UFCS(insert, vec, CPP2_UFCS_0(begin, vec) + where, val);
}
