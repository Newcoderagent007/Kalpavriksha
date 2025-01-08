#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LEN 50

void printMatrix(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LEN], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }
}

int startsWithVowel(char name[MAX_NAME_LEN]) {
    char firstLetter = tolower(name[0]);
    return (firstLetter == 'a' || firstLetter == 'e' || firstLetter == 'i' || firstLetter == 'o' || firstLetter == 'u');
}

int main() {
    int rows, cols;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LEN];
    char longestName[MAX_NAME_LEN] = "";

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) {
        printf("Invalid input. Number of rows must be between 1 and %d and number of columns must be between 1 and %d.\n", MAX_ROWS, MAX_COLS);
        return 1;
    }

    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
        }
    }

    printf("\nThe 2D array of names is:\n");
    printMatrix(names, rows, cols);

    int vowelCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (startsWithVowel(names[i][j])) {
                vowelCount++;
            }
            if (strlen(names[i][j]) > strlen(longestName)) {
                strcpy(longestName, names[i][j]);
            }
        }
    }
  
    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);

    printf("The longest name: %s\n", longestName);

    return 0;
}
