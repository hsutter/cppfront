#include <cpp2taylor.h>


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-autodiff-taylor.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-autodiff-taylor.cpp2"

#line 3 "mixed-autodiff-taylor.cpp2"
int inline constexpr order{ 6 };
using taylor = cpp2::taylor<double,order>;

struct test_add_ret { double y0; taylor y; };

#line 6 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_add(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_add_ret;
struct test_sub_ret { double y0; taylor y; };



#line 11 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_sub(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_sub_ret;
struct test_mul_ret { double y0; taylor y; };



#line 19 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_mul(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_mul_ret;
struct test_div_ret { double y0; taylor y; };



#line 30 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_div(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_div_ret;
struct test_sqrt_ret { double y0; taylor y; };



#line 38 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_sqrt(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_sqrt_ret;
struct test_log_ret { double y0; taylor y; };



#line 43 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_log(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_log_ret;
struct test_exp_ret { double y0; taylor y; };



#line 48 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_exp(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_exp_ret;
struct test_sin_ret { double y0; taylor y; };



#line 53 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_sin(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_sin_ret;
struct test_cos_ret { double y0; taylor y; };



#line 58 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_cos(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_cos_ret;

#line 63 "mixed-autodiff-taylor.cpp2"
auto write_output(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, cpp2::impl::in<taylor> x_d, auto const& ret) -> void;

#line 73 "mixed-autodiff-taylor.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-autodiff-taylor.cpp2"

#line 6 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_add(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_add_ret{
      cpp2::impl::deferred_init<double> y0;
      cpp2::impl::deferred_init<taylor> y;
#line 7 "mixed-autodiff-taylor.cpp2"
  y.construct(CPP2_UFCS(add)(x, x, x0, x0));
  y0.construct(x0 + x0);
return  { std::move(y0.value()), std::move(y.value()) }; }

#line 11 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_sub(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_sub_ret{
      cpp2::impl::deferred_init<double> y0;
      cpp2::impl::deferred_init<taylor> y;
#line 12 "mixed-autodiff-taylor.cpp2"
  y0.construct(0.0);
  y.construct(taylor());

  y.value() = CPP2_UFCS(sub)(y.value(), x, y0.value(), x0);
  y0.value() = y0.value() - x0;
return  { std::move(y0.value()), std::move(y.value()) }; }

#line 19 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_mul(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_mul_ret{
      cpp2::impl::deferred_init<double> y0;
      cpp2::impl::deferred_init<taylor> y;
#line 20 "mixed-autodiff-taylor.cpp2"
  y0.construct(x0);
  y.construct(x);
{
auto i{0};

#line 24 "mixed-autodiff-taylor.cpp2"
  for( ; cpp2::impl::cmp_less(i,6); i += 1 ) {
    y.value() = y.value().mul(x, y0.value(), x0);
    y0.value() *= x0;
  }
}
#line 25 "mixed-autodiff-taylor.cpp2"
    return  { std::move(y0.value()), std::move(y.value()) }; 

#line 28 "mixed-autodiff-taylor.cpp2"
}

#line 30 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_div(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_div_ret{
      cpp2::impl::deferred_init<double> y0;
      cpp2::impl::deferred_init<taylor> y;
#line 31 "mixed-autodiff-taylor.cpp2"
  y0.construct(1.0);
  y.construct(taylor());

  y.value() = CPP2_UFCS(div)(y.value(), x, y0.value(), x0);
  y0.value() /= CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y0.value()),x0);
return  { std::move(y0.value()), std::move(y.value()) }; }

#line 38 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_sqrt(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_sqrt_ret{
      cpp2::impl::deferred_init<double> y0;
      cpp2::impl::deferred_init<taylor> y;
#line 39 "mixed-autodiff-taylor.cpp2"
  y0.construct(sqrt(x0));
  y.construct(CPP2_UFCS(sqrt)(x, x0));
return  { std::move(y0.value()), std::move(y.value()) }; }

#line 43 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_log(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_log_ret{
      cpp2::impl::deferred_init<double> y0;
      cpp2::impl::deferred_init<taylor> y;
#line 44 "mixed-autodiff-taylor.cpp2"
  y0.construct(log(x0));
  y.construct(CPP2_UFCS(log)(x, x0));
return  { std::move(y0.value()), std::move(y.value()) }; }

#line 48 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_exp(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_exp_ret{
      cpp2::impl::deferred_init<double> y0;
      cpp2::impl::deferred_init<taylor> y;
#line 49 "mixed-autodiff-taylor.cpp2"
  y0.construct(exp(x0));
  y.construct(CPP2_UFCS(exp)(x, x0));
return  { std::move(y0.value()), std::move(y.value()) }; }

#line 53 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_sin(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_sin_ret{
      cpp2::impl::deferred_init<double> y0;
      cpp2::impl::deferred_init<taylor> y;
#line 54 "mixed-autodiff-taylor.cpp2"
  y0.construct(sin(x0));
  y.construct(CPP2_UFCS(sin)(x, x0));
return  { std::move(y0.value()), std::move(y.value()) }; }

#line 58 "mixed-autodiff-taylor.cpp2"
[[nodiscard]] auto test_cos(cpp2::impl::in<double> x0, cpp2::impl::in<taylor> x) -> test_cos_ret{
      cpp2::impl::deferred_init<double> y0;
      cpp2::impl::deferred_init<taylor> y;
#line 59 "mixed-autodiff-taylor.cpp2"
  y0.construct(cos(x0));
  y.construct(CPP2_UFCS(cos)(x, x0));
return  { std::move(y0.value()), std::move(y.value()) }; }

#line 63 "mixed-autodiff-taylor.cpp2"
auto write_output(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, cpp2::impl::in<taylor> x_d, auto const& ret) -> void{
    static_cast<void>(x);
    static_cast<void>(x_d);
    std::cout << "" + cpp2::to_string(func) + " = " + cpp2::to_string(ret.y0) + "" << std::endl;
{
auto i{1};

#line 68 "mixed-autodiff-taylor.cpp2"
    for( ; cpp2::impl::cmp_less_eq(i,order); i += 1 ) {
       std::cout << "" + cpp2::to_string(func) + " diff order " + cpp2::to_string(i) + " = " + cpp2::to_string(CPP2_ASSERT_IN_BOUNDS(ret.y, i)) + "" << std::endl;
    }
}
#line 71 "mixed-autodiff-taylor.cpp2"
}

#line 73 "mixed-autodiff-taylor.cpp2"
auto main() -> int{

    double x {2.0}; 
    taylor x_d {1.0}; 

    write_output("x + x", x, x_d, test_add(x, x_d));
    write_output("0 - x", x, x_d, test_sub(x, x_d));
    write_output("x^7", x, x_d, test_mul(x, x_d));
    write_output("1/x", x, x_d, test_div(x, x_d));
    write_output("sqrt(x)", x, x_d, test_sqrt(x, x_d));
    write_output("log(x)", x, x_d, test_log(x, x_d));
    write_output("exp(x)", x, x_d, test_exp(x, x_d));
    write_output("sin(x)", x, x_d, test_sin(x, x_d));
    write_output("cos(x)", x, x_d, test_cos(cpp2::move(x), cpp2::move(x_d)));
}

