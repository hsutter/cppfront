## Overview

An object can be declared at any scope: in a namespace, in a `type`, in a function, in an expression.

Its declaration is written using the same **name `:` kind `=` value** [declaration syntax](../cpp2/declarations.md) as everything in Cpp2:

- **name** starts with a letter and is followed by other letters, digits, or `_`. Examples: `count`, `skat_game`, `Point2D` are valid names.

- **kind** is the object's type. In most places, except type scopes, you can write the `_` wildcard as the type (or omit the type entirely) to ask for the type to be deduced. When the type is a template, the templated arguments can be inferred from the constructor (via [CTAD](../welcome/hello-world.md#ctad)).

- **value** is the object's initial value. To use the default-constructed value, write `()`.


For example:

``` cpp title="Declaring some objects" hl_lines="3 4 7-9 12 13"
//  numbers is an object of type std::vector<int>,
//  defined as having the initial contents 1, 2, 3
numbers: std::vector<int> = (1, 2, 3);
numbers: std::vector = (1, 2, 3);       // same, deducing the vector's type

//  count is an object of type int, defined as having initial value -1
count: int = -1;
count: _ = -1;      // same, deducing the object's type with the _ wildcard
count := -1;        // same, deducing the object's type by just omitting it

//  pi is a variable template; == signifies the value never changes (constexpr)
pi: <T: type> T == 3.14159'26535'89793'23846L;
pi: _ == 3.14159'26535'89793'23846L;    // same, deducing the object's type
```

The object type can be deduced by writing `_` (the default, so it can be omitted). You can use `is` to declare a type constraint (e.g., a concept) that a deduced type must match, in which case `_` is required. For example:

``` cpp title="Declaring an object of constrained deduced type" hl_lines="2"
//  number's type is deduced, but must match the std::regular concept
number: _ is std::regular = some_factory_function();
```


## <a id="init"></a> Guaranteed initialization

Every object must be initialized using `=` before it is used.

An object in any scope can be initialized at its declaration. For example:

``` cpp title="Initializing objects when they are declared" hl_lines="4 10"
shape: type = {
    //  An object at type scope (data member)
    //  initialized with its type's default value
    points: std::vector<point2d> = ();

    draw: (this, where: canvas) -> bool
    = {
        //  An object at function scope (local variable)
        //  initialized with color::red
        pen := color::red;

        // ...
    }

    //  ...
}
```

Additionally, at function local scope an object `obj` can be initialized separately from its declaration. This can be useful when the object must be declared before a program-meaningful initial value is known (to avoid a dead write of a wrong 'dummy' value), and/or when the object may be initialized in more than one way depending on other logic (e.g., by using different constructors on different paths). The way to do this is:

- Declare `obj` without an `= initializer` value, for example: `obj: some_type;`. This allocates stack space for the object, but does not construct it.

- `obj` must have a definite first use on every `#!cpp if`/`#!cpp else` branch path (and that first use must not be inside any loop), and

- that definite first use must be of the form `obj = value;` which is a constructor call, or else pass `obj` as an `out` argument to an `out` parameter (which is also effectively a constructor call, and performs the construction in the callee).

For example:

``` cpp title="Initializing local objects after they are declared" hl_lines="5 14 17 21"
f: () = {
    buf: std::array<std::byte, 1024>;   // uninitialized
    //  ... calculate some things ...
    //  ...  no uses of buf here  ...
    buf = some_calculated_value;        // constructs (not assigns) buf
    //  ...
    std::cout << buf[0];                // ok, a has been initialized
}

g: () = {
    buf: std::array<std::byte, 1024>;   // uninitialized
    if flip_coin_is_heads() {
        if heads_default_is_available {
            buf = copy_heads_default(); // constructs buf
        }
        else {
            buf = (other, constructor); // constructs buf
        }
    }
    else {
        load_from_disk( out buf );      // constructs buf (*)
    }
    std::cout << buf[0];                // ok, a has been initialized
}

load_from_disk: (out x) = {
    x = /* data read from disk */ ;     // when `buffer` is uninitialized,
}                                       // constructs it; otherwise, assigns
```

In the above example, note the simple rule for branches: The local variable must be initialized on both the `#!cpp if` and `#!cpp else` branches, or neither branch.


## <a id="heap"></a>Heap objects

Objects can also be allocated on the heap using `#!cpp xxx.new <T> (/*initializer, arguments*/)` where `xxx` is any object that acts as a memory allocator and provides a `#!cpp .new` function template. Two memory allocators objects are provided in namespace `cpp2`:

- `#!cpp unique.new<T>` calls `std::make_unique<T>` and returns a `std::unique_ptr<T>`.

- `#!cpp shared.new<T>` calls `std::make_shared<T>` and returns a `std::shared_ptr<T>`.

The default is `#!cpp unique.new` if you don't specify an allocator object.

For example (see [types](types.md) for more details about writing types):

``` cpp title="Heap allocation" hl_lines="3-6 10-11"
f: () -> std::shared_ptr<widget>
= {
    //  Dynamically allocate an object owned by a std::unique_ptr
    //  'vec' is a unique_ptr<vector<i32>> containing three values
    vec := new<std::vector<i32>>(1, 2, 3);
            // shorthand for 'unique.new<...>(...)'
    std::cout << vec*.ssize();  // prints 3
                    // note that * dereference is a suffix operator

    //  Dynamically allocate an object with shared ownership
    wid := cpp2::shared.new<widget>();
    store_a_copy( wid );        // store a copy of 'wid' somewhere
    return wid;                 // and move-return a copy too

} // as always in C++, vec is destroyed here automatically, which
  // destroys the heap vector and deallocates its dynamic memory
```

