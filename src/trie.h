#define ALPHABET_SIZE 26
#define NORMALIZE_(l) (l - 97)

typedef struct trie_node_s trie_node_t;

struct trie_node_s {
    char value;
    trie_node_t **children;
};

trie_node_t* trie_node_init (void);
int _find_value (trie_node_t **children, const char value);
int trie_add_word (trie_node_t *trie, const char* word);
