
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-deducible-parameters.cpp2"

#line 30 "pure2-bugfix-for-deducible-parameters.cpp2"
template<typename T> class v;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-deducible-parameters.cpp2"
// Dependent, non-deducible parameters are wrapped like non-dependent parameters.
#line 2 "pure2-bugfix-for-deducible-parameters.cpp2"
template<typename T> auto init(cpp2::impl::out<std::integral_constant<cpp2::i32,T::value>> x) -> void;
template<typename T> auto init(cpp2::impl::out<std::integral_constant<cpp2::i32,T::value>> x, [[maybe_unused]] T const& unnamed_param_2) -> void;
template<typename T> [[nodiscard]] auto id(std::integral_constant<cpp2::i32,T::value> const& x) -> decltype(auto);
template<typename T> auto id(cpp2::impl::in<std::integral_constant<cpp2::i32,T::value>> x, T const& y) -> void;

auto main() -> int;

#line 30 "pure2-bugfix-for-deducible-parameters.cpp2"
template<typename T> class v {
  public: explicit v([[maybe_unused]] T const& unnamed_param_2);
#line 31 "pure2-bugfix-for-deducible-parameters.cpp2"
  public: auto operator=([[maybe_unused]] T const& unnamed_param_2) -> v& ;
  public: v(v const&) = delete; /* No 'that' constructor, suppress copy */
  public: auto operator=(v const&) -> void = delete;

#line 32 "pure2-bugfix-for-deducible-parameters.cpp2"
};


//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-deducible-parameters.cpp2"

#line 2 "pure2-bugfix-for-deducible-parameters.cpp2"
template<typename T> auto init(cpp2::impl::out<std::integral_constant<cpp2::i32,T::value>> x) -> void{x.construct(); }
#line 3 "pure2-bugfix-for-deducible-parameters.cpp2"
template<typename T> auto init(cpp2::impl::out<std::integral_constant<cpp2::i32,T::value>> x, [[maybe_unused]] T const& unnamed_param_2) -> void{x.construct(); }
#line 4 "pure2-bugfix-for-deducible-parameters.cpp2"
template<typename T> [[nodiscard]] auto id(std::integral_constant<cpp2::i32,T::value> const& x) -> decltype(auto) { return x;  }
#line 5 "pure2-bugfix-for-deducible-parameters.cpp2"
template<typename T> auto id(cpp2::impl::in<std::integral_constant<cpp2::i32,T::value>> x, T const& y) -> void{if (cpp2::cpp2_default.is_active() && !(&x == &y) ) { cpp2::cpp2_default.report_violation(""); }}

#line 7 "pure2-bugfix-for-deducible-parameters.cpp2"
auto main() -> int{
  using zero = std::integral_constant<cpp2::i32,0>;

  cpp2::impl::deferred_init<zero> z; 
  init<zero>(cpp2::impl::out(&z));
  if (cpp2::cpp2_default.is_active() && !(&id<zero>(z.value()) == &z.value()) ) { cpp2::cpp2_default.report_violation(""); }

  // Deducible parameters.
  static_cast<void>(v{  0});
  []<typename T>([[maybe_unused]] std::vector<T> const& unnamed_param_1) -> void{}(std::vector<cpp2::i32>{});
  []<typename T>([[maybe_unused]] std::vector<std::vector<T>> const& unnamed_param_1) -> void{}(std::vector<std::vector<cpp2::i32>>{});
  // _ = :<T, U> (x: std::pair<T, typename U::value_type>, y: U) = {}(:std::pair = (0, 0), z); // Blocked on #727.
  []<typename T, typename U>([[maybe_unused]] std::array<T,U::value> const& unnamed_param_1, [[maybe_unused]] U const& unnamed_param_2) -> void{}(std::array<cpp2::i32,0>{}, z.value());
  init(cpp2::impl::out(&z.value()), z.value());
  id(z.value(), cpp2::move(z.value()));
{
auto f{[]<typename T>([[maybe_unused]] std::vector<std::type_identity_t<T>> const& unnamed_param_1) -> void{}};

  // Test that these are emitted unwrapped in case they are deducible.

#line 25 "pure2-bugfix-for-deducible-parameters.cpp2"
    static_assert(!(std::is_invocable_v<decltype(cpp2::move(f)),std::vector<cpp2::i32>>), "`T` is non-deducible.");
}
{
auto f{[]<typename T>([[maybe_unused]] std::vector<std::vector<T>> const& unnamed_param_1) -> void{}};

#line 27 "pure2-bugfix-for-deducible-parameters.cpp2"
    static_assert(std::is_invocable_v<decltype(cpp2::move(f)),std::vector<std::vector<cpp2::i32>>>, "`T` is deducible.");
}
#line 28 "pure2-bugfix-for-deducible-parameters.cpp2"
}

#line 31 "pure2-bugfix-for-deducible-parameters.cpp2"
  template <typename T> v<T>::v([[maybe_unused]] T const& unnamed_param_2){}
#line 31 "pure2-bugfix-for-deducible-parameters.cpp2"
  template <typename T> auto v<T>::operator=([[maybe_unused]] T const& unnamed_param_2) -> v& {
                                  return *this; }

