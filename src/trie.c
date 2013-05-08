#include <stdlib.h>
#include "trie.h"

trie_node_t* trie_init()
{
    trie_node_t* trie;
    trie = malloc(sizeof(trie_node_t));
    return trie;
}
