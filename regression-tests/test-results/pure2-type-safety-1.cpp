// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-type-safety-1.cpp2"
[[nodiscard]] auto main() -> int;
#line 24 "pure2-type-safety-1.cpp2"
auto test_generic(auto const& x, auto const& msg) -> void;
#line 29 "pure2-type-safety-1.cpp2"
auto print(cpp2::in<std::string> msg, cpp2::in<bool> b) -> void;
#line 35 "pure2-type-safety-1.cpp2"


//=== Cpp2 definitions ==========================================================

#line 1 "pure2-type-safety-1.cpp2"

[[nodiscard]] auto main() -> int
{
    std::variant<int,int,double> v { 42.0 }; 
    std::any a { "xyzzy" }; 
    std::optional<int> o {  }; 

    test_generic(3.14, "double");
    test_generic(v,    "variant<int, int, double>");
    test_generic(a,    "any");
    test_generic(o,    "optional<int>");

    std::cout << "\n";

    CPP2_UFCS_TEMPLATE(emplace, (<1>), v, 1);
    a = 2;
    o = 3;
    test_generic(42,   "int");
    test_generic(std::move(v), "variant<int, int, double>");
    test_generic(std::move(a), "any");
    test_generic(std::move(o), "optional<int>");
}

auto test_generic(auto const& x, auto const& msg) -> void{
    std::string msgx { msg }; 
    print( std::move(msgx) + " is int? ", cpp2::is<int>(x));
}

auto print(cpp2::in<std::string> msg, cpp2::in<bool> b) -> void{
    cpp2::deferred_init<const char*> bmsg; 
    if (b) { bmsg.construct("true");}
    else { bmsg.construct("false");}
    std::cout << std::setw(40) << msg << std::move(bmsg.value()) << "\n";
}

