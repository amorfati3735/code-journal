#include <stdio.h>
#include <stdlib.h>

int n, m; // n = processes, m = resources
int alloc[10][10], max[10][10], need[10][10];
int avail[10];
int safeseq[10];

// Function to calculate Need Matrix
void calculateNeed()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

// Safety Algorithm to check if system is in safe state
int isSafeState(int current_avail[])
{
    int work[10], finish[10] = {0};
    int count = 0;

    // Copy available to work
    for (int i = 0; i < m; i++)
        work[i] = current_avail[i];

    while (count < n)
    {
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            { // If process not finished
                int j;
                // Check if Need <= Work
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == m)
                { // If requirements met
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safeseq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0)
            return 0; // System is not safe
    }
    return 1; // System is safe
}

int main()
{
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("Enter Max Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    printf("Enter Available Resources: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    calculateNeed();

    // Initial Safety Check
    if (isSafeState(avail))
    {
        printf("\nSystem is in SAFE State.\nSafe Sequence: ");
        for (int i = 0; i < n; i++)
            printf("P%d ", safeseq[i]);
        printf("\n");
    }
    else
    {
        printf("\nSystem is in UNSAFE State (Potential Deadlock).\n");
        return 0;
    }

    // Resource Request Algorithm
    int pid, req[10];
    char ch;

    printf("\nDo you want to make an additional request? (y/n): ");
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y')
    {
        printf("Enter Process ID (0 to %d): ", n - 1);
        scanf("%d", &pid);
        printf("Enter Request Vector: ");
        for (int i = 0; i < m; i++)
            scanf("%d", &req[i]);

        // Check 1: Request <= Need
        for (int i = 0; i < m; i++)
        {
            if (req[i] > need[pid][i])
            {
                printf("Error: Request exceeds Need.\n");
                return 0;
            }
        }

        // Check 2: Request <= Available
        for (int i = 0; i < m; i++)
        {
            if (req[i] > avail[i])
            {
                printf("Error: Resources not available.\n");
                return 0;
            }
        }

        // Pretend to allocate
        for (int i = 0; i < m; i++)
        {
            avail[i] -= req[i];
            alloc[pid][i] += req[i];
            need[pid][i] -= req[i];
        }

        if (isSafeState(avail))
        {
            printf("\nRequest Granted. System remains Safe.\nSafe Sequence: ");
            for (int i = 0; i < n; i++)
                printf("P%d ", safeseq[i]);
            printf("\n");
        }
        else
        {
            printf("\nRequest Denied. Granting leads to Unsafe State.\n");
            // Rollback (Optional strictly speaking, but good practice)
        }
    }

    return 0;
}