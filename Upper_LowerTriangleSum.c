#include <stdio.h>
#include <string.h>

void sumTriangles(int n, int matrix[][n],int answer[2])
{
         int upper=0 , lower=0;
         static int result[2];
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 if(i<j){
                     upper = upper + matrix[i][j];
                 }
                 else if (i == j){
                     upper  = upper  + matrix[i][j];
                     lower = lower + matrix[i][j];
                 }
                 else{
                      lower = lower + matrix[i][j];
                 }
             }
         }
         answer[0]=upper;
         answer[1] = lower;
         
}

int main(){
    int n;
	scanf("%d", &n);
	int matrix[n][n];
	int answer[2];	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
		
    sumTriangles(n, matrix,answer);
    for (int i = 0; i < 2; i++)
        printf("%d ", answer[i]);
	printf("\n");
    
}

