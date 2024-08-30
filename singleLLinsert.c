#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
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

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;  // New node points to the current head
    *head = newNode;        // Update head to the new node
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;  // If the list is empty, set head to the new node
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {  // Traverse to the end of the list
        temp = temp->next;
    }
    temp->next = newNode;  // Link the last node to the new node
}

// Function to insert a new node after a given node
void insertAfterNode(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = prevNode->next;  // New node points to the next node
    prevNode->next = newNode;        // Previous node points to the new node
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate insertion in a singly linked list
int main() {
    Node* head = NULL;

    // Insert elements at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("List after inserting at the beginning: ");
    printList(head);

    // Insert elements at the end
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("List after inserting at the end: ");
    printList(head);

    // Insert element after the second node (with data 2)
    insertAfterNode(head->next, 10);

    printf("List after inserting 10 after the second node: ");
    printList(head);

    return 0;
}
