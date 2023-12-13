
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

[[nodiscard]] auto first(auto&& f, [[maybe_unused]] auto&& ...param2) -> auto&&;

auto main(int const argc_, char** argv_) -> int;
   

//=== Cpp2 function definitions =================================================

[[nodiscard]] auto first(auto&& f, [[maybe_unused]] auto&& ...param2) -> auto&& { return CPP2_FORWARD(f);  }

auto main(int const argc_, char** argv_) -> int{
   auto const args = cpp2::make_args(argc_, argv_); 
#line 4 "pure2-for-loop-range-with-lambda.cpp2"
   std::array const ints {1, 2, 3, 4, 5}; 
   // OK
   for ( auto const& i : CPP2_UFCS_0(first, ints) ) {
      std::cout << i;
   }

   // OK
   for (                 auto const& i : CPP2_UFCS(first, ints, 1) ) {
      std::cout << i;
   }

   // Used to cause Error
   for (                      auto const& i : CPP2_UFCS(first, ints, [](auto const& x) -> auto { return x; }) ) {
      std::cout << i;
   }

   // OK
   auto temp {CPP2_UFCS(first, ints, [](auto const& x) -> auto { return x;  })}; 
   for ( auto const& i : temp ) {
      std::cout << i;
   }

   for ( auto const& i : [_0 = args]() -> auto { return _0;  }() ) static_cast<void>(i); 
   for ( auto const& j : [](auto const& x) -> auto { return x;  }(args) ) static_cast<void>(j); 
   for ( auto const& k : [](auto const& x) -> auto { return x;  }(args) )  { do static_cast<void>(k);  while (false); static_cast<void>([_0 = args]() -> auto { return _0;  }()); }
   for ( auto const& l : [](auto const& x) -> auto { return x;  }(args) )  { do static_cast<void>(l);  while (false); static_cast<void>([](auto const& x) -> auto { return x;  }(args)); }
}

