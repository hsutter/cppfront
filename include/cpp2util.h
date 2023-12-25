
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

#ifndef CPP2_UTIL_H
#define CPP2_UTIL_H

//  If this implementation doesn't support source_location yet, disable it
#include <version>
#if !defined(_MSC_VER) && !defined(__cpp_lib_source_location)
    #undef CPP2_USE_SOURCE_LOCATION
#endif

//  If the cppfront user requested making the entire C++ standard library
//  available via module import or header include, do that
#if defined(CPP2_IMPORT_STD) || defined(CPP2_INCLUDE_STD)

    //  If C++23 'import std;' was requested and is available, use that
    #if defined(CPP2_IMPORT_STD) && defined(__cpp_lib_modules)

        #ifndef _MSC_VER
            //  This is the ideal -- note that we just voted "import std;"
            //  into draft C++23 in late July 2022, so implementers haven't
            //  had time to catch up yet
            import std;
        #else // MSVC
            //  Note: When C++23 "import std;" is available, we will switch to that here
            //  In the meantime, this is what works on MSVC which is the only compiler
            //  I've been able to get access to that implements modules enough to demo
            //  (but we'll have more full-C++20 compilers soon!)
            #ifdef _MSC_VER
                #include "intrin.h"
            #endif
            import std.core;
            import std.filesystem;
            import std.memory;
            import std.regex;
            import std.threading;

            //  Suppress spurious MSVC modules warning
            #pragma warning(disable:5050)
        #endif

    //  Otherwise, as a fallback if 'import std;' was requested, or else
    //  because 'include all std' was requested, include all the standard
    //  headers, with a feature test #ifdef for each header that
    //  isn't yet supported by all of { VS 2022, g++-10, clang++-12 }
    #else
        #ifdef _MSC_VER
            #include "intrin.h"
        #endif
        #include <algorithm>
        #include <any>
        #include <array>
        #include <atomic>
        #ifdef __cpp_lib_barrier
            #include <barrier>
        #endif
        #include <bit>
        #include <bitset>
        #include <cassert>
        #include <cctype>
        #include <cerrno>
        #include <cfenv>
        #include <cfloat>
        #include <charconv>
        #include <chrono>
        #include <cinttypes>
        #include <climits>
        #include <clocale>
        #include <cmath>
        #include <codecvt>
        #include <compare>
        #include <complex>
        #include <concepts>
        #include <condition_variable>
        #ifdef __cpp_lib_coroutine
            #include <coroutine>
        #endif
        #include <csetjmp>
        #include <csignal>
        #include <cstdarg>
        #include <cstddef>
        #include <cstdint>
        #include <cstdio>
        #include <cstdlib>
        #include <cstring>
        #include <ctime>
        #if __has_include(<cuchar>)
            #include <cuchar>
        #endif
        #include <cwchar>
        #include <cwctype>
        #include <deque>
        #ifndef CPP2_NO_EXCEPTIONS
            #include <exception>
        #endif
        // libstdc++ currently has a dependency on linking TBB if <execution> is
        // included, and TBB seems to be not automatically installed and linkable
        // on some GCC installations, so let's not pull in that little-used header
        // in our -pure-cpp2 "import std;" simulation mode... if you need this,
        // use mixed mode (not -pure-cpp2) and #include all the headers you need
        // including this one
        //
        // #include <execution>
        #ifdef __cpp_lib_expected
            #include <expected>
        #endif
        #include <filesystem>
        #if defined(__cpp_lib_format) || (defined(_MSC_VER) && _MSC_VER >= 1929)
            #include <format>
        #endif
        #ifdef __cpp_lib_flat_map
            #include <flat_map>
        #endif
        #ifdef __cpp_lib_flat_set
            #include <flat_set>
        #endif
        #include <forward_list>
        #include <fstream>
        #include <functional>
        #include <future>
        #ifdef __cpp_lib_generator
            #include <generator>
        #endif
        #include <initializer_list>
        #include <iomanip>
        #include <ios>
        #include <iosfwd>
        #include <iostream>
        #include <iso646.h>
        #include <istream>
        #include <iterator>
        #ifdef __cpp_lib_latch
            #include <latch>
        #endif
        #include <limits>
        #include <list>
        #include <locale>
        #include <map>
        #ifdef __cpp_lib_mdspan
            #include <mdspan>
        #endif
        #include <memory>
        #ifdef __cpp_lib_memory_resource
            #include <memory_resource>
        #endif
        #include <mutex>
        #include <new>
        #include <numbers>
        #include <numeric>
        #include <optional>
        #include <ostream>
        #ifdef __cpp_lib_print
            #include <print>
        #endif
        #include <queue>
        #include <random>
        #include <ranges>
        #include <ratio>
        #include <regex>
        #include <scoped_allocator>
        #ifdef __cpp_lib_semaphore
            #include <semaphore>
        #endif
        #include <set>
        #include <shared_mutex>
        #ifdef __cpp_lib_source_location
            #include <source_location>
        #endif
        #include <span>
        #ifdef __cpp_lib_spanstream
            #include <spanstream>
        #endif
        #include <sstream>
        #include <stack>
        #ifdef __cpp_lib_stacktrace
            #include <stacktrace>
        #endif
        #ifdef __cpp_lib_stdatomic_h
            #include <stdatomic.h>
        #endif
        #include <stdexcept>
        #if __has_include(<stdfloat>)
            #include <stdfloat>
        #endif
        #ifdef __cpp_lib_jthread
            #include <stop_token>
        #endif
        #include <streambuf>
        #include <string>
        #include <string_view>
        #ifdef __cpp_lib_syncstream
            #include <syncstream>
        #endif
        #include <system_error>
        #include <thread>
        #include <tuple>
        #include <type_traits>
        #include <typeindex>
        #ifndef CPP2_NO_RTTI
            #include <typeinfo>
        #endif
        #include <unordered_map>
        #include <unordered_set>
        #include <utility>
        #include <valarray>
        #include <variant>
        #include <vector>
    #endif

//  Otherwise, just #include the facilities used in this header
#else
    #ifdef _MSC_VER
        #include "intrin.h"
    #endif
    #include <algorithm>
    #include <any>
    #include <compare>
    #include <concepts>
    #include <cstddef>
    #include <cstdint>
    #include <cstdio>
    #ifndef CPP2_NO_EXCEPTIONS
        #include <exception>
    #endif
    #if defined(__cpp_lib_format) || (defined(_MSC_VER) && _MSC_VER >= 1929)
        #include <format>
    #endif
    #include <functional>
    #include <iostream>
    #include <iterator>
    #include <limits>
    #include <memory>
    #include <new>
    #include <random>
    #include <optional>
    #if defined(CPP2_USE_SOURCE_LOCATION)
        #include <source_location>
    #endif
    #include <span>
    #include <string>
    #include <string_view>
    #include <system_error>
    #include <tuple>
    #include <type_traits>
    #ifndef CPP2_NO_RTTI
        #include <typeinfo>
    #endif
    #include <utility>
    #include <variant>
    #include <vector>
