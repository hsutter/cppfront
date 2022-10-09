// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 1 "pure2-int-main-arg.cpp2"

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-int-main-arg.cpp2"
[[nodiscard]] auto cpp2__main(std::span<std::string_view>&& args) -> int{
    for ( auto&& cpp2_range = std::move(args);  auto const& arg : cpp2_range ) std::cout << arg << '\n';
    return 0; 
}
CPP2_MAIN_INT_ARGS

