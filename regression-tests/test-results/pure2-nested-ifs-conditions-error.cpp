
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-nested-ifs-conditions-error.cpp2"
auto main(int const argc_, char const* const* const argv_) -> int;


//=== Cpp2 function definitions =================================================

#line 1 "pure2-nested-ifs-conditions-error.cpp2"
auto main(int const argc_, char const* const* const argv_) -> int
{
    auto args = cpp2::make_args(argc_, argv_); 
#line 3 "pure2-nested-ifs-conditions-error.cpp2"
    auto a {1}; 
    auto b {2}; 
    auto c {3}; 
    auto d {4}; 

    {
        cpp2::deferred_init<int*> p; 

        // no initialization in selection_node
        if (cpp2::cmp_greater(args.argc,20)) {
            c = 20;
        } else if (cpp2::cmp_greater(args.argc,10)) {
            c = 10;
        }else {
            if (args.argc % 2) {
                b = 2;
            }else {
                b = 1;
            }
        }

        // initialization in first if condition
        if (p.construct(&b)) {
            p.value() = &a;
        } else if (args.argc==3) {
            p.value() = &b;
            if (args.argc==2) {
                p.value() = &c;
            }else {
                if (cpp2::cmp_greater(b,0)) {
                    p.value() = &a;
                }
                else {
                    p.value() = &d;
                }
            }
        }else {
            p.value() = &c;
        }

        std::cout << *cpp2::assert_not_null(std::move(p.value())) << std::endl;
    }

    {
        cpp2::deferred_init<int*> p; 

        // initialization in:
        // - first if branch
        // - second if condition
        if (args.argc==3) {
            p.construct(&a);
        } else if (p.construct(&b)) {
            p.value() = &b;
            if (args.argc==2) {
                p.value() = &c;
            }else {
                if (cpp2::cmp_greater(b,0)) {
                    p.value() = &a;
                }
                else {
                    p.value() = &d;
                }
            }
        }else {
            p.value() = &c;
        }

        std::cout << *cpp2::assert_not_null(std::move(p.value())) << std::endl;
    }

    {
        cpp2::deferred_init<int*> p; 

        // initialization in:
        // - first if branch
        // - second if branch in nested if condition (first if)
        // - else branch
        if (args.argc==3) {
            p.construct(&a);
        } else if (args.argc==2) {
            if (p.construct(&b)) {
                p.value() = &c;
            }else {
                if (cpp2::cmp_greater(b,0)) {
                    p.value() = &a;
                }
                else {
                    p.value() = &d;
                }
            }
        }else {
            p.construct(&c);
        }

        std::cout << *cpp2::assert_not_null(std::move(p.value())) << std::endl;
    }

    {
        cpp2::deferred_init<int*> p; 

        // initialization in:
        // - first if branch
        // - second if branch in nested if:
        //   - first branch
        //   - second branch in nested if condition (first if)
        // - else branch
        if (args.argc==3) {
            p.construct(&a);
        } else if (args.argc==2) {
            if (cpp2::cmp_greater(b,0)) {
                p.construct(&c);
            }else {
                if (p.construct(&b)) {
                    p.value() = &a;
                }
                else {
                    p.value() = &d;
                }
                *cpp2::assert_not_null(p.value()) = 42;
            }
            *cpp2::assert_not_null(p.value()) = 24;
        }else {
            p.construct(&c);
        }

        std::cout << *cpp2::assert_not_null(std::move(p.value())) << std::endl;
    }

    {
        cpp2::deferred_init<int*> p; 

        // initialization in:
        // - first if branch
        // - second if branch in nested if:
        //   - first branch
        //   - second branch in nested if:
        //     - first if branch
        //     - second if condition
        // - else branch
        if (args.argc==3) {
            p.construct(&a);
        } else if (args.argc==2) {
            if (cpp2::cmp_greater(b,0)) {
                p.construct(&c);
            }else {
                if (cpp2::cmp_greater(b,2)) {
                    p.construct(&a);
                }
                 else if (p.construct(&b)) {
                    d = *cpp2::assert_not_null(p.value());
                }
                else {
                    p.value() = &d;
                }
            }
        }else {
            p.construct(&c);
        }

        std::cout << *cpp2::assert_not_null(std::move(p.value())) << std::endl;
    }

}

