
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

#ifdef _MSC_VER
    #pragma warning(disable:5050)   // suppress spurious modules warning
#endif


namespace cpp2 {

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

    auto construct     (auto ...args) -> void { assert(!init);  new (&t) T(args...);  init = true; }
    auto construct_list(auto ...args) -> void { assert(!init);  new (&t) T{args...};  init = true; }
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
class contract_group {
public:
    using handler = void (*)() noexcept;

    constexpr contract_group  (handler h = nullptr)  : chandler(normalize(h)) { }
    constexpr auto set_handler(handler h) -> handler { auto old = chandler; chandler = normalize(h); return old; }
    constexpr auto get_handler() const    -> handler { return chandler; }
    constexpr auto expects  (bool b)      -> void    { assertion(b); }
    constexpr auto ensures  (bool b)      -> void    { assertion(b); }
private:
    constexpr auto assertion(bool b)      -> void    { if (!b) chandler(); }
    constexpr auto normalize(handler h)   -> handler { return h ? h : []()noexcept{}; }
    handler chandler;
};

auto inline Default = contract_group( []()noexcept{assert(!"contract violation"); } /* or: &std::terminate */);
auto inline Bounds  = contract_group( []()noexcept{assert(!"Bounds contract violation"); } );
auto inline Null    = contract_group( []()noexcept{assert(!"Null contract violation"); } );
auto inline Testing = contract_group( []()noexcept{assert(!"Testing contract violation"); } );

//  Null pointer deref checking
//
auto assert_not_null(auto&& p) -> auto&& {
    //  Checking against a default-constructed value should be fine for iterators too
    //  TODO: validate this works for all pointerlike types
    Null.expects(p != std::remove_cvref_t<decltype(p)>{});   
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


}

#endif
