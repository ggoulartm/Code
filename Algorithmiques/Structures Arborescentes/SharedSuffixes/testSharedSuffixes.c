#include "dotGraph.h"
#include <unistd.h> // For sleep()

void debug_tree(radix_t node, int level) {
    if (node==NULL || *node->value == '\0') return;

    for (int i = 0; i < level; i++) printf("  "); // Indent based on depth
    printf("%s\n", node->value);

    //sleep(1); // Sleep for 1 second to see the tree building step by step
    // Recursively debug sons and brothers
    if (node->sons) debug_tree(node->sons, level + 1);
    if (node->brothers) debug_tree(node->brothers, level);
}

int main() {
    // Create and populate the Patricia tree
    radix_t root = NULL;
    add_word(&root, "ame");
    add_word(&root, "amour");
    add_word(&root, "aimer");
    add_word(&root, "as");
    add_word(&root, "ca");
    add_word(&root, "ce");
    add_word(&root, "ces");
    add_word(&root, "va");
    add_word(&root, "vais");
    add_word(&root, "vas");
    add_word(&root, "vont");
    add_word(&root, "parler");
    add_word(&root, "partir");
    add_word(&root, "parfait");
    add_word(&root, "parfois");
    add_word(&root, "parle");
    add_word(&root, "cat");
    add_word(&root, "dog");
    add_word(&root, "fish");
    add_word(&root, "bird");
    add_word(&root, "apple");
    add_word(&root, "banana");
    add_word(&root, "grape");
    add_word(&root, "cherry");
    add_word(&root, "date");
    add_word(&root, "elderberry");
    add_word(&root, "abc");
    add_word(&root, "abcd");
    add_word(&root, "abcdef");
    add_word(&root, "a");
    add_word(&root, "repeat");
    add_word(&root, "repeat");
    add_word(&root, "repeat");
    add_word(&root, "rain");
    add_word(&root, "rainbow");
    add_word(&root, "raincoat");
    add_word(&root, "raindrop");
    add_word(&root, "rainstorm");
    add_word(&root, "rainy");
    add_word(&root, "rainfall");
    add_word(&root, "rainforest");
    add_word(&root, "sun");
    add_word(&root, "sunlight");
    add_word(&root, "sunset");
    add_word(&root, "sunrise");
    add_word(&root, "sunshine");
    add_word(&root, "racecar");
    add_word(&root, "rotor");;
    add_word(&root, "radar");
    add_word(&root, "refer");
    add_word(&root, "word1");
    add_word(&root, "word2");
    add_word(&root, "word10");
    add_word(&root, "word20");
    add_word(&root, "word100");
    add_word(&root, "word200");


    // Call this function after building the tree to verify:
    debug_tree(root, 0);
    Display(root);

    // Export the tree to a .dot file
    const char* dot_file = "tree.dot";
    save_tree_as_dot(root, dot_file);

    // Generate a graph image from the .dot file
    const char* output_file = "tree.png";
    generate_graph_image(dot_file, output_file);

    // Clean up
    free_trie(root);
    return 0;
}