#endif


#define CPP2_TYPEOF(x)              std::remove_cvref_t<decltype(x)>
#define CPP2_FORWARD(x)             std::forward<decltype(x)>(x)
#define CPP2_PACK_EMPTY(x)          (sizeof...(x) == 0)
#define CPP2_CONTINUE_BREAK(NAME)   goto CONTINUE_##NAME; CONTINUE_##NAME: continue; goto BREAK_##NAME; BREAK_##NAME: break;
                                    // these redundant goto's to avoid 'unused label' warnings


#if defined(_MSC_VER)
   // MSVC can't handle 'inline constexpr' yet in all cases
    #define CPP2_CONSTEXPR const
#else
    #define CPP2_CONSTEXPR constexpr
#endif


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

//  Discouraged: Variable precision names
//                 short
using ushort     = unsigned short;
//                 int
using uint       = unsigned int;
//                 long
using ulong      = unsigned long;
using longlong   = long long;
using ulonglong  = unsigned long long;
using longdouble = long double;

//  Strongly discouraged, for compatibility/interop only
using _schar     = signed char;      // normally use i8 instead
using _uchar     = unsigned char;    // normally use u8 instead


//-----------------------------------------------------------------------
//
//  General helpers
//
//-----------------------------------------------------------------------
//

inline constexpr auto max(auto... values) {
    return std::max( { values... } );
}

template <class T, class... Ts>
inline constexpr auto is_any = std::disjunction_v<std::is_same<T, Ts>...>;

template <std::size_t Len, std::size_t Align>
struct aligned_storage {
    alignas(Align) unsigned char data[Len];
};


//-----------------------------------------------------------------------
//
//  String: A helper workaround for passing a string literal as a
//  template argument
//
//-----------------------------------------------------------------------
//
template<std::size_t N>
struct String
{
    constexpr String(const char (&str)[N])
    {
        std::copy_n(str, N, value);
    }

    auto operator<=>(String const&) const = default;

    char value[N] = {};
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
#define CPP2_CONTRACT_MSG   cpp2::message_to_cstr_adapter

auto message_to_cstr_adapter( CPP2_MESSAGE_PARAM msg ) -> CPP2_MESSAGE_PARAM { return msg ? msg : ""; }
auto message_to_cstr_adapter( std::string const& msg ) -> CPP2_MESSAGE_PARAM { return msg.c_str(); }

class contract_group {
public:
    using handler = void (*)(CPP2_MESSAGE_PARAM msg CPP2_SOURCE_LOCATION_PARAM);

    constexpr contract_group  (handler h = {}) : reporter{h} { }
    constexpr auto set_handler(handler h = {}) { reporter = h; }
    constexpr auto get_handler() const -> handler { return reporter; }
    constexpr auto has_handler() const -> bool    { return reporter != handler{}; }

