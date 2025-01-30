#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

bool isFull(Queue* queue) {
    return queue->size == MAX;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (queue->rear == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX;
    }
    queue->data[queue->rear] = value;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int dequeuedValue = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    queue->size--;
    return dequeuedValue;
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->data[queue->front];
}

int size(Queue* queue) {
    return queue->size;
}

int main() {
    Queue queue;
    initQueue(&queue);
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if queue is empty\n");
        printf("5. Get size of queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                value = dequeue(&queue);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&queue);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                if (isEmpty(&queue)) {
                    printf("The queue is empty\n");
                } else {
                    printf("The queue is not empty\n");
                }
                break;
            case 5:
                printf("Size of the queue: %d\n", size(&queue));
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
