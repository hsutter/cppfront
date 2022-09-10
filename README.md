# cppfront

<image align="right" width="320" src="https://user-images.githubusercontent.com/1801526/189203090-bbf2eea0-83e5-4962-b2da-f81224152dcb.png"> Copyright (c) Herb Sutter

See [License](LICENSE)

[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](code_of_conduct.md)

Cppfront is a personal experimental compiler from an experimental C++ 'syntax 2' to today's 'syntax 1,' to learn some things, prove out some concepts, and share some ideas.

The goal is to explore whether there's a way we can evolve C++ itself to become 10x simpler, safer, and more toolable. If we had an alternate C++ syntax, it would give us a "bubble of new code that doesn't exist today" where we could make arbitrary improvements (e.g., change defaults, remove unsafe parts, make the language context-free and order-independent, and generally apply 30 years' worth of learnings), free of backward source compatibility constraints. I think of it as an attempt at "directed evolution."

I'm sharing this work because I hope to start a conversation about what could be possible _**within C++**_’s own evolution to rejuvenate C++, now that we have C++20 and soon C++23 to build upon. This compiler is currently still hilariously incomplete, so don't contemplate any real use yet. :) For example, as of this writing, syntax 2 doesn't yet support writing classes, though you can still write those using today's syntax (both syntaxes can be used within the same source file and seamlessly interoperate). And this is my own project; I am not speaking for any company or for the ISO C++ committee, though whenever parts of this do pan out I intend to keep bringing them to ISO C++ as evolution proposals.

### History

<image align="right" width="320" src="https://user-images.githubusercontent.com/1801526/189241726-db92ae64-2b2f-4463-a0c3-87794062da9c.png"> I did most of the 'syntax 2' design work in 2015-16. Since then, every evolution proposal paper I've brought to ISO C++, and every conference talk I've given, has come from this work — just presented as a standalone proposal under today's syntax, usually with a separate standalone prototype implementation, to help validate and refine one part of the design, then another, then another.
    
For a list of papers and conference talks that have come from this work, see below.

I started writing this cppfront compiler in mid-2021 as another step to prototype all the parts together as a whole as originally intended, now including the alternative 'syntax 2' for C++ that enables their full designs including otherwise-breaking changes. This step is to let me try out the full set of coordinated improvements in one place, and free of concerns about breaking any existing code.

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

For now, I'm not posting a lot of written documentation because that would imply this project is intended for others to use — if it someday becomes ready for that, I'll post more docs.

Here's where to find out more about my 'syntax #2' experiment:

