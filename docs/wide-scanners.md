# Wide-Scanners: SIMD-Accelerated Lexical Analysis for Cppfront

## Overview

Wide-scanners represent an evolution of cppfront's lexical analyzer to leverage SIMD (Single Instruction, Multiple Data) instructions for parallel character processing. This approach draws inspiration from BThis initiative aligns with modern compiler optimizaThis initiative aligns with modern compiler optimization trends and positions cppfront as a high-performance C++ compilation toolchain capable of handling large-scale codebases efficiently.on trends and positions cppfront as a high-performance C++ compilation toolchain capable of handling large-scale codebases efficiently.ursive auto-vectorization patterns and aims to significantly improve parsing performance for large C++ source files.

## Current State Analysis

### Cppfront Scanner Characteristics

- **Implementation**: Manual character-by-character processing in `source/lex.h`
- **Architecture**: Sequential tokenization with `lex_line()` function
- **Performance**: No SIMD utilization, relies on compiler optimizations
- **Regex Engine**: Custom template-based matcher in `include/cpp2regex.h2` with TODOs for vectorization

### Performance Bottlenecks

1. **Sequential Processing**: Character-by-character analysis limits throughput
2. **Branch-Heavy Logic**: Multiple conditional checks for token types
3. **Memory Access Patterns**: Non-contiguous memory access during lexing
4. **String Literal Handling**: Byte-by-byte processing of string contents

## SIMD Acceleration Strategy

### Auto-Vectorization Approach

Instead of platform-specific SIMD intrinsics, we leverage compiler auto-vectorization by writing scalar code that exhibits patterns conducive to vectorization:

- **Loop Unrolling**: Process multiple elements per iteration
- **Branch Elimination**: Use conditional moves instead of branches
- **Memory Alignment**: Ensure data structures support vector loads
- **Data Layout**: Arrange data for contiguous access patterns

### 1. Character Classification Auto-Vectorization

```cpp
// Auto-vectorizable whitespace detection
bool is_whitespace_av(const char* data, size_t length) {
    // Compiler can vectorize this loop
    for (size_t i = 0; i < length; ++i) {
        char c = data[i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            return true;
        }
    }
    return false;
}

// Optimized version for auto-vectorization
bool is_whitespace_av_optimized(const char* data, size_t length) {
    // Process in chunks to help vectorization
    constexpr size_t CHUNK_SIZE = 16;
    size_t i = 0;
    
    // Main vectorizable loop
    for (; i + CHUNK_SIZE <= length; i += CHUNK_SIZE) {
        bool found = false;
        #pragma clang loop vectorize(enable)
        for (size_t j = 0; j < CHUNK_SIZE; ++j) {
            char c = data[i + j];
            found |= (c == ' ' || c == '\t' || c == '\n' || c == '\r');
        }
        if (found) return true;
    }
    
    // Handle remainder
    for (; i < length; ++i) {
        char c = data[i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            return true;
        }
    }
    return false;
}
```

### 2. Token Boundary Detection

```cpp
// Auto-vectorizable token boundary finding
std::vector<size_t> find_token_boundaries_av(const std::string& input) {
    std::vector<size_t> boundaries;
    const char* data = input.data();
    size_t length = input.size();
    
    // Character class lookup tables (encourage vectorization)
    static const bool is_identifier_char[256] = {
        // Initialize with identifier character flags
        ['a'] = true, ['b'] = true, /* ... */ ['z'] = true,
        ['A'] = true, ['B'] = true, /* ... */ ['Z'] = true,
        ['0'] = true, ['1'] = true, /* ... */ ['9'] = true,
        ['_'] = true
    };
    
    static const bool is_operator_char[256] = {
        // Initialize with operator character flags
        ['+'] = true, ['-'] = true, ['*'] = true, ['/'] = true,
        ['='] = true, ['<'] = true, ['>'] = true, ['!'] = true,
        ['&'] = true, ['|'] = true, ['^'] = true, ['%'] = true,
        ['?'] = true, [':'] = true, ['.'] = true, [','] = true,
        [';'] = true, ['('] = true, [')'] = true, ['['] = true,
        [']'] = true, ['{'] = true, ['}'] = true
    };
    
    bool prev_was_identifier = false;
    bool prev_was_operator = false;
    
    #pragma clang loop vectorize(enable)
    for (size_t i = 0; i < length; ++i) {
        char c = data[i];
        bool curr_is_identifier = is_identifier_char[static_cast<unsigned char>(c)];
        bool curr_is_operator = is_operator_char[static_cast<unsigned char>(c)];
        
        // Detect transitions between character classes
        if ((prev_was_identifier && !curr_is_identifier && !curr_is_operator) ||
            (prev_was_operator && !curr_is_operator && !curr_is_identifier) ||
            (!prev_was_identifier && !prev_was_operator && (curr_is_identifier || curr_is_operator))) {
            boundaries.push_back(i);
        }
        
        prev_was_identifier = curr_is_identifier;
        prev_was_operator = curr_is_operator;
    }
    
    return boundaries;
}
```

