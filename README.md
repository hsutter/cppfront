# cppfront

<image align="right" width="320" src="https://user-images.githubusercontent.com/1801526/189203090-bbf2eea0-83e5-4962-b2da-f81224152dcb.png"> Copyright (c) Herb Sutter

See [License](LICENSE)

[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](code_of_conduct.md)

Cppfront is a personal experimental compiler from an experimental C++ 'syntax 2' to today's 'syntax 1,' to learn some things, prove out some concepts, and share some ideas.

The goal is to explore whether there's a way we can evolve C++ itself to become 10x simpler, safer, and more toolable. If we had an alternate C++ syntax, it would give us a "bubble of new code that doesn't exist today" where we could make arbitrary improvements (e.g., change defaults, remove unsafe parts, make the language context-free and order-independent, and generally apply 30 years' worth of learnings), free of backward source compatibility constraints.

I'm sharing this work because I hope to start a conversation about what could be possible _**within C++**_’s own evolution to rejuvenate C++, now that we have C++20 and soon C++23 to build upon. This compiler is currently still hilariously incomplete, so don't contemplate any real use yet. :) For example, as of this writing, syntax 2 doesn't yet support writing classes, though you can still write those using today's syntax (both syntaxes can be used within the same source file and seamlessly interoperate). And this is my own project; I am not speaking for any company or for the ISO C++ committee, though whenever parts of this do pan out I intend to keep bringing them to ISO C++ as evolution proposals.

### History

<image align="right" width="320" src="https://user-images.githubusercontent.com/1801526/189241726-db92ae64-2b2f-4463-a0c3-87794062da9c.png"> I did most of the 'syntax 2' design work in 2015-16. Since then, every evolution proposal paper I've brought to ISO C++, and every conference talk I've given, has come from this work — just presented as a standalone proposal under today's syntax, usually with a separate standalone prototype implementation, to help validate and refine one part of the design, then another, then another.
    
For a list of papers and conference talks that have come from this work, see below.

I started writing this cppfront compiler in mid-2021 as another step to prototype all the parts together as a whole as originally intended, now includeing the alternative 'syntax 2' for C++ that enables their full designs including otherwise-breaking changes. This step is to let me try out the full set of coordinated improvements in one place, and free of concerns about breaking any existing code.

## What's different?

This is one of many experiments going on across the industry looking at ways to accomplish a major C++ evolution. Several of those other experiments' designers have seen this 'syntax 2' work privately since 2016, and if they found parts of this useful in their own experiments then I think that's great, we should learn from each other and I look forward to seeing how their experiments work out too.
    
What makes this experiment different from the others? Two main things...

### 1) This is about C++20/23/... — not about something else

<image align="right" width="150" src="https://user-images.githubusercontent.com/1801526/188887745-23e0c3a0-3ea7-4589-993c-f54fe662b107.png"> For me, ISO C++ is the best tool in the world today to write the programs I want and need. I want to keep writing code in C++... just "nicer":
    
- with less ceremony to remember;

- with fewer safety gotchas; and

- with the same level of tool support other languages enjoy.

If you're a C++ programmer, you may know what I mean... I want "C++, the powerful and expressive parts" without "C++, the cumbersome and dangerous parts." That C++ is an awesome language. More like that please.
    
We've already been improving C++'s safety and ergonomics with every ISO C++ release, but they have been "10%" improvements. We haven't been able to do a **"10x"** improvement primarily because we have to keep 100% syntax backward compatibility.

What if we could have our compatibility cake, and eat it too — by having:

- 100% seamless **link compatibility always** (no marshaling, no thunks, no wrappers, no generated 'compatibility modules' to import/export C++ code from/to a different world); and
    
- 100% seamless **backward source compatibility always available**, including 100% SFINAE and macro compatibility, **but only pay for it when we use it**... that is, apply C++'s familiar "zero-overhead principle" also to backward source compatibility?

I want to encourage us to look for ways to push the boundaries to bring C++ itself forward and double down on C++ — not to switch to something else.
    
I want us to aim for major C++ evolution directed toward things that will make us better C++ programmers — not programmers of something else.

    
### 2) This is about improvements to safety, simplicity, and toolability — not about green-field design or random drive-by improvements
    
<image align="right" width="320" src="https://user-images.githubusercontent.com/1801526/189236486-0b5a4892-42c8-4486-9722-bb60a5df8c7e.png"> My specific goal is to explore the question: Can we make C++ **10x safer, simpler, and more toolable** if C++ had an alternative "syntax #2," within which we could be completely free to **improve semantics** by applying 30 years' worth of C++ language experience without any backward source compatibility constraints? We want each proposed improvement to address a known C++ pain point, and in a measurable way (e.g., reduce a class of CVEs (vulnerabilities) by some quantifiable %, reduce the amount of guidance we have to teach by some quantifiable %).
    
