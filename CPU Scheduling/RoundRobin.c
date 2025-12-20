#include<stdio.h>
int main(){
    int i,n,qt;
    printf("\n Enter the total no of processes:");
    scanf("%d",&n);
    printf("\n Enter the quantam time:");
    scanf("%d",&qt);
    int count = 0 ;// keeps track of the total no of completed processes 
    int time = 0 ;// indicates the current unit of time 
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],rt[n];
    float sumwt = 0.0;
    float sumtat = 0.0;
    // input taking 
    for(i=0;i<n;i++){
        pid[i] = i+1;
        printf("\n Enter the arrival time of process %d:",pid[i]);
        scanf("%d",&at[i]);
    }
    for(i=0;i<n;i++){
        printf("\n Enter the burst time of process %d:",pid[i]);
        scanf("%d",&bt[i]);
        // initializing the rt and ct of every process 
        ct[i] = 0;
        rt[i] = bt[i];
    }
    // round robin starts from here 
    while(count<n){ // the loop continues untill all processes are completed 
        int executed = 0; // keeps track of whether a process is ready to execute or not,initially not ready
        for(i=0;i<n;i++){
            // when a process arrives before or just at the current time and that process has also some rt 
            // then only the process will be executable 
            if(at[i]<=time && rt[i]>0){
                executed = 1;
                // if the remaining time is greater than quantam time then the process will be executed for on the qt
                // and rt will decrease by that amount of qt 
                if(rt[i]>qt){
                    rt[i] -= qt;
                    time += qt;
                }
                // if the remaining time is less that qt then the process will execute for only the rt 
                else{
                    time += rt[i];
                    rt[i] = 0;
                    // calculating the ct,tat,wt of process 
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    sumwt += wt[i];
                    sumtat += tat[i];

                    // one process is completed 
                    count++;
                }
            }
        }
        // when no process is inside the cpu,idle condition 
        if(executed == 0){
            time++;
        }    
    }
    // display the output 
    printf("\n ProcessId\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime");
    for(i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n Average waiting time :%f",sumwt/n);
    printf("\n Average turn around time :%f",sumtat/n);
    return 0;
}