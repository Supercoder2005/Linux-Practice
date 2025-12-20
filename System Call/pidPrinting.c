#include<stdio.h>
#include<unistd.h>

int main(){
    if(fork()==0){
        printf("\n Child Process is Calling ----\n");
        printf("\n Process id of this process : %d\n",getpid());
        printf("\n Process id of its parent process : %d\n",getppid());
    }
    else{
        printf("\n Parent Process is Calling ----\n");
        printf("\n Process id of this process : %d\n",getpid());
    }
}