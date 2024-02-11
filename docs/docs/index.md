
# Overview & getting started

## What are Cpp2 and cppfront?

### What is Cpp2?

"Cpp2" is shorthand name for an experimental alternate "syntax 2" for C++ itself. The goal is to help us evolve C++ to make it simpler and safer, while maintaining full source and link compatibility — but to only pay for perfect backward source compatibility when we actually use it.

Having an unambiguous alternative "syntax 2" gives us:

- **Full freedom to evolve, without breaking any of today's code.** All code written in a distinct syntax is automatically a "bubble of new code that doesn't exist today," so we can make it mean whatever we think is best and know we aren't breaking any of today's existing code. For example, this approach lets us change language defaults, which would be impossible to do directly in an existing syntax.

- **Power to make C++ simpler and safer, by making today's existing best practices the default.** Cpp2 is designed to take all the consensus C++ best-practices guidance we already teach, and make it the default. For example, writing unsafe type casts is just not possible in Cpp2 syntax; the code won't compile. A programmer can always "break the glass" when needed to violate the guidance, but has to opt out explicitly by writing "unsafe," so if the program has a bug you can grep for those places to look at first.

- **Perfect source compatibility always available, and you pay for it only if you use it.** You can write a "mixed" source files that has both Cpp2 and Cpp1 code, and get full backward C++ source compatibility. Or you can write a "pure" Cpp2 source file to use just the simpler syntax standalone, and get to write in a 10x simpler C++. This applies C++'s zero-overhead principle also to backward source compatibility: 100% of today's C++ is always available, but you pay for it only if you use it.

- **Perfect link interoperability always, it's always still pure C++.** Any type/function/object written in either syntax is always still just a normal C++ type/function/object. Cpp2 code can invoke any existing C++ code or library (and vice versa) directly, with no wrapping/marshaling/thunking. There is no 'C++ compatibility bridge'... Cpp2 code *is* C++ code, just written more conveniently.

Bjarne Stroustrup said it best:

> "Inside C++, there is a much smaller and cleaner language struggling to get out." <br>— Bjarne Stroustrup, _The Design and Evolution of C++_ (D&E), 1994
>
> "Say 10% of the size of C++ in definition and similar in front-end compiler size. ... most of the simplification would come from generalization." <br>— Bjarne Stroustrup, _ACM History of Programming Languages III_, 2007

My goal for this project is to try to prove that Bjarne Stroustrup has long been right: That it's possible and desirable to have true C++ with all its expressive power and control and with full backward compatibility, but in a C++ that's **10x simpler** with fewer warts and special cases, and **50x safer** where it's far easier to not write security bugs by accident.


### What is cppfront?