### 3. String Literal Processing

```cpp
// Auto-vectorizable escape sequence detection
bool contains_escape_sequences_av(const std::string& str) {
    const char* data = str.data();
    size_t length = str.size();
    
    // Use lookup table for vectorization
    static const bool is_escape_char[256] = {
        ['\\'] = true, ['"'] = true, ['\''] = true,
        ['n'] = true, ['t'] = true, ['r'] = true,
        ['0'] = true, ['x'] = true, ['u'] = true, ['U'] = true
    };
    
    bool in_escape = false;
    #pragma clang loop vectorize(enable)
    for (size_t i = 0; i < length; ++i) {
        char c = data[i];
        if (in_escape) {
            if (is_escape_char[static_cast<unsigned char>(c)]) {
                return true;
            }
            in_escape = false;
        } else if (c == '\\') {
            in_escape = true;
        }
    }
    
    return false;
}
```

## Architecture Integration

### Hybrid Approach

- **Fast Path**: SIMD processing for homogeneous character sequences
- **Slow Path**: Traditional processing for complex tokens requiring state
- **Fallback**: Automatic fallback to scalar processing when SIMD unavailable

### Memory Layout Optimization

```cpp
struct alignas(16) simd_token_buffer {
    char data[64];  // 64-byte aligned buffer
    size_t length;
    
    void load_chunk(const char* source, size_t offset) {
        // Ensure aligned loads where possible
        if (offset % 16 == 0) {
            _mm_store_si128((__m128i*)data, _mm_load_si128((__m128i*)&source[offset]));
        } else {
            _mm_store_si128((__m128i*)data, _mm_loadu_si128((__m128i*)&source[offset]));
        }
    }
};
```

## Performance Targets

### Expected Improvements

- **2-4x speedup** for identifier tokenization
- **3-8x speedup** for whitespace skipping
- **1.5-3x speedup** for string literal processing
- **Overall 20-40% improvement** in total lexing time for large files

### Benchmarking Strategy

```cpp
struct lexer_benchmark {
    std::string test_file;
    size_t file_size;
    std::chrono::nanoseconds scalar_time;
    std::chrono::nanoseconds simd_time;
    double speedup_ratio;
    
    void run_comparison() {
        // Load test file
        // Run scalar lexer
        // Run SIMD lexer  
        // Calculate metrics
    }
};
```

## Implementation Roadmap

### Phase 1: Foundation

- [ ] SIMD utility functions and abstractions
- [ ] Character classification SIMD primitives
- [ ] Memory alignment helpers
- [ ] CPU feature detection

### Phase 2: Core Acceleration

- [ ] Whitespace detection SIMD
- [ ] Identifier boundary detection
- [ ] Number literal parsing SIMD
- [ ] String literal escape handling

### Phase 3: Advanced Features

- [ ] Comment processing SIMD
- [ ] Multi-line string handling
- [ ] Unicode character support
- [ ] Error recovery optimization

### Phase 4: Integration

- [ ] Hybrid lexer implementation
- [ ] Performance regression testing
- [ ] Memory usage optimization
- [ ] Cross-platform SIMD support

## Cross-Platform Considerations

### Auto-Vectorization Strategy

- **Compiler Agnostic**: Rely on compiler auto-vectorization rather than intrinsics
- **Universal Compatibility**: Same code works across x86, ARM, RISC-V, etc.
- **Future-Proof**: Adapts to new SIMD instruction sets automatically
- **Maintainability**: No platform-specific code branches

### Compiler Hints and Pragmas

```cpp
// Encourage vectorization with pragmas
#pragma clang loop vectorize(enable)
#pragma clang loop interleave(enable)
#pragma clang loop vectorize_width(4)

// GCC equivalents
#pragma GCC ivdep  // Ignore vector dependencies
#pragma GCC unroll 4

// MSVC
#pragma loop(ivdep)
#pragma loop(no_vector)  // For fallback cases
```

### Optimization Flags

```bash
# Clang/LLVM optimization flags for auto-vectorization
-O3 -march=native -ffast-math -funroll-loops
-Rpass=loop-vectorize -Rpass-analysis=loop-vectorize
-fvectorize -fslp-vectorize

# GCC optimization flags
-O3 -march=native -ftree-vectorize -funroll-loops
-fvect-cost-model=dynamic -fvect-cost-model
```

### Fallback Mechanisms

