//print repeating words
#include<string.h>
#include <stdio.h>

int is_unique(char words[][101],int n, char word[]){
    int count =0;
    for(int i=0;i<n;i++){
        if(strcmp(words[i] , word)==0) count++;
    }
    return count == 1;
}

int main()
{
    char sentence[10000];
    char words[101][101];
    printf("enter sentence: ");
    fgets(sentence,sizeof(sentence),stdin);
  
    int n=0;
    char *token = strtok(sentence," ");
    while(token != NULL){
        int token_len = strlen(token); 
        if (token[token_len - 1] == '\n') {
            token[token_len - 1] = '\0';
        }
        strcpy(words[n++],token);
        token = strtok(NULL," ");
    }
    printf("Non repeating words\n");
    for(int i=0;i<n;i++){
        if(is_unique(words , n ,words[i])){
            printf("%s\n",words[i]);
        }
    }

    return 0;
}
