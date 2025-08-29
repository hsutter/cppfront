
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-autodiff.cpp2"
namespace ad_name {

#line 7 "pure2-autodiff.cpp2"
class type_outer;
  
  class type_outer_d;


#line 15 "pure2-autodiff.cpp2"
class ad_test;

#line 194 "pure2-autodiff.cpp2"
class ad_test_reverse;

#line 204 "pure2-autodiff.cpp2"
}

class ad_test_twice;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-autodiff.cpp2"
namespace ad_name {
using func_outer_ret = double;


#line 3 "pure2-autodiff.cpp2"
[[nodiscard]] auto func_outer(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_outer_ret;

#line 7 "pure2-autodiff.cpp2"
class type_outer {
  public: double a {0.0}; 

  public: [[nodiscard]] auto add(cpp2::impl::in<double> b) const& -> double;
struct add_d_ret { double r; double r_d; };


  public: [[nodiscard]] auto add_d(cpp2::impl::in<type_outer_d> this_d, cpp2::impl::in<double> b, cpp2::impl::in<double> b_d) const& -> add_d_ret;

  public: type_outer() = default;
  public: type_outer(type_outer const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(type_outer const&) -> void = delete;


#line 13 "pure2-autodiff.cpp2"
};

struct func_outer_d_ret { double ret; double ret_d; };


[[nodiscard]] auto func_outer_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_outer_d_ret;
class type_outer_d {
public: double a_d {}; 
 public: type_outer_d() = default;
 public: type_outer_d(type_outer_d const&) = delete; /* No 'that' constructor, suppress copy */
 public: auto operator=(type_outer_d const&) -> void = delete;

};

#line 15 "pure2-autodiff.cpp2"
class ad_test {
using add_1_ret = double;


#line 17 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto add_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_1_ret;
using add_2_ret = double;


#line 21 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto add_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_2_ret;
using sub_1_ret = double;


#line 25 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto sub_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_1_ret;
using sub_2_ret = double;


#line 29 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_2_ret;
using add_sub_2_ret = double;


#line 33 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto add_sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_sub_2_ret;
using mul_1_ret = double;


#line 37 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto mul_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_1_ret;
using mul_2_ret = double;


#line 41 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto mul_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_2_ret;
using div_1_ret = double;


#line 45 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto div_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_1_ret;
using div_2_ret = double;


#line 49 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_2_ret;
using mul_div_2_ret = double;


#line 53 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto mul_div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_div_2_ret;
using mul_add_ret = double;


#line 57 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto mul_add(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_add_ret;
using add_mul_ret = double;


#line 61 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto add_mul(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_mul_ret;
using prefix_add_ret = double;


#line 65 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto prefix_add(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> prefix_add_ret;
using prefix_sub_ret = double;


#line 69 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto prefix_sub(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> prefix_sub_ret;
using func_ret = double;


#line 73 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto func(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_ret;
using func_call_ret = double;


#line 77 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto func_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_call_ret;
using func_outer_call_ret = double;


#line 81 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto func_outer_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_outer_call_ret;
using sin_call_ret = double;


#line 85 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto sin_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sin_call_ret;
using if_branch_ret = double;


#line 89 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto if_branch(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> if_branch_ret;
using if_else_branch_ret = double;


#line 97 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto if_else_branch(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> if_else_branch_ret;

#line 106 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto direct_return(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> double;
using intermediate_var_ret = double;


#line 110 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto intermediate_var(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_var_ret;
using intermediate_passive_var_ret = double;


#line 116 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto intermediate_passive_var(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_passive_var_ret;
using intermediate_untyped_ret = double;


#line 124 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto intermediate_untyped(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_untyped_ret;
using intermediate_default_init_ret = double;


#line 131 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto intermediate_default_init(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_default_init_ret;
using intermediate_no_init_ret = double;


#line 138 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto intermediate_no_init(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_no_init_ret;
using while_loop_ret = double;


#line 145 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto while_loop(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> while_loop_ret;
using do_while_loop_ret = double;


#line 154 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto do_while_loop(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> do_while_loop_ret;
using for_loop_ret = double;


#line 165 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto for_loop(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> for_loop_ret;
using type_outer_use_ret = double;


#line 179 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto type_outer_use(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> type_outer_use_ret;
using type_outer_call_ret = double;


#line 186 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto type_outer_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> type_outer_call_ret;
struct add_1_d_ret { double r; double r_d; };


    public: [[nodiscard]] static auto add_1_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_1_d_ret;

struct add_2_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto add_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_2_d_ret;

struct sub_1_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto sub_1_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sub_1_d_ret;

struct sub_2_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto sub_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sub_2_d_ret;

struct add_sub_2_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto add_sub_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_sub_2_d_ret;

struct mul_1_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto mul_1_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_1_d_ret;

struct mul_2_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto mul_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_2_d_ret;

struct div_1_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto div_1_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> div_1_d_ret;

struct div_2_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto div_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> div_2_d_ret;

struct mul_div_2_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto mul_div_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_div_2_d_ret;

struct mul_add_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto mul_add_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_add_d_ret;

struct add_mul_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto add_mul_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_mul_d_ret;

struct prefix_add_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto prefix_add_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> prefix_add_d_ret;

struct prefix_sub_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto prefix_sub_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> prefix_sub_d_ret;

struct func_d_ret { double ret; double ret_d; };

public: [[nodiscard]] static auto func_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_d_ret;

struct func_call_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto func_call_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_call_d_ret;

struct func_outer_call_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto func_outer_call_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_outer_call_d_ret;

struct sin_call_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto sin_call_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sin_call_d_ret;

struct if_branch_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto if_branch_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> if_branch_d_ret;

struct if_else_branch_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto if_else_branch_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> if_else_branch_d_ret;

struct direct_return_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto direct_return_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> direct_return_d_ret;

struct intermediate_var_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto intermediate_var_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_var_d_ret;

struct intermediate_passive_var_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto intermediate_passive_var_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_passive_var_d_ret;

struct intermediate_untyped_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto intermediate_untyped_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_untyped_d_ret;

struct intermediate_default_init_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto intermediate_default_init_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_default_init_d_ret;

struct intermediate_no_init_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto intermediate_no_init_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_no_init_d_ret;

struct while_loop_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto while_loop_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> while_loop_d_ret;

struct do_while_loop_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto do_while_loop_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> do_while_loop_d_ret;

struct for_loop_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto for_loop_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> for_loop_d_ret;

struct type_outer_use_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto type_outer_use_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> type_outer_use_d_ret;

struct type_outer_call_d_ret { double r; double r_d; };

public: [[nodiscard]] static auto type_outer_call_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> type_outer_call_d_ret;

    public: ad_test() = default;
    public: ad_test(ad_test const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(ad_test const&) -> void = delete;


#line 192 "pure2-autodiff.cpp2"
};

class ad_test_reverse {
using add_1_ret = double;


#line 196 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto add_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_1_ret;
using mul_1_ret = double;


#line 200 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto mul_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_1_ret;
using add_1_b_ret = double;

    public: [[nodiscard]] static auto add_1_b(cpp2::impl::in<double> x, double& x_b, cpp2::impl::in<double> y, double& y_b, double& r_b) -> add_1_b_ret;

using mul_1_b_ret = double;
public: [[nodiscard]] static auto mul_1_b(cpp2::impl::in<double> x, double& x_b, cpp2::impl::in<double> y, double& y_b, double& r_b) -> mul_1_b_ret;

    public: ad_test_reverse() = default;
    public: ad_test_reverse(ad_test_reverse const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(ad_test_reverse const&) -> void = delete;


#line 203 "pure2-autodiff.cpp2"
};
}

class ad_test_twice {
using mul_1_ret = double;

#line 207 "pure2-autodiff.cpp2"
    public: [[nodiscard]] static auto mul_1(cpp2::impl::in<double> x) -> mul_1_ret;
struct mul_1_d_ret { double r; double r_d; };


    public: [[nodiscard]] static auto mul_1_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d) -> mul_1_d_ret;

struct mul_1_d2_ret { double r; double r_d2; };

public: [[nodiscard]] static auto mul_1_d2(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d2) -> mul_1_d2_ret;

struct mul_1_d_d2_ret { double r; double r_d2; double r_d; double r_d_d2; };

public: [[nodiscard]] static auto mul_1_d_d2(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d2, cpp2::impl::in<double> x_d, cpp2::impl::in<double> x_d_d2) -> mul_1_d_d2_ret;

    public: ad_test_twice() = default;
    public: ad_test_twice(ad_test_twice const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(ad_test_twice const&) -> void = delete;


#line 210 "pure2-autodiff.cpp2"
};

auto write_output(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d, auto const& ret) -> void;

#line 216 "pure2-autodiff.cpp2"
auto write_output_reverse(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, double& x_b, cpp2::impl::in<double> y, double& y_b, cpp2::impl::in<double> r_b, auto const& ret) -> void;

#line 222 "pure2-autodiff.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-autodiff.cpp2"
namespace ad_name {

#line 3 "pure2-autodiff.cpp2"
[[nodiscard]] auto func_outer(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_outer_ret{
      cpp2::impl::deferred_init<double> ret;
#line 4 "pure2-autodiff.cpp2"
  ret.construct(x + y);
return std::move(ret.value()); }

#line 10 "pure2-autodiff.cpp2"
  [[nodiscard]] auto type_outer::add(cpp2::impl::in<double> b) const& -> double{
    return a + b; 
  }

  [[nodiscard]] auto type_outer::add_d(cpp2::impl::in<type_outer_d> this_d, cpp2::impl::in<double> b, cpp2::impl::in<double> b_d) const& -> add_d_ret{
                                                                                                                           double r {};
                                                                                                                           double r_d {};r_d = this_d.a_d + b_d;
  r = a + b;
  return  { std::move(r), std::move(r_d) }; }

  [[nodiscard]] auto func_outer_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_outer_d_ret{
                                                                                                                                                double ret {0.0};
                                                                                                                                                double ret_d {0.0};ret_d = x_d + y_d;
  ret = x + y;
  return  { std::move(ret), std::move(ret_d) }; 
  }



#line 17 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::add_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 18 "pure2-autodiff.cpp2"
        r.construct(x + y);
    return std::move(r.value()); }

#line 21 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::add_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 22 "pure2-autodiff.cpp2"
        r.construct(x + y + x);
    return std::move(r.value()); }

#line 25 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::sub_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 26 "pure2-autodiff.cpp2"
        r.construct(x - y);
    return std::move(r.value()); }

#line 29 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sub_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 30 "pure2-autodiff.cpp2"
        r.construct(x - y - x);
    return std::move(r.value()); }

#line 33 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::add_sub_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_sub_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 34 "pure2-autodiff.cpp2"
        r.construct(x + y - x);
    return std::move(r.value()); }

#line 37 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::mul_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 38 "pure2-autodiff.cpp2"
        r.construct(x * y);
    return std::move(r.value()); }