    constexpr auto enforce(bool b, CPP2_MESSAGE_PARAM msg = "" CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT)
                                          -> void { if (!b) report_violation(msg CPP2_SOURCE_LOCATION_ARG); }
    constexpr auto report_violation(CPP2_MESSAGE_PARAM msg = "" CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT)
                                          -> void { if (reporter) reporter(msg CPP2_SOURCE_LOCATION_ARG); }
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
    if (msg && msg[0] != '\0') {
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
auto assert_not_null(auto&& p CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> decltype(auto)
{
    //  NOTE: This "!= T{}" test may or may not work for STL iterators. The standard
    //        doesn't guarantee that using == and != will reliably report whether an
    //        STL iterator has the default-constructed value. So use it only for raw *...
    if constexpr (std::is_pointer_v<CPP2_TYPEOF(p)>) {
        if (p == CPP2_TYPEOF(p){}) {
            Null.report_violation("dynamic null dereference attempt detected" CPP2_SOURCE_LOCATION_ARG);
        };
    }
    return CPP2_FORWARD(p);
}

//  Subscript bounds checking
//
auto assert_in_bounds_impl(auto&& x, auto&& arg CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> void
    requires (std::is_integral_v<CPP2_TYPEOF(arg)> &&
             requires { std::size(x); std::ssize(x); x[arg]; std::begin(x) + 2; })
{
    auto max = [&]() -> auto {
        if constexpr (std::is_signed_v<CPP2_TYPEOF(arg)>) { return std::ssize(x); }
        else { return std::size(x); }
    };
    auto msg = "out of bounds access attempt detected - attempted access at index " + std::to_string(arg) + ", ";
    if (max() > 0 ) {
        msg += "[min,max] range is [0," + std::to_string(max()-1) + "]";
    }
    else {
        msg += "but container is empty";
    }
    if (!(0 <= arg && arg < max())) {
        Bounds.report_violation(msg.c_str()  CPP2_SOURCE_LOCATION_ARG);
    }
}

auto assert_in_bounds_impl(auto&&, auto&& CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> void
{
}

#define CPP2_ASSERT_IN_BOUNDS(x, arg) (cpp2::assert_in_bounds_impl((x),(arg)), (x)[(arg)])


//-----------------------------------------------------------------------
//
//  Support wrappers that unblock using this file in environments that
//  disable EH or RTTI
//
//  Note: This is not endorsing disabling those features, it's just
//        recognizing that disabling them is popular (e.g., games, WASM)
//        and so we should remove a potential adoption blocker... only a
//        few features in this file depend on EH or RTTI anyway, and
//        wouldn't be exercised in such an environment anyway so there
//        is no real net loss here
//
//-----------------------------------------------------------------------
//

[[noreturn]] auto Throw(auto&& x, [[maybe_unused]] char const* msg) -> void {
#ifdef CPP2_NO_EXCEPTIONS
    auto err = std::string{"exceptions are disabled with -fno-exceptions - attempted to throw exception with type \"" + typeid(decltype(x)).name() + "\""};
    if (msg) {
        err += " and the message \"" + msg + "\"";
    }
    Type.report_violation( err );
    std::terminate();
#else
    throw CPP2_FORWARD(x);
#endif
}

inline auto Uncaught_exceptions() -> int {
#ifdef CPP2_NO_EXCEPTIONS
    return 0;
#else
    return std::uncaught_exceptions();
#endif
}

template<typename T>
auto Dynamic_cast( [[maybe_unused]] auto&& x ) -> decltype(auto) {
#ifdef CPP2_NO_RTTI
    Type.report_violation( "'as' dynamic casting is disabled with -fno-rtti" );
    return nullptr;
#else
    return dynamic_cast<T>(CPP2_FORWARD(x));
#endif
}

template<typename T>
auto Typeid() -> decltype(auto) {
#ifdef CPP2_NO_RTTI
    Type.report_violation( "'any' dynamic casting is disabled with -fno-rtti" );
#else
    return typeid(T);
#endif
}

auto Typeid( [[maybe_unused]] auto&& x ) -> decltype(auto) {
#ifdef CPP2_NO_RTTI
    Type.report_violation( "'typeid' is disabled with -fno-rtti" );
#else
    return typeid(CPP2_FORWARD(x));
#endif
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
        //  Prefer { } to ( ) so that initializing a vector<int> with
        //  (10), (10, 20), and (10, 20, 30) is consistent
        if constexpr (requires { T{CPP2_FORWARD(args)...}; }) {
            //  This is because apparently make_unique can't deal with list
            //  initialization of aggregates, even after P0960
            return std::unique_ptr<T>( new T{CPP2_FORWARD(args)...} );
        }
        else {
            return std::make_unique<T>(CPP2_FORWARD(args)...);
        }
    }
} inline unique;

[[maybe_unused]] struct {
    template<typename T>
    [[nodiscard]] auto cpp2_new(auto&& ...args) const -> std::shared_ptr<T> {
        //  Prefer { } to ( ) as noted for unique.new
        //
        //  Note this does mean we don't get the make_shared optimization a lot
        //  of the time -- we can restore that as soon as make_shared improves to
        //  allow list initialization. But the make_shared optimization isn't a
        //  huge deal anyway: it saves one allocation, but most of the cost of
        //  shared_ptrs is copying them and the allocation cost saving is probably
        //  outweighed by just a couple of shared_ptr copies; also, the make_shared
        //  optimization has the potential downside of keeping the raw storage
        //  alive longer when there are weak_ptrs. So, yes, we can and should
        //  restore the make_shared optimization as soon as make_shared supports
        //  list init, but I don't think it's all that important AFAIK
        if constexpr (requires { T{CPP2_FORWARD(args)...}; }) {
            //  Why this calls 'unique.new': The workaround to use { } initialization
            //  requires calling naked 'new' to allocate the object separately anyway,
            //  so reuse the unique.new path that already does that (less code
            //  duplication, plus encapsulate the naked 'new' in one place)
            return unique.cpp2_new<T>(CPP2_FORWARD(args)...);
        }
        else {
            return std::make_shared<T>(CPP2_FORWARD(args)...);
        }
    }
} inline shared;

template<typename T>
[[nodiscard]] auto cpp2_new(auto&& ...args) -> std::unique_ptr<T> {
    return unique.cpp2_new<T>(CPP2_FORWARD(args)...);
}


//-----------------------------------------------------------------------
//
//  in<T>       For "in" parameter
//
//-----------------------------------------------------------------------
//
template<typename T>
constexpr bool prefer_pass_by_value =
    sizeof(T) <= 2*sizeof(void*)
    && std::is_trivially_copy_constructible_v<T>;

template<typename T>
    requires std::is_class_v<T> || std::is_union_v<T> || std::is_array_v<T> || std::is_function_v<T>
constexpr bool prefer_pass_by_value<T> = false;

template<typename T>
    requires (!std::is_void_v<T>)
using in =
    std::conditional_t <
        prefer_pass_by_value<T>,
        T const,
        T const&
    >;


//-----------------------------------------------------------------------
//
//  Initialization: These are closely related...
//
//  deferred_init<T>    For deferred-initialized local object
//
//  out<T>              For out parameter
//
//-----------------------------------------------------------------------
//
template<typename T>
class deferred_init {
    alignas(T) std::byte data[sizeof(T)];
    bool init = false;

    auto t() -> T& { return *std::launder(reinterpret_cast<T*>(&data)); }

    template<typename U>
    friend class out;

    auto destroy() -> void         { if (init) { t().~T(); }  init = false; }

public:
    deferred_init() noexcept       { }
   ~deferred_init() noexcept       { destroy(); }
    auto value()    noexcept -> T& { Default.enforce(init);  return t(); }

    auto construct(auto&& ...args) -> void { Default.enforce(!init);  new (&data) T{CPP2_FORWARD(args)...};  init = true; }
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
    int  uncaught_count   = Uncaught_exceptions();
    //  ... but all in a chain share the topmost called_construct_
    bool called_construct_ = false;

public:
    out(T*                 t_) noexcept :  t{ t_}, has_t{true}       { Default.enforce( t); }
    out(deferred_init<T>* dt_) noexcept : dt{dt_}, has_t{false}      { Default.enforce(dt); }
    out(out<T>*           ot_) noexcept : ot{ot_}, has_t{ot_->has_t} { Default.enforce(ot);
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
        if (called_construct() && uncaught_count != Uncaught_exceptions()) {
            Default.enforce(!has_t);
            dt->destroy();
            called_construct() = false;
        }
    }

    auto construct(auto&& ...args) -> void {
        if (has_t || called_construct()) {
            if constexpr (requires { *t = T(CPP2_FORWARD(args)...); }) {
                Default.enforce( t );
                *t = T(CPP2_FORWARD(args)...);
            }
            else {
                Default.report_violation("attempted to copy assign, but copy assignment is not available");
            }
        }
        else {
            Default.enforce( dt );
            if (dt->init) {
                if constexpr (requires { *t = T(CPP2_FORWARD(args)...); }) {
                    dt->value() = T(CPP2_FORWARD(args)...);
                }
                else {
                    Default.report_violation("attempted to copy assign, but copy assignment is not available");
                }
            }
            else {
                dt->construct(CPP2_FORWARD(args)...);
                called_construct() = true;
            }
        }
    }

    auto value() noexcept -> T& {
        if (has_t) {
            Default.enforce( t );
            return *t;
        }
        else {
            Default.enforce( dt );
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
// Workaround <https://github.com/llvm/llvm-project/issues/70556>.
#define CPP2_FORCE_INLINE_LAMBDA_CLANG /* empty */

#if defined(_MSC_VER) && !defined(__clang_major__)
    #define CPP2_FORCE_INLINE              __forceinline
    #define CPP2_FORCE_INLINE_LAMBDA       [[msvc::forceinline]]
    #define CPP2_LAMBDA_NO_DISCARD
#else
    #define CPP2_FORCE_INLINE              __attribute__((always_inline))
    #if defined(__clang__)
        #define CPP2_FORCE_INLINE_LAMBDA       /* empty */
        #undef CPP2_FORCE_INLINE_LAMBDA_CLANG
        #define CPP2_FORCE_INLINE_LAMBDA_CLANG __attribute__((always_inline))
    #else
        #define CPP2_FORCE_INLINE_LAMBDA       __attribute__((always_inline))
    #endif

    #if defined(__clang_major__)
        //  Also check __cplusplus, only to satisfy Clang -pedantic-errors
        #if __cplusplus >= 202302L && (__clang_major__ > 13 || (__clang_major__ == 13 && __clang_minor__ >= 2))
            #define CPP2_LAMBDA_NO_DISCARD   [[nodiscard]]
        #else
            #define CPP2_LAMBDA_NO_DISCARD
        #endif
    #elif defined(__GNUC__)
        #if __GNUC__ >= 9
            #define CPP2_LAMBDA_NO_DISCARD   [[nodiscard]]
        #else
            #define CPP2_LAMBDA_NO_DISCARD
        #endif
        #if ((__GNUC__ * 100) + __GNUC_MINOR__) < 1003
            //  GCC 10.2 doesn't support this feature (10.3 is fine)
            #undef  CPP2_FORCE_INLINE_LAMBDA
            #define CPP2_FORCE_INLINE_LAMBDA
        #endif
    #else
        #define CPP2_LAMBDA_NO_DISCARD
    #endif
#endif

#define CPP2_UFCS_REMPARENS(...) __VA_ARGS__

// Ideally, the expression `CPP2_UFCS_IS_NOTHROW` expands to
// is in the _noexcept-specifier_ of the UFCS lambda, but without 'std::declval'.
// To workaround [GCC bug 101043](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=101043),
// we instead make it a template parameter of the UFCS lambda.
// But using a template parameter, Clang also ICEs on an application.
// So we use these `NOTHROW` macros to fall back to the ideal for when not using GCC.
#define CPP2_UFCS_IS_NOTHROW(QUALID,TEMPKW,...) \
   requires { requires  requires { std::declval<Obj>().CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(std::declval<Params>()...); }; \
              requires    noexcept(std::declval<Obj>().CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(std::declval<Params>()...)); } \
|| requires { requires !requires { std::declval<Obj>().CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(std::declval<Params>()...); }; \
              requires noexcept(CPP2_UFCS_REMPARENS QUALID __VA_ARGS__(std::declval<Obj>(), std::declval<Params>()...)); }
#define CPP2_UFCS_IS_NOTHROW_PARAM(...)               /*empty*/
#define CPP2_UFCS_IS_NOTHROW_ARG(QUALID,TEMPKW,...)   CPP2_UFCS_IS_NOTHROW(QUALID,TEMPKW,__VA_ARGS__)
#if defined(__GNUC__) && !defined(__clang__)
    #undef  CPP2_UFCS_IS_NOTHROW_PARAM
    #undef  CPP2_UFCS_IS_NOTHROW_ARG
    #define CPP2_UFCS_IS_NOTHROW_PARAM(QUALID,TEMPKW,...) , bool IsNothrow = CPP2_UFCS_IS_NOTHROW(QUALID,TEMPKW,__VA_ARGS__)
    #define CPP2_UFCS_IS_NOTHROW_ARG(...)                 IsNothrow
    #if __GNUC__ < 11
        #undef  CPP2_UFCS_IS_NOTHROW_PARAM
        #undef  CPP2_UFCS_IS_NOTHROW_ARG
        #define CPP2_UFCS_IS_NOTHROW_PARAM(...)    /*empty*/
        #define CPP2_UFCS_IS_NOTHROW_ARG(...)      false // GCC 10 UFCS is always potentially-throwing.
    #endif
#endif

// Ideally, the expression `CPP2_UFCS_CONSTRAINT_ARG` expands to
// is in the _requires-clause_ of the UFCS lambda.
// To workaround an MSVC bug within a member function 'F' where UFCS is also for 'F'
// (<https://github.com/hsutter/cppfront/pull/506#issuecomment-1826086952>),
// we instead make it a template parameter of the UFCS lambda.
// But using a template parameter, Clang also ICEs and GCC rejects a local 'F'.
// Also, Clang rejects the SFINAE test case when using 'std::declval'.
// So we use these `CONSTRAINT` macros to fall back to the ideal for when not using MSVC.
#define CPP2_UFCS_CONSTRAINT_PARAM(...)               /*empty*/
#define CPP2_UFCS_CONSTRAINT_ARG(QUALID,TEMPKW,...) \
   requires { CPP2_FORWARD(obj).CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(CPP2_FORWARD(params)...); } \
|| requires { CPP2_UFCS_REMPARENS QUALID __VA_ARGS__(CPP2_FORWARD(obj), CPP2_FORWARD(params)...); }
#if defined(_MSC_VER)
    #undef  CPP2_UFCS_CONSTRAINT_PARAM
    #undef  CPP2_UFCS_CONSTRAINT_ARG
    #define CPP2_UFCS_CONSTRAINT_PARAM(QUALID,TEMPKW,...) , bool IsViable = \
   requires { std::declval<Obj>().CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(std::declval<Params>()...); } \
|| requires { CPP2_UFCS_REMPARENS QUALID __VA_ARGS__(std::declval<Obj>(), std::declval<Params>()...); }
    #define CPP2_UFCS_CONSTRAINT_ARG(...)                 IsViable
#endif

#define CPP2_UFCS_(LAMBDADEFCAPT,QUALID,TEMPKW,...) \
[LAMBDADEFCAPT]< \
    typename Obj, typename... Params \
    CPP2_UFCS_IS_NOTHROW_PARAM(QUALID,TEMPKW,__VA_ARGS__) \
    CPP2_UFCS_CONSTRAINT_PARAM(QUALID,TEMPKW,__VA_ARGS__) \
  > \
  CPP2_LAMBDA_NO_DISCARD (Obj&& obj, Params&& ...params) CPP2_FORCE_INLINE_LAMBDA_CLANG \
  noexcept(CPP2_UFCS_IS_NOTHROW_ARG(QUALID,TEMPKW,__VA_ARGS__)) CPP2_FORCE_INLINE_LAMBDA -> decltype(auto) \
    requires CPP2_UFCS_CONSTRAINT_ARG(QUALID,TEMPKW,__VA_ARGS__) { \
    if constexpr (requires{ CPP2_FORWARD(obj).CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(CPP2_FORWARD(params)...); }) { \
        return CPP2_FORWARD(obj).CPP2_UFCS_REMPARENS QUALID TEMPKW __VA_ARGS__(CPP2_FORWARD(params)...); \
    } else { \
        return CPP2_UFCS_REMPARENS QUALID __VA_ARGS__(CPP2_FORWARD(obj), CPP2_FORWARD(params)...); \
    } \
}

#define CPP2_UFCS(...)                                    CPP2_UFCS_(&,(),,__VA_ARGS__)
#define CPP2_UFCS_TEMPLATE(...)                           CPP2_UFCS_(&,(),template,__VA_ARGS__)
#define CPP2_UFCS_QUALIFIED_TEMPLATE(QUALID,...)          CPP2_UFCS_(&,QUALID,template,__VA_ARGS__)
#define CPP2_UFCS_NONLOCAL(...)                           CPP2_UFCS_(,(),,__VA_ARGS__)
#define CPP2_UFCS_TEMPLATE_NONLOCAL(...)                  CPP2_UFCS_(,(),template,__VA_ARGS__)
#define CPP2_UFCS_QUALIFIED_TEMPLATE_NONLOCAL(QUALID,...) CPP2_UFCS_(,QUALID,template,__VA_ARGS__)


//-----------------------------------------------------------------------
//
//  to_string for string interpolation
//
//-----------------------------------------------------------------------
//
//  For use when returning "no such thing", such as
//  when customizing "as" for std::variant
struct nonesuch_ {
    auto operator==(auto const&) -> bool { return false; }
};
constexpr inline nonesuch_ nonesuch;

inline auto to_string(...) -> std::string
{
    return "(customize me - no cpp2::to_string overload exists for this type)";
}

inline auto to_string(nonesuch_) -> std::string
{
    return "(invalid type)";
}

inline auto to_string(std::same_as<std::any> auto const&) -> std::string
{
    return "std::any";
}

inline auto to_string(bool b) -> std::string
{
    return b ? "true" : "false";
}

template<typename T>
inline auto to_string(T const& t) -> std::string
    requires requires { std::to_string(t); }
{
    return std::to_string(t);
}

inline auto to_string(char const& t) -> std::string
{
    return std::string{t};
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

//  MSVC supports it but doesn't define __cpp_lib_format until the ABI stablizes, but here
//  don't care about that, so consider it as supported since VS 2019 16.10 (_MSC_VER 1929)
#if defined(__cpp_lib_format) || (defined(_MSC_VER) && _MSC_VER >= 1929)
inline auto to_string(auto&& value, std::string_view fmt) -> std::string
{
    return std::vformat(fmt, std::make_format_args(CPP2_FORWARD(value)));
}
#else
inline auto to_string(auto&& value, std::string_view) -> std::string
{
    //  This Cpp1 implementation does not support <format>-ted string interpolation
    //  so the best we can do is ignore the formatting request (degraded operation
    //  seems better than a dynamic error message string or a hard error)
    return to_string(CPP2_FORWARD(value));
}
#endif


//-----------------------------------------------------------------------
//
//  is and as
//
//-----------------------------------------------------------------------
//

//-------------------------------------------------------------------------------------------------------------
//  Built-in is
//

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
    return Dynamic_cast<C const*>(&x) != nullptr;
}

template< typename C, typename X >
    requires (
        ( std::is_base_of_v<X, C> ||
          ( std::is_polymorphic_v<C> && std::is_polymorphic_v<X>)
        ) && !std::is_same_v<C,X>)
auto is( X const* x ) -> bool {
    return Dynamic_cast<C const*>(x) != nullptr;
}

template< typename C, typename X >
    requires (requires (X x) { *x; X(); } && std::is_same_v<C, empty>)
auto is( X const& x ) -> bool {
    return x == X();
}


//  Values
//
inline constexpr auto is( auto const& x, auto&& value ) -> bool
{
    //  Value with customized operator_is case
    if constexpr (requires{ x.op_is(value); }) {
        return x.op_is(value);
    }

    //  Predicate case
    else if constexpr (requires{ bool{ value(x) }; }) {
        return value(x);
    }
    else if constexpr (std::is_function_v<decltype(value)> || requires{ &value.operator(); }) {
        return false;
    }

    //  Value equality case
    else if constexpr (requires{ bool{x == value}; }) {
        return x == value;
    }
    return false;
}


//-------------------------------------------------------------------------------------------------------------
//  Built-in as
//

//  The 'as' cast functions are <To, From> so use that order here
//  If it's confusing, we can switch this to <From, To>
template< typename To, typename From >
inline constexpr auto is_narrowing_v =
    // [dcl.init.list] 7.1
    (std::is_floating_point_v<From> && std::is_integral_v<To>) ||
    // [dcl.init.list] 7.2
    (std::is_floating_point_v<From> && std::is_floating_point_v<To> && sizeof(From) > sizeof(To)) ||
    // [dcl.init.list] 7.3
    (std::is_integral_v<From> && std::is_floating_point_v<To>) ||
    (std::is_enum_v<From> && std::is_floating_point_v<To>) ||
    // [dcl.init.list] 7.4
    (std::is_integral_v<From> && std::is_integral_v<To> && sizeof(From) > sizeof(To)) ||
    (std::is_enum_v<From> && std::is_integral_v<To> && sizeof(From) > sizeof(To)) ||
    // [dcl.init.list] 7.5
    (std::is_pointer_v<From> && std::is_same_v<To, bool>);

template <typename... Ts>
inline constexpr auto program_violates_type_safety_guarantee = sizeof...(Ts) < 0;

//  For literals we can check for safe 'narrowing' at a compile time (e.g., 1 as std::size_t)
template< typename C, auto x >
inline constexpr bool is_castable_v =
    std::is_integral_v<C> &&
    std::is_integral_v<CPP2_TYPEOF(x)> &&
    !(static_cast<CPP2_TYPEOF(x)>(static_cast<C>(x)) != x ||
        (
            (std::is_signed_v<C> != std::is_signed_v<CPP2_TYPEOF(x)>) &&
            ((static_cast<C>(x) < C{}) != (x < CPP2_TYPEOF(x){}))
        )
    );

//  As
//

template< typename C >
auto as(auto const&) -> auto {
    return nonesuch;
}

template< typename C, auto x >
    requires (std::is_arithmetic_v<C> && std::is_arithmetic_v<CPP2_TYPEOF(x)>)
inline constexpr auto as() -> auto
{
    if constexpr ( is_castable_v<C, x> ) {
        return static_cast<C>(x);
    } else {
        return nonesuch;
    }
}

template< typename C >
inline constexpr auto as(auto const& x) -> auto
    requires (
        std::is_floating_point_v<C> &&
        std::is_floating_point_v<CPP2_TYPEOF(x)> &&
        sizeof(CPP2_TYPEOF(x)) > sizeof(C)
    )
{
    return nonesuch;
}

//  Signed/unsigned conversions to a not-smaller type are handled as a precondition,
//  and trying to cast from a value that is in the half of the value space that isn't
//  representable in the target type C is flagged as a Type safety contract violation
template< typename C >
inline constexpr auto as(auto const& x CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> auto
    requires (
        std::is_integral_v<C> &&
        std::is_integral_v<CPP2_TYPEOF(x)> &&
        std::is_signed_v<CPP2_TYPEOF(x)> != std::is_signed_v<C> &&
        sizeof(CPP2_TYPEOF(x)) <= sizeof(C)
    )
{
    const C c = static_cast<C>(x);
    Type.enforce(   // precondition check: must be round-trippable => not lossy
        static_cast<CPP2_TYPEOF(x)>(c) == x && (c < C{}) == (x < CPP2_TYPEOF(x){}),
        "dynamic lossy narrowing conversion attempt detected" CPP2_SOURCE_LOCATION_ARG
    );
    return c;
}

template< typename C, typename X >
    requires std::is_same_v<C, X>
auto as( X const& x ) -> decltype(auto) {
    return x;
}

template< typename C, typename X >
    requires std::is_same_v<C, X>
auto as( X& x ) -> decltype(auto) {
    return x;
}


template< typename C, typename X >
auto as(X const& x) -> C
    requires (std::is_same_v<C, std::string> && std::is_integral_v<X>)
{
    return cpp2::to_string(x);
}


template< typename C, typename X >
auto as( X const& x ) -> auto
    requires (!std::is_same_v<C, X> && !std::is_base_of_v<C, X> && requires { C{x}; }
              && !(std::is_same_v<C, std::string> && std::is_integral_v<X>) // exclude above case
             )
{
    //  Experiment: Recognize the nested `::value_type` pattern for some dynamic library types
    //  like std::optional, and try to prevent accidental narrowing conversions even when
    //  those types themselves don't defend against them
    if constexpr( requires { requires std::is_convertible_v<X, typename C::value_type>; } ) {
        if constexpr( is_narrowing_v<typename C::value_type, X>) {
            return nonesuch;
        }
    }
    return C{x};
}

template< typename C, typename X >
    requires (std::is_base_of_v<C, X> && !std::is_same_v<C, X>)
auto as( X& x ) -> C& {
    return x;
}

template< typename C, typename X >
    requires (std::is_base_of_v<C, X> && !std::is_same_v<C, X>)
auto as( X const& x ) -> C const& {
    return x;
}

template< typename C, typename X >
    requires (std::is_base_of_v<X, C> && !std::is_same_v<C,X>)
auto as( X& x ) -> C& {
    return Dynamic_cast<C&>(x);
}

template< typename C, typename X >
    requires (std::is_base_of_v<X, C> && !std::is_same_v<C,X>)
auto as( X const& x ) -> C const& {
    return Dynamic_cast<C const&>(x);
}

template< typename C, typename X >
    requires (
        std::is_pointer_v<C>
        && std::is_pointer_v<X>
        && std::is_base_of_v<CPP2_TYPEOF(*std::declval<X>()), CPP2_TYPEOF(*std::declval<C>())>
        && !std::is_same_v<C, X>
    )
auto as( X x ) -> C {
    return Dynamic_cast<C>(x);
}


//-------------------------------------------------------------------------------------------------------------
//  std::variant is and as
//

//  Common internal helper
//
template<std::size_t I, typename... Ts>
constexpr auto operator_as( std::variant<Ts...> && x ) -> decltype(auto) {
    if constexpr (I < std::variant_size_v<std::variant<Ts...>>) {
        return std::get<I>( x );
    }
    else {
        return nonesuch;
    }
}

template<std::size_t I, typename... Ts>
constexpr auto operator_as( std::variant<Ts...> & x ) -> decltype(auto) {
    if constexpr (I < std::variant_size_v<std::variant<Ts...>>) {
        return std::get<I>( x );
    }
    else {
        return nonesuch;
    }
}

template<std::size_t I, typename... Ts>
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
constexpr auto is( std::variant<Ts...> const& x, auto&& value ) -> bool
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
auto as( std::variant<Ts...> && x ) -> decltype(auto) {
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
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<10>(x)), T >) { if (x.index() == 10) return operator_as<10>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<11>(x)), T >) { if (x.index() == 11) return operator_as<11>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<12>(x)), T >) { if (x.index() == 12) return operator_as<12>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<13>(x)), T >) { if (x.index() == 13) return operator_as<13>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<14>(x)), T >) { if (x.index() == 14) return operator_as<14>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<15>(x)), T >) { if (x.index() == 15) return operator_as<15>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<16>(x)), T >) { if (x.index() == 16) return operator_as<16>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<17>(x)), T >) { if (x.index() == 17) return operator_as<17>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<18>(x)), T >) { if (x.index() == 18) return operator_as<18>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<19>(x)), T >) { if (x.index() == 19) return operator_as<19>(x); }
    Throw( std::bad_variant_access(), "'as' cast failed for 'variant'");
}

