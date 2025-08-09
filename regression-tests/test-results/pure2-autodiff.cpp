
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-autodiff.cpp2"

#line 2 "pure2-autodiff.cpp2"
class ad_test;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-autodiff.cpp2"

#line 2 "pure2-autodiff.cpp2"
class ad_test {
using add_1_ret = double;


#line 4 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto add_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_1_ret;
using add_2_ret = double;


#line 8 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto add_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_2_ret;
using sub_1_ret = double;


#line 12 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto sub_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_1_ret;
using sub_2_ret = double;


#line 16 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_2_ret;
using add_sub_2_ret = double;


#line 20 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto add_sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_sub_2_ret;
using mul_1_ret = double;


#line 24 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto mul_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_1_ret;
using mul_2_ret = double;


#line 28 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto mul_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_2_ret;
using div_1_ret = double;


#line 32 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto div_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_1_ret;
using div_2_ret = double;


#line 36 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_2_ret;
using mul_div_2_ret = double;


#line 40 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto mul_div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_div_2_ret;
struct add_1_diff_ret { double r; double r_d; };


    public: [[nodiscard]] static auto add_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_1_diff_ret;

struct add_2_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto add_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_2_diff_ret;

struct sub_1_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto sub_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sub_1_diff_ret;

struct sub_2_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto sub_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sub_2_diff_ret;

struct add_sub_2_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto add_sub_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_sub_2_diff_ret;

struct mul_1_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto mul_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_1_diff_ret;

struct mul_2_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto mul_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_2_diff_ret;

struct div_1_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto div_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> div_1_diff_ret;

struct div_2_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto div_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> div_2_diff_ret;

struct mul_div_2_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto mul_div_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_div_2_diff_ret;

    public: ad_test() = default;
    public: ad_test(ad_test const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(ad_test const&) -> void = delete;


#line 43 "pure2-autodiff.cpp2"
};

auto write_output(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d, auto const& ret) -> void;

#line 49 "pure2-autodiff.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-autodiff.cpp2"

#line 4 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::add_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 5 "pure2-autodiff.cpp2"
        r.construct(x + y);
    return std::move(r.value()); }

#line 8 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::add_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 9 "pure2-autodiff.cpp2"
        r.construct(x + y + x);
    return std::move(r.value()); }

#line 12 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::sub_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 13 "pure2-autodiff.cpp2"
        r.construct(x - y);
    return std::move(r.value()); }

#line 16 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 17 "pure2-autodiff.cpp2"
        r.construct(x - y - x);
    return std::move(r.value()); }

#line 20 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::add_sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_sub_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 21 "pure2-autodiff.cpp2"
        r.construct(x + y - x);
    return std::move(r.value()); }

#line 24 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::mul_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 25 "pure2-autodiff.cpp2"
        r.construct(x * y);
    return std::move(r.value()); }

#line 28 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::mul_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 29 "pure2-autodiff.cpp2"
        r.construct(x * y * x);
    return std::move(r.value()); }

#line 32 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::div_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 33 "pure2-autodiff.cpp2"
        r.construct(x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y));
    return std::move(r.value()); }

#line 36 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 37 "pure2-autodiff.cpp2"
        r.construct(x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y),y));
    return std::move(r.value()); }

#line 40 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::mul_div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_div_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 41 "pure2-autodiff.cpp2"
        r.construct(x * y / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y),x));
    return std::move(r.value()); }

    [[nodiscard]] auto ad_test::add_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_1_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x_d + y_d;r = x + y;
    return  { std::move(r), std::move(r_d) }; 
    }
[[nodiscard]] auto ad_test::add_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_2_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x_d + y_d + x_d;r = x + y + x;
    return  { std::move(r), std::move(r_d) }; 
    }
[[nodiscard]] auto ad_test::sub_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sub_1_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x_d - y_d;r = x - y;
    return  { std::move(r), std::move(r_d) }; 
    }
[[nodiscard]] auto ad_test::sub_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sub_2_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x_d - y_d - x_d;r = x - y - x;
    return  { std::move(r), std::move(r_d) }; 
    }
