

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-is-as-value-with-variant.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-is-as-value-with-variant.cpp2"
auto in(int min, int max) {
    return [=](int x){ return min <= x && x <= max; };
}

#line 5 "mixed-is-as-value-with-variant.cpp2"
auto test(auto&& v) -> void;

#line 40 "mixed-is-as-value-with-variant.cpp2"
using my_variant = std::variant<std::monostate,int,int,std::optional<int>,std::any,int*,std::unique_ptr<int>>;

[[nodiscard]] auto main() -> int;

#line 110 "mixed-is-as-value-with-variant.cpp2"
auto header(cpp2::impl::in<int> lvl, cpp2::impl::in<std::string> msg) -> void;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-is-as-value-with-variant.cpp2"

#line 5 "mixed-is-as-value-with-variant.cpp2"
auto test(auto&& v) -> void{
    if (cpp2::impl::is(v, (42))) {
        std::cout << " 42";
    }
    if (cpp2::impl::is(v, (24))) {
        std::cout << " 24";
    }
    if (cpp2::impl::is(v, (100))) {
        std::cout << " 100";
    }
    if (cpp2::impl::is(v, (-100))) {
        std::cout << " -100";
    }
    if (cpp2::impl::is(v, (314))) {
        std::cout << " 314";
    }
    if (cpp2::impl::is(v, (std::optional<int>(100)))) {
        std::cout << " std::optional<int>(100)";
    }
    if (cpp2::impl::is(v, (std::any(-100)))) {
        std::cout << " std::any(-100)";
    }
    if (cpp2::impl::is(v, (cpp2_new<int>(1000)))) {
        std::cout << " std::unique_ptr<int>(1000)";
    }
    int i {314}; 
    if (cpp2::impl::is(v, (&i))) {
        std::cout << " *int(314)";
    }
    if (cpp2::impl::is(CPP2_FORWARD(v), (in(0, 100)))) {
        std::cout << " in(0,100)";
    }
    std::cout << "\n---" << std::endl;
}

#line 42 "mixed-is-as-value-with-variant.cpp2"
[[nodiscard]] auto main() -> int{

    std::variant<std::monostate,int,int,std::optional<int>,std::any,int*,std::unique_ptr<int>,my_variant> v {}; 

    header(1, "std::monostate");
    v.emplace<0>();
    test(v);

    header(1, "int(42)");
    v.emplace<1>(42);
    test(v);

    header(1, "int(24)");
    v.emplace<2>(24);
    test(v);

    header(1, "std::optional<int>(100)");
    v.emplace<3>(100);
    test(v);

    header(1, "std::any(-100)");
    v.emplace<4>(-100);
    test(v);

    int i {314}; 
    header(1, "*int(314)");
    v.emplace<5>(&i);
    test(v);

    header(1, "std::unique_ptr<int>(1000)");
    v.emplace<6>(cpp2_new<int>(1000));
    test(v);

    header(1, "my_variant(std::monostate)");
    v.emplace<7>();
    test(v);

    header(1, "my_variant(int(42))");
    v.emplace<7>();
    std::get<7>(v).emplace<1>(42);
    test(v);

    header(1, "my_variant(int(24))");
    v.emplace<7>();
    std::get<7>(v).emplace<2>(24);
    test(v);

    header(1, "my_variant(std::optional<int>(100))");
    v.emplace<7>();
    std::get<7>(v).emplace<3>(100);
    test(v);

    header(1, "my_variant(std::any(-100))");
    v.emplace<7>();
    std::get<7>(v).emplace<4>(-100);
    test(v);

    header(1, "my_variant(*int(314))");
    v.emplace<7>();
    std::get<7>(v).emplace<5>(&i);
    test(v);

    header(1, "my_variant(std::unique_ptr<int>(1000))");
    v.emplace<7>();
    std::get<7>(v).emplace<6>(cpp2_new<int>(1000));
    test(cpp2::move(v));
}

#line 110 "mixed-is-as-value-with-variant.cpp2"
auto header(cpp2::impl::in<int> lvl, cpp2::impl::in<std::string> msg) -> void{
    std::cout << std::string(lvl, '#') << " " << msg << std::endl;
}

