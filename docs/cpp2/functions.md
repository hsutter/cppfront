
# Functions

## Overview

TODO

## Calling functions: Nonmember function syntax, and UFCS syntax

A function call like `f(x)` is a normal non-member function call. It will call non-member functions only.

A function call like `x.f()` is a unified function call syntax (aka UFCS) call. It will call a member function if one is available, and otherwise will call `f(x)`. Having UFCS is important for generic code that may want to call a member or a non-member function, whichever is available. It's also important to enable fluid programming styles and natural IDE autocompletion support.

For example:

``` cpp title="Example: Function calls"
f: ( v : std::vector<widget> ) = {

    //  This calls std::vector::size()
    std::cout << v.size();

    //  This calls std::ssize(v), because v
    //  doesn't have a .ssize member function
    std::cout << v.ssize();
}
```


## Parameter passing

TODO

All parameters and other objects in Cpp2 are `const` by default, except for local variables. For details, see [Design note: `const` objects by default](https://github.com/hsutter/cppfront/wiki/Design-note%3A-const-objects-by-default).

## Control flow

## `if`, `else` — Branches

TODO

## `for`, `while`, `do` — Loops

TODO

Loops can be named using the usual **name `:`** name introduction syntax, and `break` and `continue` can refer to those names. For example:

``` cpp title="Example: Writing a simple type"
outer: while i<M next i++ {      // loop named "outer"
    // ...
    inner: while j<N next j++ {  // loop named "inner"
        // ...
        if something() {
            continue inner;      // continue the inner loop
        }
        // ...
        if something_else() {
            break outer;         // break the outer loop
        }
        // ...
    }
    // ...
}
```

## Unnamed function expressions (aka lambdas)

TODO

## Move/forward from last use

TODO

## Generality: Unifying functions and local scopes

TODO

