

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-captures-in-expressions-and-postconditions.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-captures-in-expressions-and-postconditions.cpp2"

#include <algorithm>
#include <vector>

#line 5 "mixed-captures-in-expressions-and-postconditions.cpp2"
[[nodiscard]] auto main() -> int;

#line 17 "mixed-captures-in-expressions-and-postconditions.cpp2"
extern std::vector<int> vec;

auto insert_at(cpp2::impl::in<int> where, cpp2::impl::in<int> val) -> void;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-captures-in-expressions-and-postconditions.cpp2"

#line 5 "mixed-captures-in-expressions-and-postconditions.cpp2"
[[nodiscard]] auto main() -> int{
    std::vector<std::string> vec {
            "hello", "2022"}; 

    std::string y {"\n"}; 
    auto callback {[_0 = (&y)](auto const& x) mutable -> decltype(auto) { return std::cout << x << *cpp2::impl::assert_not_null(_0);  }}; 

    std::ranges::for_each(vec, callback);
    y = "-ish\n";
    std::ranges::for_each(cpp2::move(vec), cpp2::move(callback));
}

std::vector<int> vec {}; 

#line 19 "mixed-captures-in-expressions-and-postconditions.cpp2"
auto insert_at(cpp2::impl::in<int> where, cpp2::impl::in<int> val) -> void

#line 22 "mixed-captures-in-expressions-and-postconditions.cpp2"
{
    cpp2::finally_presuccess cpp2_finally_presuccess;
    if (cpp2::cpp2_default.is_active() && !(cpp2::impl::cmp_less_eq(0,where) && cpp2::impl::cmp_less_eq(where,CPP2_UFCS(ssize)(vec))) ) { cpp2::cpp2_default.report_violation(""); }
    cpp2_finally_presuccess.add([&, _1 = CPP2_UFCS(ssize)(vec)]{if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(ssize)(vec) == _1 + 1) ) { cpp2::cpp2_default.report_violation(""); }} );
#line 23 "mixed-captures-in-expressions-and-postconditions.cpp2"
    static_cast<void>(CPP2_UFCS(insert)(vec, CPP2_UFCS(begin)(vec) + where, val));
}

