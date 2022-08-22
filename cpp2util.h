
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


//===========================================================================
//  Cpp2 utilities:
//      Language support implementations
//      #include'd by generated Cpp1 code
//===========================================================================

#ifndef __CPP2_UTIL
#define __CPP2_UTIL

#ifdef CPP2_USE_MODULES
//  Note: When C++23 "import std;" is available, we will swich to that here
//  In the meantime, this is what works on MSVC which is the only compiler
//  I've been able to get access to that implements modules enough to demo
//  (but we'll have more full-C++20 compilers soon!)
import std.core;
import std.regex;
import std.filesystem;
import std.memory;
import std.threading;
#define assert(x) { if(!x) std::terminate(); }
#else
#include <exception>
#include <type_traits>
#include <new>
#include <memory>
#include <string_view>
#include <iostream>
#include <cassert>
#include <variant>
#endif


//  If this compiler doesn't support source location info yet, disable it
#ifndef __cpp_lib_source_location
#undef CPP2_USE_SOURCE_LOCATION
#endif
#ifdef CPP2_USE_SOURCE_LOCATION
#include <source_location>
#endif

//  Suppress spurious modules warning
#ifdef _MSC_VER
    #pragma warning(disable:5050)
#endif


#define CPP2_TYPEOF(x)  std::remove_cvref_t<decltype(x)>
#define CPP2_FORWARD(x) std::forward<decltype(x)>(x)


namespace cpp2 {

//-----------------------------------------------------------------------
// 
//  Arena objects for std::allocators
// 
//-----------------------------------------------------------------------
//
struct {
    template<typename T, typename... Args>
    [[nodiscard]] auto new_(auto ...args) const -> std::unique_ptr<T> {
        return std::make_unique<T>(CPP2_FORWARD(args)...);
    }
} unique;

struct {
    template<typename T, typename... Args>
    [[nodiscard]] auto new_(auto ...args) const -> std::unique_ptr<T> {
        return std::make_shared<T>(CPP2_FORWARD(args)...);
    }
} shared;

template<typename T, typename... Args>
[[nodiscard]] auto new_(auto ...args) -> std::unique_ptr<T> {
    return std::make_unique<T>(CPP2_FORWARD(args)...);
}


//-----------------------------------------------------------------------
// 
//  in<T>       For "in" parameter
// 
//-----------------------------------------------------------------------
//
template<typename T>
using in = 
    std::conditional_t <
        sizeof(T) < 2*sizeof(void*) && std::is_trivially_copy_constructible_v<T>,
        T const,
        T const&
    >;


//-----------------------------------------------------------------------
// 
//  Initialization: These are closely related...
// 
//  deferred_init<T>    For deferred-initialized local or member variable
//
//  out<T>              For out parameter
// 
//-----------------------------------------------------------------------
//
template<typename T>
class deferred_init {
    bool init = false;
    union { 
        int i;
        T t;
    };

    template<typename U>
    friend class out;

public:
    deferred_init() noexcept       : i {0} { }
   ~deferred_init() noexcept       { if (init) t.~T(); }
    auto value()    noexcept -> T& { assert(init);  return t; }

    auto construct     (auto ...args) -> void { assert(!init);  new (&t) T(CPP2_FORWARD(args)...);  init = true; }
    auto construct_list(auto ...args) -> void { assert(!init);  new (&t) T{CPP2_FORWARD(args)...};  init = true; }
};

template<typename T>
class out {
    //  Not going to bother with std::variant here
    union {
        T* t;
        deferred_init<T>* dt;
    };
    int  uncaught_count   = std::uncaught_exceptions();
    bool has_t;
    bool called_construct = false;

public:
    out(T* t)                 noexcept : t{t},   has_t{true}  { }
    out(deferred_init<T>* dt) noexcept : dt{dt}, has_t{false} { }

    //  In the case of an exception, if the parameter was uninitialized
    //  then leave it in the same state on exit (strong guarantee)
    ~out() {
        if (called_construct && uncaught_count != std::uncaught_exceptions()) {
            assert (!has_t);
            dt->value().~T();
        }
    }

    auto construct     (auto ...args) -> void { 
        if (has_t) {
            *t = T(args...);
        }
        else if (dt->init) {
            dt->value() = T(args...);
        }
        else {
            dt->construct(args...);
            called_construct = true;
        }
    }

