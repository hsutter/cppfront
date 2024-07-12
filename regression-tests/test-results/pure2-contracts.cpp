
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-contracts.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-contracts.cpp2"
[[nodiscard]] auto test_condition_evaluation(auto const& tag) -> bool;

#line 3 "pure2-contracts.cpp2"
extern bool audit;

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-contracts.cpp2"
[[nodiscard]] auto test_condition_evaluation(auto const& tag) -> bool{std::cout << tag << "\n"; return true; }

#line 3 "pure2-contracts.cpp2"
bool audit {true}; 

#line 5 "pure2-contracts.cpp2"
auto main() -> int{
    //  A few basic tests
    if (cpp2::cpp2_default.is_active() && !(1 != 2) ) { cpp2::cpp2_default.report_violation(CPP2_CONTRACT_MSG("ack, arithmetic is buggy")); }
    if (cpp2::type_safety.is_active() && !(typeid(int) != typeid(double)) ) { cpp2::type_safety.report_violation(CPP2_CONTRACT_MSG("ack, C types are broken")); }

#line 11 "pure2-contracts.cpp2"
    //  Now test that conditions are only evaluated if there's
    //  a handler active + any other control flags are enabled

    if (cpp2::cpp2_default.is_active() && !(test_condition_evaluation(1)) ) { cpp2::cpp2_default.report_violation(CPP2_CONTRACT_MSG("default")); }// evaluated: prints "1"

    //  Type has a handler
    if (cpp2::type_safety.is_active() && !(test_condition_evaluation(2)) ) { cpp2::type_safety.report_violation(CPP2_CONTRACT_MSG("type")); }// evaluated: prints "2"
    CPP2_UFCS(set_handler)(cpp2::type_safety);
    //  Type does not have a handler
    if (cpp2::type_safety.is_active() && !(test_condition_evaluation(3)) ) { cpp2::type_safety.report_violation(CPP2_CONTRACT_MSG("1 == " + cpp2::to_string(1) + "")); }// not evaluated

    //  Bounds has a handler, and audit is true
    if (audit && cpp2::bounds_safety.is_active() && !(test_condition_evaluation(4)) ) { cpp2::bounds_safety.report_violation(CPP2_CONTRACT_MSG("type")); }// evaluated: prints "4"
    audit = false;
    //  Bounds has a handler, but audit is false
    if (audit && cpp2::bounds_safety.is_active() && !(test_condition_evaluation(5)) ) { cpp2::bounds_safety.report_violation(CPP2_CONTRACT_MSG("type")); }// not evaluated

                                                                    // not evaluated
}

