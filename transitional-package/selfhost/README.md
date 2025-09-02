# Self-Hosting Cppfront

This is a minimal self-hosting implementation of Cppfront written in Cpp2, with SIMD-optimized wide scanning capabilities.

## Structure

- `cppfront.cpp2` - Main compiler implementation
- `lexer.cpp2` - Lexical analysis with SIMD-optimized wide scanning
- `parser.cpp2` - Parsing of Cpp2 syntax
- `semantic_analyzer.cpp2` - Semantic analysis
- `code_generator.cpp2` - Code generation to C++1
- `test.cpp2` - Sample test file
- `Makefile` - Build system
- `build.sh` - Build script

## Features

1. **SIMD-Optimized Wide Scanning**: Uses vectorized operations for efficient lexical analysis
2. **Auto-Vectorization Hints**: Compiler pragmas to encourage SIMD optimization
3. **Minimal Implementation**: Focuses on core Cpp2 features for bootstrapping
4. **Self-Hosting**: Able to compile itself

## Building

### Method 1: Using the build script (recommended)
```bash
./build.sh
```

### Method 2: Using make
```bash
make
```

### Method 3: Manual build
1. Use the existing cppfront to compile the Cpp2 files:
   ```bash
   ../source/cppfront cppfront.cpp2 > cppfront.cpp
   ../source/cppfront lexer.cpp2 > lexer.cpp
   ../source/cppfront parser.cpp2 > parser.cpp
   ../source/cppfront semantic_analyzer.cpp2 > semantic_analyzer.cpp
   ../source/cppfront code_generator.cpp2 > code_generator.cpp
   ```

2. Compile the generated C++ code:
   ```bash
   g++ -std=c++20 -I../include -O3 -o cppfront cppfront.cpp lexer.cpp parser.cpp semantic_analyzer.cpp code_generator.cpp
   ```

## Testing

After building, you can test the compiler with:
```bash
./cppfront test.cpp2
```

## SIMD Optimization Features

The lexer includes SIMD-optimized functions for:
- Whitespace detection
- Boundary detection
- Character classification

These functions use compiler hints to encourage auto-vectorization:
```cpp
#pragma clang loop vectorize(enable)
```

## Design Goals

1. Minimal implementation focusing on core Cpp2 features
2. Self-hosting (able to compile itself)
3. Dependency on existing cppfront for bootstrapping
4. SIMD-optimized lexical analysis for performance
5. Extensible architecture for future enhancements