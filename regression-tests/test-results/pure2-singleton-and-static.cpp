
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-singleton-and-static.cpp2"

#line 2 "pure2-singleton-and-static.cpp2"
class test;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-singleton-and-static.cpp2"

#line 2 "pure2-singleton-and-static.cpp2"
class test {
    private: int value {42}; 
    public: auto print() const& -> void;
    private: explicit test();
public: [[nodiscard]] static auto instance() -> test&;

    public: test(test const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(test const&) -> void = delete;

#line 5 "pure2-singleton-and-static.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-singleton-and-static.cpp2"

#line 4 "pure2-singleton-and-static.cpp2"
    auto test::print() const& -> void{std::cout << "" + cpp2::to_string(value) + "\n"; }

    test::test(){}
[[nodiscard]] auto test::instance() -> test&{

    static test _instance {}; return _instance; 
    }

#line 7 "pure2-singleton-and-static.cpp2"
auto main() -> int{
    CPP2_UFCS(print)(test::instance());
}

