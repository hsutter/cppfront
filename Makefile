# Recursive Makefile to convert Cpp2 files to C++ in target directory
# Outputs to ./target directory like Cargo
# Usage: make all (converts all .cpp2 to .cpp in ./target)

CPPFRONT := ./source/cppfront
TARGET_DIR := ./target
CPP2_FILES := $(shell find . -name "*.cpp2" -type f)
CPP_FILES := $(patsubst %.cpp2, $(TARGET_DIR)/%.cpp, $(CPP2_FILES))

# Compiler settings (adjust as needed)
CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wold-style-cast -Wunused-parameter -Wpedantic -Werror -pthread

.PHONY: all clean build-cppfront

all: build-cppfront $(TARGET_DIR) $(CPP_FILES)

build-cppfront: $(CPPFRONT)

$(CPPFRONT): source/cppfront.cpp
	@echo "Building cppfront executable..."
	$(CXX) source/cppfront.cpp $(CXXFLAGS) -o $(CPPFRONT)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

$(TARGET_DIR)/%.cpp: %.cpp2
	@mkdir -p $(dir $@)
	@echo "Converting $< to $@"
	@if $(CPPFRONT) $< > $@ 2>&1; then 
		echo "Successfully converted $<"; 
	else 
		echo "Failed to convert $< - skipping"; 
		rm -f $@; 
	fi

clean:
	@echo "Cleaning target directory and cppfront executable"
	rm -rf $(TARGET_DIR)
	rm -f $(CPPFRONT)
