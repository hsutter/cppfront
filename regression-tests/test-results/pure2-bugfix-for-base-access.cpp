
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-base-access.cpp2"
class x;
class y;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-base-access.cpp2"
class x {
      public: x() = default;
      public: x(x const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(x const&) -> void = delete;

#line 1 "pure2-bugfix-for-base-access.cpp2"
};

struct y_a_as_base { int a; };
struct y_b_as_base { int b; };
struct y_c_as_base { int c; };
#line 2 "pure2-bugfix-for-base-access.cpp2"
class y: private y_a_as_base, private y_b_as_base, private y_c_as_base, public x {
  private: using y_a_as_base::a;
  public: using y_b_as_base::b;
  private: using y_c_as_base::c;
  
  public: y() = default;
  public: y(y const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(y const&) -> void = delete;

#line 7 "pure2-bugfix-for-base-access.cpp2"
};
[[nodiscard]] auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 8 "pure2-bugfix-for-base-access.cpp2"
[[nodiscard]] auto main() -> int{
  static_assert(!(std::invocable<decltype([](auto const& v) -> std::void_t<decltype(v.a)>{}),y>));
  static_assert(!(std::invocable<decltype([](auto const& v) -> std::void_t<decltype(v.c)>{}),y>));
  static_assert(!(std::invocable<decltype([]<typename T>(T const& v) -> std::void_t<decltype(&T::a)>{}),y>));
  (void) &y::b;
  return y().b; 
}

