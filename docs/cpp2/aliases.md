# Aliases

Aliases are pronounced **"synonym for**, and written using the same **name `:` kind `=` value** [declaration syntax](../cpp2/declarations.md) as everything in Cpp2:

- **name** is declared to be a synonym for **value**.

- **kind** can be any of the kinds: `namespace`, `type`, a function signature, or a type.

- **`==`**, pronounced **"defined as a synonym for"**, always precedes the value. The `==` syntax stresses that during compilation every use of the name could be equivalently replaced with the value.

- **value** is the expression that the **name** is a synonym for.


## <a id="namespace-aliases"></a> Namespace aliases

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


## <a id="type-aliases"></a> Type aliases

A namespace alias is written the same way as a [type](types.md), but using `==` and with the name of another type as its value. For example:

``` cpp title="Type aliases" hl_lines="1 2 7 10"
//  'imap<T>' is a type defined as a synonym for 'std::map<i32, T>'
imap : <T> type == std::map<i32, T>;

main: () = {
    //  The next two lines declare two objects with identical type
    map1: std::map<i32, std::string> = ();
    map2: imap<std::string> = ();

    //  Assertion they are the same type, using the same_as concept
    assert( std::same_as< decltype(map1), decltype(map2) > );
}
```


## <a id="function-aliases"></a> Function aliases

A function alias is written the same way as a [function](functions.md), but using `==` and with a side-effect-free body as its value; the body must always return the same value for the same input arguments. For example:

``` cpp title="Function aliases" hl_lines="1 2 6 9 12 15"
//  'square' is a function defined as a synonym for the value of 'i * i'
square: (i: i32) -> _ == i * i;

main: () = {
    //  It can be used at compile time, with compile time values
    ints: std::array<i32, square(4)> = ();

    //  Assertion that the size is the square of 4
    assert( ints.size() == 16 );

    //  And if can be used at run time, with run time values
    std::cout << "the square of 4 is (square(4))$\n";
}
//  Prints:
//      the square of 4 is 16
```

> Note: A function alias is compiled to a Cpp1 `#!cpp constexpr` function.


## <a id="object-aliases"></a> Object aliases

An object alias is written the same way as an [object](objects.md), but using `==` and with a side-effect-free value. For example:

``` cpp title="Function aliases" hl_lines="1 2 5 6"
//  'BufferSize' is an object defined as a synonym for the value 1'000'000
BufferSize: i32 == 1'000'000;

main: () = {
    buf: std::array<std::byte, BufferSize> = ();
    assert( buf.size() == BufferSize );
}
```

> Note: An object alias is compiled to a Cpp1 `#!cpp constexpr` object.

