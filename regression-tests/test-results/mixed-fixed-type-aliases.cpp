

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#include <typeinfo>
#include <iostream>
#include <cassert>

namespace my {
    using u16 = float;
}

#line 9 "mixed-fixed-type-aliases.cpp2"
auto test(auto const& x) -> void;
    

#line 16 "mixed-fixed-type-aliases.cpp2"
[[nodiscard]] auto main(int const argc_, char const* const* const argv_) -> int;
    

//=== Cpp2 function definitions =================================================


#line 9 "mixed-fixed-type-aliases.cpp2"
auto test(auto const& x) -> void{
    std::cout 
        << std::boolalpha 
        << std::is_floating_point_v<CPP2_TYPEOF(x)> 
        << "\n";
}

[[nodiscard]] auto main(int const argc_, char const* const* const argv_) -> int{
    auto args = cpp2::make_args(argc_, argv_); 
#line 17 "mixed-fixed-type-aliases.cpp2"
    assert(sizeof(my::u16)==4);
    my::u16 y {42}; 
    test(std::move(y));

    assert(sizeof(cpp2::u16)==2);
    cpp2::u16 z {42}; 
    test(std::move(z));

    for ( auto const& arg : args ) 
        std::cout << arg << "\n";
}

