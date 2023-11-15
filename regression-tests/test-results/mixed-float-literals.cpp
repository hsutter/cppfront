

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-float-literals.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-float-literals.cpp2"
void literals_cpp1() {
  // integers
  std::cout << 123 << std::endl;
  std::cout << 123u << std::endl;
  std::cout << 123ul << std::endl;
  std::cout << 123ull << std::endl;
  std::cout << 123l << std::endl;
  std::cout << 123ll << std::endl;
  std::cout << 123'456ll << std::endl;
  std::cout << 123 << std::endl;
  std::cout << 123U << std::endl;
  std::cout << 123UL << std::endl;
  std::cout << 123ULL << std::endl;
  std::cout << 123L << std::endl;
  std::cout << 123LL << std::endl;
  std::cout << 123'456LL << std::endl;
  // float points
  std::cout << 123'456.0f << std::endl;
  std::cout << 123'456.f << std::endl;
  std::cout << 456.0 << std::endl;
  std::cout << 456. << std::endl;
  std::cout << 1.0e10 << std::endl;
  std::cout << 1.0e+10 << std::endl;
  std::cout << 1.0e-10 << std::endl;
  std::cout << 1.0e-10f << std::endl;
  std::cout << 1.e-10 << std::endl;
  std::cout << 1.e-10f << std::endl;
  std::cout << 1e-10 << std::endl;
  std::cout << 1e-10f << std::endl;
  std::cout << 1e-1'0 << std::endl;
  std::cout << 123'456.0F << std::endl;
  std::cout << 123'456.F << std::endl;
  std::cout << 456.0 << std::endl;
  std::cout << 456. << std::endl;
  std::cout << 1.0E10 << std::endl;
  std::cout << 1.0E+10 << std::endl;
  std::cout << 1.0E-10 << std::endl;
  std::cout << 1.0E-10F << std::endl;
  std::cout << 1.E-10 << std::endl;
  std::cout << 1.E-10F << std::endl;
  std::cout << 1E-10 << std::endl;
  std::cout << 1E-10F << std::endl;
  std::cout << 1E-1'0 << std::endl;
  // invalid
  // 456f
  // (void)1e-10.0f;
  // 1.0e-10.0;
  // 1.0e-10.0f;
  // 1e-10.0;
  // 1e-10.0f;
  // 1e - 10;
  // 1e - 10.0;
  // 1e - 10f;
  // 1e - 10.0f;
}

#line 57 "mixed-float-literals.cpp2"
auto literals_cpp2() -> void;

#line 114 "mixed-float-literals.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "mixed-float-literals.cpp2"

#line 57 "mixed-float-literals.cpp2"
auto literals_cpp2() -> void{
  // integers
  std::cout << 123 << std::endl;
  std::cout << 123u << std::endl;
  std::cout << 123ul << std::endl;
  std::cout << 123ull << std::endl;
  std::cout << 123l << std::endl;
  std::cout << 123ll << std::endl;
  std::cout << 123'456ll << std::endl;
  std::cout << 123 << std::endl;
  std::cout << 123U << std::endl;
  std::cout << 123UL << std::endl;
  std::cout << 123ULL << std::endl;
  std::cout << 123L << std::endl;
  std::cout << 123LL << std::endl;
  std::cout << 123'456LL << std::endl;
  // float points
  std::cout << 123'456.0f << std::endl;
  std::cout << 456.0 << std::endl;
  std::cout << 1.0e10 << std::endl;
  std::cout << 1.0e+10 << std::endl;
  std::cout << 1.0e-10 << std::endl;
  std::cout << 1.0e-10f << std::endl;
  std::cout << 1e-10 << std::endl;
  std::cout << 1e-10f << std::endl;
  std::cout << 1e-1'0 << std::endl;
  std::cout << 123'456.0F << std::endl;
  std::cout << 456.0 << std::endl;
  std::cout << 1.0E10 << std::endl;
  std::cout << 1.0E+10 << std::endl;
  std::cout << 1.0E-10 << std::endl;
  std::cout << 1.0E-10F << std::endl;
  std::cout << 1E-10 << std::endl;
  std::cout << 1E-10F << std::endl;
  std::cout << 1E-1'0 << std::endl;
  // invalid
  // 456f
  // (void)1e-10.0f;
  // 1.0e-10.0;
  // 1.0e-10.0f;
  // 1e-10.0;
  // 1e-10.0f;
  // 1e - 10;
  // 1e - 10.0;
  // 1e - 10f;
  // 1e - 10.0f;
  // 123'456.f;
  // 123'456.f;
  // 456.;
  // 1.e-10;
  // 1.e-10f;
  // 123'456.F;
  // 456.;
  // 1.E-10;
  // 1.E-10F;
}

[[nodiscard]] auto main() -> int{
  literals_cpp1();
  literals_cpp2();
}

