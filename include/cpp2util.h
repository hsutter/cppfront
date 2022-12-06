
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

//  If this implementation doesn't support source_location yet, disable it
//  TODO: technically this test should have <version> included first, but GEFN
#if !defined(_MSC_VER) && !defined(__cpp_lib_source_location)
    #undef CPP2_USE_SOURCE_LOCATION
#endif

//  If the cppfront user requested -pure-cpp2, this will be set
//  and we should be using modules only
#ifdef CPP2_USE_MODULES

    //  If we have real modules, use those the best we can
    //  as implementations are still underway
    #ifdef __cpp_modules

        #ifndef _MSC_VER
            //  This is the ideal -- note that we just voted "import std;"
            //  into draft C++23 in late July 2022, so implementers haven't
            //  had time to catch up yet. As of this writing (September 2022)
            //  no compiler will take this path yet, but they're on the way...
            import std;
        #else // MSVC
            //  Note: When C++23 "import std;" is available, we will switch to that here
            //  In the meantime, this is what works on MSVC which is the only compiler
            //  I've been able to get access to that implements modules enough to demo
            //  (but we'll have more full-C++20 compilers soon!)
            import std.core;
            import std.regex;
            import std.filesystem;
            import std.memory;
            import std.threading;

            //  Suppress spurious MSVC modules warning
            #pragma warning(disable:5050)
        #endif

    //  Otherwise, "fake it till you make it"... include (nearly) all the
    //  standard headers, with a feature test #ifdef for each header that
    //  isn't yet supported by all of { VS 2022, g++-10, clang++-12 }
    //  ... this should approximate "import std;" on those compilers
    #else
        #include <version>
        #include <concepts>
        #ifdef __cpp_lib_coroutine
            #include <coroutine>
        #endif
        #include <any>
        #include <bitset>
        #include <chrono>
        #include <compare>
        #include <csetjmp>
        #include <csignal>
        #include <cstdarg>
        #include <cstddef>
        #include <cstdlib>
        #include <ctime>
        #include <functional>
        #include <initializer_list>
        #include <optional>
        #ifdef __cpp_lib_source_location
            #include <source_location>
        #endif
        #include <tuple>
        #include <type_traits>
        #include <typeindex>
        #include <typeinfo>
        #include <utility>
        #include <variant>
        #include <memory>
        #ifdef __cpp_lib_memory_resource
            #include <memory_resource>
        #endif
        #include <new>
        #include <scoped_allocator>
        #include <cfloat>
        #include <cinttypes>
        #include <climits>
        #include <cstdint>
        #include <limits>
        #include <cassert>
        #include <cerrno>
        #include <exception>
        #include <stdexcept>
        #include <system_error>
        #include <cctype>
        #include <charconv>
        #include <cstring>
        #if __has_include(<cuchar>)
            #include <cuchar>
        #endif
        #include <cwchar>
        #include <cwctype>
        #ifdef __cpp_lib_format
            #include <format>
        #endif
        #include <string>
        #include <string_view>
        #include <array>
        #include <deque>
        #include <forward_list>
        #include <list>
        #include <map>
        #include <queue>
        #include <set>
        #include <span>
        #include <stack>
        #include <unordered_map>
        #include <unordered_set>
        #include <vector>
        #include <iterator>
        #include <ranges>
        #include <algorithm>
        // GCC sometime after version 10 got a dependency on linking TBB if <execution> is
        // included, so let's not pull in that header in our "import std;" simulation mode
        #if not defined(__GNUC__) || __GNUC__ < 11
            #include <execution>
        #endif
        #include <bit>
        #include <cfenv>
        #include <cmath>
        #include <complex>
        #include <numbers>
        #include <numeric>
        #include <random>
        #include <ratio>
        #include <valarray>
        #include <clocale>
        #include <codecvt>
        #include <locale>
        #include <cstdio>
        #include <fstream>
        #include <iomanip>
        #include <ios>
        #include <iosfwd>
        #include <iostream>
        #include <istream>
        #include <ostream>
        #ifdef __cpp_lib_spanstream
            #include <spanstream>
        #endif
        #include <sstream>
        #include <streambuf>
        #ifdef __cpp_lib_syncstream
            #include <syncstream>
        #endif
        #include <filesystem>
        #include <regex>
        #include <atomic>
        #ifdef __cpp_lib_barrier
            #include <barrier>
        #endif
        #include <condition_variable>
        #include <future>
        #ifdef __cpp_lib_latch
            #include <latch>
        #endif
        #include <mutex>
        #ifdef __cpp_lib_semaphore
            #include <semaphore>
        #endif
        #include <shared_mutex>
        #ifdef __cpp_lib_jthread
            #include <stop_token>
        #endif
        #include <thread>
        #include <iso646.h>
    #endif

