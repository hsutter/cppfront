
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

        // libstdc++ currently has a dependency on linking TBB if <execution> is
        // included, and TBB seems to be not automatically installed and linkable
        // on some GCC installations, so let's not pull in that little-used header
        // in our -pure-cpp2 "import std;" simulation mode... if you need this,
        // use mixed mode (not -pure-cpp2) and #include all the headers you need
        // including this one
        // 
        // #include <execution>
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
    #include <cstdint>

    #if defined(CPP2_USE_SOURCE_LOCATION)
        #include <source_location>
    #endif
#endif


#define CPP2_TYPEOF(x)  std::remove_cvref_t<decltype(x)>
#define CPP2_FORWARD(x) std::forward<decltype(x)>(x)


namespace cpp2 {

//-----------------------------------------------------------------------
//
//  Convenience names for fundamental types
//
//  Note: De jure, some of these are optional per the C and C++ standards
//        De facto, all of these are supported in all implementations I know of
//
//-----------------------------------------------------------------------
//

//  Encouraged by default: Fixed-precision names
using i8        = std::int8_t        ;
using i16       = std::int16_t       ;
using i32       = std::int32_t       ;
using i64       = std::int64_t       ;
using u8        = std::uint8_t       ;
using u16       = std::uint16_t      ;
using u32       = std::uint32_t      ;
using u64       = std::uint64_t      ;

//  Rarely, when really needed for speed optimization: Fastest type with at least N bits
using i8_fast   = std::int_fast8_t   ;
using i16_fast  = std::int_fast16_t  ;
using i32_fast  = std::int_fast32_t  ;
using i64_fast  = std::int_fast64_t  ;
using u8_fast   = std::uint_fast8_t  ;
using u16_fast  = std::uint_fast16_t ;
using u32_fast  = std::uint_fast32_t ;
using u64_fast  = std::uint_fast64_t ;

//  Rarely, when really needed for space optimization: Smallest type with at least N bits
using i8_small  = std::int_least8_t  ;
using i16_small = std::int_least16_t ;
using i32_small = std::int_least32_t ;
using i64_small = std::int_least64_t ;
using u8_small  = std::uint_least8_t ;
using u16_small = std::uint_least16_t;
using u32_small = std::uint_least32_t;
using u64_small = std::uint_least64_t;

//  Discouraged: Variable precision names
//                short
using ushort    = unsigned short;
//                int
using ulong     = unsigned long;
//                long
using longlong  = long long;
using ulonglong = unsigned long long;
using longdouble = long double;

//  Strongly discouraged, for compatibility/interop only
using __schar   = signed char;      // normally use i8 instead
using __uchar   = unsigned char;    // normally use u8 instead


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

