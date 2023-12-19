

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-type-safety-1.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-type-safety-1.cpp2"
#include <iostream>
#include <string>
#include <variant>
#include <any>
#include <optional>

class Shape { public: virtual ~Shape() { } };
class Circle : public Shape { };
class Square : public Shape { };

//--- printing helpers -----------------

#line 13 "mixed-type-safety-1.cpp2"
auto print(cpp2::in<std::string> msg, auto const& x) -> void;

#line 16 "mixed-type-safety-1.cpp2"
auto print(cpp2::in<std::string> msg, cpp2::in<bool> b) -> void;

#line 24 "mixed-type-safety-1.cpp2"
//--- examples -------------------------

[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-type-safety-1.cpp2"

#line 13 "mixed-type-safety-1.cpp2"
auto print(cpp2::in<std::string> msg, auto const& x) -> void { 
    std::cout << msg << x << "\n";  }

auto print(cpp2::in<std::string> msg, cpp2::in<bool> b) -> void
{
    cpp2::deferred_init<char const*> bmsg; 
    if (b) { bmsg.construct("true");}
    else {bmsg.construct("false"); }
    std::cout << msg << std::move(bmsg.value()) << "\n";
}

#line 26 "mixed-type-safety-1.cpp2"
[[nodiscard]] auto main() -> int
{
    print("1.1 is int? ", cpp2::is<int>(1.1));
    print( "1   is int? ", cpp2::is<int>(1));

    auto c {cpp2_new<Circle>()}; // safe by construction
    Shape* s {CPP2_UFCS(get)(std::move(c))}; // safe by Lifetime
    print("\ns* is Shape?  ", cpp2::is<Shape>(*cpp2::assert_not_null(s)));
    print(  "s* is Circle? ", cpp2::is<Circle>(*cpp2::assert_not_null(s)));
    print(  "s* is Square? ", cpp2::is<Square>(*cpp2::assert_not_null(std::move(s))));
}