template<typename T, typename... Ts>
auto as( std::variant<Ts...> & x ) -> decltype(auto) {
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
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<10>(x)), T >) { if (x.index() == 10) return operator_as<10>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<11>(x)), T >) { if (x.index() == 11) return operator_as<11>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<12>(x)), T >) { if (x.index() == 12) return operator_as<12>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<13>(x)), T >) { if (x.index() == 13) return operator_as<13>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<14>(x)), T >) { if (x.index() == 14) return operator_as<14>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<15>(x)), T >) { if (x.index() == 15) return operator_as<15>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<16>(x)), T >) { if (x.index() == 16) return operator_as<16>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<17>(x)), T >) { if (x.index() == 17) return operator_as<17>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<18>(x)), T >) { if (x.index() == 18) return operator_as<18>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<19>(x)), T >) { if (x.index() == 19) return operator_as<19>(x); }
    Throw( std::bad_variant_access(), "'as' cast failed for 'variant'");
}

template<typename T, typename... Ts>
auto as( std::variant<Ts...> const& x ) -> decltype(auto) {
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
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<10>(x)), T >) { if (x.index() == 10) return operator_as<10>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<11>(x)), T >) { if (x.index() == 11) return operator_as<11>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<12>(x)), T >) { if (x.index() == 12) return operator_as<12>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<13>(x)), T >) { if (x.index() == 13) return operator_as<13>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<14>(x)), T >) { if (x.index() == 14) return operator_as<14>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<15>(x)), T >) { if (x.index() == 15) return operator_as<15>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<16>(x)), T >) { if (x.index() == 16) return operator_as<16>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<17>(x)), T >) { if (x.index() == 17) return operator_as<17>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<18>(x)), T >) { if (x.index() == 18) return operator_as<18>(x); }
    if constexpr (std::is_same_v< CPP2_TYPEOF(operator_as<19>(x)), T >) { if (x.index() == 19) return operator_as<19>(x); }
    Throw( std::bad_variant_access(), "'as' cast failed for 'variant'");
}