    constexpr contract_group  (handler h = {})  : reporter(h) { }
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
auto assert_not_null(auto&& p CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> decltype(auto)
{
    //  NOTE: This "!= T{}" test may or may not work for STL iterators. The standard
    //        doesn't guarantee that using == and != will reliably report whether an
    //        STL iterator has the default-constructed value
    Null.expects(p != CPP2_TYPEOF(p){}, "dynamic null dereference attempt detected" CPP2_SOURCE_LOCATION_ARG);
    return std::forward<decltype(p)>(p);
}

//  Subscript bounds checking
//
auto assert_in_bounds(auto&& x, auto&& arg CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> decltype(auto)
    requires (std::is_integral_v<CPP2_TYPEOF(arg)> &&
             requires { std::ssize(x); x[arg]; })
{
    Bounds.expects(0 <= arg && arg < std::ssize(x), "out of bounds access attempt detected" CPP2_SOURCE_LOCATION_ARG);
    return std::forward<decltype(x)>(x) [ std::forward<decltype(arg)>(arg) ];
}

auto assert_in_bounds(auto&& x, auto&& arg CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> decltype(auto)
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

[[maybe_unused]] struct {
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

    auto destroy() -> void         { if (init) { t().~T(); }  init = false; }

public:
    deferred_init() noexcept       { }
   ~deferred_init() noexcept       { destroy(); }
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
    out<T>* ot = {};
    bool has_t;

    //  Each out in a chain contains its own uncaught_count ...
    int  uncaught_count   = std::uncaught_exceptions();
    //  ... but all in a chain share the topmost called_construct_
    bool called_construct_ = false;

public:
    out(T*                 t) noexcept :  t{ t}, has_t{true}      { Default.expects( t); }
    out(deferred_init<T>* dt) noexcept : dt{dt}, has_t{false}     { Default.expects(dt); }
    out(out<T>*           ot) noexcept : ot{ot}, has_t{ot->has_t} { Default.expects(ot);
        if (has_t) {  t = ot->t;  }
        else       { dt = ot->dt; }
    }

    auto called_construct() -> bool& {
        if (ot) { return ot->called_construct(); }
        else    { return called_construct_; }
    }

    //  In the case of an exception, if the parameter was uninitialized
    //  then leave it in the same state on exit (strong guarantee)
    ~out() {
        if (called_construct() && uncaught_count != std::uncaught_exceptions()) {
            Default.expects(!has_t);
            dt->destroy();
            called_construct() = false;
        }
    }

    auto construct(auto&& ...args) -> void {
        if (has_t) {
            Default.expects( t );
            *t = T(std::forward<decltype(args)>(args)...);
        }
        else {
            Default.expects( dt );
            if (dt->init) {
                dt->value() = T(std::forward<decltype(args)>(args)...);
            }
            else {
                dt->construct(std::forward<decltype(args)>(args)...);
                called_construct() = true;
            }
        }
    }

    auto construct_list(auto&& ...args) -> void {
        if (has_t) {
            Default.expects( t );
            *t = T{std::forward<decltype(args)>(args)...};
        }
        else {
            Default.expects( dt );
            if (dt->init) {
                dt->value() = T{std::forward<decltype(args)>(args)...};
            }
            else {
                dt->construct_list(std::forward<decltype(args)>(args)...);
                called_construct() = true;
            }
        }
    }

    auto value() noexcept -> T& {
        if (has_t) {
            Default.expects( t );
            return *t;
        }
        else {
            Default.expects( dt );
            return dt->value();
        }
    }
};


//-----------------------------------------------------------------------
//
//  CPP2_UFCS: Variadic macro generating a variadic lamba, oh my...
//
//-----------------------------------------------------------------------
//
#ifdef _MSC_VER
    #define CPP2_FORCE_INLINE [[msvc::forceinline]]
#else
    #define CPP2_FORCE_INLINE __attribute__((always_inline))
#endif

#define CPP2_UFCS(FUNCNAME,PARAM1,...) \
[](auto&& obj, auto&& ...params) CPP2_FORCE_INLINE { \
    if constexpr (requires{ std::forward<decltype(obj)>(obj).FUNCNAME(std::forward<decltype(params)>(params)...); }) { \
        return std::forward<decltype(obj)>(obj).FUNCNAME(std::forward<decltype(params)>(params)...); \
    } else { \
        return FUNCNAME(std::forward<decltype(obj)>(obj), std::forward<decltype(params)>(params)...); \
    } \
}(PARAM1, __VA_ARGS__)

#define CPP2_UFCS_0(FUNCNAME,PARAM1) \
[](auto&& obj) CPP2_FORCE_INLINE { \
    if constexpr (requires{ std::forward<decltype(obj)>(obj).FUNCNAME(); }) { \
        return std::forward<decltype(obj)>(obj).FUNCNAME(); \
    } else { \
        return FUNCNAME(std::forward<decltype(obj)>(obj)); \
    } \
}(PARAM1)

#define CPP2_UFCS_REMPARENS(...) __VA_ARGS__

#define CPP2_UFCS_TEMPLATE(FUNCNAME,TEMPARGS,PARAM1,...) \
[](auto&& obj, auto&& ...params) CPP2_FORCE_INLINE { \
    if constexpr (requires{ std::forward<decltype(obj)>(obj).template FUNCNAME CPP2_UFCS_REMPARENS TEMPARGS (std::forward<decltype(params)>(params)...); }) { \
        return std::forward<decltype(obj)>(obj).template FUNCNAME CPP2_UFCS_REMPARENS TEMPARGS (std::forward<decltype(params)>(params)...); \
    } else { \
        return FUNCNAME CPP2_UFCS_REMPARENS TEMPARGS (std::forward<decltype(obj)>(obj), std::forward<decltype(params)>(params)...); \
    } \
}(PARAM1, __VA_ARGS__)

#define CPP2_UFCS_TEMPLATE_0(FUNCNAME,TEMPARGS,PARAM1) \
[](auto&& obj) CPP2_FORCE_INLINE { \
    if constexpr (requires{ std::forward<decltype(obj)>(obj).template FUNCNAME CPP2_UFCS_REMPARENS TEMPARGS (); }) { \
        return std::forward<decltype(obj)>(obj).template FUNCNAME CPP2_UFCS_REMPARENS TEMPARGS (); \
    } else { \
        return FUNCNAME CPP2_UFCS_REMPARENS TEMPARGS (std::forward<decltype(obj)>(obj)); \
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
//  Built-in is
//

//  For use when returning "no such thing", such as
//  when customizing is/as for std::variant
struct nonesuch_ {
    auto operator==(auto const&) -> bool { return false; }
};
static nonesuch_ nonesuch;

//  For designating "holds no value" -- used only with is, not as
//  TODO: Does this really warrant a new synonym? Perhaps "is void" is enough
using empty = void;


//  Templates
//
template <template <typename...> class C, typename... Ts>
constexpr auto is(C< Ts...> const& ) -> bool {
    return true;
}

#if defined(_MSC_VER)
    template <template <typename, typename...> class C, typename T>
    constexpr auto is( T const& ) -> bool {
        return false;
    }
#else
    template <template <typename...> class C, typename T>
    constexpr auto is( T const& ) -> bool {
        return false;
    }
#endif

template <template <typename,auto> class C, typename T, auto V>
constexpr auto is( C<T, V> const& ) -> bool {
    return true;
}

template <template <typename,auto> class C, typename T>
constexpr auto is( T const& ) -> bool {
    return false;
}

//  Types
//
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
    requires (
        ( std::is_base_of_v<X, C> || 
          ( std::is_polymorphic_v<C> && std::is_polymorphic_v<X>) 
        ) && !std::is_same_v<C,X>)
auto is( X const& x ) -> bool {
    return dynamic_cast<C const*>(&x) != nullptr;
}

template< typename C, typename X >
    requires (
        ( std::is_base_of_v<X, C> || 
          ( std::is_polymorphic_v<C> && std::is_polymorphic_v<X>) 
        ) && !std::is_same_v<C,X>)
auto is( X const* x ) -> bool {
    return dynamic_cast<C const*>(x) != nullptr;
}

template< typename C, typename X >
    requires (requires (X x) { *x; X(); } && std::is_same_v<C, empty>)
auto is( X const& x ) -> bool {
    return x == X();
}


//  Values
//
inline constexpr auto is( auto const& x, auto const& value ) -> bool
{
    //  Predicate case
    if constexpr (requires{ bool{ value(x) }; }) {
        return value(x);
    }
    else if constexpr (std::is_function_v<decltype(value)> || requires{ &value.operator(); }) {
        return false;
    }

    //  Value case
    else if constexpr (requires{ bool{x == value}; }) {
        return x == value;
    }
    return false;
}


//-------------------------------------------------------------------------------------------------------------
//  Built-in as
//
template< typename C >
auto as(auto const&) -> auto {
    return nonesuch;
}

template< typename C, typename X >
    requires std::is_same_v<C, X>
auto as( X const& x ) -> decltype(auto) {
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

//  Common internal helper
//
template<size_t I, typename... Ts>
constexpr auto operator_as( std::variant<Ts...> const& x ) -> decltype(auto) {
    if constexpr (I < std::variant_size_v<std::variant<Ts...>>) {
        return std::get<I>( x );
    }
    else {
        return nonesuch;
    }
}


//  is Type
//
template<typename... Ts>
constexpr auto operator_is( std::variant<Ts...> const& x ) {
    return x.index();
}

template<typename T, typename... Ts>
auto is( std::variant<Ts...> const& x );


//  is Value
//
template<typename... Ts>
constexpr auto is( std::variant<Ts...> const& x, auto const& value ) -> bool
{
    //  Predicate case
    if constexpr      (requires{ bool{ value(operator_as< 0>(x)) }; }) { if (x.index() ==  0) return value(operator_as< 0>(x)); }
    else if constexpr (requires{ bool{ value(operator_as< 1>(x)) }; }) { if (x.index() ==  1) return value(operator_as< 1>(x)); }
    else if constexpr (requires{ bool{ value(operator_as< 2>(x)) }; }) { if (x.index() ==  2) return value(operator_as< 2>(x)); }
    else if constexpr (requires{ bool{ value(operator_as< 3>(x)) }; }) { if (x.index() ==  3) return value(operator_as< 3>(x)); }
    else if constexpr (requires{ bool{ value(operator_as< 4>(x)) }; }) { if (x.index() ==  4) return value(operator_as< 4>(x)); }
    else if constexpr (requires{ bool{ value(operator_as< 5>(x)) }; }) { if (x.index() ==  5) return value(operator_as< 5>(x)); }
    else if constexpr (requires{ bool{ value(operator_as< 6>(x)) }; }) { if (x.index() ==  6) return value(operator_as< 6>(x)); }
    else if constexpr (requires{ bool{ value(operator_as< 7>(x)) }; }) { if (x.index() ==  7) return value(operator_as< 7>(x)); }
    else if constexpr (requires{ bool{ value(operator_as< 8>(x)) }; }) { if (x.index() ==  8) return value(operator_as< 8>(x)); }
    else if constexpr (requires{ bool{ value(operator_as< 9>(x)) }; }) { if (x.index() ==  9) return value(operator_as< 9>(x)); }
    else if constexpr (requires{ bool{ value(operator_as<10>(x)) }; }) { if (x.index() == 10) return value(operator_as<10>(x)); }
    else if constexpr (requires{ bool{ value(operator_as<11>(x)) }; }) { if (x.index() == 11) return value(operator_as<11>(x)); }
    else if constexpr (requires{ bool{ value(operator_as<12>(x)) }; }) { if (x.index() == 12) return value(operator_as<12>(x)); }
    else if constexpr (requires{ bool{ value(operator_as<13>(x)) }; }) { if (x.index() == 13) return value(operator_as<13>(x)); }
    else if constexpr (requires{ bool{ value(operator_as<14>(x)) }; }) { if (x.index() == 14) return value(operator_as<14>(x)); }
    else if constexpr (requires{ bool{ value(operator_as<15>(x)) }; }) { if (x.index() == 15) return value(operator_as<15>(x)); }
    else if constexpr (requires{ bool{ value(operator_as<16>(x)) }; }) { if (x.index() == 16) return value(operator_as<16>(x)); }
    else if constexpr (requires{ bool{ value(operator_as<17>(x)) }; }) { if (x.index() == 17) return value(operator_as<17>(x)); }
    else if constexpr (requires{ bool{ value(operator_as<18>(x)) }; }) { if (x.index() == 18) return value(operator_as<18>(x)); }
    else if constexpr (requires{ bool{ value(operator_as<19>(x)) }; }) { if (x.index() == 19) return value(operator_as<19>(x)); }
    else if constexpr (std::is_function_v<decltype(value)> || requires{ &value.operator(); }) {
        return false;
    }

    //  Value case
    else {
        if constexpr (requires{ bool{ operator_as< 0>(x) == value }; }) { if (x.index() ==  0) return operator_as< 0>(x) == value; }
        if constexpr (requires{ bool{ operator_as< 1>(x) == value }; }) { if (x.index() ==  1) return operator_as< 1>(x) == value; }
        if constexpr (requires{ bool{ operator_as< 2>(x) == value }; }) { if (x.index() ==  2) return operator_as< 2>(x) == value; }
        if constexpr (requires{ bool{ operator_as< 3>(x) == value }; }) { if (x.index() ==  3) return operator_as< 3>(x) == value; }
        if constexpr (requires{ bool{ operator_as< 4>(x) == value }; }) { if (x.index() ==  4) return operator_as< 4>(x) == value; }
        if constexpr (requires{ bool{ operator_as< 5>(x) == value }; }) { if (x.index() ==  5) return operator_as< 5>(x) == value; }
        if constexpr (requires{ bool{ operator_as< 6>(x) == value }; }) { if (x.index() ==  6) return operator_as< 6>(x) == value; }
        if constexpr (requires{ bool{ operator_as< 7>(x) == value }; }) { if (x.index() ==  7) return operator_as< 7>(x) == value; }
        if constexpr (requires{ bool{ operator_as< 8>(x) == value }; }) { if (x.index() ==  8) return operator_as< 8>(x) == value; }
        if constexpr (requires{ bool{ operator_as< 9>(x) == value }; }) { if (x.index() ==  9) return operator_as< 9>(x) == value; }
        if constexpr (requires{ bool{ operator_as<10>(x) == value }; }) { if (x.index() == 10) return operator_as<10>(x) == value; }
        if constexpr (requires{ bool{ operator_as<11>(x) == value }; }) { if (x.index() == 11) return operator_as<11>(x) == value; }
        if constexpr (requires{ bool{ operator_as<12>(x) == value }; }) { if (x.index() == 12) return operator_as<12>(x) == value; }
        if constexpr (requires{ bool{ operator_as<13>(x) == value }; }) { if (x.index() == 13) return operator_as<13>(x) == value; }
        if constexpr (requires{ bool{ operator_as<14>(x) == value }; }) { if (x.index() == 14) return operator_as<14>(x) == value; }
        if constexpr (requires{ bool{ operator_as<15>(x) == value }; }) { if (x.index() == 15) return operator_as<15>(x) == value; }
        if constexpr (requires{ bool{ operator_as<16>(x) == value }; }) { if (x.index() == 16) return operator_as<16>(x) == value; }
        if constexpr (requires{ bool{ operator_as<17>(x) == value }; }) { if (x.index() == 17) return operator_as<17>(x) == value; }
        if constexpr (requires{ bool{ operator_as<18>(x) == value }; }) { if (x.index() == 18) return operator_as<18>(x) == value; }
        if constexpr (requires{ bool{ operator_as<19>(x) == value }; }) { if (x.index() == 19) return operator_as<19>(x) == value; }
    }
    return false;
}


//  as
//
template <class T, class... Ts>
inline constexpr auto is_any = std::disjunction_v<std::is_same<T, Ts>...>;

template<typename T, typename... Ts>
auto is( std::variant<Ts...> const& x ) {
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 0>(x)), T >) { if (x.index() ==  0) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 1>(x)), T >) { if (x.index() ==  1) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 2>(x)), T >) { if (x.index() ==  2) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 3>(x)), T >) { if (x.index() ==  3) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 4>(x)), T >) { if (x.index() ==  4) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 5>(x)), T >) { if (x.index() ==  5) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 6>(x)), T >) { if (x.index() ==  6) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 7>(x)), T >) { if (x.index() ==  7) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 8>(x)), T >) { if (x.index() ==  8) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 9>(x)), T >) { if (x.index() ==  9) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<10>(x)), T >) { if (x.index() == 10) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<11>(x)), T >) { if (x.index() == 11) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<12>(x)), T >) { if (x.index() == 12) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<13>(x)), T >) { if (x.index() == 13) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<14>(x)), T >) { if (x.index() == 14) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<15>(x)), T >) { if (x.index() == 15) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<16>(x)), T >) { if (x.index() == 16) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<17>(x)), T >) { if (x.index() == 17) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<18>(x)), T >) { if (x.index() == 18) return true; }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<19>(x)), T >) { if (x.index() == 19) return true; }
    if constexpr (std::is_same_v< T, empty > ) {
        if (x.valueless_by_exception()) return true;
        //  Need to guard this with is_any otherwise the get_if is illegal
        if constexpr (is_any<std::monostate, Ts...>) return std::get_if<std::monostate>(&x) != nullptr;
    }
    return false;
}

