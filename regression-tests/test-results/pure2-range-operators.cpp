
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-range-operators.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-range-operators.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-range-operators.cpp2"
auto main() -> int{

#line 3 "pure2-range-operators.cpp2"
    std::vector v {
        "Aardvark", "Baboon", "Cat", "Dolphin", "Elephant", "Flicker", "Grue", "Wumpus"}; 

    std::cout << "We have some alpabetical animals:\n";
    for ( auto const& e : cpp2::range(CPP2_UFCS(begin)(v),CPP2_UFCS(end)(v)) ) {
        std::cout << "  " + cpp2::to_string(*cpp2::impl::assert_not_null(e)) + "\n";
    }

    std::cout << "\nAnd from indexes 1..=5 they are:\n";
    for ( auto const& e : cpp2::range(1,5,true) ) {
        std::cout << "  " + cpp2::to_string(e) + "  " + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(v, e)) + "\n";
    }

    std::list all_about {
        "Hokey", "Pokey"}; 

    std::cout << "\nMake sure non-random-access iterators work:\n";
    for ( auto const& e : cpp2::range(CPP2_UFCS(begin)(all_about),CPP2_UFCS(end)(cpp2::move(all_about))) ) {
        std::cout << "  " + cpp2::to_string(*cpp2::impl::assert_not_null(e)) + "\n";
    }

}

