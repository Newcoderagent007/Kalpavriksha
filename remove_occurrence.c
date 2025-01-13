//  remove all occurrences of val in nums
#include <stdio.h>
#include <stdlib.h>


int removeElement(int* nums, int numsSize, int val) {
    int k = 0; 
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    
    return k;
}

int main() {
    int numsSize, val;
    
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);
    
    int* nums = (int*)malloc(numsSize * sizeof(int));
    
    printf("Enter %d elements:\n", numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    
    printf("Enter the value to be removed: ");
    scanf("%d", &val);
    
    printf("Original array:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    int newLength = removeElement(nums, numsSize, val);
    
    printf("Array after removing %d:\n", val);
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    printf("New length of the array: %d\n", newLength);
    
    free(nums); 
    return 0;
}