template<typename T, typename... Ts>
auto as( std::variant<Ts...> const& x ) {
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 0>(x)), T >) { if (x.index() ==  0) return operator_as<0>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 1>(x)), T >) { if (x.index() ==  1) return operator_as<1>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 2>(x)), T >) { if (x.index() ==  2) return operator_as<2>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 3>(x)), T >) { if (x.index() ==  3) return operator_as<3>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 4>(x)), T >) { if (x.index() ==  4) return operator_as<4>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 5>(x)), T >) { if (x.index() ==  5) return operator_as<5>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 6>(x)), T >) { if (x.index() ==  6) return operator_as<6>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 7>(x)), T >) { if (x.index() ==  7) return operator_as<7>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 8>(x)), T >) { if (x.index() ==  8) return operator_as<8>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as< 9>(x)), T >) { if (x.index() ==  9) return operator_as<9>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<10>(x)), T >) { if (x.index() == 10) return operator_as<0>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<11>(x)), T >) { if (x.index() == 11) return operator_as<1>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<12>(x)), T >) { if (x.index() == 12) return operator_as<2>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<13>(x)), T >) { if (x.index() == 13) return operator_as<3>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<14>(x)), T >) { if (x.index() == 14) return operator_as<4>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<15>(x)), T >) { if (x.index() == 15) return operator_as<5>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<16>(x)), T >) { if (x.index() == 16) return operator_as<6>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<17>(x)), T >) { if (x.index() == 17) return operator_as<7>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<18>(x)), T >) { if (x.index() == 18) return operator_as<8>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<19>(x)), T >) { if (x.index() == 19) return operator_as<9>(x); }
    throw std::bad_variant_access();
}


