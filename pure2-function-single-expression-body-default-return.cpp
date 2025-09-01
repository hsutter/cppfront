

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "regression-tests/pure2-function-single-expression-body-default-return.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "regression-tests/pure2-function-single-expression-body-default-return.cpp2"

#line 2 "regression-tests/pure2-function-single-expression-body-default-return.cpp2"
[[nodiscard]] auto f() -> decltype(auto);

auto g2() -> void;
[[nodiscard]] auto g() -> decltype(auto);

[[nodiscard]] auto h() -> decltype(auto);

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "regression-tests/pure2-function-single-expression-body-default-return.cpp2"

#line 2 "regression-tests/pure2-function-single-expression-body-default-return.cpp2"
[[nodiscard]] auto f() -> decltype(auto) { return std::cout << "hi";  }

#line 4 "regression-tests/pure2-function-single-expression-body-default-return.cpp2"
auto g2() -> void{}
#line 5 "regression-tests/pure2-function-single-expression-body-default-return.cpp2"
[[nodiscard]] auto g() -> decltype(auto) { return g2();  }

#line 7 "regression-tests/pure2-function-single-expression-body-default-return.cpp2"
[[nodiscard]] auto h() -> decltype(auto) { return cpp2::impl::cmp_greater(2,0);  }

#line 9 "regression-tests/pure2-function-single-expression-body-default-return.cpp2"
auto main() -> int{
    f() << " ho";
    static_assert(std::is_same_v<decltype(g()),void>);
    if (h()) {std::cout << " hum"; }
}

