// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 2 "pure2-type-safety-1.cpp2"
[[nodiscard]] auto main() -> int;
#line 24 "pure2-type-safety-1.cpp2"
auto test_generic(auto const& x) -> void;
#line 30 "pure2-type-safety-1.cpp2"
auto print(cpp2::in<std::string> msg, cpp2::in<bool> b) -> void;
#line 36 "pure2-type-safety-1.cpp2"


//=== Cpp2 definitions ==========================================================

#line 1 "pure2-type-safety-1.cpp2"

[[nodiscard]] auto main() -> int
{
    std::variant<int,double> v { 42.0 }; 
    std::any a { "xyzzy" }; 
    std::optional<int> o {  }; 

    test_generic(3.14);
    test_generic(v);
    test_generic(a);
    test_generic(o);

    std::cout << "\n";

    v = 1;
    a = 2;
    o = 3;
    test_generic(42);
    test_generic(v);
    test_generic(a);
    test_generic(o);
}

auto test_generic(auto const& x) -> void{
    std::string msg { typeid(x).name() }; 
    msg += " is int? ";
    print( msg, cpp2::is<int>(x));
}

auto print(cpp2::in<std::string> msg, cpp2::in<bool> b) -> void{
    cpp2::deferred_init<const char*> bmsg; 
    if (b) { bmsg.construct("true");}
    else { bmsg.construct("false");}
    std::cout << std::setw(40) << msg << bmsg.value() << "\n";
}
