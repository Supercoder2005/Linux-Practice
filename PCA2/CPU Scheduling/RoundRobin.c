#include<stdio.h>
int main(){
    int i,n,qt;
    printf("\n Enter total no of process :");
    scanf("%d",&n);
    printf("\n Enter the quantam time :");
    scanf("%d",&qt);
    int count = 0; // count = total no of completed process
    int time = 0; // keep tracks of the current unit of time
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n],rt[n];
    float avgWt = 0,avgTat=0;
    // input taking 
    for(i=0;i<n;i++){
        pid[i] = i+1;
        printf("\n Enter arrival time of process %d :",pid[i]);
        scanf("%d",&at[i]);
    }
    for(i=0;i<n;i++){
        printf("\n Enter burst time of process %d :",pid[i]);
        scanf("%d",&bt[i]);
        // initalize the remaining time and completion time of each process
        rt[i] = bt[i];
        ct[i] = 0;
    }
    // round robin starts from here
    while(count < n){ // the loop continues untill all processes are completed
        int executed = 0; // keep tracks of whether a process is ready to execute or not, initially not ready
        for(i=0;i<n;i++){
            // when a process arrives before or just at the current time and that process has also some remaining burst time 
            // then only the process will be executable 
            if(at[i]<=time && rt[i]>0){
                executed = 1;
                //if the remaining time is greater than quantam time then process will be executed for only the qt 
                //and remaining time will decrease by that amount of qt.
                if(rt[i]>qt) {
                    rt[i] -= qt;
                    time += qt;
                }
                //if the remaining time is less than quantam time then process will be executed for only the rt
                else{
                    time += rt[i];
                    rt[i] = 0;
                    // caluclating the ct,tat,wt of that process
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    
                    avgWt += wt[i];
                    avgTat += tat[i];

                    // one more process is completed 
                    count ++;
                }
            }
        }
        // when no more process is inside the cpu , idle condition
        if(executed == 0){
            time++;
        }
    }
    // display the output 
    printf("\n ProcessId\tArrivalTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime");
    for(i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n Average waiting time :%f",avgWt/n);
    printf("\n Average turn around time :%f",avgTat/n);
    return 0;
}