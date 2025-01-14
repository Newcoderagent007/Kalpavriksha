//atoi
#include <stdio.h>
#include <limits.h>
#include <string.h>
int myAtoi(char* s) {
    int sign = 1, res = 0, idx = 0;

    while (s[idx] == ' ') {
        idx++;
    }

    if (s[idx] == '-' || s[idx] == '+') {
        if (s[idx++] == '-') {
            sign = -1;
        }
    }

   
    while (s[idx] >= '0' && s[idx] <= '9') {
        
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[idx] - '0' > 7)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        res = 10 * res + (s[idx++] - '0');
    }
    return res * sign;
}

int main() {
    char s[100];

    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    int result = myAtoi(s);

    printf("Converted integer: %d\n", result);

    return 0;
}
