
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-discard-precedence.cpp2"
class quantity;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-discard-precedence.cpp2"
class quantity {
  private: cpp2::i32 number; 
  public: explicit quantity(cpp2::in<std::in_place_t> _, cpp2::in<cpp2::i32> x);
    

#line 7 "pure2-bugfix-for-discard-precedence.cpp2"
  public: [[nodiscard]] auto operator+=(quantity const& that) -> quantity&;
    
  public: quantity(quantity const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(quantity const&) -> void = delete;


#line 11 "pure2-bugfix-for-discard-precedence.cpp2"
};

auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 3 "pure2-bugfix-for-discard-precedence.cpp2"
  quantity::quantity(cpp2::in<std::in_place_t> _, cpp2::in<cpp2::i32> x)
    : number{ x }
#line 3 "pure2-bugfix-for-discard-precedence.cpp2"
  {

    static_cast<void>(_);
  }
  [[nodiscard]] auto quantity::operator+=(quantity const& that) -> quantity&{
    static_cast<void>(number += that.number);
    return (*this); 
  }

#line 13 "pure2-bugfix-for-discard-precedence.cpp2"
auto main() -> int{
  quantity x {std::in_place, 1729}; 
  static_cast<void>(x += std::move(x));
}

