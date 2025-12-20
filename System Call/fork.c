#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t pid;
    pid = fork();
    if(pid == 0){
        printf("Child Process is calling ------\n");
        printf("Returned value of child process system call fork() : %d\n",pid);
    }
    else{
        printf("Parent Process is calling ------\n");
        printf("Returned value of parent process system call fork() : %d\n",pid);
    }
    return 0;
}