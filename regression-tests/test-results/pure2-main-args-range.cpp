
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-main-args-range.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-main-args-range.cpp2"
auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-main-args-range.cpp2"
auto main(int const argc_, char** argv_) -> int{
    auto const args = cpp2::make_args(argc_, argv_); 
#line 2 "pure2-main-args-range.cpp2"
    static_assert(std::bidirectional_iterator<cpp2::args::iterator>);
    static_assert(std::ranges::bidirectional_range<cpp2::args>);
    static_assert(std::ranges::viewable_range<cpp2::args>);

    // Output command line arguments, dropping the program name argc[0].
    for ( auto const& arg : args | std::ranges::views::drop(1) ) 
    {
        std::cout 
            << arg << std::endl;
    }
}

