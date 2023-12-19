
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bounds-safety-span.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bounds-safety-span.cpp2"

#line 2 "pure2-bounds-safety-span.cpp2"
[[nodiscard]] auto main() -> int;

#line 15 "pure2-bounds-safety-span.cpp2"
auto print_and_decorate(auto const& thing) -> void;
#line 17 "pure2-bounds-safety-span.cpp2"

#line 1 "pure2-bounds-safety-span.cpp2"

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bounds-safety-span.cpp2"

#line 2 "pure2-bounds-safety-span.cpp2"
[[nodiscard]] auto main() -> int
{
    std::vector<std::string> words {"decorated", "hello", "world"}; 

    std::span<std::string> s {words}; 
    static_cast<void>(std::move(words));

    auto i {0}; 
    for( ; cpp2::cmp_less(i,CPP2_UFCS(ssize)(s)); ++i ) {
        print_and_decorate(CPP2_ASSERT_IN_BOUNDS(s, i));
    }
}

auto print_and_decorate(auto const& thing) -> void { 
    std::cout << ">> " << thing << "\n";  }

