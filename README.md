# cppfront

A personal experimental C++ Syntax 2 -> Syntax 1 transpiler

Copyright (c) Herb Sutter

See [License](LICENSE)

[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](code_of_conduct.md)

# What is this project?

I'm sharing this work because I hope to start a conversation about what could be possible _**within C++**_’s own evolution to rejuvenate C++. For now this is my personal project for my own use and experimentation, to learn some things, proof out some concepts, and share some ideas. It's currently still hilariously incomplete (e.g., as of this writing, there's no support for classes! I just started implementing a basic `inspect` statement along the lines I [presented at CppCon 2021](https://www.youtube.com/watch?v=raB_289NxBk) and in [P2392](https://wg21.link/p2392)).

I'm sharing this to show my work, and to try to get others thinking about what could be possible by this kind of direction.

This is one of many experiments going on across the industry looking at ways to accomplish a major C++ evolution. What makes this experiment different from the others? Two main things...

## 1) This is about C++, not about something else... including as always seamless (no-marshal no-thunk no-bridging) interop with all of today's ISO C++ and tomorrow's further-evolved C++.

<image align="right" width="150" src="https://user-images.githubusercontent.com/1801526/188887745-23e0c3a0-3ea7-4589-993c-f54fe662b107.png"> I love ISO C++. I want to keep writing code in C++... just nicer, with less ceremony to remember, fewer safety mistakes, and the same level of tool support other languages enjoy.

We've already been improving C++'s safety and ergonomics with every ISO C++ release, but they have been "10%" improvements. We haven't been able to do a "10x" improvement primarily because we have to keep 100% syntax backward compatibility.

What if we could have our compatibility cake, and eat it too -- by having:

    - 100% seamless **link compatibility always**, and
    
    - 100% seamless **backward source compatibility always available**, including 100% SFINAE and macro compatibility, **but only pay for it when we use it**... that is, apply C++'s familiar "zero-overhead principle" also to backward source compatibilty?

I want to encourage us to look for ways to push the boundaries to bring C++ itself forward and double down on C++ — not to switch to something else. I want us to aim for major C++ evolution directed toward things that will make us better C++ programmers — not programmers of something else.

## 2) I want to stick to a specific goal: See if we can make C++ **10x safer, simpler, and more toolable** if we had a "syntax #2" alternative syntax for C++.

An alternative syntax would be a cleanly demarcated "bubble of new code" that would let us do things that we can never do in today's syntax without breaking the world, such as to:

   - fix defaults (e.g., make `[[nodiscard]]` the default),
   - double down on modern C++ (e.g., make C++20 modules and C++23 `import std;` the default),
   - remove unsafe parts that are already superseded (e.g., no unsafe `union`s or pointer arithmetic),
   - have type and memory safety by default, by making the [C++ Core Guidelines safety profiles](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-profile) we already have the default and required,
   - eliminate 90% of the guidance we have to teach about today's complex language (e.g., by eliminating special cases, and refactoring the language into a smaller number of regular composable features), and
   - make it easy to write a parser (e.g., having a context-free grammar and order-independent semantics.
   
This repo is an experiment to try to develop a proof of concept that evolution along these lines may be possible. For example, this repo's `parse.h` is a standalone context-free parser that is growing month by month as I implement more of the "syntax #2" experiment.

# Where's the documentation?

For now I'm not posting a lot of written documentation because that would imply this project is intended for others to use -- if it someday becomes ready for that, I'll post more docs.

Here's where to find out more about my 'syntax #2' experiment:

    - **My CppCon 2022 talk** [link coming soon] - this is the primary documentation right now
    - The [cppfront regression tests](https://github.com/hsutter/cppfront/tree/main/regression-tests/test-results) which show dozens of `.cpp2` files and the `.cpp` file each one is translated to - each filename briefly describes the language features the test demonstrates (e.g., contracts, parameter passing, bounds safety, `is` queries and `as` casts, generalized value capture including in "lambdas" and string interpolation)

I'll add a few overview examples here soon...
