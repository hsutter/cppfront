
# Contracts

## Overview

Cpp2 currently supports three kinds of contracts:

- **Preconditions and postconditions.** A function declaration can include `pre(condition)` and `post(condition)` before the `= /* function body */`. Before entering the function body, preconditions are fully evaluated and postconditions are captured (and performs their captures, if any). Immediately before exiting the function body via a normal return, postconditions are evaluated. If the function exits via an exception, postconditions are not evaluated.

- **Assertions.** A function body can write `assert(condition)` assertion statements. Assertions are evaluated when control flow passes through them.

Notes:

- `condition` is an expression that evaluates to `#!cpp true` or `#!cpp false`.

- Optionally, `condition` may be followed by `, "message"`, a message to include if a violation occurs. For example, `pre(condition, "message")`.

- Optionally, a `<Group>` can be written inside `<` `>` angle brackets immediately before the `(`, to designate that this test is part of the [contract group](#contract-groups) named `Group`. If a violation occurs, `Group.report_violation()` will be called. For example, `pre<Group>(condition)`.

For example:

``` cpp title="Precondition and postcondition examples" hl_lines="2 3"
insert_at: (container, where: int, val: int)
    pre<Bounds>( 0 <= where <= container.ssize(), "position (where)$ is outside 'container'" )
    post       ( container.ssize() == container.ssize()$ + 1 )
= {
    _ = container.insert( container.begin()+where, val );
}
```

In this example:

- The `$` captures are performed before entering the function.

- The precondition is part of the `Bounds` safety contract group and is checked before entering the function. If the check fails, say because `where` is `#!cpp -1`, then `#!cpp cpp2::Bounds.report_violation("position -1 is outside 'container'")` is called.

- The postcondition is part of the `Default` safety contract group.  If the check fails, then `#!cpp cpp2::Default.report_violation()` is called.


## <a id="contract-groups"></a> Contract groups

Contract groups are useful to enable or disable or [set custom handlers](#violation-handlers) independently for different groups of contracts. A contract group `G` is just the name of an object that can be called with `G.report_violation()` and `G.report_violation(message)`, where `message` is a `* const char` C-style text string.

You can create new contract groups just by creating new objects that have a `.report_violation` function. The object's name is the contract group's name. The object can be at any scope: local, global, or heap.

For example, here are some ways to use contract groups of type [`cpp2::contract_group`](#violation_handlers), which is a convenient group type:

``` cpp title="Using contract groups" hl_lines="1 4 6 10-12"
GroupA: cpp2::contract_group = ();          // a global group

func: () = {
    GroupB: cpp2::contract_group = ();      // a local group

    GroupC := new<cpp2::contract_group>();  // a dynamically allocated group

    // ...

    assert<GroupA >( some    && condition );
    assert<GroupB >( another && condition );
    assert<GroupC*>( another && condition );
}
```

You can make all the objects in a class hierarchy into a contract group by having a `.report_violation` function in a base class, and then writing contracts in that hierarchy using `<this>` as desired. This technique is used in cppfront's own reflection API:

``` cpp title="Example of using 'this' as a contract group, from cppfront 'reflect.h2'" hl_lines="8 9"
function_declaration: @copyable type =
{
    // inherits from a base class that provides '.report_violation'

    // ...

    add_initializer: (inout this, source: std::string_view)
        pre<this> (!has_initializer(), "cannot add an initializer to a function that already has one")
        pre<this> (parent_is_type(),   "cannot add an initializer to a function that isn't in a type scope")
    = { /*...*/ }

    // ...

}
```


## <a id="violation-handlers"></a> `cpp2::contract_group`, and customizable violation handling

The contract group object could also provide additional functionality. For example, Cpp2 comes with the `cpp2::contract_group` type which allows installing a customizable handler for each object. Each object can only have one handler at a time, but the handler can change during the course of the program. `contract_group` supports:

- `.set_handler(pfunc)` accepts a pointer to a handler function with signature `#!cpp * (* const char)`.

- `.get_handler()` returns the current handler function pointer, or null if none is installed.

- `.has_handler()` returns whether there is a current handler installed.

- `.enforce(condition, message)` evaluates `condition`, and if it is `false` then calls `.report_violation(message)`.

Cpp2 comes with five predefined `contract group` global objects in namespace `cpp2`:

- `Default`, which is used as the default contract group for contracts that don't specify a group.

- `Type` for type safety checks.

- `Bounds` for bounds safety checks.

- `Null` for null safety checks.

- `Testing` for general test checks.

For these groups, the default handler is `cpp2::report_and_terminate`, which prints information about the violation to `std::cerr` and then calls `std::terminate()`. But you can customize it to do anything you want, including to integrate with any third-party or in-house error reporting system your project is already using. For example:

``` cpp title="Example of customized contract violation handler" hl_lines="2 8-9"
main: () -> int = {
    cpp2::Default.set_handler(call_my_framework&);
    assert<Default>(false, "this is a test, this is only a test");
    std::cout << "done\n";
}

call_my_framework: (msg: * const char) = {
    //  You can do anything you like here, including arbitrary work
    //  and integration with your current error reporting libraries
    std::cout
        << "sending error to my framework... ["
        << msg << "]\n";
    exit(0);
}
//  Prints:
//      sending error to my framework... [this is a test, this is only a test]
```
