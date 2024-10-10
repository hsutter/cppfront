
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-template-template-parameter.cpp2"
template<template <typename UnnamedTypeParam1_1, auto UnnamedTypeParam2_2> class T> class t;
#line 2 "pure2-bugfix-for-template-template-parameter.cpp2"

template<typename T, auto V> class u;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-template-template-parameter.cpp2"
template<template <typename UnnamedTypeParam1_1, auto UnnamedTypeParam2_2> class T> class t {};
#line 2 "pure2-bugfix-for-template-template-parameter.cpp2"

template<typename T, auto V> class u {};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-template-template-parameter.cpp2"

#line 5 "pure2-bugfix-for-template-template-parameter.cpp2"
auto main() -> int{static_cast<void>(t<u>{}); }

