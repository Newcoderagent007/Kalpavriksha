//check if one array is a subset of another
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSubset(int *a, int m, int *b, int n) {
    for (int i = 0; i < n; i++) {
        bool found = false;

        for (int j = 0; j < m; j++) {
            if (b[i] == a[j]) {
                found = true;
                break;
            }
        }

        if (!found) return false;
    }

    return true;
}

int main() {
    int m, n;

    printf("Enter the number of elements in the first array (M): ");
    scanf("%d", &m);

    int *a = (int *)malloc(m * sizeof(int));

    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < m; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter the number of elements in the second array (N): ");
    scanf("%d", &n);

    int *b = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &b[i]);
    }

    if (isSubset(a, m, b, n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    free(a);
    free(b);

    return 0;
}
