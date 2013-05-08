GCC=gcc
SRC=src
TESTS=tests
BUILD=build
FLAGS=-DDEBUG=0 -std=c99
DEBUG_FLAGS=-DDEBUG=1 -std=c99

SOURCES=$(SRC)/trie.c
TEST_SOURCES=$(TESTS)/thc.c $(TESTS)/test_trie.c $(TESTS)/suite.c

clean:
	rm -rf build/
test:
	@mkdir -p build
	@$(GCC) $(SOURCES) $(TEST_SOURCES) $(FLAGS) -o $(BUILD)/trie_test_bin && $(BUILD)/trie_test_bin
