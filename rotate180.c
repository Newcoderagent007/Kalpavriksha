//  rotate the matrix by 180 degrees
#include <stdio.h>
#include <stdlib.h>


void rotateMatrix(int **mat, int n) {
    
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[n - i - 1][n - j - 1];
            mat[n - i - 1][n - j - 1] = temp;
        }
    }

    if (n % 2 != 0) {
        int mid = n / 2;
        for (int j = 0; j < n / 2; j++) {
            int temp = mat[mid][j];
            mat[mid][j] = mat[mid][n - j - 1];
            mat[mid][n - j - 1] = temp;
        }
    }
}

int main() {
    int n;

    printf("Enter the dimension of the square matrix (N): ");
    scanf("%d", &n);

    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    rotateMatrix(mat, n);

    printf("Rotated matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
