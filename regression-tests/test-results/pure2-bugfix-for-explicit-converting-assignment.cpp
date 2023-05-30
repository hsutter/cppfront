
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-explicit-converting-assignment.cpp2"
class quantity;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-explicit-converting-assignment.cpp2"
class quantity {
  private: int value {}; 
  public: explicit quantity(cpp2::in<int> val);

  public: quantity(quantity const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(quantity const&) -> void = delete;
#line 4 "pure2-bugfix-for-explicit-converting-assignment.cpp2"
};

auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 3 "pure2-bugfix-for-explicit-converting-assignment.cpp2"
  quantity::quantity(cpp2::in<int> val)
                                      : value{ val }
#line 3 "pure2-bugfix-for-explicit-converting-assignment.cpp2"
  {}

#line 6 "pure2-bugfix-for-explicit-converting-assignment.cpp2"
auto main() -> int{
  auto x {quantity(0)}; 
  static_assert(!(std::is_assignable_v<decltype((x)),int>));
  (void) std::move(x);
}

