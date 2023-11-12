
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 3 "pure2-bugfix-for-assign-expression-list.cpp2"
class my_vec;
  

//=== Cpp2 type definitions and function declarations ===========================

using vec = std::vector<int>;

class my_vec {
  private: vec v {}; 
  public: explicit my_vec([[maybe_unused]] cpp2::in<std::integral_constant<int,0>> param2);
  
#line 5 "pure2-bugfix-for-assign-expression-list.cpp2"
  public: auto operator=([[maybe_unused]] cpp2::in<std::integral_constant<int,0>> param2) -> my_vec& ;
  public: explicit my_vec([[maybe_unused]] cpp2::in<std::integral_constant<int,1>> param2);
  
#line 6 "pure2-bugfix-for-assign-expression-list.cpp2"
  public: auto operator=([[maybe_unused]] cpp2::in<std::integral_constant<int,1>> param2) -> my_vec& ;
  public: explicit my_vec([[maybe_unused]] cpp2::in<std::integral_constant<int,2>> param2);
#line 7 "pure2-bugfix-for-assign-expression-list.cpp2"
  public: auto operator=([[maybe_unused]] cpp2::in<std::integral_constant<int,2>> param2) -> my_vec& ;

  public: my_vec(my_vec const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(my_vec const&) -> void = delete;
#line 8 "pure2-bugfix-for-assign-expression-list.cpp2"
};

auto main() -> int;


//=== Cpp2 function definitions =================================================


#line 5 "pure2-bugfix-for-assign-expression-list.cpp2"
  my_vec::my_vec([[maybe_unused]] cpp2::in<std::integral_constant<int,0>> param2)
                                                             : v{  }
#line 5 "pure2-bugfix-for-assign-expression-list.cpp2"
   {  }
#line 5 "pure2-bugfix-for-assign-expression-list.cpp2"
  auto my_vec::operator=([[maybe_unused]] cpp2::in<std::integral_constant<int,0>> param2) -> my_vec&  { 
                                                             v = {  };
                                                             return *this;
#line 5 "pure2-bugfix-for-assign-expression-list.cpp2"
   }
  my_vec::my_vec([[maybe_unused]] cpp2::in<std::integral_constant<int,1>> param2)
                                                             : v{ 1 }
#line 6 "pure2-bugfix-for-assign-expression-list.cpp2"
   {  }
#line 6 "pure2-bugfix-for-assign-expression-list.cpp2"
  auto my_vec::operator=([[maybe_unused]] cpp2::in<std::integral_constant<int,1>> param2) -> my_vec&  { 
                                                             v = { 1 };
                                                             return *this;
#line 6 "pure2-bugfix-for-assign-expression-list.cpp2"
   }
  my_vec::my_vec([[maybe_unused]] cpp2::in<std::integral_constant<int,2>> param2)
                                                             : v{ 2, 3 }
#line 7 "pure2-bugfix-for-assign-expression-list.cpp2"
   {  }
#line 7 "pure2-bugfix-for-assign-expression-list.cpp2"
  auto my_vec::operator=([[maybe_unused]] cpp2::in<std::integral_constant<int,2>> param2) -> my_vec&  { 
                                                             v = { 2, 3 };
                                                             return *this;
#line 7 "pure2-bugfix-for-assign-expression-list.cpp2"
   }

#line 10 "pure2-bugfix-for-assign-expression-list.cpp2"
auto main() -> int{
  vec v {0}; 
  v                   = {  };
  cpp2::Default.expects(v == vec{}, "");
  v                   = { 1 };
  cpp2::Default.expects(v == vec{1}, "");
  v                   = { 2, 3 };
  cpp2::Default.expects(std::move(v) == vec{2, 3}, "");
}

