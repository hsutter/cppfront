
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
#include <string>
#include <string_view>
#include <iostream>
#include <cassert>
#include <variant>
#include <any>
#include <optional>
#include <cstddef>
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
    [[nodiscard]] auto cpp2_new(auto ...args) const -> std::unique_ptr<T> {
        return std::make_unique<T>(std::forward<decltype(args)>(args)...);
    }
} unique;

struct {
    template<typename T, typename... Args>
    [[nodiscard]] auto cpp2_new(auto ...args) const -> std::shared_ptr<T> {
        return std::make_shared<T>(std::forward<decltype(args)>(args)...);
    }
} shared;

template<typename T, typename... Args>
[[nodiscard]] auto cpp2_new(auto ...args) -> std::unique_ptr<T> {
    return std::make_unique<T>(std::forward<decltype(args)>(args)...);
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

    auto construct     (auto ...args) -> void { assert(!init);  new (&t) T(std::forward<decltype(args)>(args)...);  init = true; }
    auto construct_list(auto ...args) -> void { assert(!init);  new (&t) T{std::forward<decltype(args)>(args)...};  init = true; }
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
    Null.expects(p != CPP2_TYPEOF(p){}, "dynamic null dereference attempt detected" CPP2_SOURCE_LOCATION_ARG);
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
    if constexpr (requires{ std::forward<decltype(obj)>(obj).FUNCNAME(std::forward<decltype(params)>(params)...); }) { \
        return std::forward<decltype(obj)>(obj).FUNCNAME(std::forward<decltype(params)>(params)...); \
    } else { \
        return FUNCNAME(std::forward<decltype(obj)>(obj), std::forward<decltype(params)>(params)...); \
    } \
}(PARAM1, __VA_ARGS__)

#define CPP2_UFCS_0(FUNCNAME,PARAM1) \
[](auto&& obj) { \
    if constexpr (requires{ std::forward<decltype(obj)>(obj).FUNCNAME(); }) { \
        return std::forward<decltype(obj)>(obj).FUNCNAME(); \
    } else { \
        return FUNCNAME(std::forward<decltype(obj)>(obj)); \
    } \
}(PARAM1)


//-----------------------------------------------------------------------
// 
//  is and as
// 
//-----------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------------------
//  Built-in is (partial)
//

//  For use when returning "no such thing", such as
//  when customizing is/as for std::variant
static std::nullptr_t nonesuch = nullptr;

template< typename C, typename X >
auto is( X const& ) -> bool {
    return false;
}

template< typename C, typename X >
    requires std::is_same_v<C, X>
auto is( X const& ) -> bool {
    return true;
}

template< typename C, typename X >
    requires (std::is_base_of_v<C, X> && !std::is_same_v<C,X>)
auto is( X const& ) -> bool {
    return true;
}

template< typename C, typename X >
    requires (std::is_base_of_v<X, C> && !std::is_same_v<C,X>)
auto is( X const& x ) -> bool {
    return dynamic_cast<C const*>(&x) != nullptr;
}

template< typename C, typename X >
    requires (std::is_base_of_v<X, C> && !std::is_same_v<C,X>)
auto is( X const* x ) -> bool {
    return dynamic_cast<C const&>(x) != nullptr;
}


//-------------------------------------------------------------------------------------------------------------
//  Built-in as (partial)
//
template< typename C, typename X >
    requires std::is_base_of_v<C, X>
auto as( X&& x ) -> C&& {
    return std::forward<X>(x);
}

template< typename C, typename X >
    requires (std::is_base_of_v<X, C> && !std::is_same_v<C,X>)
auto as( X& x ) -> C& {
    return dynamic_cast<C&>(x);
}

template< typename C, typename X >
    requires (std::is_base_of_v<X, C> && !std::is_same_v<C,X>)
auto as( X const& x ) -> C const& {
    return dynamic_cast<C const&>(x);
}

template< typename C, typename X >
    requires (std::is_base_of_v<X, C> && !std::is_same_v<C,X>)
auto as( X* x ) -> C* {
    return dynamic_cast<C*>(x);
}

template< typename C, typename X >
    requires (std::is_base_of_v<X, C> && !std::is_same_v<C,X>)
auto as( X const* x ) -> C const* {
    return dynamic_cast<C const*>(x);
}


//-------------------------------------------------------------------------------------------------------------
//  std::variant is and as
//
template<typename... Ts>
constexpr auto operator_is( std::variant<Ts...> const& x ) {
    return x.index();
}
template<size_t I, typename... Ts>
constexpr auto operator_as( std::variant<Ts...> const& x ) -> auto&& {
    if constexpr (I < std::variant_size_v<std::variant<Ts...>>) {
        return std::get<I>( x );
    }
    else {
        return nonesuch;
    }
}

