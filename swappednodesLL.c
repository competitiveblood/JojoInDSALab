#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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

// Function to swap two nodes in a linked list
struct Node* swapNodes(struct Node* head, int x, int y) {
    if (x == y) {
        return head; // No need to swap if x and y are the same
    }

    // Initialize pointers to track the nodes to be swapped and their previous nodes
    struct Node* prevX = NULL;
    struct Node* prevY = NULL;
    struct Node* currX = head;
    struct Node* currY = head;

    // Find the nodes x and y and their previous nodes
    while (currX != NULL && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    while (currY != NULL && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not present in the list, return the original list
    if (currX == NULL || currY == NULL) {
        return head;
    }

    // If x is not the head of the list, update the next of the previous node of x
    if (prevX != NULL) {
        prevX->next = currY;
    } else {
        head = currY; // If x is the head, update the head to y
    }

    // If y is not the head of the list, update the next of the previous node of y
    if (prevY != NULL) {
        prevY->next = currX;
    } else {
        head = currX; // If y is the head, update the head to x
    }

    // Swap the next pointers of x and y nodes
    struct Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original Linked List: ");
    printList(head);

    int x = 2;
    int y = 4;

    head = swapNodes(head, x, y);

    printf("Linked List after swapping %d and %d: ", x, y);
    printList(head);

    return 0;
}
