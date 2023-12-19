

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-lifetime-safety-and-null-contracts.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-lifetime-safety-and-null-contracts.cpp2"

#include <iostream>
#include <vector>
#include <string>

#line 6 "mixed-lifetime-safety-and-null-contracts.cpp2"
[[nodiscard]] auto main() -> int;
#line 11 "mixed-lifetime-safety-and-null-contracts.cpp2"

//  Calling Cpp1 is the easiest way to create a null...
auto null_from_cpp1() -> int* { return nullptr; }

auto try_pointer_stuff() -> void;

#line 21 "mixed-lifetime-safety-and-null-contracts.cpp2"
auto call_my_framework(char const* msg) -> void;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-lifetime-safety-and-null-contracts.cpp2"

#line 6 "mixed-lifetime-safety-and-null-contracts.cpp2"
[[nodiscard]] auto main() -> int{
    CPP2_UFCS(set_handler)(cpp2::Null, &call_my_framework);
    try_pointer_stuff();
    std::cout << "done\n";
}

#line 15 "mixed-lifetime-safety-and-null-contracts.cpp2"
auto try_pointer_stuff() -> void{
    int* p {null_from_cpp1()}; 
    *cpp2::assert_not_null(p) = 42;// deliberate null dereference
                // to show -n
}

auto call_my_framework(char const* msg) -> void{
    std::cout 
        << "sending error to my framework... [" 
        << msg << "]\n";
    exit(0);
}