An alternative syntax would be a cleanly demarcated "bubble of new code" that would let us do things that we can never do in today's syntax without breaking the world, such as to:

- fix defaults (e.g., make `[[nodiscard]]` the default);
- double down on modern C++ (e.g., make C++20 modules and C++23 `import std;` the default);
- remove unsafe parts that are already superseded (e.g., no unsafe `union` or pointer arithmetic, use `std::variant` and `std::span` instead as we already teach);
- have type and memory safety by default (e.g., make the [C++ Core Guidelines safety profiles](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-profile) the default and required);
- eliminate 90% of the guidance we have to teach about today's complex language (e.g., make common guidance the language default, eliminate irregular special cases through generalization, refactor the language into a smaller number of regular composable features);
- make it easy to write a parser (e.g., have a context-free grammar); and
- make it easy to write refactoring and other tools (e.g., have order-independent semantics).
   
The cppfront compiler is an experiment to try to develop a proof of concept that evolution along these lines may be possible. For example, this repo's `parse.h` is a standalone context-free parser that is growing month by month as I implement more of the "syntax #2" experiment, and I hope for it to become a standalone context-free parser for a flavor of C++ that has full parity with the expressive power of today's C++.

> **Important disclaimer: This isn't about 'just a pretty syntax,' it's about fixing semantics.** The unambiguous alternative syntax is just a means to an end, a gateway that lets us access a new open space beyond it — and sure, if we build a gate, then the gate ought to look nice too, so we build it with good boards and paint it nice colors. But the gate is the doorway, the portal, not the goal... the real payoff is gaining access to that new open space in C++ that's free of backward source compatibility constraints where we can (finally) fix semantics — order-independence, great defaults, regular composable semantic meanings — as we see fit. 

## How do I build cppfront?

<image align="right" width="120" src="https://user-images.githubusercontent.com/1801526/188906112-ef377a79-b6a9-4a30-b318-10b51d8ea934.png">
Cppfront builds with any major C++20 compiler.
    
#### MSVC build instructions
    
    cl cppfront.cpp -std:c++20 -EHsc
    
#### GCC build instructions
    
    g++-10 cppfront.cpp -std=c++20 -o cppfront
    
#### Clang build instructions
    
    clang++-12 cppfront.cpp -std=c++20 -o cppfront

That's it.

There are no outside dependencies (no YACC/Bison/...), no build scripts (no CMake/Bazel/...). I started cppfront with just a blank editor and the C++ standard library, and have stuck to that so far. The parser is custom hand-written code, so is everything else, and all the code in this repo is my own (including a small function that is also in the Microsoft GSL implementation because I contributed it there too).

## How do I build my `.cpp2` file?

Just run `cppfront your.cpp2`, then run the generated `your.cpp` through any major C++20 compiler after putting `/cppfront/include` in the path so it can find `cpp2util.h`.

- MSVC would be: `cl your.cpp -std:c++20 -EHsc`
- GCC would be: `g++-10 your.cpp -std=c++20`
- Clang would be: `clang++-12 your.cpp -std=c++20`

That's it.
    
Of course, if your code wants to use features that are under additional switches provided by your compiler, then you'll need to add those switches. For example, if you're using post-C++20 features you may need to specify `-std=c++2a` or `-std:c++latest`, if you're using OpenMP you may need to specify something like `/openmp` or `-fopenmp`, and so forth. This especially comes up in mixed Cpp1/Cpp2 source files, because of course the Cpp1 code can use anything your C++ compiler understands, including nonstandard extensions, `#pragmas`, etc.


## Where's the documentation?

For now I'm not posting a lot of written documentation because that would imply this project is intended for others to use — if it someday becomes ready for that, I'll post more docs.

Here's where to find out more about my 'syntax #2' experiment:

