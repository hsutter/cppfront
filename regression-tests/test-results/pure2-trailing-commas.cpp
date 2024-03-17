
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-trailing-commas.cpp2"

#line 9 "pure2-trailing-commas.cpp2"
class vals;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-trailing-commas.cpp2"
[[nodiscard]] auto f(auto const& a, auto const& b) -> auto;

#line 3 "pure2-trailing-commas.cpp2"
template<typename T, typename U> [[nodiscard]] auto g(T const& a, U const& b) -> auto;
using doubler_ret = int;


#line 5 "pure2-trailing-commas.cpp2"
[[nodiscard]] auto doubler(cpp2::impl::in<int> a) -> doubler_ret;

#line 9 "pure2-trailing-commas.cpp2"
class vals {public: int i; };

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-trailing-commas.cpp2"
[[nodiscard]] auto f(auto const& a, auto const& b) -> auto { return a + b;  }

#line 3 "pure2-trailing-commas.cpp2"
template<typename T, typename U> [[nodiscard]] auto g(T const& a, U const& b) -> auto { return a + b;  }

#line 5 "pure2-trailing-commas.cpp2"
[[nodiscard]] auto doubler(cpp2::impl::in<int> a) -> doubler_ret{
        cpp2::impl::deferred_init<int> i;
#line 6 "pure2-trailing-commas.cpp2"
    i.construct(a * 2);
return std::move(i.value()); }

#line 11 "pure2-trailing-commas.cpp2"
auto main() -> int{
{
auto a{42};
#line 12 "pure2-trailing-commas.cpp2"
    while( false ) {++a; }
}
#line 13 "pure2-trailing-commas.cpp2"
    static_cast<void>(g(1, 2));

    std::vector grouping {0, 1, 2}; 

    std::array array {0, 1, 2}; 

    static_cast<void>(std::move(array));
    static_cast<void>(std::move(grouping));
}

