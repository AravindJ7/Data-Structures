#include <stdio.h>
#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key using quadratic probing
void insert(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (hashTable[newIndex] == EMPTY) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }
    printf("Hash table is full. Cannot insert %d\n", key);
}

// Search for a key using quadratic probing
int search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (hashTable[newIndex] == EMPTY) {
            return -1; // Not found
        }
        if (hashTable[newIndex] == key) {
            return newIndex; // Found
        }
        i++;
    }
    return -1; // Not found
}

// Delete a key (mark it as EMPTY again)
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

    // Test the table
    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);

    display();

    printf("Search 25: %s\n", search(25) != -1 ? "Found" : "Not Found");
    printf("Search 15: %s\n", search(15) != -1 ? "Found" : "Not Found");

    delete(30);
    display();

    return 0;
}
