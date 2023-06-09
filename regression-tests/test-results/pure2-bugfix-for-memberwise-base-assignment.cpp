
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
class Base;
  

#line 7 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
class Derived;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
class Base {
  public: explicit Base();
  public: Base(Base const& that);
  
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  public: auto operator=(Base const& that) -> Base& ;
  
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  public: Base(Base&& that) noexcept;
  
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  public: auto operator=(Base&& that) noexcept -> Base& ;
  public: Base(auto const& x);
#line 4 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  public: auto operator=(auto const& x) -> Base& ;
};

class Derived: public Base {

  public: explicit Derived();
  public: Derived(Derived const& that);
  public: auto operator=(Derived&& that) noexcept -> Derived& ;
};

auto main() -> int;


//=== Cpp2 function definitions =================================================


#line 2 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  Base::Base(){}
  Base::Base (Base const& that) { std::cout << "(out this, that)\n"; }
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  auto Base::operator=(Base const& that) -> Base&  { std::cout << "(out this, that)\n";
                                      return *this;
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
                                     }
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  Base::Base (Base&& that) noexcept { std::cout << "(out this, that)\n"; }
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  auto Base::operator=(Base&& that) noexcept -> Base&  { std::cout << "(out this, that)\n";
                                      return *this;
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
                                     }
  Base::Base(auto const& x) { std::cout << "(implicit out this, x)\n";  }
#line 4 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  auto Base::operator=(auto const& x) -> Base&  { std::cout << "(implicit out this, x)\n";
                                      return *this;
#line 4 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
   }

#line 9 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  Derived::Derived()
                            : Base{  }
#line 9 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  {}
  Derived::Derived(Derived const& that)
                                    : Base{ static_cast<Base const&>(that) }
#line 10 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
                                {}
  auto Derived::operator=(Derived&& that) noexcept -> Derived& {
                                         Base::operator= ( static_cast<Base&&>(that) );
                                         return *this;
#line 11 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  }

#line 14 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
auto main() -> int{
  auto d {Derived()}; 
  auto d2 {d}; 
  d2 = std::move(d);
}

