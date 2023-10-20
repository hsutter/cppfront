

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#include <filesystem>
#include <iostream>
#include <typeinfo>

namespace my {
    using u16 = float;
}

#line 9 "mixed-fixed-type-aliases.cpp2"
auto test(auto const& x) -> void;
    

#line 15 "mixed-fixed-type-aliases.cpp2"
[[nodiscard]] auto main(int const argc_, char** argv_) -> int;
    

//=== Cpp2 function definitions =================================================


#line 9 "mixed-fixed-type-aliases.cpp2"
auto test(auto const& x) -> void{
    std::cout 
        << cpp2::as_<std::string>(std::is_floating_point_v<CPP2_TYPEOF(x)>) 
        << "\n";
}

[[nodiscard]] auto main(int const argc_, char** argv_) -> int{
    auto const args = cpp2::make_args(argc_, argv_); 
#line 16 "mixed-fixed-type-aliases.cpp2"
    my::u16 y {42}; 
    test(std::move(y));

    cpp2::u16 z {42}; 
    test(std::move(z));

    for ( auto const& arg : args ) 
        std::cout << CPP2_UFCS_0(filename, std::filesystem::path(arg)) << "\n";
}

