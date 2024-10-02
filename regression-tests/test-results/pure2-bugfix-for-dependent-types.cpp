
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-dependent-types.cpp2"

#line 49 "pure2-bugfix-for-dependent-types.cpp2"
template<typename T> class t;
  

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-dependent-types.cpp2"
template<typename T> using identity = T;
#line 2 "pure2-bugfix-for-dependent-types.cpp2"

template<typename T> auto f([[maybe_unused]] typename T::value_type& unnamed_param_1) -> void;
template<typename T> auto f([[maybe_unused]] typename T::value_type&& unnamed_param_1) -> void;
template<typename T, T::value_type V> [[nodiscard]] auto f(cpp2::impl::in<typename T::value_type> x) -> T::value_type;

#line 49 "pure2-bugfix-for-dependent-types.cpp2"
template<typename T> class t {
struct u_x_as_base { typename T::value_type x; };

#line 50 "pure2-bugfix-for-dependent-types.cpp2"
  public: class u: public u_x_as_base, public T::type {

#line 53 "pure2-bugfix-for-dependent-types.cpp2"
    // Test that there's no `typename` in the member initializer list.
    public: u(u const& that);
  };
  private: T::value_type x {0}; 
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-dependent-types.cpp2"

#line 3 "pure2-bugfix-for-dependent-types.cpp2"
template<typename T> auto f([[maybe_unused]] typename T::value_type& unnamed_param_1) -> void{}
#line 4 "pure2-bugfix-for-dependent-types.cpp2"
template<typename T> auto f([[maybe_unused]] typename T::value_type&& unnamed_param_1) -> void{}
#line 5 "pure2-bugfix-for-dependent-types.cpp2"
template<typename T, T::value_type V> [[nodiscard]] auto f(cpp2::impl::in<typename T::value_type> x) -> T::value_type{
  if (cpp2::cpp2_default.is_active() && !(cpp2::impl::is<typename T::value_type>(x)) ) { cpp2::cpp2_default.report_violation(""); }
  cpp2::impl::deferred_init<typename T::value_type> y; 
  y.construct(x);
  using z = T::value_type;
  return { typename T::value_type{x} }; 

  // Dependent *template-id*s.
  static_cast<void>(typename identity<T>::value_type{});// First identifier.
  static_cast<void>(typename std::optional<T>::value_type{});// Non-first identifier.
  static_cast<void>(typename std::array<cpp2::i32,T::value>::value_type{});
  static_cast<void>(typename std::array<cpp2::i32,T::value + T::value>::value_type{});

  // Emitted `template`.
  using ptr = T*;    // Also test lookup through type aliases.
  using nptr = cpp2::i32*;
  static_cast<void>(typename std::pointer_traits<ptr>::template rebind<ptr>{});// Type-only context.
  static_cast<void>(std::pointer_traits<nptr>::rebind<nptr>{});// Non-dependent.
  static_cast<void>(std::pointer_traits<nptr>::rebind<ptr>{});// Dependent on the nested template.
  static_cast<void>(typename std::pointer_traits<ptr>::template rebind<nptr>{});// Dependent on the outer template.
  // _ = :identity<typename std::pointer_traits<ptr>::rebind<ptr>> = (); // Non type-only context. Blocked on #727.

  // Aliases.
  using w = T;
  static_cast<void>(typename w::value_type{x});
  using v = w;
  static_cast<void>(typename v::value_type{x});
  using a = T::type;
  static_cast<void>(typename a::value_type{x});

  {
    // Test that there's no prefixed `typename` to....
    static_cast<void>(std::integral_constant<cpp2::i32,T::value>());// `T::value`.
    static_cast<void>(std::type_identity_t<T>{});// `std::type_identity_t<T>`.

    // Test that non-dependent names aren't emitted with `typename`.
    using a = std::integral_constant<cpp2::i32,0>;
    using b = a;
    using c = b;
    static_cast<void>(b::value_type{x});
    static_cast<void>(c::value_type{x});
  }
}

#line 54 "pure2-bugfix-for-dependent-types.cpp2"
    template <typename T> t<T>::u::u(u const& that)
                                    : u_x_as_base{ that.x }
                                    , T::type{ static_cast<typename T::type const&>(that) }{}

#line 59 "pure2-bugfix-for-dependent-types.cpp2"
auto main() -> int{
  using zero = std::integral_constant<cpp2::i32,0>;
  static_cast<void>(f<zero,0>(0));

  static_cast<void>(::t<zero>{});

  // Emitted `template` (noop, taken care of by the UFCS macro).
  static_cast<void>([](auto&& f) -> decltype(auto) { return static_cast<void>(CPP2_UFCS_TEMPLATE(operator()<cpp2::i32>)(cpp2::move(f)));  }([]<typename T>() -> void{}));

  // Nesting is not relevant to lookup.
  static_cast<void>([]<typename T>() -> void{static_cast<void>(typename T::value_type{}); });
  static_cast<void>([]() -> void{static_cast<void>([]<typename T>() -> void{static_cast<void>(typename T::value_type{}); }); });
  static_cast<void>([]() -> void{static_cast<void>([]() -> void{static_cast<void>([]<typename T>() -> void{static_cast<void>(typename T::value_type{}); }); }); });
  static_cast<void>([]() -> void{static_cast<void>([]() -> void{static_cast<void>([]() -> void{static_cast<void>([]<typename T>() -> void{static_cast<void>(typename T::value_type{}); }); }); }); });
  static_cast<void>([]() -> void{static_cast<void>([]() -> void{static_cast<void>([]<typename T>() -> void{static_cast<void>([]() -> void{static_cast<void>(typename T::value_type{}); }); }); }); });
  static_cast<void>([]() -> void{static_cast<void>([]<typename T>() -> void{static_cast<void>([]() -> void{static_cast<void>([]() -> void{static_cast<void>(typename T::value_type{}); }); }); }); });
  static_cast<void>([]<typename T>() -> void{static_cast<void>([]() -> void{static_cast<void>([]() -> void{static_cast<void>([]() -> void{static_cast<void>(typename T::value_type{}); }); }); }); });
  static_cast<void>([]<typename T>() -> void{static_cast<void>([]() -> void{static_cast<void>([]() -> void{static_cast<void>([]([[maybe_unused]] cpp2::impl::in<typename T::value_type> unnamed_param_1) -> void{}); }); }); });
  static_cast<void>([]<typename T>() -> void{static_cast<void>([]() -> void{static_cast<void>([]([[maybe_unused]] cpp2::impl::in<typename T::value_type> unnamed_param_1) -> void{static_cast<void>([]() -> void{}); }); }); });
  static_cast<void>([]<typename T>() -> void{static_cast<void>([]([[maybe_unused]] cpp2::impl::in<typename T::value_type> unnamed_param_1) -> void{static_cast<void>([]() -> void{static_cast<void>([]() -> void{}); }); }); });
  static_cast<void>([]<typename T>([[maybe_unused]] cpp2::impl::in<typename T::value_type> unnamed_param_1) -> void{static_cast<void>([]() -> void{static_cast<void>([]() -> void{static_cast<void>([]() -> void{}); }); }); });

  // Lookup.
  {
    using alias = std::integral_constant<cpp2::i32,0>;
    static_cast<void>(alias::value_type{0});// Non-dependent.
  }
  static_cast<void>([]<typename T>([[maybe_unused]] T const& unnamed_param_1) -> void{
    using alias = std::integral_constant<T,0>;
    static_cast<void>(typename alias::value_type{0});// Dependent.
    {
      using alias = std::integral_constant<cpp2::i32,0>;
      static_cast<void>(alias::value_type{0});// Non-dependent.
    }
  }(0));

  static_cast<void>([](auto const& r) -> std::type_identity_t<decltype(*cpp2::impl::assert_not_null(begin(r)))> { return CPP2_ASSERT_IN_BOUNDS_LITERAL(r, 0);  }(std::vector<int>(1)));
}

