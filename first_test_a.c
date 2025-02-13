#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b =temp;
}

int main(){
    int matrix[10][10] = {0};
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int x,y,z;
        printf("enter input-\n");
        scanf("%d",&x);
        if(x == 1){
            printf("enter position x and y: \n");
            scanf("%d %d",&y,&z);
            matrix[y][z] = 1; 
        }
        if( x == 2){
            for(int i=0;i<10;i++){
                for(int j=0;j<5;j++){
                    swap(&matrix[i][j],&matrix[i][10-j-1]);
                }
            }
        }
        if(x == 3){
            for(int i=0;i<10;i++){
                for(int j=i+1;j<10;j++){
                   swap(&matrix[i][j] , &matrix[j][i]) ;
                }
            }
            for(int i=0;i<10;i++){
                for(int j=0;j<5;j++){
                    swap(&matrix[i][j],&matrix[i][10-j-1]);
                }
            }
        }

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
