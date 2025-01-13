//comon element in in all rows of a given matrix
#include <stdio.h>
#include <stdlib.h>

void printCommonElements(int **mat, int m, int n) {
    int *mp = (int *)malloc(1001 * sizeof(int)); 
    for (int i = 0; i <= 1000; i++) mp[i] = 0;

    for (int j = 0; j < n; j++) 
        mp[mat[0][j]] = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            
            if (mp[mat[i][j]] == i) {
                
                mp[mat[i][j]] = i + 1;

                
                if (i == m - 1 && mp[mat[i][j]] == m) {
                    printf("%d ", mat[i][j]);
                }
            }
        }
    }

    free(mp);
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

    printf("Common elements in all rows: ");
    printCommonElements(mat, m, n);
    printf("\n");

    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