//-------------------------------------------------------------------------------------------------------------
//  std::any is and as
//

//  is Type
//
template<typename T, typename X>
    requires (std::is_same_v<X,std::any> && !std::is_same_v<T,std::any> && !std::is_same_v<T,empty>)
constexpr auto is( X const& x ) -> bool
    { return x.type() == typeid(T); }

template<typename T, typename X>
    requires (std::is_same_v<X,std::any> && std::is_same_v<T,empty>)
constexpr auto is( X const& x ) -> bool
    { return !x.has_value(); }


//  is Value
//
inline constexpr auto is( std::any const& x, auto const& value ) -> bool
{
    //  Predicate case
    if constexpr (requires{ bool{ value(x) }; }) {
        return value(x);
    }
    else if constexpr (std::is_function_v<decltype(value)> || requires{ &value.operator(); }) {
        return false;
    }

    //  Value case
    else if constexpr (requires{ bool{ *std::any_cast<CPP2_TYPEOF(value)>(&x) == value }; }) {
        auto pvalue = std::any_cast<CPP2_TYPEOF(value)>(&x);
        return pvalue && *pvalue == value;
    }
    //  else
    return false;
}


//  as
//
template<typename T, typename X>
    requires (!std::is_reference_v<T> && std::is_same_v<X,std::any> && !std::is_same_v<T,std::any>)
