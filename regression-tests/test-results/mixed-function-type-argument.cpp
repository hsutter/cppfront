

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-function-type-argument.cpp2"

#line 19 "mixed-function-type-argument.cpp2"
class t;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-function-type-argument.cpp2"
#include <cstddef>
auto main() -> int;
#line 16 "mixed-function-type-argument.cpp2"
#if defined(_MSC_VER) || defined(__GNUC__)
int inline constexpr _{ __builtin_bit_cast(int const, 0) };
#line 18 "mixed-function-type-argument.cpp2"
#endif
class t {
  public: int a; 
  public: t(auto&& a_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<int>&>) ;

public: auto operator=(auto&& a_) -> t& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<int>&>) ;

#line 21 "mixed-function-type-argument.cpp2"
};


//=== Cpp2 function definitions =================================================

#line 1 "mixed-function-type-argument.cpp2"

#line 2 "mixed-function-type-argument.cpp2"
auto main() -> int{
  static_cast<void>(alignof(int));
  static_cast<void>(sizeof(int));
  static_cast<void>(typeid(int));
  static_cast<void>(offsetof(t, a));
  static_cast<void>([]<typename T>([[maybe_unused]] T const& unnamed_param_1) -> auto { return static_cast<void>(sizeof(T::value));  }(std::true_type()));
  static_cast<void>([]<typename T>([[maybe_unused]] T const& unnamed_param_1) -> auto { return static_cast<void>(sizeof(typename T::value_type));  }(std::true_type()));
  static_cast<void>(alignof(int const));
  static_cast<void>(sizeof(int const));
  static_cast<void>(typeid(int const));
  static_cast<void>(alignof(int*));
  static_cast<void>(sizeof(int*));
  static_cast<void>(typeid(int*));
}

t::t(auto&& a_)
requires (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<int>&>) 
                                                           : a{ CPP2_FORWARD(a_) }{}

auto t::operator=(auto&& a_) -> t& 
requires (std::is_convertible_v<CPP2_TYPEOF(a_), std::add_const_t<int>&>) {
                                                           a = CPP2_FORWARD(a_);
                                                           return *this;}
