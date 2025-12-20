#include<stdio.h>
int main(){
    int n;
    printf("\n Enter no. of processes :");
    scanf("%d",&n);
    // initializing all arrays
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n];
    // taking input of Arrival times of all processes
    for(int i=0;i<n;i++){
        pid[i] = i+1;
        printf("\n Enter the arrival time of process %d:",pid[i]);
        scanf("%d",&at[i]);
    }
    // taking input of Burst time of all processes
    for(int i=0;i<n;i++){
        printf("\n Enter the burst time of process %d:",pid[i]);
        scanf("%d",&bt[i]);
    }
    // sort the processes according to their arrival times -- Bubble sort 
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
    // Completion time of the first arrived process will be simply addition of its arrival time and burst time 
    ct[0] = at[0] + bt[0];
    // completion of the other processes 
    for(int i=1;i<n;i++){
        // when processes come one by one (at of current process > ct of previous process) --> sekhetre ager process er sathe er kono len den nei 
        // tai current process er ct hobe simply addition of e kokhon aslo + er kotokkhon lagbe sesh hote 
        if(at[i]>ct[i-1]){
            ct[i] = at[i] + bt[i];
        }
        // if current process arrives before the completion of previous process ---> then current er ct hobe ager process er ct + er bt 
        else{
            ct[i] = ct[i-1] + bt[i];
        }
    }
    // tat , wt calculation 
    for(int i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    // average tat & wt calculation 
    float sumwt = 0;
    float sumtat = 0;
    for(int i=0;i<n;i++){
        sumwt += wt[i];
        sumtat += tat[i];
    }
    float avgWt = sumwt/n;
    float avgTat = sumtat/n;
    printf("\n Average waiting time = %f",avgWt);
    printf("\n Average turn around time = %f",avgTat);
}