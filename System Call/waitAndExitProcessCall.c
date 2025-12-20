#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
    int arr[] = {5,9,2,6,2};
    int i;
    if(fork()==0){
        printf("Child Process is calling-------\n");
        int s =0;
        for(i=0;i<5;i++){
            s = s+arr[i];
        }
        printf("The sum of the elements of the array = %d\n",s);
        exit(0);
    }
    else{
        wait(NULL);
        printf("Parent Process is called after termination of child process.\n");
    }
    return 0;
}