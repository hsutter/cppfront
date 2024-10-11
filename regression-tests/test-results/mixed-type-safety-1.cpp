

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

#line 12 "mixed-type-safety-1.cpp2"
template<typename T> auto print(cpp2::impl::in<std::string> msg, T const& x) -> void;

#line 16 "mixed-type-safety-1.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-type-safety-1.cpp2"

#line 12 "mixed-type-safety-1.cpp2"
template<typename T> auto print(cpp2::impl::in<std::string> msg, T const& x) -> void{
    std::cout << "" + cpp2::to_string(msg) + " " + cpp2::to_string(x) + "\n";
}

#line 16 "mixed-type-safety-1.cpp2"
[[nodiscard]] auto main() -> int
{
    // Full qualification is necessary to avoid ambiguity in C++23
    // C++23 defines std::print, which would be picked up here by ADL
    ::print("1.1 is int?", cpp2::impl::is<int>(1.1));
    ::print( "1   is int?", cpp2::impl::is<int>(1));

    auto c {cpp2_new<Circle>()}; // safe by construction
    Shape* s {CPP2_UFCS(get)(cpp2::move(c))}; // safe by Lifetime
    ::print("\ns* is Shape? ", cpp2::impl::is<Shape>(*cpp2::impl::assert_not_null(s)));
    ::print(  "s* is Circle?", cpp2::impl::is<Circle>(*cpp2::impl::assert_not_null(s)));
    ::print(  "s* is Square?", cpp2::impl::is<Square>(*cpp2::impl::assert_not_null(cpp2::move(s))));
}