```cpp
// Runtime vectorization capability detection
bool should_use_vectorized_path() {
    #ifdef __clang__
    return __builtin_cpu_supports("avx2") || __builtin_cpu_supports("sse4.2");
    #elif defined(__GNUC__)
    return __builtin_cpu_supports("avx2") || __builtin_cpu_supports("sse4.2");
    #else
    // Conservative fallback for unknown compilers
    return true;  // Assume vectorization is beneficial
    #endif
}

// Conditional compilation for vectorization hints
#ifdef __clang__
#define VECTORIZE_HINT _Pragma("clang loop vectorize(enable)")
#define INTERLEAVE_HINT _Pragma("clang loop interleave(enable)")
#else
#define VECTORIZE_HINT
#define INTERLEAVE_HINT
#endif

void process_characters(const char* data, size_t length) {
    if (should_use_vectorized_path()) {
        VECTORIZE_HINT
        INTERLEAVE_HINT
        for (size_t i = 0; i < length; ++i) {
            // Vectorizable operations
        }
    } else {
        // Scalar fallback
        for (size_t i = 0; i < length; ++i) {
            // Scalar operations
        }
    }
}
```

## Integration with Existing Codebase

### Minimal Invasive Changes

- Keep existing `lex.h` interface unchanged
- Add SIMD variants as optional implementations
- Use feature flags for SIMD enablement
- Maintain backward compatibility

### Build System Integration

```cmake
# CMake auto-vectorization configuration
include(CheckCXXCompilerFlag)

# Check for vectorization support
check_cxx_compiler_flag("-fvectorize" COMPILER_SUPPORTS_VECTORIZE)
check_cxx_compiler_flag("-ftree-vectorize" COMPILER_SUPPORTS_TREE_VECTORIZE)
check_cxx_compiler_flag("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)

# Optimization flags for auto-vectorization
if(COMPILER_SUPPORTS_VECTORIZE)
    add_compile_options(-fvectorize)
endif()

if(COMPILER_SUPPORTS_TREE_VECTORIZE)
    add_compile_options(-ftree-vectorize)
endif()

if(COMPILER_SUPPORTS_MARCH_NATIVE)
    add_compile_options(-march=native)
endif()

# General optimization flags
add_compile_options(
    -O3
    -ffast-math
    -funroll-loops
    -fomit-frame-pointer
)

# Debug vectorization (Clang)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(
        -Rpass=loop-vectorize
        -Rpass-analysis=loop-vectorize
    )
endif()

# Feature detection
add_definitions(-DCPP2_AUTO_VECTORIZE)
```

## Testing and Validation

### Correctness Verification

- **Token Equivalence**: Ensure SIMD and scalar lexers produce identical tokens
- **Position Accuracy**: Verify character positions are correctly maintained
- **Error Handling**: Test error conditions and recovery paths

### Performance Validation

- **Microbenchmarks**: Individual SIMD primitive performance
- **End-to-End Benchmarks**: Complete file lexing performance
- **Memory Benchmarks**: SIMD memory access patterns
- **Scalability Testing**: Performance across different file sizes

## Future Extensions

### Advanced Auto-Vectorization Features

- **Profile-Guided Optimization**: Use PGO to improve vectorization decisions
- **Loop Transformations**: Advanced loop unrolling and interleaving
- **Memory Prefetching**: Compiler-guided memory access optimization
- **SIMD Function Libraries**: Leverage compiler-built-in vector functions

### Integration Opportunities

- **Regex Engine**: Auto-vectorization for pattern matching loops
- **Parser Integration**: Vectorizable syntax analysis patterns
- **Code Generation**: Vectorization-aware code emission
- **Memory Management**: Vector-aligned memory allocation

### Compiler Evolution

- **New Vectorization Heuristics**: Benefit from compiler improvements automatically
- **Cross-Platform Consistency**: Same optimizations across all supported platforms
- **Debugging Tools**: Better vectorization reports and diagnostics
- **Performance Monitoring**: Runtime vectorization effectiveness tracking

## Conclusion

Wide-scanners represent a significant performance enhancement opportunity for cppfront's lexical analysis through compiler auto-vectorization. By writing scalar code that exhibits vectorization-friendly patterns, we can achieve substantial speedups while maintaining:

- **Platform Independence**: No architecture-specific code required
- **Future Compatibility**: Automatic adaptation to new SIMD capabilities
- **Maintainability**: Clean, readable code without intrinsics
- **Robustness**: Compiler handles optimization complexity

The implementation follows a phased approach, starting with foundational vectorization patterns and progressing to comprehensive lexer acceleration. This auto-vectorization strategy aligns with modern compiler optimization trends and positions cppfront as a high-performance C++ compilation toolchain capable of handling large-scale codebases efficiently without platform-specific tuning.
