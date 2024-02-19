
# Common expressions

## Calling functions: `f(x)` syntax, and `x.f()` UFCS syntax

A function call like `f(x)` is a normal function call that will call non-member functions only, as usual in C++.

A function call like `x.f()` is a unified function call syntax (aka UFCS) call. It will call a member function if one is available, and otherwise will call `f(x)`. Having UFCS is important for generic code that may want to call a member or a non-member function, whichever is available. It's also important to enable fluid programming styles and natural IDE autocompletion support.

An operator notation call like `#!cpp a + b` will call an overloaded operator function if one is available, as usual in C++.

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



## `_` — the "don't care" wildcard, including explicit discard

`_` is pronounced **"don't care"** and allowed as a wildcard in most contexts. For example:

``` cpp title="Using the _ wildcard" hl_lines="2 5 11"
//  We don't care about the guard variable's name
_ : std::lock_guard = mut;

//  If we don't care to write the variable's type, deduce it
x : _ = 42;
    // in cases like this, _ can be omitted...
    // this is equivalent to "x := 42;"

return inspect v -> std::string {
    is std::vector = "v is a std::vector";
    is _ = "unknown";   // don't care what else, match anything
};
```

Cpp2 treats all function outputs (return values, and results produced via `inout` and `out` parameters) as important, and does not let them be silently discarded by default. To explicitly discard such a value, assign it to `_`. For example:

``` cpp title="Using _ for explicit discard" hl_lines="1 8"
_ = vec.emplace_back(1,2,3);
    // "_ =" is required to explicitly discard emplace_back's
    // return value (which is non-void since C++17)

{
    x := my_vector.begin();
    std::advance(x, 2);
    _ = x;  // required to explicitly discard x's new value,
            // because std::advance modifies x's value
}
```

For details, see [Design note: Explicit discard](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Explicit-discard). In Cpp2, data is always initialized, data is never silently lost, data flow is always visible. Data is precious, and it's always safe.


## `is` — safe type/value queries

An `x is C` expression allows safe type and value queries, and evaluates to `#!cpp true` if `x` matches constraint `C`. It supports both static and dynamic queries, including customization, with support for standard library dynamic types like `std::variant`, `std::optional`, `std::expected`, and `std::any` provided out of the box.

There are two kinds of `is`:

- A **type query**, where `C` is a type constraint: a type, a template name, a concept, or a type predicate. Here `x` may be a type, or an object or expression; if it is an object or expression, the query refers to `x`'s type.

| Type constraint kind | Example |
|---|---|
| Static type query | `x is int` |
| Dynamic type query | `ptr* is Shape` |
| Static template type query | `x is std::vector` |
| Static concept query | `x is std::integral` |

- A **value query**, where `C` is a value constraint: a value, or a value predicate. Here `x` must be an object or expression.

| Value constraint kind | Example |
|---|---|
| Value | `#!cpp x is 0` |
| Value predicate | `#!cpp x is (in(10, 20))` |

`is` is useful throughout the language, including in `inspect` pattern matching alternatives. `is` is extensible, and works out of the box with `std::variant`, `std::optional`, `std::expected`, and `std::any`. For examples, see:

