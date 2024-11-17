#ifndef DOTGRAPH_H
#define DOTGRAPH_H

#include "PatriciaTreeSharedSuffixes.h"


void export_tree_to_dot(FILE* file, radix_t node);
void save_tree_as_dot(radix_t root, const char* filename);
void generate_graph_image(const char* dot_file, const char* output_file);

#endif // DOTGRAPH_H