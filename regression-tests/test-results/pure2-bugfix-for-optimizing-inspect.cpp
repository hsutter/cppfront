
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-optimizing-inspect.cpp2"
auto main() -> int;
  

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-optimizing-inspect.cpp2"
auto main() -> int{
  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = x;
      // Condition is `false_type` for `int`, alternative not instantiated.
      if constexpr (requires { cpp2::is<std::string>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::string>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::string>(__expr)), std::true_type>) { return CPP2_UFCS(substr, x, 0);  } else { if (cpp2::is<std::string>(__expr)) { return CPP2_UFCS(substr, x, 0);  } } } }
      return true;
    }(), "");
  }(1);

  {
    auto pred {[]<typename T>(T const& y) -> std::true_type{
      std::terminate();
      return {  }; 
    }}; 
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = 1;
      // Condition is `true_type` for `int`, statement unconditionally executed.
      if constexpr (requires { cpp2::is(__expr, (std::move(pred))); }) { if constexpr (!std::is_same_v<decltype(cpp2::is(__expr, (std::move(pred)))), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is(__expr, (std::move(pred)))), std::true_type>) { return true;  } else { if (cpp2::is(__expr, (std::move(pred)))) { return true;  } } } }
      return false;
    }(), "");
  }

  (void) [](auto const& x) -> void{
    auto pred {[]<typename T>(T const& y) -> bool
requires (std::is_same_v<T,long>)
#line 23 "pure2-bugfix-for-optimizing-inspect.cpp2"
    {
      std::terminate();
      return true; 
    }}; 
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = x;
      // Condition is non-viable for `int`, alternative not instantiated.
      if constexpr (requires { cpp2::is(__expr, (std::move(pred))); }) { if constexpr (!std::is_same_v<decltype(cpp2::is(__expr, (std::move(pred)))), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is(__expr, (std::move(pred)))), std::true_type>) { return CPP2_UFCS(substr, x, 0);  } else { if (cpp2::is(__expr, (std::move(pred)))) { return CPP2_UFCS(substr, x, 0);  } } } }
      return true;
    }(), "");
  }(1);

  // Exercise all `is` overloads.

  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = x;
      if constexpr (requires { cpp2::is<std::vector>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::vector>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::vector>(__expr)), std::true_type>) { return CPP2_UFCS(substr, x, 0); } else { if (cpp2::is<std::vector>(__expr)) { return CPP2_UFCS(substr, x, 0); } } } }
      if constexpr (requires { cpp2::is<std::array>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::array>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::array>(__expr)), std::true_type>) { return CPP2_UFCS(substr, x, 0); } else { if (cpp2::is<std::array>(__expr)) { return CPP2_UFCS(substr, x, 0); } } } }
      if constexpr (requires { cpp2::is<std::string>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::string>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::string>(__expr)), std::true_type>) { return CPP2_UFCS(substr, x, 0); } else { if (cpp2::is<std::string>(__expr)) { return CPP2_UFCS(substr, x, 0); } } } }
      if constexpr (requires { cpp2::is<std::exception>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::exception>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::exception>(__expr)), std::true_type>) { return CPP2_UFCS(substr, x, 0); } else { if (cpp2::is<std::exception>(__expr)) { return CPP2_UFCS(substr, x, 0); } } } }
      if constexpr (requires { cpp2::is<cpp2::empty>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<cpp2::empty>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<cpp2::empty>(__expr)), std::true_type>) { return CPP2_UFCS(substr, x, 0); } else { if (cpp2::is<cpp2::empty>(__expr)) { return CPP2_UFCS(substr, x, 0); } } } }
      if constexpr (requires { cpp2::is(__expr, (std::ranges::empty)); }) { if constexpr (!std::is_same_v<decltype(cpp2::is(__expr, (std::ranges::empty))), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is(__expr, (std::ranges::empty))), std::true_type>) { return CPP2_UFCS(substr, x, 0);  } else { if (cpp2::is(__expr, (std::ranges::empty))) { return CPP2_UFCS(substr, x, 0);  } } } }
      if constexpr (requires { cpp2::is(__expr, ""); }) { if constexpr (!std::is_same_v<decltype(cpp2::is(__expr, "")), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is(__expr, "")), std::true_type>) { return CPP2_UFCS(substr, x, 0); } else { if (cpp2::is(__expr, "")) { return CPP2_UFCS(substr, x, 0); } } } }
      return true;
    }(), "");
  }(1);
  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = &x;
      if constexpr (requires { cpp2::is<std::exception>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::exception>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::exception>(__expr)), std::true_type>) { return CPP2_UFCS(substr, x, 0);  } else { if (cpp2::is<std::exception>(__expr)) { return CPP2_UFCS(substr, x, 0);  } } } }
      return true;
    }(), "");
  }(1);

  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = x;
      if constexpr (requires { cpp2::is<std::vector>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::vector>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::vector>(__expr)), std::true_type>) { return true;  } else { if (cpp2::is<std::vector>(__expr)) { return true;  } } } }
      return false;
    }(), "");
  }(std::vector{1});

  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = x;
      if constexpr (requires { cpp2::is<std::array>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::array>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::array>(__expr)), std::true_type>) { return true;  } else { if (cpp2::is<std::array>(__expr)) { return true;  } } } }
      return false;
    }(), "");
  }(std::array{1});

  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = x;
      if constexpr (requires { cpp2::is<int>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<int>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<int>(__expr)), std::true_type>) { return true;  } else { if (cpp2::is<int>(__expr)) { return true;  } } } }
      return false;
    }(), "");
  }(1);

  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = x;
      // FIXME
      // Using `std::ranges::subrange<std::add_pointer_t<i32>>::view_interface` fails.
      // The alternative is elided due to the `is` being ambiguous.
      // Like in P2392, the cases of the built-in `is` should be a chain of conditions.
      // Using overloads to implement that is tedious and error-prone.
      if constexpr (requires { cpp2::is<std::ranges::view_interface<std::ranges::subrange<std::add_pointer_t<cpp2::i32>>>>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::ranges::view_interface<std::ranges::subrange<std::add_pointer_t<cpp2::i32>>>>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::ranges::view_interface<std::ranges::subrange<std::add_pointer_t<cpp2::i32>>>>(__expr)), std::true_type>) { return true;  } else { if (cpp2::is<std::ranges::view_interface<std::ranges::subrange<std::add_pointer_t<cpp2::i32>>>>(__expr)) { return true;  } } } }
      return false;
    }(), "");
  }(std::ranges::subrange<std::add_pointer_t<cpp2::i32>>{});

  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = x;
      if constexpr (requires { cpp2::is<std::exception>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::exception>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::exception>(__expr)), std::true_type>) { return true;  } else { if (cpp2::is<std::exception>(__expr)) { return true;  } } } }
      return false;
    }(), "");
  }(std::bad_exception{});

  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = &x;
      if constexpr (requires { cpp2::is<std::exception>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<std::exception>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<std::exception>(__expr)), std::true_type>) { return true;  } else { if (cpp2::is<std::exception>(__expr)) { return true;  } } } }
      return false;
    }(), "");
  }(std::bad_exception{});

  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = x;
      if constexpr (requires { cpp2::is<cpp2::empty>(__expr); }) { if constexpr (!std::is_same_v<decltype(cpp2::is<cpp2::empty>(__expr)), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is<cpp2::empty>(__expr)), std::true_type>) { return true;  } else { if (cpp2::is<cpp2::empty>(__expr)) { return true;  } } } }
      return false;
    }(), "");
  }(std::optional<cpp2::i32>{});

  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = x;
      if constexpr (requires { cpp2::is(__expr, (std::ranges::empty)); }) { if constexpr (!std::is_same_v<decltype(cpp2::is(__expr, (std::ranges::empty))), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is(__expr, (std::ranges::empty))), std::true_type>) { return true;  } else { if (cpp2::is(__expr, (std::ranges::empty))) { return true;  } } } }
      return false;
    }(), "");
  }(std::vector<cpp2::i32>{});

  (void) [](auto const& x) -> void{
    cpp2::Testing.expects([&] () -> bool { auto&& __expr = x;
      if constexpr (requires { cpp2::is(__expr, (1)); }) { if constexpr (!std::is_same_v<decltype(cpp2::is(__expr, (1))), std::false_type>) { if constexpr (std::is_same_v<decltype(cpp2::is(__expr, (1))), std::true_type>) { return true;  } else { if (cpp2::is(__expr, (1))) { return true;  } } } }
      return false;
    }(), "");
  }(1);
}