[[nodiscard]] auto ad_test::add_sub_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_sub_2_diff_ret{
                                                                                                                          double r {0.0};
                                                                                                                          double r_d {0.0};r_d = x_d + y_d - x_d;r = x + y - x;
    return  { std::move(r), std::move(r_d) }; 
    }
[[nodiscard]] auto ad_test::mul_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_1_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x * y_d + y * x_d;r = x * y;
    return  { std::move(r), std::move(r_d) }; 
    }
[[nodiscard]] auto ad_test::mul_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_2_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};
auto temp_1_d {x * y_d + y * x_d}; 
auto temp_1 {x * y}; r_d = temp_1 * x_d + x * cpp2::move(temp_1_d);r = cpp2::move(temp_1) * x;
    return  { std::move(r), std::move(r_d) }; 
    }
[[nodiscard]] auto ad_test::div_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> div_1_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x_d),y) - x * y_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y_d),(y * y));r = x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y);
    return  { std::move(r), std::move(r_d) }; 
    }
[[nodiscard]] auto ad_test::div_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> div_2_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};
auto temp_1_d {x_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x_d),y) - x * y_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y_d),(y * y))}; 
auto temp_1 {x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y)}; r_d = cpp2::move(temp_1_d) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1_d)),y) - temp_1 * y_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y_d),(y * y));r = cpp2::move(temp_1) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1)),y);
    return  { std::move(r), std::move(r_d) }; 
    }
[[nodiscard]] auto ad_test::mul_div_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_div_2_diff_ret{
                                                                                                                          double r {0.0};
                                                                                                                          double r_d {0.0};
auto temp_1_d {x * y_d + y * x_d}; 
auto temp_1 {x * y}; r_d = cpp2::move(temp_1_d) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1_d)),x) - temp_1 * x_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x_d),(x * x));r = cpp2::move(temp_1) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1)),x);
    return  { std::move(r), std::move(r_d) }; 
    }

#line 45 "pure2-autodiff.cpp2"
auto write_output(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d, auto const& ret) -> void{
    std::cout << "diff(" + cpp2::to_string(func) + ") at (x = " + cpp2::to_string(x) + ", x_d = " + cpp2::to_string(x_d) + ", y = " + cpp2::to_string(y) + ", y_d = " + cpp2::to_string(y_d) + ") = (r = " + cpp2::to_string(ret.r) + ", r_d = " + cpp2::to_string(ret.r_d) + ")" << std::endl;
}

#line 49 "pure2-autodiff.cpp2"
auto main() -> int{

    double x {2.0}; 
    double x_d {1.0}; 
    double y {3.0}; 
    double y_d {2.0}; 

    write_output("x + y", x, x_d, y, y_d, ad_test::add_1_diff(x, x_d, y, y_d));
    write_output("x + y + x", x, x_d, y, y_d, ad_test::add_2_diff(x, x_d, y, y_d));
    write_output("x - y", x, x_d, y, y_d, ad_test::sub_1_diff(x, x_d, y, y_d));
    write_output("x - y - x", x, x_d, y, y_d, ad_test::sub_2_diff(x, x_d, y, y_d));
    write_output("x + y - x", x, x_d, y, y_d, ad_test::add_sub_2_diff(x, x_d, y, y_d));
    write_output("x * y", x, x_d, y, y_d, ad_test::mul_1_diff(x, x_d, y, y_d));
    write_output("x * y * x", x, x_d, y, y_d, ad_test::mul_2_diff(x, x_d, y, y_d));
    write_output("x / y", x, x_d, y, y_d, ad_test::div_1_diff(x, x_d, y, y_d));
    write_output("x / y / y", x, x_d, y, y_d, ad_test::div_2_diff(x, x_d, y, y_d));
    write_output("x * y / x", x, x_d, y, y_d, ad_test::mul_div_2_diff(cpp2::move(x), cpp2::move(x_d), cpp2::move(y), cpp2::move(y_d)));
}

