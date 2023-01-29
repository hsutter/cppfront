
#line 1 "mixed-as-for-variant-20-types.cpp2"
template<int I>
struct X { operator int() const { return I; } };

#include "cpp2util.h"


#line 4 "mixed-as-for-variant-20-types.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 definitions ==========================================================

#line 3 "mixed-as-for-variant-20-types.cpp2"

[[nodiscard]] auto main() -> int{

    std::variant<X<0>,X<1>,X<2>,X<3>,X<4>,X<5>,X<6>,X<7>,X<8>,X<9>,X<10>,X<11>,X<12>,X<13>,X<14>,X<15>,X<16>,X<17>,X<18>,X<19>> v {
                                                                                            X<0>()}; 

    // lvalue reference
    v = X< 0>(); std::cout << "v as X< 0> = " + cpp2::to_string(int(cpp2::as_<X<0>>(v))) << std::endl;
    v = X< 1>(); std::cout << "v as X< 1> = " + cpp2::to_string(int(cpp2::as_<X<1>>(v))) << std::endl;
    v = X< 2>(); std::cout << "v as X< 2> = " + cpp2::to_string(int(cpp2::as_<X<2>>(v))) << std::endl;
    v = X< 3>(); std::cout << "v as X< 3> = " + cpp2::to_string(int(cpp2::as_<X<3>>(v))) << std::endl;
    v = X< 4>(); std::cout << "v as X< 4> = " + cpp2::to_string(int(cpp2::as_<X<4>>(v))) << std::endl;
    v = X< 5>(); std::cout << "v as X< 5> = " + cpp2::to_string(int(cpp2::as_<X<5>>(v))) << std::endl;
    v = X< 6>(); std::cout << "v as X< 6> = " + cpp2::to_string(int(cpp2::as_<X<6>>(v))) << std::endl;
    v = X< 7>(); std::cout << "v as X< 7> = " + cpp2::to_string(int(cpp2::as_<X<7>>(v))) << std::endl;
    v = X< 8>(); std::cout << "v as X< 8> = " + cpp2::to_string(int(cpp2::as_<X<8>>(v))) << std::endl;
    v = X< 9>(); std::cout << "v as X< 9> = " + cpp2::to_string(int(cpp2::as_<X<9>>(v))) << std::endl;
    v = X<10>(); std::cout << "v as X<10> = " + cpp2::to_string(int(cpp2::as_<X<10>>(v))) << std::endl;
    v = X<11>(); std::cout << "v as X<11> = " + cpp2::to_string(int(cpp2::as_<X<11>>(v))) << std::endl;
    v = X<12>(); std::cout << "v as X<12> = " + cpp2::to_string(int(cpp2::as_<X<12>>(v))) << std::endl;
    v = X<13>(); std::cout << "v as X<13> = " + cpp2::to_string(int(cpp2::as_<X<13>>(v))) << std::endl;
    v = X<14>(); std::cout << "v as X<14> = " + cpp2::to_string(int(cpp2::as_<X<14>>(v))) << std::endl;
    v = X<15>(); std::cout << "v as X<15> = " + cpp2::to_string(int(cpp2::as_<X<15>>(v))) << std::endl;
    v = X<16>(); std::cout << "v as X<16> = " + cpp2::to_string(int(cpp2::as_<X<16>>(v))) << std::endl;
    v = X<17>(); std::cout << "v as X<17> = " + cpp2::to_string(int(cpp2::as_<X<17>>(v))) << std::endl;
    v = X<18>(); std::cout << "v as X<18> = " + cpp2::to_string(int(cpp2::as_<X<18>>(v))) << std::endl;
    v = X<19>(); std::cout << "v as X<19> = " + cpp2::to_string(int(cpp2::as_<X<19>>(v))) << std::endl;

    // const lvalue reference
    v = X< 0>(); std::cout << "as_const(v) as X< 0> = " + cpp2::to_string(int(cpp2::as_<X<0>>(std::as_const(v)))) << std::endl;
    v = X< 1>(); std::cout << "as_const(v) as X< 1> = " + cpp2::to_string(int(cpp2::as_<X<1>>(std::as_const(v)))) << std::endl;
    v = X< 2>(); std::cout << "as_const(v) as X< 2> = " + cpp2::to_string(int(cpp2::as_<X<2>>(std::as_const(v)))) << std::endl;
    v = X< 3>(); std::cout << "as_const(v) as X< 3> = " + cpp2::to_string(int(cpp2::as_<X<3>>(std::as_const(v)))) << std::endl;
    v = X< 4>(); std::cout << "as_const(v) as X< 4> = " + cpp2::to_string(int(cpp2::as_<X<4>>(std::as_const(v)))) << std::endl;
    v = X< 5>(); std::cout << "as_const(v) as X< 5> = " + cpp2::to_string(int(cpp2::as_<X<5>>(std::as_const(v)))) << std::endl;
    v = X< 6>(); std::cout << "as_const(v) as X< 6> = " + cpp2::to_string(int(cpp2::as_<X<6>>(std::as_const(v)))) << std::endl;
    v = X< 7>(); std::cout << "as_const(v) as X< 7> = " + cpp2::to_string(int(cpp2::as_<X<7>>(std::as_const(v)))) << std::endl;
    v = X< 8>(); std::cout << "as_const(v) as X< 8> = " + cpp2::to_string(int(cpp2::as_<X<8>>(std::as_const(v)))) << std::endl;
    v = X< 9>(); std::cout << "as_const(v) as X< 9> = " + cpp2::to_string(int(cpp2::as_<X<9>>(std::as_const(v)))) << std::endl;
    v = X<10>(); std::cout << "as_const(v) as X<10> = " + cpp2::to_string(int(cpp2::as_<X<10>>(std::as_const(v)))) << std::endl;
    v = X<11>(); std::cout << "as_const(v) as X<11> = " + cpp2::to_string(int(cpp2::as_<X<11>>(std::as_const(v)))) << std::endl;
    v = X<12>(); std::cout << "as_const(v) as X<12> = " + cpp2::to_string(int(cpp2::as_<X<12>>(std::as_const(v)))) << std::endl;
    v = X<13>(); std::cout << "as_const(v) as X<13> = " + cpp2::to_string(int(cpp2::as_<X<13>>(std::as_const(v)))) << std::endl;
    v = X<14>(); std::cout << "as_const(v) as X<14> = " + cpp2::to_string(int(cpp2::as_<X<14>>(std::as_const(v)))) << std::endl;
    v = X<15>(); std::cout << "as_const(v) as X<15> = " + cpp2::to_string(int(cpp2::as_<X<15>>(std::as_const(v)))) << std::endl;
    v = X<16>(); std::cout << "as_const(v) as X<16> = " + cpp2::to_string(int(cpp2::as_<X<16>>(std::as_const(v)))) << std::endl;
    v = X<17>(); std::cout << "as_const(v) as X<17> = " + cpp2::to_string(int(cpp2::as_<X<17>>(std::as_const(v)))) << std::endl;
    v = X<18>(); std::cout << "as_const(v) as X<18> = " + cpp2::to_string(int(cpp2::as_<X<18>>(std::as_const(v)))) << std::endl;
    v = X<19>(); std::cout << "as_const(v) as X<19> = " + cpp2::to_string(int(cpp2::as_<X<19>>(std::as_const(v)))) << std::endl;

    // rvalue reference
    v = X< 0>(); std::cout << "move(v) as X< 0> = " + cpp2::to_string(int(cpp2::as_<X<0>>((std::move(v))))) << std::endl;
    v = X< 1>(); std::cout << "move(v) as X< 1> = " + cpp2::to_string(int(cpp2::as_<X<1>>((std::move(v))))) << std::endl;
    v = X< 2>(); std::cout << "move(v) as X< 2> = " + cpp2::to_string(int(cpp2::as_<X<2>>((std::move(v))))) << std::endl;
    v = X< 3>(); std::cout << "move(v) as X< 3> = " + cpp2::to_string(int(cpp2::as_<X<3>>((std::move(v))))) << std::endl;
    v = X< 4>(); std::cout << "move(v) as X< 4> = " + cpp2::to_string(int(cpp2::as_<X<4>>((std::move(v))))) << std::endl;
    v = X< 5>(); std::cout << "move(v) as X< 5> = " + cpp2::to_string(int(cpp2::as_<X<5>>((std::move(v))))) << std::endl;
    v = X< 6>(); std::cout << "move(v) as X< 6> = " + cpp2::to_string(int(cpp2::as_<X<6>>((std::move(v))))) << std::endl;
    v = X< 7>(); std::cout << "move(v) as X< 7> = " + cpp2::to_string(int(cpp2::as_<X<7>>((std::move(v))))) << std::endl;
    v = X< 8>(); std::cout << "move(v) as X< 8> = " + cpp2::to_string(int(cpp2::as_<X<8>>((std::move(v))))) << std::endl;
    v = X< 9>(); std::cout << "move(v) as X< 9> = " + cpp2::to_string(int(cpp2::as_<X<9>>((std::move(v))))) << std::endl;
    v = X<10>(); std::cout << "move(v) as X<10> = " + cpp2::to_string(int(cpp2::as_<X<10>>((std::move(v))))) << std::endl;
    v = X<11>(); std::cout << "move(v) as X<11> = " + cpp2::to_string(int(cpp2::as_<X<11>>((std::move(v))))) << std::endl;
    v = X<12>(); std::cout << "move(v) as X<12> = " + cpp2::to_string(int(cpp2::as_<X<12>>((std::move(v))))) << std::endl;
    v = X<13>(); std::cout << "move(v) as X<13> = " + cpp2::to_string(int(cpp2::as_<X<13>>((std::move(v))))) << std::endl;
    v = X<14>(); std::cout << "move(v) as X<14> = " + cpp2::to_string(int(cpp2::as_<X<14>>((std::move(v))))) << std::endl;
    v = X<15>(); std::cout << "move(v) as X<15> = " + cpp2::to_string(int(cpp2::as_<X<15>>((std::move(v))))) << std::endl;
    v = X<16>(); std::cout << "move(v) as X<16> = " + cpp2::to_string(int(cpp2::as_<X<16>>((std::move(v))))) << std::endl;
    v = X<17>(); std::cout << "move(v) as X<17> = " + cpp2::to_string(int(cpp2::as_<X<17>>((std::move(v))))) << std::endl;
    v = X<18>(); std::cout << "move(v) as X<18> = " + cpp2::to_string(int(cpp2::as_<X<18>>((std::move(v))))) << std::endl;
    v = X<19>(); std::cout << "move(v) as X<19> = " + cpp2::to_string(int(cpp2::as_<X<19>>((std::move(std::move(v)))))) << std::endl;

}

