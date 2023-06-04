# cppfront

<image align="right" width="320" src="https://user-images.githubusercontent.com/1801526/192037760-90c68098-a72d-4111-accf-5a5a682e2b6e.png"> Copyright (c) Herb Sutter

See [License](LICENSE)

[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](CODE_OF_CONDUCT.md)

Cppfront is an experimental compiler from a potential C++ 'syntax 2' (Cpp2) to today's 'syntax 1' (Cpp1), to learn some things, prove out some concepts, and share some ideas. This compiler is a work in progress and currently hilariously incomplete... basic functions work, classes will be next, then metaclasses and lightweight exceptions.

- [Goals and history](#goals-and-history)
- [What's different about this experiment?](#whats-different-about-this-experiment)
- [How do I build cppfront?](#how-do-i-build-cppfront)
- [How do I build my `.cpp2` file?](#how-do-i-build-my-cpp2-file)
- [Where's the documentation?](#wheres-the-documentation)
- [Papers and talks derived from this work (presented in today's syntax)](#papers-and-talks-derived-from-this-work-presented-in-current-syntax)
- [Epilog: 2016 roadmap diagram](#epilog-2016-roadmap-diagram)

## Goals and history

<image align="right" width="320" src="https://user-images.githubusercontent.com/1801526/189241726-db92ae64-2b2f-4463-a0c3-87794062da9c.png"> My goal is to explore whether there's a way we can evolve C++ itself to become 10x simpler, safer, and more toolable. If we had an alternate C++ syntax, it would give us a "bubble of new code that doesn't exist today" where we could make arbitrary improvements (e.g., change defaults, remove unsafe parts, make the language context-free and order-independent, and generally apply 30 years' worth of learnings), free of backward source compatibility constraints.

In 2015-16 I did most of the 'syntax 2' design work. Since then, my ISO C++ evolution proposals and conference talks have come from this work (see list below) — each presenting one part of the design as a standalone proposal under today's syntax, usually with a standalone prototype implementation, to validate and refine that part. Since 2021, I've been writing this cppfront compiler to prototype all the parts together as a whole as originally intended, now including the alternative 'syntax 2' for C++ that enables their full designs including otherwise-breaking changes.

## What's different about this experiment?

This is one of many experiments going on across the industry looking at ways to accomplish a major C++ evolution. I look forward to seeing how all the experiments work out. This experiment is different in two main ways.

### 1) This is about C++20/23/... — not about something else

<image align="right" width="150" src="https://user-images.githubusercontent.com/1801526/188887745-23e0c3a0-3ea7-4589-993c-f54fe662b107.png"> For me, ISO C++ is the best tool in the world today to write the programs I want and need. I want to keep writing code in C++... just "nicer":

- with less complexity to remember;

- with fewer safety gotchas; and

- with the same level of tool support other languages enjoy.

We've been improving C++'s safety and ergonomics with each ISO C++ release, but they have been "10%" improvements. We haven't been able to do a **"10x"** improvement primarily because we have to keep 100% syntax backward compatibility. So, what if we could have our compatibility cake, and eat it too — by having:

- 100% seamless **link compatibility always** (no marshaling, no thunks, no wrappers, no generated 'compatibility modules' to import/export C++ code from/to a different world); and

- 100% seamless **backward source compatibility always _available_**, including 100% SFINAE and macro compatibility, but only pay for it when we use it... that is, apply C++'s familiar "zero-overhead principle" also to backward source compatibility?

In cppfront this means you have two options always available: (1) _Write mixed Cpp1/Cpp2 in the same source file_ with perfect backward source compatibility via `#include` or `import`. (2) _Write only Cpp2 in a particular source file_ and program in a 10x simpler C++, where code is type-safe and memory-safe by construction, keeps perfect backward link compatibility via `import`, and in the future (if this project succeeds) with faster compilers and better tools tuned for the simpler language.

I hope to start a conversation about what could be possible _**within C++**_’s own evolution to rejuvenate C++, now that we have C++20 and soon C++23 to build upon. I want to encourage us to look for ways to push the boundaries to bring C++ itself forward and double down on C++ — not to switch to something else. I want us to aim for major C++ evolution directed toward things that will make us better C++ programmers — not programmers of something else.

### 2) This is about measurable improvements to safety, simplicity, and toolability — not about green-field design or random drive-by changes

<image align="right" width="320" src="https://user-images.githubusercontent.com/1801526/189236486-0b5a4892-42c8-4486-9722-bb60a5df8c7e.png"> My specific goal is to explore the question: Can we make C++ **10x safer, simpler, and more toolable?** I want each proposed improvement to address those known C++ pain points in a measurable way (e.g., reduce a class of CVEs (vulnerabilities) by A%, reduce the guidance we have to teach by B%).

An alternative syntax would let us do things we can never do within today's syntax without breaking the world:

- fix defaults (e.g., make `[[nodiscard]]` the default);
- double down on modern C++ (e.g., make C++20 modules and C++23 `import std;` the default);
- remove unsafe parts that are already superseded (e.g., remove `union` and pointer arithmetic);
- have type and memory safety by default (e.g., make the [C++ Core Guidelines safety profiles](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-profile) the default and required);
- eliminate 90% of the guidance we have to teach about today's complex language;
- make it easy to write a parser (e.g., have a context-free grammar); and
- make it easy to write refactoring and other tools (e.g., have order-independent semantics).

### Acknowledgments

Scores of people have given valuable feedback and many are listed below, but I especially want to thank Joe Duffy, Anders Hejlsberg, Bjarne Stroustrup, Andrew Sutton, Tim Sweeney, and Mads Torgersen for their insights and valuable feedback on this work over the years — especially when they disagreed with me. I'd also like to thank Dave Abrahams, Andrei Alexandrescu, Walter Bright, Lee Howes, Chris McKinsey, Scott Meyers, Gor Nishanov, Andrew Pardoe, Sean Parent, Jared Parsons, David Sankel, Nathan Sidwell, JC van Winkel, and Ville Voutilainen for broad feedback on the design.

Many more people are listed below for their help with specific parts of the design and those proposals/prototypes. I apologize for the names I have forgotten.

## How do I build cppfront?

<image align="right" width="120" src="https://user-images.githubusercontent.com/1801526/188906112-ef377a79-b6a9-4a30-b318-10b51d8ea934.png">
Cppfront builds with any major C++20 compiler.

#### MSVC build instructions

    cl cppfront.cpp -std:c++20 -EHsc

#### GCC build instructions

    g++-10 cppfront.cpp -std=c++20 -o cppfront

#### Clang build instructions

    clang++-12 cppfront.cpp -std=c++20 -o cppfront

## How do I build my `.cpp2` file?

Run `cppfront your.cpp2`, then run the generated `your.cpp` through any major C++20 compiler after putting `/cppfront/include` in the path so it can find `cpp2util.h`.

- MSVC would be: `cl your.cpp -std:c++20 -EHsc`
- GCC would be: `g++-10 your.cpp -std=c++20`
- Clang would be: `clang++-12 your.cpp -std=c++20`

## Where's the documentation?

I'm not posting much documentation because that would imply this project is intended for others to use — if it someday becomes ready for that, I'll post more docs.

To learn more, please see:

- [**My CppCon 2022 talk, "Can C++ be 10x simpler and safer ...?"**](https://www.youtube.com/watch?v=ELeZAKCN4tY)
- **The [cppfront regression tests](https://github.com/hsutter/cppfront/tree/main/regression-tests)** which show dozens of working examples, each with a`.cpp2` file. In the `/test-results/` subdirectory you can see the `.cpp` file that each is translated to. Each filename briefly describes the language features the test demonstrates (e.g., contracts, parameter passing, bounds safety, type-safe `is` queries and `as` casts, initialization safety, and generalized value capture including in function expressions ('lambdas'), postconditions, and string interpolation).
- The list of papers and talks below.

## Papers and talks derived from this work (presented in current syntax)

Here are the ISO C++ papers and CppCon conference talks I've given since 2015 that have been derived from this work, in the order that I brought each piece forward. Most of the details in the materials below are still current with only incremental updates, apart from the specific syntax of course.

### 2015: Lifetime safety

- [**CppCon 2015**: "Writing good C++14... _by default_"](https://youtu.be/hEx5DNLWGgA) particularly [from 29:00 onward](https://youtu.be/hEx5DNLWGgA?t=1757) shows the Lifetime analysis with live demos in a Visual Studio prototype.
- [**CppCon 2018**: "Thoughts on a more powerful _and_ simpler C++ (#5 of N)](https://youtu.be/80BZxujhY38):
    - [The section starting at 18:00](https://youtu.be/80BZxujhY38?t=1097) is an update on the Lifetime status with live demos in a Clang prototype.
    - [The final part starting at 1:28:00](https://youtu.be/80BZxujhY38?t=5307) shows the Lifetime and Metaclasses proposals working hand-in-hand. This is one of the few places before cppfront where the same compiler has contained prototypes of multiple 'syntax 2'-derived features so I could show how they build on each other when used together.
- [**C++ Core Guidelines**: Lifetime safety profile](https://github.com/isocpp/CppCoreGuidelines/blob/master/docs/Lifetime.pdf) is this static analysis adopted by the C++ Core Guidelines.
- [**P1179**: Lifetime Safety: Preventing common dangling](https://wg21.link/p1179) is the same analysis in the WG 21 paper list.

This is not yet implemented in cppfront. Implementations are shipping in Visual Studio and in CLion, and initial parts have been upstreamed in Clang. I want to especially thank Matthias Gehre, Gabor Horvath, Neil MacIntosh, and Kyle Reed for their help in implementing the Lifetime static analysis design in Visual Studio and a Clang fork. Thanks also to the following for their input and feedback on the specification: Andrei Alexandrescu, Steve Carroll, Pavel Curtis, Gabriel Dos Reis, Joe Duffy, Daniel Frampton, Anna Gringauze, Chris Hawblitzel, Nicolai Josuttis, Ellie Kornstaedt, Aaron Lahman, Ryan McDougall, Nathan Myers, Gor Nishanov, Andrew Pardoe, Jared Parsons, Dave Sielaff, Richard Smith, Jim Springfield, and Bjarne Stroustrup.

### 2016: Garbage-collected memory arena

- [**CppCon 2016**: "Leak-freedom in C++... _by default_"](https://www.youtube.com/watch?v=JfmTagWcqoE) particularly [from 59:00 onward](https://youtu.be/JfmTagWcqoE?t=3558) where I show the strawman prototype I wrote of a tracing garbage-collection memory arena.
- [**Github.com/hsutter/gcpp**: "gcpp: Deferred and unordered destruction"](https://github.com/hsutter/gcpp) is the GitHub prototype I wrote.

This is not yet implemented in cppfront. I welcome a real GC expert to collaborate with on bringing this forward to become a "real" usable tracing GC memory arena that C++ code can opt into, with real C++ zero-overhead costing (don't pay anything if you don't do a `gc.new`, and if you do use it then have the costs be proportional to the number of `gc.new` allocations).

### 2017: Spaceship operator for comparisons, `<=>`

- [**CppCon 2017 (just the intro, first 6 minutes)**: "Meta: Thoughts on generative C++"](https://www.youtube.com/watch?v=4AfRAVcThyA).
- [**P0515**: Consistent comparison](https://wg21.link/p0515) is the proposal in today's syntax that I proposed, and was adopted, for C++20.

This is part of ISO C++20 and C++23. Thank you again to everyone who helped land this in the Standard in C++20 and improve it in C++23, including especially Walter Brown, Lawrence Crowl, Cameron DaCamara, Gabriel Dos Reis, Jens Maurer, Barry Revzin, Richard Smith, and David Stone.

### 2017: Reflection, generation, and metaclasses

- [**ACCU 2017**: "Thoughts on metaclasses"](https://www.youtube.com/watch?v=6nsyX37nsRs) is the first talk I gave about this.
- [**CppCon 2017**: "Meta: Thoughts on generative C++"](https://www.youtube.com/watch?v=4AfRAVcThyA) from after the intro, [from 6:00 onward](https://youtu.be/4AfRAVcThyA?t=393).
- [**CppCon 2018**: "Thoughts on a more powerful _and_ simpler C++ ("Simplifying C++" #5 of N)](https://youtu.be/80BZxujhY38):
    - [The section starting at 51:00](https://youtu.be/80BZxujhY38?t=1097) is an update on the Metaclasses status with live demos in a Clang prototype.
    - (repeating the Lifetime section bullet above) [The final part starting at 1:28](https://youtu.be/80BZxujhY38?t=5307) shows the Lifetime and Metaclasses proposals working hand-in-hand. This is one of the few places before cppfront where the same compiler has contained prototypes of multiple 'syntax 2'-derived features so I could show how they build on each other when used together.
- [**P0707**: Metaclass functions: Generative C++](https://wg21.link/p0707) is the paper I brought to the ISO C++ committee.

This is not yet implemented in cppfront. Thanks again to Andrew Sutton and his colleagues Wyatt Childers and Jennifer Yao for their help in implementing the Clang-based prototypes of this proposal, and everyone else who contributed feedback on the design including Louis Brandy, Chandler Carruth, Casey Carter, Matúš Chochlík, Lawrence Crowl, Pavel Curtis, Louis Dionne, Gabriel Dos Reis, Joe Duffy, Kenny Kerr, Nicolai Josuttis, Aaron Lahman, Scott Meyers, Axel Naumann, Gor Nishanov, Stephan T. Lavavej, Andrew Pardoe, Sean Parent, Jared Parsons, David Sankel, Richard Smith, Jeff Snyder, Mike Spertus, Mads Torgersen, Daveed Vandevoorde, Tony Van Eerd, JC van Winkel, Ville Voutilainen, and Titus Winters, and many more WG 21 / SG 7 participants.

### 2018: Updates to Lifetime and Metaclasses (see above)

### 2019: Zero-overhead deterministic exceptions: Throwing values

- [**ACCU 2019**: "De-fragmenting C++: Making exceptions more affordable and usable](https://www.youtube.com/watch?v=os7cqJ5qlzo).
- [**CppCon 2019**: "De-fragmenting C++: Making exceptions and RTTI more affordable and usable ("Simplifying C++" #6 of N)](https://www.youtube.com/watch?v=ARYP83yNAWk).
- [**P0709**: Zero-overhead deterministic exceptions: Throwing values](https://wg21.link/p0709).

This is not yet implemented in cppfront.

### 2020: Parameter passing

- **ACCU autumn 2019**: "Quantifying accidental complexity: An empirical look at teaching and using C++" was my first public talk about this, but a "beta" version that was not recorded; you can find the description [here](https://accu.org/conf-previous/2019_autumn/sessions/#XQuantifyingAccidentalComplexityAnEmpiricalLookatTeachingandUsingC).
- [**CppCon 2020**: "Quantifying accidental complexity: An empirical look at teaching and using C++"](https://www.youtube.com/watch?v=6lurOCdaj0Y):
    - The first half of the talk is about how to be rigorous and actually measure that we're making improvements, including to measure the percentage of today's C++ guidance that is about parameter passing and initialization.
    - The second half of the talk is about `in`, `inout`, `out`, `move`, and `forward`.
- [**d0708**: "Parameter passing -> guaranteed unified initialization and value setting](https://github.com/hsutter/708/blob/main/708.pdf) goes into additional detail I didn't have time for in the talk.
- [**Github.com/hsutter/708**](https://github.com/hsutter/708) is a repo with the paper and demo examples as used in the talk.
- [**P2064**: "Assumptions"](https://wg21.link/p2064) is also related to this 'syntax 2' work, because this work includes a contracts design, and assumptions ought to be separate from that. This paper was making the technical argument why assumptions and assertions (contracts) are different things.

This is implemented in cppfront, except not the unified `operator=` experiment which will come with classes. Thanks to Andrew Sutton for an initial Clang-based implementation.

### 2020: "Bridge to NewThingia"

In 2020 I also started socializing the ideas of:

- _How do you answer "why is your thing different when others that look like it have all failed"?_
- _What does it take to be adoptable, including to enable incremental adoption?_

I had specifically in mind a major C++ evolution's success when many attempts to make C or C++ safer have failed, and the importance of seamless compatibility. The talk was "Bridge to NewThingia," presented at:

- [**DevAroundTheSun**: "Bridge to Newthingia"](https://herbsutter.com/2020/06/14/talk-video-available-bridge-to-newthingia-devaroundthesun/), an initial 26-minute version.
- [**C++ on Sea**: "Bridge to NewThingia"](https://www.youtube.com/watch?v=BF3qw1ObUyo) which especially [at the end starting near 48:00](https://youtu.be/BF3qw1ObUyo?t=2883) had a slide that directly tackled the "C++ major evolution" scenario, and laid out what I think it would take to have credible answers to the key questions.

### 2021: `is`, `as`, and pattern matching

- [**CppCon 2021**: "Extending and simplifying C++: Thoughts on pattern matching using `is` and `as`"](https://www.youtube.com/watch?v=raB_289NxBk).
- [**P2392**: Pattern matching using `is` and `as`](https://wg21.link/p2392) is the ISO C++ committee paper.

This is partly implemented in cppfront. There is basic support for `is` and `as`, and very basic `inspect` expressions.

### 2022: CppCon 2022 talk and cppfront

- [**CppCon 2022: "Can C++ be 10x simpler and safer ...?"**](https://www.youtube.com/watch?v=ELeZAKCN4tY)
- This repo.

# Epilog: 2016 roadmap diagram

Finally, here is a roadmap diagram I made in 2016 that is still recognizably a roadmap of Cpp2's design approach, although a few additions like `<=>` came later. I think this is important to show design decisions are related and support each other, so that they are not a gaggle of point fixes but a coordinated refactoring of C++ into a smaller number of regular and combinable features. As Bjarne Stroustrup put it in the _ACM History of Programming Languages III_ (among other places):

> "**10% the size of C++** in definition and similar in front-end compiler size. ... **Most of the simplification would come from generalization.**" (B. Stroustrup, ACM HOPL-III, 2007; emphasis added)


![image](https://user-images.githubusercontent.com/1801526/189503047-0b0a4f0f-c5e7-42b2-a17d-37d80bef3970.png)

I haven't updated this roadmap diagram since 2016, but it shows many of the talks and papers that have come since then from this work, and it's still a pretty up-to-date roadmap of the major parts of Cpp2. As of spring 2023, cppfront implements most of this roadmap.

I hope you enjoy reading about this personal experiment, and I hope that it might at least start a conversation about what could be possible _**within C++**_'s own evolution to make C++ 10x simpler, safer, and more toolable.

