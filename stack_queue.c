#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}
bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    Node* temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return dequeuedValue;
}

typedef struct Stack {
    Queue queue;
} Stack;

void initStack(Stack* stack) {
    initQueue(&stack->queue);
}
void push(Stack* stack, int value) {
    enqueue(&stack->queue, value);
    for (int i = 0; i < stack->queue.size - 1; i++) {
        enqueue(&stack->queue, dequeue(&stack->queue));
    }
}

int pop(Stack* stack) {
    return dequeue(&stack->queue);
}

int peek(Stack* stack) {
    if (isEmpty(&stack->queue)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->queue.front->data;
}

bool isStackEmpty(Stack* stack) {
    return isEmpty(&stack->queue);
}

int stackSize(Stack* stack) {
    return stack->queue.size;
}

int main() {
    Stack stack;
    initStack(&stack);
    int choice, value;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if stack is empty\n");
        printf("5. Get size of stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                if (isStackEmpty(&stack)) {
                    printf("The stack is empty\n");
                } else {
                    printf("The stack is not empty\n");
                }
                break;
            case 5:
                printf("Size of the stack: %d\n", stackSize(&stack));
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
