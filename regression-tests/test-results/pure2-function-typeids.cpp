
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-function-typeids.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-function-typeids.cpp2"

//  --- Scaffolding

#line 4 "pure2-function-typeids.cpp2"
auto f() -> void;

auto g_in(      cpp2::impl::in<std::string> s) -> void;
auto g_inout(std::string& s) -> void;
auto g_out(cpp2::impl::out<std::string> s) -> void;
auto g_move(std::string&& s) -> void;

[[nodiscard]] auto h_forward(std::string& s) -> std::string&;
[[nodiscard]] auto h_out(cpp2::impl::in<std::string> s) -> std::string;

[[nodiscard]] auto f1(cpp2::impl::in<std::function<int(cpp2::impl::in<int> x)>> a) -> int;
[[nodiscard]] auto f2(int(*a)(cpp2::impl::in<int> x)) -> int;
[[nodiscard]] auto g   (cpp2::impl::in<int> x) -> int;

#line 19 "pure2-function-typeids.cpp2"
// --- Tests for type aliases

using A_h_forward = std::string&(std::string& s);

#line 24 "pure2-function-typeids.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-function-typeids.cpp2"

#line 4 "pure2-function-typeids.cpp2"
auto f() -> void{std::cout << "hello world!\n"; }

#line 6 "pure2-function-typeids.cpp2"
auto g_in(      cpp2::impl::in<std::string> s) -> void{std::cout << "Come in, " + cpp2::to_string(s) + "\n";}
#line 7 "pure2-function-typeids.cpp2"
auto g_inout(std::string& s) -> void{std::cout << "Come in awhile, but take some biscuits on your way out, " + cpp2::to_string(s) + "!\n"; }
#line 8 "pure2-function-typeids.cpp2"
auto g_out(cpp2::impl::out<std::string> s) -> void{s.construct("A Powerful Mage");}
#line 9 "pure2-function-typeids.cpp2"
auto g_move(std::string&& s) -> void{std::cout << "I hear you've moving, " + cpp2::to_string(cpp2::move(s)) + "?\n";}

#line 11 "pure2-function-typeids.cpp2"
[[nodiscard]] auto h_forward(std::string& s) -> std::string&{std::cout << "Inout " + cpp2::to_string(s) + " ... "; return s; }
#line 12 "pure2-function-typeids.cpp2"
[[nodiscard]] auto h_out(cpp2::impl::in<std::string> s) -> std::string{std::cout << "In " + cpp2::to_string(s) + " ... ";return "yohoho"; }

#line 14 "pure2-function-typeids.cpp2"
[[nodiscard]] auto f1(cpp2::impl::in<std::function<int(cpp2::impl::in<int> x)>> a) -> int { return a(1);  }
#line 15 "pure2-function-typeids.cpp2"
[[nodiscard]] auto f2(int(*a)(cpp2::impl::in<int> x)) -> int { return a(2); }
#line 16 "pure2-function-typeids.cpp2"
[[nodiscard]] auto g   (cpp2::impl::in<int> x) -> int { return x + 42; }

#line 24 "pure2-function-typeids.cpp2"
auto main() -> int
{
    //  --- Test basic/degenerate cases

    //  Test std::function< void() >
    std::function<void()> ff {&f}; 
    cpp2::move(ff)();

    //  Ordinary pointer to function, deduced (always worked)
    void(*pf)()  = &f; 
    cpp2::move(pf)();

#line 37 "pure2-function-typeids.cpp2"
    //  --- Tests for parameters
    //      Note: Not forward parameters which imply a template...
    //            function type-ids are for single function signatures

    std::function<void(cpp2::impl::in<std::string> s)> fg_in {&g_in}; 
    std::function<void(std::string& s)> fg_inout {&g_inout}; 
    std::function<void(cpp2::impl::out<std::string> s)> fg_out {&g_out}; 
    std::function<void(std::string&& s)> fg_move {&g_move}; 
    void(*pg_in)(cpp2::impl::in<    std::string> s)  = &g_in; 
    void(*pg_inout)(          std::string& s)  = &g_inout; 
    void(*pg_out)(cpp2::impl::out<std::string> s)  = &g_out; 
    void(*pg_move)(           std::string&& s)  = &g_move; 

    std::string frodo {"Frodo"}; 
    std::string sam {"Sam"}; 

    //  Test in param
    cpp2::move(fg_in)(frodo);
    cpp2::move(pg_in)(sam);

    //  Test inout
    cpp2::move(fg_inout)(frodo);
    cpp2::move(pg_inout)(sam);

    //  Test out
    cpp2::impl::deferred_init<std::string> gandalf; 
    cpp2::impl::deferred_init<std::string> galadriel; 
    cpp2::move(fg_out)(cpp2::impl::out(&gandalf));
    std::cout << "fg_out initialized gandalf to: " + cpp2::to_string(gandalf.value()) + "\n";
    cpp2::move(pg_out)(cpp2::impl::out(&galadriel));
    std::cout << "pg_out initialized galadriel to: " + cpp2::to_string(galadriel.value()) + "\n";
    gandalf.value() = "Gandalf";
    galadriel.value() = "Galadriel";

    //  Test move
    cpp2::move(fg_move)(cpp2::move(frodo));// last use, so (move frodo) is not required
    cpp2::move(pg_move)(cpp2::move(sam));// last use, so (move sam) is not required

#line 76 "pure2-function-typeids.cpp2"
    //  --- Tests for single anonymous returns
    //      Note: Not multiple named return values... function-type-ids 
    //      are for Cpp1-style (single anonymous, possibly void) returns

    std::function<std::string&(std::string& s)> fh_forward {&h_forward}; 
    std::function<std::string(cpp2::impl::in<std::string> s)> fh_out {&h_out}; 
    std::string&(*ph_forward)(  std::string& s)  = &h_forward; 
    std::string(*ph_out)(cpp2::impl::in<std::string> s)  = &h_out; 

    A_h_forward* ph_forward2 {&h_forward}; 

    //  Test forward return
    std::cout << "fh_forward returned: " + cpp2::to_string(cpp2::move(fh_forward)(gandalf.value())) + "\n";
    std::cout << "ph_forward returned: " + cpp2::to_string(cpp2::move(ph_forward)(galadriel.value())) + "\n";
    std::cout << "ph_forward2 returned: " + cpp2::to_string(cpp2::move(ph_forward2)(galadriel.value())) + "\n";

    //  Test out return
    std::cout << "fh_out returned: " + cpp2::to_string(cpp2::move(fh_out)(cpp2::move(gandalf.value()))) + "\n";
    std::cout << "ph_out returned: " + cpp2::to_string(cpp2::move(ph_out)(cpp2::move(galadriel.value()))) + "\n";

#line 97 "pure2-function-typeids.cpp2"
    //  --- Tests for function parameters
    std::cout << "" + cpp2::to_string(f1(&g)) + "\n";
    std::cout << "" + cpp2::to_string(f2(&g)) + "\n";

#line 102 "pure2-function-typeids.cpp2"
}