#line 41 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::mul_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 42 "pure2-autodiff.cpp2"
        r.construct(x * y * x);
    return std::move(r.value()); }

#line 45 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::div_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 46 "pure2-autodiff.cpp2"
        r.construct(x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y));
    return std::move(r.value()); }

#line 49 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> div_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 50 "pure2-autodiff.cpp2"
        r.construct(x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y),y));
    return std::move(r.value()); }

#line 53 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::mul_div_2(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_div_2_ret{
            cpp2::impl::deferred_init<double> r;
#line 54 "pure2-autodiff.cpp2"
        r.construct(x * y / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y),x));
    return std::move(r.value()); }

#line 57 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::mul_add(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_add_ret{
            cpp2::impl::deferred_init<double> r;
#line 58 "pure2-autodiff.cpp2"
        r.construct(x * (x + y));
    return std::move(r.value()); }

#line 61 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::add_mul(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_mul_ret{
            cpp2::impl::deferred_init<double> r;
#line 62 "pure2-autodiff.cpp2"
        r.construct(x + x * y);
    return std::move(r.value()); }

#line 65 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::prefix_add(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> prefix_add_ret{
            cpp2::impl::deferred_init<double> r;
#line 66 "pure2-autodiff.cpp2"
        r.construct(+x + y);
    return std::move(r.value()); }

