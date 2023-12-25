
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-template-parameter-lists.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-template-parameter-lists.cpp2"

#line 2 "pure2-template-parameter-lists.cpp2"
template<typename T, typename U> [[nodiscard]] auto f1(T const& t, U const& u) -> auto;
template<typename T, typename U> [[nodiscard]] auto f2(T const& t, U const& u) -> auto;
template<auto T, auto U> [[nodiscard]] auto f3() -> auto;
template<cpp2::i8 T, cpp2::i16 U> [[nodiscard]] auto f4() -> auto;

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-template-parameter-lists.cpp2"

#line 2 "pure2-template-parameter-lists.cpp2"
template<typename T, typename U> [[nodiscard]] auto f1(T const& t, U const& u) -> auto { return t + u; }
template<typename T, typename U> [[nodiscard]] auto f2(T const& t, U const& u) -> auto { return t + u; }
template<auto T, auto U> [[nodiscard]] auto f3() -> auto { return T + U; }
template<cpp2::i8 T, cpp2::i16 U> [[nodiscard]] auto f4() -> auto { return T + U; }

auto main() -> int{
    std::cout << "f1: " + cpp2::to_string(f1(1, 1)) + "\n";
    std::cout << "f2: " + cpp2::to_string(f2(2, 2)) + "\n";
    std::cout << "f3: " + cpp2::to_string(f3<3,3>()) + "\n";
    std::cout << "f4: " + cpp2::to_string(f4<4,4>()) + "\n";
}

