//freq of each digit in string

#include <stdio.h>
#include <string.h>

int main() {
    char num[1001];
    int count[10] = {0};
    scanf("%s", num);
    for (int i = 0; i < strlen(num); i++) {
        if (num[i] >= '0' && num[i] <= '9') {
          count[num[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("freq of %d is :%d\n", i,count[i]);
    }
    
    return 0;
}
