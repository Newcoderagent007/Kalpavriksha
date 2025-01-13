//Rotate Each Row of Matrix K Times
#include <stdio.h>
#include <stdlib.h>

void rotateMatrix(int **matrix, int rows, int cols, int k) {
   
    int *temp = (int *)malloc(cols * sizeof(int));

    k = k % cols;

    for (int i = 0; i < rows; i++) {
       
        for (int t = 0; t < cols - k; t++)
            temp[t] = matrix[i][t];

        for (int j = cols - k; j < cols; j++)
            matrix[i][j - cols + k] = matrix[i][j];

        for (int j = k; j < cols; j++)
            matrix[i][j] = temp[j - k];
    }

    free(temp);
}

void displayMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int rows, cols, k;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the number of rotations (k): ");
    scanf("%d", &k);

    rotateMatrix(matrix, rows, cols, k);

    printf("Rotated Matrix:\n");
    displayMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
