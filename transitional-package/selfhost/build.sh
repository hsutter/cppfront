#!/bin/bash
# build.sh - Build script for self-hosting cppfront

echo "=== Building self-hosting cppfront ==="

# Check if we're in the right directory
if [ ! -f "cppfront.cpp2" ]; then
    echo "Error: cppfront.cpp2 not found. Please run this script from the selfhost directory."
    exit 1
fi

# Check if the main cppfront exists
CPPFRONT_PATH="../../source/cppfront"
if [ ! -f "$CPPFRONT_PATH" ]; then
    echo "Error: Main cppfront not found at $CPPFRONT_PATH"
    exit 1
fi

# Convert Cpp2 files to C++ (extract only the C++ code, not the status messages)
echo "Converting Cpp2 files to C++..."
$CPPFRONT_PATH cppfront.cpp2 | tail -n +3 > cppfront.cpp
$CPPFRONT_PATH lexer.cpp2 | tail -n +3 > lexer.cpp
$CPPFRONT_PATH parser.cpp2 | tail -n +3 > parser.cpp
$CPPFRONT_PATH semantic_analyzer.cpp2 | tail -n +3 > semantic_analyzer.cpp
$CPPFRONT_PATH code_generator.cpp2 | tail -n +3 > code_generator.cpp

# Compile the generated C++ code
echo "Compiling generated C++ code..."
g++ -std=c++20 -Wall -Wextra -O3 -I../../include -o cppfront cppfront.cpp

if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "You can now run the self-hosting cppfront with './cppfront'"
else
    echo "Build failed!"
    exit 1
fi