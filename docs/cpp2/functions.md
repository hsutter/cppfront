
# Functions

## Overview

TODO


## Parameters

There are six ways to pass parameters that cover all use cases:

| Parameter kind | "Pass me an `x` I can ______" | Accepts arguments that are | Special semantics |
|---|---|---|---|
| `in` (default) | read from | anything | always `#!cpp const`<p>automatically passes by value if cheaply copyable |
| `copy` | take a copy of | anything | acts like a normal local variable initialized with the argument |
| `inout` | read from and write to | lvalues | |
| `out` | write to (including construct) | lvalues, including uninitialized lvalues | must `=` assign/construct before other uses |
| `move` | move from | rvalues | automatically moves from every definite last use |
| `forward` | forward | anything | automatically forwards from every definite last use |



> Note: All parameters and other objects in Cpp2 are `#!cpp const` by default, except for local variables. For details, see [Design note: `#!cpp const` objects by default](https://github.com/hsutter/cppfront/wiki/Design-note%3A-const-objects-by-default).


## Return values

TODO


### Function outputs

A function's outputs are its return values, and the "out" state of any `out` and `inout` parameters.

Function outputs cannot be silently discarded. To explicitly discard a function output, assign it to `_`. For example:

``` cpp title="No silent discard" hl_lines="10 11 22 27"
f: ()             -> void = { }
g: ()             -> int  = { return 10; }
h: (inout x: int) -> void = { x = 20; }

main: ()
= {
    f();                    // ok, no return value

    std::cout << g();       // ok, use return value
    _ = g();                // ok, explicitly discard return value
    g();                    // ERROR, return value is ignored

    {
        x := 0;
        h( x );             // ok, x is referred to again...
        std::cout << x;     // ... here, so its new value is used
    }

    {
        x := 0;
        h( x );             // ok, x is referred to again...
        _ = x;              // ... here where its value explicitly discarded
    }

    {
        x := 0;
        h( x );             // ERROR, this is a definite last use of x
    }                       // so x is not referred to again, and its
                            // 'out' value can't be implicitly discarded
}
```

> Cpp2 imbues Cpp1 code with nondiscardable semantics, while staying fully compatible as usual:
>
> - A function written in Cpp2 syntax that returns something other than `#!cpp void` is always compiled to Cpp1 with `[[nodiscard]]`.
>
> - A function call written in Cpp2 `x.f()` member call syntax always treats a non-`#!cpp void` return type as not discardable, even if the function was written in Cpp1 syntax that did not write `[[nodiscard]]`.


## Control flow

## `#!cpp if`, `#!cpp else` — Branches

TODO

## `#!cpp for`, `#!cpp while`, `#!cpp do` — Loops

TODO

Loops can be named using the usual **name `:`** syntax that introduces all names, and `#!cpp break` and `#!cpp continue` can refer to those names. For example:

``` cpp title="Using named break and continue" hl_lines="6 10"
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

