
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
class identity;
#line 2 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
  

#line 5 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
class t;
  

#line 9 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
class u;

namespace ns {

}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
class identity {
#line 2 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
  public: [[nodiscard]] constexpr auto operator()(auto&& x) const& -> auto&&;
};

class t {
  public: [[nodiscard]] constexpr auto f() const& -> int;
};

class u {};

namespace ns {
[[nodiscard]] constexpr auto f([[maybe_unused]] auto const& unnamed_param_1) -> int;
} // namespace ns

// v: @struct type = {
//   f :== :(_) 0; // Pending on #706.
//   g: (i) i.f();
// }

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-ufcs-name-lookup.cpp2"

#line 2 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
  [[nodiscard]] constexpr auto identity::operator()(auto&& x) const& -> auto&& { return CPP2_FORWARD(x);  }

#line 6 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
  [[nodiscard]] constexpr auto t::f() const& -> int { return 0;  }

#line 11 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
namespace ns {
[[nodiscard]] constexpr auto f([[maybe_unused]] auto const& unnamed_param_1) -> int { return 1;  }
}

#line 20 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
auto main() -> int{
  {
    auto f {t().f()}; 
    cpp2::Default.expects(std::move(f) == 0, "");
  }
  {
    auto f {t().f()}; 
    cpp2::Default.expects(std::move(f) == 0, "");
  }
{
auto const& f = t().f();
#line 29 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
  cpp2::Default.expects(f == 0, "");
}
{
auto const& f = t().f();
#line 30 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
  cpp2::Default.expects(f == 0, "");
}
#line 31 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
  {
    auto constexpr f = t().f();
    static_assert(f == 0);
  }
  {
    auto constexpr f = t().f();
    static_assert(f == 0);
  }
  {
    auto f {[](auto const& f) -> auto{
      cpp2::Default.expects(CPP2_UFCS(f)(t()) == 0, "");
      return CPP2_UFCS(f)(u()); 
    }(identity())}; 
    static_cast<void>(std::move(f));
  }
  { // Rejected by MSVC.
    // f := :<f: _> (copy _: std::integral_constant<identity, f>) -> _ = {
    //   assert(t().f() == 0);
    //   return u().f();
    // }(:std::integral_constant<identity, (:identity = ())> = ());
    // _ = f;
  }
  {
    auto f {[]() -> void{
{
cpp2::in<identity> f = identity();
#line 55 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
      cpp2::Default.expects(CPP2_UFCS(f)(t()) == 0, "");
}
{
cpp2::in<identity> f = identity();
#line 56 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
      static_cast<void>(CPP2_UFCS(f)(u()));
}
#line 57 "pure2-bugfix-for-ufcs-name-lookup.cpp2"
    }}; 
    static_cast<void>(std::move(f));
  }
  {
    auto f {[]() -> void{
      using ns::f;
      static_assert(CPP2_UFCS(f)(t()) == 0);
      static_assert(CPP2_UFCS(f)(u()) == 1);
    }}; 
    static_cast<void>(std::move(f));
  }
  {
    auto f {[]() -> void{
      static_assert(t().f() == 0);
      auto g {[]<typename T>([[maybe_unused]] T const& unnamed_param_1) -> std::void_t<decltype(T().f())>{}}; 
      static_assert(!(std::is_invocable_v<decltype(std::move(g)),u>));
      using ns::f;
    }}; 
    static_cast<void>(std::move(f));
  }
  {
    auto f {[]() -> void{
      using ns::f;
      static_cast<void>([]() -> void{
        static_assert(CPP2_UFCS(f)(t()) == 0);
        static_assert(CPP2_UFCS(f)(u()) == 1);
      });
      {
        static_assert(CPP2_UFCS(f)(t()) == 0);
        static_assert(CPP2_UFCS(f)(u()) == 1);
      }
    }}; 
    static_cast<void>(std::move(f));
  }
  {
    auto f {[]() -> void{
      static_cast<void>([]() -> void{
        static_assert(t().f() == 0);
        auto g {[]<typename T>([[maybe_unused]] T const& unnamed_param_1) -> std::void_t<decltype(T().f())>{}}; 
        static_assert(!(std::is_invocable_v<decltype(std::move(g)),u>));
      });
      {
        static_assert(t().f() == 0);
        auto g {[]<typename T>([[maybe_unused]] T const& unnamed_param_1) -> std::void_t<decltype(T().f())>{}}; 
        static_assert(!(std::is_invocable_v<decltype(std::move(g)),u>));
      }
      using ns::f;
    }}; 
    static_cast<void>(std::move(f));
  }
}

