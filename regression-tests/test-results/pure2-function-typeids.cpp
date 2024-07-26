
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

[[nodiscard]] auto h_out(cpp2::impl::in<std::string> s) -> std::string;
[[nodiscard]] auto h_forward(std::string& s) -> std::string&;

#line 15 "pure2-function-typeids.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-function-typeids.cpp2"

#line 4 "pure2-function-typeids.cpp2"
auto f() -> void { std::cout << "hello world!\n";  }

#line 6 "pure2-function-typeids.cpp2"
auto g_in(      cpp2::impl::in<std::string> s) -> void { std::cout << "Come in, " + cpp2::to_string(s) + "\n"; }
#line 7 "pure2-function-typeids.cpp2"
auto g_inout(std::string& s) -> void { std::cout << "Come in awhile, but take some biscuits on your way out, " + cpp2::to_string(s) + "!\n";  }
#line 8 "pure2-function-typeids.cpp2"
auto g_out(cpp2::impl::out<std::string> s) -> void { s.construct("Gandalf"); }
#line 9 "pure2-function-typeids.cpp2"
auto g_move(std::string&& s) -> void { std::cout << "I hear you've moving, " + cpp2::to_string(cpp2::move(s)) + "?\n"; }

#line 11 "pure2-function-typeids.cpp2"
[[nodiscard]] auto h_out(cpp2::impl::in<std::string> s) -> std::string{std::cout << "In " + cpp2::to_string(s) + " ... ";return "yohoho"; }
#line 12 "pure2-function-typeids.cpp2"
[[nodiscard]] auto h_forward(std::string& s) -> std::string&{std::cout << "Inout " + cpp2::to_string(s) + " ... "; return s; }

#line 15 "pure2-function-typeids.cpp2"
auto main() -> int
{
    //  --- Test basic/degenerate cases

    //  Ordinary pointer to function, deduced (always worked)
    auto pf {&f}; 
    cpp2::move(pf)();

    //  Test std::function< void() >
    std::function<void()> ff {&f}; 
    cpp2::move(ff)();

#line 28 "pure2-function-typeids.cpp2"
    //  --- Tests for parameters
    //      Note: Not forward parameters which imply a template...
    //            function type-ids are for single function signatures

    std::function<void(std::string& s)> fg_in {&g_in}; 
    std::function<void(std::string& s)> fg_inout {&g_inout}; 
    std::function<void(cpp2::impl::out<std::string> s)> fg_out {&g_out}; 
    std::function<void(std::string&& s)> fg_move {&g_move}; 

    std::string frodo {"Frodo"}; 

    //  Test in param
    cpp2::move(fg_in)(frodo);

    //  Test inout
    cpp2::move(fg_inout)(frodo);

    //  Test out
    cpp2::impl::deferred_init<std::string> gandalf; 
    cpp2::move(fg_out)(cpp2::impl::out(&gandalf));
    std::cout << "fg_out initialized the arg to: " + cpp2::to_string(gandalf.value()) + "\n";

    //  Test move
    cpp2::move(fg_move)(cpp2::move(frodo));// last use, so (move frodo) is not required

#line 54 "pure2-function-typeids.cpp2"
    //  --- Tests for single anonymous returns
    //      Note: Not multiple named return values... function-type-ids 
    //      are for Cpp1-style (single anonymous, possibly void) returns

    std::function<std::string(cpp2::impl::in<std::string> s)> fh_out {&h_out}; 
    std::function<std::string&(std::string& s)> fh_forward {&h_forward}; 

    //  Test out return
    std::cout << "fh_out returned: " + cpp2::to_string(cpp2::move(fh_out)(gandalf.value())) + "\n";

    //  Test forward return
    std::cout << "fh_forward returned: " + cpp2::to_string(cpp2::move(fh_forward)(gandalf.value())) + "\n";

    static_cast<void>(cpp2::move(gandalf.value()));
}

