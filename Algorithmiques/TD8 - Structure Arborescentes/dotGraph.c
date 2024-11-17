#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PatriciaTreeSharedSuffixes.h"

// Function to export a node and its connections to the .dot file
void export_tree_to_dot(FILE* file, radix_t node) {
    if (!node) return;

    // Write the current node to the file
    fprintf(file, "  \"%s\" [label=\"%s\"];\n", node->value, node->value);

    // If the node has a son, write the edge and recurse
    if (node->sons) {
        fprintf(file, "  \"%s\" -> \"%s\" [color=black];\n", node->value, node->sons->value);
        export_tree_to_dot(file, node->sons);
    }

    // If the node has a brother, write the edge and recurse
    if (node->brothers) {
        fprintf(file, "  \"%s\" -> \"%s\" [color=blue, style=dotted];\n", node->value, node->brothers->value);
        export_tree_to_dot(file, node->brothers);
    }
}

// Wrapper function to export the entire tree
void save_tree_as_dot(radix_t root, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Write the Graphviz digraph header
    fprintf(file, "digraph PatriciaTree {\n");
    fprintf(file, "  node [shape=circle];\n");

    // Export the tree starting from the root
    export_tree_to_dot(file, root);

    // Close the Graphviz digraph
    fprintf(file, "}\n");
    fclose(file);
}

// Function to generate the graph image using Graphviz
void generate_graph_image(const char* dot_file, const char* output_file) {
    char command[256];
    snprintf(command, sizeof(command), "dot -Tpng %s -o %s", dot_file, output_file);
    int result = system(command); // Execute the system command
    if (result != 0) {
        fprintf(stderr, "Failed to generate graph image.\n");
    } else {
        printf("Graph image saved to %s\n", output_file);
    }
}


