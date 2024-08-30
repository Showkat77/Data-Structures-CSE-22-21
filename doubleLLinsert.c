#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(Node** head, Node** tail, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) { // If the list is empty
        *head = *tail = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node** head, Node** tail, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) { // If the list is empty
        *head = *tail = newNode;
    } else {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Function to insert a node at a specific position in the doubly linked list
void insertAtPosition(Node** head, Node** tail, int data, int position) {
    if (position <= 0) {
        printf("Position must be greater than 0.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, tail, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* current = *head;

    for (int i = 1; i < position - 1; i++) {
        if (current == NULL) {
            printf("Position out of bounds.\n");
            free(newNode);
            return;
        }
        current = current->next;
    }

    if (current == NULL || current->next == NULL) { // Insert at end if position is beyond list length
        insertAtEnd(head, tail, data);
    } else {
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to demonstrate insertion in a doubly linked list
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Insert elements at the beginning
    insertAtBeginning(&head, &tail, 3);
    insertAtBeginning(&head, &tail, 2);
    insertAtBeginning(&head, &tail, 1);

    printf("List after inserting at the beginning: ");
    printList(head);

    // Insert elements at the end
    insertAtEnd(&head, &tail, 4);
    insertAtEnd(&head, &tail, 5);

    printf("List after inserting at the end: ");
    printList(head);

    // Insert element at position 3
    insertAtPosition(&head, &tail, 10, 3);

    printf("List after inserting 10 at position 3: ");
    printList(head);

    return 0;
}
