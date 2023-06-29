

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#include <iostream>
#include <string>
#include <variant>
#include <any>
#include <optional>

class Shape { public: virtual ~Shape() { } };
class Circle : public Shape { };
class Square : public Shape { };

//--- printing setup -------------------

#line 13 "mixed-type-safety-1.cpp2"
auto print(cpp2::in<std::string> msg, auto const& x) -> void;
    

#line 17 "mixed-type-safety-1.cpp2"
[[nodiscard]] auto main() -> int;


//=== Cpp2 function definitions =================================================


#line 13 "mixed-type-safety-1.cpp2"
auto print(cpp2::in<std::string> msg, auto const& x) -> void { 
    std::cout << msg << x << "\n";  }

#line 17 "mixed-type-safety-1.cpp2"
[[nodiscard]] auto main() -> int
{
    std::cout << std::boolalpha;

//--- examples -------------------------

    print("1.1 is int? ", cpp2::is<int>(1.1));
    print( "1   is int? ", cpp2::is<int>(1));

    auto c {cpp2_new<Circle>()}; // safe by construction
    Shape* s {CPP2_UFCS_0(get, c)}; // safe by Lifetime
    print("\ns* is Shape?  ", cpp2::is<Shape>(*cpp2::assert_not_null(s)));
    print(  "s* is Circle? ", cpp2::is<Circle>(*cpp2::assert_not_null(s)));
    print(  "s* is Square? ", cpp2::is<Square>(*cpp2::assert_not_null(std::move(s))));
}

