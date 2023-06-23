
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-multi-token-type-prvalue.cpp2"
auto main(int const argc_, char const* const* const argv_) -> int;


//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-multi-token-type-prvalue.cpp2"
auto main(int const argc_, char const* const* const argv_) -> int{
                 auto args = cpp2::make_args(argc_, argv_); 
#line 1 "pure2-bugfix-for-multi-token-type-prvalue.cpp2"
(void) std::type_identity_t<int*>{&args.argc}; }

