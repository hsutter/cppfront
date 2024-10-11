
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-types-order-independence-and-nesting.cpp2"

#line 2 "pure2-types-order-independence-and-nesting.cpp2"
namespace N {

#line 6 "pure2-types-order-independence-and-nesting.cpp2"
class X;
    

#line 46 "pure2-types-order-independence-and-nesting.cpp2"
class Y;
    

#line 56 "pure2-types-order-independence-and-nesting.cpp2"
namespace M {

#line 59 "pure2-types-order-independence-and-nesting.cpp2"
template<typename T, typename U> class A;
    

#line 65 "pure2-types-order-independence-and-nesting.cpp2"
}

}


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-types-order-independence-and-nesting.cpp2"

#line 2 "pure2-types-order-independence-and-nesting.cpp2"
namespace N {

//  A type X, that uses Y (defined later)
//
class X {
    private: Y* py; 

    //  Note: A constructor with an 'out' parameter
    public: explicit X(cpp2::impl::out<Y> y);
#line 10 "pure2-types-order-independence-and-nesting.cpp2"
    public: auto operator=(cpp2::impl::out<Y> y) -> X& ;

#line 34 "pure2-types-order-independence-and-nesting.cpp2"
    //  X::exx member function description here
    public: auto exx(cpp2::impl::in<int> count) const& -> void;
    public: X(X const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(X const&) -> void = delete;


#line 42 "pure2-types-order-independence-and-nesting.cpp2"
};

//  Another type Y, that uses X
//
class Y {
    private: X* px; 

    public: explicit Y(X* x);
#line 49 "pure2-types-order-independence-and-nesting.cpp2"
    public: auto operator=(X* x) -> Y& ;

    public: auto why(cpp2::impl::in<int> count) const& -> void;
    public: Y(Y const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(Y const&) -> void = delete;


#line 54 "pure2-types-order-independence-and-nesting.cpp2"
};

namespace M {

//  Testing nested templated types
template<typename T, typename U> class A {
    public: template<int I> class B {
        public: template<typename V, int J, typename W> static auto f(W const& w) -> void;
        public: B() = default;
        public: B(B const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(B const&) -> void = delete;

#line 62 "pure2-types-order-independence-and-nesting.cpp2"
    };

    public: A() = default;
    public: A(A const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(A const&) -> void = delete;
};
#line 64 "pure2-types-order-independence-and-nesting.cpp2"

}

}

//  Mainline - gratuitous comment just to check that this comment
//  stays on the function declaration when lowering
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-types-order-independence-and-nesting.cpp2"

#line 2 "pure2-types-order-independence-and-nesting.cpp2"
namespace N {

#line 10 "pure2-types-order-independence-and-nesting.cpp2"
    X::X(cpp2::impl::out<Y> y)
        : py{(y.construct(&(*this)), &y.value() )}{
        //  === The following comments will stay close to, but not exactly at,
        //      the corresponding lines that get moved to the Cpp1 mem-init-list

        //  At this point, 'this' is now in scope and can safely be used.
        //  The guaranteed initialization rules ensure we cannot use an
        //  unconstructed object, and if a constructor that has begun chooses to
        //  hand out 'this&' (as in the next line below) then it is explicitly
        //  aware it's doing so - this constructor knows that if y's constructor
        //  uses the pointer it will see 'this' object's state as of this line

        //  'out' parameters are constructed first
                    // ok, construct 'y' to refer to 'this'
        //  at this point, 'y' is now initialized and can safely be used

        //  then members are constructed next
                    // ok, set 'this' to refer to 'y'

        //  === from here onward, the comments stick with their code

        //  then do anything else the constructor wants to do
#line 31 "pure2-types-order-independence-and-nesting.cpp2"
        std::cout << "made a safely initialized cycle\n";
    }
#line 10 "pure2-types-order-independence-and-nesting.cpp2"
    auto X::operator=(cpp2::impl::out<Y> y) -> X& {
        y.construct(&(*this));
        py = &y.value();

#line 31 "pure2-types-order-independence-and-nesting.cpp2"
        std::cout << "made a safely initialized cycle\n";
        return *this;
#line 32 "pure2-types-order-independence-and-nesting.cpp2"
    }

#line 35 "pure2-types-order-independence-and-nesting.cpp2"
    auto X::exx(cpp2::impl::in<int> count) const& -> void{
        //  Exercise '_' anonymous objects too while we're at it
        cpp2::finally auto_1 {[&]() -> decltype(auto) { return std::cout << "leaving call to 'why(" + cpp2::to_string(count) + ")'\n";  }}; 
        if (cpp2::impl::cmp_less(count,5)) {
            CPP2_UFCS(why)((*cpp2::impl::assert_not_null(py)), count + 1);// use Y object from X
        }
    }

#line 49 "pure2-types-order-independence-and-nesting.cpp2"
    Y::Y(X* x)
                                     : px{ x }{}
#line 49 "pure2-types-order-independence-and-nesting.cpp2"
    auto Y::operator=(X* x) -> Y& {
                                     px = x;
                                     return *this; }

#line 51 "pure2-types-order-independence-and-nesting.cpp2"
    auto Y::why(cpp2::impl::in<int> count) const& -> void{
        CPP2_UFCS(exx)((*cpp2::impl::assert_not_null(px)), count + 1);// use X object from Y
    }

#line 56 "pure2-types-order-independence-and-nesting.cpp2"
namespace M {

#line 61 "pure2-types-order-independence-and-nesting.cpp2"
        template <typename T, typename U> template <int I> template<typename V, int J, typename W> auto A<T,U>::B<I>::f(W const& w) -> void{std::cout << "hallo " + cpp2::to_string(w) + "\n"; }

#line 65 "pure2-types-order-independence-and-nesting.cpp2"
}

}

#line 71 "pure2-types-order-independence-and-nesting.cpp2"
auto main() -> int
{
    cpp2::impl::deferred_init<N::Y> y; // declare an uninitialized Y object
    N::X x {cpp2::impl::out(&y)}; // construct y and x, and point them at each other

    // now have the two objects call each other back and forth a few times
    CPP2_UFCS(exx)(cpp2::move(x), 1);

    // and test a nested template out-of-line definition
    N::M::A<int,int>::B<42>::f<int,43>("welt");
}

