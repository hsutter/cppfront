
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
using mul_add_ret = double;


#line 44 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto mul_add(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_add_ret;
using add_mul_ret = double;


#line 48 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto add_mul(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_mul_ret;
using func_ret = double;


#line 52 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto func(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_ret;
using func_call_ret = double;


#line 56 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto func_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_call_ret;
using sin_call_ret = double;


#line 60 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto sin_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sin_call_ret;
using if_branch_ret = double;


#line 64 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto if_branch(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> if_branch_ret;
using if_else_branch_ret = double;


#line 72 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto if_else_branch(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> if_else_branch_ret;

#line 81 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto direct_return(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> double;
using intermediate_var_ret = double;


#line 85 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto intermediate_var(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_var_ret;
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

struct mul_add_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto mul_add_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_add_diff_ret;

struct add_mul_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto add_mul_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_mul_diff_ret;

struct func_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto func_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_diff_ret;

struct func_call_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto func_call_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_call_diff_ret;

struct sin_call_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto sin_call_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sin_call_diff_ret;

struct if_branch_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto if_branch_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> if_branch_diff_ret;

struct if_else_branch_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto if_else_branch_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> if_else_branch_diff_ret;

struct direct_return_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto direct_return_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> direct_return_diff_ret;

struct intermediate_var_diff_ret { double r; double r_d; };

public: [[nodiscard]] static auto intermediate_var_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_var_diff_ret;

    public: ad_test() = default;
    public: ad_test(ad_test const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(ad_test const&) -> void = delete;


#line 91 "pure2-autodiff.cpp2"
};

auto write_output(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d, auto const& ret) -> void;

#line 97 "pure2-autodiff.cpp2"
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

#line 44 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::mul_add(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_add_ret{
            cpp2::impl::deferred_init<double> r;
#line 45 "pure2-autodiff.cpp2"
        r.construct(x * (x + y));
    return std::move(r.value()); }

#line 48 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::add_mul(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_mul_ret{
            cpp2::impl::deferred_init<double> r;
#line 49 "pure2-autodiff.cpp2"
        r.construct(x + x * y);
    return std::move(r.value()); }

#line 52 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::func(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_ret{
          cpp2::impl::deferred_init<double> r;
#line 53 "pure2-autodiff.cpp2"
      r.construct(x + y);
    return std::move(r.value()); }

#line 56 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::func_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_call_ret{
          cpp2::impl::deferred_init<double> r;
#line 57 "pure2-autodiff.cpp2"
      r.construct(x * func(x, y));
    return std::move(r.value()); }

#line 60 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::sin_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sin_call_ret{
          cpp2::impl::deferred_init<double> r;
#line 61 "pure2-autodiff.cpp2"
      r.construct(sin(x - y));
    return std::move(r.value()); }

#line 64 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::if_branch(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> if_branch_ret{
          cpp2::impl::deferred_init<double> r;
#line 65 "pure2-autodiff.cpp2"
      r.construct(x);

      if (cpp2::impl::cmp_less(x,0.0)) {
        r.value() = y;
      }return std::move(r.value()); 
    }

#line 72 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::if_else_branch(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> if_else_branch_ret{
          cpp2::impl::deferred_init<double> r;
#line 73 "pure2-autodiff.cpp2"
      if (cpp2::impl::cmp_less(x,0.0)) {
        r.construct(y);
      }
      else {
        r.construct(x);
      }return std::move(r.value()); 
    }

#line 81 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::direct_return(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> double{
      return x + y; 
    }

#line 85 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::intermediate_var(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_var_ret{
          cpp2::impl::deferred_init<double> r;
#line 86 "pure2-autodiff.cpp2"
      double t {};    // TODO: change to x initializer when we have access to the initializer expression.
      t = x + y;

      r.construct(cpp2::move(t));
    return std::move(r.value()); }

    [[nodiscard]] auto ad_test::add_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_1_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x_d + y_d;r = x + y;return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::add_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_2_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x_d + y_d + x_d;r = x + y + x;return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::sub_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sub_1_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x_d - y_d;r = x - y;return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::sub_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sub_2_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x_d - y_d - x_d;r = x - y - x;return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::add_sub_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_sub_2_diff_ret{
                                                                                                                          double r {0.0};
                                                                                                                          double r_d {0.0};r_d = x_d + y_d - x_d;r = x + y - x;return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_1_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x * y_d + y * x_d;r = x * y;return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_2_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};
