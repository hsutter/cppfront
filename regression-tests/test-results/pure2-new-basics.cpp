
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-new-basics.cpp2"
class Movable;
#line 2 "pure2-new-basics.cpp2"
    

#line 7 "pure2-new-basics.cpp2"
class Copyable;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-new-basics.cpp2"
class Movable {
#line 2 "pure2-new-basics.cpp2"
    public: explicit Movable();
    public: Movable([[maybe_unused]] Movable&& that) noexcept;
#line 3 "pure2-new-basics.cpp2"
    public: auto operator=([[maybe_unused]] Movable&& that) noexcept -> Movable& ;
    public: auto test() const& -> void;
};

class Copyable {
    public: explicit Copyable();
    public: Copyable([[maybe_unused]] Copyable const& that);
#line 9 "pure2-new-basics.cpp2"
    public: auto operator=([[maybe_unused]] Copyable const& that) -> Copyable& ;
#line 9 "pure2-new-basics.cpp2"
    public: Copyable([[maybe_unused]] Copyable&& that) noexcept;
#line 9 "pure2-new-basics.cpp2"
    public: auto operator=([[maybe_unused]] Copyable&& that) noexcept -> Copyable& ;
    public: auto test() const& -> void;
};

auto call_test(auto const& m) -> void;

#line 17 "pure2-new-basics.cpp2"
auto test_movable() -> void;

#line 29 "pure2-new-basics.cpp2"
auto test_movable_ref() -> void;

#line 43 "pure2-new-basics.cpp2"
auto test_movable_ref_replace() -> void;

#line 55 "pure2-new-basics.cpp2"
auto test_copyable() -> void;

#line 67 "pure2-new-basics.cpp2"
auto test_copyable_ref() -> void;

#line 85 "pure2-new-basics.cpp2"
auto test_copyable_ref_replace() -> void;

#line 98 "pure2-new-basics.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-new-basics.cpp2"

#line 2 "pure2-new-basics.cpp2"
    Movable::Movable(){}
#line 3 "pure2-new-basics.cpp2"
    Movable::Movable([[maybe_unused]] Movable&& that) noexcept{}
#line 3 "pure2-new-basics.cpp2"
    auto Movable::operator=([[maybe_unused]] Movable&& that) noexcept -> Movable& {
                                         return *this; }
#line 4 "pure2-new-basics.cpp2"
    auto Movable::test() const& -> void{}

#line 8 "pure2-new-basics.cpp2"
    Copyable::Copyable(){}
#line 9 "pure2-new-basics.cpp2"
    Copyable::Copyable([[maybe_unused]] Copyable const& that){}
#line 9 "pure2-new-basics.cpp2"
    auto Copyable::operator=([[maybe_unused]] Copyable const& that) -> Copyable& {
                                       return *this; }
#line 9 "pure2-new-basics.cpp2"
    Copyable::Copyable([[maybe_unused]] Copyable&& that) noexcept{}
#line 9 "pure2-new-basics.cpp2"
    auto Copyable::operator=([[maybe_unused]] Copyable&& that) noexcept -> Copyable& {
                                       return *this; }
#line 10 "pure2-new-basics.cpp2"
    auto Copyable::test() const& -> void{}

#line 13 "pure2-new-basics.cpp2"
auto call_test(auto const& m) -> void{
    CPP2_UFCS(test)(m);
}

#line 17 "pure2-new-basics.cpp2"
auto test_movable() -> void{
    Movable a {}; 
    CPP2_UFCS(test)(a);
    call_test(a);

    Movable b {std::move(a)}; 
    CPP2_UFCS(test)(b);
    call_test(std::move(b));

    //a.test(); // not allowed
}

#line 29 "pure2-new-basics.cpp2"
auto test_movable_ref() -> void{
    auto a {cpp2_new<Movable>()}; 

    if ((a)) {
        CPP2_UFCS(test)((*cpp2::assert_not_null(*cpp2::assert_not_null(a))));
        call_test(*cpp2::assert_not_null(*cpp2::assert_not_null(a)));
        //b : _ = a**;      // cannot create copy       
        auto c {*cpp2::assert_not_null(std::move(a))}; 
        call_test(*cpp2::assert_not_null(c));
        CPP2_UFCS(test)((*cpp2::assert_not_null(std::move(c))));
        // a**.test(); // not allowed
    }
}

#line 43 "pure2-new-basics.cpp2"
auto test_movable_ref_replace() -> void{
    auto a {cpp2_new<Movable>()}; 
    if ((a)) {
        CPP2_UFCS(test)((*cpp2::assert_not_null(*cpp2::assert_not_null(a))));
    }

    a = cpp2_new<Movable>();
    if ((a)) {
        CPP2_UFCS(test)((*cpp2::assert_not_null(*cpp2::assert_not_null(std::move(a)))));
    }
}

#line 55 "pure2-new-basics.cpp2"
auto test_copyable() -> void{
    Copyable a {}; 
    CPP2_UFCS(test)(a);
    call_test(a);

    Copyable b {a}; 
    CPP2_UFCS(test)(b);
    call_test(std::move(b));

    CPP2_UFCS(test)(std::move(a));// allowed
}

#line 67 "pure2-new-basics.cpp2"
auto test_copyable_ref() -> void{
    auto a {cpp2_new<Copyable>()}; 

    if ((a)) {
        CPP2_UFCS(test)((*cpp2::assert_not_null(*cpp2::assert_not_null(a))));
        call_test(*cpp2::assert_not_null(*cpp2::assert_not_null(a)));
        auto b {*cpp2::assert_not_null(*cpp2::assert_not_null(a))}; // create copy
        call_test(b);
        CPP2_UFCS(test)(std::move(b));
        CPP2_UFCS(test)((*cpp2::assert_not_null(*cpp2::assert_not_null(a))));// allowed

        auto c {*cpp2::assert_not_null(std::move(a))}; // move owning reference from optional
        call_test(*cpp2::assert_not_null(c));
        CPP2_UFCS(test)((*cpp2::assert_not_null(std::move(c))));
        //a**.test(); // no longer allowed
    }
}

#line 85 "pure2-new-basics.cpp2"
auto test_copyable_ref_replace() -> void{
    auto a {cpp2_new<Copyable>()}; 
    if ((a)) {
        CPP2_UFCS(test)((*cpp2::assert_not_null(*cpp2::assert_not_null(a))));
    }

    a = cpp2_new<Copyable>();
    if ((a)) {
        CPP2_UFCS(test)((*cpp2::assert_not_null(*cpp2::assert_not_null(std::move(a)))));
    }
}

#line 98 "pure2-new-basics.cpp2"
auto main() -> int{
    test_movable();
    test_movable_ref();
    test_movable_ref_replace();
    test_copyable();
    test_copyable_ref();
    test_copyable_ref_replace();
}

