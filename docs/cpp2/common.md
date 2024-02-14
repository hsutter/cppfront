# Common programming concepts

## Comments

The usual `// line comments` and `/* stream comments */` are supported. For example:

``` cpp title="Example: Comments"
//  A line comment: After //, the entire
//  rest of the line is part of the comment

/*
    A stream comment: After /*, everything until the
    next * / (without a space between) is part of the
    comment. Note that stream comments do not nest.
 */
```

## Fundamental data types

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

## Type qualifiers

Types can be qualified with `const` and `*`. Types are written left-to-right, so a qualifier always applies to what immediately follows it. For example, to declare a `const` pointer to a non-`const` pointer to a `const i32` object, write:

``` cpp title="Example: Type qualifiers"
//  A const pointer to a non-const pointer to a const i32 object
p: const * * const i32;
```

## Literals

Cpp2 supports the same `'c'`haracter, `"string"`, binary, integer, and floating point literals as Cpp1, including most Unicode encoding prefixes and raw string literals.

Cpp2 supports using Cpp1 user-defined literals for compatibility, to support seamlessly using existing libraries. However, because Cpp2 has unified function call syntax (UFCS), the preferred way to author the equivalent in Cpp2 is to just write a function or type name as a `.` call suffix. For example:

- You can create a `u8` value by writing either `u8(123)` or **`123.u8()`**. [^u8using]

- You can write a 'constexpr' function like `nm: (value: i64) -> my_nanometer_type == { /*...*/ }` that takes an integer and returns a value of a strongly typed "nanometer" type, and then create a `nm` value by writing either `nm(123)` or **`123.nm()`**.

Both **`123.n()`** and **`123.u8()`** are very similar to user-defined literal syntax, and more general.

## Operators

Operators have the same precedence and associativity as in Cpp1, but some unary operators that are prefix (always or sometimes) in Cpp1 are postfix (always) in Cpp2.

## Unary operators

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

## Binary operators

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
