

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-is-with-variant.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-is-with-variant.cpp2"
auto test(auto const& v) -> void;

#line 12 "mixed-is-with-variant.cpp2"
auto set_and_test(auto& v, auto const& what, auto&& value) -> void;

#line 18 "mixed-is-with-variant.cpp2"
[[nodiscard]] auto main() -> int;
#line 44 "mixed-is-with-variant.cpp2"

template<int I>
struct X { operator int() const { return I; } };

struct ThrowingConstruction {
    constexpr ThrowingConstruction() = default;
    ThrowingConstruction(int) { throw 1; }
};

using PotentiallyThrowingVariant = std::variant<std::monostate,ThrowingConstruction,X<0>,X<1>,X<2>>;

void set_to_valueless_by_exception(auto& v) try {
    v.template emplace<1>(42);
} catch (...) {}


//=== Cpp2 function definitions =================================================

#line 1 "mixed-is-with-variant.cpp2"
auto test(auto const& v) -> void{
#line 2 "mixed-is-with-variant.cpp2"
    std::cout << "v is empty = " + cpp2::to_string(cpp2::impl::is<void>(v)) + "" << std::endl;
    std::cout << "v is std::monostate = " + cpp2::to_string(cpp2::impl::is<std::monostate>(v)) + "" << std::endl;
    std::cout << "v is X< 0> = " + cpp2::to_string(cpp2::impl::is<X<0>>(v)) + "" << std::endl;
    std::cout << "v is X<10> = " + cpp2::to_string(cpp2::impl::is<X<10>>(v)) + "" << std::endl;
    std::cout << "v is X<29> = " + cpp2::to_string(cpp2::impl::is<X<29>>(v)) + "" << std::endl;
    std::cout << "v is X<30> = " + cpp2::to_string(cpp2::impl::is<X<30>>(v)) + "" << std::endl;
    std::cout << "v is ThrowingConstruction = " + cpp2::to_string(cpp2::impl::is<ThrowingConstruction>(v)) + "" << std::endl;
    std::cout << std::endl;
}

#line 12 "mixed-is-with-variant.cpp2"
auto set_and_test(auto& v, auto const& what, auto&& value) -> void{
    std::cout << "set v to " + cpp2::to_string(what) + "" << std::endl;
    v = CPP2_FORWARD(value);
    test(v);
}

#line 18 "mixed-is-with-variant.cpp2"
[[nodiscard]] auto main() -> int{

    std::variant<std::monostate,ThrowingConstruction,X<0>,X<1>,X<2>,X<3>,X<4>,X<5>,X<6>,X<7>,X<8>,X<9>,X<10>,X<11>,X<12>,X<13>,X<14>,X<15>,X<16>,X<17>,X<18>,X<19>,PotentiallyThrowingVariant,X<20>,X<21>,X<22>,X<23>,X<24>,X<25>,X<26>,X<27>,X<28>,X<29>> v {

#line 25 "mixed-is-with-variant.cpp2"
                    }; 

#line 28 "mixed-is-with-variant.cpp2"
    set_and_test(v, "std::monostate", std::monostate());
    set_and_test(v, "X<19>", X<19>());
    set_and_test(v, "X<29>", X<29>());
    set_and_test(v, "X<0> in std::variant<std::monostate, PotentiallyThrowingVariant, X<0>, X<1>, X<2>>", PotentiallyThrowingVariant(X<0>()));
    set_and_test(v, "std::monostate in std::variant<std::monostate, PotentiallyThrowingVariant, X<0>, X<1>, X<2>>", PotentiallyThrowingVariant(std::monostate()));
    set_and_test(v, "ThrowingConstruction", ThrowingConstruction());

    std::cout << "set v to valueless by exception state" << std::endl;
    set_to_valueless_by_exception(v);
    test(v);

    std::cout << "set v element to valueless by exception state" << std::endl;
    CPP2_UFCS_TEMPLATE(emplace<22>)(v);
    set_to_valueless_by_exception(CPP2_UFCS_TEMPLATE(get<22>)(v));
    test(cpp2::move(v));
}

