
# Functions

## Overview

TODO

## Calling functions: `f(x)` syntax, and `x.f()` UFCS syntax

A function call like `f(x)` is a normal function call that will call non-member functions only, as usual in C++.

A function call like `x.f()` is a unified function call syntax (aka UFCS) call. It will call a member function if one is available, and otherwise will call `f(x)`. Having UFCS is important for generic code that may want to call a member or a non-member function, whichever is available. It's also important to enable fluid programming styles and natural IDE autocompletion support.

An operator notation call like `a + b` will call an overloaded operator function if one is available, as usual in C++.

For example:

``` cpp title="Function calls" hl_lines="3 7 11 16 19 20"
//  Generic function to log something
//  This calls operator<< using operator notation
log: (x) = clog << x;

f: ( v : std::vector<widget> ) = {
    //  This calls log() with the result of std::vector::size()
    log( v.size() );

    //  This calls log() with the result of std::ssize(v), because
    //  v doesn't have a .ssize member function
    log( v.ssize() );
}

//  Generic function to print "hello, ___!" for any printable type
hello: (name) = {
    myfile := fopen("xyzzy.txt", "w");
    //  Direct calls to C nonmember functions, using UFCS and safe
    //  string interpolation (instead of type-unsafe format strings)
    myfile.fprintf( "Hello, (name)$!\n" );
    myfile.fclose();
    //  The C and C++ standard libraries are not only fully available,
    //  but safer (and arguably nicer) when used from Cpp2 syntax code
}
```

To explicitly treat an object name passed as an argument as `move` or `out`, write that keyword before the variable name.

- Explicit `move` is rarely needed. Every definite last use of a local variable will apply `move` by default. Writing `move` from an object before its definite last use means that later uses may see a moved-from state.

- Explicit `out` is needed only when initializing a local variable separately from its declaration using a call to a function with an `out` parameter. For details, see [Guaranteed initialization](../cpp2/objects.md#Init).

For example:


## Parameters

There are six ways to pass parameters that cover all use cases:

| Parameter kind | "Pass me an `x` I can ______" | Accepts arguments that are | Special semantics |
|---|---|---|---|
| `in` (default) | read from | anything | always `const`<p>automatically passes by value if cheaply copyable |
| `copy` | take a copy of | anything | acts like a normal local variable initialized with the argument |
| `inout` | read from and write to | lvalues | |
| `out` | write to (including construct) | lvalues, including uninitialized lvalues | must `=` assign/construct before other uses |
| `move` | move from | rvalues | automatically moves from every definite last use |
| `forward` | forward | anything | automatically forwards from every definite last use |



> Note: All parameters and other objects in Cpp2 are `const` by default, except for local variables. For details, see [Design note: `const` objects by default](https://github.com/hsutter/cppfront/wiki/Design-note%3A-const-objects-by-default).


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
> - A function written in Cpp2 syntax that returns something other than `void` is always compiled to Cpp1 with `[[nodiscard]]`.
>
> - A function call written in Cpp2 `x.f()` member call syntax always treats a non-`void` return type as not discardable, even if the function was written in Cpp1 syntax that did not write `[[nodiscard]]`.


## Control flow

## `if`, `else` — Branches

TODO

## `for`, `while`, `do` — Loops

TODO

Loops can be named using the usual **name `:`** name introduction syntax, and `break` and `continue` can refer to those names. For example:

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

