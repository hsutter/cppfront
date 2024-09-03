
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-requires-clauses.cpp2"

#line 2 "pure2-requires-clauses.cpp2"
template<typename T, typename U> 

    requires( std::is_same_v<T,int> 
              && std::is_same_v<U,int> )class X;

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-requires-clauses.cpp2"

#line 2 "pure2-requires-clauses.cpp2"
template<typename T, typename U> 

    requires( std::is_same_v<T,int> 
              && std::is_same_v<U,int> )class X
 {
    public: explicit X();
    public: X(X const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(X const&) -> void = delete;

#line 8 "pure2-requires-clauses.cpp2"
};

template<typename T, typename U> [[nodiscard]] auto f
    (auto&& a, auto&& b) -> int
CPP2_REQUIRES (std::is_same_v<T,int> && std::is_same_v<U,int> && std::is_convertible_v<CPP2_TYPEOF(a), std::add_const_t<int>&> && std::is_convertible_v<CPP2_TYPEOF(b), std::add_const_t<int>&>) 
#line 10 "pure2-requires-clauses.cpp2"
;

#line 18 "pure2-requires-clauses.cpp2"
[[nodiscard]] constexpr auto f(auto const& x) -> int
CPP2_REQUIRES (true) ;

#line 20 "pure2-requires-clauses.cpp2"
template<typename T> 
CPP2_REQUIRES_ (std::same_as<T,cpp2::i32>) extern T const v;

#line 22 "pure2-requires-clauses.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-requires-clauses.cpp2"

#line 7 "pure2-requires-clauses.cpp2"
    template <typename T, typename U> requires( std::is_same_v<T,int> && std::is_same_v<U,int> )
X<T,U>::X(){}

#line 10 "pure2-requires-clauses.cpp2"
template<typename T, typename U> [[nodiscard]] auto f
    (auto&& a, auto&& b) -> int
requires (std::is_same_v<T,int> && std::is_same_v<U,int> && std::is_convertible_v<CPP2_TYPEOF(a), std::add_const_t<int>&> && std::is_convertible_v<CPP2_TYPEOF(b), std::add_const_t<int>&>) 

#line 14 "pure2-requires-clauses.cpp2"
{
    return CPP2_FORWARD(a) * CPP2_FORWARD(b); 
}

#line 18 "pure2-requires-clauses.cpp2"
[[nodiscard]] constexpr auto f(auto const& x) -> int
requires (true)  { return x;  }

#line 20 "pure2-requires-clauses.cpp2"
template<typename T> 
requires (std::same_as<T,cpp2::i32>) T const v {0}; 

#line 22 "pure2-requires-clauses.cpp2"
auto main() -> int{
    X<int,int> auto_1 {}; 
    std::cout << f<int,int>(2, 5) 
              << f(0);
}

