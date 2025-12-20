#include<stdio.h>
#include<unistd.h>
int main(){
    int pd[2]; // pd[0] used for read , pd[1] used for write 
    int num,i;
    // create the pipe 
    pipe(pd);
    // creating child process 
    if(fork()==0){
        close(pd[1]); // close the write end
        printf("\n Child process is created.");
        read(pd[0],&num,sizeof(num)); // read 
        int fact = 1;
        while(num>0){
            fact = fact*num;
            num--;
        }
        printf("\n The factorial is: %d\n",fact);
        close(pd[0]); // close the read end
    }
    else{
        close(pd[0]); // close the read end
        printf("\n Parent process is created.");
        printf("\n Enter the number :");
        scanf("%d",&num);
        write(pd[1],&num,sizeof(num)); // write the input 
        close(pd[1]); // close the write end 
    }
    return 0;
}