- **My CppCon 2022 talk** [link coming soon] — this is the primary documentation right now. See also every talk I've given and paper I've written since 2015, each of which details an individual part of this design experiment, but presented in today's C++ syntax as a standalone C++ evolution proposal.
- **The [cppfront regression tests](https://github.com/hsutter/cppfront/tree/main/regression-tests/test-results)** which show dozens of working examples, each with a`.cpp2` file and the `.cpp` file it is translated to. Each filename briefly describes the language features the test demonstrates (e.g., contracts, parameter passing, bounds safety, type-safe `is` queries and `as` casts, initialization safety, and generalized value capture including in function expressions ('lambdas'), postconditions, and string interpolation).
    
### List of my papers and talks since 2015 (all from this work, but presented in today's syntax)

All of the ISO C++ papers and CppCon conference talks I've given since 2015 have been derived from this work. I've spent the last seven years bringing each individual experimental design improvement of the 'syntax 2' experiment as a standalone proposal in today's syntax, to validate that the committee and community agreed with the problem to be solved and the solution direction, and to further flesh out each part individually... thanks very much to all of you who have given valuable feedback!
    
Here is a list of those papers and talks, in the order that I brought each individual design forward. Most of the details in the following papers and talks are still current with only incremental updates, apart from the specific syntax of course.
    
#### Lifetime safety
    
- [**CppCon 2015**: "Writing good C++14... _by default_"](https://youtu.be/hEx5DNLWGgA) particularly [from 29:00 onward](https://youtu.be/hEx5DNLWGgA?t=1757) shows the Lifetime analysis with live demos in a Visual Studio prototype
- [**CppCon 2018**: "Thoughts on a more powerful _and_ simpler C++ (#5 of N)](https://youtu.be/80BZxujhY38)
    - [the section starting at 18:00](https://youtu.be/80BZxujhY38?t=1097) is an update on the Lifetime status with live demos in a Clang prototype
    - [the final part starting at 1:28](https://youtu.be/80BZxujhY38?t=5307) which shows the Lifetime and Metaclasses proposals working hand-in-hand (this is one of the few places before cppfront where the same compiler has contained prototypes of multiple 'syntax 2'-derived features so I could show how they build on each other when used together)
- [**C++ Core Guidelines**: Lifetime safety profile](https://github.com/isocpp/CppCoreGuidelines/blob/master/docs/Lifetime.pdf) is this static analysis adopted by the C++ Core Guidelines
- [**P1179**: Lifetime Safety: Preventing common dangling](https://wg21.link/p1179) is the same analysis in the WG 21 paper list

Much of this Lifetime analysis has been implemented and shipped in Visual Studio and in CLion, and initial small parts have been implemented and shipped in Clang. The implementations have exposed bugs in shipping code that were not caught before. My experiment in 'syntax 2' is to make these safety rules the default and mandatory. (Note: Most of this is not yet implemented in cppfront.)
    
#### Garbage-collected memory arena

- [**CppCon 2016**: "Leak-freedom in C++... _by default_"](https://www.youtube.com/watch?v=JfmTagWcqoE) particularly [from 59:00 onward](https://youtu.be/JfmTagWcqoE?t=3558) where I show the strawman prototype I wrote of a tracing garbage-collection memory arena
- [**GCPP**: "gcpp: Deferred and unordered destruction"](https://github.com/hsutter/gcpp) is the GitHub prototype I wrote

I welcome a real GC expert to collaborate with on bringing this forward to become a "real" usable tracing GC memory arena that C++ code can opt into. As always, we still prefer scopes first (no tracking needed), and if that's not sufficient then `unique_ptr` (minimal tracking needed), then if that's not sufficient `shared_ptr` (more tracking needed), and then if that's not sufficient this tracing GC arena (suitable for cases where the existing smart pointers aren't enough, such as when you really cannot statically know enough about lifetimes to use the existing smart pointers).

#### Spaceship operator for comparisons, `<=>`
    
- [**CppCon 2017 (just the intro, first 6 minutes)**: "Meta: Thoughts on generative C++"](https://www.youtube.com/watch?v=4AfRAVcThyA)
- [**P0515**: Consistent comparison](https://wg21.link/p0515)
    
This is the first feature from my Cpp2 work that is now in the ISO C++ standard, as part of C++20.
    
It is also the only feature in the history of ISO C++ where we _added_ a feature to ISO C++ that made the whole standard _smaller_: It took about 10 pages of core language wording to specify, but it was also applied throughout the standard library which reduced the C++ standard library's specification by about 25 pages. I take this as a data point that it is possible to simplify C++ by thoughtfully adding the right kinds of features.
    
This is also the only feature from the Cpp2 work that I proposed without first having a prototype implementation, and so the proposal had bugs in two main areas that were discovered and fixed later: Keeping the `==` optimization, which was known but in the initial proposal was easy to lose accidentally; and smoother interoperation with existing pre-`<=>` types (which is important because there are _a lot_ of those). Thank you again to everyone who helped land this in the Standard in C++20 and improved in C++23, including: Walter Brown, Lawrence Crowl, Cameron DaCamara, Gabriel Dos Reis, Jens Maurer, Barry Revzin, Richard Smith, and David Stone. This shows the importance of prototype experience.

    
