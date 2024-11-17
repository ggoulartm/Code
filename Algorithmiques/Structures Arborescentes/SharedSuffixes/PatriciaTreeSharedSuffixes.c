#include "PatriciaTreeSharedSuffixes.h"

// Global node for the shared `\0` (end-of-word) marker
radix_t end_of_word_node = NULL;

// Function to create a new node
radix_t create_radix_node(const char* value) {
    radix_t node = (radix_t)malloc(sizeof(struct node_radix));
    if (!node) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE);
    }
    node->value = strdup(value);  // Allocate and copy the value
    node->sons = NULL;
    node->brothers = NULL;
    return node;
}

// Initialize the shared end-of-word node
void initialize_end_of_word_node() {
    if (end_of_word_node == NULL) {
        end_of_word_node = create_radix_node("\0");
    }
}


// Function to add a word to the Patricia Tree
void add_word(radix_t* root, const char* word) {
    if (*root == NULL) {
        *root = create_radix_node(word); // Create the root node
        initialize_end_of_word_node();
        (*root)->sons = end_of_word_node; // Attach the end-of-word marker
        return;
    }

    radix_t current = *root;
    while (current != NULL) {
        // Find the longest common prefix
        size_t common_len = 0;
        while (common_len < strlen(current->value) &&
               common_len < strlen(word) &&
               current->value[common_len] == word[common_len]) {
            common_len++;
        }

        if (common_len == 0) {
            // No common prefix, move to brothers
            if (current->brothers == NULL) {
                current->brothers = create_radix_node(word);
                initialize_end_of_word_node();
                current->brothers->sons = end_of_word_node;
                return;
            }
            current = current->brothers;
        } else if (common_len < strlen(current->value)) {
            // Partial match, split the node
            radix_t new_son = create_radix_node(current->value + common_len);
            new_son->sons = current->sons; // Move existing children to the new node
            current->value[common_len] = '\0'; // Truncate the current node's value
            current->sons = new_son;

            if (common_len < strlen(word)) {
                // Add the remaining part of the word as a new child
                new_son->brothers = create_radix_node(word + common_len);
                initialize_end_of_word_node();
                new_son->brothers->sons = end_of_word_node;
            } else {
                // Attach the end-of-word marker
                new_son->brothers = end_of_word_node;
            }
            return;
        } else {
            // Full match, proceed to sons with the remaining part of the word
            word += common_len;
            if (*word == '\0') {
                return; // The word already exists
            }
            if (current->sons == NULL) {
                current->sons = create_radix_node(word);
                initialize_end_of_word_node();
                current->sons->sons = end_of_word_node;
                return;
            }
            current = current->sons;
        }
    }
}


// Function to search for a word in the Patricia Tree
bool search_word(radix_t root, const char* word) {
    radix_t current = root;
    while (current != NULL) {
        // Compare the word with the current node's value
        size_t len = strlen(current->value);
        if (strncmp(current->value, word, len) == 0) {
            word += len;
            if (*word == '\0') {
                // Check if the shared `\0` node is present
                return current->sons == end_of_word_node;
            }
            current = current->sons; // Continue to next level
        } else {
            current = current->brothers; // Check next sibling
        }
    }
    return false; // Word not found
}

// Function to display the Patricia Tree
void display_trie(radix_t root, char* buffer, int level) {
    if (root == NULL) return;

    strcpy(buffer + level, root->value);
    level += strlen(root->value);

    if (root->sons == end_of_word_node) {
        buffer[level] = '\0';
        printf("%s\n", buffer);
    } else {
        display_trie(root->sons, buffer, level);
    }

    display_trie(root->brothers, buffer, level - strlen(root->value));
}

// Function to display the Patricia Tree
void Display(radix_t root) {
    if (root == NULL) return;

    char buffer[200];
    int level = 0;
    strcpy(buffer + level, root->value);
    level += strlen(root->value);

    if (root->sons == end_of_word_node) {
        buffer[level] = '\0';
        printf("%s\n", buffer);
    } else {
        display_trie(root->sons, buffer, level);
    }

    display_trie(root->brothers, buffer, level - strlen(root->value));
}


// Free the Patricia Tree memory
void free_trie(radix_t root) {
    if (root == NULL || root == end_of_word_node) return;

    free_trie(root->sons);
    free_trie(root->brothers);
    free(root->value);
    free(root);
}