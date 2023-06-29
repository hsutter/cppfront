
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
}

