#include<stdio.h>
#include<unistd.h>

int main(){
    int pd[2];
    int i,num;
    int count = 0;
    // create pipe 
    pipe(pd);
    // create child process (logic of prime number)
    if(fork() == 0){
        close(pd[1]); // close the write end 
        read(pd[0],&num,sizeof(num)); // read 
        // prime no logic
        for(i=2;i<num;i++){
            if(num%i == 0){
                count = 1;
                break;
            }
        }
        if(count == 0){
            printf("\n Child: %d is a prime number.\n",num);
        }
        else{
            printf("\n Child: %d is not a prime number.\n",num);
        }
        close(pd[0]);
    }
    // Parent process 
    else{
        close(pd[0]);
        printf("\n Parent Process is created.");
        printf("\n Enter a number:");
        scanf("%d",&num);
        write(pd[1],&num,sizeof(num));
        close(pd[1]);
    }
    return 0;
}