//-------------------------------------------------------------------------------------------------------------
//  std::any is and as
//

//  is Type
//
template<typename T, typename X>
    requires (std::is_same_v<X,std::any> && !std::is_same_v<T,std::any> && !std::is_same_v<T,empty>)
constexpr auto is( X const& x ) -> bool
    { return x.type() == Typeid<T>(); }

template<typename T, typename X>
    requires (std::is_same_v<X,std::any> && std::is_same_v<T,empty>)
constexpr auto is( X const& x ) -> bool
    { return !x.has_value(); }


//  is Value
//
inline constexpr auto is( std::any const& x, auto&& value ) -> bool
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
constexpr auto is( std::optional<T> const& x, auto&& value ) -> bool
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
//  A variation of GSL's final_action_success / finally
//
//  finally ensures something is run at the end of a scope always
//
//  finally_success ensures something is run at the end of a scope
//      if no exception is thrown
//
//  finally_presuccess ensures a group of add'd operations are run
//      immediately before (not after) the return if no exception is
//      thrown - right now this is used only for postconditions, so
//      they can inspect named return values before they're moved from
//
//-----------------------------------------------------------------------
//

template <class F>
class finally_success
{
public:
    explicit finally_success(const F& ff) noexcept : f{ff} { }
    explicit finally_success(F&& ff) noexcept : f{std::move(ff)} { }