//  Otherwise, we're not in -pure-cpp2 and so just #include
//  what we need in this header to make this self-contained
#else
    #include <exception>
    #include <type_traits>
    #include <new>
    #include <memory>
    #include <string>
    #include <string_view>
    #include <iostream>
    #include <variant>
    #include <any>
    #include <optional>
    #include <cstddef>
    #include <utility>
    #include <cstdio>

    #if defined(CPP2_USE_SOURCE_LOCATION)
        #include <source_location>
    #endif
#endif


#define CPP2_TYPEOF(x)  std::remove_cvref_t<decltype(x)>
#define CPP2_FORWARD(x) std::forward<decltype(x)>(x)


namespace cpp2 {

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
    using handler = void (*)(CPP2_MESSAGE_PARAM msg CPP2_SOURCE_LOCATION_PARAM);

    constexpr contract_group  (handler h = nullptr)  : reporter(h) { }
    constexpr auto set_handler(handler h) -> handler;
    constexpr auto get_handler() const    -> handler { return reporter; }
    constexpr auto expects    (bool b, CPP2_MESSAGE_PARAM msg = "" CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT)
                                          -> void { if (!b) reporter(msg CPP2_SOURCE_LOCATION_ARG); }
private:
    handler reporter;
};

[[noreturn]] inline auto report_and_terminate(std::string_view group, CPP2_MESSAGE_PARAM msg = "" CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) noexcept -> void {
    std::cerr
#ifdef CPP2_USE_SOURCE_LOCATION
        << where.file_name() << "("
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

constexpr auto contract_group::set_handler(handler h) -> handler {
    Default.expects(h);
    auto old = reporter;
    reporter = h;
    return old;
}


//  Null pointer deref checking
//
auto assert_not_null(auto&& p CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> auto&&
{
    //  NOTE: This "!= T{}" test may or may not work for STL iterators. The standard
    //        doesn't guarantee that using == and != will reliably report whether an
    //        STL iterator has the default-constructed value
    Null.expects(p != CPP2_TYPEOF(p){}, "dynamic null dereference attempt detected" CPP2_SOURCE_LOCATION_ARG);
    return std::forward<decltype(p)>(p);
}

//  Subscript bounds checking
//
auto assert_in_bounds(auto&& x, auto&& arg CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> auto&&
    requires (std::is_integral_v<CPP2_TYPEOF(arg)> &&
             requires { std::ssize(x); x[arg]; })
{
    Bounds.expects(0 <= arg && arg < std::ssize(x), "out of bounds access attempt detected" CPP2_SOURCE_LOCATION_ARG);
    return std::forward<decltype(x)>(x) [ std::forward<decltype(arg)>(arg) ];
}

auto assert_in_bounds(auto&& x, auto&& arg CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> auto&&
    requires (!(std::is_integral_v<CPP2_TYPEOF(arg)> &&
             requires { std::ssize(x); x[arg]; }))
{
    return std::forward<decltype(x)>(x) [ std::forward<decltype(arg)>(arg) ];
}


//-----------------------------------------------------------------------
//
//  Arena objects for std::allocators
//
//  Note: cppfront translates "new" to "cpp2_new", so in Cpp2 code
//        these are invoked by simply "unique.new<T>" etc.
//
//-----------------------------------------------------------------------
//
struct {
    template<typename T>
    [[nodiscard]] auto cpp2_new(auto&& ...args) const -> std::unique_ptr<T> {
        return std::make_unique<T>(std::forward<decltype(args)>(args)...);
    }
} unique;

struct {
    template<typename T>
    [[nodiscard]] auto cpp2_new(auto&& ...args) const -> std::shared_ptr<T> {
        return std::make_shared<T>(std::forward<decltype(args)>(args)...);
    }
} shared;

template<typename T>
[[nodiscard]] auto cpp2_new(auto&& ...args) -> std::unique_ptr<T> {
    return unique.cpp2_new<T>(std::forward<decltype(args)>(args)...);
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
    alignas(T) std::byte data[sizeof(T)]; // or: std::aligned_storage_t<sizeof(T), alignof(T)> data

    auto t() -> T& { return *std::launder(reinterpret_cast<T*>(&data)); }

    template<typename U>
    friend class out;

public:
    deferred_init() noexcept       { }
   ~deferred_init() noexcept       { if (init) t().~T(); }
    auto value()    noexcept -> T& { Default.expects(init);  return t(); }

    auto construct     (auto&& ...args) -> void { Default.expects(!init);  new (&data) T(std::forward<decltype(args)>(args)...);  init = true; }
    auto construct_list(auto&& ...args) -> void { Default.expects(!init);  new (&data) T{std::forward<decltype(args)>(args)...};  init = true; }
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
            Default.expects(!has_t);
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
//  CPP2_UFCS: Variadic macro generating a variadic lamba, oh my...
//
//-----------------------------------------------------------------------
//

//--------------------------------------------------------------------
//  TODO: When MSVC supports __VA_OPT__ in standard mode without the
//        experimental /Zc:preprocessor switch, use this single macro
//        instead of the dual macros below that special-case _0 args
//  AND:  Make the similarly noted change in cppfront.cpp
//
//#define CPP2_UFCS(FUNCNAME,PARAM1,...) \
//[](auto&& obj __VA_OPT__(, auto&& ...params) ) { \
//    if constexpr (requires{ std::forward<decltype(obj)>(obj).FUNCNAME(__VA_OPT__(std::forward<decltype(params)>(params)...)); }) { \
//        return std::forward<decltype(obj)>(obj).FUNCNAME(__VA_OPT__(std::forward<decltype(params)>(params)...)); \
//    } else { \
//        return FUNCNAME(std::forward<decltype(obj)>(obj) __VA_OPT__(, std::forward<decltype(params)>(params)...)); \
//    } \
//}(PARAM1 __VA_OPT__(, __VA_ARGS__) )


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
//--------------------------------------------------------------------


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

//  For designating "holds no value" -- used only with is, not as
//  TODO: Does this really warrant a new synonym? Perhaps "is void" is enough
using empty = void;

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
    return dynamic_cast<C const*>(x) != nullptr;
}

template< typename C, typename X >
    requires (requires (X x) { *x; X(); } && std::is_same_v<C, empty>)
auto is( X const& x ) -> bool {
    return x == X();
}


//-------------------------------------------------------------------------------------------------------------
//  Built-in as (partial)
//
template< typename C >
auto as(...) -> auto {
    return nonesuch;
}

template< typename C, typename X >
    requires std::is_same_v<C, X>
auto as( X const& x ) -> auto&& {
    return x;
}

template< typename C, typename X >
auto as( X const& x ) -> auto
    requires (!std::is_same_v<C, X> && requires { C{x}; })
{
    return C{x};
}

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

//  A helper for is...
template <class T, class... Ts>
inline constexpr auto is_any = std::disjunction_v<std::is_same<T, Ts>...>;

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
    if constexpr (std::is_same_v< T, empty > ) {
        if (x.valueless_by_exception()) return true;
        //  Need to guard this with is_any otherwise the get_if is illegal
        if constexpr (is_any<std::monostate, Ts...>) return std::get_if<std::monostate>(&x) != nullptr;
    }
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
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<6>(x)), T >) if (x.index() == 6) return operator_as<6>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<7>(x)), T >) if (x.index() == 7) return operator_as<7>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<8>(x)), T >) if (x.index() == 8) return operator_as<8>(x);
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<9>(x)), T >) if (x.index() == 9) return operator_as<9>(x);
    throw std::bad_variant_access();
}


