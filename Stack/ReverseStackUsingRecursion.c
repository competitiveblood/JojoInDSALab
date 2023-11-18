#include <stdio.h>
#include <stdlib.h>

// Structure of a stack node
struct sNode {
    int data;
    struct sNode* next;
};

// Function Prototypes
void push(struct sNode** top_ref, int new_data);
int pop(struct sNode** top_ref);
int isEmpty(struct sNode* top);
void insertAtBottom(struct sNode** top_ref, int item);
void reverse(struct sNode** top_ref);

// Function to push an item to stack
void push(struct sNode** top_ref, int new_data) {
    struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));

    if (new_node == NULL) {
        printf("Stack overflow\n");
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

// Function to pop an item from stack
int pop(struct sNode** top_ref) {
    int res;
    struct sNode* top;

    if (*top_ref == NULL) {
        printf("Stack underflow\n");
        exit(0);
    } else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

// Function to check if the stack is empty
int isEmpty(struct sNode* top) {
    return (top == NULL) ? 1 : 0;
}

// Function to insert an element at the bottom of a stack
void insertAtBottom(struct sNode** top_ref, int item) {
    if (isEmpty(*top_ref))
        push(top_ref, item);
    else {
        int temp = pop(top_ref);
        insertAtBottom(top_ref, item);
        push(top_ref, temp);
    }
}

// Function to reverse the given stack using insertAtBottom()
void reverse(struct sNode** top_ref) {
    if (!isEmpty(*top_ref)) {
        int temp = pop(top_ref);
        reverse(top_ref);
        insertAtBottom(top_ref, temp);
    }
}

// Function to print a stack
void print(struct sNode* top) {
    printf("\n");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

// Driver Code
int main() {
    struct sNode* stack = NULL;
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 1);

    printf("Original Stack: ");
    print(stack);

    reverse(&stack);

    printf("Reversed Stack: ");
    print(stack);

    return 0;
}
