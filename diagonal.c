//diagonal sum
#include <stdio.h>
#include <stdlib.h>

void printDiagonalSums(int **mat, int m, int n)
{
    int principal = 0, secondary = 0;
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i == j)
                principal += mat[i][j];

            if ((i + j) == (n - 1))
                secondary += mat[i][j];
        }
    }

    printf("Principal Diagonal: %d\n", principal);
    printf("Secondary Diagonal: %d\n", secondary);
}

int main()
{
    int m, n;

    printf("Enter the number of rows (M): ");
    scanf("%d", &m);
    printf("Enter the number of columns (N): ");
    scanf("%d", &n);

    int **a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) 
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the %dx%d matrix:\n", m, n);
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printDiagonalSums(a, m, n);

    for (int i = 0; i < m; i++) 
    {
        free(a[i]);
    }
    free(a);

    return 0;
}
