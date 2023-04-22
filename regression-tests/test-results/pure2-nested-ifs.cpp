
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-nested-ifs.cpp2"
auto main(int const argc_, char const* const* const argv_) -> int;


//=== Cpp2 function definitions =================================================

#line 1 "pure2-nested-ifs.cpp2"
auto main(int const argc_, char const* const* const argv_) -> int
{
    auto args = cpp2::make_args(argc_, argv_); 
#line 3 "pure2-nested-ifs.cpp2"
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

        // initialization in:
        // - first if branch
        // - second if branch in nested if:
        //   - first branch
        //   - second branch in nested if:
        //     - first if branch
        //     - else branch
        // - else branch
        if (args.argc==3) {
            p.construct(&a);
        } else if (args.argc==2) {
            if (cpp2::cmp_greater(b,0)) {
                p.construct(&c);
            }else {
                if (cpp2::cmp_greater(std::move(b),2)) {
                    p.construct(&a);
                }
                else {
                    p.construct(&d);
                }
            }
        }else {
            p.construct(&c);
        }

        std::cout << *cpp2::assert_not_null(std::move(p.value())) << std::endl;
    }

}