auto temp_1_d {x * y_d + y * x_d}; 
auto temp_1 {x * y}; r_d = temp_1 * x_d + x * cpp2::move(temp_1_d);r = cpp2::move(temp_1) * x;return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::div_1_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> div_1_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};r_d = x_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x_d),y) - x * y_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y_d),(y * y));r = x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y);return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::div_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> div_2_diff_ret{
                                                                                                                      double r {0.0};
                                                                                                                      double r_d {0.0};
auto temp_1_d {x_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x_d),y) - x * y_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y_d),(y * y))}; 
auto temp_1 {x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y)}; r_d = cpp2::move(temp_1_d) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1_d)),y) - temp_1 * y_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y_d),(y * y));r = cpp2::move(temp_1) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1)),y);return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_div_2_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_div_2_diff_ret{
                                                                                                                          double r {0.0};
                                                                                                                          double r_d {0.0};
auto temp_1_d {x * y_d + y * x_d}; 
auto temp_1 {x * y}; r_d = cpp2::move(temp_1_d) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1_d)),x) - temp_1 * x_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x_d),(x * x));r = cpp2::move(temp_1) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1)),x);return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_add_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_add_diff_ret{
                                                                                                                        double r {0.0};
                                                                                                                        double r_d {0.0};
auto temp_1_d {x_d + y_d}; 
auto temp_1 {x + y}; r_d = x * cpp2::move(temp_1_d) + temp_1 * x_d;r = x * cpp2::move(temp_1);return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::add_mul_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_mul_diff_ret{
                                                                                                                        double r {0.0};
                                                                                                                        double r_d {0.0};
auto temp_1_d {x * y_d + y * x_d}; 
auto temp_1 {x * y}; r_d = x_d + cpp2::move(temp_1_d);r = x + cpp2::move(temp_1);return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::func_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_diff_ret{
                                                                                                                     double r {0.0};
                                                                                                                     double r_d {0.0};r_d = x_d + y_d;r = x + y;return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::func_call_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_call_diff_ret{
                                                                                                                          double r {0.0};
                                                                                                                          double r_d {0.0};
auto temp_2 {func_diff(x, x_d, y, y_d)}; 

    auto temp_1 {temp_2.r}; 

    auto temp_1_d {cpp2::move(temp_2).r_d}; 
    r_d = x * cpp2::move(temp_1_d) + temp_1 * x_d;r = x * cpp2::move(temp_1);return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::sin_call_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sin_call_diff_ret{
                                                                                                                         double r {0.0};
                                                                                                                         double r_d {0.0};
auto temp_1_d {x_d - y_d}; 
auto temp_1 {x - y}; r_d = cos(temp_1) * cpp2::move(temp_1_d);
    r = sin(cpp2::move(temp_1));
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::if_branch_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> if_branch_diff_ret{
                                                                                                                          double r {0.0};
                                                                                                                          double r_d {0.0};r_d = x_d;r = x;if (cpp2::impl::cmp_less(x,0.0)) {
    r_d = y_d;r = y;}
    else {
    }
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::if_else_branch_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> if_else_branch_diff_ret{
                                                                                                                               double r {0.0};
                                                                                                                               double r_d {0.0};if (cpp2::impl::cmp_less(x,0.0)) {
    r_d = y_d;r = y;}
    else {
    r_d = x_d;r = x;}
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::direct_return_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> direct_return_diff_ret{
                                                                                                                          double r {};
                                                                                                                          double r_d {};r_d = x_d + y_d;r = x + y;
    return  { std::move(r), std::move(r_d) }; 
    }
[[nodiscard]] auto ad_test::intermediate_var_diff(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_var_diff_ret{
                                                                                                                                 double r {0.0};
                                                                                                                                 double r_d {0.0};
double t_d {}; 

    double t {}; 
    t_d = x_d + y_d;t = x + y;r_d = cpp2::move(t_d);r = cpp2::move(t);return  { std::move(r), std::move(r_d) }; 
    }

#line 93 "pure2-autodiff.cpp2"
auto write_output(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d, auto const& ret) -> void{
    std::cout << "diff(" + cpp2::to_string(func) + ") at (x = " + cpp2::to_string(x) + ", x_d = " + cpp2::to_string(x_d) + ", y = " + cpp2::to_string(y) + ", y_d = " + cpp2::to_string(y_d) + ") = (r = " + cpp2::to_string(ret.r) + ", r_d = " + cpp2::to_string(ret.r_d) + ")" << std::endl;
}

#line 97 "pure2-autodiff.cpp2"
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
    write_output("x * y / x", x, x_d, y, y_d, ad_test::mul_div_2_diff(x, x_d, y, y_d));
    write_output("x * (x + y)", x, x_d, y, y_d, ad_test::mul_add_diff(x, x_d, y, y_d));
    write_output("x + x * y", x, x_d, y, y_d, ad_test::add_mul_diff(x, x_d, y, y_d));
    write_output("x * func(x, y)", x, x_d, y, y_d, ad_test::func_call_diff(x, x_d, y, y_d));
    write_output("sin(x + y)", x, x_d, y, y_d, ad_test::sin_call_diff(x, x_d, y, y_d));
    write_output("if branch", x, x_d, y, y_d, ad_test::if_branch_diff(x, x_d, y, y_d));
    write_output("if else branch", x, x_d, y, y_d, ad_test::if_else_branch_diff(x, x_d, y, y_d));
    write_output("direct return", x, x_d, y, y_d, ad_test::direct_return_diff(x, x_d, y, y_d));
    write_output("intermediate var", x, x_d, y, y_d, ad_test::intermediate_var_diff(cpp2::move(x), cpp2::move(x_d), cpp2::move(y), cpp2::move(y_d)));
}

