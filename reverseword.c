//reverse word with .
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseWords(char *str) {
    
    char **words = (char **)malloc(strlen(str) * sizeof(char *));
    int wordCount = 0;

    char *token = strtok(str, ".");
    while (token != NULL) {
        words[wordCount++] = token;
        token = strtok(NULL, ".");
    }

    for (int i = 0; i < wordCount / 2; ++i) {
        char *temp = words[i];
        words[i] = words[wordCount - i - 1];
        words[wordCount - i - 1] = temp;
    }

    for (int i = 0; i < wordCount; ++i) {
        if (i > 0) {
            printf(".");
        }
        printf("%s", words[i]);
    }
    printf("\n");

    free(words);
}

int main() {
    char str[100];

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    reverseWords(str);

    return 0;
}
