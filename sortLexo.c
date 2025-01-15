//Sort Array of Strings Lexicographically
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int comp(const void* a,  const void*b){
    return strcmp(*(const char **)a , *(const char **)b);
    //return (*(const char **)a - *(const char **)b);
}

int main(){
    int n;
    scanf("%d",&n);
    
    char **str = malloc(n*sizeof(char *));
    
    for(int i=0;i<n;i++){
        str[i] = malloc(100 *sizeof(char));
    }
    
    for(int i=0;i<n;i++){
        printf("enter string at %d: \n",i);
        scanf("%s",str[i]);
    }
    
    qsort(str,n,sizeof(char *),comp);
    
    printf("after sorting\n");
    
    for(int i=0;i<n;i++){
        printf("%s ",str[i]);
    }
    for(int i=0;i<n;i++){
        free(str[i]);
    }
    free(str);
}
