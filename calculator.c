#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LEN 100

// Function to apply an operator to two operands
int applyOperator(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
            return a / b;
        default: return 0;
    }
}

// Function to get the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to evaluate an expression
int evaluateExpression(char *expr, int *result) {
    int len = strlen(expr);
    int stack[MAX_EXPR_LEN], top = -1;
    char operators[MAX_EXPR_LEN];
    int op_top = -1;

    for (int i = 0; i < len; i++) {
        if (isspace(expr[i])) {
            continue;
        }

        if (isdigit(expr[i])) {
            int num = 0;
            while (i < len && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            stack[++top] = num;
        } else if (expr[i] == '(') {
            operators[++op_top] = expr[i];
        } else if (expr[i] == ')') {
            while (op_top >= 0 && operators[op_top] != '(') {
                int b = stack[top--];
                int a = stack[top--];
                char op = operators[op_top--];
                stack[++top] = applyOperator(op, a, b);
            }
            if (op_top >= 0) op_top--; // Pop '('
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (op_top >= 0 && precedence(operators[op_top]) >= precedence(expr[i])) {
                int b = stack[top--];
                int a = stack[top--];
                char op = operators[op_top--];
                stack[++top] = applyOperator(op, a, b);
            }
            operators[++op_top] = expr[i];
        } else {
            printf("Error: Invalid expression.\n");
            return 0;
        }
    }

    while (op_top >= 0) {
        int b = stack[top--];
        int a = stack[top--];
        char op = operators[op_top--];
        stack[++top] = applyOperator(op, a, b);
    }

    if (top == 0) {
        *result = stack[top];
        return 1;
    } else {
        printf("Error: Invalid expression.\n");
        return 0;
    }
}

int main() {
    char expr[MAX_EXPR_LEN];
    int result;

    printf("Enter a mathematical expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0'; // Remove newline character from input

    if (evaluateExpression(expr, &result)) {
        printf("Result: %d\n", result);
    }

    return 0;
}
