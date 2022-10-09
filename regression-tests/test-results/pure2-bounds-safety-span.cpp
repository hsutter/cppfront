// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-bounds-safety-span.cpp2"
#line 14 "pure2-bounds-safety-span.cpp2"
auto print_and_decorate(auto const& thing) -> void;
#line 16 "pure2-bounds-safety-span.cpp2"


//=== Cpp2 definitions ==========================================================

#line 1 "pure2-bounds-safety-span.cpp2"

auto cpp2__main() -> void
{
    std::vector<std::string> words { "decorated", "hello", "world" }; 

    std::span<std::string> s { words }; 

    auto i { 0 }; 
    for( ; i < CPP2_UFCS_0(ssize, s); ++i ) {
        print_and_decorate( s[i] );
    }
}
CPP2_MAIN_VOID_NO_ARGS
auto print_and_decorate(auto const& thing) -> void { 
    std::cout << ">> " << thing << "\n"; }
