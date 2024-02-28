# Declaration syntax

## Overview: Unified declaration syntax

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
> - `==` stresses that this name will always have the given value, to express [aliases](aliases.md) and side-effect-free 'constexpr' [function aliases](aliases.md/#function-aliases).


## <a id="template-parameters"></a> Template parameters

A template parameter list is enclosed by `<` `>` angle brackets, and the parameters separated by commas. Each parameter is declared using the [same syntax as any type or object](declarations.md). If a parameter's **`:`** ***kind*** is not specified, the default is `: type`.

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


## <a id="requires"></a> `#!cpp requires` constraints

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


## Examples

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
