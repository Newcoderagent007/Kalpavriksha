//remove duplicates in-place such that each unique element appears at most twice
#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }

    int k = 2; 

    for (int i = 2; i < numsSize; i++) {
        
        if (nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k; }

int main() {
    int numsSize;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &numsSize);

    int* nums = (int*)malloc(numsSize * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    int k = removeDuplicates(nums, numsSize);

    printf("The new length of the array is: %d\n", k);
    printf("The modified array is:\n");

    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    free(nums);

    return 0;
}