//-------------------------------------------------------------------------------------------------------------
//  std::any is and as
//
template<typename T, typename X>
    requires (std::is_same_v<X,std::any> && !std::is_same_v<T,std::any> && !std::is_same_v<T,empty>)
constexpr auto is( X const& x ) -> bool
    { return x.type() == typeid(T); }

template<typename T, typename X>
    requires (std::is_same_v<X,std::any> && std::is_same_v<T,empty>)
constexpr auto is( X const& x ) -> bool
    { return !x.has_value(); }

template<typename T, typename X>
    requires (!std::is_reference_v<T> && std::is_same_v<X,std::any> && !std::is_same_v<T,std::any>)
constexpr auto as( X const& x ) -> T
    { return std::any_cast<T>( x ); }


//-------------------------------------------------------------------------------------------------------------
//  std::optional is and as
//
template<typename T, typename X>
    requires std::is_same_v<X,std::optional<T>>
constexpr auto is( X const& x ) -> bool
    { return x.has_value(); }

template<typename T, typename U>
    requires std::is_same_v<T,empty>
constexpr auto is( std::optional<U> const& x ) -> bool
    { return !x.has_value(); }

template<typename T, typename X>
    requires std::is_same_v<X,std::optional<T>>
constexpr auto as( X const& x ) -> auto&&
    { return x.value(); }


//-----------------------------------------------------------------------
//
//  A variation of GSL's final_action_success and finally to run only on success
//  (based on a PR I contributed to Microsoft GSL)
//
//  final_action_success ensures something is run at the end of a scope
//      if no exception is thrown
//
//  finally_success is a convenience function to make a final_action_success_success
//
//-----------------------------------------------------------------------
//

template <class F>
class final_action_success
{
public:
    explicit final_action_success(const F& ff) noexcept : f{ff} { }
    explicit final_action_success(F&& ff) noexcept : f{std::move(ff)} { }

    ~final_action_success() noexcept
    {
        if (invoke && ecount == std::uncaught_exceptions()) {
            f();
        }
    }