    auto construct_list(auto ...args) -> void { 
        if (has_t) {
            *t = T{args...};
        }
        else if (dt->init) {
            dt->value() = T{args...};
        }
        else {
            dt->construct_list(args...);
            called_construct = true;
        }
    }
};


//-----------------------------------------------------------------------
// 
//  contract_group
// 
//-----------------------------------------------------------------------
//

#ifdef CPP2_USE_SOURCE_LOCATION
    #define CPP2_SOURCE_LOCATION_PARAM              , std::source_location where
    #define CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT , std::source_location where = std::source_location::current()
    #define CPP2_SOURCE_LOCATION_PARAM_SOLO         std::source_location where
    #define CPP2_SOURCE_LOCATION_ARG                , where
#else
    #define CPP2_SOURCE_LOCATION_PARAM
    #define CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT
    #define CPP2_SOURCE_LOCATION_PARAM_SOLO
    #define CPP2_SOURCE_LOCATION_ARG
#endif

//  For C++23: make this std::string_view and drop the macro
//      Before C++23 std::string_view was not guaranteed to be trivially copyable,
//      and so in<T> will pass it by const& and really it should be by value
#define CPP2_MESSAGE_PARAM  char const*

class contract_group {
public:
    using handler = void (*)(CPP2_MESSAGE_PARAM msg CPP2_SOURCE_LOCATION_PARAM) noexcept;

