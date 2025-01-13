// calculate the product of array elements except self
#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *result = (int *)malloc(numsSize * sizeof(int));
    int *left = (int *)malloc(numsSize * sizeof(int));
    int *right = (int *)malloc(numsSize * sizeof(int));
    
    left[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        left[i] = left[i - 1] * nums[i - 1];
    }

    right[numsSize - 1] = 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        right[i] = right[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < numsSize; i++) {
        result[i] = left[i] * right[i];
    }

    *returnSize = numsSize;
    free(left);
    free(right);
    return result;
}

int main() {
    int numsSize;
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    int *nums = (int*)malloc(numsSize * sizeof(int));
    printf("Enter %d elements:\n", numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* output = productExceptSelf(nums, numsSize, &returnSize); // Renamed variable

    printf("Product of array elements except self:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    free(nums);
    free(output);
    return 0;
}
