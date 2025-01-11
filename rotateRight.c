 //  rotate  array to the right by k steps
#include <stdio.h>
#include <stdlib.h>


void reverse(int a,int b,int *nums){
    while(a<b){
        int temp = nums[b];
        nums[b] = nums[a];
         nums[a] = temp;
         b--;
         a++;
    }
}
void rotate(int* nums, int numsSize, int k) {
    int timesRotate = k%numsSize;
    reverse(0,numsSize-1, nums);
    reverse(0,timesRotate-1,nums);
    reverse(timesRotate,numsSize-1,nums);
}

int main() {
    int numsSize, k;
    
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);
    
    int* nums = (int*)malloc(numsSize * sizeof(int));
    
    printf("Enter %d elements:\n", numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    printf("Original array:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    rotate(nums, numsSize, k);
    
    printf("Array after rotation ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    free(nums); 
    return 0;
}
