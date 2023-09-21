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

// Function to insert a new node at a given position
void insertNodeAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position < 1) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }
    
    if (position == 1) {
        // Insert at the beginning
        newNode->next = *head;
        *head = newNode;
    } else {
        // Traverse to the node just before the position
        struct Node* prevNode = *head;
        for (int i = 1; i < position - 1 && prevNode != NULL; i++) {
            prevNode = prevNode->next;
        }
        
        if (prevNode == NULL) {
            printf("Invalid position.\n");
            free(newNode);
            return;
        }
        
        // Insert the new node after prevNode
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
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

    // Insert nodes at different positions
    insertNodeAtPosition(&head, 1, 1); // 1 -> NULL
    insertNodeAtPosition(&head, 2, 2); // 1 -> 2 -> NULL
    insertNodeAtPosition(&head, 3, 2); // 1 -> 3 -> 2 -> NULL
    insertNodeAtPosition(&head, 4, 4); // 1 -> 3 -> 2 -> 4 -> NULL

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Free memory allocated for the linked list
    freeList(head);

    return 0;
}
