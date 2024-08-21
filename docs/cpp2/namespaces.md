
# Namespaces

## Overview

A namespace `N` can contain declarations that are then accessed by writing `N::` or [`using`](#using) the namespace or declaration. For example:

``` cpp title="Declaring some things in a namespace" hl_lines="2 8"
//  A namespace to put all the names provided by a widget library
widgetlib: namespace = {
    widget: type = { /*...*/ }
    // ... more things ...
}

main: () = {
    w: widgetlib::widget = /*...*/;
}
```


## <a id="using"></a> `using`

A `#!cpp using` statement brings names declared in another namespace into the current scope as if they had been declared in the current scope.

`#!cpp using a_namespace::a_name ;` brings the single name `a_name` into scope.

`#!cpp using a_namespace::_ ;` brings all the namespace's names into scope using the `#!cpp _` wildcard.

For example:

``` cpp title="using statements" hl_lines="13 14 20 21"
//  A namespace to put all the names provided by a widget library
widgetlib: namespace = {
    widget: type = { /*...*/ }
    // ... more things ...
}

main: () = {
    //  Explicit name qualification
    w: widgetlib::widget = /*...*/;

    {
        //  Using the specific name, no widgetlib:: qualification needed
        using widgetlib::widget;
        w2: widget = /*...*/;
        // ...
    }

    {
        //  Using the whole namespace, no widgetlib:: qualification needed
        using widgetlib::_;
        w3: widget = /*...*/;
        // ...
    }

    // ...
}
```


