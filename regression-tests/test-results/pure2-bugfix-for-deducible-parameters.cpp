
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
template<typename T> auto init(cpp2::out<std::integral_constant<cpp2::i32,T::value>> x) -> void;
template<typename T> auto init(cpp2::out<std::integral_constant<cpp2::i32,T::value>> x, [[maybe_unused]] T const& unnamed_param_2) -> void;
template<typename T> [[nodiscard]] auto id(cpp2::in<std::integral_constant<cpp2::i32,T::value>> x) -> auto&&;
template<typename T> auto id(cpp2::in<std::integral_constant<cpp2::i32,T::value>> x, T const& y) -> void;

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
template<typename T> auto init(cpp2::out<std::integral_constant<cpp2::i32,T::value>> x) -> void{x.construct(); }
template<typename T> auto init(cpp2::out<std::integral_constant<cpp2::i32,T::value>> x, [[maybe_unused]] T const& unnamed_param_2) -> void{x.construct(); }
template<typename T> [[nodiscard]] auto id(cpp2::in<std::integral_constant<cpp2::i32,T::value>> x) -> auto&& { return x;  }
template<typename T> auto id(cpp2::in<std::integral_constant<cpp2::i32,T::value>> x, T const& y) -> void{if (cpp2::Default.has_handler() && !(&x == &y) ) { cpp2::Default.report_violation(""); }}

auto main() -> int{
  using zero = std::integral_constant<cpp2::i32,0>;

  cpp2::deferred_init<zero> z; 
  init<zero>(cpp2::out(&z));
  if (cpp2::Default.has_handler() && !(&id<zero>(z.value()) == &z.value()) ) { cpp2::Default.report_violation(""); }

  // Deducible parameters.
  static_cast<void>(v{  0});
  []<typename T>([[maybe_unused]] std::vector<T> const& unnamed_param_1) mutable -> void{}(std::vector<cpp2::i32>{});
  []<typename T>([[maybe_unused]] std::vector<std::vector<T>> const& unnamed_param_1) mutable -> void{}(std::vector<std::vector<cpp2::i32>>{});
  // _ = :<T, U> (x: std::pair<T, typename U::value_type>, y: U) = {}(:std::pair = (0, 0), z); // Blocked on #727.
  []<typename T, typename U>([[maybe_unused]] std::array<T,U::value> const& unnamed_param_1, [[maybe_unused]] U const& unnamed_param_2) mutable -> void{}(std::array<cpp2::i32,0>{}, z.value());
  init(cpp2::out(&z.value()), z.value());
  id(z.value(), std::move(z.value()));
{
auto f = []<typename T>([[maybe_unused]] std::vector<std::type_identity_t<T>> const& unnamed_param_1) mutable -> void{};

  // Test that these are emitted unwrapped in case they are deducible.

#line 25 "pure2-bugfix-for-deducible-parameters.cpp2"
    static_assert(!(std::is_invocable_v<decltype(f),std::vector<cpp2::i32>>), "`T` is non-deducible.");
}
{
auto f = []<typename T>([[maybe_unused]] std::vector<std::vector<T>> const& unnamed_param_1) mutable -> void{};

#line 27 "pure2-bugfix-for-deducible-parameters.cpp2"
    static_assert(std::is_invocable_v<decltype(std::move(f)),std::vector<std::vector<cpp2::i32>>>, "`T` is deducible.");
}
#line 28 "pure2-bugfix-for-deducible-parameters.cpp2"
}

#line 31 "pure2-bugfix-for-deducible-parameters.cpp2"
  template <typename T> v<T>::v([[maybe_unused]] T const& unnamed_param_2){}
#line 31 "pure2-bugfix-for-deducible-parameters.cpp2"
  template <typename T> auto v<T>::operator=([[maybe_unused]] T const& unnamed_param_2) -> v& {
                                  return *this; }

