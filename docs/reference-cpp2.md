
# Cpp2 reference


## Common programming concepts

### Comments

The usual `// line comments` and `/* stream comments */` are supported. For exmaple:

``` cpp title="Example: Comments"
//  A line comment: After //, the entire rest of the line is part of the comment

/*
    A stream comment: After /*, everything until the next * / (without a space between)
    is part of the comment. Note that stream comments do not nest.
 */
```

### Declarations

All Cpp2 declarations are written as **"_name_ `:` _kind_ `=` _statement_"**.

- The `:` is pronounced **"is a."**
- The `=` is pronounced is pronounced **"defined as."**
- The _statement_ is typically an expression statement (e.g., `a + b();`) or a compound statement (e.g., `{ /*...*/ return c(d) / e; }`).

For example:

``` cpp title="Example: Consistent declartions — name : kind = statement"
// n is a namespace defined as the following scope
n: namespace
= {
    // shape is a type defined as the following scope
    shape: type
    = {
        // points is an object of type std::vector<point2d>,
        // defined as having an empty default value
        // (type-scope objects are private by default)
        points: std::vector<point2d> = ();

        // draw is a function taking 'this' and 'canvas' parameters
        // and returning bool, defined as the following body
        // (type-scope functions are public by default)
        //   - this is as if 'this: shape', an object of type shape
        //   - where is an object of type canvas
        draw: (this, where: canvas) -> bool
        = {
            // pen is an object of deduced (omitted) type 'color',
            // defined as having initial value 'color::red'
            pen := color::red;

            // success is an object of deduced (omitted) type bool,
            // defined as having initial value 'false'
            success := false;

            // ...

            return success;
        }

        // count is a function taking 'this' and returning a type
        // deduced from its body, defined as a single-expression body
        count: (this) = points.ssize();

        // ...
    }

    // color is an @enum type (described later)
    color: @enum type = { red; green; blue; }
}
```

### The `_` wildcard, including explicit discard

`_` is pronounced **"don't care"** and allowed as a wildcard in most contexts. For example:

``` cpp title="Example: _ wildcard"
_ : std::lock_guard = mut;      // don't care about the guard variable's name

x : _ = 42;                     // don't care to write the variable's type, deduce it
    // in cases like this, _ can be omitted... this is equivalent to "x := 42;"

return inspect v -> std::string {
    is std::vector = "v is a std::vector";
    is _ = "unknown";           // don't care what else, match anything
};
```

Cpp2 treats all function outputs (return values, and results produced via `inout` and `out` parameters) as important, and does not let them be silently discarded by default. To explicitly discard such a value, assign it to `_`. For example:

