
#define CPP2_USE_MODULES         Yes

#include "cpp2util.h"


#line 1 "pure2-chained-comparisons.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-chained-comparisons.cpp2"
[[nodiscard]] auto main() -> int{
    std::cout << std::boolalpha;
    auto i {0}; for( ; cpp2::cmp_less(i,3); ++i ) {
        auto j {0}; for( ; cpp2::cmp_less(j,3); ++j ) {
            auto k {0}; for( ; cpp2::cmp_less(k,3); ++k ) {
                std::cout 
                    << i << " " 
                    << j << " " 
                    << k << ": " 
                    << ([_0 = i, _1 = j, _2 = k]{ return _0==_1 && _1==_2; }()) << " " 
                    << ([_0 = i, _1 = j, _2 = k]{ return cpp2::cmp_less(_0,_1) && cpp2::cmp_less_eq(_1,_2); }()) << " " 
                    << ([_0 = i, _1 = j, _2 = k]{ return cpp2::cmp_greater_eq(_0,_1) && cpp2::cmp_greater(_1,_2); }()) << "\n";
            }
        }
    }
}

