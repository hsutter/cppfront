
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-nested-lists.cpp2"
class point;
#line 2 "pure2-bugfix-for-nested-lists.cpp2"
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-nested-lists.cpp2"
class point {
#line 2 "pure2-bugfix-for-nested-lists.cpp2"
    public: int x {0}; 
    public: int y {0}; 
    public: point(cpp2::impl::in<int> x_, cpp2::impl::in<int> y_);
    public: [[nodiscard]] auto operator<=>(point const& that) const& -> std::strong_ordering = default;
public: point(point const& that);

public: auto operator=(point const& that) -> point& ;
public: point(point&& that) noexcept;
public: auto operator=(point&& that) noexcept -> point& ;
public: explicit point();

#line 8 "pure2-bugfix-for-nested-lists.cpp2"
};

[[nodiscard]] auto check(point p) -> point;

auto main() -> int;

#line 29 "pure2-bugfix-for-nested-lists.cpp2"
auto issue_1283() -> void;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-nested-lists.cpp2"

#line 4 "pure2-bugfix-for-nested-lists.cpp2"
    point::point(cpp2::impl::in<int> x_, cpp2::impl::in<int> y_)
        : x{ x_ }
        , y{ y_ }{

#line 7 "pure2-bugfix-for-nested-lists.cpp2"
    }


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
#line 10 "pure2-bugfix-for-nested-lists.cpp2"
[[nodiscard]] auto check(point p) -> point { return cpp2::move(p);  }

#line 12 "pure2-bugfix-for-nested-lists.cpp2"
auto main() -> int{
    if (cpp2::cpp2_default.is_active() && !(check({ 17, 29 }).x == 17) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(check({ 17, 29 }).y == 29) ) { cpp2::cpp2_default.report_violation(""); }

    std::array<std::array<cpp2::u8,3>,3> board {{ { 
                                            'O', 'X', 'O' }, { 
                                            ' ', { 'X' }, 'X' }, { 
                                            'X', 'O', 'O' } }}; 

    if (cpp2::cpp2_default.is_active() && !(CPP2_ASSERT_IN_BOUNDS_LITERAL(board, 0) == std::array<cpp2::u8,3>{'O', 'X', 'O'}) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(CPP2_ASSERT_IN_BOUNDS_LITERAL(board, 1) == std::array<cpp2::u8,3>{' ', 'X', 'X'}) ) { cpp2::cpp2_default.report_violation(""); }
    if (cpp2::cpp2_default.is_active() && !(CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(board), 2) == std::array<cpp2::u8,3>{'X', 'O', 'O'}) ) { cpp2::cpp2_default.report_violation(""); }

    // Still parentheses (for now?)
    if (cpp2::cpp2_default.is_active() && !(CPP2_UFCS(size)((std::vector{17, 29})) == 2) ) { cpp2::cpp2_default.report_violation(""); }
}

#line 29 "pure2-bugfix-for-nested-lists.cpp2"
auto issue_1283() -> void{
  auto f {[]() -> void{}}; 
  static_cast<void>([_0 = (&f)]() mutable -> decltype(auto) { return (*cpp2::impl::assert_not_null(_0))();  });
}

