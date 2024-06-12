
# Functions

## Overview

A function is defined by writing a function signature after the `:` and a statement (expression or `{` `}` compound statement) after the `=`. After the optional [template parameters](declarations.md#template-parameters) available for all declarations, a function signature consists of a possibly-empty [parameter list](#parameters), and one or more optional [return values](#return-values).

For example, the minimal function named `func` that takes no parameters and returns nothing (`#!cpp void`) is:

``` cpp title="A minimal function"
func: ( /* no parameters */ ) = { /* empty body */ }
```


## <a id="parameters"></a> Parameters

The parameter list is a [list](common.md#lists) enclosed by `(` `)` parentheses. Each parameter is declared using the [same unified syntax](declarations.md) as used for all declarations. For example:

``` cpp title="Declaring parameters" hl_lines="2-4"
func: (
    x: i32,                         // parameter x is a 32-bit int
    y: std::string,                 // parameter y is a std::string
    z: std::map<i32, std::string>   // parameter z is a std::map
    )
= {
    // ...
}
```

There are six ways to pass parameters that cover all use cases, that can be written before the parameter name:

| Parameter ***kind*** | "Pass me an `x` I can ______" | Accepts arguments that are | Special semantics | ***kind*** `x: X` Compiles to Cpp1 as |
|---|---|---|---|---|
| `in` (default) | read from | anything | always `#!cpp const`<p>automatically passes by value if cheaply copyable | `X const x` or `X const& x` |
| `copy` | take a copy of | anything | acts like a normal local variable initialized with the argument | `X x` |
| `inout` | read from and write to | lvalues | | `X& x` |
| `out` | write to (including construct) | lvalues (including uninitialized) | must `=` assign/construct before other uses | `cpp2::impl::out<X>` |
| `move` | move from (consume the value of) | rvalues | automatically moves from every definite last use | `X&&` |
| `forward` | forward | anything | automatically forwards from every definite last use | `T&&` constrained to type `X` |

> Note: All parameters and other objects in Cpp2 are `#!cpp const` by default, except for local variables. For details, see [Design note: `#!cpp const` objects by default](https://github.com/hsutter/cppfront/wiki/Design-note%3A-const-objects-by-default).

For example:

``` cpp title="Declaring parameter kinds" hl_lines="2 3 10"
append_x_to_y: (
    x       : i32,          // an i32 I can read from (i.e., const)
    inout y : std::string   // a string I can read from and write to
    )
= {
    y = y + to_string(x);   // read x, read and write y
}

wrap_f: (
    forward x               // a generic value of deduced type I can forward
)                           //  (omitting x's  type means the same as ': _')
= {
    global_counter += x;    // ok to read x
    f(x);                   // last use: automatically does 'std::forward<T>(x)'
}
```


## <a id="return-values"></a> Return values

A function can return either of the following. The default is `#!cpp -> void`.

(1) **`#!cpp -> X`** to return a single unnamed value of type `X`, which can be  `#!cpp void` to signify the function has no return value. If `X` is not `#!cpp void`, the function body must have a `#!cpp return /*value*/;` statement that returns a value of type `X` on every path that exits the function. For example:

``` cpp title="Functions with an unnamed return value" hl_lines="2 4 7 9 12 14"
//  A function returning no value (void)
increment_in_place: (inout a: i32) -> void = { a++; }
//  Or, using syntactic defaults, the following has identical meaning:
increment_in_place: (inout a: i32) = a++;

//  A function returning a single value of type i32
add_one: (a: i32) -> i32 = { return a+1; }
//  Or, using syntactic defaults, the following has identical meaning:
add_one: (a: i32) -> i32 = a+1;

//  A generic function returning a single value of deduced type
add: <T: type, U: type> (a:T, b:U) -> decltype(a+b) = { return a+b; }
//  Or, using syntactic defaults, the following has identical meaning:
add: (a, b) -> _ = a+b;
```

(2) **`#!cpp -> ( /* parameter list */ )`** to return a list of named return parameters using the same [parameters](#parameters) syntax, but where the only passing styles are `out` (the default, which moves where possible) or `forward`. The function body must [initialize](objects.md#init) the value of each return-parameter `ret` in its body the same way as any other local variable. An explicit return statement is written just `#!cpp return;` and returns the named values; the function has an implicit `#!cpp return;` at the end. For example:

``` cpp title="Function with multiple/named return values" hl_lines="1 3-4 7-8 14 16-17"
divide: (dividend: int, divisor: int) -> (quotient: int, remainder: int) = {
    if divisor == 0 {
        quotient  = 0;                      // constructs quotient
        remainder = 0;                      // constructs remainder
    }
    else {
        quotient = dividend / divisor;      // constructs quotient
        remainder = dividend % divisor;     // constructs remainder
    }
}

main: () = {
    div := divide(11, 5);
    std::cout << "(div.quotient)$, (div.remainder)$\n";
}
//  Prints:
//     2, 1
```

This next example declares a [member function](types.md#this-parameter) with multiple return values in a [type](types.md) named `set`:

``` cpp title="Member function with multiple/named return values" hl_lines="7 9 10 22-24"
set: <Key> type = {
    container: std::set<Key>;
    iterator : type == std::set<Key>::iterator;

    //  A std::set::insert-like function using named return values
    //  instead of just a std::pair/tuple
    insert: (inout this, value: Key) -> (where: iterator, inserted: bool) = {
        set_returned := container.insert(value);
        where    = set_returned.first;
        inserted = set_returned.second;
    }

    ssize: (this) -> i64 = std::ssize(container);

    // ...
}

use_inserted_position: (_) = { }

main: () = {
    m: set<std::string> = ();
    ret := m.insert("xyzzy");
    if ret.inserted {
        use_inserted_position( ret.where );
    }
    assert( m.ssize() == 1 );
}
```


### <a id="nodiscard-outputs"></a> Function outputs are not implicitly discardable

A function's outputs are its return values, and the "out" state of any `out` and `inout` parameters.

Function outputs cannot be silently discarded. To explicitly discard a function output, assign it to `_`. For example:

``` cpp title="No silent discard" hl_lines="9 11 13 17-18 23-24 29-30"
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


## <a id="control flow"></a> Control flow

## <a id="branches"></a> `#!cpp if`, `#!cpp else` — Branches

`if` and `else` are like always in C++, except that `(` `)` parentheses around the condition are not required. Instead, `{` `}` braces around a branch body *are* required. For example:

``` cpp title="Using if and else" hl_lines="1 4"
if vec.ssize() > 100 {
    do_general_algorithm( container );
}
else {
    do_linear_scan( vec );
}
```


## <a id="loops"></a> `#!cpp for`, `#!cpp while`, `#!cpp do` — Loops

**`#!cpp do`** and **`#!cpp while`** are like always in C++, except that `(` `)` parentheses around the condition are not required. Instead, `{` `}` braces around the loop body *are* required.

**`#!cpp for range do (e)`** ***statement*** says "for each element in `range`, call it `e` and perform the statement." The loop parameter `(e)` is an ordinary parameter that can be passed using any [parameter passing style](#parameters); as always, the default is `in`, which is read-only and expresses a read-only loop. The statement is not required to be enclosed in braces.

Every loop can have a `next` clause, that is performed at the end of each loop body execution. This makes it easy to have a counter for any loop, including a range `#!cpp for` loop.

> Note: Whitespace is just a stylistic choice. This documentation's style generally puts each keyword on its own line and lines up what follows.

For example:

``` cpp title="Using loops" hl_lines="4 5 13 16 17 22-24"
words: std::vector<std::string> = ("Adam", "Betty");
i := 0;

while i < words.ssize() // while this condition is true
next  i++               // and increment i after each loop body is run
{                       // do this loop body
    std::cout << "word: (words[i])$\n";
}
//  prints:
//      word: Adam
//      word: Betty

do {                    // do this loop body
    std::cout << "**\n";
}
next  i--               // and decrement i after each loop body is run
while i > 0;            // while this condition is true
//  prints:
//      **
//      **

for  words              // for each element in 'words'
next i++                // and increment i after each loop body is run
do   (inout word)       // declare via 'inout' the loop can change the contents
{                       // do this loop body
    word = "[" + word + "]";
    std::cout << "counter: (i)$, word: (word)$\n";
}
//  prints:
//      counter: 0, word: [Adam]
//      counter: 1, word: [Betty]
```

There is no special "select" or "where" to perform the loop body for only a subset of matches, because this can naturally be expressed with `if`. For example:

``` cpp title="Using loops + if" hl_lines="7"
//  Continuing the previous example
i = 0;

for  words
next i++
do   (word)
if   i % 2 == 1         // if i is odd
{                       // do this loop body
    std::cout << "counter: (i)$, word: (word)$\n";
}
//  prints:
//      counter: 1, word: [Betty]
```

Here is the equivalent of the Cpp1 code `for ( int i = 0; i < 10; ++i ){ std::cout << i; }`:

``` cpp title="Equivalent of Cpp1 'for ( int i = 0; i < 10; ++i ){ std::cout << i; }'"
(copy i := 0)
while i < 10
next  i++ {
    std::cout << i;
}
```

Line by line:

- `(copy i := 0)`: Any statement can have [statement-local parameters](declarations.md#from-functions-to-local-scopes-and-back-again), and this is declaring `i` as an `int` that's local to the loop. Parameters by default are `const`, and for not-cheap-to-copy types they bind to the original value; so because we want to modify `i` we say `copy` to explicitly declare this is the loop's own mutable scratch variable.
- `while i < 10`: The termination condition.
- `next i++`: The end-of-loop-iteration statement. Note `++` is always postfix in Cpp2.


### Loop names, `#!cpp break`, and `#!cpp continue`

Loops can be named using the usual **name `:`** syntax that introduces all names, and `#!cpp break` and `#!cpp continue` can refer to those names. For example:

``` cpp title="Using named break and continue" hl_lines="1 3 6 10"
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


## <a id="definite-last-use"></a> Move/forward from definite last use

In a function body, a **definite last use** of a local name is a single use of that name in a statement that is not in a loop, where no control flow path after that statement mentions the name again.

For each definite last use:

- If the name is a local object or a `copy` or `move` parameter, we know the object will not be used again before being destroyed, and so the object is automatically treated as an rvalue (move candidate). If the expression that contains the last use is able to move from the rvalue, the move will happen automatically.

- If the name is a `forward` parameter, the object is automatically forwarded to preserve its constness and value category (`std::forward`-ed).

For example:

``` cpp title="Definite last uses" linenums="1" hl_lines="13 16 19 21"
f: (
    copy    x: some_type,
    move    y: some_type,
    forward z: some_type
    )
= {
    w: some_type = "y";

    prepare(x);                     // NOT a definite last use

    if something() {
        process(y);
        z.process(x);		        // definite last uses of x and z
    }
    else {
        cout << z;		            // definite last use of z
    }

    transfer(y);                    // definite last use of y

    offload(w);                     // definite last use of w
}
```

In this example:

- `x` has a definite last use on one path, but not another. Line 13 is a definite last use that automatically treats `x` as an rvalue. However, if the `#!cpp else` is taken, `x` gets no special automatic handling. Line 9 is not a definite last use because `x` could be used again where it is mentioned later on line 13.

- `y` has a definite last use on every path, in this case the same on all executions of the function. Line 19 is a definite last use that automatically treats `x` as an rvalue.

- `z` has a definite last use on every path, but unlike `y` it can be a different last use on different executions of the function. That's fine, each of lines 13 and 16 is a definite last use that automatically forwards the constness and value category of `z`.

- `w` has a definite last use on every path, in this case the same on all executions of the function. Line 21 is a definite last use that automatically treats `w` as an rvalue.


## <a id="function-defaults"></a> Generality note: Summary of function defaults

There is a single function syntax, designed so we can just omit the parts we're not currently using.

For example, let's express in full verbose detail that `equals` is a function template that has two type parameters `T` and `U`, two ordinary `in` parameters `a` and `b` of type `T` and `U` respectively, and a deduced return type, and its body returns the result of `a == b`:

``` cpp title="equals: A generic function written in full detail (using no defaults)"
equals: <T: type, U: type> (in a: T, in b: U) -> _ = { return a == b; }
```

We can write all that, but we don't have to.

First, `: type` is the default for template parameters, so we can omit it since that's what we want:

``` cpp title="equals: Identical meaning, now using the :type default for template parameters"
equals: <T, U> (in a: T, in b: U) -> _ = { return a == b; }
```

So far, the return type is already using one common default available throughout Cpp2: the wildcard `_` (pronounced "don't care"). Since this function's body doesn't actually use the parameter type names `T` and `U`, we can just use wildcards for the parameter types too:

``` cpp title="equals: Identical meaning, now using the _ wildcard also for the parameter types"
equals: (in a: _, in b: _) -> _ = { return a == b; }
```

Next, `: _` is also the default parameter type, so we don't need to write even that:

``` cpp title="equals: Identical meaning, now using the :_ default parameter type"
equals: (in a, in b) -> _ = { return a == b; }
```

Next, `in` is the default [parameter passing mode](#parameters). So we can use that default too:

``` cpp title="equals: Identical meaning, now using the 'in' default parameter passing style"
equals: (a, b) -> _ = { return a == b; }
```

We already saw that `{` `}` is the default for a single-line function that returns nothing. Similarly, `{ return` and `}` is the default for a single-line function that returns something:

``` cpp title="equals: Identical meaning, now using the { return ... } default body decoration"
equals: (a, b) -> _ = a == b;
```

Next, `#!cpp -> _ =` (deduced return type) is the default for single-expression functions that return something and so can be omitted:

``` cpp title="equals: Identical meaning, now using the -> _ = default for functions that return something"
equals: (a, b) a == b;
```

Finally, at expression scope (aka "lamba/temporary") functions/objects aren't named, and the trailing `;` is optional:

``` cpp title="(not) 'equals': Identical meaning, but without a name as an unnamed function at expression scope"
:(a, b) a == b
```

Here are some additional examples of unnamed function expressions:

``` cpp title="Some more examples of unnamed function expressions"
std::ranges::for_each( a, :(x) = std::cout << x );

std::ranges::transform( a, b, :(x) x+1 );

where_is = std::ranges::find_if( a, :(x) x == waldo$ );
```

> Note: Cpp2 doesn't have a separate "lambda" syntax; you just use the regular function syntax at expression scope to write an unnamed function, and the syntactic defaults are chosen to make such function expressions convenient to write. And because in Cpp2 every local variable [capture](expressions.md#captures) (for example, `waldo$` above) is written in the body, it doesn't affect the function syntax.

