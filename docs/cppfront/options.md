# Cppfront command line options

Cppfront is invoked using

    cppfront [options] file ...

where

- **options** is optional, and can include options described on this page

- **file ...** is a list of one or more `.cpp2` filenames to be compiled

Command line options are spelled starting with `-` or `/` followed by the option name. For example, `-help` prints help.

For convenience, you can shorten the name to any unique prefix not shared with another option. For example:

- `-help` can be equivalently written as `-hel`, `-he`, or `-h`, because no other option starts with `h`.
- `-import-std` and `-include-std` can be shortened to `-im` and `-in` respectively, but not `-i` which would be ambiguous with each other.


# Basic command line options

## `-help`, `-h`, `-?`

Prints an abbreviated version of this documentation page.

## `-import-std`, `-im`

Makes the entire C++ standard library (namespace `std::`) available via a module `import std.compat;` (which implies `import std;`).

> When you use either `-import-std` or `-include-std`, your `.cpp2` program will not need to explicitly `import` any C++ standard library module or `#include` any C++ standard library header (it can still do that, but it would be redundant).

This option is implicitly set if `-pure-cpp2` is selected.

This option is ignored if `-include-std` is selected. If your Cpp1 compiler does not yet support standard library modules `std` and `std.compat`, this option automatically uses  `-include-std` instead as a fallback.

## `-include-std`, `-in`

Makes the entire C++ standard library (namespace `std::`) available via an '#include" of every standard header.

This option should always work with all standard headers, including draft-standard C++26 headers that are not yet in a published standard, because it tracks new headers as they are added and uses feature tests to not include headers that are not yet available on your Cpp1 implementation.

## `-pure-cpp2`, `-p`

Allow Cpp2 syntax only.

This option also sets `-import-std`.

## `-version`, `-vers`

Print version, build, copyright, and license information.


# Additional dynamic safety checks and contract information

## `-add-source-info`, `-a`

Enable `source_location` information for contract checks. If this is supported by your Cpp1 compiler, the default contract failure messages will include exact file/line/function information. For example, if the default `Bounds` violation handler would print this without `-a`:

    Bounds safety violation: out of bounds access attempt detected - attempted access at index 2, [min,max] range is [0,1]

then it would print something like this with `-a` (the exact text will vary with the Cpp1 standard library vendor's `source_location` implementation):

    demo.cpp2(4) int __cdecl main(void): Bounds safety violation: out of bounds access attempt detected - attempted access at index 2, [min,max] range is [0,1]

## `-no-comparison-checks`, `-no-c`

Disable mixed-sign comparison safety checks. If not disabled, mixed-sign comparisons are diagnosed by default.

## `-no-null-checks`, `-no-n`

Disable null safety checks. If not disabled, null dereference checks are performed by default.

## `-no-subscript-checks`, `-no-s`

Disable subscript bounds safety checks. If not disabled, subscript bounds safety checks are performed by default.


# Support for constrained target environments

## `-fno-exceptions`, `-fno-e`

Disable C++ exception handling. This should be used only if you must run in an environment that bans C++ exception handling, and so you are already using a similar command line option for your Cpp1 compiler.

If this option is selected, a failed `as` for `std::variant` will assert.

## `-fno-rtti`, `-fno-r`

Disable C++ run-time type information (RTTI). This should be used only if you must run in an environment that bans C++ RTTI, and so you are already using a similar command line option for your Cpp1 compiler.

If this option is selected, trying to using `as` for `*` (raw pointers) or `std::any` will assert.


# Other options

## `-clean-cpp1`, `-c`

Emit clean `.cpp` files without `#line` directives and other extra information that cppfront normally emits in the `.cpp` to light up C++ tools (e.g., to let IDEs integrate cppfront error message output, debuggers step to the right lines in Cpp2 source code, and so forth). In normal use, you won't need `-c`.

## `-debug`, `-d`

Emit compiler debug output. This is only useful when debugging cppfront itself.

## `-emit-cppfront-info`, `-e`

Emit cppfront version and build in the `.cpp` file.

## `-format-colon-errors`, `-fo`

Emit cppfront diagnostics using `:line:col:` format for line and column numbers, if that is the format better recognized by your IDE, so that it will pick up cppfront messages and integrate them in its normal error message output location. If not set, by default cppfront diagnostics use `(line,col)` format.

## `-line-paths`, `-l`

Emit absolute paths in `#line` directives.

## `-output` _filename_, `-o` _filename_

Output to 'filename' (can be 'stdout'). If not set, the default output filename for is the same as the input filename without the `2` (e.g., compiling `hello.cpp2` by default writes its output to `hello.cpp`, and `header.h2` to `header.h`).

## `-verbose`, `-verb`

Print verbose statistics and `-debug` output.
