#include <stdlib.h>
#include "trie.h"

trie_node_t* trie_node_init ()
{
    trie_node_t* trie;
    trie = malloc (sizeof (trie_node_t));
    if (trie == NULL)
        return NULL;
    trie->children = malloc (sizeof (trie_node_t*) * ALPHABET_SIZE);
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
    if (children == NULL)
        return 0;

    if (!VALID_(value))
        return -1;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (children[i] != NULL) {
            if (children[i]->value == value)
                return 1;
        }
    }
    return 0;
}

int trie_add_word (trie_node_t *trie, const char* word)
{
    while (*word) {
        int found = _find_value (trie->children, *(word));
        if (found) {
            trie = trie->children[NORMALIZE_(*(word))];
        } else {
            trie->children[NORMALIZE_(*(word))] = trie_node_init ();
            trie->children[NORMALIZE_(*(word))]->value = *(word);
            trie = trie->children[NORMALIZE_(*word)];
        }
        *(word++);
    }
    return 1;
}

int trie_has_node (trie_node_t *trie, const char* word)
{
    while (*word) {
        int found = _find_value (trie->children, *(word));
        if (found) {
            trie = trie->children[NORMALIZE_(*(word))];
        } else {
            return 0;
        }
        *(word++);
    }
    return 1;
}
