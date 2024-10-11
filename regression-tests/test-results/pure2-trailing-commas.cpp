
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-trailing-commas.cpp2"

#line 9 "pure2-trailing-commas.cpp2"
class vals;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-trailing-commas.cpp2"
[[nodiscard]] auto f(auto const& a, auto const& b) -> decltype(auto);

#line 3 "pure2-trailing-commas.cpp2"
template<typename T, typename U> [[nodiscard]] auto g(T const& a, U const& b) -> decltype(auto);
using doubler_ret = int;


#line 5 "pure2-trailing-commas.cpp2"
[[nodiscard]] auto doubler(cpp2::impl::in<int> a) -> doubler_ret;

#line 9 "pure2-trailing-commas.cpp2"
class vals {public: int i; 
public: vals(auto&& i_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<int>&>) ;

public: auto operator=(auto&& i_) -> vals& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<int>&>) ;

#line 9 "pure2-trailing-commas.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-trailing-commas.cpp2"
[[nodiscard]] auto f(auto const& a, auto const& b) -> decltype(auto) { return a + b;  }

#line 3 "pure2-trailing-commas.cpp2"
template<typename T, typename U> [[nodiscard]] auto g(T const& a, U const& b) -> decltype(auto) { return a + b;  }

#line 5 "pure2-trailing-commas.cpp2"
[[nodiscard]] auto doubler(cpp2::impl::in<int> a) -> doubler_ret{
        cpp2::impl::deferred_init<int> i;
#line 6 "pure2-trailing-commas.cpp2"
    i.construct(a * 2);
return std::move(i.value()); }

vals::vals(auto&& i_)
requires (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<int>&>) 
                                                           : i{ CPP2_FORWARD(i_) }{}

auto vals::operator=(auto&& i_) -> vals& 
requires (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<int>&>) {
                                                           i = CPP2_FORWARD(i_);
                                                           return *this;}
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

    static_cast<void>(cpp2::move(array));
    static_cast<void>(cpp2::move(grouping));
}

