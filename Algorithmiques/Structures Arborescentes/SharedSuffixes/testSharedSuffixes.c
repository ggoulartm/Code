#include "dotGraph.h"

void debug_tree(radix_t node, int level) {
    if (!node) return;

    for (int i = 0; i < level; i++) printf("  "); // Indent based on depth
    printf("%s\n", node->value);

    // Recursively debug sons and brothers
    if (node->sons) debug_tree(node->sons, level + 1);
    if (node->brothers) debug_tree(node->brothers, level);
}


void reset_visited_flag(radix_t node) {
    if (!node) return;
    node->visited = 0;
    reset_visited_flag(node->sons);
    reset_visited_flag(node->brothers);
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
