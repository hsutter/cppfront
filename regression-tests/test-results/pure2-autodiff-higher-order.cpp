
#define CPP2_IMPORT_STD          Yes
#include "cpp2taylor.h"

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-autodiff-higher-order.cpp2"

#line 5 "pure2-autodiff-higher-order.cpp2"
class ad_test;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-autodiff-higher-order.cpp2"

#line 2 "pure2-autodiff-higher-order.cpp2"
int inline constexpr ad_order{ 6 };
using ad_type = cpp2::taylor<double,ad_order>;

class ad_test {
using add_1_ret = double;


#line 7 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto add_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_1_ret;
using add_2_ret = double;


#line 11 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto add_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_2_ret;
using sub_1_ret = double;


#line 15 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto sub_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_1_ret;
using sub_2_ret = double;


#line 19 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_2_ret;
using add_sub_2_ret = double;


#line 23 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto add_sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_sub_2_ret;
using mul_1_ret = double;


#line 27 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto mul_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_1_ret;
using mul_2_ret = double;


#line 31 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto mul_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_2_ret;
using div_1_ret = double;


#line 35 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto div_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_1_ret;
using div_2_ret = double;


#line 39 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_2_ret;
using mul_div_2_ret = double;


#line 43 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto mul_div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_div_2_ret;
using mul_add_ret = double;


#line 47 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto mul_add(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_add_ret;
using add_mul_ret = double;


#line 51 "pure2-autodiff-higher-order.cpp2"
    public: [[nodiscard]] static auto add_mul(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_mul_ret;
struct add_1_d_ret { double r; cpp2::taylor<double,6> r_d; };


    public: [[nodiscard]] static auto add_1_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> add_1_d_ret;

struct add_2_d_ret { double r; cpp2::taylor<double,6> r_d; };

public: [[nodiscard]] static auto add_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> add_2_d_ret;

struct sub_1_d_ret { double r; cpp2::taylor<double,6> r_d; };

public: [[nodiscard]] static auto sub_1_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> sub_1_d_ret;

struct sub_2_d_ret { double r; cpp2::taylor<double,6> r_d; };

public: [[nodiscard]] static auto sub_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> sub_2_d_ret;

struct add_sub_2_d_ret { double r; cpp2::taylor<double,6> r_d; };

public: [[nodiscard]] static auto add_sub_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> add_sub_2_d_ret;

struct mul_1_d_ret { double r; cpp2::taylor<double,6> r_d; };

public: [[nodiscard]] static auto mul_1_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> mul_1_d_ret;

struct mul_2_d_ret { double r; cpp2::taylor<double,6> r_d; };

public: [[nodiscard]] static auto mul_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> mul_2_d_ret;

struct div_1_d_ret { double r; cpp2::taylor<double,6> r_d; };

public: [[nodiscard]] static auto div_1_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> div_1_d_ret;

struct div_2_d_ret { double r; cpp2::taylor<double,6> r_d; };

public: [[nodiscard]] static auto div_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> div_2_d_ret;

struct mul_div_2_d_ret { double r; cpp2::taylor<double,6> r_d; };

public: [[nodiscard]] static auto mul_div_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> mul_div_2_d_ret;

struct mul_add_d_ret { double r; cpp2::taylor<double,6> r_d; };

public: [[nodiscard]] static auto mul_add_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> mul_add_d_ret;

struct add_mul_d_ret { double r; cpp2::taylor<double,6> r_d; };

public: [[nodiscard]] static auto add_mul_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> add_mul_d_ret;

    public: ad_test() = default;
    public: ad_test(ad_test const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(ad_test const&) -> void = delete;


#line 54 "pure2-autodiff-higher-order.cpp2"
};

auto write_output(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, cpp2::impl::in<ad_type> x_d, cpp2::impl::in<double> y, cpp2::impl::in<ad_type> y_d, auto const& ret) -> void;

#line 65 "pure2-autodiff-higher-order.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-autodiff-higher-order.cpp2"

#line 7 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::add_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 8 "pure2-autodiff-higher-order.cpp2"
        r.construct(x + y);
    return std::move(r.value()); }

#line 11 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::add_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 12 "pure2-autodiff-higher-order.cpp2"
        r.construct(x + y + x);
    return std::move(r.value()); }

#line 15 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::sub_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 16 "pure2-autodiff-higher-order.cpp2"
        r.construct(x - y);
    return std::move(r.value()); }

#line 19 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 20 "pure2-autodiff-higher-order.cpp2"
        r.construct(x - y - x);
    return std::move(r.value()); }

#line 23 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::add_sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_sub_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 24 "pure2-autodiff-higher-order.cpp2"
        r.construct(x + y - x);
    return std::move(r.value()); }

#line 27 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::mul_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 28 "pure2-autodiff-higher-order.cpp2"
        r.construct(x * y);
    return std::move(r.value()); }

