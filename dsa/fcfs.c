#include <stdio.h>

int main()
{
    int n, bt[20], wt[20], tat[20], i;
    float avwt = 0, avtat = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculation for FCFS (Non-preemptive, Arrival=0)
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1]; // Wait time = Cumulative previous burst
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i]; // TAT = WT + BT
        avwt += wt[i];
        avtat += tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", avwt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avtat / n);

    return 0;
}