``` cpp title="Example: Using _ for explicit discard"
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

For details, see [Design note: Explicit discard](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Explicit-discard). In Cpp2, data is always initialized, data is never silently lost, data flow is always visible. Data is precious, and it's always safe. This feels right and proper to me.

### Fundamental data types

Cpp2 supports the same fundamental types as today's Cpp1, but additionally provides the following aliases in namespace `cpp2`:

| Fixed-width types | Synonym for |
|---|---|
| `i8`        | `std::int8_t`        |
| `i16`       | `std::int16_t`       |
| `i32`       | `std::int32_t`       |
| `i64`       | `std::int64_t`       |
| `u8`        | `std::uint8_t`       |
| `u16`       | `std::uint16_t`      |
| `u32`       | `std::uint32_t`      |
| `u64`       | `std::uint64_t`      |

| Variable-width types <br> (Cpp2-compatible single-word names) | Synonym for (these multi-word<br> names are not allowed in Cpp2) |
|---|---|
| `ushort`      | `unsigned short`       |
| `uint`        | `unsigned int`         |
| `ulong`       | `unsigned long`        |
| `longlong`    | `long long`            |
| `ulonglong`   | `unsigned long long`   |
| `longdouble`  | `long double`          |

| For compatibility/interop only,<br> so deliberately ugly names | Synonym for | Notes |
|---|---|---|
| `_schar`     | `signed char`   | Normally, prefer `i8` instead |
| `_uchar`     | `unsigned char` | Normally, prefer `u8` instead |

### Type qualifiers

Types can be qualified with `const` and `*`. Types are written left-to-right, so a qualifier always applies to what immediately follows it. For example, to declare a `const` pointer to a non-`const` pointer to a `const i32` object, write:

``` cpp title="Example: Type qualifiers"
//  A const pointer to a non-const pointer to a const i32 object
p: const * * const i32; //
```

### Literals

Cpp2 supports the same `'c'`haracter, `"string"`, binary, integer, and floating point literals as Cpp1, including most Unicode encoding prefixes and raw string literals.

Cpp2 supports using Cpp1 user-defined literals for compatibility, to support seamlessly using existing libraries. However, because Cpp2 has unified function call syntax (UFCS), the preferred way to author the equivalent in Cpp2 is to just write a function or type name as a `.` call suffix. For example:

- You can create a `u8` value by writing either `u8(123)` or **`123.u8()`**. [^u8using]

- You can write a 'constexpr' function like `nm: (value: i64) -> my_nanometer_type == { /*...*/ }` that takes an integer and returns a value of a strongly typed "nanometer" type, and then create a `nm` value by writing either `nm(123)` or **`123.nm()`**.

Both **`123.n()`** and **`123.u8()`** are very similar to user-defined literal syntax, and more general.

### Operators

Operators have the same precedence and associativity as in Cpp1, but some unary operators that are prefix (always or sometimes) in Cpp1 are postfix (always) in Cpp2.

#### Unary operators

The operators `!`, `+`, and `-` are prefix, as in Cpp1. For example:

``` cpp title="Example: Prefix operators"
if !vec.empty() {
    vec.emplace_back( -123.45 );
}
```

| Unary operator | Cpp2 example | Cpp1 equivalent |
|---|---|---|
| `!` | `!vec.empty()` | `!vec.empty()` |
| `+` | `+100` | `+100` |
| `-` | `-100` | `-100` |

The operators `.`, `*`, `&`, `~`, `++`, `--`, `()`, `[]`, and `$` are postfix. For example:

``` cpp title="Example: Postfix operators"
//  Cpp1 examples, from cppfront's own source code:
//      address = &(*tokens)[pos + num];
//      is_void = *(*u)->identifier == "void";
//  Cpp2 equivalents:
        address = tokens*[pos + num]&;
        is_void = u**.identifier* == "void";
