# Common programming concepts

## <a id="main"></a> `main`

As always, `main` is the entry point of the program. For example:

`main` can have either:

- No parameters: &emsp; **`#!cpp main: () /*etc.*/`**

- One parameter of implicit type named `args`: &emsp; **`#!cpp main: (args) /*etc.*/`**

    - The type of `args` cannot be explicitly specified. It is always `cpp2::args_t`, which behaves similarly to a `#!cpp const std::array<std::string_view>`.

    - Using `args` performs zero heap allocations. Every `string_view` is directly bound to the string storage provided by host environment.

    - `args.argc` and `args.argv` additionally provide access to the raw C/C++ `main` parameters.

``` cpp title="main with (args)" hl_lines="5 9"
//  Print out command line arguments, then invoke
//  a Qt event loop for a non-UI Qt application
main: (args) -> int
= {
    for args do (arg) {
        std::cout << arg << "\n";
    }

    app: QCoreApplication = (args.argc, args.argv);
    return app.exec();
}
```

`main` can return:

- `#!cpp void`, the default return value for functions. No `#!cpp return` statement is allowed in the body. In this case, the compiled Cpp1 code behaves as if `main` returned `#!cpp int`.

- `#!cpp int`. If the body has no `#!cpp return` statement, the default is to `#!cpp return 0;` at the end of the function body.

- Some other type that your Cpp1 compiler(s) supports as a nonstandard extension.


## <a id="comments"></a> Comments

The usual `#!cpp // line comments` and `#!cpp /* stream comments */` are supported. For example:

``` cpp title="Writing comments"
//  A line comment: After //, the entire
//  rest of the line is part of the comment

/*
    A stream comment: After /*, everything until the
    next * / (without a space between) is part of the
    comment. Note that stream comments do not nest.
 */
```


## <a id="lists"></a> Lists and commas

All lists use `,` commas between list items, and may be enclosed by

- `(` `)` parentheses, for most lists

- `[` `]` brackets, for calling the subscript operator

- `<` `>` angle brackets, for template parameter/argument lists

For example:

``` cpp title="Lists" hl_lines="1 4 6 7"
print: <T,U> (t: T, u: U) = std::cout << t << u << "\n";

main: () = {
    array: std::array = ('A', 'B', 'C');

    for (0, 1, 2) do (e) {
        print( e, array[e] );
    }
    //  Prints:
    //      0A
    //      1B
    //      2C
}
```


An extra comma at the end of the list, before the closing `)` or `>`, is always allowed but ignored if present (for details, see [Design note: Commas](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Commas)).

For example:

``` cpp title="Lists, using optional trailing commas just because we can" hl_lines="1 4 6 7"
print: <T,U,> (t: T, u: U,) = std::cout << t << u << "\n";

main: () = {
    array: std::array = ('A', 'B', 'C',);

    for (0, 1, 2,) do (e) {
        print( e, array[e,], );
    }
    //  Prints:
    //      0A
    //      1B
    //      2C
}
```


## <a id="keywords"></a> Reserved keywords

Cpp2 has very few globally reserved keywords; nearly all keywords are contextual, where they have their special meaning when they appear in a particular place in the grammar. For example:

- `new` is used as an ordinary function to do allocation (e.g., `shared.new<widget>(1, 2, 3)`).

- `struct` and `enum` are used as function names in the metafunctions library.

- `type` can be used as an ordinary name (e.g., `std::common_type<T1,T2>::type`).

In rare cases, usually when consuming code written in other languages, you may need to write a name that is a reserved keyword. The way to do that is to prefix it with `__identifer__`, which treats it as an ordinary identifier (without the prefix).


## <a id="fundamental-types"></a> Fundamental data types

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
| `ushort`      | `#!cpp unsigned short`       |
| `uint`        | `#!cpp unsigned int`         |
| `ulong`       | `#!cpp unsigned long`        |
| `longlong`    | `#!cpp long long`            |
| `ulonglong`   | `#!cpp unsigned long long`   |
| `longdouble`  | `#!cpp long double`          |

| For compatibility/interop only,<br> so deliberately ugly names | Synonym for (these multi-word<br> names are not allowed in Cpp2) | Notes |
|---|---|---|
| `_schar`     | `#!cpp signed char`   | Normally, prefer `i8` instead |
| `_uchar`     | `#!cpp unsigned char` | Normally, prefer `u8` instead |

