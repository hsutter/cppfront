
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-initialization-safety-with-else-if.cpp2"

#line 27 "pure2-initialization-safety-with-else-if.cpp2"
class ad_test;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-initialization-safety-with-else-if.cpp2"
auto main(int const argc_, char** argv_) -> int;

#line 27 "pure2-initialization-safety-with-else-if.cpp2"
class ad_test {
using intermediate_default_no_init_ret = double;

#line 28 "pure2-initialization-safety-with-else-if.cpp2"
    public: [[nodiscard]] static auto intermediate_default_no_init(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_default_no_init_ret;
    public: ad_test() = default;
    public: ad_test(ad_test const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(ad_test const&) -> void = delete;


#line 34 "pure2-initialization-safety-with-else-if.cpp2"
};

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
    [[nodiscard]] auto ad_test::intermediate_default_no_init(cpp2::impl::in<double> x, cpp2::impl::in<double> y) -> intermediate_default_no_init_ret{
            cpp2::impl::deferred_init<double> r;
#line 29 "pure2-initialization-safety-with-else-if.cpp2"
        cpp2::impl::deferred_init<double> t; 
        t.construct(x + y);

        r.construct(cpp2::move(t.value()));// OK, after t but it's a return value
    return std::move(r.value()); }

#line 36 "pure2-initialization-safety-with-else-if.cpp2"
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

