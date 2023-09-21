#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertNodeAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete a node at a given position
void deleteNodeAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        // Delete the first node
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node* current = *head;
    struct Node* prevNode = NULL;
    int currentPosition = 1;

    while (current != NULL && currentPosition != position) {
        prevNode = current;
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position not found.\n");
        return;
    }

    // Delete the node at the specified position
    prevNode->next = current->next;
    free(current);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the end of the list
    insertNodeAtEnd(&head, 1);
    insertNodeAtEnd(&head, 2);
    insertNodeAtEnd(&head, 3);
    insertNodeAtEnd(&head, 4);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Delete a node at a specific position
    int positionToDelete = 3;
    deleteNodeAtPosition(&head, positionToDelete);

    // Print the updated linked list
    printf("Linked List after deleting position %d: ", positionToDelete);
    printList(head);

    // Free memory allocated for the linked list
    freeList(head);

    return 0;
}
