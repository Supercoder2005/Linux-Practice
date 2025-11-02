#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    int fd[2],n,i;
    int fact = 1;
    pipe(fd);
    if(pipe(fd)== -1){
        printf("\n Pipe creation failed.");
    }
    if(fork()==0){ // Child process
        read(fd[0],&n,sizeof(n));
        for(i=n;i>=1;i--){
            fact = fact*i;
        }
        printf("\n Factorial :%d",fact);
    }
    else{ // Parent process
        printf("\n Enter the number:");
        scanf("%d",&n);
        write(fd[1],&n,sizeof(n));
    }
    return 0;
}