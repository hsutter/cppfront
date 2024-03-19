
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-assert-shared-ptr-not-null.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-assert-shared-ptr-not-null.cpp2"

#line 2 "pure2-assert-shared-ptr-not-null.cpp2"
[[nodiscard]] auto fine() -> int;

#line 11 "pure2-assert-shared-ptr-not-null.cpp2"
[[nodiscard]] auto bad_shared_ptr_access() -> int;

#line 18 "pure2-assert-shared-ptr-not-null.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-assert-shared-ptr-not-null.cpp2"

#line 2 "pure2-assert-shared-ptr-not-null.cpp2"
[[nodiscard]] auto fine() -> int
{
    auto up {CPP2_UFCS_TEMPLATE(cpp2_new<int>)(cpp2::unique, 1)}; 
    auto sp {CPP2_UFCS_TEMPLATE(cpp2_new<int>)(cpp2::shared, 2)}; 
    std::optional<int> op {3}; 

    return *cpp2::impl::assert_not_null(cpp2::move(up)) + *cpp2::impl::assert_not_null(cpp2::move(sp)) + *cpp2::impl::assert_not_null(cpp2::move(op)); 
}

#line 11 "pure2-assert-shared-ptr-not-null.cpp2"
[[nodiscard]] auto bad_shared_ptr_access() -> int
{
    auto sp {std::make_shared<int>(1)}; 
    CPP2_UFCS(reset)(sp);
    return *cpp2::impl::assert_not_null(cpp2::move(sp)); 
}

#line 18 "pure2-assert-shared-ptr-not-null.cpp2"
[[nodiscard]] auto main() -> int
{
    std::set_terminate(std::abort);
    return fine() + bad_shared_ptr_access(); 
}