```

Postfix notation lets the code read fluidly left-to-right, in the same order in which the operators will be applied, and lets declaration syntax be consistent with usage syntax. For more details, see [Design note: Postfix operators](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Postfix-operators).

> Note: The function call syntax `f(x)` calls a namespace-scope function, or a function object, named `f`. The function call syntax `x.f()` is a unified function call syntax (aka UFCS) that calls a type-scope function in the type of `x` if available, otherwise calls the same as `f(x)`. For details, see [Design note: UFCS](https://github.com/hsutter/cppfront/wiki/Design-note%3A-UFCS).

| Unary operator | Cpp2 example | Cpp1 equivalent |
|---|---|---|
| `.` | `obj.f()` | `obj.f()` |
| `*` | `pobj*.f()` | `(*pobj).f()` or `pobj->f()` |
| `&` | `obj&` | `&obj` |
| `~` | `val~` | `~val` |
| `++` | `iter++` | `++iter` |
| `--` | `iter--` | `--iter` |
| `(` `)` | `f( 1, 2, 3)` | `f( 1, 2, 3)` |
| `[` `]` | `vec[123]` | `vec[123]` |
| `$` | `val$` | (reflection — no C++23 equivalent) |

> Because `++` and `--` always have in-place update semantics, we never need to remember "use prefix `++`/`--` unless you need a copy of the old value." If you do need a copy of the old value, just take the copy before calling `++`/`--`.

Unary suffix operators must not be preceded by whitespace. When `*`, `&`, and `~` are used as binary operators they must be preceded by whitespace. For example:

| Unary postfix operators that<br>are also binary operators | Cpp2 example | Cpp1 equivalent |
|---|---|---|
| `*` | `pobj* * 42` | `(*pobj)*42` |
| `&` | `obj& & mask` <p> (note: allowed in unsafe code only) | `&obj & mask` |
| `~` | `~val ~ bitcomplement` | `val~ ~ bitcomplement` |

For more details, see [Design note: Postfix unary operators vs binary operators](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Postfix-unary-operators-vs-binary-operators).

#### Binary operators

Binary operators are the same as in Cpp1. From lowest to highest precedence:

| Binary operators grouped by precedence |
|---|
| `*`, `/`, `%` |
| `+`, `-` |
| `<<`, `>>` |
| `<=>` |
| `<`, `>`, `<=`, `>=` |
| `==`, `!=` |
| `&` |
| `^` |
| `|` |
| `&&` |
| `||` |
| `=` and compound assignment |

### `is` — safe type/value queries

An `x is C` expression allows safe type and value queries, and evaluates to `true` if `x` matches constraint `C`. It supports both static and dynamic queries, including customization with support for the standard dynamically typed libraries `std::variant`, `std::optional`, and `std::any` provided in the box.

There are two kinds of `is`:

- A **type query**, where `C` is a type constraint: A type, a template name, a concept, or a type predicate. Here `x` may be a type, or an object or expression; if it is an object or expression, the query refers to `x`'s type.

| Type constraint kind | Example | Notes |
|---|---|---|
| Static type query | `x is int` |
| Dynamic type query | `ptr* is Shape` |
| Static template type query | `x is std::vector` |
| Static concept query | `x is std::integral` |

- A **value query**, where `C` is a value constraint: A value, or a value predicate. Here `x` must be an object or expression.

| Value constraint kind | Example |
|---|---|
| Value | `x is 0` |
| Value predicate | `x is (in(10, 20))` |

`is` is useful throughout the language, including in `inspect` pattern matching alternatives. `is` is extensible, and works out of the box with `std::variant`, `std::optional`, and `std::any`. For examples, see:

- [`mixed-inspect-templates.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/mixed-inspect-templates.cpp2)
- [`mixed-inspect-values.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/mixed-inspect-values.cpp2)
- [`mixed-inspect-values-2.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/mixed-inspect-values-2.cpp2)
- [`mixed-type-safety-1.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/mixed-type-safety-1.cpp2)
- [`pure2-enum.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/pure2-enum.cpp2)
- [`pure2-inspect-expression-in-generic-function-multiple-types.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/pure2-inspect-expression-in-generic-function-multiple-types.cpp2)
- [`pure2-inspect-fallback-with-variant-any-optional.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/pure2-inspect-fallback-with-variant-any-optional.cpp2)
- [`pure2-type-safety-1.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/pure2-type-safety-1.cpp2)
- [`pure2-type-safety-2-with-inspect-expression.cpp2`](https://github.com/hsutter/cppfront/tree/main/regression-tests/pure2-type-safety-2-with-inspect-expression.cpp2)


### `as` — safe casts and conversions

An `x as T` expression allows safe type casts. `x` must be an object or expression, and `T` must be a type. It supports both static and dynamic typing, including customization with support for the standard dynamically tyuped libraries `std::variant`, `std::optional`, and `std::any` provided in the box. For example:

``` cpp title="Example: Using as"
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

### `inspect` — pattern matching

An `inspect expr -> Type` expression allows pattern matching using `is`.

- `expr` is evaluated once.
- Each alternative spelled `is C` is evaluated in order as if called with `expr is C`.
- If an alternative evaluates to `true`, then its `= alternative;` body is used as the value of the entire `inspect` expression, and the meaning is the same as if the entire `inspect` expression had been written as just `:Type = alternative;` — i.e., an unnamed object expression (aka 'temporary object') of type `Type` initialized with `alternative`.
- A catchall `is _` is required.

For example:

``` cpp title="Example: Using inspect"
//  A generic function that takes an argument 'x' of any type
//  and inspects various things about `x`
test: (x) = {
    forty_two := 42;
    std::cout << inspect x -> std::string {
        is 0           = "zero";            // == 0
        is (forty_two) = "the answer";      // == 42
        is int         = "integer";         // is type int (value other than 0 or 42)
        is std::string = x as std::string;  // is type std::string
        is std::vector = "a std::vector";   // is a vector</*of-some-type*/>
        is _           = "(no match)";      // is something else
    } << "\n";
}

//  Sample call site
test(42);
    //  Behaves as if the following function were called:
    //      test: (x) = { std::cout << (:std::string = "the answer") << "\n";; }
    //  (and that's why inspect alternatives are introduced with '=')
```

For more examples, see also the examples in the previous two sections on `is` and `as`, many of which use `inspect`.


### `$` — captures, including interpolations


For details, see [Design note: Capture](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Capture).



## Functions and variables

### Overview

### Parameter passing

All parameters and other objects in Cpp2 are `const` by default, except for local variables. For details, see [Design note: Capture](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Capture).

### Control flow

#### `if` and `else` branches

#### `for`, `while`, and `do` loops

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



### Unnamed function expressions

### Move/forward from last use

### Design note: Unifying functions and local scopes


## Types

### Overview

User-defined types are written using the same **name `:` kind `=` value** syntax as everything in Cpp2. The type's "value" is a `{}`-enclosed body containing more declarations. In a type, data members are private by default, and functions and nested types are public by default. To explicitly declare a type scope declaration `public`, `protected`, or `private`, write that keyword at the beginning of the declaration.

``` cpp title="Example: Writing a simple type"
mytype: type =
{
    // data members are private by default
    x: std::string;

    // functions are public by default
    protected f: (this) = { do_something_with(x); }

    // ...
}
```

### `this`

The `this` parameter is explicit, and has special sauce:

- `this` is a synonym for the current object (not a pointer).
- Inside a type scope function, writing `this.` before a member name is optional.
- `this` defaults to the current type.
- `this`'s parameter passing style declares what kind of function you're writing. For example, `(in this)` (or just `(this)` since `in` is the default as usual) clearly means a `const` member function because `in` always implies constness; `(inout this)` means a non-const member function; `(move this)` expresses and emits a Cpp1 `&&`-qualified member function; and so on.
For example, here is how to write read-only member function named `print` that takes a read-only string value and prints this object's data value and the string message:

``` cpp title="Example: this"
mytype: type = {
    data: i32;   // some data member (private by default)

    print: (this, msg: std::string) = {
        std::cout << data << msg;
                 // "data" is shorthand for "this.data"
    }

    // ...
}
```

### Base types

Base types are written as members named this. For example, just as a type could write a data member as `data: string = "xyzzy";`, which is pronounced "`data` is a `string` defined as having the default value `"xyzzy"`, a base type is written as `this: Shape = (default, values);`, which is pronounced "`this` is a `Shape` defined as having these default values."

> Cpp2 syntax has no separate base list or separate member initializer list.

Because base and member subobjects are all declared in the same place (the type body) and initialized in the same place (an `operator=` function body), they can be written in any order, including interleaved, and are still guaranteed to be safely initialized in declared order. This means that in Cpp2 you can declare a data member object before a base subobject, so that it naturally outlives the base subobject.

> Cpp2 code doesn't need workarounds like Boost's `base_from_member`, because all of the motivating examples for that can be written directly. See my comments on [cppfront issue #334](https://github.com/hsutter/cppfront/issues/334) for details.

### `virtual`, `override`, and `final`

Virtual functions are written by specifying exactly one of `virtual`, `override`, or `final` on the `this` parameter. A pure virtual function is a function with a `virtual this` parameter and no body. For example:

``` cpp title="Example: Virtual functions"
abstract_base: type = {
    // ...
    print: (virtual this, msg: std::string);    // pure virtual (virtual + no body)
    // ...
}

derived: type = {
    this: abstract_base;                        // derives from abstract_base
    // ...
    print: (override this, msg: std::string);   // explicit override
    // ...
}
```

### `operator=`: Construction, assignment, and destruction

All value operations are spelled `operator=`, including construction, assignment, and destruction. All default to memberwise semantics and safe "explicit" by default. A special `that` parameter makes writing copy/move/conversion in particular simpler and safer. For details, see [Design note: operator=, this & that](https://github.com/hsutter/cppfront/wiki/Cpp2:-operator=,-this-&-that). Briefly summarizing here:

- The only special function every type must have is the destructor. If you don't write it by hand, a public nonvirtual destructor is generated by default.

- If no `operator=` functions are written by hand, a public default constructor is generated by default.

- All other `operator=` functions are explicitly written, either by hand or by opting into applying a metafunction (see below).

> Because generated functions are always opt-in, you can never get a generated function that's wrong for your type, and so Cpp2 doesn’t need to support "=delete" for the purpose of suppressing unwanted generated functions.

- The most general form of `operator=` is `operator=: (out this, that)`. It works as a unified general {copy, move} x { constructor, assignment } operator, and generates all of four of those in the lowered Cpp1 code if you didn't write a more specific one yourself (see design note above for details).

- All copy/move/comparison operator= functions are memberwise by default in Cpp2, including memberwise construction and assignment when you write them yourself.

- All conversion `operator=` functions are safely "explicit" by default. To opt into an implicit conversion, write the `implicit` qualifier on the `this` parameter.

- All functions can have a `that` parameter which is just like `this` (knows it's the current type, can be passed in all the usual ways, etc.) but refers to some other object of this type rather than the current object.

### `operator<=>`: Unified comparisons (mostly in C++20)

Most of Cpp2's `operator<=>` has already been merged into ISO C++, except for allowing chained comparisons. In Cpp2, comparisons can be safely chained, and always have the mathematically sound transitive meaning or else are rejected at compile time:

- **Valid chains: All `<`/`<=`, all `>`/`>=`, or all `==`.** All mathematically sound and safe chains like `a <= b < c` are supported, with efficient single evaluation of each term. They are "sound" because they are transitive; these chains imply a relationship between `a` and `c` (in this case, the chain implies that `a <= c` is also true).

- **Invalid chains: Everything else.** Nonsense chains like `a >= b < c` and `a != b != c` are compile time errors. They are "nonsense" because they are non-transitive; these chains do not imply any relationship between `a` and `c`.

For details, see [P0515 "Consistent comparison" section 3.3](https://wg21.link/p0515) and [P0893 "Chaining comparisons"](https://wg21.link/p0893).


## Metafunctions

A metafunction is a compile-time function that can participate in interpreting the meaning of a declaration, and can:

- apply defaults (e.g., `interface` makes functions virtual by default)
- enforce constraints (e.g., `value` enforces that the type has no virtual functions)
- generate additional functions and other code (e.g., `value` generates copy/move/comparison operations for a type if it didn't write them explicitly)

The most important thing about metafunctions is that they are not hardwired language features — they are compile-time library code that uses the reflection and code generation API, that lets the author of an ordinary type easily opt into a named set of defaults, requirements, and generated contents. This approach is essential to making the language simpler, because it lets us avoid hardwiring special "extra" types into the language and compiler.

### Applying metafunctions

Using a metafunctionis always opt-in, by writing `@name` afer the `:` of a declaration, where `name` is the name of the metafunctions. This lets the type author declare (and the human reader see) the intent up front: "This isn't just any `type`, this is a `@value type`" which automatically gives the type default/copy/move construction and assignment, `<=>` with `std::strong_ordering` comparisons, and guarantees that it has a public destructor and no protected or virtual functions:

``` cpp title="Example: Using the value metafunction when writing a type"
point2d: @value type = {
    x: i32 = 0;
    y: i32 = 0;
    // @value automatically generates default/copy/move
    // construction/assignment and <=> strong_ordering comparison,
    // and emits an error if you try to write a non-public
    // destructor or any protected or virtual function
}
```

### Generating source code at compile time

### Built-in metafunctions


#### `enum` and `flag_enum`

Cpp2 has no `enum` feature hardwired into the language. Instead you apply the `@enum` metafunction when writing an ordinary `type`:

``` cpp title="Example: Using @enum"
// skat_game is declaratively a safe enumeration type: it has
// default/copy/move construction/assignment and <=> with
// std::strong_ordering, a minimal-size signed underlying type
// by default if the user didn't specify a type, no implicit
// conversion to/from the underlying type, in fact no public
// construction except copy construction so that it can never
// have a value different from its listed enumerators, inline
// constexpr enumerators with values that automatically start
// at 1 and increment by 1 if the user didn't write their own
// value, and conveniences like to_string()... the word "enum"
// carries all that meaning as a convenient and readable
// opt-in, without hardwiring "enum" specially into the language
//
skat_game: @enum<i16> type = {
    diamonds := 9;
    hearts;  // 10
    spades;  // 11
    clubs;   // 12
    grand    := 20;
    null     := 23;
}
```

Consider `hearts`: It's a member object declaration, but it doesn't have a type (or a default value) which is normally illegal, but here it's okay because the `@enum<i16>` metafunction fills them in: It iterates over all the data members and gives each one the underlying type (here explicitly specified as `i16`, otherwise it would be computed as the smallest signed type that's big enough), and an initializer (by default one higher than the previous enumerator).

Unlike C `enum`, this `@union` is scoped and strongly type (does not implicitly convert to the underlying type.

Unlike C++11 `enum class`, it's "just a `type`" which means it can naturally also have member functions and other things that a type can have:

``` cpp title="Example: An @enum type with a member function"
janus: @enum type = {
    past;
    future;

    flip: (inout this) == {
        if this == past { this = future; }
        else { this = past; }
    }
}
```

There's also a `flag_enum` variation with power-of-two semantics and an unsigned underlying type:

``` cpp title="Example: Using @flag_enum"
// file_attributes is declaratively a safe flag enum type:
// same as enum, but with a minimal-size unsigned underlying
// type by default, and values that automatically start at 1
// and rise by powers of two if the user didn't write their
// own value, and bitwise operations plus .has(flags),
// .set(flags), and .clear(flags)... the word "flag_enum"
// carries all that meaning as a convenient and readable
// opt-in without hardwiring "[Flags]" specially into the
// language
//
file_attributes: @flag_enum<u8> type = {
    cached;     // 1
    current;    // 2
    obsolete;   // 4
    cached_and_current := cached | current;
}
```


#### `union`

`@union` declaratively opts into writing a safe discriminated union/variant dynamic type. For example:

``` cpp title="Example: Using @union"
// name_or_number is declaratively a safe union/variant type:
// it has a discriminant that enforces only one alternative
// can be active at a time, members always have a name, and
// each member has .is_member() and .member() accessors...
// the word "union" carries all that meaning as a convenient
// and readable opt-in without hardwiring "union" specially
// into the language
//
name_or_number: @union type = {
    name: std::string;
    num : i32;
}

main: () = {
    x: name_or_number = ();

    x.set_name("xyzzy");            // now x is a string
    std::cout << x.name();          // prints the string

    // trying to use x.num() here would cause a Type safety
    // contract violation, because x is currently a string

    x.set_num( 120 );               // now x is a number
    std::cout << x.num() + 3;       // prints 123
}
```

Unlike C `union`, this `@union` is safe to use because it always ensures only the active type is accessed.

Unlike C++11 `std::variant`, this `@union` is easier to use because its alternatives are anonymous, and safer to use because each union type is a distinct type. [^variant]

Each `@union` type has its own type-safe name, has clear and unambiguous named members, and safely encapsulates a discriminator to rule them all. Sure, it uses unsafe casts in the implementation, but they are fully encapsulated, where they can be tested once and be safe in all uses. That makes @union:

Because a `@union type` is still a `type`, it can naturally have other things normal types can have, such as template parameter lists and member functions:

``` cpp title="Example: A templated custom safe union type"
name_or_other: @union <T:type> type
= {
    name  : std::string;
    other : T;

    // a custom member function
    to_string: (this) -> std::string = {
        if is_name()       { return name(); }
        else if is_other() { return other() as std::string; }
        else               { return "invalid value"; }
    }
}

main: () = {
    x: name_or_other<int> = ();
    x.set_other(42);
    std::cout << x.other() * 3.14 << "\n";
    std::cout << x.to_string(); // prints "42" here, but is legal
                                // whichever alternative is active
}
```

### Writing your own metafunctions

### Reflection API reference


## Namespaces

### Overview

For details, see [Design note: Namespaces](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Namespaces).


### `using`



## `requires` constraints



## Aliases

### Namespace aliases

### Type aliases

### Function aliases

### Object aliases


## Modules

### `import`

### `export`



[^u8using]: Or `123.cpp2::u8()` if you aren't `using` the namespace or that specific name.

[^variant]: With `variant`, there's no way to distinguish in the type system between a `variant<int,string>` that stores either an employee id or employee name, and a `variant<int,string>` that stores either a lucky number or a pet unicorn's dominant color.
