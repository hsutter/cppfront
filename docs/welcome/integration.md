
# Adding cppfront in your IDE / build system

To start trying out Cpp2 syntax in any existing C++ project, just add a build step to translate the Cpp2 to Cpp1 syntax:

- Copy the `.cpp` file to the same name with a `.cpp2` extension.
- Add the `.cpp2` file to the project, and ensure the `.cpp` is in C++20 mode.
- Tell the IDE to build that file using a custom build tool to invoke cppfront.

That's it... The result Just Works with every C++20 or higher compiler and all existing C++ tools (debuggers, build systems, sanitizers, etc.). The IDE build should just pick up the `.cpp2` file source locations for any error messages, and the debugger should just step through the `.cpp2` file.

The following uses Visual Studio as an example, but others have done the same in Xcode, Qt Creator, CMake, and other IDEs.

## <a id="add-cpp2"></a> 1. Add the `.cpp2` file to the project, and ensure the `.cpp` is in C++20 mode

For Visual Studio: In the Solution Explorer, right-click on Source Files and pick Add to add the file to the project.

<p align="center"><img width="600" src="https://github.com/hsutter/cppfront/assets/1801526/0be904e4-4222-40bc-85e4-b573d6371d2d"></p>

Also in Solution Explorer, right-click on the `.cpp` file Properties and make sure it's in C++20 (or C++latest) mode.

<p align="center"><img width="600" src="https://github.com/hsutter/cppfront/assets/1801526/f7a25778-5056-41b3-a6e3-3034bf0587fd"></p>


## <a id="add-build-step"></a> 2. Tell the project system to build that file using a custom build tool to invoke cppfront, and add `cppfront/include` to the include path

For Visual Studio: In Solution Explorer, right-click on the `.cpp2` file and select Properties, and add the custom build tool. Remember to also tell it that the custom build tool produces the `.cpp` file, so that it knows about the build dependency:

<p align="center"><img width="600" src="https://github.com/hsutter/cppfront/assets/1801526/1307ac57-6c3b-4c83-b606-f5c626867ebf"></p>

Finally, put the `/cppfront/include` directory on your `INCLUDE` path. In Solution Explorer, right-click the app and select Properties, and add it to the VC++ Directories > Include Directories:

<p align="center"><img width="600" src="https://github.com/hsutter/cppfront/assets/1801526/866fc2b8-bfca-4568-823b-f0fecfae27f5"></p>


## <a id="it-just-works"></a> That's it: Error message outputs, debuggers, visualizers, and other tools should just work

That's enough to enable builds, and the IDE just picks up the rest from the `.cpp` file that cppfront generated:

- **The cppfront error messages in `filename(line, col)` format.** Most C++ IDEs recognize these, and usually automatically merge any diagnostic output wherever compiler error output normally appears. If your IDE prefers `filename:line:col`, just use the cppfront `-format-colon-errors` command line option.

- **The `#line` directives cppfront emits in the generated `.cpp` file.** Most C++ debuggers recognize these and will know to step through the `.cpp2` file. Note that `#line` emission is on by default, but if you choose `-c` (short for `-clean-cpp1`) these will be suppressed and then the debugger will step through the generated C++ code instead.  If your debugger can't find the files, you may need to use `-line-paths` to have absolute paths instead of relative paths in the `#line` directives.

- **Regardless of syntax, every type/function/object/namespace/etc. is still just an ordinary C++ type/function/object/namespace/etc.** Most C++ debugger visualizers will just work and show beautiful output for the types your program uses, including to use any in-the-box visualizers for all the `std::` types (since those are used directly as usual) and any custom visualizers you may have already written for your own types or popular library types.

