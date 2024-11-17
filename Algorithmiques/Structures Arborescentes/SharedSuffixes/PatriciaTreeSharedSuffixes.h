#ifndef PATRICIATREESHAREDSUFFIXES_H
#define PATRICIATREESHAREDSUFFIXES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the structure for a Patricia Tree node
typedef struct node_radix {
    char* value;                   // String (substring)
    struct node_radix* sons;       // Pointer to the first child
    struct node_radix* brothers;   // Pointer to the next sibling
    int visited; // New: To track visited nodes
} *radix_t;


// Function prototypes
radix_t create_radix_node(const char* value);
void initialize_end_of_word_node();
void add_word(radix_t* root, const char* word);
bool search_word(radix_t root, const char* word);
void display_trie(radix_t root, char* buffer, int level);
void free_trie(radix_t root);
void Display(radix_t root);

#endif // PATRICIATREESHAREDSUFFIXES_H