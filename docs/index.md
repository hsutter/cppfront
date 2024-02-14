
# Overview & getting started

## What are Cpp2 and cppfront?

### What is Cpp2?

"Cpp2," short for "C++ syntax 2," is my ([Herb Sutter's](https://github.com/hsutter)) personal project to try to make writing ordinary C++ types/functions/objects be much **simpler and safer**, without breaking backward compatibility. Bjarne Stroustrup said it best:

> "Inside C++, there is a much smaller and cleaner language struggling to get out." <br>&emsp;&emsp;— Bjarne Stroustrup, _The Design and Evolution of C++_ (D&E), 1994
>
> "Say 10% of the size of C++ in definition and similar in front-end compiler size. ... most of the simplification would come from generalization." <br>&emsp;&emsp;— Bjarne Stroustrup, _ACM History of Programming Languages III_, 2007

My goal is to try to prove that Stroustrup is right: that it's possible and desirable to have true C++ with all its expressive power and control and with full backward compatibility, but in a flavor that's 10x simpler with fewer quirks and special cases to remember, [^simpler] and 50x safer where it's far easier to not write security bugs by accident.

We can't make an improvement that large to C++ via gradual evolution to today's syntax, because some important changes would require changing the meaning of code written in today's syntax. For example, we can never change a language feature default in today's syntax, not even if the default creates a security vulnerability pitfall, because changing a default would break vast swathes of existing code. Having a distinct alternative syntax gives us a "bubble of new code" that doesn't exist today, and have:

- **Freedom to make any desired improvement, without breaking any of today's code.** Cpp2 is designed to take all the consensus C++ best-practices guidance we already teach, and make it the default when using "syntax 2." Examples: Writing unsafe type casts is just not possible in Cpp2 syntax; and Cpp2 can change language defaults to make them simpler and safer. You can always "break the glass" when needed to violate the guidance, but has to opt out explicitly to write unsafe code, so if the program has a bug you can grep for those places to look at first. For details, see [Design note: unsafe code](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Unsafe-code).

- **Perfect link compatibility always on, perfect source compatibility always available (but you pay for it only if you use it).** Any type/function/object/namespace/module/etc. written in either syntax is always still just a normal C++ type/function/object/namespace/module/etc., so any code or library written in either Cpp2 or today's C++ syntax ("Cpp1" for short) can seamlessly call each other, with no wrapping/marshaling/thunking. You can write a "mixed" source files that has both Cpp2 and Cpp1 code and get perfect backward C++ source compatibility (even SFINAE and macros), or you can write a "pure" all-Cpp2 source file and write code in a 10x simpler syntax.

**What it isn't.** Cpp2 is not a successor or alternate language with its own divergent or incompatible ecosystem. For example, it does not have its own nonstandard incompatible modules/concepts/etc. that compete with the Standard C++ features; and it does not replace your Standard C++ compiler and other tools.

**What it is.** Cpp2 aims to be another "skin" for C++ itself, just a simpler and safer way to write ordinary C++ types/functions/objects. It seamlessly uses Standard C++ modules and concepts requirements and other features, and it works with all existing C++20 or higher compilers and tools right out of the box with zero overhead.


### What is cppfront?

[**Cppfront**](https://github.com/hsutter/cppfront) is a compiler that compiles Cpp2 syntax to today's Cpp1 syntax. This lets you start trying out Cpp2 syntax in any existing C++ project and build system just by renaming a source file from `.cpp` to `.cpp2` and [adding a build step](#adding-cppfront-in-your-ide-build-system), and the result Just Works with every C++20 or higher compiler and all existing C++ tools (debuggers, build systems, sanitizers, etc.).

This deliberately follows Bjarne Stroustrup's wise approach with [**cfront**](https://en.wikipedia.org/wiki/Cfront), the original C++ compiler: In the 1980s and 1990s, Stroustrup created cfront to translate C++ to pure C, and similarly ensured that C++ could be interleaved with C in the same source file, and that C++ could always call any C code with no wrapping/marshaling/thunking. By providing a C++ compiler that emitted pure C, Stroustrup ensured full compatibility with the C ecosystems that already existed, and made it easy for people to start trying out C++ code in any existing C project by adding just another build step to translate the C++ to C first, and the result Just Worked with existing C tools.

### How do I get and build cppfront?

The full source code for cppfront is at the [**Cppfront GitHub repo**](https://github.com/hsutter/cppfront).

Cppfront builds with any recent C++ compiler. Go to the `/cppfront/source` directory, and run one of the following:

<image align="right" width="120" src="https://user-images.githubusercontent.com/1801526/188906112-ef377a79-b6a9-4a30-b318-10b51d8ea934.png">

``` bash title="MSVC build instructions (Visual Studio 2019 version 16.11 or higher)"
cl cppfront.cpp -std:c++20 -EHsc
```

``` bash title="GCC build instructions (GCC 10 or higher)"
g++ cppfront.cpp -std=c++20 -o cppfront
```

``` bash title="Clang build instructions (Clang 12 or higher)"
clang++ cppfront.cpp -std=c++20 -o cppfront
```

That's it!


## **Hello, world!**

### A `hello.cpp2` program

Here is the usual one-line starter program that prints `Hello, world!`. Note that this is a complete program, no `#include` required:

``` cpp title="hello.cpp2 — on one line"
main: () = std::cout << "Hello, world!\n";
```

But let's add a little more, just to show a few things:

``` cpp title="hello.cpp2 — slightly more interesting"
main: () = {
    words: std::vector = ( "Alice", "Bob" );
    hello( words[0] );
    hello( words[1] );
    std::cout << "... and goodnight\n";
}

hello: (msg: std::string_view) =
    std::cout << "Hello, (msg)$!\n";
```

This short program code already illustrates a few Cpp2 essentials.

**Consistent context-free syntax.** Cpp2 is designed so that there is one general way to spell a given thing, that works consistently everywhere. All Cpp2 type/function/object/namespace/module/etc. declarations use the unambiguous and context-free syntax **"_name_ `:` _kind_ `=` _statement_"**. The `:` is pronounced **"is a,"** and the `=` is pronounced **"defined as."**

- `main` **is a** function that takes no arguments and returns nothing, and is **defined as** the code body shown.

- `words` **is a** `std::vector`, initially **defined as** holding `"Alice"` and `"Bob"`.

- `hello` **is a** function that takes a `std::string_view` it will only read from and that returns nothing, and is **defined as** code that prints the string to `cout` the usual C++ way.

All grammar is context-free. In particular, we (the human reading the code, and the compiler) never need to do name lookup to figure out how to parse something — there is never a ["vexing parse"](https://en.wikipedia.org/wiki/Most_vexing_parse) in Cpp2. For details, see [Design note: Unambiguous parsing](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Unambiguous-parsing).

**Simple and safe by default.** Cpp2 has contracts (tracking draft C++26 contracts), `inspect` pattern matching, string interpolation, and more.

- Declaring `words` uses **"CTAD"** (C++'s normal constructor template argument deduction) to declare its `words` variable.

- Calling `words[0]` and `words[1]` is **bounds-checked by default**. From Cpp2 code, ordinary `std::vector` subscript accesses are safely bounds-checked by default without requiring any upgrade to your favorite standard library, and that's true for any similar subscript of something whose size can be queried using `std::size()`, including any in-house integer-indexed container types you already have that can easily provide `std::size()` if they don't already.

- `hello` uses **string interpolation** to be able to write `"Hello, (msg)$!\n"` instead of `"Hello, (" << msg << "!\n"`.

**Simplicity through generality + defaults.** A major way that Cpp2 delivers simplicity is by providing just one powerful general syntax for a given thing (e.g., one function definition syntax), but designing it so you can omit the parts you're not currently using (e.g., where you're happy with the defaults). We're already using some of those defaults above:

- We can omit writing the `-> void` return type for a function that doesn't return anything, as both of these functions do.

- We can omit the `{` `}` around single-statement function bodies, as `hello` does.

- We can omit the `in` on the `msg` parameter. Cpp2 has just six ways to pass parameters: The most common ones are `in` for read-only (the default so we can omit it, as `hello` does), `inout` for read-write, and also `copy`, `out`, `move`, and `forward`.

For details, see [Design note: Defaults are one way to say the same thing](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Defaults-are-one-way-to-say-the-same-thing).

**Order-independent by default.** Did you notice that `main` called `hello`, which was defined later? Cpp2 code is order-independent by default — there are no forward declarations.

**Seamless compatibility and interop.** We can just use `std::cout` and `std::operator<<` and `std::string_view` directly as usual. Cpp2 code works with any C++ code or library, including the standard library, using ordinary direct calls without any wrapping/marshaling/thunking.

**C++ standard library always available.** We didn't need `#include <iostream>` or `import std;`. The full C++ standard library is always available by default if your source file contains only syntax-2 code and you compile using cppfront's `-p` (short for `-pure-cpp2`). Cppfront is regularly updated to be compatible with C++23 and the latest draft C++26 library additions as soon as the ISO C++ committee votes them into the C++26 working draft, so as soon as you have a C++ implementation that has a new standard (or bleeding-edge draft standard!) C++ library feature, you'll be able to fully use it in Cpp2 code.


### Building `hello.cpp2` from the command line

Now use `cppfront` to compile `hello.cpp2` to a standard C++ file `hello.cpp`:

``` bash title="Call cppfront to produce hello.cpp"
cppfront hello.cpp2 -p
```

The result is an ordinary C++ file that looks like this: [^clean-cpp1]

``` cpp title="hello.cpp — created by cppfront" linenums="1"
#define CPP2_IMPORT_STD          Yes

#include "cpp2util.h"

auto main() -> int;

auto hello(cpp2::in<std::string_view> msg) -> void;
auto main() -> int{
    std::vector words {"Alice", "Bob"};
    hello(CPP2_ASSERT_IN_BOUNDS_LITERAL(words, 0));
    hello(CPP2_ASSERT_IN_BOUNDS_LITERAL(std::move(words), 1));
    std::cout << "... and goodnight\n";
}

auto hello(cpp2::in<std::string_view> msg) -> void {
    std::cout << ("Hello, " + cpp2::to_string(msg) + "!\n");  }
```

Here we can see more of how Cpp2 makes it features work.

**How: Consistent context-free syntax.**

- **Lines 8, 9, and 15:** Cpp2's context-free syntax converts directly to today's Cpp1 syntax. We can write and read our C++ types/functions/objects in simpler Cpp2 syntax without wrestling with context sensitivity and ambiguity, and they're all still just ordinary types/functions/objects.

**How: Simple and safe by default.**

- **Line 9:** CTAD just works, because it turns into ordinary C++ code which is CTAD-aware.
- **Lines 10-11:** The accesses of `words[0]` and `words[1]` are bounds-checked nonintrusively at the call site by default. Because it's nonintrusive, it works seamlessly with all existing container types that are `std::ssize`-aware, when you use them from safe Cpp2 code.
- **Line 16:** String interpolation performs the string capture of `msg`'s current value via `cpp2::to_string`. That uses `std::to_string` when available, and it also works for additional types (such as `bool`, to print `false` and `true` instead of `0` and `1`, without having to remember to use `std::boolalpha`).

**How: Simplicity through generality + defaults.**

- **Line 7:** The default `in` parameter passing convention is implemented using `cpp2::in<>`, which is smart enough to pass by `const` value when that's safe and appropriate, otherwise by `const&`, so you don't have to choose the right one by hand.

**How: Order-independent by default.**

- **Lines 5 and 7:** Cppfront achieves order independence is by generating all the type and function forward declarations for you, so you don't have to. That's why `main` can just call `hello`: Both are forward-declared, so they can both see each other.

**How: Seamless compatibility and interop.**

- **Lines 9, 12, and 16:** Calling existing C++ code is just ordinary direct calls, so there's never a need for wrapping/marshaling/thunking.

**How: C++ standard library always available.**

- **Lines 1 and 3:** Because cppfront was invoked with `-p`, which implies either `-im` (short for `-import-std`) or `-in` (short for `-include-std`, for compilers that don't support modules yet), the generated code tells `cpp2util.h` to `import` the entire standard library as a module (or do the equivalent via headers if modules are not available).


### Building and running `hello.cpp` from the command line

Finally, just build `hello.cpp` using your favorite C++20 compiler, where `CPPFRONT_INCLUDE` is the path to `/cppfront/include`:

<image align="right" width="120" src="https://user-images.githubusercontent.com/1801526/188906112-ef377a79-b6a9-4a30-b318-10b51d8ea934.png">

``` title="MSVC"
> cl hello.cpp -std:c++20 -EHsc -I CPPFRONT_INCLUDE
> hello.exe
Hello, world!
```

``` bash title="GCC"
$ g++ hello.cpp -std=c++20 -ICPPFRONT_INCLUDE -o hello
$ ./hello.exe
Hello, world!
```

``` bash title="Clang"
$ clang++ hello.cpp -std=c++20 -ICPPFRONT_INCLUDE -o hello
$ ./hello.exe
Hello, world!
```

## Adding cppfront in your IDE / build system

To start trying out Cpp2 syntax in any existing C++ project, just add a build step to translate the Cpp2 to Cpp1 syntax:

- Add the `.cpp2` file to the project, and ensure the `.cpp` is in C++20 mode.
- Tell the IDE to build that file using a custom build tool to invoke cppfront.

That's it... The result Just Works with every C++20 or higher compiler and all existing C++ tools (debuggers, build systems, sanitizers, etc.). The IDE build should just pick up the `.cpp2` file source locations for any error messages, and the debugger should just step through the `.cpp2` file.

The following uses Visual Studio as an example, but others have done the same in Xcode, Qt Creator, CMake, and other IDEs.

#### 1. Add the `.cpp2` file to the project, and ensure the `.cpp` is in C++20 mode

For Visual Studio: In the Solution Explorer, right-click on Source Files and pick Add to add the file to the project.

<p align="center"><img width="600" src="https://github.com/hsutter/cppfront/assets/1801526/0be904e4-4222-40bc-85e4-b573d6371d2d"></p>

Also in Solution Explorer, right-click on the `.cpp` file Properties and make sure it's in C++20 (or C++latest) mode.

<p align="center"><img width="600" src="https://github.com/hsutter/cppfront/assets/1801526/f7a25778-5056-41b3-a6e3-3034bf0587fd"></p>


#### 2. Tell the project system to build that file using a custom build tool to invoke cppfront, and add `cppfront/include` to the include path

For Visual Studio: In Solution Explorer, right-click on the `.cpp2` file and select Properties, and add the custom build tool. Remember to also tell it that the custom build tool produces the `.cpp` file, so that it knows about the build dependency:

<p align="center"><img width="600" src="https://github.com/hsutter/cppfront/assets/1801526/1307ac57-6c3b-4c83-b606-f5c626867ebf"></p>

Finally, put the `/cppfront/include` directory on your `INCLUDE` path. In Solution Explorer, right-click the app and select Properties, and add it to the VC++ Directories > Include Directories:

<p align="center"><img width="600" src="https://github.com/hsutter/cppfront/assets/1801526/866fc2b8-bfca-4568-823b-f0fecfae27f5"></p>

#### That's it: Error message outputs, debuggers, visualizers, and other tools should just work

That's enough to enable builds, and the IDE just picks up the rest from the `.cpp` file that cppfront generated:

- **The cppfront error messages in `filename(line, col)` format.** Most C++ IDEs recognize these, and usually automatically merge any diagnostic output wherever compiler error output normally appears. If your IDE prefers `filename:line:col`, just use the cppfront `-format-colon-errors` command line option.

- **The `#line` directives cppfront emits in the generated `.cpp` file.** Most C++ debuggers recognize these and will know to step through the `.cpp2` file. Note that `#line` emission is on by default, but if you choose `-c` (short for `-clean-cpp1`) these will be suppressed and then the debugger will step through the generated C++ code instead.

- **Regardless of syntax, every type/function/object/namespace/module/etc. is still just an ordinary C++ type/function/object/namespace/module/etc.** Most C++ debugger visualizers will just work and show beautiful output for the types your program uses, including to use any in-the-box visualizers for all the `std::` types (since those are used directly as usual) and any custom visualizers you may have already written for your own types or popular library types.



[^simpler]: I'd ideally love to obsolete ~90% of the C++ guidance I've personally had to write and teach over the past quarter century, by removing inconsistencies and pitfalls and gotchas. I love writing C++ code... I just want it to be easier and safer by default.

[^clean-cpp1]: For presentation purposes, this documentation generally shows the `.cpp` as generated when using cppfront's `-c` (short for `-clean-cpp1`), which suppresses extra information cppfront normally emits in the `.cpp` to light up C++ tools (e.g., to let IDEs integrate cppfront error message output, debuggers step to the right lines in Cpp2 source code, and so forth). In normal use, you won't need `-c`.
