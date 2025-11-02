#include<stdio.h>
int main(){
    int n;
    printf("\n Enter no of processes :");
    scanf("%d",&n);
    int pid[n],at[n],bt[n],ct[n],wt[n],tat[n];
    for(int i=0;i<n;i++){
        pid[i] = i+1;
        printf("\n Enter the arrival time of the process %d:",pid[i]);
        scanf("%d",&at[i]);
    }
    for(int i=0;i<n;i++){
        printf("\n Enter the burst time of the process %d:",pid[i]);
        scanf("%d",&bt[i]);
    }
    // sort the processes according to its arrival time - bubble sort
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(at[i]>at[j]){
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }
    // completion time  of first arrived process is simply adding its arrival time and burst time
    ct[0] = at[0] + bt[0];
    for(int i=1;i<n;i++){
        if(at[i]>ct[i-1]){ // when arrival time of i-th process is greater than completion time of previous process, processes arrives one by one
            ct[i] = bt[i] + at[i];
        }
        else{ // when the second process arrives before the compldetion of the previous process 
            ct[i] = bt[i] + ct[i-1];
        }
    }

    // tat,wt calculation 
    for(int i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // average wt calculation
    int sumWt = 0;
    int sumTat = 0;
    for(int i=0;i<n;i++){
        sumWt += wt[i];
        sumTat += tat[i];
    }

    float avgWt = sumWt/n;
    float avgTat = sumTat/n;
    printf("\n Average waiting time = %f",avgWt);
    printf("\n Average waiting time = %f",avgTat);

}