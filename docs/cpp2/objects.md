## Overview

An object can be declared at any scope: in a namespace, in a `type`, in a function, in an expression.

Its declaration is written using the same **name `:` kind `=` value** [declaration syntax](../cpp2/declarations.md) as everything in Cpp2:

- **name** starts with a letter and is followed by other letters, digits, or `_`. Examples: `count`, `skat_game`, `Point2D` are valid names.

- **kind** is the object's type. In most places, except type scopes, you can write the `_` wildcard as the type (or omit the type entirely) to ask for the type to be deduced. When the type is a template and the templated arguments can be inferred from the constructor (via [CTAD](../welcome/hello-world.md#CTAD)).

- **value** is the object's initial value. To use the default-constructed value, write `()`.


For example:

``` cpp title="Example: Declaring some objects"
//  numbers is an object of type std::vector<point2d>,
//  defined as having the initial contents 1, 2, 3
numbers: std::vector<int> = (1, 2, 3);
numbers: std::vector = (1, 2, 3);       // same, deducing the vector's type

//  count is an object of type int, defined as having initial value -1
count: int = -1;
count: _ = -1;      // same, deducing the object's type with the _ wildcard
count := -1;        // same, deducing the object's type by just omitting it
```


## Heap objects

Objects can also be allocated on the heap using `arena.new <T> (/*initializer, arguments)` where `arena` is any object that acts as a memory arena and provides a `.new` function template. Two memory arena objects are provided in namespace `cpp2`:

- `unique.new<T>` calls `std::make_unique` and returns a `std::unique_ptr`.

- `shared.new<T>` calls `std::make_shared` and returns a `std::shared_ptr`.

The default is `unique.new` if you don't specify an arena object.

For example (see [types](types.md) for more details about writing types):


``` cpp title="Example: Heap allocation"
f: () -> std::shared_ptr<widget>
= {
    //  Dynamically allocate an object owned by a std::unique_ptr
    //  'vec' is a unique_ptr<vector<i32>> containing three values
    vec := new<std::vector<i32>>(1, 2, 3);
        // shorthand for 'unique.new<...>(...)'
    std::cout << vec*.ssize();  // prints 3

    //  Dynamically allocate an object with shared ownership
    wid := cpp2::shared.new<widget>();
    store_a_copy( wid );        // store a copy of 'wid' somewhere
    return wid;                 // and move-return a copy too

} // as always in C++, vec is destroyed here automatically, which
  // destroys the heap vector and deallocates its dynamic memory
```


## Guaranteed initialization

TODO

