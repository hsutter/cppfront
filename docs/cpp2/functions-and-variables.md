
# Functions and variables

## Overview

TODO

## Parameter passing

TODO

All parameters and other objects in Cpp2 are `const` by default, except for local variables. For details, see [Design note: Capture](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Capture).

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

