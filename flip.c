#include <stdio.h>

void flip(int n, int matrix[][n]) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(matrix[i][j] == 0){
                matrix[i][j] = 1;
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
    
}
int main() {
	int n;
	scanf("%d", &n);
	int matrix[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	flip(n, matrix);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
    return 0;
}

