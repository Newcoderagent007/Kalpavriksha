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

bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
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

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

int size(Stack* stack) {
    return stack->size;
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
                if (isEmpty(&stack)) {
                    printf("The stack is empty\n");
                } else {
                    printf("The stack is not empty\n");
                }
                break;
            case 5:
                printf("Size of the stack: %d\n", size(&stack));
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
