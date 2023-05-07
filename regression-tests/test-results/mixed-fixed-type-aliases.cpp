

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#include <typeinfo>
#include <iostream>

namespace my {
    using u16 = float;
}

#line 8 "mixed-fixed-type-aliases.cpp2"
auto test(auto const& x) -> void;
    

#line 15 "mixed-fixed-type-aliases.cpp2"
[[nodiscard]] auto main(int const argc_, char const* const* const argv_) -> int;
    

//=== Cpp2 function definitions =================================================


#line 8 "mixed-fixed-type-aliases.cpp2"
auto test(auto const& x) -> void{
    std::cout 
        << std::boolalpha 
        << std::is_floating_point_v<CPP2_TYPEOF(x)> 
        << "\n";
}

[[nodiscard]] auto main(int const argc_, char const* const* const argv_) -> int{
    auto args = cpp2::make_args(argc_, argv_); 
#line 16 "mixed-fixed-type-aliases.cpp2"
    my::u16 y {42}; 
    test(std::move(y));

    cpp2::u16 z {42}; 
    test(std::move(z));

    { auto const& cpp2_range = args; for ( auto const& arg : cpp2_range ) 
        std::cout << arg << "\n";}
#line 24 "mixed-fixed-type-aliases.cpp2"
}

