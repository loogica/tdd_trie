#include "thc.h"
#include "test_trie.h"

int main (int argc, char *argv[])
{
    thc_addtest (test_trie_init);
    return thc_run (THC_VERBOSE | THC_NOFORK);
}