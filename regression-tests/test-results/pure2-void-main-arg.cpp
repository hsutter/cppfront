// ----- Cpp2 support -----
#define CPP2_USE_MODULES         Yes
#include "cpp2util.h"


#line 1 "pure2-void-main-arg.cpp2"

//=== Cpp2 definitions ==========================================================

#line 1 "pure2-void-main-arg.cpp2"
auto cpp2__main(std::span<std::string_view>&& args) -> void{
    for ( auto&& cpp2_range = std::move(args);  auto const& arg : cpp2_range ) std::cout << arg << '\n';
}
CPP2_MAIN_VOID_ARGS

