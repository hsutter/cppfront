# Transitional Package

This package contains the initial work for the self-hosting cppfront implementation and test files.

## Contents

- `selfhost/` - Self-hosting cppfront implementation in Cpp2
- `test_compiler.cpp2` - Simple test file to verify cppfront works
- `test_compiler.cpp` - Generated C++ code from test_compiler.cpp2
- `test_compiler` - Compiled executable from test_compiler.cpp

## Purpose

This transitional package serves as a bridge between the current cppfront implementation and a future self-hosting version. It demonstrates that:

1. The existing cppfront can compile Cpp2 code successfully
2. The generated C++ code can be compiled with a standard C++20 compiler
3. The resulting executables run correctly
4. A self-hosting implementation can be built using the existing toolchain

## Usage

To test the existing cppfront:
```bash
./source/cppfront transitional-package/test_compiler.cpp2
g++ -std=c++20 -I./include transitional-package/test_compiler.cpp -o test_compiler
./test_compiler
```

To build the self-hosting version:
```bash
cd transitional-package/selfhost
./build.sh
```