
#include "dotGraph.h"

// Function to export a node and its connections to the .dot file
void export_tree_to_dot(FILE* file, radix_t node) {
    if (node==NULL || *node->value == '\0') return;

    // Write the current node
    fprintf(file, "  \"%s\" [label=\"%s\"];\n", node->value, node->value);

    // Recursively export sons and brothers
    if (node->sons) {
        fprintf(file, "  \"%s\" -> \"%s\" [color=black];\n", node->value, node->sons->value);
        export_tree_to_dot(file, node->sons);
    }
    if (node->brothers) {
        fprintf(file, "  \"%s\" -> \"%s\" [color=blue, style=dotted];\n", node->value, node->brothers->value);
        export_tree_to_dot(file, node->brothers);
    }
}

// Function to save the Patricia Tree as a .dot file
void save_tree_as_dot(radix_t root, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "digraph PatriciaTree {\n");
    fprintf(file, "  node [shape=circle];\n");
    export_tree_to_dot(file, root);
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

