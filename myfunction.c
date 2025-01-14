#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_strcpy(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; 
}

int my_strlen(const char *str) {
    int len = 0;
    while (*str) {
        len++;
        str++;
    }
    return len;
}

int my_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}

char* my_strchr(const char *str, char c) {
    while (*str) {
        if (*str == c) {
            return (char*)str;
        }
        str++;
    }
    return NULL;
}

void my_strcat(char *dest, const char *src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; 
}

int main() {
    
    char *str1 = (char*)malloc(100 * sizeof(char));
    char *str2 = (char*)malloc(100 * sizeof(char));

    if (str1 == NULL || str2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';  

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';  

    char *copy_str = (char*)malloc((my_strlen(str1) + 1) * sizeof(char));
    my_strcpy(copy_str, str1);
    printf("\nCopied string: %s\n", copy_str);

    printf("Length of first string: %d\n", my_strlen(str1));

    int cmp_result = my_strcmp(str1, str2);
    if (cmp_result == 0) {
        printf("Strings are equal.\n");
    } else if (cmp_result < 0) {
        printf("First string is less than the second string.\n");
    } else {
        printf("First string is greater than the second string.\n");
    }

    char ch;
    printf("Enter a character to find in the first string: ");
    scanf(" %c", &ch);  
    char *char_pos = my_strchr(str1, ch);
    if (char_pos) {
        printf("Character '%c' found at position: %ld\n", ch, char_pos - str1);
    } else {
        printf("Character '%c' not found in the first string.\n", ch);
    }

    my_strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    free(str1);
    free(str2);
    free(copy_str);

    return 0;
}
