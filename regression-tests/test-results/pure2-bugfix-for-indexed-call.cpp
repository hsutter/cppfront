
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-indexed-call.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-indexed-call.cpp2"
auto f([[maybe_unused]] cpp2::impl::in<cpp2::i32> unnamed_param_1) -> void;
#line 2 "pure2-bugfix-for-indexed-call.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-indexed-call.cpp2"
auto f([[maybe_unused]] cpp2::impl::in<cpp2::i32> unnamed_param_1) -> void{}
#line 2 "pure2-bugfix-for-indexed-call.cpp2"
auto main() -> int{
  std::array array_of_functions {f, f}; 
  auto index {0}; 
  cpp2::i32 arguments {0}; 
  CPP2_ASSERT_IN_BOUNDS(array_of_functions, index)(arguments);
  static_cast<void>(cpp2::move(array_of_functions));
  static_cast<void>(cpp2::move(index));
  static_cast<void>(cpp2::move(arguments));
}