- [`mixed-inspect-templates.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/mixed-inspect-templates.cpp2)
- [`mixed-inspect-values.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/mixed-inspect-values.cpp2)
- [`mixed-inspect-values-2.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/mixed-inspect-values-2.cpp2)
- [`mixed-type-safety-1.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/mixed-type-safety-1.cpp2)
- [`pure2-enum.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/pure2-enum.cpp2)
- [`pure2-inspect-expression-in-generic-function-multiple-types.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/pure2-inspect-expression-in-generic-function-multiple-types.cpp2)
- [`pure2-inspect-fallback-with-variant-any-optional.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/pure2-inspect-fallback-with-variant-any-optional.cpp2)
- [`pure2-type-safety-1.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/pure2-type-safety-1.cpp2)
- [`pure2-type-safety-2-with-inspect-expression.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/pure2-type-safety-2-with-inspect-expression.cpp2)

Here are some `is` queries with their Cpp1 equivalents. In this table, uppercase names are type names, lowercase names are objects, `v` is a `std::variant` where one alternative is `T`, `o` is a `std::optional<T>`, and `a` is a `std::any`:

| Some sample `is` queries | Cpp1 equivalent
|---|---|
| `X is Y && Y is X` | `std::is_same_v<X,Y>` |
| `D is B` | `std::is_base_of<B,D>` |
| `#!cpp pb is *D` | `#!cpp dynamic_cast<D*>(pb) != nullptr` |
| `v is T`  | `std::holds_alternative<T>(v)` |
| `a is T`  | `#!cpp a.type() == typeid(T)` |
| `o is T`  | `o.has_value()` |

> Note: `is` unifies a variety of differently-named Cpp1 language and library queries under one syntax, and supports only the type-safe ones.


## `as` — safe casts and conversions

An `x as T` expression allows safe type casts. `x` must be an object or expression, and `T` must be a type. Like `is`, `as` supports both static and dynamic typing, including customization, with support for standard library dynamic types like `std::variant`, `std::optional`, `std::expected`, and `std::any` provided out of the box. For example:

``` cpp title="Using as" hl_lines="4 6 14"
main: () = {
    a: std::any = 0;                // a's type is now int, value 0
    test(a);                        // prints "zero"
    a = "plugh" as std::string;     // a's type is now std::string, value "plugh"
    test(a);                        // prints "plugh"
    test("xyzzy" as std::string);   // prints "xyzzy"
}

//  A generic function that takes an argument 'x' of any type,
//  same as "void test( auto const& x )" in C++20 syntax
test: (x) = {
    std::cout << inspect x -> std::string {
        is 0           = "zero";
        is std::string = x as std::string;
        is _           = "(no match)";
    } << "\n";
}
```

Here are some `as` casts with their Cpp1 equivalents. In this table, uppercase names are type names, lowercase names are objects, `v` is a `std::variant` where one alternative is `T`, `o` is a `std::optional<T>`, and `a` is a `std::any`:

| Some sample `as` casts | Cpp1 equivalent
|---|---|
| `x as Y` | `Y{x}` |
| `#!cpp pb as *D` | `#!cpp dynamic_cast<D*>(pb)` |
| `v as T`  | `std::get<T>(v)` |
| `a as T`  | `std::any_cast<T>(a)` |
| `o as T`  | `o.value()` |

> Note: `as` unifies a variety of differently-named Cpp1 language and library casts and conversions under one syntax, and supports only the type-safe ones.


## `inspect` — pattern matching

An `inspect expr -> Type` expression allows pattern matching using `is`.

- `expr` is evaluated once.

- Each alternative spelled `is C` is evaluated in order as if called with `expr is C`.

- If an alternative evaluates to `#!cpp true`, then its `#!cpp = alternative;` body is used as the value of the entire `inspect` expression, and the meaning is the same as if the entire `inspect` expression had been written as just `#!cpp :Type = alternative;` — i.e., an unnamed object expression (aka 'temporary object') of type `Type` initialized with `alternative`.

- A catchall `is _` is required.

For example:

``` cpp title="Using inspect" hl_lines="6-13"
//  A generic function that takes an argument 'x' of any type
//  and inspects various things about `x`
test: (x) = {
    forty_two := 42;
    std::cout
        << inspect x -> std::string {
            is 0           = "zero";            // == 0
            is (forty_two) = "the answer";      // == 42
            is int         = "integer";         // is type int (and not 0 or 42)
            is std::string = x as std::string;  // is type std::string
            is std::vector = "a std::vector";   // is a vector</*of-some-type*/>
            is _           = "(no match)";      // is something else
        }
        << "\n";
}

//  Sample call site
test(42);
    //  Behaves as if the following function were called:
    //      test: (x) = { std::cout << (:std::string = "the answer") << "\n"; }
    //  (and that's why inspect alternatives are introduced with '=')
```

For more examples, see also the examples in the previous two sections on `is` and `as`, many of which use `inspect`.


## `$` — captures, including interpolations

TODO

For details, see [Design note: Capture](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Capture).
