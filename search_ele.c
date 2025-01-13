// search an element in a row-wise and column-wise sorted matrix
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool matSearch(int **mat, int rows, int cols, int x) {
    int i = 0, j = cols - 1;

    while (i < rows && j >= 0) {
        
        if (x > mat[i][j]) {
            i++;
        }
         
        else if (x < mat[i][j]) {
            j--;
        }
        
        else {
            return true;
        }
    }

  
    return false;
}


int main() {
    int rows, cols, x;

   
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    
    int **mat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat[i] = (int *)malloc(cols * sizeof(int));
    }

    
    printf("Enter the elements of the %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Enter the element to search for: ");
    scanf("%d", &x);

    if (matSearch(mat, rows, cols, x)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
