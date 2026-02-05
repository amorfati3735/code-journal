#include <stdio.h>

int main()
{
    int n, p[20], bt[20], wt[20], tat[20], i, j, temp;
    float avwt = 0, avtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++)
    {
        p[i] = i + 1; // Process ID
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sorting by Burst Time (Ascending)
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                // Swap Burst Time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                // Swap Process ID to keep track
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculation
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", avwt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avtat / n);

    return 0;
}