## <a id="type-qualifiers"></a> Type qualifiers

Types can be qualified with `#!cpp const` and `#!cpp *`. Types are written left-to-right, so a qualifier always applies to what immediately follows it. For example, to declare a `#!cpp const` pointer to a non-`#!cpp const` pointer to a `#!cpp const i32` object, write:

``` cpp title="Using type qualifiers"
//  A const pointer to a non-const pointer to a const i32 object
p: const * * const i32;
```

## <a id="literals"></a> Literals

Cpp2 supports the same `#!cpp 'c'`haracter, `#!cpp "string"`, binary, integer, and floating point literals as Cpp1, including most Unicode encoding prefixes and raw string literals.

Cpp2 supports using Cpp1 user-defined literals for compatibility, to support seamlessly using existing libraries. However, because Cpp2 has [unified function call syntax (UFCS)](expressions.md#ufcs), the preferred way to author the equivalent in Cpp2 is to just write a function or type name as a `.` call suffix. For example:

- You can create a `u8` value by writing either `u8(123)` or **`123.u8()`**. [^u8using]

- You can write a 'constexpr' function like `#!cpp nm: (value: i64) -> my_nanometer_type == { /*...*/ }` that takes an integer and returns a value of a strongly typed "nanometer" type, and then create a `nm` value by writing either `nm(123)` or **`123.nm()`**.

Both **`123.nm()`** and **`123.u8()`** are very similar to user-defined literal syntax, and more general.

## <a id="operators"></a> Operators

Operators have the same precedence and associativity as in Cpp1, but some unary operators that are prefix (always or sometimes) in Cpp1 are postfix (always) in Cpp2.

### <a id="unary-operators"></a> Unary operators

The operators `!`, `+`, and `-` are prefix, as in Cpp1. For example:

``` cpp title="Using prefix operators"
if !vec.empty() {
    vec.emplace_back( -123.45 );
}
```

| Unary operator | Cpp2 example | Cpp1 equivalent |
|---|---|---|
| `!` | `!vec.empty()` | `!vec.empty()` |
| `+` | `#!cpp +100` | `#!cpp +100` |
| `-` | `#!cpp -100` | `#!cpp -100` |

The operators `.`, `*`, `&`, `~`, `++`, `--`, `()`, `[]`, and `$` are postfix. For example:

``` cpp title="Using postfix operators"
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
| `#!cpp .` | `#!cpp obj.f()` | `#!cpp obj.f()` |
| `#!cpp *` | `#!cpp pobj*.f()` | `#!cpp (*pobj).f()` or `#!cpp pobj->f()` |
| `#!cpp &` | `#!cpp obj&` | `#!cpp &obj` |
| `#!cpp ~` | `#!cpp val~` | `#!cpp ~val` |
| `#!cpp ++` | `#!cpp iter++` | `#!cpp ++iter` |
| `#!cpp --` | `#!cpp iter--` | `#!cpp --iter` |
| `(` `)` | `#!cpp f( 1, 2, 3)` | `#!cpp f( 1, 2, 3)` |
| `[` `]` | `#!cpp vec[123]` | `#!cpp vec[123]` |
| `$` | `val$` | _reflection — no Cpp1 equivalent yet_ |

> Because `++` and `--` always have in-place update semantics, we never need to remember "use prefix `++`/`--` unless you need a copy of the old value." If you do need a copy of the old value, just take the copy before calling `++`/`--`.

Unary suffix operators must not be preceded by whitespace. When `*`, `&`, and `~` are used as binary operators they must be preceded by whitespace. For example:

| Unary postfix operators that<br>are also binary operators | Cpp2 example | Cpp1 equivalent |
|---|---|---|
| `#!cpp *` | `#!cpp pobj* * 42` | `#!cpp (*pobj)*42` |
| `#!cpp &` | `#!cpp obj& & mask` <p> (note: allowed in unsafe code only) | `#!cpp &obj & mask` |

For more details, see [Design note: Postfix unary operators vs binary operators](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Postfix-unary-operators-vs-binary-operators).


### <a id="binary-operators"></a> Binary operators

Binary operators are the same as in Cpp1. From highest to lowest precedence:

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


[^u8using]: Or `123.cpp2::u8()` if you aren't `using` the namespace or that specific name.
