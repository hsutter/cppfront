// ----- Cpp2 support -----
#include "cpp2util.h"

#line 1 "mixed-type-safety-1.cpp2"
#include <iostream>
#include <string>
#include <variant>
#include <any>
#include <optional>

class Shape { public: virtual ~Shape() { } };
class Circle : public Shape { };
class Square : public Shape { };

#line 13 "mixed-type-safety-1.cpp2"
auto print(cpp2::in<std::string> msg, auto const& x) -> void;
#line 16 "mixed-type-safety-1.cpp2"
auto print(cpp2::in<std::string> msg, cpp2::in<bool> b) -> void;
#line 26 "mixed-type-safety-1.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 10 "mixed-type-safety-1.cpp2"

//--- printing helpers -----------------

auto print(cpp2::in<std::string> msg, auto const& x) -> void { 
    std::cout << msg << x << "\n"; }

auto print(cpp2::in<std::string> msg, cpp2::in<bool> b) -> void
{
    cpp2::deferred_init<const char*> bmsg; 
    if (b) { bmsg.construct("true");}
    else { bmsg.construct("false");}
    std::cout << msg << bmsg.value() << "\n";
}

//--- examples -------------------------

[[nodiscard]] auto main() -> int
{
    print( "1.1 is int? ", cpp2::is<int>(1.1));
    print( "1   is int? ", cpp2::is<int>(1));

    auto c { cpp2_new<Circle>() }; // safe by construction
    Shape* s { CPP2_UFCS_0(get, c) }; // safe by Lifetime
    print("\ns* is Shape?  ", cpp2::is<Shape>(*s));
    print(  "s* is Circle? ", cpp2::is<Circle>(*s));
    print(  "s* is Square? ", cpp2::is<Square>(*s));
}
