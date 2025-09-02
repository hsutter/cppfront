# Makefile for self-hosting cppfront

# Compiler settings
CPPFRONT := ../source/cppfront
CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -O3

# Source files
SOURCES := cppfront.cpp2 lexer.cpp2 parser.cpp2 semantic_analyzer.cpp2 code_generator.cpp2
CPP_SOURCES := $(SOURCES:.cpp2=.cpp)

# Target executable
TARGET := cppfront

# Default target
all: $(TARGET)

# Build the self-hosting cppfront
$(TARGET): $(CPP_SOURCES)
	$(CXX) $(CXXFLAGS) -I../include -o $(TARGET) $(CPP_SOURCES)

# Convert Cpp2 to C++ using the existing cppfront
%.cpp: %.cpp2
	$(CPPFRONT) $< > $@

# Clean generated files
clean:
	rm -f $(CPP_SOURCES) $(TARGET)

# Test the compiler
test: $(TARGET)
	./$(TARGET) test.cpp2

.PHONY: all clean test