#line 31 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::mul_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 32 "pure2-autodiff-higher-order.cpp2"
        r.construct(x * y * x);
    return std::move(r.value()); }

#line 35 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::div_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 36 "pure2-autodiff-higher-order.cpp2"
        r.construct(x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y));
    return std::move(r.value()); }

#line 39 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 40 "pure2-autodiff-higher-order.cpp2"
        r.construct(x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y),y));
    return std::move(r.value()); }

#line 43 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::mul_div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_div_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 44 "pure2-autodiff-higher-order.cpp2"
        r.construct(x * y / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y),x));
    return std::move(r.value()); }

#line 47 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::mul_add(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_add_ret{
            cpp2::impl::deferred_init<double> r;
#line 48 "pure2-autodiff-higher-order.cpp2"
        r.construct(x * (x + y));
    return std::move(r.value()); }

#line 51 "pure2-autodiff-higher-order.cpp2"
    [[nodiscard]] auto ad_test::add_mul(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_mul_ret{
            cpp2::impl::deferred_init<double> r;
#line 52 "pure2-autodiff-higher-order.cpp2"
        r.construct(x + x * y);
    return std::move(r.value()); }

    [[nodiscard]] auto ad_test::add_1_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> add_1_d_ret{
                                                                                                                                                                      double r {0.0};
                                                                                                                                                                      cpp2::taylor<double,6> r_d {0.0};r_d = x_d + y_d;
    r = x + y;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::add_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> add_2_d_ret{
                                                                                                                                                                      double r {0.0};
                                                                                                                                                                      cpp2::taylor<double,6> r_d {0.0};r_d = x_d + y_d + x_d;
    r = x + y + x;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::sub_1_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> sub_1_d_ret{
                                                                                                                                                                      double r {0.0};
                                                                                                                                                                      cpp2::taylor<double,6> r_d {0.0};r_d = x_d - y_d;
    r = x - y;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::sub_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> sub_2_d_ret{
                                                                                                                                                                      double r {0.0};
                                                                                                                                                                      cpp2::taylor<double,6> r_d {0.0};r_d = x_d - y_d - x_d;
    r = x - y - x;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::add_sub_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> add_sub_2_d_ret{
                                                                                                                                                                          double r {0.0};
                                                                                                                                                                          cpp2::taylor<double,6> r_d {0.0};r_d = x_d + y_d - x_d;
    r = x + y - x;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_1_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> mul_1_d_ret{
                                                                                                                                                                      double r {0.0};
                                                                                                                                                                      cpp2::taylor<double,6> r_d {0.0};r_d = CPP2_UFCS(mul)(x_d, y_d, x, y);
    r = x * y;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> mul_2_d_ret{
                                                                                                                                                                      double r {0.0};
                                                                                                                                                                      cpp2::taylor<double,6> r_d {0.0};
auto temp_1_d {CPP2_UFCS(mul)(x_d, y_d, x, y)}; 
auto temp_1 {x * y}; r_d = CPP2_UFCS(mul)(cpp2::move(temp_1_d), x_d, temp_1, x);
    r = cpp2::move(temp_1) * x;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::div_1_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> div_1_d_ret{
                                                                                                                                                                      double r {0.0};
                                                                                                                                                                      cpp2::taylor<double,6> r_d {0.0};r_d = CPP2_UFCS(div)(x_d, y_d, x, y);
    r = x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::div_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> div_2_d_ret{
                                                                                                                                                                      double r {0.0};
                                                                                                                                                                      cpp2::taylor<double,6> r_d {0.0};
auto temp_1_d {CPP2_UFCS(div)(x_d, y_d, x, y)}; 
auto temp_1 {x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y)}; r_d = CPP2_UFCS(div)(cpp2::move(temp_1_d), y_d, temp_1, y);
    r = cpp2::move(temp_1) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1)),y);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_div_2_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> mul_div_2_d_ret{
                                                                                                                                                                          double r {0.0};
                                                                                                                                                                          cpp2::taylor<double,6> r_d {0.0};
auto temp_1_d {CPP2_UFCS(mul)(x_d, y_d, x, y)}; 
auto temp_1 {x * y}; r_d = CPP2_UFCS(div)(cpp2::move(temp_1_d), x_d, temp_1, x);
    r = cpp2::move(temp_1) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1)),x);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_add_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> mul_add_d_ret{
                                                                                                                                                                        double r {0.0};
                                                                                                                                                                        cpp2::taylor<double,6> r_d {0.0};
auto temp_1_d {x_d + y_d}; 

    auto temp_1 {x + y}; 
    r_d = CPP2_UFCS(mul)(x_d, cpp2::move(temp_1_d), x, temp_1);
    r = x * cpp2::move(temp_1);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::add_mul_d(cpp2::impl::in<double> x, cpp2::impl::in<cpp2::taylor<double,6>> x_d, cpp2::impl::in<double> y, cpp2::impl::in<cpp2::taylor<double,6>> y_d) -> add_mul_d_ret{
                                                                                                                                                                        double r {0.0};
                                                                                                                                                                        cpp2::taylor<double,6> r_d {0.0};
auto temp_1_d {CPP2_UFCS(mul)(x_d, y_d, x, y)}; 

    auto temp_1 {x * y}; 
    r_d = x_d + cpp2::move(temp_1_d);
    r = x + cpp2::move(temp_1);
    return  { std::move(r), std::move(r_d) }; 
    }

#line 56 "pure2-autodiff-higher-order.cpp2"
auto write_output(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, cpp2::impl::in<ad_type> x_d, cpp2::impl::in<double> y, cpp2::impl::in<ad_type> y_d, auto const& ret) -> void{
    std::cout << "diff(" + cpp2::to_string(func) + ") at (x = " + cpp2::to_string(x) + ", x_d = " + cpp2::to_string(x_d) + ", y = " + cpp2::to_string(y) + ", y_d = " + cpp2::to_string(y_d) + "):" << std::endl;
    std::cout << "  r = " + cpp2::to_string(ret.r) + "" << std::endl;
{
auto i{1};

#line 60 "pure2-autodiff-higher-order.cpp2"
    for( ; cpp2::impl::cmp_less_eq(i,ad_order); i += 1 ) {
      std::cout << "  d" + cpp2::to_string(i) + " = " + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(ret.r_d, i)) + "" << std::endl;
    }
}
#line 63 "pure2-autodiff-higher-order.cpp2"
}

#line 65 "pure2-autodiff-higher-order.cpp2"
auto main() -> int{

#line 68 "pure2-autodiff-higher-order.cpp2"
    double x {2.0}; 
    ad_type x_d {1.0}; 
    double y {3.0}; 
    ad_type y_d {2.0}; 

    write_output("x + y", x, x_d, y, y_d, ad_test::add_1_d(x, x_d, y, y_d));
    write_output("x + y + x", x, x_d, y, y_d, ad_test::add_2_d(x, x_d, y, y_d));
    write_output("x - y", x, x_d, y, y_d, ad_test::sub_1_d(x, x_d, y, y_d));
    write_output("x - y - x", x, x_d, y, y_d, ad_test::sub_2_d(x, x_d, y, y_d));
    write_output("x + y - x", x, x_d, y, y_d, ad_test::add_sub_2_d(x, x_d, y, y_d));
    write_output("x * y", x, x_d, y, y_d, ad_test::mul_1_d(x, x_d, y, y_d));
    write_output("x * y * x", x, x_d, y, y_d, ad_test::mul_2_d(x, x_d, y, y_d));
    write_output("x / y", x, x_d, y, y_d, ad_test::div_1_d(x, x_d, y, y_d));
    write_output("x / y / y", x, x_d, y, y_d, ad_test::div_2_d(x, x_d, y, y_d));
    write_output("x * y / x", x, x_d, y, y_d, ad_test::mul_div_2_d(x, x_d, y, y_d));
    write_output("x * (x + y)", x, x_d, y, y_d, ad_test::mul_add_d(x, x_d, y, y_d));
    write_output("x + x * y", x, x_d, y, y_d, ad_test::add_mul_d(cpp2::move(x), cpp2::move(x_d), cpp2::move(y), cpp2::move(y_d)));
//    write_output("x * func(x, y)", x, x_d, y, y_d, ad_test::func_call_d(x, x_d, y, y_d));
//    write_output("sin(x + y)", x, x_d, y, y_d, ad_test::sin_call_d(x, x_d, y, y_d));
//    write_output("if branch", x, x_d, y, y_d, ad_test::if_branch_d(x, x_d, y, y_d));
//    write_output("if else branch", x, x_d, y, y_d, ad_test::if_else_branch_d(x, x_d, y, y_d));
//    write_output("direct return", x, x_d, y, y_d, ad_test::direct_return_d(x, x_d, y, y_d));
//    write_output("intermediate var", x, x_d, y, y_d, ad_test::intermediate_var_d(x, x_d, y, y_d));
//    write_output("intermediate passive var", x, x_d, y, y_d, ad_test::intermediate_passive_var_d(x, x_d, y, y_d));
//    write_output("intermediate untyped", x, x_d, y, y_d, ad_test::intermediate_untyped_d(x, x_d, y, y_d));
//    write_output("intermediate default init", x, x_d, y, y_d, ad_test::intermediate_default_init_d(x, x_d, y, y_d));
//    write_output("intermediate no init", x, x_d, y, y_d, ad_test::intermediate_no_init_d(x, x_d, y, y_d));
//    write_output("while loop", x, x_d, y, y_d, ad_test::while_loop_d(x, x_d, y, y_d));
//    write_output("do while loop", x, x_d, y, y_d, ad_test::do_while_loop_d(x, x_d, y, y_d));
//    write_output("for loop", x, x_d, y, y_d, ad_test::for_loop_d(x, x_d, y, y_d));
}

