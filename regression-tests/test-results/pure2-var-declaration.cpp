// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 1 "pure2-var-declaration.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-var-declaration.cpp2"
[[nodiscard]] auto main() -> int{
    auto i1 {42}; 
    auto const i1c {42}; 
    auto static i1s {42}; 
    int i2 {42}; 
    int         static i2s {42}; 
    int         const i2c {42}; 
    int                static const i2sc {42}; 


    auto* p1 {&i1}; 
    auto* const p1c {&i1}; 
    auto static* p1s {&i1s}; 
    auto const* p2 {&i1}; 
    auto const* const p2c {&i1}; 
    auto static const* p2s {&i1s}; 
    auto static const* const p2cs {&i1s}; 
    int   * p3 {&i1}; 
    int          * const p3c {&i1}; 
    int           static* p3s {&i1s}; 
    int                  static* const p3sc {&i1s}; 
    int          const* p4 {&i1}; 
    int                 static const* p4s {&i1s}; 
    int         * const p5 {&i1}; 
    int                 static* const p5s {&i1s}; 
    int                        const* const* const p6 {&p4}; 
    int                               static const* const* const p6s {&p5s}; 


    auto s1 {"Fred"}; 
    auto const s1c {"Fred"}; 
    auto static s1s {"Fred"}; 
    auto static const s1sc {"Fred"}; 
    std::string s2 {"Fred"}; 
    std::string const s2c {"Fred"}; 
    std::string static s2s {"Fred"}; 
    std::string        static const s2sc {"Fred"}; 


    std::cout << std::move(s2sc) << " is " << *cpp2::assert_not_null(*cpp2::assert_not_null(std::move(p6s))) << std::endl;
}

