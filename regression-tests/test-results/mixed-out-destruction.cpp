

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "mixed-out-destruction.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "mixed-out-destruction.cpp2"
#include <iostream>

struct X {
    inline static int Xnum = 0;
    int num;
    X() : num{++Xnum}                { std::cout << "+X " << num << "\n"; }
    ~X()                             { std::cout << "-X " << num << "\n"; }
    X(const X& that) : num{that.num} { std::cout << "+X copy " << num << "\n"; }
    void operator=(const X& that)    { num = that.num; std::cout << "=X copy " << num << "\n"; }
};

auto throw_1() { throw 1; }

struct C {
    std::string f;
    C(std::string const& fn) : f{fn} { std::cout << "enter " << f << "\n"; }
    ~C()                             { std::cout << "exit " << f << "\n"; }
};

//-------------------------------------------------------
// 0x: Test one level of out and immediate throw
#line 22 "mixed-out-destruction.cpp2"
auto f00() -> void;
auto f01(cpp2::out<X> x) -> void;

//-------------------------------------------------------
// 1x: Test multiple levels of out and intermediate throw
auto f10() -> void;
auto f11(cpp2::out<X> x) -> void;
auto f12(cpp2::out<X> x) -> void;
auto f13(cpp2::out<X> x) -> void;
auto f14(cpp2::out<X> x) -> void;

int main() {
    C c("main");
    try { f00(); } catch (int) {}
    std::cout << "\n";
    try { f10(); } catch (int) {}
}


//=== Cpp2 function definitions =================================================

#line 1 "mixed-out-destruction.cpp2"

#line 22 "mixed-out-destruction.cpp2"
auto f00() -> void     {   C auto_22_28 {"f00"}; cpp2::deferred_init<X> x; f01(cpp2::out(&x));}
auto f01(cpp2::out<X> x) -> void{C auto_23_28 {"f01"}; x.construct();throw_1();}

#line 27 "mixed-out-destruction.cpp2"
auto f10() -> void     {   C auto_27_28 {"f10"}; cpp2::deferred_init<X> x; f11(cpp2::out(&x));}
auto f11(cpp2::out<X> x) -> void{C auto_28_28 {"f11"}; f12(cpp2::out(&x));}
auto f12(cpp2::out<X> x) -> void{C auto_29_28 {"f12"}; f13(cpp2::out(&x));throw_1();}
auto f13(cpp2::out<X> x) -> void{C auto_30_28 {"f13"}; f14(cpp2::out(&x));}
auto f14(cpp2::out<X> x) -> void{C auto_31_28 {"f14"}; x.construct();}

