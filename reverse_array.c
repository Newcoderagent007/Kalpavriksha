///array reversal
#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /* Write the logic to reverse the array. */
    int j=0;
    int k = num-1;
    
    while(j<k){
        swap(&arr[j],&arr[k]);
        j++;
        k--;
    }
    

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