    ~finally_success() noexcept
    {
        if (invoke && ecount == std::uncaught_exceptions()) {
            f();
        }
    }

    finally_success(finally_success&& that) noexcept
        : f(std::move(that.f)), invoke(std::exchange(that.invoke, false))
    { }

    finally_success(finally_success const&) = delete;
    void operator= (finally_success const&) = delete;
    void operator= (finally_success&&)      = delete;

private:
    F f;
    int  ecount = std::uncaught_exceptions();
    bool invoke = true;
};


template <class F>
class finally
{
public:
    explicit finally(const F& ff) noexcept : f{ff} { }
    explicit finally(F&& ff) noexcept : f{std::move(ff)} { }

    ~finally() noexcept { f(); }

    finally(finally&& that) noexcept
        : f(std::move(that.f)), invoke(std::exchange(that.invoke, false))
    { }

    finally       (finally const&) = delete;
    void operator=(finally const&) = delete;
    void operator=(finally&&)      = delete;

private:
    F f;
    bool invoke = true;
};


class finally_presuccess
{
public:
    finally_presuccess() = default;

    auto add(const auto& f) { fs.push_back(f); }

    //  In compiled Cpp2 code, this function will be called
    //  immediately before 'return' (both explicit and implicit)
    auto run() {
        if (invoke && ecount == std::uncaught_exceptions()) {
            for (auto const& f : fs) {
                f();
            }
        }
        invoke = false;
    }

