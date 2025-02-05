#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char *time) {
    int hour, minute;
    char period[3];
    sscanf(time, "%d:%d %s", &hour, &minute, period);

    if (strcmp(period, "am") == 0 && hour == 12) {
        hour = 0; 
    } else if (strcmp(period, "pm") == 0 && hour != 12) {
        hour += 12;  
    }

    printf("%d:%d\n", hour, minute);
}

int main() {
    char str[100];
    printf("Enter the timestamps: ");
    scanf("%[^\n]", str);

    char *token = strtok(str, ",");
    while (token != NULL) {

        printf("%s -> ", token);
        convert(token);

        token = strtok(NULL, ",");
    }

    return 0;
}
