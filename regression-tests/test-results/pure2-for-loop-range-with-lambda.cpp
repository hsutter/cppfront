

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

[[nodiscard]] auto first(auto&& f, [[maybe_unused]] auto&& ...param2) -> auto&&;

auto main() -> int;
   

//=== Cpp2 function definitions =================================================

[[nodiscard]] auto first(auto&& f, [[maybe_unused]] auto&& ...param2) -> auto&& { return CPP2_FORWARD(f);  }

auto main() -> int{
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
}

