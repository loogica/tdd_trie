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

void test_trie_add_word (void)
{
    trie_node_t *trie;
    trie = trie_init ();

    ENSURE (1 == trie_add_word (trie, "d"));
    ENSURE (1 == _find_value (trie->children, 'd'));
    ENSURE (1 == trie_add_word (trie, "z"));
    ENSURE (1 == _find_value (trie->children, 'z'));
    ENSURE (1 == _find_value (trie->children, 'z'));
    ENSURE (0 == _find_value (trie->children, 'a'));
    ENSURE (0 == _find_value (trie->children, 'b'));
    ENSURE (0 == _find_value (trie->children, 'c'));
    ENSURE (0 == _find_value (trie->children, 'e'));
}
