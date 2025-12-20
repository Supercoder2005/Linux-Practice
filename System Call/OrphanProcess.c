#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
    if(fork()==0){
        sleep(5); // childs wait
        printf("\n Child Process (PID = %d), new Parent (PID = %d)\n",getpid(),getppid());
    }
    else{
        printf("\n Parent exiting... Child will be Orphan");
    }
    return 0;
}