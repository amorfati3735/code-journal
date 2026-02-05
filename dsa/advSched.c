#include <stdio.h>
#include <limits.h>

struct Process
{
    int pid;
    int at;       // Arrival Time
    int bt;       // Burst Time
    int rem_bt;   // Remaining Burst Time
    int priority; // Priority (Lower value = Higher priority)
    int ct, wt, tat;
};

int n;
struct Process p[20];

// Helper to reset remaining burst times before running a new algo
void reset_processes()
{
    for (int i = 0; i < n; i++)
    {
        p[i].rem_bt = p[i].bt;
    }
}

void print_table()
{
    int total_wt = 0, total_tat = 0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAvg Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAvg Turnaround Time: %.2f\n", (float)total_tat / n);
}

// --- 1. Round Robin Algorithm ---
void round_robin(int quantum)
{
    reset_processes();
    int time = 0, completed = 0;
    int queue[100], front = 0, rear = 0;
    int visited[20] = {0};

    // Push first process (assuming sorted by AT or AT=0)
    // For simplicity, checking all processes initially
    if (p[0].at <= time)
    {
        queue[rear++] = 0;
        visited[0] = 1;
    }

    while (completed < n)
    {
        if (front == rear)
        { // Queue empty
            time++;
            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && p[i].at <= time)
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++]; // Dequeue

        if (p[idx].rem_bt > quantum)
        {
            time += quantum;
            p[idx].rem_bt -= quantum;
        }
        else
        {
            time += p[idx].rem_bt;
            p[idx].rem_bt = 0;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        }

        // Check for new arrivals
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && p[i].at <= time)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        // If process not finished, enqueue again
        if (p[idx].rem_bt > 0)
        {
            queue[rear++] = idx;
        }
    }
    print_table();
}

// --- 2. SRTF (Preemptive SJF) ---
void srtf()
{
    reset_processes();
    int time = 0, completed = 0, min_idx;
    int min_bt = INT_MAX;
    int shortest = -1;
    int finish_time;

    // Run until all processes complete
    while (completed != n)
    {
        shortest = -1;
        min_bt = INT_MAX;

        // Find process with min remaining time among arrived ones
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= time && p[i].rem_bt > 0 && p[i].rem_bt < min_bt)
            {
                min_bt = p[i].rem_bt;
                shortest = i;
            }
        }

        if (shortest == -1)
        {
            time++;
            continue;
        }

        // Process found, execute for 1 unit
        p[shortest].rem_bt--;
        time++;

        if (p[shortest].rem_bt == 0)
        {
            completed++;
            p[shortest].ct = time;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
        }
    }
    print_table();
}

// --- 3. Preemptive Priority ---
void preemptive_priority()
{
    reset_processes();
    int time = 0, completed = 0;
    int highest_pri_val = INT_MAX; // Lower value = higher priority
    int selected = -1;

    while (completed != n)
    {
        selected = -1;
        highest_pri_val = INT_MAX;

        // Find process with highest priority (lowest number) among arrived
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= time && p[i].rem_bt > 0 && p[i].priority < highest_pri_val)
            {
                highest_pri_val = p[i].priority;
                selected = i;
            }
        }

        if (selected == -1)
        {
            time++;
            continue;
        }

        // Execute for 1 unit
        p[selected].rem_bt--;
        time++;

        if (p[selected].rem_bt == 0)
        {
            completed++;
            p[selected].ct = time;
            p[selected].tat = p[selected].ct - p[selected].at;
            p[selected].wt = p[selected].tat - p[selected].bt;
        }
    }
    print_table();
}

int main()
{
    int choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("P%d -> Enter Arrival Time, Burst Time, Priority: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
    }

    while (1)
    {
        printf("\n1. Round Robin\n2. SRTF\n3. Preemptive Priority\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Time Quantum: ");
            scanf("%d", &quantum);
            printf("\n--- Round Robin ---\n");
            round_robin(quantum);
            break;
        case 2:
            printf("\n--- SRTF ---\n");
            srtf();
            break;
        case 3:
            printf("\n--- Preemptive Priority ---\n");
            preemptive_priority();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}