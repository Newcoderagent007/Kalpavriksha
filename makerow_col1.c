//make row and col as 1 if i is present
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void booleanMatrix(int **mat, int rows, int cols) {
    bool *rowMarker = (bool *)malloc(rows * sizeof(bool));
    bool *colMarker = (bool *)malloc(cols * sizeof(bool));

    for (int i = 0; i < rows; i++) rowMarker[i] = false;
    for (int j = 0; j < cols; j++) colMarker[j] = false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 1) {
                rowMarker[i] = true;
                colMarker[j] = true;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowMarker[i] || colMarker[j]) {
                mat[i][j] = 1;
            }
        }
    }

    free(rowMarker);
    free(colMarker);
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **mat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the %dx%d matrix (0 or 1):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            do {
                printf("Element [%d][%d] (0 or 1): ", i, j);
                scanf("%d", &value);
                if (value != 0 && value != 1) {
                    printf("Invalid input. Please enter 0 or 1.\n");
                }
            } while (value != 0 && value != 1);
            mat[i][j] = value;
        }
    }

    booleanMatrix(mat, rows, cols);

    printf("Updated Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
