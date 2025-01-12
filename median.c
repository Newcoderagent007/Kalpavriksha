//median of 2d matrix
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int median(int **mat, int m, int n) {
  
    int size = m * n;
    int *arr = (int *)malloc(size * sizeof(int));

    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[k++] = mat[i][j];
        }
    }

    qsort(arr, size, sizeof(int), compare);

    int mid = size / 2;
    int result;
    if (size % 2 == 0) {
        result = arr[mid - 1];
    } else {
        result = arr[mid];
    }

    free(arr);
    return result;
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

    printf("Enter the elements of the %dx%d matrix:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    int med = median(mat, m, n);
    printf("Median of the matrix is %d\n", med);

    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
