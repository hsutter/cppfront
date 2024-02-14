# Mixing Cpp1 (today's C++) and Cpp2 in the same source file

## Compiling a source file that contains both Cpp1 and Cpp2 code

Cppfront compiles a `.cpp2` file and produces a `.cpp` file to be compiled by your favorite C++20 or higher C++ compiler.

The same `.cpp2` file may contain both Cpp2 syntax and today's "Cpp1" C++ syntax, **side by side but not nested**.

When cppfront compiles such a mixed file, it just passes through the Cpp1 code as-is, and translates the Cpp2 code to Cpp1 in-place. This means that when a call site (call this the "caller") uses a type/function/object (call this the "callee") written in the same file:

- **Code written in all Cpp2 is always order-independent by default.** When a caller written in Cpp2 syntax uses a callee written in Cpp2 syntax, they can appear in either order in the file.

- **Code written in Cpp1 is order-dependent as usual.** When either the caller or the callee (or both) are written in Cpp1 syntax, the callee must be declared before the caller.


## Okay: Cpp1 and Cpp2 side by side, interleaved

For example, this source file is fine, where the Cpp2 and Cpp1 code are side by side and seamlessly call each other directly as usual:

``` cpp title="mixed.cpp2  — Mixing Cpp1 and Cpp2 code side by side in the same source file is okay" linenums="1" hl_lines="4-7"
#include <iostream>                             // Cpp1
#include <string_view>                          // Cpp1

N: namespace = {                                        // Cpp2
    hello: (msg: std::string_view) =                    // Cpp2
        std::cout << "Hello, (msg)$!\n";                // Cpp2
}                                                       // Cpp2

int main() {                                    // Cpp1
    auto words = std::vector{ "Alice", "Bob" }; // Cpp1
    N::hello( words[0] );                       // Cpp1
    N::hello( words[1] );                       // Cpp1
    std::cout << "... and goodnight\n";         // Cpp1
}                                               // Cpp1
```

## Not allowed: Nesting Cpp1 inside Cpp2 (and vice versa)

However, the following source file is not valid, because it tries to nest Cpp2 code inside Cpp1 code, and vice versa:

``` cpp title="ERROR.cpp2 — this is NOT allowed" linenums="1" hl_lines="5 6 9 14"
#include <iostream>                             // Cpp1
#include <string_view>                          // Cpp1

namespace N {                                   // Cpp1
    hello: (msg: std::string_view) =                    // Cpp2 (ERROR here)
        std::cout << "Hello, (msg)$!\n";                // Cpp2 (ERROR here)
}                                               // Cpp1

main: () = {                                            // Cpp2
    auto words = std::vector{ "Alice", "Bob" }; // Cpp1 (ERROR here)
    N::hello( words[0] );                           // ?
    N::hello( words[1] );                           // ?
    std::cout << "... and goodnight\n";             // ?
}                                                       // Cpp2
```

The above nesting is not supported because it would create not just parsing problems but also semantic ambiguities. For example, lines 11-13 are syntactically valid as Cpp1 or as Cpp2, but if they are treated as Cpp2 then the `words[0]` and `words[1]` expressions' `std::vector::operator[]` calls are bounds-checked and bounds-safe by default, whereas if they are treated as Cpp1 then they are not bounds-checked. And that's a pretty important difference to be sure about!

