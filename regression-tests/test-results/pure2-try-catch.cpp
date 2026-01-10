
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-try-catch.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-try-catch.cpp2"
[[nodiscard]] auto throwing_pred([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1) -> bool;

#line 7 "pure2-try-catch.cpp2"
auto f(cpp2::impl::in<int> x) -> void;

#line 11 "pure2-try-catch.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-try-catch.cpp2"
[[nodiscard]] auto throwing_pred([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1) -> bool
#line 2 "pure2-try-catch.cpp2"
{
    throw(42);
    return false; 
}

#line 7 "pure2-try-catch.cpp2"
auto f(cpp2::impl::in<int> x) -> void

{
    if (cpp2::cpp2_default.is_active() && !(throwing_pred(x)) ) { cpp2::cpp2_default.report_violation(CPP2_CONTRACT_MSG("a throwing predicate failed, oh my")); }}

#line 11 "pure2-try-catch.cpp2"
auto main() -> int
{
    auto fptr {&f}; 
    try {
        cpp2::move(fptr)(-666);
    } catch (cpp2::impl::in<int> i) {
        std::cout << "oh look, a thrown int: " << i << std::endl;
    }
    try {
        f(-42);
    } catch (...) {
        std::cout << "oh look, another exception" << std::endl;
    }
}

