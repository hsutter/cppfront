# Wide-Scanners: SIMD-Accelerated Lexical Analysis for Cppfront

## Overview

Wide-scanners represent an evolution of cppfront's lexical analyzer to leverage SIMD (Single Instruction, Multiple Data) instructions for parallel character processing. This approach draws inspiration from BBCursive auto-vectorization patterns and aims to significantly improve parsing performance for large C++ source files.

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

### 1. Character Classification SIMD

```cpp
// SIMD-accelerated whitespace detection
__m128i whitespace_mask = _mm_set1_epi8(0x20); // space character
__m128i tab_mask = _mm_set1_epi8(0x09);        // tab character
__m128i newline_mask = _mm_set1_epi8(0x0A);    // newline character

bool is_whitespace_simd(const char* data, size_t length) {
    for (size_t i = 0; i < length; i += 16) {
        __m128i chunk = _mm_loadu_si128((__m128i*)&data[i]);
        __m128i ws_result = _mm_or_si128(
            _mm_cmpeq_epi8(chunk, whitespace_mask),
            _mm_or_si128(
                _mm_cmpeq_epi8(chunk, tab_mask),
                _mm_cmpeq_epi8(chunk, newline_mask)
            )
        );
        if (_mm_movemask_epi8(ws_result)) {
            return true; // Found whitespace
        }
    }
    return false;
}
```

### 2. Token Boundary Detection

```cpp
// Parallel token boundary identification
__m128i identifier_chars = create_identifier_mask();
__m128i operator_chars = create_operator_mask();

std::vector<size_t> find_token_boundaries_simd(const std::string& input) {
    std::vector<size_t> boundaries;
    const size_t chunk_size = 16;
    
    for (size_t i = 0; i < input.size(); i += chunk_size) {
        __m128i chunk = _mm_loadu_si128((__m128i*)&input[i]);
        
        // Check for identifier characters
        __m128i id_mask = _mm_and_si128(chunk, identifier_chars);
        
        // Check for operator characters  
        __m128i op_mask = _mm_and_si128(chunk, operator_chars);
        
        // Find transitions between character classes
        uint16_t transition_mask = _mm_movemask_epi8(
            _mm_xor_si128(id_mask, op_mask)
        );
        
        // Extract boundary positions
        while (transition_mask) {
            int bit_pos = __builtin_ctz(transition_mask);
            boundaries.push_back(i + bit_pos);
            transition_mask &= transition_mask - 1;
        }
    }
    
    return boundaries;
}
```

### 3. String Literal Processing

```cpp
// SIMD-accelerated escape sequence detection
bool contains_escape_sequences_simd(const std::string& str) {
    const char* data = str.data();
    size_t length = str.size();
    
    __m128i backslash_mask = _mm_set1_epi8('\\');
    
    for (size_t i = 0; i < length; i += 16) {
        __m128i chunk = _mm_loadu_si128((__m128i*)&data[i]);
        __m128i result = _mm_cmpeq_epi8(chunk, backslash_mask);
        
        if (_mm_movemask_epi8(result)) {
            return true;
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

### SIMD Instruction Sets

- **x86-64**: SSE4.2, AVX2, AVX-512
- **ARM64**: NEON
- **Fallback**: Scalar implementation for unsupported platforms

### Compiler Support

```cpp
#if defined(__SSE4_2__)
#include <nmmintrin.h>  // SSE4.2 CRC32, POPCNT
#endif

#if defined(__AVX2__)
#include <immintrin.h>  // AVX2
#endif

// Runtime CPU feature detection
bool has_simd_support() {
    #if defined(__x86_64__)
    return __builtin_cpu_supports("sse4.2") && __builtin_cpu_supports("avx2");
    #elif defined(__aarch64__)
    return true; // NEON always available on ARM64
    #else
    return false;
    #endif
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
# CMake SIMD detection
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-msse4.2" COMPILER_SUPPORTS_SSE42)
check_cxx_compiler_flag("-mavx2" COMPILER_SUPPORTS_AVX2)

if(COMPILER_SUPPORTS_SSE42)
    add_compile_options(-msse4.2)
    add_definitions(-DCPP2_SIMD_SSE42)
endif()

if(COMPILER_SUPPORTS_AVX2)
    add_compile_options(-mavx2)
    add_definitions(-DCPP2_SIMD_AVX2)
endif()
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

### Advanced SIMD Features

- **AVX-512**: 512-bit vectors for maximum parallelism
- **Masked Operations**: Conditional processing within vectors
- **Gather/Scatter**: Non-contiguous memory access patterns

### Integration Opportunities

- **Regex Engine**: SIMD acceleration for pattern matching
- **Parser Integration**: SIMD-assisted syntax analysis
- **Code Generation**: SIMD-aware code emission

## Conclusion

Wide-scanners represent a significant performance enhancement opportunity for cppfront's lexical analysis. By leveraging SIMD instructions for parallel character processing, we can achieve substantial speedups while maintaining full compatibility with the existing codebase. The implementation follows a phased approach, starting with foundational SIMD primitives and progressing to comprehensive lexer acceleration.

This initiative aligns with modern compiler optimization trends and positions cppfront as a high-performance C++ compilation toolchain capable of handling large-scale codebases efficiently.</content>
<parameter name="filePath">/Users/jim/work/cppfront/docs/wide-scanners.md
