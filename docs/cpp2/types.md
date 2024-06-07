
# Types

## Overview

A user-defined `type` is written using the same **name `:` kind `=` value** [declaration syntax](../cpp2/declarations.md) as everything in Cpp2. The type's "value" is a `{}`-enclosed body containing more declarations.

In a `type`, data members are private by default, and functions and nested types are public by default. To explicitly declare a type scope declaration `#!cpp public`, `#!cpp protected`, or `#!cpp private`, write that keyword at the beginning of the declaration.

``` cpp title="Writing a simple type" hl_lines="1"
mytype: type =
{
    // data members are private by default
    x: std::string;

    // functions are public by default
    protected f: (this) = { do_something_with(x); }

    // ...
}
```

## <a id="this-parameter"></a> `#!cpp this` — The parameter name

**`#!cpp this`** is a synonym for the current object. Inside the scope of a type that has a member named `member`, `member` by default means `#!cpp this.member`.

> Note: In Cpp2, `#!cpp this` is not a pointer.

The name `#!cpp this` may only be used for the first parameter of a type-scope function (aka member function). It is never declared with an explicit `: its_type` because its type is always the current type.

`#!cpp this` can be an `in` (default), `inout`, `out`, or `move` parameter. Which you choose naturally determines what kind of member function is being declared:

- **`#!cpp in this`**: Writing `#!cpp myfunc: (this /*...*/)`, which is shorthand for `#!cpp myfunc: (in this /*...*/)`, defines a Cpp1 `#!cpp const`-qualified member function, because  `in` parameters are `#!cpp const`.

- **`#!cpp inout this`**: Writing `#!cpp myfunc: (inout this /*...*/)` defines a Cpp1 non-`#!cpp const` member function.

- **`#!cpp out this`**: Writing `#!cpp myfunc: (out this /*...*/)` defines a Cpp1 constructor... and more. (See below.)

- **`#!cpp move this`**: Writing `#!cpp myfunc: (move this /*...*/)` defines a Cpp1 `#!cpp &&`-qualified member function, or if there are no additional parameters it defines the destructor.

For example, here is how to write read-only member function named `print` that takes a read-only string value and prints this object's data value and the string message:

``` cpp title="The this parameter" hl_lines="4 6"
mytype: type = {
    data: i32;   // some data member (private by default)

    print: (this, msg: std::string) = {
        std::cout << data << msg;
                 // "data" is shorthand for "this.data"
    }

    // ...
}
```

## <a id="this-inheritance"></a> `#!cpp this` — Inheritance

Base types are written as members named `#!cpp this`. For example, just as a type could write a data member as `#!cpp data: string = "xyzzy";`, which is pronounced "`data` is a `string` defined as having the default value `#!cpp "xyzzy"`, a base type is written as `#!cpp this: Shape = (default, values);`, which is pronounced "`#!cpp this` is a `Shape` defined as having these default values."

> Cpp2 syntax has no separate base list or separate member initializer list.

Because base and member subobjects are all declared in the same place (the type body) and initialized in the same place (an `#!cpp operator=` function body), they can be written in any order, including interleaved, and are still guaranteed to be safely initialized in declared order. This means that in Cpp2 you can declare a data member object before a base subobject, so that it naturally outlives the base subobject.

