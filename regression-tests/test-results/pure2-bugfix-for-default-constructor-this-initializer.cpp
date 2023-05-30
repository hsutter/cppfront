
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
class base;

#line 6 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
class derived;

#line 10 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
class derived2;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
class base {
         public: cpp2::i32 x {-1}; 
  public: explicit base();
  public: base(cpp2::in<cpp2::i32> y);
#line 4 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
  public: auto operator=(cpp2::in<cpp2::i32> y) -> base& ;

  public: base(base const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(base const&) -> void = delete;
#line 5 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
};

struct derived_y_as_base { cpp2::i32 y; };
#line 6 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
class derived: public derived_y_as_base, public base {
public: explicit derived();

  public: derived(derived const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(derived const&) -> void = delete;


#line 9 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
};

struct derived2_y_as_base { cpp2::i32 y; };
#line 10 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
class derived2: public derived2_y_as_base, public base {

#line 13 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
  public: cpp2::i32 z {3}; 
};
auto main() -> int;
  

//=== Cpp2 function definitions =================================================


#line 3 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
  base::base(){}
  base::base(cpp2::in<cpp2::i32> y)
                                           : x{ y }
#line 4 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
   {  }
#line 4 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
  auto base::operator=(cpp2::in<cpp2::i32> y) -> base&  { 
                                           x = y;
                                           return *this;
#line 4 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
   }

  derived::derived()
                          : derived_y_as_base{ 2 }
                          , base{ 42 }{}

#line 15 "pure2-bugfix-for-default-constructor-this-initializer.cpp2"
auto main() -> int{
  cpp2::Default.expects(derived().y==2, "");
  cpp2::Default.expects(derived().x==42, "");
  (void) derived2{1, 2, 3};
}

