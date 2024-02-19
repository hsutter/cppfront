# Declaration syntax

## Unified declaration syntax

All Cpp2 declarations are written as **"_name_ `:` _kind_ `=` _statement_"**.

- The `:` is pronounced **"is a."**

- The `=` is pronounced **"defined as."**

- The _statement_ is typically an expression statement (e.g., `#!cpp a + b();`) or a compound statement (e.g., `#!cpp { /*...*/ return c(d) / e; }`).

- Various parts of the syntax allow a `_` "don't care" wildcard or can be omitted entirely to accept a default (e.g., `#!cpp x: int = 0;` can be equivalently written `#!cpp x: _ = 0;` or `#!cpp x := 0;` both of which deduce the type).

> Note: When the type is omitted, whitespace does not matter, and writing `#!cpp x: = 0;` or `#!cpp x : = 0;` or `#!cpp x := 0;` or other whitespace is just a stylistic choice. This documentation's style uses the last one, except when there are multiple adjacent declaration lines this style lines up their `:` and `=`.


## Examples

``` cpp title="Consistent declarations — name : kind = statement" hl_lines="2 5 10 17 21 25 34 40"
//  n is a namespace defined as the following scope
n: namespace
= {
    //  shape is a type defined as the following scope
    shape: type
    = {
        //  points is an object of type std::vector<point2d>,
        //  defined as having an empty default value
        //  (type-scope objects are private by default)
        points: std::vector<point2d> = ();

        //  draw is a function taking 'this' and 'canvas' parameters
        //  and returning bool, defined as the following body
        //  (type-scope functions are public by default)
        //      - this is as if 'this: shape', an object of type shape
        //      - where is an object of type canvas
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
        count: (this) = points.ssize();

        //  ...
    }

    //  color is an @enum type (see Note)
    color: @enum type = { red; green; blue; }
}
```

> Note: `@enum` is a metafunction, which provides an easy way to opt into a group of defaults, constraints, and generated functions. For details, see [`@enum`, `@flag_enum`](metafunctions.md/#enum-flag_enum)


## `requires` constraints

TODO

