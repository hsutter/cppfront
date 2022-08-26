File `all-std.cxx` is an include-all-standard-headers file
intended to be built with

    g++-10 all-std.cxx -std=c++2a -E > gcc-10-libstdc++-e.cpp2

    clang++-12 all-std.cxx -std=c++2a -E > clang-12-libstdc++-e.cpp2

    cl all-std.cxx -std:c++latest /E > msvc-msstl-e.cpp2

each of which generates a single .cpp2 test file representing the
contents of a stdlib implementation.

> **Note**: Not all implementations actually support all standard headers.
> So for each compiler invocation above just manually edit `all-std.cxx`
> to comment out the headers that implementation doesn't understand.

Each such `.cpp2` file is then compiled with `cppfront` and the output `.cpp`
file tested to be diff-identical ith the `.cpp2` input, to ensure
that cppfront correctly passes Cpp1 code through unchanged.

Here's a test script:

    cppfront gcc-10-libstdc++-e.cpp2
    diff -s -Z gcc-10-libstdc++-e.cpp2 gcc-10-libstdc++-e.cpp

    cppfront clang-12-libstdc++-e.cpp2
    diff -s -Z clang-12-libstdc++-e.cpp2 clang-12-libstdc++-e.cpp

    cppfront msvc-msstl-e.cpp2
    diff -s -Z msvc-msstl-e.cpp2 msvc-msstl-e.cpp

Each diff should report "files ... are identical".
