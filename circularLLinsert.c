#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular singly linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the circular list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Point the new node to itself
        return;
    }

    Node* temp = *head;
    while (temp->next != *head) {  // Traverse to the last node
        temp = temp->next;
    }

    temp->next = newNode;  // Link the last node to the new node
    newNode->next = *head; // Link the new node back to the head
}

// Function to insert a new node at the beginning of the circular list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Point the new node to itself
        return;
    }

    Node* temp = *head;
    while (temp->next != *head) {  // Traverse to the last node
        temp = temp->next;
    }

    newNode->next = *head;  // New node points to the current head
    temp->next = newNode;    // Last node points to the new node
    *head = newNode;         // Update head to the new node
}

// Function to print the circular linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Continue until we reach the head again
    printf("(back to head)\n");
}

// Main function to demonstrate insertion in a circular singly linked list
int main() {
    Node* head = NULL;

    // Insert elements at the end of the list
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 6);

    printf("Circular Linked List after inserting at the end: ");
    printList(head);

    // Insert elements at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 0);

    printf("Circular Linked List after inserting at the beginning: ");
    printList(head);

    return 0;
}
