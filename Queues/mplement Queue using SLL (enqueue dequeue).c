#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Queue Implementation

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to enqueue an element in the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

int main() {
    struct Queue* queue = createQueue();
    
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Dequeued from the queue: %d\n", dequeue(queue));
    printf("Dequeued from the queue: %d\n", dequeue(queue));

    return 0;
}
