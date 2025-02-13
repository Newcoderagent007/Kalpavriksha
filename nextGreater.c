#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100

typedef struct stack {
    int arr[maxsize];
    int top;
} stack;

void init(stack *s) {
    s->top = -1;
}

int isfull(stack *s) {
    if (s->top == maxsize - 1) {
        return 1;
    }
    return 0;
}

int isempty(stack *s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

void push(stack *s, int val) {
    if (isfull(s)) {
        return;
    }
    s->arr[++s->top] = val;
}

int pop(stack *s) {
    if (isempty(s)) {
        return -1;
    }
    return s->arr[s->top--];
}

int main() {
    int n;
    scanf("%d", &n);
    int res[n];
    for (int i = 0; i < n; i++) {
        res[i] = -1;
    }
    stack s;
    init(&s);
    int input[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!isempty(&s) && input[i % n] >= s.arr[s.top]) {
            pop(&s);
        }
        if (!isempty(&s)) {
            res[i % n] = s.arr[s.top];
        }
        push(&s, input[i % n]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