#line 69 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::prefix_sub(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> prefix_sub_ret{
            cpp2::impl::deferred_init<double> r;
#line 70 "pure2-autodiff.cpp2"
        r.construct(-x + y);
    return std::move(r.value()); }

#line 73 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::func(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_ret{
          cpp2::impl::deferred_init<double> ret;
#line 74 "pure2-autodiff.cpp2"
      ret.construct(x + y);
    return std::move(ret.value()); }

#line 77 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::func_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_call_ret{
          cpp2::impl::deferred_init<double> r;
#line 78 "pure2-autodiff.cpp2"
      r.construct(x * func(x, y));
    return std::move(r.value()); }

#line 81 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::func_outer_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> func_outer_call_ret{
          cpp2::impl::deferred_init<double> r;
#line 82 "pure2-autodiff.cpp2"
      r.construct(x * func_outer(x, y));
    return std::move(r.value()); }

#line 85 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::sin_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> sin_call_ret{
          cpp2::impl::deferred_init<double> r;
#line 86 "pure2-autodiff.cpp2"
      r.construct(sin(x - y));
    return std::move(r.value()); }

#line 89 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::if_branch(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> if_branch_ret{
          cpp2::impl::deferred_init<double> r;
#line 90 "pure2-autodiff.cpp2"
      r.construct(x);

      if (cpp2::impl::cmp_less(x,0.0)) {
        r.value() = y;
      }return std::move(r.value()); 
    }

#line 97 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::if_else_branch(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> if_else_branch_ret{
          cpp2::impl::deferred_init<double> r;
#line 98 "pure2-autodiff.cpp2"
      if (cpp2::impl::cmp_less(x,0.0)) {
        r.construct(y);
      }
      else {
        r.construct(x);
      }return std::move(r.value()); 
    }

#line 106 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::direct_return(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> double{
      return x + y; 
    }

#line 110 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::intermediate_var(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_var_ret{
          cpp2::impl::deferred_init<double> r;
