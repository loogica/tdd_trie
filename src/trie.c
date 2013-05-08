#include <stdlib.h>
#include "trie.h"

trie_node_t* trie_init ()
{
    trie_node_t* trie;
    trie = malloc (sizeof (trie_node_t));
    if (trie == NULL)
        return NULL;
    trie->children = malloc (sizeof (trie_node_t) * ALPHABET_SIZE);
    if (trie->children == NULL) {
        free (trie);
        return NULL;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        trie->children[i] = NULL;
    }
    trie->value = 0;
    return trie;
}

int _find_value (trie_node_t **children, const char value)
{

}
