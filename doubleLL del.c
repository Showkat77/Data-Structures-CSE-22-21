#include <stdio.h>

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

// Function to delete a specific node from the doubly linked list
void deleteNode(Node** head, Node** tail, Node* delNode) {
    if (*head == NULL || delNode == NULL) return;

    // If the node to be deleted is the head node
    if (*head == delNode) {
        *head = delNode->next;
    }

    // If the node to be deleted is the tail node
    if (*tail == delNode) {
        *tail = delNode->prev;
    }

    // Update the next and previous pointers of the adjacent nodes
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }

    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }

    // Free the memory of the deleted node
    free(delNode);
}

// Function to delete all nodes with a given value from the doubly linked list
void deleteAllInstances(Node** head, Node** tail, int value) {
    Node* current = *head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next; // Store the next node

        if (current->data == value) {
            deleteNode(head, tail, current); // Delete the current node if it matches the value
        }

        current = nextNode; // Move to the next node
    }
}

// Function to append a new node at the end of the list
void append(Node** head, Node** tail, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) { // If the list is empty, set head and tail to the new node
        *head = *tail = newNode;
        return;
    }

    // Link the new node with the current tail and update the tail
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
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

// Main function to demonstrate deletion of all instances of a value
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Append some nodes to the list
    append(&head, &tail, 1);
    append(&head, &tail, 2);
    append(&head, &tail, 3);
    append(&head, &tail, 2);
    append(&head, &tail, 4);
    append(&head, &tail, 2);

    printf("Original list: ");
    printList(head);

    // Delete all instances of the value 2
    deleteAllInstances(&head, &tail, 2);
    printf("After deleting all instances of 2: ");
    printList(head);

    return 0;
}
