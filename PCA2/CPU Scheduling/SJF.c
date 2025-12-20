#include<stdio.h>
#include<limits.h>
int main(){
    int i,n;
    printf("\n Enter the number of processes:");
    scanf("%d",&n);

    int pid[n],at[n],bt[n],ct[n],wt[n],tat[n];

    int count = 0; // no. of completed processes 
    int time = 0; // keeps track of the current cpu time 
    int completed[n]; // entry = 1 if processes are completed , otherwise 0 
    float sumtat = 0.0;
    float sumwt = 0.0;

    for(i=0;i<n;i++){
        pid[i] = i+1;
        printf("\n Enter the arrival time of the process %d:",pid[i]);
        scanf("%d",&at[i]);
    }
    for(i=0;i<n;i++){
        printf("\n Enter the burst time of the process %d:",pid[i]);
        scanf("%d",&bt[i]);
        // initialize the completed array with all processes are not completed = 0
        completed[i] = 0;
    }
    // main SJF algorithm starts from here 
    // loop will continue untill all n processes are completed 
    while(count<n){
        int smallest = -1; // stores index of that process having shortest burst time 
        int min = INT_MAX; // storest the process with smallest bt 

        // if a process has already arrived, having shortest job and not completed yet
        for(i=0;i<n;i++){
            if(at[i]<=time && completed[i] == 0 && bt[i]<= min){
                min = bt[i];
                smallest = i;                                                                                                                                                                                             
            }
        }
        
        // CPU idle condition , there is no process in the CPU
        if(smallest == -1){
            time++;
            continue;
        }
        // execute selected process according to their shorted job time completely one by one (Non Preemptive way)
        time = time + bt[smallest];

        ct[smallest] = time;
        tat[smallest] = ct[smallest] - at[smallest];
        wt[smallest] = tat[smallest] - bt[smallest];

        sumtat += tat[smallest];
        sumwt += wt[smallest];

        completed[smallest] = 1; // the process with smallest burst time is completed now 
        count++; // increment the count as one process is finished just now 
    }
    // output 
    printf("\n ProcessID\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime");
    for(i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n Average Turn around time = %f",sumtat/n);
    printf("\n Average Waiting time = %f",sumwt/n);
    
    return 0;
}