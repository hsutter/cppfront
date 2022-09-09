// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-inspect-statement-with-as-in-generic-function.cpp2"
auto print_an_int(auto const& x) -> void;
#line 12 "pure2-inspect-statement-with-as-in-generic-function.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-inspect-statement-with-as-in-generic-function.cpp2"

auto print_an_int(auto const& x) -> void{
    std::cout << std::setw(30) << typeid(x).name() 
              << " value is ";
    { auto&& __expr = x;
        if (cpp2::is<int>(__expr)) std::cout << cpp2::as<int>(x);
        else     std::cout << "not an int";
    }
    std::cout << "\n";
}

[[nodiscard]] auto main() -> int{
    print_an_int("syzygy");
    print_an_int(1);
    print_an_int(1.1);
}
