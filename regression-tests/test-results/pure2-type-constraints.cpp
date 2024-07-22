
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-type-constraints.cpp2"

#line 10 "pure2-type-constraints.cpp2"
class irregular;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-type-constraints.cpp2"

#line 2 "pure2-type-constraints.cpp2"
auto print(auto const& r) -> void
CPP2_REQUIRES (std::regular<CPP2_TYPEOF(r)>) ;

#line 6 "pure2-type-constraints.cpp2"
auto print([[maybe_unused]] auto const& unnamed_param_1) -> void;

#line 10 "pure2-type-constraints.cpp2"
class irregular {
      public: irregular() = default;
      public: irregular(irregular const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(irregular const&) -> void = delete;
};
#line 11 "pure2-type-constraints.cpp2"

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-type-constraints.cpp2"

#line 2 "pure2-type-constraints.cpp2"
auto print(auto const& r) -> void
requires (std::regular<CPP2_TYPEOF(r)>) {
#line 3 "pure2-type-constraints.cpp2"
    std::cout << "satisfies std::regular\n";
}

#line 6 "pure2-type-constraints.cpp2"
auto print([[maybe_unused]] auto const& unnamed_param_1) -> void{
    std::cout << "fallback\n";
}

#line 12 "pure2-type-constraints.cpp2"
auto main() -> int{
    print(42);
    print(irregular());

    std::regular auto ok {42}; 
    //err: _ is std::regular = irregular();
}

