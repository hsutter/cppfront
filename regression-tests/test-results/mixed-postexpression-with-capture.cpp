

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-postexpression-with-capture.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-postexpression-with-capture.cpp2"
#include <vector>
#include <ranges>
#include <string>
#include <span>
#include <algorithm>
#include <iostream>

#line 8 "mixed-postexpression-with-capture.cpp2"
[[nodiscard]] auto main() -> int;

#line 14 "mixed-postexpression-with-capture.cpp2"
extern std::vector<int> vec;

auto insert_at(cpp2::impl::in<int> where, cpp2::impl::in<int> val) -> void;
using make_string_ret = std::string;


#line 23 "mixed-postexpression-with-capture.cpp2"
[[nodiscard]] auto make_string() -> make_string_ret;
struct make_strings_ret { std::string a; std::string b; };



#line 29 "mixed-postexpression-with-capture.cpp2"
[[nodiscard]] auto make_strings() -> make_strings_ret;
#line 38 "mixed-postexpression-with-capture.cpp2"

#line 1 "mixed-postexpression-with-capture.cpp2"

//=== Cpp2 function definitions =================================================

#line 1 "mixed-postexpression-with-capture.cpp2"

#line 8 "mixed-postexpression-with-capture.cpp2"
[[nodiscard]] auto main() -> int{
    insert_at(0, 42);
    std::cout << make_string() + "plugh\n";
    std::cout << make_strings().a + make_strings().b + "\n";
}

std::vector<int> vec {}; 

#line 16 "mixed-postexpression-with-capture.cpp2"
auto insert_at(cpp2::impl::in<int> where, cpp2::impl::in<int> val) -> void

#line 19 "mixed-postexpression-with-capture.cpp2"
{
    cpp2::finally_presuccess cpp2_finally_presuccess;
    if (cpp2::cpp2_default.is_active() && !(cpp2::impl::cmp_less_eq(0,where) && cpp2::impl::cmp_less_eq(where,CPP2_UFCS(ssize)(vec))) ) { cpp2::cpp2_default.report_violation(""); }
    cpp2_finally_presuccess.add([&, _1 = CPP2_UFCS(size)(vec)]{if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(size)(vec) == _1 + 1) ) { cpp2::cpp2_default.report_violation(""); }} );
#line 20 "mixed-postexpression-with-capture.cpp2"
    CPP2_UFCS(push_back)(vec, val);
}

#line 23 "mixed-postexpression-with-capture.cpp2"
[[nodiscard]] auto make_string() -> make_string_ret

{
    cpp2::finally_presuccess cpp2_finally_presuccess;
    std::string ret {"xyzzy"};
    cpp2_finally_presuccess.add([&, _1 = CPP2_UFCS(length)(ret)]{if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(length)(ret) == _1 + 5) ) { cpp2::cpp2_default.report_violation(""); }} );
#line 26 "mixed-postexpression-with-capture.cpp2"
    ret += " and ";
cpp2_finally_presuccess.run(); return ret; }

#line 29 "mixed-postexpression-with-capture.cpp2"
[[nodiscard]] auto make_strings() -> make_strings_ret

#line 35 "mixed-postexpression-with-capture.cpp2"
{
cpp2::finally_presuccess cpp2_finally_presuccess;
std::string a {"xyzzy"};
std::string b {"plugh"};
cpp2_finally_presuccess.add([&]{if (cpp2::cpp2_default.is_active() && !([_0 = CPP2_UFCS(length)(a), _1 = CPP2_UFCS(length)(b), _2 = 5]{ return _0==_1 && _1==_2; }()) ) { cpp2::cpp2_default.report_violation(""); }} );
#line 30 "mixed-postexpression-with-capture.cpp2"
cpp2_finally_presuccess.run(); return  { std::move(a), std::move(b) }; 

#line 36 "mixed-postexpression-with-capture.cpp2"
    // 'return' is generated when omitted like this
}

