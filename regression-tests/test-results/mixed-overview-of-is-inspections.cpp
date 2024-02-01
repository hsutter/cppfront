

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-overview-of-is-inspections.cpp2"

#line 263 "mixed-overview-of-is-inspections.cpp2"
class A;
class B;
class C;
    

#line 269 "mixed-overview-of-is-inspections.cpp2"
template<int I> class VA;

class VC;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-overview-of-is-inspections.cpp2"
int* raw_null = nullptr;

auto expect_throws(auto l) -> bool {
    try {
        l();
    } catch (...) {
        return true;
    }
    return false;
}

struct ThrowingConstruction {
    constexpr ThrowingConstruction() = default;
    ThrowingConstruction(int) { throw 1; }
};

#line 18 "mixed-overview-of-is-inspections.cpp2"
auto main() -> int;

#line 263 "mixed-overview-of-is-inspections.cpp2"
class A {
      public: A() = default;
      public: A(A const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(A const&) -> void = delete;
};
#line 264 "mixed-overview-of-is-inspections.cpp2"
class B {
      public: B() = default;
      public: B(B const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(B const&) -> void = delete;
};
#line 265 "mixed-overview-of-is-inspections.cpp2"
class C: public A {
    public: C() = default;
    public: C(C const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(C const&) -> void = delete;


#line 267 "mixed-overview-of-is-inspections.cpp2"
};

template<int I> class VA {
public: virtual ~VA() noexcept;

      public: VA() = default;
      public: VA(VA const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(VA const&) -> void = delete;
};
#line 270 "mixed-overview-of-is-inspections.cpp2"

class VC: public VA<0>, public VA<1> {
    public: VC() = default;
    public: VC(VC const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(VC const&) -> void = delete;


#line 274 "mixed-overview-of-is-inspections.cpp2"
};

#line 277 "mixed-overview-of-is-inspections.cpp2"
[[nodiscard]] auto pred_i(cpp2::in<int> x) -> bool;

#line 281 "mixed-overview-of-is-inspections.cpp2"
[[nodiscard]] auto pred_d(cpp2::in<double> x) -> bool;

#line 285 "mixed-overview-of-is-inspections.cpp2"
[[nodiscard]] auto pred_(auto const& x) -> bool;

#line 289 "mixed-overview-of-is-inspections.cpp2"
extern std::array<int,5> col;

auto print(auto const& what, auto const& value, auto const& expected, auto const& comment) -> void;

#line 302 "mixed-overview-of-is-inspections.cpp2"
auto print(auto const& what, auto const& value, auto const& expected) -> void;

#line 306 "mixed-overview-of-is-inspections.cpp2"
auto print(auto const& what, auto const& value, auto const& expected, auto const& result, auto const& comment) -> void;

#line 315 "mixed-overview-of-is-inspections.cpp2"
auto print_header(auto const& title) -> void;
#line 325 "mixed-overview-of-is-inspections.cpp2"

#include <iomanip>
#include <map>


//=== Cpp2 function definitions =================================================

#line 1 "mixed-overview-of-is-inspections.cpp2"

#line 18 "mixed-overview-of-is-inspections.cpp2"
auto main() -> int{

    print_header("type is type");
    {
        print("<A> is A", cpp2::is<A,A>(), true);
        print("<A> is B", cpp2::is<A,B>(), false);
        print("<A> is C", cpp2::is<A,C>(), false);
        print("<B> is A", cpp2::is<B,A>(), false);
        print("<B> is B", cpp2::is<B,B>(), true);
        print("<B> is C", cpp2::is<B,C>(), false);
        print("<C> is A", cpp2::is<C,A>(), true);
        print("<C> is B", cpp2::is<C,B>(), false);
        print("<C> is C", cpp2::is<C,C>(), true);
    }

    print_header("type is template");
    {
        print("<std::vector<int>> is std::vector", cpp2::is<std::vector<int>,std::vector>(), true);
        print("<std::vector<int>> is std::array", cpp2::is<std::vector<int>,std::array>(), false);
        print("<std::vector<int>> is std::optional", cpp2::is<std::vector<int>,std::optional>(), false);
        print("<std::array<int, 3>> is ", cpp2::is<std::array<int,3>,std::vector>(), false);
        print("<std::array<int, 3>> is ", cpp2::is<std::array<int,3>,std::array>(), true);
        print("<std::array<int, 3>> is ", cpp2::is<std::array<int,3>,std::optional>(), false);
        print("<std::optional<int>> is ", cpp2::is<std::optional<int>,std::vector>(), false);
        print("<std::optional<int>> is ", cpp2::is<std::optional<int>,std::array>(), false);
        print("<std::optional<int>> is ", cpp2::is<std::optional<int>,std::optional>(), true);
    }

    print_header("type is type_trait");
    {
        std::vector<int> v {}; 
        print("<const std::vector<int>> is std::is_const", cpp2::is<std::vector<int> const,std::is_const>(), true);
        print("<std::vector<int>> is std::is_const", cpp2::is<std::vector<int>,std::is_const>(), false);
        print("<std::vector<int>&> is std::is_reference", cpp2::is<decltype(std::move(v)),std::is_reference>(), true);
    }

    print_header("type is concept");
    {
        // requires: clang-13+, gcc-12.1+, msvc-v19.34+
        print("<int> is std::integral", cpp2::is<int,[]<std::integral T>() mutable -> void{}>(), true);
        print("<double> is std::integral", cpp2::is<double,[]<std::integral T>() mutable -> void{}>(), false);
    }

    print_header("variable is template");
    {
        std::vector v {1, 2, 3}; 
        print("v is vector",   cpp2::is<std::vector>(v), true);
        print("v is array",    cpp2::is<std::array>(v), false);
        print("v is optional", cpp2::is<std::optional>(std::move(v)), false);
        std::array<int,4> a {4, 3, 2, 1}; 
        print("a is array",    cpp2::is<std::array>(a), true);
        print("a is vector",   cpp2::is<std::vector>(a), false);
        print("a is optional", cpp2::is<std::optional>(std::move(a)), false);
        std::optional o {42}; 
        print("o is array",    cpp2::is<std::array>(o), false);
        print("o is vector",   cpp2::is<std::vector>(o), false);
        print("o is optional", cpp2::is<std::optional>(std::move(o)), true);

    }

    print_header("variable is type");
    {
        A a {}; 
        B b {}; 
        C c {}; 
        print("a is A", cpp2::is<A>(std::move(a)), true);
        print("b is A", cpp2::is<A>(std::move(b)), false);
        print("c is A", cpp2::is<A>(std::move(c)), true);
    }
    {
        VC vc {}; 
        VA<0>* ptr_va0 {&vc}; 
        VA<1>* ptr_va1 {&vc}; 
        VA<0> const* cptr_va0 {&vc}; 

        print("vc is VA<0>", cpp2::is<VA<0>>(vc), true);
        print("vc is VA<1>", cpp2::is<VA<1>>(vc), true);
        print("vc& is *VA<0>", cpp2::is<VA<0>*>(&vc), true);
        print("vc& is *VA<1>", cpp2::is<VA<1>*>(&vc), true);

        print("ptr_va0 is *VC", cpp2::is<VC*>(ptr_va0), true);
        print("ptr_va1 is *VC", cpp2::is<VC*>(ptr_va1), true);
        print("ptr_va0 is *VA<1>", cpp2::is<VA<1>*>(ptr_va0), true);
        print("ptr_va1 is *VA<0>", cpp2::is<VA<0>*>(ptr_va1), true);
        print("cptr_va0 is *VC", cpp2::is<VC*>(cptr_va0), false);
        print("cptr_va0 is * const VC", cpp2::is<VC const*>(cptr_va0), true);

        print("ptr_va0* is VC", cpp2::is<VC>(*cpp2::assert_not_null(ptr_va0)), true);
        print("ptr_va1* is VC", cpp2::is<VC>(*cpp2::assert_not_null(ptr_va1)), true);
        print("ptr_va0* is VA<1>", cpp2::is<VA<1>>(*cpp2::assert_not_null(std::move(ptr_va0))), true);
        print("ptr_va1* is VA<0>", cpp2::is<VA<0>>(*cpp2::assert_not_null(std::move(ptr_va1))), true);
        print("cptr_va0* is VC", cpp2::is<VC>(*cpp2::assert_not_null(cptr_va0)), false);
        print("cptr_va0* is const VC", cpp2::is<VC const>(*cpp2::assert_not_null(std::move(cptr_va0))), true);
    }

    print_header("pointer-like variable is empty");
    {
        print("raw_null is empty", cpp2::is<cpp2::empty>(raw_null), true);
        print("nullptr is empty", cpp2::is<cpp2::empty>(nullptr), true);
        print("shared_ptr() is empty", cpp2::is<cpp2::empty>(std::shared_ptr<int>()), true);
        print("unique_ptr() is empty", cpp2::is<cpp2::empty>(std::unique_ptr<int>()), true);

        auto i {42}; 
        print("i& is empty", cpp2::is<cpp2::empty>(&i), false);
        print("std::make_shared<int>(42) is empty", cpp2::is<cpp2::empty>(std::make_shared<int>(42)), false);
        print("std::make_unique<int>(44) is empty", cpp2::is<cpp2::empty>(std::make_unique<int>(44)), false);
    }

    print_header("variable is value");
    {
        auto i {42}; 
        print("i{42} is empty", cpp2::is<cpp2::empty>(i), false);
        print("i{42} is 24",    cpp2::is(i, 24), false);
        print("i{42} is 42",    cpp2::is(i, 42), true);
        print("i{42} is 42u",   cpp2::is(i, 42u), true);
        print("i{42} is 42L",   cpp2::is(i, 42L), true);
        print("i{42} is 42.0",  cpp2::is(i, 42.0), true);
        print("i{42} is 42.0f", cpp2::is(std::move(i), 42.0f), true);
        print("3.14f is 3.14",  cpp2::is(3.14f, 3.14), false);
        auto close_to {[](auto const& v) mutable -> auto { return [_0 = v](auto const& x) mutable -> bool{
            return cpp2::cmp_less(std::abs(_0 - x),std::max<std::common_type_t<std::decay_t<decltype(x)>,std::decay_t<decltype(_0)>>>(std::numeric_limits<std::decay_t<decltype(x)>>::epsilon(), std::numeric_limits<std::decay_t<decltype(_0)>>::epsilon())); 
        }; }}; 
        print("3.14f is (close_to(3.14 ))",  cpp2::is(3.14f, (close_to(3.14))), true);
        print("3.14  is (close_to(3.14f))",  cpp2::is(3.14, (std::move(close_to)(3.14f))), true);
    }

    print_header("variable is type_trait");
    {
        int i {42}; 
        int const ci {24}; 

        print("i{int} is std::is_const",                  cpp2::is<std::is_const>(std::move(i)), false);
        print("ci{const int} is std::is_const",          cpp2::is<std::is_const>(ci), true);
        print("ci{const int} is std::is_integral",       cpp2::is<std::is_integral>(ci), true);
        print("ci{const int} is std::is_floating_point", cpp2::is<std::is_floating_point>(std::move(ci)), false);
    }

    print_header("variable is predicate");
    {
        auto d {3.14}; 

        print("d{3.14} is (:(x) -> bool = x>0;)", cpp2::is(d, ([](auto const& x) mutable -> bool { return cpp2::cmp_greater(x,0); })), true);
        print("d{3.14} is (:(x:int) -> bool = x>0;)", cpp2::is(d, ([](cpp2::in<int> x) mutable -> bool { return cpp2::cmp_greater(x,0); })), false);
        print("d{3.14} is (:(x:std::string) -> bool = x.ssize()>5;)", cpp2::is(d, ([](cpp2::in<std::string> x) mutable -> bool { return cpp2::cmp_greater(CPP2_UFCS(ssize)(x),5); })), false);
        print("std::string(\"abcdefg\") is (:(x:std::string) -> bool = x.ssize()>5;)", cpp2::is(std::string("abcdefg"), ([](cpp2::in<std::string> x) mutable -> bool { return cpp2::cmp_greater(CPP2_UFCS(ssize)(x),5); })), true);

        print("d{3.14} is (pred_i)", cpp2::is(d, (pred_i)), false);
        print("d{3.14} is (pred_d)", cpp2::is(d, (pred_d)), true);
        print("d{3.14} is (pred_)", true, true);

        print("d{3.14} is (:<T:std::floating_point> () -> _ = true;)", cpp2::is(d, ([]<std::floating_point T>() mutable -> auto { return true; })), true);
        print("d{3.14} is (:<T:std::floating_point> () = {})", cpp2::is(d, ([]<std::floating_point T>() mutable -> void{})), true);
        print("d{3.14} is (:<T:std::integral> () = {})", cpp2::is(std::move(d), ([]<std::integral T>() mutable -> void{})), false);
    }

    print_header("variant variable is value");
    {
        std::variant<int,long,float,double,std::string,std::vector<int>> v {42}; 

        print("v{42} is 42",   cpp2::is(v, 42), true);
        print("v{42} is int",   cpp2::is<int>(v), true);
        print("v{42} is int",   cpp2::is<double>(v), false);
        print("v{42} is 42.0", cpp2::is(v, 42.0), true);
        print("v{42} is 24",   cpp2::is(v, 24), false);
        print("v{42} is (std::string(\"hello\"))",   cpp2::is(v, (std::string("hello"))), false);
        print("v{42} is std::integral",   cpp2::is(v, ([]<std::integral T>() mutable -> void{})), true);
        print("v{42} is std::floating_point",   cpp2::is(v, ([]<std::floating_point T>() mutable -> void{})), false);

        v = std::string("hello");
        print("v{hello} is (std::string(\"hello\"))",   cpp2::is(v, (std::string("hello"))), true);
        print("v{hello} is 42",    cpp2::is(v, 42), false);
        print("v{hello} is empty", cpp2::is<cpp2::empty>(v), false);
        print("v{hello} is int",   cpp2::is<int>(v), false);
        print("v{hello} is std::string",   cpp2::is<std::string>(v), true);

        v = std::vector{1, 2, 3, 4};
        print("v{std::vector{1,2,3,4}} is std::vector<int>", cpp2::is<std::vector<int>>(v), true);
        print("v{std::vector{1,2,3,4}} is std::vector",      cpp2::is<std::vector>(v), true);
        print("v{std::vector{1,2,3,4}} is std::map",         cpp2::is<std::map>(v), false);
        print("v{std::vector{1,2,3,4}} is std::variant",     cpp2::is<std::variant>(std::move(v)), true);
    }

    print_header("variant variable is empty");
    {
        std::variant<int,ThrowingConstruction,std::monostate> v {}; 
        print("v{int} is empty", cpp2::is<cpp2::empty>(v), false, "v contains default value of first type");

        v = std::monostate();
        print("v{monostate} is empty", cpp2::is<cpp2::empty>(v), true);

        expect_throws([_0 = (&v)]() mutable -> void { CPP2_UFCS_TEMPLATE(emplace<1>)((*cpp2::assert_not_null(_0)), 42);  });
        print("v{valueless_by_exception} is empty", cpp2::is<cpp2::empty>(v), true, "is valueless: " + cpp2::to_string(CPP2_UFCS(valueless_by_exception)(std::move(v))));

    }

    print_header("any variable is type");
    {
        std::any a {42}; 

        print("a{42} is int", cpp2::is<int>(a), true);
        print("a{42} is double", cpp2::is<double>(a), false);
        print("a{42} is empty", cpp2::is<cpp2::empty>(std::move(a)), false);

        print("std::any() is empty", cpp2::is<cpp2::empty>(std::any()), true);
    }

    print_header("any variable is value");
    {
        std::any a {42}; 

        print("a{42} is 42",  cpp2::is(a, 42), true);
        print("a{42} is 24",  cpp2::is(a, 24), false);
        print("a{42} is 42L", cpp2::is(a, 42L), false);
        print("std::any(3.14) is 3", cpp2::is(std::any(3.14), 3), false);

        print("a{42} is :(v)->bool = v.has_value();", cpp2::is(a, [](auto const& v) mutable -> bool { return CPP2_UFCS(has_value)(v); }), true);
        print("a{42} is :(v:std::any)->bool = v.has_value();", cpp2::is(a, [](cpp2::in<std::any> v) mutable -> bool { return CPP2_UFCS(has_value)(v); }), true);
        print("a{42} is :(v:int)->bool = v>0;", cpp2::is(std::move(a), [](cpp2::in<int> v) mutable -> bool { return cpp2::cmp_greater(v,0); }), true);
    }

    print_header("optional variable is type");
    {
        std::optional o {42}; 

        print("o{42} is int",  cpp2::is<int>(o), true);
        print("o{42} is empty",  cpp2::is<cpp2::empty>(std::move(o)), false);
        print("std::optional<int>() is empty",  cpp2::is<cpp2::empty>(std::optional<int>()), true);
    }

    print_header("optional variable is value");
    {
        std::optional o {42}; 

        print("o{42} is 42",   cpp2::is(o, 42), true);
        print("o{42} is 24",   cpp2::is(o, 24), false);
        print("o{42} is 42.0", cpp2::is(o, 42.0), true);

        print("o{42} is :(v) -> bool = v > 0;",   cpp2::is(o, [](auto const& v) mutable -> bool { return cpp2::cmp_greater(v,0); }), true);
        print("o{42} is :(v:std::optional<int>) -> bool = v > 0;",   cpp2::is(o, [](cpp2::in<std::optional<int>> v) mutable -> bool { return cpp2::cmp_greater(v,0); }), true);
        print("o{42} is :(v:std::optional<long>) -> bool = v > 0;",   cpp2::is(std::move(o), [](cpp2::in<std::optional<long>> v) mutable -> bool { return cpp2::cmp_greater(v,0); }), true);
        print("std::optional(3.14) is :(v:std::optional<int>) -> bool = v == 3;", cpp2::is(std::optional(3.14), [](cpp2::in<std::optional<int>> v) mutable -> bool { return *cpp2::assert_not_null(v) == 3; }), false);
    }

}

template <int I> VA<I>::~VA() noexcept{}

#line 277 "mixed-overview-of-is-inspections.cpp2"
[[nodiscard]] auto pred_i(cpp2::in<int> x) -> bool{
    return cpp2::cmp_greater(x,0); 
}

#line 281 "mixed-overview-of-is-inspections.cpp2"
[[nodiscard]] auto pred_d(cpp2::in<double> x) -> bool{
    return cpp2::cmp_greater(x,0); 
}

#line 285 "mixed-overview-of-is-inspections.cpp2"
[[nodiscard]] auto pred_(auto const& x) -> bool{
    return cpp2::cmp_greater(x,0); 
}

std::array<int,5> col {70, 8, 8, 8, 40}; 

#line 291 "mixed-overview-of-is-inspections.cpp2"
auto print(auto const& what, auto const& value, auto const& expected, auto const& comment) -> void{
    auto l {[](auto const& value) mutable -> std::string{
        if (value) {
            return "true"; 
        }else {
            return "false"; 
        }
    }}; 
    print(what, l(value), std::move(l)(expected), [&] () -> std::string { auto&& _expr = (value == expected); if (cpp2::is(_expr, (true))) { if constexpr( requires{"OK";} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("OK")),std::string> ) return "OK"; else return std::string{}; else return std::string{}; }else return "FAILED!"; }(), comment);
}

#line 302 "mixed-overview-of-is-inspections.cpp2"
auto print(auto const& what, auto const& value, auto const& expected) -> void{
    print(what, value, expected, std::string());
}

#line 306 "mixed-overview-of-is-inspections.cpp2"
auto print(auto const& what, auto const& value, auto const& expected, auto const& result, auto const& comment) -> void{
    std::cout << "|" << std::setw(CPP2_ASSERT_IN_BOUNDS_LITERAL(col, 0)) << std::right << what;
    std::cout << "|" << std::setw(CPP2_ASSERT_IN_BOUNDS_LITERAL(col, 1)) << std::internal << value;
    std::cout << "|" << std::setw(CPP2_ASSERT_IN_BOUNDS_LITERAL(col, 2)) << std::internal << expected;
    std::cout << "|" << std::setw(CPP2_ASSERT_IN_BOUNDS_LITERAL(col, 3)) << std::internal << result;
    std::cout << "|" << std::setw(CPP2_ASSERT_IN_BOUNDS_LITERAL(col, 4)) << std::left << std::setprecision(20) << comment;
    std::cout << "|" << std::endl;
}

#line 315 "mixed-overview-of-is-inspections.cpp2"
auto print_header(auto const& title) -> void{
    std::cout << ("\n# " + cpp2::to_string(title) + "\n\n");
    print("Test", "Actual", "Expected", "Result", "Comment");
    print(     std::string(CPP2_ASSERT_IN_BOUNDS_LITERAL(col, 0) - 1, '-') + ":", 
         ":" + std::string(CPP2_ASSERT_IN_BOUNDS_LITERAL(col, 1) - 2, '-') + ":", 
         ":" + std::string(CPP2_ASSERT_IN_BOUNDS_LITERAL(col, 2) - 2, '-') + ":", 
         ":" + std::string(CPP2_ASSERT_IN_BOUNDS_LITERAL(col, 3) - 2, '-') + ":", 
         ":" + std::string(CPP2_ASSERT_IN_BOUNDS_LITERAL(col, 4) - 1, '-')
    );
}

