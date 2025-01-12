//boundary traversal
#include <stdio.h>
#include <stdlib.h>


void boundaryTraversal(int **mat, int n, int m) 
{

    int *ans = (int *)malloc((2 * n + 2 * m - 4) * sizeof(int));
    int k = 0;

    if (n == 1) {
        for (int i = 0; i < m; i++)
            ans[k++] = mat[0][i];
    } else if (m == 1) {
        for (int i = 0; i < n; i++)
            ans[k++] = mat[i][0];
    } else {
        for (int i = 0; i < m; i++)
            ans[k++] = mat[0][i];
        for (int i = 1; i < n; i++)
            ans[k++] = mat[i][m - 1];
        for (int i = m - 2; i >= 0; i--)
            ans[k++] = mat[n - 1][i];
        for (int i = n - 2; i > 0; i--)
            ans[k++] = mat[i][0];
    }

    printf("Boundary Traversal: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    free(ans);
}

int main() {
    int n, m;

    printf("Enter the number of rows : ");
    scanf("%d", &n);
    printf("Enter the number of columns : ");
    scanf("%d", &m);

    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the elements of the %dx%d matrix:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }


    boundaryTraversal(mat, n, m);

    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
