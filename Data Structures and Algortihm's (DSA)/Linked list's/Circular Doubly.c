#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }
    struct Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    head->prev = last->next = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }
    struct Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = head->prev = newNode;
}

// Insert at position
void insertAtPosition(int data, int pos) {
    if (pos <= 1 || head == NULL) {
        insertFront(data);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) {
        insertEnd(data);
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
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
    struct Node* last = head->prev;
    struct Node* temp = head;

    head = head->next;
    head->prev = last;
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
    struct Node* last = head->prev;
    struct Node* secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;
    free(last);
}

// Delete at position
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
    for (int i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;

    if (temp == head) {
        printf("Position out of range\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
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

    struct Node* current = head;
    struct Node* temp = NULL;

    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // previously next
    } while (current != head);

    head = head->prev; // update head to new first node
}

// Display forward
void displayForward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Display backward
void displayBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* last = head->prev;
    struct Node* temp = last;
    printf("Backward: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("(head)\n");
}

// Main function
int main() {
    insertEnd(10);
    insertFront(5);
    insertEnd(20);
    insertAtPosition(15, 3);

    displayForward();   // 5 <-> 10 <-> 15 <-> 20
    displayBackward();  // 20 <-> 15 <-> 10 <-> 5

    deleteFront();
    displayForward();   // 10 <-> 15 <-> 20

    deleteEnd();
    displayForward();   // 10 <-> 15

    deleteAtPosition(2);
    displayForward();   // 10

    insertEnd(25);
    insertEnd(35);
    displayForward();   // 10 <-> 25 <-> 35

    search(25);         // Found
    search(100);        // Not found

    reverse();
    displayForward();   // 35 <-> 25 <-> 10

    return 0;
}
