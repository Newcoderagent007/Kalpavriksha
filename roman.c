// convert decimal to Roman Numerals
#include <stdio.h>
#include <stdlib.h>


void printRoman(int number) {
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    char *sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;

    while (number > 0) {
        int div = number / num[i];
        number = number % num[i];
        while (div--) {
            printf("%s", sym[i]);
        }
        i--;
    }
}

int main() {
    int number;

    printf("Enter the decimal number: ");
    scanf("%d", &number);

    printRoman(number);
    printf("\n");

    return 0;
}
