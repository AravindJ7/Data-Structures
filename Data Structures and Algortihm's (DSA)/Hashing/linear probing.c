#include <stdio.h>
#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key using linear probing
void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    while (hashTable[index] != EMPTY && i < TABLE_SIZE) {
        index = (originalIndex + ++i) % TABLE_SIZE;
    }

    if (i == TABLE_SIZE) {
        printf("Hash table is full. Cannot insert %d\n", key);
    } else {
        hashTable[index] = key;
        printf("Inserted %d at index %d\n", key, index);
    }
}

// Search for a key
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 0;

    while (hashTable[index] != EMPTY && i < TABLE_SIZE) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (originalIndex + ++i) % TABLE_SIZE;
    }
    return -1; // Not found
}

// Delete a key (mark it as deleted using a special marker)
void delete(int key) {
    int index = search(key);
    if (index == -1) {
        printf("Key %d not found\n", key);
    } else {
        hashTable[index] = EMPTY;
        printf("Deleted %d from index %d\n", key, index);
    }
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != EMPTY)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }

    // Test
    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);

    display();

    printf("Search 25: %s\n", search(25) != -1 ? "Found" : "Not Found");
    printf("Search 15: %s\n", search(15) != -1 ? "Found" : "Not Found");

    delete(20);
    display();

    return 0;
}
