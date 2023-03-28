
#define CPP2_USE_MODULES         Yes

#include "cpp2util.h"

#line 2 "pure2-requires-clauses.cpp2"
template<typename T, typename U> 

    requires( std::is_same_v<T,int> 
              && std::is_same_v<U,int>)
class X;

#line 10 "pure2-requires-clauses.cpp2"
template<typename T, typename U> [[nodiscard]] auto f
    (auto&& a, auto&& b) -> int;

#line 18 "pure2-requires-clauses.cpp2"
auto main() -> int;

//=== Cpp2 definitions ==========================================================


#line 2 "pure2-requires-clauses.cpp2"
template<typename T, typename U> 

    requires( std::is_same_v<T,int> 
              && std::is_same_v<U,int>)
class X {
    public: X(){}
};

template<typename T, typename U> [[nodiscard]] auto f
    (auto&& a, auto&& b) -> int
requires (std::is_same_v<T,int> && std::is_same_v<U,int> && std::is_same_v<CPP2_TYPEOF(a), int> && std::is_same_v<CPP2_TYPEOF(b), int>)
#line 14 "pure2-requires-clauses.cpp2"
{
    return CPP2_FORWARD(a) * CPP2_FORWARD(b); 
}

auto main() -> int{
    X<int,int> x {}; 
    std::cout << f<int,int>(2, 5);
}

