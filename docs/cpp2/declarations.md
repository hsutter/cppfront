# Declarations and aliases

## Unified declarations

All Cpp2 declarations are written as **"_name_ `:` _kind_ `=` _statement_"**.

- The _name_ must be a valid identifier (start with a letter, and consist of letters, digits, or `_`). The name can be variadic (be a name for a list of zero or more things) by writing a `...` suffix at the end of the name.

- The `:` is pronounced **"is a."**

- The _kind_ can start with [template parameters](#template-parameters) and end with [`#!cpp requires` constraints](#requires).

- The `=` is pronounced **"defined as."** For the definition of something that will always have the same value, write `==`, pronounced **"defined as a synonym for"**.

- The _statement_ is typically an expression statement (e.g., `#!cpp a + b();`) or a compound statement (e.g., `#!cpp { /*...*/ return c(d) / e; }`).

Various parts of the syntax allow a `_` "don't care" wildcard or can be omitted entirely to accept a default (e.g., `#!cpp x: int = 0;` can be equivalently written `#!cpp x: _ = 0;` or `#!cpp x := 0;` both of which deduce the type).

> Notes:
>
> - When the type is omitted, whitespace does not matter, and writing `#!cpp x: = 0;` or `#!cpp x : = 0;` or `#!cpp x := 0;` or other whitespace is just a stylistic choice. This documentation's style uses the last one, except when there are multiple adjacent declaration lines this style lines up their `:` and `=`.
>
> - `==` stresses that this name will always have the given value, to express [aliases](#aliases) and side-effect-free 'constexpr' [function aliases](#function-aliases).


### <a id="unnamed-declarations"></a> Unnamed declaration expressions

In an expression, most declarations can be written without a name (just starting with `:`). Such unnamed declaration expressions are useful for single-use temporary variables or 'lambda' functions that don't need a name to be reused elsewhere. For example:

- `#!cpp :widget = 42` is an unnamed expression-local (aka temporary) object of type `widget` defined as having the initial value `#!cpp 42`. It uses the same general syntax, just without declaring a name.

- `#!cpp :(x) = std::cout << x` is an unnamed expression-local generic function expression (aka lambda) defined as having the given one-statement body. The body can include [captures](expressions.md/#captures).

Both just omit the name and make the final `;` optional. Otherwise, they have the identical syntax and meaning as if you declared the same thing with a name outside expression scope (e.g., `w: widget = 42;` or `f: (x) = std::cout << x;`) and then used the name in the expression.

> Note: Throughout Cpp2, every declaration is written with `:`, and every use of `:` is a declaration.



### <a id="function-scope-unification"></a> From functions to local scopes, and back again

The function syntax is deliberately designed to be general, so you can omit parts. This means Cpp2 has no special "lambda function" syntax for unnamed functions; an unnamed function is really an unnamed function, written using the ordinary function just without a name. This scales all the way down to ordinary blocks and statements, which are written the same as functions that have no name or parameters.

We can illustrate this in two directions. First, let's start with a full function, and successively omit optional parts that we aren't currently using:

``` cpp title="Start with a full function, and successively omit optional parts if unused" hl_lines="1 5 9 13"
// Full named function
f:(x: int = init) = { /*...*/ }     // x is a parameter to the function
f:(x: int = init) = statement;      // same, { } is implicit

// Omit name => anonymous function (aka 'lamba')
 :(x: int = init) = { /*...*/ }     // x is a parameter to the function
 :(x: int = init) = statement;      // same, { } is implicit

// Omit declaration => local and immediate (aka 'let' in other languages)
  (x: int = init)   { /*...*/ }     // x is a parameter to this
  (x: int = init)   statement;      //  compound or single-statement

// Omit parameters => ordinary block or statement
                    { /*...*/ }     // ordinary compound statement
                    statement;      // ordinary statement
```

Conversely, we can start with an ordinary block or statement, and successively build it up to make it more powerful:

``` cpp title="Start with an ordinary block or statement, and successively add parts" hl_lines="1 5 9 13"
// Ordinary block or statement
                    { /*...*/ }     // ordinary compound statement
                    statement;      // ordinary statement

// Add parameters => more RAII locally-scoped variables
  (x: int = init)   { /*...*/ }     // x is destroyed after this
  (x: int = init)   statement;      //  compound or single-statement

// Add declaration => treat the code as a callable object
 :(x: int = init) = { /*...*/ }     // x is a parameter to the function
 :(x: int = init) = statement;      // same, { } is implicit

// Add name => full named function
f:(x: int = init) = { /*...*/ }     // x is a parameter to the function
f:(x: int = init) = statement;      // same, { } is implicit

```


### <a id="template-parameters"></a> Template parameters

A template parameter list is a [list](common.md#lists) enclosed by `<` `>` angle brackets, and the parameters separated by commas. Each parameter is declared using the [same syntax as any type or object](declarations.md). If a parameter's **`:`** ***kind*** is not specified, the default is `: type`.

For example:

``` cpp title="Declaring template parameters" hl_lines="1-3 8-9"
array: <T: type, size: i32> type
    // parameter T is a type
    // parameter size is a 32-bit int
= {
    // ...
}

tuple: <Ts...: type> type
    // parameter Ts is variadic list of zero or more types
= {
    // ...
}
```


### <a id="requires"></a> `#!cpp requires` constraints

A `#!cpp requires` ***condition*** constraint appears at the end of the ***kind*** of a templated declaration. If the condition evaluates to `#!cpp false`, that specialization of the template is ignored as if not declared.

For example:

``` cpp title="A requires constraint on a variadic function" hl_lines="3"
print: <Args...: type>
       (inout out: std::ostream, args...: Args)
       requires sizeof...(Args) >= 1u
= {
    (out << ... << args);
}
```


### Examples

``` cpp title="Consistent declarations — name : kind = statement" linenums="1" hl_lines="2 6 10 15 24 28 32 43 49 53"
//  n is a namespace defined as the following scope
n: namespace
= {
    //  shape is a templated type with one type parameter T
    //  (equivalent to '<T: type>') defined as the following scope
    shape: <T> type
    = {
        //  point is a type defined as being always the same as
        //  (i.e., an alias for) T
        point_type: type == T;

        //  points is an object of type std::vector<point_type>,
        //  defined as having an empty default value
        //  (type-scope objects are private by default)
        points: std::vector<point_type> = ();

        //  draw is a function taking 'this' and 'canvas' parameters
        //  and returning bool, defined as the following body
        //  (type-scope functions are public by default)
        //
        //  this is an object of type shape (as if written 'this: shape')
        //
        //  where is an object of type canvas
        draw: (this, where: canvas) -> bool
        = {
            //  pen is an object of deduced (omitted) type 'color',
            //  defined as having initial value 'color::red'
            pen := color::red;

            //  success is an object of deduced (omitted) type bool,
            //  defined as having initial value 'false'
            success := false;

            // ...

            return success;
        }

        //  count is a function taking 'this' and returning a type
        //  deduced from its body, defined as a single-expression body
        //  (equivalent to '= { return points.ssize(); }' but omitting
        //  syntax where we're using the language defaults)
        count: (this) = points.ssize();

        //  ...
    }

    //  color is an @enum type (see Note) defined as having these enumerators
    color: @enum type = { red; green; blue; }

    //  calc_next_year is a function defined as always returning the same
    //  value for the same input (i.e., 'constexpr', side effect-free)
    calc_next_year: (year: i32) -> i32 == year + 1;
}
```

> Note: `@enum` is a metafunction, which provides an easy way to opt into a group of defaults, constraints, and generated functions. For details, see [`@enum`](metafunctions.md#enum).


## <a id="aliases"></a> Aliases

Aliases are pronounced **"synonym for"**, and written using the same **name `:` kind `=` value** [declaration syntax](../cpp2/declarations.md) as everything in Cpp2:

- **name** is declared to be a synonym for **value**.

- **kind** can be any of the kinds: `namespace`, `type`, a function signature, or a type.

- **`==`**, pronounced **"defined as a synonym for"**, always precedes the value. The `==` syntax stresses that during compilation every use of the name could be equivalently replaced with the value.

- **value** is the expression that the **name** is a synonym for.


### <a id="namespace-aliases"></a> Namespace aliases

A namespace alias is written the same way as a [namespace](namespaces.md), but using `==` and with the name of another namespace as its value. For example:

``` cpp title="Namespace aliases" hl_lines="1 2 4 5 8 12 16"
//  'chr' is a namespace defined as a synonym for 'std::chrono'
chr    : namespace == std::chrono;

//  'chrlit' is a namespace defined as a synonym for 'std::chrono_literals'
chrlit : namespace == std::chrono_literals;

main: () = {
    using namespace chrlit;

    //  The next two lines are equivalent
    std::cout << "1s is (std::chrono::nanoseconds(1s).count())$ns\n";
    std::cout << "1s is (chr::nanoseconds(1s).count())$ns\n";
}
//  Prints:
//      1s is 1000000000ns
//      1s is 1000000000ns
```


### <a id="type-aliases"></a> Type aliases

A type alias is written the same way as a [type](types.md), but using `==` and with the name of another type as its value. For example:

``` cpp title="Type aliases" hl_lines="1 2 7 10"
//  'imap<T>' is a type defined as a synonym for 'std::map<i32, T>'
imap : <T> type == std::map<i32, T>;

main: () = {
    //  The next two lines declare two objects with identical type
    map1: std::map<i32, std::string> = ();
    map2: imap<std::string> = ();

    //  Assertion they are the same type, using the same_as concept
    static_assert( std::same_as< decltype(map1), decltype(map2) > );
}
```


### <a id="function-aliases"></a> Function aliases

A function alias is written the same way as a [function](functions.md), but using `==` and with a side-effect-free body as its value; the body must always return the same value for the same input arguments. For example:

``` cpp title="Function aliases" hl_lines="1 2 6 9 12 15"
//  'square' is a function defined as a synonym for the value of 'i * i'
square: (i: i32) -> _ == i * i;

main: () = {
    //  It can be used at compile time, with compile time values
    ints: std::array<i32, square(4)> = ();

    //  Assertion that the size is the square of 4
    static_assert( ints.size() == 16 );

    //  And it can be used at run time, with run time values
    std::cout << "the square of 4 is (square(4))$\n";
}
//  Prints:
//      the square of 4 is 16
```

> Note: A function alias is compiled to a Cpp1 `#!cpp constexpr` function.


### <a id="object-aliases"></a> Object aliases

An object alias is written the same way as an [object](objects.md), but using `==` and with a side-effect-free value. For example:

``` cpp title="Function aliases" hl_lines="1 2 5 6"
//  'BufferSize' is an object defined as a synonym for the value 1'000'000
BufferSize: i32 == 1'000'000;

main: () = {
    buf: std::array<std::byte, BufferSize> = ();
    static_assert( buf.size() == BufferSize );
}
```

> Note: An object alias is compiled to a Cpp1 `#!cpp constexpr` object.

