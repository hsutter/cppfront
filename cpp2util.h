
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

#include <cassert>
#include <exception>
#include <type_traits>
#include <new>
#include <iostream>
#include <string_view>


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
    #define CPP2_SOURCE_LOCATION_PARAM_SOLO_ANON    std::source_location
    #define CPP2_SOURCE_LOCATION_ARG                , where
    #define CPP2_SOURCE_LOCATION_ARG_SOLO           where
#else
    #define CPP2_SOURCE_LOCATION_PARAM
    #define CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT
    #define CPP2_SOURCE_LOCATION_PARAM_SOLO
    #define CPP2_SOURCE_LOCATION_PARAM_SOLO_ANON
    #define CPP2_SOURCE_LOCATION_ARG
    #define CPP2_SOURCE_LOCATION_ARG_SOLO
#endif


class contract_group {
public:
    using handler = void (*)(CPP2_SOURCE_LOCATION_PARAM_SOLO_ANON) noexcept;

    constexpr contract_group  (handler h = nullptr)  : reporter(h) { }
    constexpr auto set_handler(handler h) -> handler { assert(h); auto old = reporter; reporter = h; return old; }
    constexpr auto get_handler() const    -> handler { return reporter; }
    constexpr auto expects    (bool b CPP2_SOURCE_LOCATION_PARAM_WITH_DEFAULT) -> void { if (!b) reporter(CPP2_SOURCE_LOCATION_ARG_SOLO); }
private:
    handler reporter;
};

[[noreturn]] auto report_and_terminate(std::string_view msg CPP2_SOURCE_LOCATION_PARAM) noexcept -> void {
    std::cerr
#ifdef CPP2_USE_SOURCE_LOCATION
        << where.file_name() << "2("
        << where.line() << ") "
        << where.function_name() << ": "
#endif
        << msg << " violation\n";
    std::terminate();
}

auto inline Default = contract_group( 
    [](CPP2_SOURCE_LOCATION_PARAM_SOLO)noexcept { 
        report_and_terminate(""              CPP2_SOURCE_LOCATION_ARG);
    }
);
auto inline Bounds  = contract_group( 
    [](CPP2_SOURCE_LOCATION_PARAM_SOLO)noexcept { 
        report_and_terminate("Bounds safety" CPP2_SOURCE_LOCATION_ARG); 
    } 
);
auto inline Null    = contract_group( 
    [](CPP2_SOURCE_LOCATION_PARAM_SOLO)noexcept {
        report_and_terminate("Null safety"   CPP2_SOURCE_LOCATION_ARG); 
    } 
);
auto inline Testing = contract_group( 
    [](CPP2_SOURCE_LOCATION_PARAM_SOLO)noexcept {
        report_and_terminate("Testing"       CPP2_SOURCE_LOCATION_ARG); 
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


}

#endif
