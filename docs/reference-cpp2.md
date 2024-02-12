
# Cpp2 reference


## Common programming concepts

### Comments

Cpp2 supports the same `// line comments` and `/* stream comments */` as Cpp1 (today's C++ syntax).

### Fundamental data types

Cpp2 supports the same fundamental types as today's Cpp1, but additionally provides the following aliases in namespace `cpp2`:

| Known-width types | Synonym for |
|---|---|
| `i8`        | `std::int8_t`        |
| `i16`       | `std::int16_t`       |
| `i32`       | `std::int32_t`       |
| `i64`       | `std::int64_t`       |
| `u8`        | `std::uint8_t`       |
| `u16`       | `std::uint16_t`      |
| `u32`       | `std::uint32_t`      |
| `u64`       | `std::uint64_t`      |


| Variable-width types (Cpp2-compatible single-word names) | Synonym for (multi-word names not allowed in Cpp2) |
|---|---|
| `ushort`      | `unsigned short`       |
| `uint`        | `unsigned int`         |
| `ulong`       | `unsigned long`        |
| `longlong`    | `long long`            |
| `ulonglong`   | `unsigned long long`   |
| `longdouble`  | `long double`          |

| For compatibility/interop only | Synonym for | Notes |
|---|---|---|
| `_schar`     | `signed char`   | Normally, prefer `i8` instead |
| `_uchar`     | `unsigned char` | Normally, prefer `u8` instead |

### Literals

Cpp2 supports the same `'c'`haracter, `"string"`, binary, integer, and floating point literals as Cpp1, including most Unicode encoding prefixes and raw string literals.

Cpp2 supports using Cpp1 user-defined literals. However, because Cpp2 has unified function call syntax (UFCS), the preferred way to author the equivalent in Cpp2 is to just write a function or type name as a `.` call suffix. For example:

- You can create a `u8` value by writing either `u8(123)` or **`123.u8()`**. [^u8using]

- You can write a 'constexpr' function like `nm: (value: i64) -> my_nanometer_type == { /*...*/ }` that takes an integer and returns a value of a strongly typed "nanometer" type, and then create a `nm` value by writing either `nm(123)` or **`123.nm()`**.

Both `123.n()` and `123.u8()` are very similar to user-defined literal syntax, and more general.


### Captures, including interpolations


### Control flow

#### `if` and `else` branches

#### `for`, `while`, and `do` loops

#### `inspect` expressions (pattern matching)


## Functions

### Named functions

### Unnamed function expressions

### Design note: Unifying functions and local scopes


## Types and type-scope functions

### Base types

### Virtual functions

### `operator=`: Unified construction and assignment

### `operator<=>`: Unified comparisons (mostly in C++20)


## Metafunctions

### Built-in metafunctions

### Writing your own metafunctions

### Reflection API reference


## Namespaces

### `using`


## Modules

### `import`

### `export`



[^u8using]: Or `123.cpp2::u8()` if you aren't `using` the namespace or that specific name.
