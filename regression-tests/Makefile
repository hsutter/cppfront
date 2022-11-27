MIXED_SOURCES = $(wildcard mixed-*.cpp2)
PURE_SOURCES = $(wildcard pure2-*.cpp2)

RESULTS_DIR = test-results

MIXED_TARGETS = $(subst .cpp2,.cpp,$(MIXED_SOURCES))
PURE_TARGETS = $(subst .cpp2,.cpp,$(PURE_SOURCES))

ALL_TARGETS = $(MIXED_TARGETS) $(PURE_TARGETS)

BATS_TARGETS = $(subst .cpp,.bats,$(ALL_TARGETS))

CPPFRONT = ../source/cppfront

NEGATIVE_TESTS = negative_tests

BATS = $(shell which bats)
ifeq (, $(BATS))
$(error "The 'bats' executble was not found. Try running: sudo apt-get install bats")
endif

all:
	@true

check: $(BATS_TARGETS) $(BATS)
	@$(BATS) $^

$(CPPFRONT):
	$(MAKE) -C $(dir $(CPPFRONT))

mixed-%.bats: test.bats.envsubst $(CPPFRONT) $(NEGATIVE_TESTS)
	DOLLAR='$$' CPPFRONT=$(CPPFRONT) CPPFRONT_FLAGS= STATUS=`grep $* $(NEGATIVE_TESTS) | awk '{print $$NF} END {if(NR==0) print NR}'` RESULTS_DIR=$(RESULTS_DIR) TEST_NAME=mixed-$* envsubst < $< > $@

pure2-%.bats: test.bats.envsubst $(CPPFRONT)
	DOLLAR='$$' CPPFRONT=$(CPPFRONT) CPPFRONT_FLAGS="-p" STATUS=`grep $* $(NEGATIVE_TESTS) | awk '{print $$NF} END {if(NR==0) print NR}'` RESULTS_DIR=$(RESULTS_DIR) TEST_NAME=pure2-$* envsubst < $< > $@

clean:
	rm -f $(MIXED_TARGETS) $(PURE_TARGETS) $(BATS_TARGETS)
	git checkout $(RESULTS_DIR)
