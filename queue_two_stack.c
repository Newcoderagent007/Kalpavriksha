#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

bool isEmptyStack(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return poppedValue;
}

typedef struct Queue {
    Stack stack1;
    Stack stack2;
} Queue;

void initQueue(Queue* queue) {
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

void enqueue(Queue* queue, int value) {
    push(&queue->stack1, value);
}

int dequeue(Queue* queue) {
    if (isEmptyStack(&queue->stack2)) {
        while (!isEmptyStack(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }
    return pop(&queue->stack2);
}

int peek(Queue* queue) {
    if (isEmptyStack(&queue->stack2)) {
        while (!isEmptyStack(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }
    if (isEmptyStack(&queue->stack2)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->stack2.top->data;
}

bool isQueueEmpty(Queue* queue) {
    return isEmptyStack(&queue->stack1) && isEmptyStack(&queue->stack2);
}

int queueSize(Queue* queue) {
    return queue->stack1.size + queue->stack2.size;
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
                if (isQueueEmpty(&queue)) {
                    printf("The queue is empty\n");
                } else {
                    printf("The queue is not empty\n");
                }
                break;
            case 5:
                printf("Size of the queue: %d\n", queueSize(&queue));
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
