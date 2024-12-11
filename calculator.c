#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100


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


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


int evaluateExpression(const char *expr, int *result) {
    int values[MAX_LEN], values_top = -1;
    char ops[MAX_LEN], ops_top = -1;
    int i, num;

    for (i = 0; expr[i]; i++) {
        if (isspace(expr[i])) continue;

        if (isdigit(expr[i])) {
            num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--; 
            values[++values_top] = num;
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (ops_top >= 0 && precedence(ops[ops_top]) >= precedence(expr[i])) {
                int b = values[values_top--];
                int a = values[values_top--];
                char op = ops[ops_top--];
                values[++values_top] = applyOperator(op, a, b);
            }
            ops[++ops_top] = expr[i];
        } else {
            printf("Error: Invalid expression.\n");
            return 0;
        }
    }

    while (ops_top >= 0) {
        int b = values[values_top--];
        int a = values[values_top--];
        char op = ops[ops_top--];
        values[++values_top] = applyOperator(op, a, b);
    }

    *result = values[values_top];
    return 1;
}

int main() {
    char expr[MAX_LEN];
    int result;

    printf("Enter a mathematical expression: ");
    fgets(expr, sizeof(expr), stdin);

    if (evaluateExpression(expr, &result)) {
        printf("Result: %d\n", result);
    }

    return 0;
}
