
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-requires-clause-in-forward-declaration.cpp2"
class element;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-requires-clause-in-forward-declaration.cpp2"
class element {
  private: std::string name; 
  public: explicit element(auto&& n)
CPP2_REQUIRES (cpp2::is<CPP2_TYPEOF(n), std::string>())
#line 3 "pure2-bugfix-for-requires-clause-in-forward-declaration.cpp2"
  ;
#line 3 "pure2-bugfix-for-requires-clause-in-forward-declaration.cpp2"
  public: auto operator=(auto&& n) -> element& 
CPP2_REQUIRES (cpp2::is<CPP2_TYPEOF(n), std::string>())
#line 3 "pure2-bugfix-for-requires-clause-in-forward-declaration.cpp2"
  ;

  public: element(element const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(element const&) -> void = delete;
#line 4 "pure2-bugfix-for-requires-clause-in-forward-declaration.cpp2"
};
auto main() -> int;


//=== Cpp2 function definitions =================================================


#line 3 "pure2-bugfix-for-requires-clause-in-forward-declaration.cpp2"
  element::element(auto&& n)
requires (cpp2::is<CPP2_TYPEOF(n), std::string>())
                                                    : name{ CPP2_FORWARD(n) }
#line 3 "pure2-bugfix-for-requires-clause-in-forward-declaration.cpp2"
  {}
#line 3 "pure2-bugfix-for-requires-clause-in-forward-declaration.cpp2"
  auto element::operator=(auto&& n) -> element& 
requires (cpp2::is<CPP2_TYPEOF(n), std::string>())
#line 3 "pure2-bugfix-for-requires-clause-in-forward-declaration.cpp2"
  {
                                                    name = CPP2_FORWARD(n);
                                                    return *this;
#line 3 "pure2-bugfix-for-requires-clause-in-forward-declaration.cpp2"
  }

auto main() -> int{}

