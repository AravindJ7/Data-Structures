#include <stdio.h>
#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Function to find the nearest smaller prime less than TABLE_SIZE
int getSmallerPrime(int n) {
    for (int i = n - 1; i >= 2; i--) {
        if (isPrime(i)) return i;
    }
    return 2; // Default fallback
}

// First hash function
int hash1(int key) {
    return key % TABLE_SIZE;
}

// Second hash function (step size), calculated using dynamic prime
int hash2(int key, int prime) {
    return prime - (key % prime);
}

// Insert a key using double hashing
void insert(int key, int prime) {
    int index1 = hash1(key);
    int index2 = hash2(key, prime);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index1 + i * index2) % TABLE_SIZE;
        if (hashTable[newIndex] == EMPTY) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
        i++;
    }

    printf("Hash table is full. Cannot insert %d\n", key);
}

// Search for a key
int search(int key, int prime) {
    int index1 = hash1(key);
    int index2 = hash2(key, prime);
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index1 + i * index2) % TABLE_SIZE;
        if (hashTable[newIndex] == EMPTY) return -1;
        if (hashTable[newIndex] == key) return newIndex;
        i++;
    }

    return -1;
}

// Delete a key
void delete(int key, int prime) {
    int index = search(key, prime);
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
    // Initialize table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }

    // Dynamically calculate prime for hash2
    int prime = getSmallerPrime(TABLE_SIZE);
    printf("Using prime = %d for second hash\n\n", prime);

    // Test insertions
    insert(10, prime);
    insert(20, prime);
    insert(30, prime);
    insert(23, prime);
    insert(44, prime);
    insert(32, prime);
    insert(12, prime);

    display();

    printf("\nSearch 44: %s\n", search(44, prime) != -1 ? "Found" : "Not Found");
    printf("Search 99: %s\n", search(99, prime) != -1 ? "Found" : "Not Found");

    printf("\n");
    delete(30, prime);
    display();

    return 0;
}