[**Cppfront**](https://github.com/hsutter/cppfront) is a compiler that compiles Cpp2 syntax to today's C++ syntax (aka Cpp1). This lets you start trying out Cpp2 syntax in any existing C++ project just by [adding a build step](#adding-cppfront-in-your-ide-build-system) to translate the Cpp2 to Cpp1 syntax, and the result Just Works with every C++20 or higher compiler and all existing C++ tools (debuggers, build systems, sanitizers, etc.).

This deliberately follows Bjarne Stroustrup's wise approach with [**cfront**](https://en.wikipedia.org/wiki/Cfront), the original C++ compiler: In the 1980s and 1990s, Stroustrup created cfront to translate C++ to pure C, Stroustrup similarly ensured that C++ could be interleaved with C in the same source file, and C++ could always call any C code with no wrapping/marshaling/thunking. By providing a C++ compiler that emitted pure C, Stroustrup ensured full compatibility with the C ecosystems that already existed, and made it easy for people to start trying out C++ code in any existing C project by adding just another build step to translate the C++ to C first, and the result Just Worked with existing C tools.

### How do I get and build cppfront?

The full source code for cppfront is at the [**Cppfront repo**](https://github.com/hsutter/cppfront).

Cppfront builds with any major C++20 compiler. Go to the `/cppfront/source` directory, and run one of the following:

<image align="right" width="120" src="https://user-images.githubusercontent.com/1801526/188906112-ef377a79-b6a9-4a30-b318-10b51d8ea934.png">

``` bash title="MSVC build instructions"
cl cppfront.cpp -std:c++20 -EHsc
```

``` bash title="GCC build instructions"
g++-10 cppfront.cpp -std=c++20 -o cppfront
```

``` bash title="Clang build instructions"
clang++-12 cppfront.cpp -std=c++20 -o cppfront
```

That's it!


## **Hello, world!**

### A `hello.cpp2` program

Here is the usual one-line starter program that prints `Hello, world!`. Note that this is a complete program... even without any `#include`s:

``` cpp title="hello.cpp2, on one line"
main: () = std::cout << "Hello, world!\n";
```

But let's add a little more, just to show a few things:

``` cpp title="hello.cpp2, slightly more interesting"
main: () = {
    words: std::vector = ( "Abigail", "Benjamin" );
    hello( words[0] );
    hello( words[1] );
    std::cout << "... and goodnight\n";
}

hello: (msg: std::string_view) =
    std::cout << "Hello, (msg)$!\n";
```

This short program code already illustrates a few Cpp2 essentials.

**Consistent context-free syntax.** Cpp2 is designed so that there is one general way to spell a given thing, that works consistently everywhere. It's a main goal to avoid special cases, and avoid features that only work in certain parts of the language. All Cpp2 declarations use the unambiguous and context-free syntax **"_name_ `:` _kind_ `=` _statement_"**. The `:` is pronounced **"is a."**

- `main` **is a** function that takes no arguments and returns nothing, and has the body shown.
- `words` **is a** `std::vector`, whose initial contents are `"Abigail"` and `"Benjamin"`.
- `hello` **is a** function that takes a `std::string_view` that it will only read from, that returns nothing, and has a body that prints the string to `cout` the usual C++ way.

All grammar is context-free. In particular, we (the human reading the code, or the compiler) never need to do name lookup to figure out how to parse something — there is never a ["vexing parse"](https://en.wikipedia.org/wiki/Most_vexing_parse) in Cpp2.

**Simple and safe by default.** Cpp2 has contracts (tracking draft C++26 contracts), `inspect` pattern matching, string interpolation, and more. The above `hello` function uses string interpolation to be able to write `"Hello, (msg)$!\n"` instead of `"Hello, (" << msg << "!\n"`. In `main`, the declaration of `words` takes advantage of C++'s normal constructor template argument deduction (aka CTAD). Also, the calls to `words[0]` and `words[1]` are automatically bounds-checked by default — `vector` subscript accesses from Cpp2 code are safely bounds-checked by default without requiring any upgrade to your favorite standard library, and that's true for any similar subscript of something whose size can be queried using `std::size()`, including any in-house integer-indexed container types you already have that can easily provide `std::size()` if they don't already.

**Simplicity through generality + defaults.** A major way that Cpp2 delivers simplicity is by providing just one powerful general syntax for a given thing (e.g., one function definition syntax), but designing it so you can omit the parts you're not currently using (e.g., where you're happy with the defaults). We're already using some of those defaults above:
    - We can omit writing the `-> void` return type for a function that doesn't return anything, as both of these functions do.
    - We can omit the `{` `}` around single-statement function bodies, as `hello` does.
    - We can omit the `in` on the `msg` parameter. Cpp2 has just six ways to pass parameters: The most common ones are `in` for read-only (the default so we can omit it, as `hello` does), `inout` for read-write, and also `copy`, `out`, `move`, and `forward`.

**Order-independent by default.** Did you notice that `main` called `hello`, which was defined later? Cpp2 code is order-independent by default — there are no forward declarations.

**Seamless compatibility and interop.** We can just use `std::cout` and `std::operator<<` and `std::string_view` directly as usual. Cpp2 code works with any C++ code or library, including the standard library, using direct calls without any wrapping/marshaling/thunking.

**C++ standard library always available.** We didn't need `#include <iostream>` or `import std;`. The full C++ standard library is always available by default if your source file contains only syntax-2 code and you compile using cppfront's `-p` (short for `-pure-cpp2`). Cppfront is regularly updated to be compatible with C++23 and draft C++26 library additions, so as soon as you have a C++ implementation that has the new library feature, you'll be able to fully use it in Cpp2 code.


### Building `hello.cpp2` from the command line

Now use `cppfront` to compile `hello.cpp2` to a standard C++ file `hello.cpp`:

``` bash title="Call cppfront to produce hello.cpp"
cppfront hello.cpp2 -p
```

The result is an ordinary C++ file that looks like this: [^clean-cpp1]

``` cpp title="hello.cpp"
#define CPP2_IMPORT_STD          Yes

#include "cpp2util.h"


auto main() -> int;

auto hello(cpp2::in<std::string_view> msg) -> void;
auto main() -> int{
    std::vector words {"Abigail", "Benjamin"};
    hello(CPP2_ASSERT_IN_BOUNDS_LITERAL(words, 0));
    hello(CPP2_ASSERT_IN_BOUNDS_LITERAL(std::move(words), 1));
    std::cout << "... and goodnight\n";
}

auto hello(cpp2::in<std::string_view> msg) -> void {
    std::cout << ("Hello, " + cpp2::to_string(msg) + "!\n");  }
```

Here we can see more of how Cpp2 makes it features work.

**How: Consistent context-free syntax.** Cpp2's context-free syntax converts directly to today's Cpp1 syntax. All the types/functions/objects are ordinary C++ types/functions/objects, but can be written and read without wrestling with context and ambiguity.

**How: Simple and safe by default.** Cpp2's contracts, `inspect`, string interpolation, and more are lowered to regular C++ code. Here, the body of `hello` shows how string interpolation is implemented to perform the string capture of `msg`'s current value. In `main`, we see why CTAD just works — because it turns into ordinary C++ CTAD-aware code. And we can see that cppfront injected calls to bounds-check the accesses of  `words[0]` and `words[1]`, which it does by ensuring the index is betweeen `0` and `std::size(words)` — and, again, this works out of the box with your favorite standard library (or `std::ssize`-aware custom in-house container) you already have, when you use it from safe Cpp2 code.

**How: Simplicity through generality + defaults.** The default `in` parameter passing convention is implemented using `cpp2::in<>`, which is smart enough to pass by `const` value or by `const&` so you don't have to do it by hand as today.

**How: Order-independent by default.** The way cppfront achieves order independence is by generating all the type and function forward declarations, so that you don't have to. (Maybe you're already doing that by hand, which is a good but laborious workaround today. In Cpp2, this is automated so that the programmer doesn't have to.) So there's really no magic about how `main` can call `hello`: it's forward-declared.

**How: Seamless compatibility and interop.** When you see the bodies of `main` and `hello`, it's clear why the uses of `std::cout` and `std::operator<<` and `std::string_view` are all direct without any wrapping/marshaling/thunking: It's just ordinary C++ code, as if you'd written it yourself by hand. Any type/function/object written in either syntax is always still just an ordinary C++ type/function/object. Cpp2 code can invoke any existing C++ code or library (and vice versa) directly, with no wrapping/marshaling/thunking. There is no 'C++ compatibility bridge'... Cpp2 code *is* C++ code, just written more conveniently.

**How: C++ standard library always available.** Because cppfront was invoked with `-p`, which implies either `-im` (short for `-import-std`) or `-in` (short for `-include-std`, for compilers that don't support modules yet), the generated code tells `cpp2util.h` to `import` the entire standard library as a module (or do the equivalent via headers). Cpp2 is a modules-first design, fully compatible with today's header files but attemping to "skate where the puck is going" by having first-class support for standard library modules.

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
- **Regardless of syntax, every type/function/object is still just an ordinary C++ type/function/object.** Most C++ debugger visualizers will just work and show beautiful output for the types your program uses, including to use any in-the-box visualizers for all the `std::` types (since those are used directly as usual) and any custom visualizers you may have already written for your own types or popular library types.



[^clean-cpp1]: For presentation purposes, this documentation generally shows the Cpp1 code generated when using cppfront's `-c` (short for `-clean-cpp1`), which eliminates extra output including `#line` directives. In normal use, you won't need `-c`, because you want the `#line` information which enables accurate error messages, debuggers, and other tools.
