
# Metafunctions

A metafunction is a compile-time function that can participate in interpreting the meaning of a declaration, and can:

- apply defaults (e.g., `interface` makes functions virtual by default)
- enforce constraints (e.g., `value` enforces that the type has no virtual functions)
- generate additional functions and other code (e.g., `value` generates copy/move/comparison operations for a type if it didn't write them explicitly)

The most important thing about metafunctions is that they are not hardwired language features — they are compile-time library code that uses the reflection and code generation API, that lets the author of an ordinary type easily opt into a named set of defaults, requirements, and generated contents. This approach is essential to making the language simpler, because it lets us avoid hardwiring special "extra" types into the language and compiler.

## Applying metafunctions

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

## Generating source code at compile time

TODO


## Built-in metafunctions

The following metafunctions are provided in the box with cppfront.

### interface

TODO


### polymorphic_base

TODO


### ordered, weakly_ordered, partially_ordered

TODO


### copyable

TODO


### basic_value, value, weakly_ordered_value, partially_ordered_value

TODO


### struct

TODO


### `enum`, `flag_enum`

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

Unlike C `enum`, this `@enum` is scoped and strongly typed (does not implicitly convert to the underlying type.

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


### `union`

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

Each `@union` type has its own type-safe name, has clear and unambiguous named members, and safely encapsulates a discriminator to rule them all. Sure, it uses unsafe casts in the implementation, but they are fully encapsulated, where they can be tested once and be safe in all uses.

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

### cpp1_rule_of_zero

TODO

### print

TODO


## Writing your own metafunctions

TODO


## Reflection API reference

TODO


[^variant]: With `variant`, there's no way to distinguish in the type system between a `variant<int,string>` that stores either an employee id or employee name, and a `variant<int,string>` that stores either a lucky number or a pet unicorn's dominant color.
