// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-lifetime-safety-and-null-contracts.cpp2"

#include <iostream>
#include <vector>
#include <string>

[[nodiscard]] auto main() -> int;
#line 11 "mixed-lifetime-safety-and-null-contracts.cpp2"

//  Calling Cpp1 is the easiest way to create a null...
auto null_from_cpp1() -> int* { return nullptr; }

auto try_pointer_stuff() -> void;
#line 21 "mixed-lifetime-safety-and-null-contracts.cpp2"
auto call_my_framework(cpp2::in<const char *> msg) -> void;

//=== Cpp2 definitions ==========================================================

#line 5 "mixed-lifetime-safety-and-null-contracts.cpp2"

[[nodiscard]] auto main() -> int{
    cpp2::Null.set_handler(&call_my_framework);
    try_pointer_stuff();
    std::cout << "done\n";
}
#line 14 "mixed-lifetime-safety-and-null-contracts.cpp2"

auto try_pointer_stuff() -> void{
    int* p { null_from_cpp1() }; 
    *p = 42;    // deliberate null dereference
                // to show -n
}

auto call_my_framework(cpp2::in<const char *> msg) -> void { 
    std::cout 
        << "sending error to my framework... [" 
        << msg << "]\n"; }