    final_action_success(final_action_success&& that) noexcept
        : f(std::move(that.f)), invoke(std::exchange(that.invoke, false))
    { }

    final_action_success(final_action_success const&) = delete;
    void operator=      (final_action_success const&) = delete;
    void operator=      (final_action_success&&)      = delete;

private:
    F f;
    int  ecount = std::uncaught_exceptions();
    bool invoke = true;
};

template <class F>
[[nodiscard]] auto finally_success(F&& f) noexcept
{
    return final_action_success<std::remove_cvref_t<F>>{std::forward<F>(f)};
}


//-----------------------------------------------------------------------
//
//  to_string for string interpolation
//
//-----------------------------------------------------------------------
//
inline auto to_string(...) -> std::string {
    return "(customize me - no cpp2::to_string overload exists for this type)";
}

template<typename T>
inline auto to_string(T const& t) -> std::string
    requires requires { std::to_string(t); }
{
    return std::to_string(t);
}

inline auto to_string(std::string const& s) -> std::string const&
{
    return s;
}

template<typename T>
inline auto to_string(T const& sv) -> std::string
    requires (std::is_convertible_v<T, std::string_view> 
              && !std::is_convertible_v<T, const char*>)
{
    return std::string{sv};
}

template <typename... Ts>
inline auto to_string(std::variant<Ts...> const& v) -> std::string;

template < typename T, typename U>
inline auto to_string(std::pair<T,U> const& p) -> std::string;

template < typename... Ts>
inline auto to_string(std::tuple<Ts...> const& t) -> std::string;

template<typename T>
inline auto to_string(std::optional<T> const& o) -> std::string {
    if (o.has_value()) {
        return cpp2::to_string(o.value());
    }
    return "(empty)";
}

template <typename... Ts>
inline auto to_string(std::variant<Ts...> const& v) -> std::string
{
    if (v.valueless_by_exception()) return "(empty)";
    //  Need to guard this with is_any otherwise the get_if is illegal
    if constexpr (is_any<std::monostate, Ts...>) if (std::get_if<std::monostate>(&v) != nullptr) return "(empty)";

    return std::visit([](auto&& arg) -> std::string {
        return cpp2::to_string(arg);
    }, v);
}

template < typename T, typename U>
inline auto to_string(std::pair<T,U> const& p) -> std::string
{
    return "(" + cpp2::to_string(p.first) + ", " + cpp2::to_string(p.second) + ")";
}

template < typename... Ts>
inline auto to_string(std::tuple<Ts...> const& t) -> std::string
{
    if constexpr (sizeof...(Ts) == 0) {
        return "()";
    } else {
        std::string out = "(" + cpp2::to_string(std::get<0>(t));
        std::apply([&out](auto&&, auto&&... args) {
            ((out += ", " + cpp2::to_string(args)), ...);
        }, t);
        out += ")";
        return out;
    }
}


//-----------------------------------------------------------------------
//
//  Speculative: RAII wrapping for the C standard library
//
//  As part of embracing compatibility while also reducing what we have to
//  teach and learn about C++ (which includes the C standard library), I
//  was curious to see if we can improve use of the C standard library
//  from Cpp2 code... UFCS is a part of that, and then RAII destructors is
//  another that goes hand in hand with that, hence this section...
//  but see caveat note at the end.
//
//-----------------------------------------------------------------------
//
template<typename T>
class c_raii {
    T t;
    void (*dtor)(void*);
public:
    template<typename D>
    c_raii( T t_, D d )
        : t{ t_ }
        , dtor{ [](void* x) { (void)(D)(x); } }
    { }

    ~c_raii() { if (dtor) dtor(t); }

    operator T&() { return t; }

    c_raii(c_raii const&)         = delete;
    auto operator=(c_raii const&) = delete;
    c_raii(c_raii&& that)         : t  {std::move(that.t)}, dtor  {that.dtor} { that.dtor = nullptr; }
    auto operator=(c_raii&& that) { t = std::move(that.t);  dtor = that.dtor;   that.dtor = nullptr; }
};

inline auto fopen( const char* filename, const char* mode ) {
    auto x = std::fopen(filename, mode);
    if (!x) {
        throw std::make_error_condition(std::errc::no_such_file_or_directory);
    }
    return c_raii( x, &fclose );
}

//  Caveat: There's little else in the C stdlib that allocates a resource...
//
//      malloc          is already wrapped like this via std::unique_ptr, which
//                        typically uses malloc or gets memory from the same pool
//      thrd_create     std::jthread is better
//
//  ... is that it? I don't think it's useful to provide a c_raii just for fopen,
//  but perhaps c_raii may be useful for bringing forward third-party C code too,
//  with cpp2::fopen as a starting example.


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

}

#endif
