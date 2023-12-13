
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-discard-precedence.cpp2"
class quantity;
#line 2 "pure2-bugfix-for-discard-precedence.cpp2"
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-discard-precedence.cpp2"
class quantity {
#line 2 "pure2-bugfix-for-discard-precedence.cpp2"
  private: cpp2::i32 number; 
  public: explicit quantity(cpp2::in<cpp2::i32> x);
#line 3 "pure2-bugfix-for-discard-precedence.cpp2"
  public: auto operator=(cpp2::in<cpp2::i32> x) -> quantity& ;
  public: [[nodiscard]] auto operator+(quantity const& that) & -> quantity;
  public: quantity(quantity const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(quantity const&) -> void = delete;

#line 5 "pure2-bugfix-for-discard-precedence.cpp2"
};

auto main(int const argc_, char** argv_) -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-discard-precedence.cpp2"

#line 3 "pure2-bugfix-for-discard-precedence.cpp2"
  quantity::quantity(cpp2::in<cpp2::i32> x)
                                  : number{ x } {  }
#line 3 "pure2-bugfix-for-discard-precedence.cpp2"
  auto quantity::operator=(cpp2::in<cpp2::i32> x) -> quantity&  { 
                                  number = x;
                                  return *this; }
#line 4 "pure2-bugfix-for-discard-precedence.cpp2"
  [[nodiscard]] auto quantity::operator+(quantity const& that) & -> quantity { return quantity(number + that.number);  }

#line 7 "pure2-bugfix-for-discard-precedence.cpp2"
auto main(int const argc_, char** argv_) -> int{
  auto const args = cpp2::make_args(argc_, argv_); 
#line 8 "pure2-bugfix-for-discard-precedence.cpp2"
  quantity x {1729}; 
  static_cast<void>(x + std::move(x));// Not `(void) x + x`; would attempt to add a `void` to `x`.
  static_cast<void>(args);// Not `void(args)`; would attempt to declare `args` with `void` type.
}

