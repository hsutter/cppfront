
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-template-specialization.cpp2"
template<typename T> class t;
#line 2 "pure2-template-specialization.cpp2"
  

#line 18 "pure2-template-specialization.cpp2"
template<typename ...T> class u;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-template-specialization.cpp2"
template<typename T> class t {
#line 2 "pure2-template-specialization.cpp2"
  public: cpp2::i32 a {1}; 
};
template<typename T> requires( std::is_void_v<T> )
  class t<T> {public: cpp2::i32 b {2}; 
};
template<> class t<cpp2::i64> {
  public: cpp2::i32 c {3}; 
};
template<> class t<cpp2::i8*> {
  public: [[nodiscard]] static auto f() -> decltype(auto);
  public: static const int v;
};
template<typename T> class t<T*> {
  public: static const int v;
  public: [[nodiscard]] static auto f() -> decltype(auto);
};
template<typename ...T> class u {
  public: cpp2::i32 a {1}; 
};
template<> class u<> {
  public: cpp2::i32 a {2}; 
};
template<> class u<cpp2::i16> {
      public: u() = default;
      public: u(u const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(u const&) -> void = delete;
};
#line 25 "pure2-template-specialization.cpp2"
template<typename T> extern cpp2::i32 const v;

#line 28 "pure2-template-specialization.cpp2"
template<> std::optional<cpp2::i32> inline constexpr v<cpp2::i16>{ 4 };
template<> std::optional<cpp2::i8> inline constexpr v<cpp2::i8>{ 5 };
template<typename T> std::optional<int> inline constexpr v<T*>{ 6 };
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-template-specialization.cpp2"

#line 11 "pure2-template-specialization.cpp2"
  [[nodiscard]] auto t<cpp2::i8*>::f() -> decltype(auto) { return 17;  }
  inline CPP2_CONSTEXPR int t<cpp2::i8*>::v{ 29 };

#line 15 "pure2-template-specialization.cpp2"
  template <typename T> inline CPP2_CONSTEXPR int t<T*>::v{ 17 };
  template <typename T> [[nodiscard]] auto t<T*>::f() -> decltype(auto) { return 29;  }

#line 25 "pure2-template-specialization.cpp2"
template<typename T> cpp2::i32 const v {1}; 
template<> cpp2::i32 const v<void> {2}; 
template<> cpp2::i32 const v<cpp2::i64> {3}; 

#line 31 "pure2-template-specialization.cpp2"
auto main() -> int{
  if (cpp2::cpp2_default.is_active() && !(t<cpp2::i32>().a == 1) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(t<void>().b == 2) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(t<cpp2::i64>().c == 3) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(t<cpp2::i8*>::f() == 17) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(t<cpp2::i8*>::v == 29) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(t<cpp2::i16*>::v == 17) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(t<cpp2::i16*>::f() == 29) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(u<cpp2::i32>().a == 1) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(u<>().a == 1) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(v<cpp2::i32> == 1) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(v<void> == 2) ) { cpp2::cpp2_default.report_violation(""); }
  if (cpp2::cpp2_default.is_active() && !(v<cpp2::i64> == 3) ) { cpp2::cpp2_default.report_violation(""); }
  static_assert(v<cpp2::i16> == 4);
  static_assert(v<cpp2::i8> == 5);
  static_assert(v<int*> == 6);
}

