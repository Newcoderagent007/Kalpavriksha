//two sum
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int numsSize, target, returnSize;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &numsSize);

    
    int* nums = (int*)malloc(numsSize * sizeof(int));

  
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

  
    printf("Enter the target value: ");
    scanf("%d", &target);

   
    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        
        free(result);
    } else {
        printf("No solution found.\n");
    }

   
    free(nums);

    return 0;
}


