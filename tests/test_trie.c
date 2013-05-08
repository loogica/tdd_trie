#include <stddef.h>
#include "thc.h"
#include "../src/trie.h"

void test_trie_init (void)
{
    trie_node_t *trie;
    trie = trie_init ();
    ENSURE (NULL != trie);
    ENSURE (0 == trie->value);
    ENSURE (NULL != trie->children);

    for (int i = 0; i < ALPHABET_SIZE; i++)
        ENSURE (trie->children[i] == NULL);
}

void test_trie_find_value (void)
{
    ENSURE (1 == 2);
}
