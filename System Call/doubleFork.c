#include<stdio.h>
#include<unistd.h>
int main(){
    printf("Calling Double Fork\n");
    fork();
    fork();
    printf("Good Morning\n");
    return 0;
}