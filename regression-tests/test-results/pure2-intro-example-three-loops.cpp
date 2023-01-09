// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-intro-example-three-loops.cpp2"
auto print(auto const& thing) -> void;
#line 5 "pure2-intro-example-three-loops.cpp2"
auto decorate_and_print(auto& thing) -> void;
#line 10 "pure2-intro-example-three-loops.cpp2"
[[nodiscard]] auto main() -> int;
#line 30 "pure2-intro-example-three-loops.cpp2"


//=== Cpp2 definitions ==========================================================

#line 1 "pure2-intro-example-three-loops.cpp2"

auto print(auto const& thing) -> void { 
    std::cout << ">> " << thing << "\n"; }

auto decorate_and_print(auto& thing) -> void{
    thing = "[" + thing + "]";
    print(thing);
}

[[nodiscard]] auto main() -> int{
    std::vector<std::string> words {
          "hello", "big", "world"}; 
    std::span<std::string> view {words}; 

    auto i {cpp2_new<int>(0)}; 
    for( ; *cpp2::assert_not_null(i) < CPP2_UFCS_0(size, view); ++*cpp2::assert_not_null(i) ) {
        print( cpp2::assert_in_bounds(view, *cpp2::assert_not_null(i)));
    }

    do {
        std::cout << std::setw(4) << "**";
    } while ( *cpp2::assert_not_null(i) > 1 && [&]{ --*cpp2::assert_not_null(i) ; return true; }() );

    std::cout << "\n";
    for ( auto&& cpp2_range = words;  auto& word : cpp2_range ) 
        decorate_and_print(word);

    print(std::string{"end of program"});
}

