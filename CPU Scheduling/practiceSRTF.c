#include<stdio.h>
#include<limits.h>
int main(){
    int i,n;
    printf("\n Enter the number of processes:");
    scanf("%d",&n);
    int pid[n],at[n],bt[n],ct[n],tat[n],rt[n],wt[n];
    int count = 0; // keeps track of how many processes are completed 
    int time = 0; // indicates the current cpu time 
    float sumwt = 0.0;
    float sumtat = 0.0;
    for(i=0;i<n;i++){
        pid[i] = i+1;
        printf("\n Enter the arrival time of process %d:",pid[i]);
        scanf("%d",&at[i]);
    }
    for(i=0;i<n;i++){
        printf("\n Enter the burst time of process %d:",pid[i]);
        scanf("%d",&bt[i]);
        // initialize the rt and ct of each process 
        rt[i] = bt[i];
        ct[i] = 0;
    }
    // main srtf algorithm 
    while(count<n){ // loop continues untill all of the n processes are completed
        int smallest = -1; // index of the process having minimum remaining time 
        int min = INT_MAX; // stores the process having minimum remaining time 
        for(i=0;i<n;i++){
            // if a process arrives before or just at the current time 
            // and have some amount of remaining time with it and rt is less than shortest remaining time 
            // then update the min with this rt 
            if(at[i]<=time && rt[i]>0 && rt[i]<min){
                min = rt[i];
                smallest = i;
            }
        }
        // everytime execute that process having smallest rt for 1 unit of time 
        rt[smallest]--;
        // when no process is in the cpu , it will be in idle condition 
        if(smallest == -1){
            time++;
            continue;
        }
        // when the remaining of the process with smallest rt , becomes 0 
        if(rt[smallest]==0){
            ct[smallest] = time+1;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];
            sumtat += tat[smallest];
            sumwt += wt[smallest];
            count ++; // count is incremented as one process is finished
        }
        time++;
    }
    printf("\n ProcessID\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime");
    for(i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n Average TurnAroundTime = %f",sumtat/n);
    printf("\n Average WaitingTime = %f",sumwt/n);
    return 0;
}