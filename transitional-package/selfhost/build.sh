#!/bin/bash
# build.sh - Build script for self-hosting cppfront

echo "=== Building self-hosting cppfront ==="

# Check if we're in the right directory
if [ ! -f "cppfront.cpp2" ]; then
    echo "Error: cppfront.cpp2 not found. Please run this script from the selfhost directory."
    exit 1
fi

# Check if the main cppfront exists
if [ ! -f "../source/cppfront" ]; then
    echo "Error: Main cppfront not found. Please build it first with 'make build-cppfront' in the root directory."
    exit 1
fi

# Convert Cpp2 files to C++
echo "Converting Cpp2 files to C++..."
../source/cppfront cppfront.cpp2 > cppfront.cpp
../source/cppfront lexer.cpp2 > lexer.cpp
../source/cppfront parser.cpp2 > parser.cpp
../source/cppfront semantic_analyzer.cpp2 > semantic_analyzer.cpp
../source/cppfront code_generator.cpp2 > code_generator.cpp

# Compile the generated C++ code
echo "Compiling generated C++ code..."
g++ -std=c++20 -Wall -Wextra -O3 -I../include -o cppfront cppfront.cpp lexer.cpp parser.cpp semantic_analyzer.cpp code_generator.cpp

if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "You can now run the self-hosting cppfront with './cppfront <source.cpp2>'"
    echo "Try './cppfront test.cpp2' to test it with the sample file."
else
    echo "Build failed!"
    exit 1
fi