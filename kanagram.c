 // check if the strings are k-anagrams
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool areKAnagrams(char *s1, char *s2, int k) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) {
        return false;
    }

    int map[256] = {0};
    for (int i = 0; i < len1; i++) {
        char ch = s1[i];
        map[ch]++;
    }

    for (int i = 0; i < len2; i++) {
        char ch = s2[i];
        if (map[ch] > 0) {
            map[ch]--;
        }
    }

    int count = 0;
    for (int i = 0; i < 256; i++) {
        count += map[i];
    }

    if (count > k)
        return false;
    else
        return true;
}

int main() {
    char str1[100], str2[100];
    int k;

    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    printf("Enter the value of k: ");
    scanf("%d", &k);


    if (areKAnagrams(str1, str2, k)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
