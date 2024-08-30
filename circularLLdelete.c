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

// Function to delete a node with a given value in a circular linked list
void deleteNode(Node** head, int key) {
    if (*head == NULL) return;  // If the list is empty, nothing to delete

    Node *temp = *head, *prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp->data == key) {
        if (temp->next == *head) {  // If the list has only one node
            free(temp);
            *head = NULL;
            return;
        }

        // Find the last node to update its next pointer
        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = (*head)->next;  // Point last node to the next node after head
        free(*head);  // Delete the head node
        *head = temp->next;  // Update head
        return;
    }

    // Otherwise, search for the node to be deleted
    prev = *head;
    temp = (*head)->next;
    while (temp != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the node with the key is found
    if (temp->data == key) {
        prev->next = temp->next;  // Unlink the node from the list
        free(temp);  // Free memory
    }
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

// Main function to demonstrate deletion in a circular singly linked list
int main() {
    Node* head = NULL;

    // Insert elements at the end of the list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original Circular Linked List: ");
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
    printf("List after deleting node with value 5: ");
    printList(head);

    return 0;
}
