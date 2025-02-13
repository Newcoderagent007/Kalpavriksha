#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isprime(int num){
    if(num <= 1) return 0;
    for (int i = 2; i*i <= num; i++)
    {
        if(num%i == 0){
            return 0;
        }
        return 1;
    }
    
}
int main(){
    char str[1000];
    int k;
    printf("enter string: \n");
    scanf("%s",str);
    printf("enter k: \n");
    scanf("%d",&k);
    k = k%26;
    int n = strlen(str);

    for(int i=0;i<n;i++){
        if(isprime(i)){
            str[i] = ((str[i]-'a' + k)%26 )+ 'a';
        }
    }

    printf("%s \n",str);
}
