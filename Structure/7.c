#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int arr[100];
    int front, rear;
};

void initializeQueue(struct queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct queue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct queue *queue) {
    return (queue->rear == 100 - 1);
}

// Function to enqueue an element into the queue
void enqueue(struct queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        // If the queue is empty, set front and rear to 0
        queue->front = 0;
        queue->rear = 0;
    } else {
        // Increment rear circularly
        queue->rear = (queue->rear + 1) % 100;
    }
    // Enqueue the value
    queue->arr[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element from the queue
int dequeue(struct queue *queue) {
    int value;

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Assuming -1 represents an error or empty queue
    }

    // Dequeue the value
    value = queue->arr[queue->front];

    if (queue->front == queue->rear) {
        // If the queue has only one element, set front and rear to -1
        queue->front = -1;
        queue->rear = -1;
    } else {
        // Increment front circularly
        queue->front = (queue->front + 1) % 100;
    }

    printf("Dequeued: %d\n", value);
    return value;
}


int main()
{
    // Declare and initialize a queue
    struct queue myQueue;
    initializeQueue(&myQueue);

    // Enqueue some elements
    enqueue(&myQueue, 100);
    enqueue(&myQueue, 200);
    enqueue(&myQueue, 300);

    // Dequeue elements
    dequeue(&myQueue);
    dequeue(&myQueue);

    // Enqueue more elements
    enqueue(&myQueue, 400);
    enqueue(&myQueue, 500);

    // Dequeue remaining elements
    dequeue(&myQueue);
    dequeue(&myQueue);

    return 0;
}