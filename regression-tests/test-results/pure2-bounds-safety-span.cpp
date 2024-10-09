
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bounds-safety-span.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bounds-safety-span.cpp2"

#line 2 "pure2-bounds-safety-span.cpp2"
[[nodiscard]] auto main() -> int;

#line 15 "pure2-bounds-safety-span.cpp2"
auto print_and_decorate(auto const& x) -> void;
#line 18 "pure2-bounds-safety-span.cpp2"

#line 1 "pure2-bounds-safety-span.cpp2"

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bounds-safety-span.cpp2"

#line 2 "pure2-bounds-safety-span.cpp2"
[[nodiscard]] auto main() -> int
{
    std::vector<std::string> words {"decorated", "hello", "world"}; 

    std::span<std::string> s {words}; 
    static_cast<void>(cpp2::move(words));

    auto i {0}; 
    for( ; cpp2::impl::cmp_less(i,CPP2_UFCS(ssize)(s)); ++i ) {
        print_and_decorate(CPP2_ASSERT_IN_BOUNDS(s, i));
    }
}

#line 15 "pure2-bounds-safety-span.cpp2"
auto print_and_decorate(auto const& x) -> void{
    std::cout << ">> " << x << "\n";
}

