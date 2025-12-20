#include<stdio.h>
#include<limits.h>
int main(){
    int i,n;
    printf("\n Enter the number of processes:");
    scanf("%d",&n);
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],rt[n];
    int count = 0; // keeps track of the no. of completed processes 
    int time = 0; // indicates the current time
    float sumwt = 0;
    float sumtat = 0;
    // taking input of arrival times 
    for(i=0;i<n;i++){
        pid[i] = i+1;
        printf("\n Enter arrival time of process %d:",pid[i]);
        scanf("%d",&at[i]);
    }
    // taking input of burst time 
    for(i=0;i<n;i++){
        printf("\n Enter burst time of process %d:",pid[i]);
        scanf("%d",&bt[i]);
        // initialize remaining time and completion time of each process
        rt[i] = bt[i];
        ct[i] = 0;
    }
    // main SRTF algorithm 
    // loop will continue untill all processes are completed 
    while(count<n){
        // initialize smallest and min variable 
        int smallest = -1; // stores the index of the process with smallest remaining time , initially -1 
        int min = INT_MAX; // stores the process with shortest remaining time 
        for(i=0;i<n;i++){
            // when a process arrives before or just at the current time,
            // having some remaining time , and the rt is less than min(shortest rt) , then update the min variable 
            if(at[i]<=time && rt[i]>0 && rt[i]<min){
                min = rt[i];
                smallest = i;
            }
        }
        // when no process in the cpu,idle condition, then increment time & skip that loop 
        if(smallest == -1){
            time++;
            continue;
        }
        // everytime execute the process with shortest rt first , for only 1 unit of time 
        rt[smallest] --;
        // when remaining time becomes 0 means process is finished
        if(rt[smallest] == 0){
            ct[smallest] = time+1;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];
            sumwt += wt[smallest];
            sumtat += tat[smallest];
            count ++; // one process execution is over so completed process count increased by 1 
        }
        time ++;
    }
    // display the output 
    printf("\n ProcessId\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime");
    for(i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n Average Waiting time : %f",sumwt/n);
    printf("\n Average Turn Around time : %f",sumtat/n);
    return 0;
}