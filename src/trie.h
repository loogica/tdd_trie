#define ALPHABET_SIZE 26

typedef struct trie_node_s trie_node_t;

struct trie_node_s {
    char value;
    trie_node_t **children;
};

trie_node_t* trie_init (void);
