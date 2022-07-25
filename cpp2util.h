
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0


//===========================================================================
//  Cpp2 utilities:
//      Language support implementations
//      #include'd by generated Cpp1 code
//===========================================================================

#ifndef __CPP2_UTIL
#define __CPP2_UTIL

#include <cassert>
#include <exception>
#include <new>


namespace cpp2 {

//-----------------------------------------------------------------------
// 
//  These are closely related...
// 
//  deferred_init<T>    For deferred-initialized local or member variable
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

    template<typename T>
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


}

#endif
