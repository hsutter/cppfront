
# A tour of Cpp2 ('C++ alt syntax 2') and the `cppfront` compiler

## Preface: What is this?

### Goal in a nutshell: 100% pure C++... just nicer

My goal for this project is to try to prove that Bjarne Stroustrup has long been right: That it's possible and desirable to have true C++ with all its expressive power and control and with full backward compatibility, but in a C++ that's **10x simpler** with fewer warts and special cases, and **50x safer** where it's far easier to not write vulnerability bugs by accident.

Stroustrup said it best:

> "Inside C++, there is a much smaller and cleaner language struggling to get out." <br>— Bjarne Stroustrup, _The Design and Evolution of C++_ (D&E), 1994
>
> "Say 10% of the size of C++ in definition and similar in front-end compiler size. ... most of the simplification would come from generalization." <br>— Bjarne Stroustrup, _ACM History of Programming Languages III_, 2007

But how?

### Approach in a nutshell: Alternative syntax + perfect compatibility

This project explores creating an alternate "syntax 2" (Cpp2 for short) for C++ itself, that's unambiguous with today's syntax (Cpp1 for short). That gives us:

- a "bubble of new code" that doesn't exist today, where we can make any change we want in a fully compatible way, without worrying about breaking existing code;
- a way to make any improvement, including to fix language defaults and make all the C++ best-practices guidance we already teach be the default;
- the power to freely use both syntaxes in the same file if we want full backward C++ source compatibility, or to freely use just the simpler syntax standalone if we want to write in a 10x simpler C++ (i.e., pay for source compatibility only if you use it); and
- perfect interoperability, because any type/function/object written in either Cpp1 or Cpp2 syntax is always still just a normal C++ type/function/object.

In the 1980s and 1990s, Stroustrup similarly ensured that C++ could be interleaved with C in the same source file, and C++ could always call any C code with no wrapping/marshaling/thunking. Stroustrup accomplished this and more by writing **cfront**, the original C++ compiler, to translate C++ to pure C. That way, people could start trying out C++ code in any existing C project with just another build step to translate the C++ to C, and the result Just Worked with existing C tools.

This project aims to follow Stroustrup's implementation approach, with a **cppfront** compiler that compiles Cpp2 syntax to Cpp1 syntax. You can start trying out Cpp2 syntax in any existing C++ project just by adding a build step to translate the Cpp2 to Cpp1 syntax, and the result Just Works with existing C++ tools.

What does it look like?

## Hello, world!

Here is the usual starter program that prints "Hello, world!":

```cpp
//  hello.cpp2
main: () = {
    std::cout << "Hello, world!";
}
```

This is a complete program that prints `Hello, world!`.

Everything in Cpp2 is declared using the syntax **"_name_ `:` _kind_ `=` _statement_"**. The `:` is pronounced "is a." Here, `main` is a function that takes no arguments, and has a body that prints the string to `cout`.

We can just use `std::cout` and `std::operator<<` directly. Cpp2 code works with any C++ code or library, using direct calls without any wrapping/marshaling/thunking.

We didn't need `#include <iostream>` or `import std;`. The full C++ standard library is always available by default if your source file contains only syntax-2 code and you compile with it `cppfront -p` (short for `-pure-cpp2`).

### Building and running the program

Now use `cppfront` to compile `hello.cpp2` to a standard C++ file `hello.cpp`:

```
cppfront hello.cpp2 -p    # produces hello.cpp
```

and then build `hello.cpp` using your favorite C++20 compiler, where `CPPFRONT_INCLUDE` is the path to `/cppfront/include`:

``` title="MSVC"
> cl hello.cpp -std:c++20 -EHsc -I CPPFRONT_INCLUDE
> hello.exe
Hello, world!
```
``` title="GCC"
$ g++ hello.cpp -std=c++20 -ICPPFRONT_INCLUDE -o hello
$ ./hello.exe
Hello, world!
```
``` title="Clang"
$ clang++ hello.cpp -std=c++20 -ICPPFRONT_INCLUDE -o hello
$ ./hello.exe
Hello, world!
```