- **My CppCon 2022 talk** [link coming soon] — this is the primary documentation right now. See also every talk I've given and paper I've written since 2015, each of which details an individual part of this design experiment, but presented in today's C++ syntax as a standalone C++ evolution proposal.
- **The [cppfront regression tests](https://github.com/hsutter/cppfront/tree/main/regression-tests/test-results)** which show dozens of working examples, each with a`.cpp2` file and the `.cpp` file it is translated to. Each filename briefly describes the language features the test demonstrates (e.g., contracts, parameter passing, bounds safety, type-safe `is` queries and `as` casts, initialization safety, and generalized value capture including in function expressions ('lambdas'), postconditions, and string interpolation).
    
## List of my papers and talks since 2015 (all from this work, but presented in today's syntax)

All of the ISO C++ papers and CppCon conference talks I've given since 2015 have been derived from this work. I've spent the last seven years bringing each individual experimental design improvement of the 'syntax 2' experiment as a standalone proposal in today's syntax, to validate that the committee and community agreed with the problem to be solved and the solution direction, and to further flesh out each part individually... thanks very much to all of you who have given valuable feedback!
    
Here is a list of those papers and talks, in the order that I brought each individual design forward. Most of the details in the following papers and talks are still current with only incremental updates, apart from the specific syntax of course.
    
### 2015: Lifetime safety
    
- [**CppCon 2015**: "Writing good C++14... _by default_"](https://youtu.be/hEx5DNLWGgA) particularly [from 29:00 onward](https://youtu.be/hEx5DNLWGgA?t=1757) shows the Lifetime analysis with live demos in a Visual Studio prototype
- [**CppCon 2018**: "Thoughts on a more powerful _and_ simpler C++ (#5 of N)](https://youtu.be/80BZxujhY38)
    - [the section starting at 18:00](https://youtu.be/80BZxujhY38?t=1097) is an update on the Lifetime status with live demos in a Clang prototype
    - [the final part starting at 1:28](https://youtu.be/80BZxujhY38?t=5307) shows the Lifetime and Metaclasses proposals working hand-in-hand (this is one of the few places before cppfront where the same compiler has contained prototypes of multiple 'syntax 2'-derived features so I could show how they build on each other when used together)
- [**C++ Core Guidelines**: Lifetime safety profile](https://github.com/isocpp/CppCoreGuidelines/blob/master/docs/Lifetime.pdf) is this static analysis adopted by the C++ Core Guidelines
- [**P1179**: Lifetime Safety: Preventing common dangling](https://wg21.link/p1179) is the same analysis in the WG 21 paper list

Much of this Lifetime analysis has been implemented and shipped in Visual Studio and in CLion, and initial small parts have been implemented and shipped in Clang. The implementations have exposed bugs in shipping code that were not caught before. My experiment in 'syntax 2' is to make these safety rules the default and mandatory. (Note: Most of this is not yet implemented in cppfront.)
    
I want to again thank many people, including especially Matthias Gehre, Gabor Horvath, Neil MacIntosh, and Kyle Reed for their help in implementing the Lifetime static analysis design in Visual Studio and a Clang fork, and to all of the following for their input and feedback on the specification: Andrei Alexandrescu, Steve Carroll, Pavel Curtis, Gabriel Dos Reis, Joe Duffy, Daniel Frampton, Anna Gringauze, Chris Hawblitzel, Nicolai Josuttis, Ellie Kornstaedt, Aaron Lahman, Ryan McDougall, Nathan Myers, Gor Nishanov, Andrew Pardoe, Jared Parsons, Dave Sielaff, Richard Smith, Jim Springfield, and Bjarne Stroustrup.
    
### 2016: Garbage-collected memory arena

- [**CppCon 2016**: "Leak-freedom in C++... _by default_"](https://www.youtube.com/watch?v=JfmTagWcqoE) particularly [from 59:00 onward](https://youtu.be/JfmTagWcqoE?t=3558) where I show the strawman prototype I wrote of a tracing garbage-collection memory arena
- [**GCPP**: "gcpp: Deferred and unordered destruction"](https://github.com/hsutter/gcpp) is the GitHub prototype I wrote

I welcome a real GC expert to collaborate with on bringing this forward to become a "real" usable tracing GC memory arena that C++ code can opt into. As always, we still prefer scopes first (no tracking needed), and if that's not sufficient then `unique_ptr` (minimal tracking needed), then if that's not sufficient `shared_ptr` (more tracking needed), and then if that's not sufficient this tracing GC arena (suitable for cases where the existing smart pointers aren't enough, such as when you really cannot statically know enough about lifetimes to use the existing smart pointers).

### 2017: Spaceship operator for comparisons, `<=>`
    
- [**CppCon 2017 (just the intro, first 6 minutes)**: "Meta: Thoughts on generative C++"](https://www.youtube.com/watch?v=4AfRAVcThyA)
- [**P0515**: Consistent comparison](https://wg21.link/p0515) is the proposal in today's syntax that I proposed, and was adopted, for C++20

This is the first feature from my Cpp2 work that is now in the ISO C++ standard as part of C++20, and with legacy comparison interoperability improvements in C++23. I had not initially been planning to make this one an ISO C++ proposal yet, but after C++17 shipped the committee continued actively discussing ways to improve comparisons, so since I had a design in my back pocket I submitted it as a proposal and, to my surprise, it was approved in a single meeting. (But see the notes about bug fixes, two paragraphs below.)
    
This is the only feature in the history of ISO C++ where we _added_ a feature to ISO C++ that made the whole standard _smaller_: It took about a dozen pages of core language wording to specify, but it was also applied throughout the standard library which reduced the C++ standard library's specification by about twice that many pages because we removed something like hundreds of comparison operators. I take this as a data point that validates the core hypothesis of 'syntax 2,' that it is possible to simplify today's C++ code (even the standard library's own specification) by thoughtfully adding the right kinds of features to the language.
    
This is also the only feature from the Cpp2 work that I proposed without first having a prototype implementation, and so the proposal had bugs in two main areas that were discovered and fixed later: Keeping the `==` optimization, which was known but in the initial proposal was easy to lose accidentally; and smoother interoperation with existing pre-`<=>` types (which is important because there are _a lot_ of those). Thank you again to everyone who helped land this in the Standard in C++20 and improved in C++23, including: Walter Brown, Lawrence Crowl, Cameron DaCamara, Gabriel Dos Reis, Jens Maurer, Barry Revzin, Richard Smith, and David Stone. This shows the importance of prototype experience.

### 2017: Reflection, generation, and metaclasses
    
- [**ACCU 2017**: "Thoughts on metaclasses"](https://www.youtube.com/watch?v=6nsyX37nsRs) is the first talk I gave about this
- [**CppCon 2017**: "Meta: Thoughts on generative C++"](https://www.youtube.com/watch?v=4AfRAVcThyA) from after the intro, [from 6:00 onward](https://youtu.be/4AfRAVcThyA?t=393)
- [**CppCon 2018**: "Thoughts on a more powerful _and_ simpler C++ ("Simplifying C++" #5 of N)](https://youtu.be/80BZxujhY38)
    - [the section starting at 51:00](https://youtu.be/80BZxujhY38?t=1097) is an update on the Metaclasses status with live demos in a Clang prototype
    - [the final part starting at 1:28](https://youtu.be/80BZxujhY38?t=5307) shows the Lifetime and Metaclasses proposals working hand-in-hand (this is one of the few places before cppfront where the same compiler has contained prototypes of multiple 'syntax 2'-derived features so I could show how they build on each other when used together)
- [**P0707**: Metaclass functions: Generative C++](https://wg21.link/p0707)

The ACCU talk started with something I've never done before: A live mini-"usability study" with unprepared subjects in front of a live audience. (It was not a proper usability study because of conference talk constraints; for example, to save time I allowed myself to use some leading questions. In a real usability study you wouldn't do that.) The reason I did this was because I had already run this design (and parameter passing, below) through actual usability studies with C++ programmers and saw how they consistently reacted to it, and I wanted the ACCU audience to see what I had already seen, namely how real C++ developers who have never seen it before react to it, and how quickly they can understand and learn it. This was a totally legit demonstration... the audience members who came on-stage really had never seen it before and I had never spoken with them about it before.
    
cppfront does not yet have 'syntax 2' user-defined types (classes) or metaclasses. I look forward to starting to implement this in cppfront over the fall and winter... wish me luck! I anticipate that using the AST that cppfront has, which is much closer to a parse tree than a bound tree, is ideal for most metaclass applications which really are about a mental model of "generating source code"... some of what has made previous metaclass prototypes difficult was that they were working on fully bound trees which meant they had to remove work already done, whereas my original design of metaclasses was much closer to the source code level and that's what I aim to (try to) implement.
    
I want to again thank Andrew Sutton and his colleagues Wyatt Childers and Jennifer Yao for their help in implementing the prototypes of this proposal, and everyone else who contributed feedback on the design.

### 2018: Updates to Lifetime and Metaclasses (see above)
    
### 2019: Zero-overhead deterministic exceptions: Throwing values

- [**ACCU 2019**: "De-fragmenting C++: Making exceptions more affordable and usable](https://www.youtube.com/watch?v=os7cqJ5qlzo)
- [**CppCon 2019**: "De-fragmenting C++: Making exceptions and RTTI more affordable and usable ("Simplifying C++" #6 of N)](https://www.youtube.com/watch?v=ARYP83yNAWk)
- [**P0709**: Zero-overhead deterministic exceptions: Throwing values](https://wg21.link/p0709)

I'll just say that when I brought this to the ISO C++ committee, I was amazed that in the Library subgroups a repeated reaction to some (not all) of the library-focused suggestions was "yup, that's a direction we've already decided we want the standard library to move toward..." Except possibly for `<=>` comparisons, this is the only time in my 25 years in WG 21 that I've made a proposal to the committee where I expected to have to do a lot of selling and suddenly had the feeling that I was pushing hard on an open door. (Disclaimer: In the Language subgroups there was more resistance, particularly to make sure pointers to functions would not be bifurcated in the type system. I believe I have an answer to that (thanks to input from Ville Voutilainen in particular), but I still need to prototype it in cppfront, and it still needs to be brought back to the committee to see if they find the results acceptable. There's real work still ahead and a possibility it might not pan out as expected... that's why we use the word "experiment.")

Note: Besides `<=>`, this is the other of the Cpp2-derived proposals that has not yet been implemented, and implementation experience is important before standardizing something like this. I hope to gain experience with it in cppfront, though this will be the trickiest part of this work to implement in a Cpp2->Cpp1 compiler like cppfront because it needs to be coordinated with stack unwinding details deep inside the existing C++ compiler and the platform ABI; I think it's doable, but I realize I have work ahead of me here.
    
### 2020: Parameter passing
    
- **ACCU autumn 2019**: "Quantifying accidental complexity: An empirical look at teaching and using C++" was my first public talk about this, but a "beta" version that was not recorded; you can find the description [here](https://accu.org/conf-previous/2019_autumn/sessions/#XQuantifyingAccidentalComplexityAnEmpiricalLookatTeachingandUsingC)
- [**CppCon 2020**: "Quantifying accidental complexity: An empirical look at teaching and using C++"](https://www.youtube.com/watch?v=6lurOCdaj0Y)
    - The first half of the talk is about how to be rigorous and actually measure that we're making improvements, including to measure the percentage of today's C++ guidance is about parameter passing and initialization
    - The second half of the talk is about `in`, `inout`, `out`, `move`, and `forward`
- [**d0708**: "Parameter passing -> guaranteed unified initialization and value setting](https://github.com/hsutter/708/blob/main/708.pdf) goes into more details than I had time for in the talk, in the second half of the paper (note: this is a "d"-draft paper I haven't formally brought to ISO C++, because during the pandemic I didn't bring any updates to my major papers as I think those major proposals are best considered when the committee can meet in person)
- [**Github.com/hsutter/708**](https://github.com/hsutter/708) is a repo with the paper and demo examples as used in the talk
    
The only change in cppfront is that I've split `in` into `in` (now the whitespace default in 'syntax 2') and `copy`, and implemented automatic-move-from-last-use for `copy` parameters. This is actually consistent with, and rediscovering, what we already teach today, including in my [CppCon 2014 talk at 55:17](https://youtu.be/xnqTKD8uD64?t=3317) where the parameter passing section already distinguishes "in" vs. "in+copy" parameters. _Plus ça change, plus c'est la même chose..._

This is basically all implemented in cppfront, except not the unified `operator=` experiment since I haven't implemented classes yet in 'syntax 2.'

### 2021: `is`, `as`, and pattern matching

- [**CppCon 2021: "Extending and simplifying C++: Thoughts on pattern matching using `is` and `as`"](https://www.youtube.com/watch?v=raB_289NxBk)
- [**P2392**: Pattern matching using `is` and `as`](https://wg21.link/p2392) is the ISO C++ committee paper

Like spaceship `<=>` comparisons, I brought this work to the committee because the committee was actively considering pattern matching proposals, and I had a design in my back pocket and so I asked if they would like to see it and they said yes, so I contributed it. This proposal is actually much more about having a general consistent type query (`is`) and a general consistent type cast (`as`) throughout the language, not just in pattern matching `inspect` statements, and then seeing how it could make the pattern matching also nice to use as well as make its usefulness broadly available instead of just inside `inspect`.
    
Cppfront currently has basic support for `is` and `as`, including for dynamic typing in the language (subsuming "dynamic_cast" downcasts) and the standard library's `std::variant`, `std::optional`, and `std::any`. Just before CppCon I also implemented very basic `inspect` statements and expressions, and I plan to continue fleshing them out. (Side note: This is one of the places I'm really glad to have C++20 as a baseline, because implementing `inspect` expressions and getting the type system right would have been nearly impossible without C++14 generic lambdas, C++17 `if constexpr`, and C++20 concepts `requires` tests. Which might give away the implementation strategy I chose... :) )
    
I still need to validate the `is` and `as` implementations with more cases (I'm sure there are still some that break that I need to fix), flesh out allowing `is` and `as` in `requires`-clauses to constrain templates (as shown in the paper), and non-basic `inspect` pattern matching examples.

### 2022: CppCon 2022 talk and cppfront
    
- **CppCon 2022**: "Can C++ be 10x simpler & safer?" (link coming soon)
- This repo
    
## Epilog: 2016 roadmap diagram
    
Finally, let me show you a diagram I made in 2016. A few words have changed, and some of the topics aren't mentioned (e.g, `<=>` was added after this), but it has remained amazingly stable and is still recognizably a roadmap of Cpp2's design approach today.
    
I think this diagram is important because it attempts to write down how design decisions lead to each other and support each other... Cpp2 is not a gaggle of unrelated fixes, it is an attempt to do a coordinated refactoring of C++ so that it is still C++ but, as Bjarne said, simplified "through generalization" into a smaller number of regular and combinable features, so we can remove special cases and duplications and confusions.
    
![image](https://user-images.githubusercontent.com/1801526/189503047-0b0a4f0f-c5e7-42b2-a17d-37d80bef3970.png)

I haven't updated this since 2016, but it shows many of the talks and papers that have come since then from this work, and it's still a pretty up-to-date roadmap of the major parts of Cpp2. Today's cppfront implements roughly the top-left part of this roadmap, and I plan for more to follow.
    
I hope you enjoy reading about this personal experiment, and I hope that it might at least start a conversation about what we can do _**within C++**_'s own evolution to make C++ 10x simpler, safer, and more toolable.
    
