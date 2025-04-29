
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-late-comments.cpp2"

#line 7 "pure2-bugfix-for-late-comments.cpp2"
class crash_m0;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-late-comments.cpp2"

#line 2 "pure2-bugfix-for-late-comments.cpp2"
[[nodiscard]] auto main() -> int;

#line 7 "pure2-bugfix-for-late-comments.cpp2"
class crash_m0 {
  public: [[nodiscard]] auto operator-([[maybe_unused]] auto const& unnamed_param_2) const& -> int;
  public: crash_m0() = default;
  public: crash_m0(crash_m0 const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(crash_m0 const&) -> void = delete;


#line 11 "pure2-bugfix-for-late-comments.cpp2"
};


//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-late-comments.cpp2"

#line 2 "pure2-bugfix-for-late-comments.cpp2"
[[nodiscard]] auto main() -> int{
  auto x {crash_m0()}; 
  static_cast<void>(cpp2::move(x));
}

#line 8 "pure2-bugfix-for-late-comments.cpp2"
  [[nodiscard]] auto crash_m0::operator-([[maybe_unused]] auto const& unnamed_param_2) const& -> int { return 0;  }/* Comment starts here
And continues here
*/