template<typename T, typename... Ts>
auto is( std::variant<Ts...> const& x ) {
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<0>(x)), T >) if (x.index() == 0) return true;
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<1>(x)), T >) if (x.index() == 1) return true;
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<2>(x)), T >) if (x.index() == 2) return true;
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<3>(x)), T >) if (x.index() == 3) return true;
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<4>(x)), T >) if (x.index() == 4) return true;
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<5>(x)), T >) if (x.index() == 5) return true;
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<6>(x)), T >) if (x.index() == 6) return true;
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<7>(x)), T >) if (x.index() == 7) return true;
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<8>(x)), T >) if (x.index() == 8) return true;
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<9>(x)), T >) if (x.index() == 9) return true;
    return false;
}

template<typename T, typename... Ts>
auto as( std::variant<Ts...> const& x ) {
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<0>(x)), T >) if (x.index() == 0) return operator_as<0>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<1>(x)), T >) if (x.index() == 1) return operator_as<1>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<2>(x)), T >) if (x.index() == 2) return operator_as<2>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<3>(x)), T >) if (x.index() == 3) return operator_as<3>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<4>(x)), T >) if (x.index() == 4) return operator_as<4>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<5>(x)), T >) if (x.index() == 5) return operator_as<5>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<6>(x)), T >) if (x.index() == 6) return operator_as<2>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<7>(x)), T >) if (x.index() == 7) return operator_as<3>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<8>(x)), T >) if (x.index() == 8) return operator_as<4>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<9>(x)), T >) if (x.index() == 9) return operator_as<5>(x);
    throw std::bad_variant_access();
}


//-------------------------------------------------------------------------------------------------------------
//  std::any is and as
//
template<typename T>
constexpr auto is( std::any const& x ) -> bool
    { return x.type() == typeid(T); }

template<typename T>  requires (!std::is_reference_v<T>)
constexpr auto as( std::any const& x ) -> T
    { return std::any_cast<T>( x ); }


//-------------------------------------------------------------------------------------------------------------
//  std::optional is and as
//
template<typename T>
constexpr auto is( std::optional<T> const& x ) -> bool
    { return x.has_value(); }

template<typename T, typename U>
    requires (!std::is_same_v<T,U>)
constexpr auto is( std::optional<U> const& x ) -> bool
    { return false; }

template<typename T>
constexpr auto as( std::optional<T> const& x ) -> auto&&
    { return x.value(); }


//-----------------------------------------------------------------------
// 
//  to_string for string interpolation
// 
//-----------------------------------------------------------------------
//
template<typename T>
auto to_string(T const& t) -> std::string
    requires requires { std::to_string(t); }
{
    return std::to_string(t);
}

auto to_string(std::string const& s) -> std::string const&
{
    return s;
}

template<typename T>
auto to_string(std::optional<T> const& o) -> std::string {
    if (o.has_value()) {
        return std::to_string(o.value());
    }
    return "nullopt";
}


}


using cpp2::cpp2_new;


//-----------------------------------------------------------------------
// 
//  A partial implementation of GSL features Cpp2 relies on,
//  to keep this a standalone header without non-std dependencies
// 
//-----------------------------------------------------------------------
//
namespace gsl {

//-----------------------------------------------------------------------
// 
//  An implementation of GSL's narrow_cast
// 
//-----------------------------------------------------------------------
//
template<typename To, typename From>
constexpr auto narrow_cast(From&& from) noexcept -> To
{
    return static_cast<To>(std::forward<From>(from));
}


//-----------------------------------------------------------------------
// 
//  An implementation of GSL's final_action and finally
//  (based on a PR I contributed to Microsoft GSL)
// 
//  final_action ensures something is run at the end of a scope
// 
//  finally is a convenience function to generate a final_action
// 
//-----------------------------------------------------------------------
//
template <class F>
class final_action
{
public:
    template <class FF>
    explicit final_action(FF&& ff) noexcept : f{std::forward<FF>(ff)} { }

    ~final_action() noexcept { if (invoke) f(); }

    final_action(final_action&& other) noexcept
        : f(std::move(other.f)), invoke(std::exchange(other.invoke, false))
    { }

    final_action(const final_action& rhs) = delete;
    void operator=(const final_action&)   = delete;
    void operator=(final_action&& other)  = delete;

private:
    F f;
    bool invoke = true;
};

template <class F>
[[nodiscard]] auto finally(F&& f) noexcept
{
    return final_action<F>{std::forward<F>(f)};
}

}

#endif
