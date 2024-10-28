#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Node for Chaining (Linked List)
typedef struct Node {
    char* key;
    char* value;
    struct Node* next;
} Node;

#define TABLE_SIZE 100

// Hash Table (Array of Linked List)
Node* hashTable[TABLE_SIZE];

// Simple hash function
unsigned int hash(char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;  // Simple shift and add algorithm
    }
    return hash % TABLE_SIZE;
}

void insert(char* key, char* value) {
    unsigned int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->key = (char*)malloc(strlen(key) + 1);   
    newNode->value = (char*)malloc(strlen(value) + 1); 

    strcpy(newNode->key, key);  
    strcpy(newNode->value, value);  

    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search function
char* search(char* key) {
    unsigned int index = hash(key);
    Node* node = hashTable[index];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;  // Key found
        }
        node = node->next;  // Move to the next node in the chain
    }
    return NULL;  // Key not found
}

int main() {
    // Initialize the hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert data into hash table
    insert("Pikachu", "Electric");
    insert("Charmander", "Fire");
    insert("Caterpie", "a");
    insert("Pidgey", "b");
    insert("Venusaur", "c");
    insert("Butterfree", "d");

    // Search in hash table
    char* result = search("Venusaur");
    if (result) {
        printf("type: %s\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}