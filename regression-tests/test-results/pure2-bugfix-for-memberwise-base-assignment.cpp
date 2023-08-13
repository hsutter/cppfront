
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
  public: Base([[maybe_unused]] Base const& that);
  
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  public: auto operator=([[maybe_unused]] Base const& that) -> Base& ;
  
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  public: Base([[maybe_unused]] Base&& that) noexcept;
  
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  public: auto operator=([[maybe_unused]] Base&& that) noexcept -> Base& ;
  public: Base([[maybe_unused]] auto const& param2);
#line 4 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  public: auto operator=([[maybe_unused]] auto const& param2) -> Base& ;
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
  Base::Base ([[maybe_unused]] Base const& that) { std::cout << "(out this, that)\n"; }
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  auto Base::operator=([[maybe_unused]] Base const& that) -> Base&  { std::cout << "(out this, that)\n";
                                      return *this;
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
                                     }
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  Base::Base ([[maybe_unused]] Base&& that) noexcept { std::cout << "(out this, that)\n"; }
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  auto Base::operator=([[maybe_unused]] Base&& that) noexcept -> Base&  { std::cout << "(out this, that)\n";
                                      return *this;
#line 3 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
                                     }
  Base::Base([[maybe_unused]] auto const& param2) { std::cout << "(implicit out this, _)\n";  }
#line 4 "pure2-bugfix-for-memberwise-base-assignment.cpp2"
  auto Base::operator=([[maybe_unused]] auto const& param2) -> Base&  { std::cout << "(implicit out this, _)\n";
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

