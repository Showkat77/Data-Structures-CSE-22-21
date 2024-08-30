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

// Function to reverse the singly linked list
void reverseList(Node** head) {
    Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    *head = prev;  // Update head to the new first node
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

// Main function to demonstrate reversing a singly linked list
int main() {
    Node* head = NULL;

    // Insert elements at the end of the list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original list: ");
    printList(head);

    // Reverse the list
    reverseList(&head);
    printf("Reversed list: ");
    printList(head);

    return 0;
}
