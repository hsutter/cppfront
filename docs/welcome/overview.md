
# Overview: What are Cpp2 and cppfront? How do I get and build cppfront?

``` cpp title="hello.cpp2"
main: () = {
    std::cout << "Hello, world!\n";
}
```

## <a id="what-is-cpp2"></a> What is Cpp2?

"Cpp2," short for "C++ syntax 2," is my ([Herb Sutter's](https://github.com/hsutter)) personal project to try to make writing ordinary C++ types/functions/objects be much **simpler and safer**, without breaking backward compatibility.

**What it isn't.** Cpp2 is not a successor or alternate language with its own divergent or incompatible ecosystem. For example, it does not have its own nonstandard incompatible modules/concepts/etc. that compete with the Standard C++ features; it does not replace your Standard C++ compiler or other tools; and it does not require any changes to your Standard C++ compiler or standard library or other libraries or tools to keep fully using all of them.

**What it is.** Cpp2 aims to be another "skin" for C++ itself, just a simpler and safer way to write ordinary C++ types/functions/objects, and a faster way to experiment with proposals for future new Standard C++ features in a simpler compiler and syntax flavor. It seamlessly uses Standard C++ modules and concepts requirements and other features, and it works with all existing C++20 or higher compilers and libraries and tools right out of the box with no changes required to use them all seamlessly and directly with zero overhead.

 Bjarne Stroustrup said it best:

 > "Inside C++, there is a much smaller and cleaner language struggling to get out." <br>&emsp;&emsp;— Bjarne Stroustrup, _The Design and Evolution of C++_ (D&E), 1994
>
> "Say 10% of the size of C++ in definition and similar in front-end compiler size. ... most of the simplification would come from generalization." <br>&emsp;&emsp;— Bjarne Stroustrup, _ACM History of Programming Languages III_, 2007

**My goal is to try to prove that Stroustrup is right:** that it's possible and desirable to have true C++ with all its expressive power and control and with full backward compatibility, but in a flavor that's 10x simpler with fewer quirks and special cases to remember, [^simpler] and 50x safer where it's far easier to not write security bugs by accident.

We can't make an improvement that large to C++ via gradual evolution to today's syntax, because some important changes would require changing the meaning of code written in today's syntax. For example, we can never change a language feature default in today's syntax, not even if the default creates a security vulnerability pitfall, because changing a default would break vast swathes of existing code. Having a distinct alternative syntax gives us a "bubble of new code" that doesn't exist today, and have:

- **Freedom to make any desired improvement, without breaking any of today's code.** Cpp2 is designed to take all the consensus C++ best-practices guidance we already teach, and make them the default when using "syntax 2." Examples: Writing type-unsafe casts is just not possible in Cpp2 syntax; and Cpp2 can change language defaults to make them simpler and safer. You can always "break the glass" when needed to violate the guidance, but you have to opt out explicitly to write type-unsafe code (usually using the word `unchecked`), so if the program has a bug you can grep for those places to look at first. For details, see [Design note: unsafe code](https://github.com/hsutter/cppfront/wiki/Design-note%3A-Unsafe-code).

- **Perfect link compatibility always on, perfect source compatibility always available (but you pay for it only if you use it).** Any type/function/object/namespace written in either syntax is always still just a normal C++ type/function/object/namespace, so any code or library written in either Cpp2 or today's C++ syntax ("Cpp1" for short) can seamlessly call each other, with no wrapping/marshaling/thunking. You can write a "mixed" source file that has both Cpp2 and Cpp1 code and get perfect backward C++ source compatibility (even SFINAE and macros), or you can write a "pure" all-Cpp2 source file and write code in a 10x simpler syntax.


## <a id="what-is-cppfront"></a> What is cppfront?

[**Cppfront**](https://github.com/hsutter/cppfront) is a compiler that compiles Cpp2 syntax to today's Cpp1 syntax. This lets you start trying out Cpp2 syntax in any existing C++ project and build system just by renaming a source file from `.cpp` to `.cpp2` and [adding a build step](integration.md), and the result Just Works with every C++20 or higher compiler and all existing C++ tools (debuggers, build systems, sanitizers, etc.).

This deliberately follows Bjarne Stroustrup's wise approach with [**cfront**](https://en.wikipedia.org/wiki/Cfront), the original C++ compiler: In the 1980s and 1990s, Stroustrup created cfront to translate C++ to pure C, and similarly ensured that C++ could be interleaved with C in the same source file, and that C++ could always call any C code with no wrapping/marshaling/thunking. By providing a C++ compiler that emitted pure C, Stroustrup ensured full compatibility with the C ecosystems that already existed, and made it easy for people to start trying out C++ code in any existing C project by adding just another build step to translate the C++ to C first, and the result Just Worked with existing C tools.


## <a id="build-cppfront"></a> How do I get and build cppfront?

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

> Note: On Windows (including MinGW), if you get a "too many sections" message, specify the switch `/bigobj` (MSVC) or `/Wa,-mbig-obj` (GCC).


### &#10148; Next: [Hello, world!](hello-world.md)


[^simpler]: I'd ideally love to obsolete ~90% of my own books. I know that Cpp2 can eliminate that much of the C++ guidance I've personally had to write and teach over the past quarter century, by removing inconsistencies and pitfalls and gotchas, so that they're either impossible to write or are compile-time errors (either way, we don't have to teach them). I love writing C++ code... I just want it to be easier and safer by default.