    ~finally_presuccess() noexcept {
        run();
    }

    finally_presuccess(finally_presuccess const&) = delete;
    void operator=    (finally_presuccess const&) = delete;
    void operator=    (finally_presuccess &&)     = delete;

private:
    std::vector<std::function<void()>> fs;
    int  ecount = std::uncaught_exceptions();
    bool invoke = true;
};


//-----------------------------------------------------------------------
//
//  args: see main() arguments as vector<string_view>
//
//-----------------------------------------------------------------------
//
struct args_t : std::vector<std::string_view>
{
    args_t(int c, char** v) : vector{static_cast<std::size_t>(c)}, argc{c}, argv{v} {}

    mutable int        argc = 0;        //  mutable for compatibility with frameworks that take 'int& argc'
    char**             argv = nullptr;
};

inline auto make_args(int argc, char** argv) -> args_t
{
    auto ret  = args_t{argc, argv};
    auto args = std::span(argv, static_cast<std::size_t>(argc));
    std::copy( args.begin(), args.end(), ret.data());
    return ret;
}


//-----------------------------------------------------------------------
//
//  alien_memory: memory typed as T but that is outside C++ and that the
//                compiler may not assume it knows anything at all about
//
//-----------------------------------------------------------------------
//
template<typename T>
using alien_memory = T volatile;


//-----------------------------------------------------------------------
//
//  An implementation of GSL's narrow_cast with a clearly 'unsafe' name
//
//-----------------------------------------------------------------------
//
template <typename C, typename X>
constexpr auto unsafe_narrow( X&& x ) noexcept -> decltype(auto)
{
    return static_cast<C>(CPP2_FORWARD(x));
}


//-----------------------------------------------------------------------
//
//  has_flags:  query whether a flag_enum value has all flags in 'flags' set
//
//  flags       set of flags to check
//
//  Returns a function object that takes a 'value' of the same type as
//  'flags', and evaluates to true if and only if 'value' has set all of
//  the bits set in 'flags'
//
//-----------------------------------------------------------------------
//
template <typename T>
auto has_flags(T flags)
{
    return [=](T value) { return (value & flags) == flags; };
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
        Throw( std::make_error_condition(std::errc::no_such_file_or_directory), "'fopen' attempt failed");
    }
    return c_raii( x, &std::fclose );
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


//-----------------------------------------------------------------------
//
//  Signed/unsigned comparison checks
//
//-----------------------------------------------------------------------
//
template<typename T, typename U>
CPP2_FORCE_INLINE constexpr auto cmp_mixed_signedness_check() -> void
{
    if constexpr (
        std::is_same_v<T, bool> ||
        std::is_same_v<U, bool>
        )
    {
        static_assert(
            program_violates_type_safety_guarantee<T, U>,
            "comparing bool values using < <= >= > is unsafe and not allowed - are you missing parentheses?");
    }
    else if constexpr (
        std::is_integral_v<T> &&
        std::is_integral_v<U> &&
        std::is_signed_v<T> != std::is_signed_v<U>
        )
    {
        //  Note: It's tempting here to "just call std::cmp_*() instead"
        //  which does signed/unsigned relational comparison correctly
        //  for negative values, and so silently "fix that for you." But
        //  doing that has security pitfalls for the reasons described at
        //  https://github.com/hsutter/cppfront/issues/220, so this
        //  static_assert to reject the comparison is the right way to go.
        static_assert(
            program_violates_type_safety_guarantee<T, U>,
            "mixed signed/unsigned comparison is unsafe - prefer using .ssize() instead of .size(), consider using std::cmp_less instead, or consider explicitly casting one of the values to change signedness by using 'as' or 'cpp2::unsafe_narrow'"
            );
    }
}


