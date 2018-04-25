#include <stdio.h>
#include <conio.h>
#include <stdbool.h> 

void WaitingTime(int processes[], int n, int bt[], int wt[], int quantum)  // Function to find the waiting time for all processes
{
     
    int rem_bt[n],i;                         // Make a copy of burst times bt[] to store remaining burst times.
    for (i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];
 
    int t = 0;
    while (1)
    {
        bool done = true;
 

        for (i = 0 ; i < n; i++)                 // Traverse all processes one by one repeatedly
        {
            
            if (rem_bt[i] > 0)                  //  If burst time of a process is greater than 0  then only need to process further 
            {
                done = false;                 // There is a pending process
 
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
 
                    wt[i] = t - bt[i];
 
                    rem_bt[i] = 0;
                }
            }
        }
 
        
        if (done == true)                    // If all processes are done
          break;
    }
}
 

void TurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[])   // Function to calculate turn around time
{
	int i;
    
    for (i = 0; i < n ; i++)  
	{                          
        tat[i] = bt[i] + wt[i];                      // calculating turnaround time by adding Burst Time and Waiting Time
    }
}
 

void AvgTime(int processes[], int n, int bt[],int quantum)     // Function to calculate average time
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0,i;
     
    WaitingTime(processes, n, bt, wt, quantum);    // Function to find waiting time of all processes 
    
    TurnAroundTime(processes, n, bt, wt, tat);      // Function to find turn around time for all processes
     
    printf("Processes(ID)   Burst time   Waiting time   Turn Around time");   // Display processes along with all details
    printf("\n----------------------------------------------------------");
 
    for (i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("\n  %d\t\t %d\t\t %d\t\t %d",i+1 ,bt[i] ,  wt[i] , tat[i]);   // Calculate total waiting time and total turn around time
    }
        printf("\n----------------------------------------------------------");
    printf("\n\nAverage waiting time = %f", (float)total_wt / (float)n);
    printf("\nAverage turn around time = %f", (float)total_tat / (float)n);
    printf("\n\n\t\t\t\t\tThank You");
    printf("\n\t\t\t\t\tSk Maifuj Alam ");
    printf("\n\t\t\t\t\tB-32 (11603117) ");
    
}
 
int main()
{
    int processes[] = { 1, 2, 3, 4};                          // process id's
    int n = sizeof processes / sizeof processes[0];           //Number of Processes
    int burst_time[] = {20, 36, 19, 42};                      // Burst time of all processes 
    int quantum = 10;                                         // Time quantum
    AvgTime(processes, n, burst_time, quantum);
    return 0;
}
