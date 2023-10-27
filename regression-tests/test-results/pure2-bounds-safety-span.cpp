
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-bounds-safety-span.cpp2"
[[nodiscard]] auto main() -> int;

#line 14 "pure2-bounds-safety-span.cpp2"
auto print_and_decorate(auto const& thing) -> void;
    


//=== Cpp2 function definitions =================================================


#line 2 "pure2-bounds-safety-span.cpp2"
[[nodiscard]] auto main() -> int
{
    std::vector<std::string> words {"decorated", "hello", "world"}; 

    std::span<std::string> s {words}; 

    auto i {0}; 
    for( ; cpp2::cmp_less(i,CPP2_UFCS_0(ssize, s)); ++i ) {
        print_and_decorate(cpp2::assert_in_bounds(s, i));
    }
}

#line 14 "pure2-bounds-safety-span.cpp2"
auto print_and_decorate(auto const& thing) -> void { 
    std::cout << ">> " << thing << "\n";  }

