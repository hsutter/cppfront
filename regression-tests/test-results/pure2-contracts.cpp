
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-contracts.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-contracts.cpp2"
[[nodiscard]] auto test_condition_evaluation(auto const& tag) -> bool;

#line 3 "pure2-contracts.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-contracts.cpp2"
[[nodiscard]] auto test_condition_evaluation(auto const& tag) -> bool{std::cout << tag << "\n"; return true; }

#line 3 "pure2-contracts.cpp2"
auto main() -> int{
    if (cpp2::Default.has_handler() && !(1 != 2) ) { cpp2::Default.violation("ack, arithmetic is buggy"); }
    if (cpp2::Type.has_handler() && !(typeid(int) != typeid(double)) ) { cpp2::Type.violation("ack, C types are broken"); }

#line 8 "pure2-contracts.cpp2"
    if (cpp2::Default.has_handler() && !(test_condition_evaluation(1)) ) { cpp2::Default.violation("default"); }// evaluated: prints "1"
    if (cpp2::Type.has_handler() && !(test_condition_evaluation(2)) ) { cpp2::Type.violation("type"); }// evaluated: prints "2"
    CPP2_UFCS(set_handler)(cpp2::Type);
    if (cpp2::Type.has_handler() && !(test_condition_evaluation(3)) ) { cpp2::Type.violation("type"); }// not evaluated
                                                            // not evaluated
}