#line 111 "pure2-autodiff.cpp2"
      double t {x + y}; 

      r.construct(cpp2::move(t));
    return std::move(r.value()); }

#line 116 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::intermediate_passive_var(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_passive_var_ret{
          cpp2::impl::deferred_init<double> r;
#line 117 "pure2-autodiff.cpp2"
      int i {};    // TODO: Handle as passive when type information on call side is available.
      r.construct(x + y);
      i = 2;

      static_cast<void>(cpp2::move(i));
    return std::move(r.value()); }

#line 124 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::intermediate_untyped(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_untyped_ret{
          cpp2::impl::deferred_init<double> r;
#line 125 "pure2-autodiff.cpp2"
      auto t {0.0}; 
      t = x + y;

      r.construct(cpp2::move(t));
    return std::move(r.value()); }

#line 131 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::intermediate_default_init(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_default_init_ret{
          cpp2::impl::deferred_init<double> r;
#line 132 "pure2-autodiff.cpp2"
      double t {}; 
      t = x + y;

      r.construct(cpp2::move(t));
    return std::move(r.value()); }

#line 138 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::intermediate_no_init(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_no_init_ret{
          cpp2::impl::deferred_init<double> r;
#line 139 "pure2-autodiff.cpp2"
      cpp2::impl::deferred_init<double> t; 
      t.construct(x + y);

      r.construct(cpp2::move(t.value()));
    return std::move(r.value()); }

#line 145 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::while_loop(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> while_loop_ret{
          cpp2::impl::deferred_init<double> r;
#line 146 "pure2-autodiff.cpp2"
      int i {0}; 

      r.construct(x);
      for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
        r.value() = r.value() + y;
      }return std::move(r.value()); 
    }

#line 154 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::do_while_loop(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> do_while_loop_ret{
          cpp2::impl::deferred_init<double> r;
#line 155 "pure2-autodiff.cpp2"
      int i {0}; 

      r.construct(x);
      do {
        r.value() = r.value() + y;
      } while ( [&]{ 
      (i += 1) ; return true; }() && 
      cpp2::impl::cmp_less(i,2));return std::move(r.value()); 
    }

#line 165 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::for_loop(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> for_loop_ret{
          cpp2::impl::deferred_init<double> r;
#line 166 "pure2-autodiff.cpp2"
      std::vector<double> v {}; 

      CPP2_UFCS(push_back)(v, x);
      CPP2_UFCS(push_back)(v, y);

      r.construct(0.0);
      for ( 
      auto const& t : cpp2::move(v) ) 
      {
        r.value() = r.value() + t;
      }return std::move(r.value()); 
    }

#line 179 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::type_outer_use(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> type_outer_use_ret{
          cpp2::impl::deferred_init<double> r;
#line 180 "pure2-autodiff.cpp2"
      type_outer t {}; 
      t.a = x;

      r.construct(cpp2::move(t).a + y);
    return std::move(r.value()); }

#line 186 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test::type_outer_call(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> type_outer_call_ret{
          cpp2::impl::deferred_init<double> r;
