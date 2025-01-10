#include <stdio.h>
int main()
{
    int a[10][10], b[10][10], c[10][10], i, j, k, m, n, p, q;
    printf("\tGive the order of the first matrix :\t\tm =");
    scanf("%d", &m);
    printf("\t\tn=");
    scanf("%d", &n);
    printf("\tGive the elements of the First matrix :");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\tGive the order of the second matrix :\t\tp=");
    scanf("%d", &p);
    printf("\t\tq=");
    scanf("%d", &q);
    printf("\tGive the elements of the second matrix :");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    if (p != n)
        printf("\tError : Such matrix multiplication is not possible.");
    else if (p == n)
    {

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                c[i][j] = 0;
                for (k = 0; k < n; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        printf(" The product of 2 matrices are\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("\t%d", c[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
