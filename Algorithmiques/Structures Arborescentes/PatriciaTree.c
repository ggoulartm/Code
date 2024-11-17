#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the node structure
typedef struct node_radix {
    char* value;                   // String (substring)
    struct node_radix* sons;       // Pointer to the first child
    struct node_radix* brothers;   // Pointer to the next sibling
} *radix_t;

// Function to create a new node
radix_t create_radix_node(const char* value) {
    radix_t node = (radix_t)malloc(sizeof(struct node_radix));
    node->value = strdup(value); // Copy the string
    node->sons = NULL;
    node->brothers = NULL;
    return node;
}

// Function to add a word to the Patricia Tree
void add_word(radix_t* root, const char* word) {
    if (*root == NULL) {
        *root = create_radix_node(word); // Create root if tree is empty
        return;
    }

    radix_t current = *root;
    while (current != NULL) {
        // Find the longest common prefix between `current->value` and `word`
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
                return;
            }
            current = current->brothers;
        } else if (common_len < strlen(current->value)) {
            // Partial match, split the node
            radix_t new_son = create_radix_node(current->value + common_len);
            new_son->sons = current->sons; // Move existing children to new node
            current->value[common_len] = '\0'; // Truncate current node's value
            current->sons = new_son;

            if (common_len < strlen(word)) {
                // Add remaining part of the word as a new child
                new_son->brothers = create_radix_node(word + common_len);
            }
            return;
        } else {
            // Full match, proceed to sons with the remaining part of the word
            word += common_len;
            if (*word == '\0') {
                return; // Word already exists
            }
            if (current->sons == NULL) {
                current->sons = create_radix_node(word);
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
                return true; // Word found
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

    if (root->sons == NULL) {
        buffer[level] = '\0';
        printf("%s\n", buffer);
    } else {
        display_trie(root->sons, buffer, level);
    }

    display_trie(root->brothers, buffer, level - strlen(root->value));
}

// Free the Patricia Tree memory
void free_trie(radix_t root) {
    if (root == NULL) return;

    free_trie(root->sons);
    free_trie(root->brothers);
    free(root->value);
    free(root);
}

// Main function for testing
int main() {
    radix_t root = NULL; // Initialize the root node
    char buffer[100];

    // Add words to the Patricia Tree
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

    // Display the Patricia Tree
    printf("Words in the Patricia Tree:\n");
    display_trie(root, buffer, 0);

    // Search for words
    printf("\nSearching for words:\n");
    printf("ame: %s\n", search_word(root, "ame") ? "Found" : "Not Found");
    printf("vas: %s\n", search_word(root, "vas") ? "Found" : "Not Found");
    printf("hello: %s\n", search_word(root, "hello") ? "Found" : "Not Found");

    // Free memory
    free_trie(root);

    return 0;
}