CPP2_FORCE_INLINE constexpr auto cmp_less(auto&& t, auto&& u) -> decltype(auto)
    requires requires {CPP2_FORWARD(t) < CPP2_FORWARD(u);}
{
    cmp_mixed_signedness_check<CPP2_TYPEOF(t), CPP2_TYPEOF(u)>();
    return CPP2_FORWARD(t) < CPP2_FORWARD(u);
}

CPP2_FORCE_INLINE constexpr auto cmp_less(auto&& t, auto&& u) -> decltype(auto)
{
    static_assert(
        program_violates_type_safety_guarantee<decltype(t), decltype(u)>,
        "attempted to compare '<' for incompatible types"
        );
    return nonesuch;
}


CPP2_FORCE_INLINE constexpr auto cmp_less_eq(auto&& t, auto&& u) -> decltype(auto)
    requires requires {CPP2_FORWARD(t) <= CPP2_FORWARD(u);}
{
    cmp_mixed_signedness_check<CPP2_TYPEOF(t), CPP2_TYPEOF(u)>();
    return CPP2_FORWARD(t) <= CPP2_FORWARD(u);
}

CPP2_FORCE_INLINE constexpr auto cmp_less_eq(auto&& t, auto&& u) -> decltype(auto)
{
    static_assert(
        program_violates_type_safety_guarantee<decltype(t), decltype(u)>,
        "attempted to compare '<=' for incompatible types"
        );
    return nonesuch;
}


CPP2_FORCE_INLINE constexpr auto cmp_greater(auto&& t, auto&& u) -> decltype(auto)
    requires requires {CPP2_FORWARD(t) > CPP2_FORWARD(u);}
{
    cmp_mixed_signedness_check<CPP2_TYPEOF(t), CPP2_TYPEOF(u)>();
    return CPP2_FORWARD(t) > CPP2_FORWARD(u);
}

CPP2_FORCE_INLINE constexpr auto cmp_greater(auto&& t, auto&& u) -> decltype(auto)
{
    static_assert(
        program_violates_type_safety_guarantee<decltype(t), decltype(u)>,
        "attempted to compare '>' for incompatible types"
        );
    return nonesuch;
}


CPP2_FORCE_INLINE constexpr auto cmp_greater_eq(auto&& t, auto&& u) -> decltype(auto)
    requires requires {CPP2_FORWARD(t) >= CPP2_FORWARD(u);}
{
    cmp_mixed_signedness_check<CPP2_TYPEOF(t), CPP2_TYPEOF(u)>();
    return CPP2_FORWARD(t) >= CPP2_FORWARD(u);
}

CPP2_FORCE_INLINE constexpr auto cmp_greater_eq(auto&& t, auto&& u) -> decltype(auto)
{
    static_assert(
        program_violates_type_safety_guarantee<decltype(t), decltype(u)>,
        "attempted to compare '>=' for incompatible types"
        );
    return nonesuch;
}



//-----------------------------------------------------------------------
//
//  A static-asserting "as" for better diagnostics than raw 'nonesuch'
//
//  Note for the future: This needs go after all 'as', which is fine for
//  the ones in this file but will have problems with further user-
//  defined 'as' customizations. One solution would be to make the main
//  'as' be a class template, and have all customizations be actual
//  specializations... that way name lookup should find the primary
//  template first and then see later specializations. Or we could just
//  remove this and live with the 'nonesuch' error messages. Either way,
//  we don't need anything more right now, this solution is fine to
//  unblock general progress
//
//-----------------------------------------------------------------------
//
template< typename C >
inline constexpr auto as_( auto&& x ) -> decltype(auto)
{
    if constexpr (is_narrowing_v<C, CPP2_TYPEOF(x)>) {
        static_assert(
            program_violates_type_safety_guarantee<C, CPP2_TYPEOF(x)>,
            "'as' does not allow unsafe narrowing conversions - if you're sure you want this, use `unsafe_narrow<T>()` to force the conversion"
        );
    }
    else if constexpr( std::is_same_v< CPP2_TYPEOF(as<C>(CPP2_FORWARD(x))), nonesuch_ > ) {
        static_assert(
            program_violates_type_safety_guarantee<C, CPP2_TYPEOF(x)>,
            "No safe 'as' cast available - please check your cast"
        );
    }
    //  else
    return as<C>(CPP2_FORWARD(x));
}

template< typename C, auto x >
inline constexpr auto as_() -> decltype(auto)
{
    if constexpr (requires { as<C, x>(); }) {
        if constexpr( std::is_same_v< CPP2_TYPEOF((as<C, x>())), nonesuch_ > ) {
            static_assert(
                program_violates_type_safety_guarantee<C, CPP2_TYPEOF(x)>,
                "Literal cannot be narrowed using 'as' -  if you're sure you want this, use 'unsafe_narrow<T>()' to force the conversion"
            );
        }
    }
    else {
        static_assert(
            program_violates_type_safety_guarantee<C, CPP2_TYPEOF(x)>,
            "No safe 'as' cast available - please check your cast"
        );
    }
    //  else
    return as<C,x>();
}


}


using cpp2::cpp2_new;


//  Stabilize line numbers for "compatibility" static assertions that we know
//  will fire for some compilers, to keep regression test outputs cleaner
#line 9999

//  GCC 10 doesn't support 'requires' in forward declarations in some cases
//  Workaround: Disable the requires clause where that gets reasonable behavior
//  Diagnostic: static_assert the other cases that can't be worked around
#if !defined(__clang__) && defined(__GNUC__) && __GNUC__ == 10
    #define CPP2_REQUIRES(...) /* empty */
    #define CPP2_REQUIRES_(...) static_assert(false, "GCC 11 or higher is required to support variables and type-scope functions that have a 'requires' clause. This includes a type-scope 'forward' parameter of non-wildcard type, such as 'func: (this, forward s: std::string)', which relies on being able to add a 'requires' clause - in that case, use 'forward s: _' instead if you need the result to compile with GCC 10.")
#else
    #define CPP2_REQUIRES(...) requires (__VA_ARGS__)
    #define CPP2_REQUIRES_(...) requires (__VA_ARGS__)
#endif

#endif
