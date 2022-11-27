SOURCES = gcc-10-libstdc++-e.cpp2 clang-12-libstdc++-e.cpp2

ifeq ($(OS),Windows_NT)
SOURCES += msvc-msstl-e.cpp2
endif

TARGETS = $(subst .cpp2,.cpp,$(SOURCES))
BATS_TARGETS = $(subst .cpp2,.bats,$(SOURCES))

CPPFRONT = ../source/cppfront

BATS = $(shell which bats)
ifeq (, $(BATS))
	$(error "The 'bats' executble was not found. Try running: sudo apt-get install bats")
endif

all: $(TARGETS)

$(CPPFRONT):
	$(MAKE) -C $(dir $(CPPFRONT))

gcc-10-libstdc++-e.cpp2: all-std.cxx
	g++ all-std.cxx -std=c++2a -fcoroutines -E >$@ || (rm $@ && false)

clang-12-libstdc++-e.cpp2: all-std.cxx
	clang++-14 all-std.cxx -std=c++2a -E >$@ || (rm $@ && false)

ifeq ($(OS),Windows_NT)
msvc-msstl-e.cpp2: all-std.cxx
	cl all-std.cxx -std:c++latest /E >$@ || (rm $@ && false)
endif

%.cpp: %.cpp2 $(CPPFRONT)
	$(CPPFRONT) $<

%.bats: test.bats.envsubst %.cpp
	DOLLAR='$$' TEST_NAME=$* envsubst < $< > $@

check: $(BATS_TARGETS) $(BATS)
	@bats $^

clean:
	rm -f $(SOURCES) $(TARGETS) *.bats && git checkout $(SOURCES) $(TARGETS)
