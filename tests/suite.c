#include "thc.h"
#include "test_trie.h"

int main (int argc, char *argv[])
{
    thc_addtest (test_trie_node_init);
    thc_addtest (test_trie_find_value);
    thc_addtest (test_trie_add_word);
    thc_addtest (test_trie_has_word);
    return thc_run (THC_VERBOSE);
}
