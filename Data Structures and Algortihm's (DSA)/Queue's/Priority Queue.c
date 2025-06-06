#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

// Create new node
struct Node* createNode(int data, int priority) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Insert by priority (smaller number = higher priority)
void insert(int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    // If empty or new node has highest priority
    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority <= priority)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d with priority %d\n", data, priority);
}

// Delete highest priority element
void delete() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Deleted %d with priority %d\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

// Peek highest priority
void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Peek: %d with priority %d\n", front->data, front->priority);
    }
}

// Display the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Priority Queue: ");
    while (temp != NULL) {
        printf("(%d, p:%d) -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test
int main() {
    insert(10, 2);
    insert(5, 1);
    insert(20, 3);
    insert(15, 2);

    display(); // should be 5 -> 10 -> 15 -> 20

    peek();    // highest priority

    delete();  // remove 5
    display();

    return 0;
}
