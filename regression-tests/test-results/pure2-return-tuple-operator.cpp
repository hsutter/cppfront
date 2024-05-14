
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-return-tuple-operator.cpp2"

#line 2 "pure2-return-tuple-operator.cpp2"
class A;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-return-tuple-operator.cpp2"

#line 2 "pure2-return-tuple-operator.cpp2"
class A {
struct operator_call_ret { int x; int y; };


#line 3 "pure2-return-tuple-operator.cpp2"
    public: [[nodiscard]] auto operator()() const& -> operator_call_ret;
struct operator_dereference_ret { int x; int y; };



#line 8 "pure2-return-tuple-operator.cpp2"
    public: [[nodiscard]] auto operator*() const& -> operator_dereference_ret;
struct operator_subscript_ret { int x; int y; };



#line 13 "pure2-return-tuple-operator.cpp2"
    public: [[nodiscard]] auto operator[](cpp2::impl::in<int> idx) const& -> operator_subscript_ret;
    public: A() = default;
    public: A(A const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(A const&) -> void = delete;


#line 18 "pure2-return-tuple-operator.cpp2"
};

#line 21 "pure2-return-tuple-operator.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-return-tuple-operator.cpp2"

#line 3 "pure2-return-tuple-operator.cpp2"
    [[nodiscard]] auto A::operator()() const& -> operator_call_ret{
            cpp2::impl::deferred_init<int> x;
            cpp2::impl::deferred_init<int> y;
#line 4 "pure2-return-tuple-operator.cpp2"
        x.construct(12);
        y.construct(34);
        return  { std::move(x.value()), std::move(y.value()) }; 
    }
#line 8 "pure2-return-tuple-operator.cpp2"
    [[nodiscard]] auto A::operator*() const& -> operator_dereference_ret{
            cpp2::impl::deferred_init<int> x;
            cpp2::impl::deferred_init<int> y;
#line 9 "pure2-return-tuple-operator.cpp2"
        x.construct(23);
        y.construct(45);
        return  { std::move(x.value()), std::move(y.value()) }; 
    }
#line 13 "pure2-return-tuple-operator.cpp2"
    [[nodiscard]] auto A::operator[](cpp2::impl::in<int> idx) const& -> operator_subscript_ret{
            cpp2::impl::deferred_init<int> x;
            cpp2::impl::deferred_init<int> y;
#line 14 "pure2-return-tuple-operator.cpp2"
        x.construct(34 * (idx + 1));
        y.construct(56 * (idx + 1));
        return  { std::move(x.value()), std::move(y.value()) }; 
    }

#line 21 "pure2-return-tuple-operator.cpp2"
auto main() -> int{

    A a {}; 

    auto t1 {a()}; 
    std::cout << t1.x << " , " << t1.y << "\n";

    auto t2 {*cpp2::impl::assert_not_null(a)}; 
    std::cout << t2.x << " , " << t2.y << "\n";

    auto t3 {CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(a), 0)}; 
    std::cout << t3.x << " , " << t3.y << "\n";

}

