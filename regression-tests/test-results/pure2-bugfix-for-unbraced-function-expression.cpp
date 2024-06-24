
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-unbraced-function-expression.cpp2"
class t;
#line 2 "pure2-bugfix-for-unbraced-function-expression.cpp2"
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-unbraced-function-expression.cpp2"
class t {
#line 2 "pure2-bugfix-for-unbraced-function-expression.cpp2"
  public: auto operator[]([[maybe_unused]] auto const& unnamed_param_2) const& -> void;
  public: t() = default;
  public: t(t const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(t const&) -> void = delete;

#line 3 "pure2-bugfix-for-unbraced-function-expression.cpp2"
};

[[nodiscard]] auto main() -> int;

#line 14 "pure2-bugfix-for-unbraced-function-expression.cpp2"
auto inline constexpr x{ cpp2::i32{0} };
extern cpp2::i32 y;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-unbraced-function-expression.cpp2"

#line 2 "pure2-bugfix-for-unbraced-function-expression.cpp2"
  auto t::operator[]([[maybe_unused]] auto const& unnamed_param_2) const& -> void{}

#line 5 "pure2-bugfix-for-unbraced-function-expression.cpp2"
[[nodiscard]] auto main() -> int{
{
auto const& x{t()};
#line 6 "pure2-bugfix-for-unbraced-function-expression.cpp2"
  {CPP2_ASSERT_IN_BOUNDS(x, []() mutable -> auto { return 0;  }); }
}
{
auto const& x{t()};
#line 7 "pure2-bugfix-for-unbraced-function-expression.cpp2"
  {CPP2_ASSERT_IN_BOUNDS(x, []() mutable -> auto { return 0;  }); }
}

#line 9 "pure2-bugfix-for-unbraced-function-expression.cpp2"
  if (cpp2::cpp2_default.is_active() && !(!((cpp2::impl::is<int>([]() mutable -> auto { return 0; })))) ) { cpp2::cpp2_default.report_violation(""); }

  return cpp2::i32{0}; 
}

#line 15 "pure2-bugfix-for-unbraced-function-expression.cpp2"
cpp2::i32 y {0}; 

