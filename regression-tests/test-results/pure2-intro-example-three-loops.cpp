
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-intro-example-three-loops.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-intro-example-three-loops.cpp2"

#line 2 "pure2-intro-example-three-loops.cpp2"
auto print(auto const& thing) -> void;

#line 5 "pure2-intro-example-three-loops.cpp2"
auto decorate_and_print(auto& thing) -> void;

#line 10 "pure2-intro-example-three-loops.cpp2"
[[nodiscard]] auto main() -> int;
#line 30 "pure2-intro-example-three-loops.cpp2"

#line 1 "pure2-intro-example-three-loops.cpp2"

//=== Cpp2 function definitions =================================================

#line 1 "pure2-intro-example-three-loops.cpp2"

#line 2 "pure2-intro-example-three-loops.cpp2"
auto print(auto const& thing) -> void { 
    std::cout << ">> " << thing << "\n";  }

auto decorate_and_print(auto& thing) -> void{
    thing = "[" + thing + "]";
    print(thing);
}

[[nodiscard]] auto main() -> int{
    std::vector<std::string> words {
        "hello", "big", "world"}; 
    std::span<std::string> view {words}; 

    auto i {cpp2_new<int>(0)}; 
    for( ; cpp2::cmp_less(*cpp2::assert_not_null(i),CPP2_UFCS(ssize)(view)); ++*cpp2::assert_not_null(i) ) {
        print(CPP2_ASSERT_IN_BOUNDS(view, *cpp2::assert_not_null(i)));
    }

    do {
        std::cout << std::setw(4) << "**";
    } while ( [&]{ --*cpp2::assert_not_null(i) ; return true; }() && cpp2::cmp_greater(*cpp2::assert_not_null(i),0));

    std::cout << "\n";
    for ( auto& word : words ) 
        decorate_and_print(word);

    print(std::string{"end of program"});
}

