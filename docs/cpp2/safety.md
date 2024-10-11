
# Safety and unchecked code

Cpp2 aims to be safe by default, usually entirely at compile time, and when needed at run time.

When Cpp2 rejects unsafe code (e.g., signed/unsigned comparison) or ensuring safety can require run-time checks (e.g., subscripts bounds checks), you can opt out as needed in two ways:

- at a specific place in your code, using `unchecked_*` functions (these are in namespace `cpp2::`, but can be used unqualified from Cpp2 code)
- for a whole source file, using `-no-*-checks` switches

Nearly always, you should opt out at a specific place in your code where you are confident the result is okay, and if there is a run-time check you have measured that the performance difference matters such as in a hot loop.


### <a id="mixed-sign-comparison"></a> Integer mixed-sign `<`, `<=`, `>`, and `>=` (compile-time enforced)

Comparing signed and unsigned integer values directly using `<`, `<=`, `>`, or `>=` can give wrong results, and so such comparisons are rejected at compile time.

To disable this check at a specific place in your code, use the appropriate `unchecked_cmp_*` function instead of the operator notation: `unchecked_cmp_less`, `unchecked_cmp_less_eq`,`unchecked_cmp_greater`, or `unchecked_cmp_greater_eq`.

For example:

``` cpp title="Integer comparisons" hl_lines="7"
main: () = {
    x: i32 = 42;
    y: u32 = 43;

    if x < y { }                            // unsafe, therefore error by default

    if unchecked_cmp_less(x,y) { }          // ok, explicit "trust me" opt-out
}
```

To disable these checks for the entire source file, you can use cppfront's `-no-comparison-checks` switch:

``` bash title="Disable prevention of mixed-sign integer comparisons" hl_lines="3"
cppfront myfile.cpp2                        # mixed-sign int comparisons banned

cppfront myfile.cpp2 -no-comparison-checks  # mixed-sign int comparisons allowed
```


### <a id="division-by-zero"></a> Division by zero (run-time checked)

Dividing integers by zero is undefined behavior, and is rejected at run time by checking the denominator is nonzero.

To disable this check at a specific place in your code, use `unchecked_div`. For example:

``` cpp title="Division by zero" hl_lines="7"
main: () = {
    x := 42;
    y := 0;

    z := x/y;                               // unsafe, therefore run-time checked

    w := unchecked_div(x,y)                 // ok, explicit "trust me" opt-out
}
```

To disable these checks for the entire source file, you can use cppfront's `-no-div-zero-checks` switch:

``` bash title="Disable prevention of division by zero" hl_lines="3"
cppfront myfile.cpp2                        # division by zero checked

cppfront myfile.cpp2 -no-div-zero-checks    # division by zero not checked
```


### <a id="null-dereference"></a> Null dereference (run-time checked)

Dereferencing a null pointer is undefined behavior, and is rejected at run time by checking the pointer is not null.

To disable this check at a specific place in your code, use `unchecked_dereference`. For example:

``` cpp title="Null dereference" hl_lines="6"
main: () = {
    p: *int = cpp1_func();                  // could be initialized to null

    p* = 42;                                // unsafe, therefore run-time checked

    unchecked_dereference(p) = 42;          // ok, explicit "trust me" opt-out
}
```

To disable these checks for the entire source file, you can use cppfront's `-no-null-checks` switch:

``` bash title="Disable prevention of null deference" hl_lines="3"
cppfront myfile.cpp2                        # null dereferences checked

cppfront myfile.cpp2 -no-null-checks        # null dereferences not checked
```


### <a id="subscript-bounds"></a> Subscript bounds (run-time checked)

Accessing an out of bounds subscript is undefined behavior, and is rejected at run time by checking the subscript is in bounds. For an expression `a[b]` where

- `a` is contiguous and supports `std::size(a)`, and
- `b` is an integral value

the cppfront compiler injects a check that **`0 <= b < std::size(a)`** before the call to `a[b]`.

To disable this check at a specific place in your code, use `unchecked_subscript`. For example:

``` cpp title="Subscript bounds" hl_lines="12 13"
main: () = {
    v: std::vector = ( 1, 2, 3, 4, 5 );
    s: std::span   = v;

    idx := calc_index(s);

    v[idx] += 42;                           // unsafe, therefore run-time checked
    s[idx] += 84;                           // unsafe, therefore run-time checked

    // manually hoist the check and do it myself
    if (0 ..< v.size()).contains(idx) {
        unchecked_subscript(v,idx) += 42;   // ok, explicit "trust me" opt-out
        unchecked_subscript(s,idx) += 84;   // ok, explicit "trust me" opt-out
    }
}
```

To disable these checks for the entire source file, you can use cppfront's `-no-subscript-checks` switch:

``` bash title="Disable prevention of out-of-bounds subscripts" hl_lines="3"
cppfront myfile.cpp2                        # subscript bounds checked

cppfront myfile.cpp2 -no-subscript-checks   # subscript bounds not checked
```

