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

// Function to reverse the circular linked list
void reverseList(Node** head) {
    if (*head == NULL || (*head)->next == *head) return;  // If list is empty or has only one node

    Node *prev = NULL, *current = *head, *next = NULL;
    Node *last = *head;

    do {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    } while (current != *head);

    // Fix the last node's next pointer to the new head
    last->next = prev;
    *head = prev;  // Update head to the new first node
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

// Main function to demonstrate reversing a circular singly linked list
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

    // Reverse the list
    reverseList(&head);
    printf("Reversed Circular Linked List: ");
    printList(head);

    return 0;
}
