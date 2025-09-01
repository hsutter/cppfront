

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regression-tests/pure2-function-body-reflection.cpp2"

#line 2 "regression-tests/pure2-function-body-reflection.cpp2"
namespace ns {

#line 7 "regression-tests/pure2-function-body-reflection.cpp2"
class test;

#line 88 "regression-tests/pure2-function-body-reflection.cpp2"
}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "regression-tests/pure2-function-body-reflection.cpp2"

#line 2 "regression-tests/pure2-function-body-reflection.cpp2"
namespace ns {

// This function will be visible as a namespace member while reflecting on ns::test
auto sample_function_before_type() -> void;
[[nodiscard]] auto add_1(auto const& x) -> decltype(auto);


#line 7 "regression-tests/pure2-function-body-reflection.cpp2"
class test
 {
    public: [[nodiscard]] static auto one_liner(cpp2::impl::in<double> a, cpp2::impl::in<double> b, cpp2::impl::in<double> c) -> decltype(auto);
struct return_list_ret { double r; float s; std::string t; };



#line 11 "regression-tests/pure2-function-body-reflection.cpp2"
    public: [[nodiscard]] static auto return_list() -> return_list_ret;
using branches_ret = double;


#line 19 "regression-tests/pure2-function-body-reflection.cpp2"
    public: [[nodiscard]] static auto branches(cpp2::impl::in<double> a, cpp2::impl::in<double> b, cpp2::impl::in<double> c) -> branches_ret;

#line 34 "regression-tests/pure2-function-body-reflection.cpp2"
    public: static auto binary_ops(double& a, cpp2::impl::in<double> b, cpp2::impl::in<double> c) -> void;

#line 43 "regression-tests/pure2-function-body-reflection.cpp2"
    public: [[nodiscard]] static auto prefix() -> int;

#line 55 "regression-tests/pure2-function-body-reflection.cpp2"
    public: static auto postfix(double& a) -> void;

#line 61 "regression-tests/pure2-function-body-reflection.cpp2"
    public: [[nodiscard]] static auto qualified_ids() -> auto;

#line 67 "regression-tests/pure2-function-body-reflection.cpp2"
    public: static auto loops() -> void;
    public: test() = default;
    public: test(test const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(test const&) -> void = delete;


#line 83 "regression-tests/pure2-function-body-reflection.cpp2"
};

// This function will not be visible as a namespace member while reflecting on ns::test
auto sample_function_after_type() -> void;

}

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "regression-tests/pure2-function-body-reflection.cpp2"

#line 2 "regression-tests/pure2-function-body-reflection.cpp2"
namespace ns {

#line 5 "regression-tests/pure2-function-body-reflection.cpp2"
auto sample_function_before_type() -> void{}

[[nodiscard]] auto add_1(auto const& x) -> decltype(auto) { return x + 1; }

#line 9 "regression-tests/pure2-function-body-reflection.cpp2"
    [[nodiscard]] auto test::one_liner(cpp2::impl::in<double> a, cpp2::impl::in<double> b, cpp2::impl::in<double> c) -> decltype(auto) { return (a + c) * b;  }

#line 11 "regression-tests/pure2-function-body-reflection.cpp2"
    [[nodiscard]] auto test::return_list() -> return_list_ret

    {
            cpp2::impl::deferred_init<double> r;
            cpp2::impl::deferred_init<float> s;
            cpp2::impl::deferred_init<std::string> t;
#line 14 "regression-tests/pure2-function-body-reflection.cpp2"
        r.construct(42.0);
        s.construct(2.71828f);
        t.construct("e times pi");
    return  { std::move(r.value()), std::move(s.value()), std::move(t.value()) }; }

#line 19 "regression-tests/pure2-function-body-reflection.cpp2"
    [[nodiscard]] auto test::branches(cpp2::impl::in<double> a, cpp2::impl::in<double> b, cpp2::impl::in<double> c) -> branches_ret

    {
        double r {3.14159};
#line 22 "regression-tests/pure2-function-body-reflection.cpp2"
        if (true) {
            r = r + a;
        }

        if (cpp2::impl::cmp_greater(a * b,c)) {
            r += sin(b);
        }
        else {
            r = c;
        }return r; 
    }

#line 34 "regression-tests/pure2-function-body-reflection.cpp2"
    auto test::binary_ops(double& a, cpp2::impl::in<double> b, cpp2::impl::in<double> c) -> void
    {
        a -= b * c + (1 << 2);
        bool test {[_0 = a, _1 = b, _2 = c]{ return cpp2::impl::cmp_less_eq(_0,_1) && cpp2::impl::cmp_less(_1,_2); }() && true || false}; 
        auto x {1 & 2}; 
        auto y {3 ^ 4}; 
        auto z {5 | 6}; 
    }

#line 43 "regression-tests/pure2-function-body-reflection.cpp2"
    [[nodiscard]] auto test::prefix() -> int
    {
        auto a {-1}; 
        auto b {+2}; 
{
auto const& local{a - b};

#line 49 "regression-tests/pure2-function-body-reflection.cpp2"
        if (!(true)) {
            return local; 
        }
}
#line 52 "regression-tests/pure2-function-body-reflection.cpp2"
        return cpp2::move(a) + cpp2::move(b); 
    }

#line 55 "regression-tests/pure2-function-body-reflection.cpp2"
    auto test::postfix(double& a) -> void
    {
        auto ptr {&a}; 
        --++*cpp2::impl::assert_not_null(cpp2::move(ptr));
    }

#line 61 "regression-tests/pure2-function-body-reflection.cpp2"
    [[nodiscard]] auto test::qualified_ids() -> auto
    {
        std::vector<int> v {1, 2, 3}; 
        return CPP2_UFCS(ssize)(cpp2::move(v)); 
    }

#line 67 "regression-tests/pure2-function-body-reflection.cpp2"
    auto test::loops() -> void
    {
        std::vector v {1, 2, 3}; 
{
auto index{1};

#line 72 "regression-tests/pure2-function-body-reflection.cpp2"
        for ( 
             auto const& value : cpp2::move(v) ) 
        {
            std::cout << "" + cpp2::to_string(index) + " " + cpp2::to_string(value) + "\n";
        }
}

#line 78 "regression-tests/pure2-function-body-reflection.cpp2"
        auto i {0}; 
        for( ; cpp2::impl::cmp_less(i,3); i += 1 ) {std::cout << i << "\n"; }

        do {std::cout << "plugh\n"; } while ( false);
    }

#line 86 "regression-tests/pure2-function-body-reflection.cpp2"
auto sample_function_after_type() -> void{}

}

#line 90 "regression-tests/pure2-function-body-reflection.cpp2"
auto main() -> int{
    std::cout << "calling generated function ns::add_1... ns::add_1(42) returned " + cpp2::to_string(ns::add_1(42)) + "\n";
}

