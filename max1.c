//index of row wiht max 1
#include <stdio.h>
#include <stdlib.h>

int rowWithMax1s(int **mat, int m, int n) {
    int indexOfRow= -1;
    int maxCount = 0;

    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            indexOfRow = i;
        }
    }
    return indexOfRow;
}

int main() {
    int m, n;

    printf("Enter the number of rows (M): ");
    scanf("%d", &m);
    printf("Enter the number of columns (N): ");
    scanf("%d", &n);

    int **mat = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the %dx%d matrix (0 or 1):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
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

    int indexOfRow = rowWithMax1s(mat, m, n);
    printf("Index of row with maximum 1s is %d\n", indexOfRow);

    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
