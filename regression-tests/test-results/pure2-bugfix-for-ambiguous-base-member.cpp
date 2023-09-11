
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-ambiguous-base-member.cpp2"
class x;
  

class y;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-ambiguous-base-member.cpp2"
class x {
  private: int a {1}; 
  public: x() = default;
  public: x(x const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(x const&) -> void = delete;

#line 3 "pure2-bugfix-for-ambiguous-base-member.cpp2"
};

struct y_a_as_base { int a; };
#line 4 "pure2-bugfix-for-ambiguous-base-member.cpp2"
class y: private y_a_as_base, public x {
  public: using y_a_as_base::a;

  public: y() = default;
  public: y(y const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(y const&) -> void = delete;
#line 7 "pure2-bugfix-for-ambiguous-base-member.cpp2"
};
[[nodiscard]] auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 8 "pure2-bugfix-for-ambiguous-base-member.cpp2"
[[nodiscard]] auto main() -> int{
  (void) &y::a;
  return y().a; 
}