> Cpp2 code doesn't need workarounds like Boost's `base_from_member`, because all of the motivating examples for that can be written directly. See [this explanation](https://github.com/hsutter/cppfront/issues/334#issuecomment-1500984173) for details.

## <a id="virtual-functions"></a> `#!cpp virtual`, `#!cpp override`, and `#!cpp final` — Virtual functions

A `#!cpp this` parameter can additionally be declared as one of the following:

- **`#!cpp virtual`**: Writing `#!cpp myfunc: (virtual this /*...*/)` defines a new virtual function.

- **`#!cpp override`**: Writing `#!cpp myfunc: (override this /*...*/)` defines an override of an existing base class virtual function.

- **`#!cpp final`**: Writing `#!cpp myfunc: (final this /*...*/)` defines a final override of an existing base class virtual function.

A pure virtual function is a function with a `#!cpp virtual this` or `#!cpp override this` parameter and no body.

For example:

``` cpp title="Virtual functions" hl_lines="3 4 14 15"
abstract_base: type
= {
    //  A pure virtual function: virtual + no body
    print: (virtual this, msg: std::string) = { /*...*/ }

    // ...
}

derived: type
= {
    //  'this' is-an 'abstract_base'
    this: abstract_base;

    //  Explicit override
    print: (override this, msg: std::string) = { /*...*/ }

    // ...
}
```


## <a id="implicit"></a> `implicit` — Controlling conversion functions

A `#!cpp this` parameter of an `#!cpp operator=` function can additionally be declared as:

- **`implicit`**: Writing `#!cpp operator=: (implicit out this, /*...*/)` defines a function that will not be marked as "explicit" when lowered to Cpp1 syntax.

> Note: This reverses the Cpp1 default, where constructors are not "explicit" by default, and you have to write "explicit" to make them explicit.


## <a id="operator-equals"></a> `#!cpp operator=` — Construction, assignment, and destruction

All value operations are spelled `#!cpp operator=`, including construction, assignment, and destruction. `#!cpp operator=` sets the value of `#!cpp this` object, so the `#!cpp this` parameter can be passed as anything but `in` (which would imply `#!cpp const`):

- **`#!cpp out this`:** Writing `#!cpp operator=: (out this /*...*/ )` is naturally both a constructor and an assignment operator, because an `out` parameter can take an uninitialized or initialized argument. If you don't also write a more-specialized `#!cpp inout this` assignment operator, Cpp2 will use the `#!cpp out this` function also for assignment.

- **`#!cpp inout this`:** Writing `#!cpp operator=: (inout this /*...*/ )` is an assignment operator (only), because an `inout` parameter requires an initialized modifiable argument.

- **`#!cpp move this`:** Writing `#!cpp operator=: (move this)` is the destructor. No other parameters are allowed, so it connotes "move `#!cpp this` nowhere."

Unifying `#!cpp operator=` enables usable `out` parameters, which is essential for composable guaranteed initialization. We want the expression syntax `#!cpp x = value` to be able to call a constructor or an assignment operator, so naming them both `#!cpp operator=` is consistent.

An assignment operator always returns the same type as `#!cpp this` and automatically performs `#!cpp return this;`.

> Note: Writing `=` always invokes an `#!cpp operator=` (in fact for a Cpp2-authored type, and semantically for a Cpp1-authored type). This avoids the Cpp1 inconsistency that "writing `=` calls `#!cpp operator=`, except when it doesn't" (such as in a Cpp1 variable initialization). Conversely, `#!cpp operator=` is always invoked by `=` in Cpp2.


### <a id="that-parameter"></a> `that` — A source parameter

All type-scope functions can have **`that`** as their second parameter, which is a synonym for the object to be copied/moved from. Like `this`, at type scope it is never declared with an explicit `: its_type` because its type is always the current type.

`that` can be an `in` (default) or `move` parameter. Which you choose naturally determines what kind of member function is being declared:

- **`in that`**: Writing `#!cpp myfunc: (/*...*/ this, that)`, which is shorthand for `#!cpp myfunc: (/*...*/ this, in that)`, is naturally both a copy and move function, because it can accept an lvalue or an rvalue `that` argument. If you don't write a more-specialized `move that` move function, Cpp2 will automatically use the `in that` function also for move.

- **`move that`**: Writing `#!cpp myfunc: (/*...*/ this, move that)` defines a move function.

Putting `this` and `that` together: The most general form of `#!cpp operator=` is **`#!cpp operator=: (out this, that)`**. It works as a unified general {copy, move} x { constructor, assignment } operator, and generates all of four of those in the lowered Cpp1 code if you didn't write a more specific one yourself.


### <a id="generated-operator-equals"></a> `#!cpp operator=` can generalize (A)ssignment from construction, and (M)ove from copy

As mentioned above:
- If you don't write an `#!cpp inout this` function, Cpp2 will use your `#!cpp out this` function in its place (if you wrote one).
- If you don't write a `move that` function, Cpp2 will use your `in that` function in its place (if you wrote one).

> Note: When lowering to Cpp1, this just means generating the applicable special member functions from the appropriate Cpp2 function.

This graphic summarizes these generalizations. For convenience I've numbered the (A)ssignment and (M)ove defaults.

![image](https://user-images.githubusercontent.com/1801526/226261443-03125a35-7890-4cc7-bf7d-f23b3a0bb0df.png)

In Cpp1 terms, they can be described as follows:

- **(M)ove, M1, M2:** If you write a copy constructor or assignment operator, but not a corresponding move constructor or assignment operator, the latter is generated.

- **(A)ssignment, A1, A2, A3:** If you write a copy or move or converting constructor, but not a corresponding copy or move or converting assignment operator, the latter is generated.

- **The arrows are transitive.** For example, if you write a copy constructor and nothing else, the move constructor, copy assignment operator, and move assignment operator are generated.

- **M2 is preferred over A2.** Both M2 and A2 can generate a missing `#!cpp (inout this, move that)` function. If both options are available, Cpp2 prefers to use M2 (generate move assignment from copy assignment, which could itself have been generated from copy construction) rather than A2 (generate move assignment from move construction). This is because M2 is a better fit: Move assignment is more like copy assignment than like move construction, because assignments are designed structurally to set the value of an existing `#!cpp this` object.

The most general `#!cpp operator=` with `that` is `#!cpp (out this, that)`. In Cpp1 terms, it generates all four combinations of { copy, move } x { constructor, assignment }. This is often sufficient, so you can write all these value-setting functions just once. If you do want to write a more specific version that does something else, though, you can always write it too.

> Note: Generating `#!cpp inout this` (assignment) from `#!cpp out this` also generates **converting assignment** from converting construction, which is a new thing. Today in Cpp1, if you write a converting constructor from another type `X`, you may or may not write the corresponding assignment from `X`; in Cpp2 you will get that by default, and it sets the object to the same state as the converting constructor from `X` does.



### <a id="generated-defaults"></a> Minimal functions generated by default

There are only two defaults the language will generate implicitly for a type:

- The only special function every type must have is the destructor. If you don't write it by hand, a public nonvirtual destructor is generated by default.

- If no `#!cpp operator=` functions other than the destructor are written by hand, a public default constructor is generated by default.

All other `#!cpp operator=` functions are explicitly written, either by hand or by opting into applying a metafunction (see below).

> Note: Because generated functions are always opt-in, you can never get a generated function that's wrong for your type, and so Cpp2 doesn’t need to support "=delete" for the purpose of suppressing unwanted generated functions.

### <a id="memberwise-default"></a> Memberwise by default

All copy/move/comparison `#!cpp operator=` functions are memberwise by default in Cpp2. That includes when you write memberwise construction and assignment yourself.

In a hand-written `#!cpp operator=`:

- The body must begin with a series of `member = value;` statements, one for each of the type's data members (including base classes) in declaration order.

- If the body does not mention a member in the appropriate place in the beginning section, by default the member's default initializer is used.

- In an assignment operator (`#!cpp inout this`), you can explicitly skip setting a member by writing `member = _;` where it would normally be set if you know you have a reason to set its value later instead or if the existing value needs to be preserved. (This is rare; for an example, see the generated implementation of the [`union` metafunction](metafunctions.md#union).)

For example:

``` cpp title="Memberwise operator= semantics" hl_lines="9-11 20-22"
mytype: type
= {
    //  data members (private by default)
    name:          std::string;
    social_handle: std::string = "(unknown)";

    //  conversion from string (construction + assignment)
    operator=: (out this, who: std::string) = {
        name = who;
        //  if social_handle is not mentioned, defaults to:
        //      social_handle = "(unknown)";

        //  now that the members have been set,
        //  any other code can follow...
        print();
    }

    //  copy/move constructor/assignment
    operator=: (out this, that) = {
        //  if neither data member is mentioned, defaults to:
        //      name = that.name;
        //      social_handle = that.social_handle;
        print();
    }

    print: (this) = std::cout << "value is [(name)$] [(social_handle)$]\n";
}

//  The above definition of mytype allows all of the following...
main: () = {
    x: mytype = "Jim"; // construct from string
    x = "John";        // assign from string
    y := x;            // copy construct
    y = x;             // copy assign
    z := (move x);     // move construct
    z = (move y);      // move assign
    x.print();         // "value is [] []" - moved from
    y.print();         // "value is [] []" - moved from
}
```

> Note: This makes memberwise semantics symmetric for construction and assignment. In Cpp1, only non-copy/move constructors have a default, which is to initialize a member with its default initializer. In Cpp2, both constructors and assignment operators default to using the default initializer if it's a conversion function (non-`that`, aka non-copy/move), and using memberwise `member = that.member;` for copy/move functions.


## <a id="comparisons"></a> `#!cpp operator<=>` — Unified comparisons

To write comparison functions for your type, usually you just need to write either or both of `operator<=>` and `operator==` with a first parameter of `this` and a second parameter of any type (usually `that` which is of the same type). If you omit the function body, a memberwise comparison will be generated by default.

`operator<=>` must return one of `std::strong_ordering`, `std::partial_ordering`, or `std::weak_ordering`. It makes `<`, `<=`, `>`, and `>=` comparisons available for your type. Prefer a strong ordering unless you have a reason to use a partial or weak ordering. If you write `operator<=>` without a custom function body, `operator==` is generated for you.

`operator==` must return `bool`. It makes `==` and `!=` comparisons available for your type.

For example:

``` cpp title="Writing the <=> operator" hl_lines="5-7 13"
item: type = {
    x: i32         = ();
    y: std::string = ();

    operator<=>: (this, that) -> std::strong_ordering;
        //  memberwise by default: first compares x <=> that.x,
        //  then if those are equal compares y <=> that.y

    // ...
}

test: (x: item, y: item) = {
    if x != y {         //  ok
        //  ...
    }
}
```

The above is the same as in Cpp1 because most of Cpp2's `#!cpp operator<=>` feature has already been merged into ISO C++ (Cpp1). In addition, in Cpp2 comparisons with the same precedence can be safely chained, and always have the mathematically sound transitive meaning or else are rejected at compile time:

- **Valid chains: All `<`/`<=`, all `>`/`>=`, or all `==`.** All mathematically sound and safe chains like `a <= b < c` are supported, with efficient single evaluation of each term. They are "sound" because they are transitive; these chains imply a relationship between `a` and `c` (in this case, the chain implies that `a <= c` is also true).

> Note: These valid chains always give mathematically expected results, even when invoking existing comparison operators authored in Cpp1 syntax.

- **Invalid chains: Everything else.** Nonsense chains like `a >= b < c` and `a != b != c` are compile time errors. They are "nonsense" because they are non-transitive; these chains do not imply any relationship between `a` and `c`.

- **Non-chains: Mixed precedence is not a chain.** Expressions like `a<b == c<d` are not a chain, because `==` has lower precedence than `<`. This simply means what it appears to mean, namely `(a<b) == (c<d)`; the expression evaluates to `#!cpp true` if `a<b` and `c<d` are either both true or both false, otherwise the expression evaluates to `#!cpp false`.

``` cpp title="Chained comparisons" hl_lines="2"
//  If requested is in the range of values [lo, hi)
if lo <= requested < hi {
    // ... do something ...
}
```

For more details, see [P0515R0 "Consistent comparison" section 3.3](https://wg21.link/p0515r0) and [P0893 "Chaining comparisons"](https://wg21.link/p0893).

