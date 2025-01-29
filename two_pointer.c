#include <stdio.h>

void find_pair_with_sum(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            printf("Pair found: (%d, %d) with indices (%d, %d)\n", arr[left], arr[right], left, right);
            return;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    printf("No pair found with the given target sum.\n");
}

int main() {
    int arr[] = {1, 3, 4, 5, 7, 10, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    find_pair_with_sum(arr, size, target);

    return 0;
}
