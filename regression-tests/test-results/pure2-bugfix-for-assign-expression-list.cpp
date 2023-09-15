
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-assign-expression-list.cpp2"

#line 3 "pure2-bugfix-for-assign-expression-list.cpp2"
class my_vec;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-assign-expression-list.cpp2"
using vec = std::vector<int>;
#line 2 "pure2-bugfix-for-assign-expression-list.cpp2"

class my_vec {
  private: vec v {}; 
  public: explicit my_vec([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,0>> unnamed_param_2);
#line 5 "pure2-bugfix-for-assign-expression-list.cpp2"
  public: auto operator=([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,0>> unnamed_param_2) -> my_vec& ;
  public: explicit my_vec([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,1>> unnamed_param_2);
#line 6 "pure2-bugfix-for-assign-expression-list.cpp2"
  public: auto operator=([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,1>> unnamed_param_2) -> my_vec& ;
  public: explicit my_vec([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,2>> unnamed_param_2);
#line 7 "pure2-bugfix-for-assign-expression-list.cpp2"
  public: auto operator=([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,2>> unnamed_param_2) -> my_vec& ;
  public: my_vec(my_vec const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(my_vec const&) -> void = delete;

#line 8 "pure2-bugfix-for-assign-expression-list.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-assign-expression-list.cpp2"

#line 5 "pure2-bugfix-for-assign-expression-list.cpp2"
  my_vec::my_vec([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,0>> unnamed_param_2)
                                                             : v{  } {  }
#line 5 "pure2-bugfix-for-assign-expression-list.cpp2"
  auto my_vec::operator=([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,0>> unnamed_param_2) -> my_vec&  { 
                                                             v = {  };
                                                             return *this;  }
#line 6 "pure2-bugfix-for-assign-expression-list.cpp2"
  my_vec::my_vec([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,1>> unnamed_param_2)
                                                             : v{ 1 } {  }
#line 6 "pure2-bugfix-for-assign-expression-list.cpp2"
  auto my_vec::operator=([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,1>> unnamed_param_2) -> my_vec&  { 
                                                             v = { 1 };
                                                             return *this;  }
#line 7 "pure2-bugfix-for-assign-expression-list.cpp2"
  my_vec::my_vec([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,2>> unnamed_param_2)
                                                             : v{ 2, 3 } {  }
#line 7 "pure2-bugfix-for-assign-expression-list.cpp2"
  auto my_vec::operator=([[maybe_unused]] cpp2::impl::in<std::integral_constant<int,2>> unnamed_param_2) -> my_vec&  { 
                                                             v = { 2, 3 };
                                                             return *this;  }

#line 10 "pure2-bugfix-for-assign-expression-list.cpp2"
auto main() -> int{
  vec v {0}; 
  v                   = {  };
  if (cpp2::cpp2_default.is_active() && !(v == vec{}) ) { cpp2::cpp2_default.report_violation(""); }
  v                   = { 1 };
  if (cpp2::cpp2_default.is_active() && !(v == vec{1}) ) { cpp2::cpp2_default.report_violation(""); }
  v                   = { 2, 3 };
  if (cpp2::cpp2_default.is_active() && !(cpp2::move(v) == vec{2, 3}) ) { cpp2::cpp2_default.report_violation(""); }
}

