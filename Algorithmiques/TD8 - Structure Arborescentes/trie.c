#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the node structure
typedef struct _node {
    char data;             // Character stored in the node
    struct _link* sons;    // List of child nodes
} Node;

// Define the link structure
typedef struct _link {
    Node* data;            // Pointer to the child node
    struct _link* next;    // Pointer to the next link in the list
} Link;

// Function to create a new node
Node* create_node(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->sons = NULL;
    return new_node;
}

// Function to create a new link
Link* create_link(Node* data) {
    Link* new_link = (Link*)malloc(sizeof(Link));
    new_link->data = data;
    new_link->next = NULL;
    return new_link;
}

// Add a word to the trie
void add_word(Node* root, const char* word) {
    Node* current = root;
    for (size_t i = 0; i < strlen(word); i++) {
        char c = word[i];
        Link* prev = NULL;
        Link* current_son = current->sons;

        // Search for the character in the current level
        while (current_son != NULL && current_son->data->data < c) {
            prev = current_son;
            current_son = current_son->next;
        }

        if (current_son == NULL || current_son->data->data != c) {
            // Character not found, insert a new node
            Node* new_node = create_node(c);
            Link* new_link = create_link(new_node);

            if (prev == NULL) {
                // Insert at the beginning
                new_link->next = current->sons;
                current->sons = new_link;
            } else {
                // Insert in the middle or end
                new_link->next = prev->next;
                prev->next = new_link;
            }

            current_son = new_link;
        }

        // Move to the next level
        current = current_son->data;
    }

    // Add the special end-of-word character
    Link* end_link = create_link(create_node('\0'));
    end_link->next = current->sons;
    current->sons = end_link;
}

// Search for a word in the trie
bool search_word(Node* root, const char* word) {
    Node* current = root;
    for (size_t i = 0; i < strlen(word); i++) {
        char c = word[i];
        Link* current_son = current->sons;

        // Search for the character
        while (current_son != NULL && current_son->data->data != c) {
            current_son = current_son->next;
        }

        if (current_son == NULL) {
            return false; // Character not found
        }

        current = current_son->data;
    }

    // Check for end-of-word
    Link* current_son = current->sons;
    while (current_son != NULL && current_son->data->data != '\0') {
        current_son = current_son->next;
    }
    return current_son != NULL;
}

// Display the trie (for debugging)
void display_trie(Node* root, char* prefix, int level) {
    if (root == NULL) {
        return;
    }

    if (root->data == '\0') {
        prefix[level] = '\0';
        printf("%s\n", prefix);
        return;
    }

    prefix[level] = root->data;
    Link* current_son = root->sons;
    while (current_son != NULL) {
        display_trie(current_son->data, prefix, level + 1);
        current_son = current_son->next;
    }
}

// Free the trie memory
void free_trie(Node* root) {
    if (root == NULL) {
        return;
    }

    Link* current_son = root->sons;
    while (current_son != NULL) {
        Link* next = current_son->next;
        free_trie(current_son->data);
        free(current_son);
        current_son = next;
    }
    free(root);
}

// Main function for testing
int main() {
    Node* root = create_node(2); // Root node
    char buffer[100];

    // Add words to the trie
    add_word(root, "ame");
    add_word(root, "amour");
    add_word(root, "aimer");
    add_word(root, "as");
    add_word(root, "ca");
    add_word(root, "ce");
    add_word(root, "ces");
    add_word(root, "va");
    add_word(root, "vais");
    add_word(root, "vas");
    add_word(root, "vont");

    // Display the trie
    printf("Words in the trie:\n");
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
