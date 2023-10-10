
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

template<typename T> auto f() -> void
CPP2_REQUIRES (std::regular<T>);
auto main() -> int;


//=== Cpp2 function definitions =================================================

template<typename T> auto f() -> void
requires (std::regular<T>) { g(T());  }
auto main() -> int                 {}