    constexpr contract_group  (handler h = nullptr)  : reporter(h) { }
    constexpr auto set_handler(handler h) -> handler { assert(h); auto old = reporter; reporter = h; return old; }
    constexpr auto get_handler() const    -> handler { return reporter; }
    constexpr auto expects    (bool b, CPP2_MESSAGE_PARAM msg = "" CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT)
                                          -> void { if (!b) reporter(msg CPP2_SOURCE_LOCATION_ARG); }
private:
    handler reporter;
};

[[noreturn]] auto report_and_terminate(std::string_view group, CPP2_MESSAGE_PARAM msg = "" CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) noexcept -> void {
    std::cerr
#ifdef CPP2_USE_SOURCE_LOCATION
        << where.file_name() << "2("
        << where.line() << ") "
        << where.function_name() << ": "
#endif
        << group << " violation";
    if (msg[0] != '\0') {
        std::cerr << ": " << msg;
    }
    std::cerr << "\n";
    std::terminate();
}

auto inline Default = contract_group( 
    [](CPP2_MESSAGE_PARAM msg CPP2_SOURCE_LOCATION_PARAM)noexcept { 
        report_and_terminate("Contract",      msg CPP2_SOURCE_LOCATION_ARG);
    }
);
auto inline Bounds  = contract_group( 
    [](CPP2_MESSAGE_PARAM msg CPP2_SOURCE_LOCATION_PARAM)noexcept { 
        report_and_terminate("Bounds safety", msg CPP2_SOURCE_LOCATION_ARG);
    } 
);
auto inline Null    = contract_group( 
    [](CPP2_MESSAGE_PARAM msg CPP2_SOURCE_LOCATION_PARAM)noexcept { 
        report_and_terminate("Null safety",   msg CPP2_SOURCE_LOCATION_ARG);
    } 
);
auto inline Type    = contract_group( 
    [](CPP2_MESSAGE_PARAM msg CPP2_SOURCE_LOCATION_PARAM)noexcept { 
        report_and_terminate("Type safety",   msg CPP2_SOURCE_LOCATION_ARG);
    } 
);
auto inline Testing = contract_group( 
    [](CPP2_MESSAGE_PARAM msg CPP2_SOURCE_LOCATION_PARAM)noexcept { 
        report_and_terminate("Testing",       msg CPP2_SOURCE_LOCATION_ARG);
    } 
);

//  Null pointer deref checking
//
auto assert_not_null(auto&& p CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> auto&&
{
    //  Checking against a default-constructed value should be fine for iterators too
    //  TODO: validate this works for all pointerlike types
    Null.expects(p != CPP2_TYPEOF(p){} CPP2_SOURCE_LOCATION_ARG);
    return std::forward<decltype(p)>(p);
}


//-----------------------------------------------------------------------
// 
//  CPP2_UFCS: Variadic macro generating a variadic lamba, oh my...
// 
//-----------------------------------------------------------------------
//
#define CPP2_UFCS(FUNCNAME,PARAM1,...) \
[](auto&& obj, auto&& ...params) { \
    if constexpr (requires{ CPP2_FORWARD(obj).FUNCNAME(CPP2_FORWARD(params)...); }) { \
        return CPP2_FORWARD(obj).FUNCNAME(CPP2_FORWARD(params)...); \
    } else { \
        return FUNCNAME(CPP2_FORWARD(obj), CPP2_FORWARD(params)...); \
    } \
}(PARAM1, __VA_ARGS__)

#define CPP2_UFCS_0(FUNCNAME,PARAM1) \
[](auto&& obj) { \
    if constexpr (requires{ CPP2_FORWARD(obj).FUNCNAME(); }) { \
        return CPP2_FORWARD(obj).FUNCNAME(); \
    } else { \
        return FUNCNAME(CPP2_FORWARD(obj)); \
    } \
}(PARAM1)



/*
//-----------------------------------------------------------------------
// 
//  is and as
// 
//-----------------------------------------------------------------------
//
#include <cstddef>
#include <iostream>
#include <cassert>

#define typeof(x) std::remove_cvref_t<decltype(x)>


//-------------------------------------------------------------------------------------------------------------
//  Built-in is
//
template<typename T, typename X>
auto is( X const& x ) {
    return false;
}

template<typename T, typename X>
    requires std::is_same_v<T, X>
auto is( X const& x ) {
    return true;
}



//-------------------------------------------------------------------------------------------------------------
//  variant is and as
//
template<typename... Ts>
constexpr auto operator_is( std::variant<Ts...> const& x ) {
    return x.index();
}
template<size_t I, typename... Ts>
constexpr auto operator_as( std::variant<Ts...> const& x ) -> auto&& {
    return std::get<I>( x );
}

template<typename T, typename... Ts>
auto is( std::variant<Ts...> const& x ) {
    if constexpr (std::is_same_v< typeof(operator_as<0>(x)), T >) if (x.index() == 0) return true;
    if constexpr (std::is_same_v< typeof(operator_as<1>(x)), T >) if (x.index() == 1) return true;
    if constexpr (std::is_same_v< typeof(operator_as<2>(x)), T >) if (x.index() == 2) return true;
    return false;
}

template<typename T, typename... Ts>
auto as( std::variant<Ts...> const& x ) {
    if constexpr (std::is_same_v< typeof(operator_as<0>(x)), T >) if (x.index() == 0) return operator_as<0>(x);
    if constexpr (std::is_same_v< typeof(operator_as<1>(x)), T >) if (x.index() == 1) return operator_as<1>(x);
    if constexpr (std::is_same_v< typeof(operator_as<2>(x)), T >) if (x.index() == 2) return operator_as<2>(x);
    throw std::bad_variant_access();
}

//=============================================================================================================

int main() {
    std::cout << "1 is int == " << is<int>(1) << "\n";
    std::cout << "1.1 is int == " << is<int>(1.1) << "\n";


    std::variant<int, int, float> v;

    v.emplace<0>(42);
    std::cout << "v.index() == " << v.index() << "\n";
    std::cout << "v is int = " << (is<int>(v) ? "true" : "false") << "\n";
    std::cout << "  -> v as int == " << as<int>(v) << "\n";
    std::cout << "v is float = " << (is<float>(v) ? "true" : "false") << "\n\n";

    v.emplace<1>(84);
    std::cout << "v.index() == " << v.index() << "\n";
    std::cout << "v is int = " << (is<int>(v) ? "true" : "false") << "\n";
    std::cout << "  -> v as int == " << as<int>(v) << "\n";
    std::cout << "v is float = " << (is<float>(v) ? "true" : "false") << "\n\n";

    v.emplace<2>(3.14159);
    std::cout << "v.index() == " << v.index() << "\n";
    std::cout << "v is int = " << (is<int>(v) ? "true" : "false") << "\n";
    std::cout << "v is float = " << (is<float>(v) ? "true" : "false") << "\n";
    std::cout << "  -> v as float == " << as<float>(v) << "\n";
}

*/


}

#endif