#line 187 "pure2-autodiff.cpp2"
      type_outer t {}; 
      t.a = x;

      r.construct(CPP2_UFCS(add)(cpp2::move(t), y));
    return std::move(r.value()); }

    [[nodiscard]] auto ad_test::add_1_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_1_d_ret{
                                                                                                                                       double r {0.0};
                                                                                                                                       double r_d {0.0};r_d = x_d + y_d;
    r = x + y;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::add_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_2_d_ret{
                                                                                                                                       double r {0.0};
                                                                                                                                       double r_d {0.0};r_d = x_d + y_d + x_d;
    r = x + y + x;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::sub_1_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sub_1_d_ret{
                                                                                                                                       double r {0.0};
                                                                                                                                       double r_d {0.0};r_d = x_d - y_d;
    r = x - y;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::sub_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sub_2_d_ret{
                                                                                                                                       double r {0.0};
                                                                                                                                       double r_d {0.0};r_d = x_d - y_d - x_d;
    r = x - y - x;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::add_sub_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_sub_2_d_ret{
                                                                                                                                           double r {0.0};
                                                                                                                                           double r_d {0.0};r_d = x_d + y_d - x_d;
    r = x + y - x;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_1_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_1_d_ret{
                                                                                                                                       double r {0.0};
                                                                                                                                       double r_d {0.0};r_d = y * x_d + x * y_d;
    r = x * y;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_2_d_ret{
                                                                                                                                       double r {0.0};
                                                                                                                                       double r_d {0.0};
auto temp_1_d {y * x_d + x * y_d}; 

    auto temp_1 {x * y}; 
    r_d = x * cpp2::move(temp_1_d) + temp_1 * x_d;
    r = cpp2::move(temp_1) * x;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::div_1_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> div_1_d_ret{
                                                                                                                                       double r {0.0};
                                                                                                                                       double r_d {0.0};r_d = x_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x_d),y) + -x * y_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y_d),(y * y));
    r = x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::div_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> div_2_d_ret{
                                                                                                                                       double r {0.0};
                                                                                                                                       double r_d {0.0};
auto temp_1_d {x_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x_d),y) + -x * y_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y_d),(y * y))}; 

    auto temp_1 {x / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x),y)}; 
    r_d = cpp2::move(temp_1_d) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1_d)),y) + -temp_1 * y_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(y_d),(y * y));
    r = cpp2::move(temp_1) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1)),y);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_div_2_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_div_2_d_ret{
                                                                                                                                           double r {0.0};
                                                                                                                                           double r_d {0.0};
auto temp_1_d {y * x_d + x * y_d}; 

    auto temp_1 {x * y}; 
    r_d = cpp2::move(temp_1_d) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1_d)),x) + -temp_1 * x_d / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(x_d),(x * x));
    r = cpp2::move(temp_1) / CPP2_ASSERT_NOT_ZERO(CPP2_TYPEOF(cpp2::move(temp_1)),x);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::mul_add_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> mul_add_d_ret{
                                                                                                                                         double r {0.0};
                                                                                                                                         double r_d {0.0};
double temp_1_d {x_d + y_d}; 

    double temp_1 {x + y}; 
    r_d = temp_1 * x_d + x * cpp2::move(temp_1_d);
    r = x * cpp2::move(temp_1);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::add_mul_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> add_mul_d_ret{
                                                                                                                                         double r {0.0};
                                                                                                                                         double r_d {0.0};
double temp_1_d {y * x_d + x * y_d}; 

    double temp_1 {x * y}; 
    r_d = x_d + cpp2::move(temp_1_d);
    r = x + cpp2::move(temp_1);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::prefix_add_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> prefix_add_d_ret{
                                                                                                                                            double r {0.0};
                                                                                                                                            double r_d {0.0};
double temp_1_d {+x_d}; 

    double temp_1 {+x}; 
    r_d = cpp2::move(temp_1_d) + y_d;
    r = cpp2::move(temp_1) + y;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::prefix_sub_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> prefix_sub_d_ret{
                                                                                                                                            double r {0.0};
                                                                                                                                            double r_d {0.0};
double temp_1_d {-x_d}; 

    double temp_1 {-x}; 
    r_d = cpp2::move(temp_1_d) + y_d;
    r = cpp2::move(temp_1) + y;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::func_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_d_ret{
                                                                                                                                          double ret {0.0};
                                                                                                                                          double ret_d {0.0};ret_d = x_d + y_d;
    ret = x + y;
    return  { std::move(ret), std::move(ret_d) }; 
    }

    [[nodiscard]] auto ad_test::func_call_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_call_d_ret{
                                                                                                                                           double r {0.0};
                                                                                                                                           double r_d {0.0};
auto temp_1 {func_d(x, x_d, y, y_d)}; 

    double temp_2_d {temp_1.ret_d}; 

    double temp_2 {cpp2::move(temp_1).ret}; 
    r_d = temp_2 * x_d + x * cpp2::move(temp_2_d);
    r = x * cpp2::move(temp_2);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::func_outer_call_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> func_outer_call_d_ret{
                                                                                                                                                 double r {0.0};
                                                                                                                                                 double r_d {0.0};
auto temp_1 {func_outer_d(x, x_d, y, y_d)}; 

    double temp_2_d {temp_1.ret_d}; 

    double temp_2 {cpp2::move(temp_1).ret}; 
    r_d = temp_2 * x_d + x * cpp2::move(temp_2_d);
    r = x * cpp2::move(temp_2);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::sin_call_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> sin_call_d_ret{
                                                                                                                                          double r {0.0};
                                                                                                                                          double r_d {0.0};
double temp_1_d {x_d - y_d}; 

    double temp_1 {x - y}; 
    r_d = cos(temp_1) * cpp2::move(temp_1_d);
    r = sin(cpp2::move(temp_1));
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::if_branch_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> if_branch_d_ret{
                                                                                                                                           double r {0.0};
                                                                                                                                           double r_d {0.0};r_d = x_d;
    r = x;
    if (cpp2::impl::cmp_less(x,0.0)) {
    r_d = y_d;
    r = y;
    }
    else {
    }
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::if_else_branch_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> if_else_branch_d_ret{
                                                                                                                                                double r {0.0};
                                                                                                                                                double r_d {0.0};if (cpp2::impl::cmp_less(x,0.0)) {
    r_d = y_d;
    r = y;
    }
    else {
    r_d = x_d;
    r = x;
    }
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::direct_return_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> direct_return_d_ret{
                                                                                                                                   double r {};
                                                                                                                                   double r_d {};r_d = x_d + y_d;
    r = x + y;
    return  { std::move(r), std::move(r_d) }; }

    [[nodiscard]] auto ad_test::intermediate_var_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_var_d_ret{
                                                                                                                                                  double r {0.0};
                                                                                                                                                  double r_d {0.0};
double t_d {x_d + y_d}; 

    double t {x + y}; 
    r_d = cpp2::move(t_d);
    r = cpp2::move(t);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::intermediate_passive_var_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_passive_var_d_ret{
                                                                                                                                                          double r {0.0};
                                                                                                                                                          double r_d {0.0};
int i {}; 
    r_d = x_d + y_d;
    r = x + y;
    i = 2;
    static_cast<void>(cpp2::move(i));
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::intermediate_untyped_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_untyped_d_ret{
                                                                                                                                                      double r {0.0};
                                                                                                                                                      double r_d {0.0};
auto t_d {double()}; 

    auto t {0.0}; 
    t_d = x_d + y_d;
    t = x + y;
    r_d = cpp2::move(t_d);
    r = cpp2::move(t);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::intermediate_default_init_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_default_init_d_ret{
                                                                                                                                                           double r {0.0};
                                                                                                                                                           double r_d {0.0};
double t_d {}; 

    double t {}; 
    t_d = x_d + y_d;
    t = x + y;
    r_d = cpp2::move(t_d);
    r = cpp2::move(t);
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::intermediate_no_init_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> intermediate_no_init_d_ret{
                                                                                                                                                      double r {0.0};
                                                                                                                                                      double r_d {0.0};
cpp2::impl::deferred_init<double> t_d; 

    cpp2::impl::deferred_init<double> t; 
    t_d.construct(x_d + y_d);
    t.construct(x + y);
    r_d = cpp2::move(t_d.value());
    r = cpp2::move(t.value());
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::while_loop_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> while_loop_d_ret{
                                                                                                                                            double r {0.0};
                                                                                                                                            double r_d {0.0};
int i {0}; 
    r_d = x_d;
    r = x;
    for( ; cpp2::impl::cmp_less(i,2); (i += 1) ) {
    r_d = r_d + y_d;
    r = r + y;
    }
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::do_while_loop_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> do_while_loop_d_ret{
                                                                                                                                               double r {0.0};
                                                                                                                                               double r_d {0.0};
int i {0}; 
    r_d = x_d;
    r = x;
    do {
    r_d = r_d + y_d;
    r = r + y;
    }
     while ( [&]{ 
    (i += 1)
     ; return true; }() && 
    cpp2::impl::cmp_less(i,2)
    );
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::for_loop_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> for_loop_d_ret{
                                                                                                                                          double r {0.0};
                                                                                                                                          double r_d {0.0};
std::vector<double> v_d {}; 

    std::vector<double> v {}; 
    CPP2_UFCS(push_back)(v_d, x_d);
    CPP2_UFCS(push_back)(v, x);
    CPP2_UFCS(push_back)(v_d, y_d);
    CPP2_UFCS(push_back)(v, y);
    r_d = {  };
    r = 0.0;
{
auto t_d_iter{CPP2_UFCS(begin)(cpp2::move(v_d))};
    for ( auto const& t : cpp2::move(v) )  { do {
{
auto const& t_d{*cpp2::impl::assert_not_null(t_d_iter)};
    {
    r_d = r_d + t_d;
    r = r + t;
    }
}
    }
     while (false); (++t_d_iter); }
}
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::type_outer_use_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> type_outer_use_d_ret{
                                                                                                                                                double r {0.0};
                                                                                                                                                double r_d {0.0};
type_outer_d t_d {}; 

    type_outer t {}; 
    t_d.a_d = x_d;
    t.a = x;

    double temp_1_d {cpp2::move(t_d).a_d}; 

    double temp_1 {cpp2::move(t).a}; 
    r_d = cpp2::move(temp_1_d) + y_d;
    r = cpp2::move(temp_1) + y;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test::type_outer_call_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d) -> type_outer_call_d_ret{
                                                                                                                                                 double r {0.0};
                                                                                                                                                 double r_d {0.0};
type_outer_d t_d {}; 

    type_outer t {}; 
    t_d.a_d = x_d;
    t.a = x;

    auto temp_1 {CPP2_UFCS(add_d)(cpp2::move(t), cpp2::move(t_d), y, y_d)}; 
    r_d = temp_1.r_d;
    r = cpp2::move(temp_1).r;
    return  { std::move(r), std::move(r_d) }; 
    }

#line 196 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test_reverse::add_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> add_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 197 "pure2-autodiff.cpp2"
        r.construct(x + y);
    return std::move(r.value()); }

#line 200 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test_reverse::mul_1(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> mul_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 201 "pure2-autodiff.cpp2"
        r.construct(x * y);
    return std::move(r.value()); }

    [[nodiscard]] auto ad_test_reverse::add_1_b(cpp2::impl::in<double> x, double& x_b, cpp2::impl::in<double> y, double& y_b, double& r_b) -> add_1_b_ret{
                                                                                                                                          double r {0.0};r = x + y;
    x_b += r_b;
    y_b += r_b;
    return r; }

    [[nodiscard]] auto ad_test_reverse::mul_1_b(cpp2::impl::in<double> x, double& x_b, cpp2::impl::in<double> y, double& y_b, double& r_b) -> mul_1_b_ret{
                                                                                                                                          double r {0.0};r = x * y;
    x_b += y * r_b;
    y_b += x * r_b;
    return r; }

#line 204 "pure2-autodiff.cpp2"
}

#line 207 "pure2-autodiff.cpp2"
    [[nodiscard]] auto ad_test_twice::mul_1(cpp2::impl::in<double> x) -> mul_1_ret{
            cpp2::impl::deferred_init<double> r;
#line 208 "pure2-autodiff.cpp2"
        r.construct(x * x);
    return std::move(r.value()); }

    [[nodiscard]] auto ad_test_twice::mul_1_d(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d) -> mul_1_d_ret{
                                                                                                       double r {0.0};
                                                                                                       double r_d {0.0};r_d = x * x_d + x * x_d;
    r = x * x;
    return  { std::move(r), std::move(r_d) }; 
    }

    [[nodiscard]] auto ad_test_twice::mul_1_d2(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d2) -> mul_1_d2_ret{
                                                                                                          double r {0.0};
                                                                                                          double r_d2 {0.0};r_d2 = x * x_d2 + x * x_d2;
    r = x * x;
    return  { std::move(r), std::move(r_d2) }; 
    }

    [[nodiscard]] auto ad_test_twice::mul_1_d_d2(cpp2::impl::in<double> x, cpp2::impl::in<double> x_d2, cpp2::impl::in<double> x_d, cpp2::impl::in<double> x_d_d2) -> mul_1_d_d2_ret{
                                                                                                                                                                                                    double r {0.0};
                                                                                                                                                                                                    double r_d2 {0.0};
                                                                                                                                                                                                    double r_d {0.0};
                                                                                                                                                                                                    double r_d_d2 {0.0};
double temp_1_d2 {x_d * x_d2 + x * x_d_d2}; 

    double temp_1 {x * x_d}; 

    double temp_2_d2 {x_d * x_d2 + x * x_d_d2}; 

    double temp_2 {x * x_d}; 
    r_d_d2 = cpp2::move(temp_1_d2) + cpp2::move(temp_2_d2);
    r_d = cpp2::move(temp_1) + cpp2::move(temp_2);
    r_d2 = x * x_d2 + x * x_d2;
    r = x * x;
    return  { std::move(r), std::move(r_d2), std::move(r_d), std::move(r_d_d2) }; 
    }

#line 212 "pure2-autodiff.cpp2"
auto write_output(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, cpp2::impl::in<double> x_d, cpp2::impl::in<double> y, cpp2::impl::in<double> y_d, auto const& ret) -> void{
    std::cout << "diff(" + cpp2::to_string(func) + ") at (x = " + cpp2::to_string(x) + ", x_d = " + cpp2::to_string(x_d) + ", y = " + cpp2::to_string(y) + ", y_d = " + cpp2::to_string(y_d) + ") = (r = " + cpp2::to_string(ret.r) + ", r_d = " + cpp2::to_string(ret.r_d) + ")" << std::endl;
}

#line 216 "pure2-autodiff.cpp2"
auto write_output_reverse(cpp2::impl::in<std::string> func, cpp2::impl::in<double> x, double& x_b, cpp2::impl::in<double> y, double& y_b, cpp2::impl::in<double> r_b, auto const& ret) -> void{
    std::cout << "diff(" + cpp2::to_string(func) + ") at (x = " + cpp2::to_string(x) + ", y = " + cpp2::to_string(y) + ", r_b = " + cpp2::to_string(r_b) + ") = (r = " + cpp2::to_string(ret) + ", x_b = " + cpp2::to_string(x_b) + ", y_b = " + cpp2::to_string(y_b) + ")" << std::endl;
    x_b = 0.0;
    y_b = 0.0;
}

#line 222 "pure2-autodiff.cpp2"
auto main() -> int{

    double x {2.0}; 
    double x_d {1.0}; 
    double y {3.0}; 
    double y_d {2.0}; 

    write_output("x + y", x, x_d, y, y_d, ad_name::ad_test::add_1_d(x, x_d, y, y_d));
    write_output("x + y + x", x, x_d, y, y_d, ad_name::ad_test::add_2_d(x, x_d, y, y_d));
    write_output("x - y", x, x_d, y, y_d, ad_name::ad_test::sub_1_d(x, x_d, y, y_d));
    write_output("x - y - x", x, x_d, y, y_d, ad_name::ad_test::sub_2_d(x, x_d, y, y_d));
    write_output("x + y - x", x, x_d, y, y_d, ad_name::ad_test::add_sub_2_d(x, x_d, y, y_d));
    write_output("x * y", x, x_d, y, y_d, ad_name::ad_test::mul_1_d(x, x_d, y, y_d));
    write_output("x * y * x", x, x_d, y, y_d, ad_name::ad_test::mul_2_d(x, x_d, y, y_d));
    write_output("x / y", x, x_d, y, y_d, ad_name::ad_test::div_1_d(x, x_d, y, y_d));
    write_output("x / y / y", x, x_d, y, y_d, ad_name::ad_test::div_2_d(x, x_d, y, y_d));
    write_output("x * y / x", x, x_d, y, y_d, ad_name::ad_test::mul_div_2_d(x, x_d, y, y_d));
    write_output("x * (x + y)", x, x_d, y, y_d, ad_name::ad_test::mul_add_d(x, x_d, y, y_d));
    write_output("x + x * y", x, x_d, y, y_d, ad_name::ad_test::add_mul_d(x, x_d, y, y_d));
    write_output("+x + y)", x, x_d, y, y_d, ad_name::ad_test::prefix_add_d(x, x_d, y, y_d));
    write_output("-x + y)", x, x_d, y, y_d, ad_name::ad_test::prefix_sub_d(x, x_d, y, y_d));
    write_output("x * func(x, y)", x, x_d, y, y_d, ad_name::ad_test::func_call_d(x, x_d, y, y_d));
    write_output("x * func_outer(x, y)", x, x_d, y, y_d, ad_name::ad_test::func_outer_call_d(x, x_d, y, y_d));
    write_output("sin(x - y)", x, x_d, y, y_d, ad_name::ad_test::sin_call_d(x, x_d, y, y_d));
    write_output("if branch", x, x_d, y, y_d, ad_name::ad_test::if_branch_d(x, x_d, y, y_d));
    write_output("if else branch", x, x_d, y, y_d, ad_name::ad_test::if_else_branch_d(x, x_d, y, y_d));
    write_output("direct return", x, x_d, y, y_d, ad_name::ad_test::direct_return_d(x, x_d, y, y_d));
    write_output("intermediate var", x, x_d, y, y_d, ad_name::ad_test::intermediate_var_d(x, x_d, y, y_d));
    write_output("intermediate passive var", x, x_d, y, y_d, ad_name::ad_test::intermediate_passive_var_d(x, x_d, y, y_d));
    write_output("intermediate untyped", x, x_d, y, y_d, ad_name::ad_test::intermediate_untyped_d(x, x_d, y, y_d));
    write_output("intermediate default init", x, x_d, y, y_d, ad_name::ad_test::intermediate_default_init_d(x, x_d, y, y_d));
    write_output("intermediate no init", x, x_d, y, y_d, ad_name::ad_test::intermediate_no_init_d(x, x_d, y, y_d));
    write_output("while loop", x, x_d, y, y_d, ad_name::ad_test::while_loop_d(x, x_d, y, y_d));
    write_output("do while loop", x, x_d, y, y_d, ad_name::ad_test::do_while_loop_d(x, x_d, y, y_d));
    write_output("for loop", x, x_d, y, y_d, ad_name::ad_test::for_loop_d(x, x_d, y, y_d));
    write_output("tye_outer.a + y", x, x_d, y, y_d, ad_name::ad_test::type_outer_use_d(x, x_d, y, y_d));
    write_output("type_outer.add(y)", x, x_d, y, y_d, ad_name::ad_test::type_outer_call_d(x, x_d, y, cpp2::move(y_d)));

    double x_b {0.0}; 
    double y_b {0.0}; 
    double w_b {1.0}; 

    write_output_reverse("x + y", x, x_b, y, y_b, w_b, ad_name::ad_test_reverse::add_1_b(x, x_b, y, y_b, w_b));
    write_output_reverse("x * y", x, x_b, y, y_b, w_b, ad_name::ad_test_reverse::mul_1_b(x, x_b, cpp2::move(y), y_b, w_b));

    static_cast<void>(cpp2::move(x_b));
    static_cast<void>(cpp2::move(y_b));
    static_cast<void>(cpp2::move(w_b));

    auto r_twice {ad_test_twice::mul_1_d_d2(x, x_d, cpp2::move(x_d), 0.0)}; 
    std::cout << "2nd order diff of x*x at " + cpp2::to_string(cpp2::move(x)) + " = " + cpp2::to_string(cpp2::move(r_twice).r_d_d2) + "" << std::endl;
}

