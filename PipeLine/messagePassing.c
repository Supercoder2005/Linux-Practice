#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
    int pd[2]; // pd[] array : pd[0] uses for read , pd[1] uses for write
    char buffer[100];
    pid_t pid;
    // create pipe 
    if(pipe(pd) == -1){
        printf("\n Pipe Failed");
        exit(1);
    }
    // create child process 
    pid = fork();
    if(pid<0){
        printf("\n Fork Failed");
        exit(1);
    }
    if(pid == 0){
        close(pd[1]); // close the write part 
        read(pd[0],buffer,sizeof(buffer)); // read 
        printf("\n Child Process received message : %s\n",buffer);
        close(pd[0]); // close the read part 
    }
    // create parent process 
    else{
        close(pd[0]); // close the read part 
        char *msg = "Good Morning\n Hello World";
        write(pd[1],msg,strlen(msg));
        printf("\n Parent Process sent message\n");
        close(pd[1]);
    }
    return 0;
}