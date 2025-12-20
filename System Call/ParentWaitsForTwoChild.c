#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/types.h>
int main(){
    pid_t pid1,pid2;
    pid1 = fork();
    if(pid1 == 0){
        printf("\n First Child is created , PID = %d",getpid());
    }
    else{
        pid2 = fork();
        if(pid2 == 0){
            printf("\n Second Child is created , PID = %d",getpid());
        }
        else{
            wait(NULL);
            wait(NULL);
            printf("\n Parent Process is created after both the child are terminated.");
        }
    }
    return 0;
}