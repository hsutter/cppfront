
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-better-ufcs-error-messages.cpp2"
extern std::vector<int> vi;
auto main() -> int;
  

#line 9 "pure2-bugfix-for-better-ufcs-error-messages.cpp2"
extern cpp2::i32 i0;
extern cpp2::i32 i1;
extern cpp2::i32 i2;
extern cpp2::i32 i3;
extern cpp2::i32 i4;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-better-ufcs-error-messages.cpp2"
std::vector<int> vi {}; 
auto main() -> int{
  CPP2_UFCS(push_back, vi, "oops");
  CPP2_UFCS_0(push_back, vi);
  CPP2_UFCS_TEMPLATE(push_back, (<0>), vi, "oops");
  CPP2_UFCS_TEMPLATE_0(push_back, (<0>), vi);
  CPP2_UFCS_TEMPLATE(push_back, (<0,0>), vi, 0, 0);
}
cpp2::i32 i0 {CPP2_UFCS_NONLOCAL(push_back, vi, "oops")}; 
cpp2::i32 i1 {CPP2_UFCS_0_NONLOCAL(push_back, vi)}; 
cpp2::i32 i2 {CPP2_UFCS_TEMPLATE_NONLOCAL(push_back, (<0>), vi, "oops")}; 
cpp2::i32 i3 {CPP2_UFCS_TEMPLATE_0_NONLOCAL(push_back, (<0>), vi)}; 
cpp2::i32 i4 {CPP2_UFCS_TEMPLATE_NONLOCAL(push_back, (<0,0>), vi, 0, 0)}; 

