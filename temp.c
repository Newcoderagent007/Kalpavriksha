#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%[^\n]",str);
    char time[100];
    float temp;
    char unit;
    char *token = strtok(str,", ");
    while(token != NULL){
        sscanf(token,"%[^-]-%f%c",time,&temp,&unit);
        printf("%s - ", time);
        if (unit == 'F') {
        float celsius = (temp - 32) * 5 / 9;
        printf("Original: %.1fF, Converted: %.1fC\n", temp, celsius);
    } else if (unit == 'C') {
        float fahrenheit = (temp * 9 / 5) + 32;
        printf("Original: %.1fC, Converted: %.1fF\n", temp, fahrenheit);
    }
        printf("\n");
        token = strtok(NULL,", ");
    }
    return 0;
}
