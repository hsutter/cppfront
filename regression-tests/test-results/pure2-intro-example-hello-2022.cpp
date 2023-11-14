
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

[[nodiscard]] auto main() -> int;
    

#line 11 "pure2-intro-example-hello-2022.cpp2"
[[nodiscard]] auto decorate(auto& thing) -> int;
    

#line 16 "pure2-intro-example-hello-2022.cpp2"
auto print_it(auto const& x, auto const& len) -> void;
    

//=== Cpp2 function definitions =================================================

[[nodiscard]] auto main() -> int{
    std::vector<std::string> vec {
            "hello", "2022"}; 

    for ( auto& str : vec ) {
        auto len {decorate(str)}; 
        print_it(str, len);
    }
}

[[nodiscard]] auto decorate(auto& thing) -> int{
    thing = "[" + thing + "]";
    return CPP2_UFCS_0(ssize, thing); 
}

auto print_it(auto const& x, auto const& len) -> void { 
    std::cout 
        << ">> " << x 
        << " - length " 
        << len << "\n"; }

