

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-is-as-variant.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-is-as-variant.cpp2"
auto test(auto&& v) -> void;

#line 11 "mixed-is-as-variant.cpp2"
[[nodiscard]] auto main() -> int;

#line 39 "mixed-is-as-variant.cpp2"
auto run_tests(auto&& v) -> void;

#line 50 "mixed-is-as-variant.cpp2"
auto header(cpp2::impl::in<int> lvl, cpp2::impl::in<std::string> msg) -> void;
#line 53 "mixed-is-as-variant.cpp2"

template<int I>
struct X { 
    operator int() const { return I; } 
    X() = default;
    X(std::exception const& e) { throw e; }
    auto to_string() const { return "X<" + std::to_string(I) + ">"; }
};

template <std::size_t I>
void set_to_valueless_by_exception(auto& v) try {
    v.template emplace<I>(std::runtime_error("make valueless"));
} catch (...) {}

auto expect_no_throw(auto&& l) -> std::string try {
    if constexpr ( requires { { l() } -> std::convertible_to<std::string>; }) {
        return l();
    } else {
        l();
        return "works!";
    }
} catch (std::exception const& e) {
    return e.what();
} catch (...) {
    return "unknown exception!";
}

auto expect_no_throw(auto&& v, auto&& l) -> std::string try {
    if constexpr ( requires { { l(v) } -> std::convertible_to<std::string>; }) {
        return l(v);
    } else {
        l(v);
        return "works!";
    }
} catch (std::exception const& e) {
    return e.what();
} catch (...) {
    return "unknown exception!";
}


//=== Cpp2 function definitions =================================================

#line 1 "mixed-is-as-variant.cpp2"
auto test(auto&& v) -> void{
#line 2 "mixed-is-as-variant.cpp2"
    std::cout << "v is empty = " + cpp2::to_string(cpp2::impl::is<void>(v)) + "" << std::endl;
    std::cout << "v is std::monostate = " + cpp2::to_string(cpp2::impl::is<std::monostate>(v)) + "" << std::endl;
    std::cout << "v is X< 0> = " + cpp2::to_string(cpp2::impl::is<X<0>>(v)) + ",\t(v as X< 1>) = " << expect_no_throw(CPP2_FORWARD(v), [](auto&& v) -> decltype(auto) { return cpp2::impl::as_<X<0>>(CPP2_FORWARD(v));  }) << std::endl;
    std::cout << "v is X< 1> = " + cpp2::to_string(cpp2::impl::is<X<1>>(v)) + ",\t(v as X< 1>).to_string() = " + cpp2::to_string(expect_no_throw(CPP2_FORWARD(v), [](auto&& v) -> std::string{return CPP2_UFCS(to_string)((cpp2::impl::as_<X<1>>(CPP2_FORWARD(v)))); })) + "" << std::endl;
    std::cout << "v is X<19> = " + cpp2::to_string(cpp2::impl::is<X<19>>(v)) + ",\t(v as X<19>).to_string() = " + cpp2::to_string(expect_no_throw(CPP2_FORWARD(v), [](auto&& v) -> std::string{return CPP2_UFCS(to_string)((cpp2::impl::as_<X<19>>(CPP2_FORWARD(v)))); })) + "" << std::endl;
    std::cout << "v is X<20> = " + cpp2::to_string(cpp2::impl::is<X<20>>(v)) + ",\t(v as X<20>) = " << expect_no_throw(CPP2_FORWARD(v), [](auto&& v) -> decltype(auto) { return cpp2::impl::as_<X<20>>(CPP2_FORWARD(v));  }) << std::endl;
    std::cout << std::endl;
}

#line 11 "mixed-is-as-variant.cpp2"
[[nodiscard]] auto main() -> int{

    std::variant<std::monostate,X<1>,X<2>,X<3>,X<4>,X<5>,X<6>,X<7>,X<8>,X<9>,X<10>,X<11>,X<12>,X<13>,X<14>,X<15>,X<16>,X<17>,X<18>,X<19>,X<20>> v {

                    }; 

    header(1, "std::monostate");
    v.emplace<0>();
    run_tests(v);

    header(1, "X<1>");
    v.emplace<1>();
    run_tests(v);

    header(1, "X<19>");
    v.emplace<19>();
    run_tests(v);

    header(1, "X<20>");
    v.emplace<20>();
    run_tests(v);

    header(1, "X<10>(std::exception)");
    set_to_valueless_by_exception<10>(v);
    run_tests(cpp2::move(v));

}

#line 39 "mixed-is-as-variant.cpp2"
auto run_tests(auto&& v) -> void{
    header(2, "v as lvalue reference");
    test(v);

    header(2, "v as const lvalue reference");
    test(std::as_const(v));

    header(2, "v as rvalue reference");
    test(std::move(CPP2_FORWARD(v)));
}

#line 50 "mixed-is-as-variant.cpp2"
auto header(cpp2::impl::in<int> lvl, cpp2::impl::in<std::string> msg) -> void{
    std::cout << std::string(lvl, '#') << " " << msg << "\n" << std::endl;
}

