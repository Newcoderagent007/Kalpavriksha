//student with highest arks
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char name[100];
    int total_marks;
} student;

int main() {
    int m ,n;
    scanf("%d %d",&m,&n);
    student students[10000];
    int highest_marks =0; 
    for(int i=0;i<m;i++){
        printf("enter %d student name : ",i+1);
        scanf("%s",students[i].name);
        students[i].total_marks = 0;
        for(int j=0;j<n;j++){
            int marks;
            scanf("%d",&marks);
            students[i].total_marks+=marks;
        }
        
        if(students[i].total_marks > highest_marks ){
            highest_marks = students[i].total_marks;
        }
    }
    
    for(int i=0;i<m;i++){
        if(students[i].total_marks == highest_marks){
            printf("student with highest marks : %s\n",students[i].name);
        }
    }

    return 0;
}
