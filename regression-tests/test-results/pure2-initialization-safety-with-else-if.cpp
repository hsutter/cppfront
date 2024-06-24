
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-initialization-safety-with-else-if.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-initialization-safety-with-else-if.cpp2"
auto main(int const argc_, char** argv_) -> int;

#line 28 "pure2-initialization-safety-with-else-if.cpp2"
auto ok() -> void;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-initialization-safety-with-else-if.cpp2"
auto main(int const argc_, char** argv_) -> int{
    auto const args = cpp2::make_args(argc_, argv_); 
#line 2 "pure2-initialization-safety-with-else-if.cpp2"
    cpp2::impl::deferred_init<int*> p; 

    auto a {1}; 
    auto b {2}; 
    auto c {3}; 
    auto d {4}; 

    if (CPP2_UFCS(size)(args) == 3) {
        p.construct(&a);
    }else {if (true) {
        if (CPP2_UFCS(size)(args) == 2) {
            p.construct(&c);
        }else {if (cpp2::impl::cmp_greater(cpp2::move(b),0)) {
                p.construct(&a);
        }
        else {
            p.construct(&d);
        }}
    }else {
        p.construct(&c);
    }}

    std::cout << *cpp2::impl::assert_not_null(cpp2::move(p.value())) << std::endl;
}

#line 28 "pure2-initialization-safety-with-else-if.cpp2"
auto ok() -> void{
    cpp2::impl::deferred_init<int> i; 
    if (true) {
        i.construct(42);
        while( true ) { // OK: in-branch loop is after initialization
            i.value() = 42;
        }
    }
    else {
        i.construct(42);
    }
    i.value() = 42;
}

