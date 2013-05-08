#include <stddef.h>
#include "thc.h"
#include "../src/trie.h"

void test_trie_init (void)
{
    trie_node_t *trie;
    trie = trie_init();
    ENSURE (NULL != trie);
    return;
}
