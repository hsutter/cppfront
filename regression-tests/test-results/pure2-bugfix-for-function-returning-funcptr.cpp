
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-bugfix-for-function-returning-funcptr.cpp2"


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-bugfix-for-function-returning-funcptr.cpp2"
extern std::optional<int> g_inttemplate;
#line 2 "pure2-bugfix-for-function-returning-funcptr.cpp2"
extern std::optional<void(*)([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1)> g_template;
extern std::unordered_map<int,void(*)([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1)> g_signal_handlers;

using intfuncptr = void(*)([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1);

[[nodiscard]] auto set_signal(cpp2::impl::in<int> signum, void(*handler)([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1)) -> void(*)([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1);

#line 20 "pure2-bugfix-for-function-returning-funcptr.cpp2"
extern cpp2::i64 g_signal;
auto inc_signal(cpp2::impl::in<int> signum) -> void;

#line 24 "pure2-bugfix-for-function-returning-funcptr.cpp2"
auto dec_signal(cpp2::impl::in<int> signum) -> void;

#line 28 "pure2-bugfix-for-function-returning-funcptr.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-bugfix-for-function-returning-funcptr.cpp2"
std::optional<int> g_inttemplate {std::nullopt}; 
#line 2 "pure2-bugfix-for-function-returning-funcptr.cpp2"
std::optional<void(*)([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1)> g_template {std::nullopt}; 
std::unordered_map<int,void(*)([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1)> g_signal_handlers {}; 

#line 7 "pure2-bugfix-for-function-returning-funcptr.cpp2"
[[nodiscard]] auto set_signal(cpp2::impl::in<int> signum, void(*handler)([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1)) -> void(*)([[maybe_unused]] cpp2::impl::in<int> unnamed_param_1){
    auto default_handler {[](cpp2::impl::in<int> foo) -> void{
        // Default handler does nothing
        static_cast<void>(foo);
    }}; 
    intfuncptr old_handler {cpp2::move(default_handler)}; 
    if (CPP2_UFCS(find)(g_signal_handlers, signum) != CPP2_UFCS(end)(g_signal_handlers)) {
        old_handler = CPP2_ASSERT_IN_BOUNDS(g_signal_handlers, signum);
    }
    CPP2_ASSERT_IN_BOUNDS(g_signal_handlers, signum) = handler;
    return old_handler; 
}

cpp2::i64 g_signal {0}; 
#line 21 "pure2-bugfix-for-function-returning-funcptr.cpp2"
auto inc_signal(cpp2::impl::in<int> signum) -> void{
    g_signal += signum;
}
#line 24 "pure2-bugfix-for-function-returning-funcptr.cpp2"
auto dec_signal(cpp2::impl::in<int> signum) -> void{
    g_signal -= signum;
}

#line 28 "pure2-bugfix-for-function-returning-funcptr.cpp2"
[[nodiscard]] auto main() -> int{
    static_cast<void>(set_signal(1, inc_signal));
    auto cmpx {set_signal(1, dec_signal)}; 
    return cpp2::move(cmpx) != inc_signal; 
}

