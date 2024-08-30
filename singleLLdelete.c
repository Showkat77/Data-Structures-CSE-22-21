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

// Function to delete the first occurrence of a node with a given value
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next;  // Change head
        free(temp);  // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the list
    if (temp == NULL) return;

    // Unlink the node from the linked list
    prev->next = temp->next;

    // Free memory
    free(temp);
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

// Main function to demonstrate deletion in a singly linked list
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

    // Delete node with value 3
    deleteNode(&head, 3);
    printf("List after deleting node with value 3: ");
    printList(head);

    // Delete node with value 1 (head node)
    deleteNode(&head, 1);
    printf("List after deleting head node (value 1): ");
    printList(head);

    // Delete node with value 5 (tail node)
    deleteNode(&head, 5);
    printf("List after deleting tail node (value 5): ");
    printList(head);

    return 0;
}
