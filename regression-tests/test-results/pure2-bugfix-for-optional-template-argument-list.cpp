
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

extern std::plus<> const plus;
[[nodiscard]] auto main() -> int;


//=== Cpp2 function definitions =================================================

std::plus<> const plus {}; 
[[nodiscard]] auto main() -> int { return std::plus<>()(0, 0); }

