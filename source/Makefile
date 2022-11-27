all: cppfront

HEADERS = $(wildcard *.h)

cppfront: cppfront.cpp $(HEADERS)
	g++ --pedantic $< -std=c++20 -o $@

clean:
	rm -f cppfront
