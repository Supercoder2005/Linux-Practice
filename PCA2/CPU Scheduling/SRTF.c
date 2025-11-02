#include<stdio.h>
#include<limits.h>

int main(){
    int i,n;
    int time = 0; // simulation time
    int count = 0; // total no of completed processes 
    float avgWt = 0, avgTat = 0;
    printf("\n Enter the no of processes :");
    scanf("%d",&n);
    int pid[n],at[n],bt[n],ct[n],wt[n],tat[n],rt[n];

    for(i=0;i<n;i++){
        pid[i] = i+1;
        printf("\n Enter arrival time of process %d :",pid[i]);
        scanf("%d",&at[i]);
    }
    for(i=0;i<n;i++){
        printf("\n Enter burst time of process %d :",pid[i]);
        scanf("%d",&bt[i]);
        // initialize the remaining time of processes as their burst time
        rt[i] = bt[i];
        ct[i] = 0;
    }
    
    // sort the processes according to their remianing time 
    for(time = 0 ; count < n ; time++){

        int smallest = -1; // smallest means index of the process with the shortest rt at the current time 
        int min = INT_MAX; // initialize the min remaining time to a very large number

        // find the process with the shortest remaining time among the arrived processes
        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0 && rt[i]<min){
                min = rt[i];
                smallest = i;
            }
        }

        // if no process is ready , cpu is in idle condition 
        if(smallest == -1){
            continue;
        }
        
        // execute the process with shortest remining time for only 1 unit of time
        rt[smallest]--;
        // if the process is finished 
        if(rt[smallest]==0){
            ct[smallest] = time+1;
            tat[smallest] = ct[smallest]-at[smallest];
            wt[smallest] = tat[smallest]-bt[smallest];

            avgWt += wt[smallest];
            avgTat += tat[smallest];

            count++;
        }
    }
    // display the result 
    printf("\n ProcessID\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n Average waiting time = %f",avgWt/n);
    printf("\n Average turn around time = %f",avgTat/n);

}