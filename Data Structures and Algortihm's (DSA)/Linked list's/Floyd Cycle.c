#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a cycle using Floyd’s algorithm
int detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;          // move by 1
        fast = fast->next->next;    // move by 2

        if (slow == fast) {
            return 1;  // Cycle detected
        }
    }

    return 0;  // No cycle
}

// Utility to create a loop in the linked list
void createCycle(struct Node* head, int pos) {
    struct Node *temp = head, *joinNode = NULL;
    int count = 0;
    while (temp->next != NULL) {
        if (count == pos)
            joinNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = joinNode;  // Create cycle
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Create cycle at position 2 (node with value 3)
    createCycle(head, 2);

    if (detectCycle(head)) {
        printf("Cycle detected in the linked list\n");
    } else {
        printf("No cycle in the linked list\n");
    }

    return 0;
}
