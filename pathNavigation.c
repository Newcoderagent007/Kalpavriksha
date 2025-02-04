#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct stack {
    char arr[MAXSIZE][MAXSIZE];
    int top;
} stack;

void init(stack *s) {
    s->top = -1;
}

void push(stack *s, char str[MAXSIZE]) {
    strcpy(s->arr[++(s->top)], str);
}

char* pop(stack *s) {
    return s->arr[(s->top)--];
}

int main() {
    stack s;
    init(&s);
    int n;

    printf("Enter the n:");
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        char str[10];
        printf(">");
        scanf(" cd %s",str);

        if (strncmp(str, "../", 6) == 0) {
            if (s.top != -1) {
                pop(&s);
            }
        } else if (strncmp(str, "./", 5) == 0) {
            continue;
        } else {
            push(&s, str); 
        }
    }
    char result[MAXSIZE * MAXSIZE] = "/";
    for (int i = 0; i <= s.top; i++) {
        strcat(result, s.arr[i]);
        //strcat(result, "/");
    }

    printf("Current working directory: %s\n", result);

    return 0;
}
