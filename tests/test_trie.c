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
    trie_node_t **children = malloc (sizeof (trie_node_t) * ALPHABET_SIZE);
    const char *input = "aacdefghijklmnopqrssuvxwyz";

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = malloc (sizeof (trie_node_t));
        children[i]->value = *(input++);
    }

    ENSURE (0 == _find_value(children, 't'));
    ENSURE (0 == _find_value(children, 'b'));
    ENSURE (1 == _find_value(children, 'z'));
    ENSURE (1 == _find_value(children, 'a'));
}
