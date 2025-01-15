//four sum
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void*a,const void*b){
    return(*(int *)a - *(int *)b);
}

void foursum(int *arr,int n,int target){
    qsort(arr,n,sizeof(int),compare);
    
    for(int i=0;i<n-3;i++){
        if( i > 0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1;j<n-2;j++){
            if(j > i+1 && arr[j] == arr[j-1]) continue;
            
            int left = j+1;
            int right = n-1;
            
            while(left < right){
                int sum = arr[i]+arr[j]+arr[left]+arr[right];
                if( sum == target){
                    printf("result- %d , %d , %d ,%d\n", arr[i],arr[j],arr[left],arr[right]);
                    left++;
                    right--;
                
                
                while ( left < right && arr[left] == arr[left-1]) left++;
                while( left<right && arr[right] == arr[right+1]) right--;
                }
                else if (sum < target) {left++;}
                else {right--;}
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int target;
    scanf("%d",&target);
    
    int*arr = malloc(n * sizeof(int ));
    
    for(int i=0;i<n;i++){
        printf("enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    
    foursum(arr,n,target);
    
    free(arr);
}
