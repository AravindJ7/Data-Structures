#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hash table: array of pointers to nodes
Node* hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert value into hash table
void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("Inserted %d at index %d\n", key, index);
}

// Search for a value in the hash table
int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Delete a value from the hash table
void delete(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key %d not found\n", key);
        return;
    }

    if (prev == NULL) {
        hashTable[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Deleted %d from index %d\n", key, index);
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function to test
int main() {
    // Initialize table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert(10);
    insert(20);
    insert(15);
    insert(7);
    insert(37);

    display();

    printf("Search 15: %s\n", search(15) ? "Found" : "Not Found");
    printf("Search 5: %s\n", search(5) ? "Found" : "Not Found");

    delete(15);
    delete(99);

    display();

    return 0;
}
