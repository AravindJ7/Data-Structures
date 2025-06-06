#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Insert at position
void insertAtPosition(int data, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertFront(data);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head && pos != 2) {
        printf("Position out of range\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from front
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    struct Node* last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    struct Node* del = temp->next;
    temp->next = head;
    free(del);
}

// Delete from position
void deleteAtPosition(int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid operation\n");
        return;
    }

    if (pos == 1) {
        deleteFront();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) {
        printf("Position out of range\n");
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

// Search
void search(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Not found\n");
}

// Reverse the list
void reverse() {
    if (head == NULL || head->next == head)
        return;

    struct Node *prev = NULL, *curr = head, *next = NULL, *last = head;

    do {
        last = last->next;
    } while (last->next != head);

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->next = prev;
    head = prev;
}

// Display
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function
int main() {
    insertEnd(10);
    insertFront(5);
    insertEnd(20);
    insertAtPosition(15, 3); // 5 -> 10 -> 15 -> 20

    display();

    deleteFront();
    display();

    deleteEnd();
    display();

    deleteAtPosition(2);
    display();

    insertEnd(30);
    insertEnd(40);
    display();

    search(30); // Found
    search(100); // Not found

    reverse();
    display();

    return 0;
}
