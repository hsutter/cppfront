

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "test_simple.cpp2"

#line 2 "test_simple.cpp2"
class point;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "test_simple.cpp2"
// Simple test
#line 2 "test_simple.cpp2"
class point {
    private: double x {0.0}; 
    private: double y {0.0}; 
    public: [[nodiscard]] auto operator<=>(point const& that) const& -> std::strong_ordering = default;
public: point(point const& that);

public: auto operator=(point const& that) -> point& ;
public: point(point&& that) noexcept;
public: auto operator=(point&& that) noexcept -> point& ;
public: explicit point();

#line 5 "test_simple.cpp2"
};

[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "test_simple.cpp2"

#line 1 "test_simple.cpp2"

point::point(point const& that)
                                : x{ that.x }
                                , y{ that.y }{}
auto point::operator=(point const& that) -> point& {
                                x = that.x;
                                y = that.y;
                                return *this;}
point::point(point&& that) noexcept
                                : x{ std::move(that).x }
                                , y{ std::move(that).y }{}
auto point::operator=(point&& that) noexcept -> point& {
                                x = std::move(that).x;
                                y = std::move(that).y;
                                return *this;}
point::point(){}
#line 7 "test_simple.cpp2"
[[nodiscard]] auto main() -> int{
    point p {1.0, 2.0}; 
    return 0; 
}