constexpr auto as( X const& x ) -> T
    { return std::any_cast<T>( x ); }


//-------------------------------------------------------------------------------------------------------------
//  std::optional is and as
//

//  is Type
//
template<typename T, typename X>
    requires std::is_same_v<X,std::optional<T>>
constexpr auto is( X const& x ) -> bool
    { return x.has_value(); }

template<typename T, typename U>
    requires std::is_same_v<T,empty>
constexpr auto is( std::optional<U> const& x ) -> bool
    { return !x.has_value(); }


//  is Value
//
template<typename T>
constexpr auto is( std::optional<T> const& x, auto const& value ) -> bool
{
    //  Predicate case
    if constexpr (requires{ bool{ value(x) }; }) {
        return value(x);
    }
    else if constexpr (std::is_function_v<decltype(value)> || requires{ &value.operator(); }) {
        return false;
    }

    //  Value case
    else if constexpr (requires{ bool{ x.value() == value }; }) {
        return x.has_value() && x.value() == value;
    }
    return false;
}


//  as
//
template<typename T, typename X>
    requires std::is_same_v<X,std::optional<T>>
constexpr auto as( X const& x ) -> decltype(auto)
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

inline auto to_string(std::any const&) -> std::string {
    return "std::any";
}

template<typename T>
inline auto to_string(T const& t) -> std::string
    requires requires { std::to_string(t); }
{
    return std::to_string(t);
}

inline auto to_string(char const* s) -> std::string
{
    return std::string{s};
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
template<typename T, typename D>
class c_raii {
    T t;
    D dtor;
public:
    c_raii( T t_, D d )
        : t{ t_ }
        , dtor{ d }
    { }

    ~c_raii() { dtor(t); }

    operator T&() { return t; }

    c_raii(c_raii const&)         = delete;
    auto operator=(c_raii const&) = delete;
};

inline auto fopen( const char* filename, const char* mode ) {

    //  Suppress annoying deprecation warning about fopen
    #ifdef _MSC_VER
        #pragma warning( push )
        #pragma warning( disable : 4996 )
    #endif

    auto x = std::fopen(filename, mode);

    #ifdef _MSC_VER
        #pragma warning( pop )
    #endif

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
