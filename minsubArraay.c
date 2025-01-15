//min subarray
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int minarray(int nums[], int n) {
    int cursum = nums[0];
    int minsum = nums[0];

    for (int i = 1; i < n; i++) {
        cursum = (cursum + nums[i] < nums[i]) ? (cursum + nums[i]) : nums[i];
        minsum = (minsum < cursum) ? minsum : cursum;
    }
    return minsum;
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);

    int nums[1000];
    int n = 0;
    char *token = strtok(input, "[], ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            nums[n++] = atoi(token);
        }
        token = strtok(NULL, "[], ");
    }

    if (n == 0) {
        printf("\n");
        return 0;
    }

    int res = minarray(nums, n);
    printf("%d\n", res);

    return 0;
}
