#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int PID;
    int AT;            // Arrival Time
    int BT;            // Burst Time
    int TAT;           // Turnaround Time
    int WT;            // Waiting Time
    int remainingTime; // Remaining Burst Time for Round Robin
} Process;

// Function to calculate the time and tat using Round Robin
void caltime(Process table[], int n, int timeQuantum)
{
    int currentTime = 0;
    int remainingProcesses = n;

    // Create a circular queue to keep track of the processes
    int queue[n];
    int front = 0, rear = -1;

    while (remainingProcesses > 0)
    {
        int idx = queue[front]; // Get the front process from the queue
        front = (front + 1) % n;

        // Process the current process with the time quantum
        if (table[idx].remainingTime > timeQuantum)
        {
            currentTime += timeQuantum;
            table[idx].remainingTime -= timeQuantum;
        }
        else
        {
            currentTime += table[idx].remainingTime;
            table[idx].remainingTime = 0;
            table[idx].TAT = currentTime;
            table[idx].WT = table[idx].TAT - table[idx].BT;
            remainingProcesses--;
        }

        // Enqueue the processes that have arrived and not completed
        for (int i = 0; i < n; i++)
        {
            if (table[i].remainingTime > 0 && table[i].AT <= currentTime)
            {
                queue[++rear] = i;
            }
        }

        //  Denqueue the current process if it's not completed
        if (table[idx].remainingTime > 0)
        {
            queue[++rear] = idx;
        }
    }
}

int main()
{
    int n, timeQuantum;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    Process Table[n];

    // Adding values in the table
    // Values of Number of PID, AT, and BT
    for (int i = 0; i < n; i++)
    {
        printf("Enter Process %d details:\n", i + 1);
        Table[i].PID = i + 1;

        printf("Arrival Time: "); // Add Arrival Time input
        scanf("%d", &Table[i].AT);

        printf("Burst Time: ");
        scanf("%d", &Table[i].BT);
        Table[i].remainingTime = Table[i].BT;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    // Calculate CT, TAT, and WT using Round Robin
    caltime(Table, n, timeQuantum);

    // Show the result in tabular format
    printf("\nPID\tAT\tBT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", Table[i].PID, Table[i].AT, Table[i].BT, Table[i].TAT, Table[i].WT);
    }

    return 0;
}



/*



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int PID;
    int AT;
    int BT;
    int Priority;
    int TAT;
    int CT;
    int WT;
    int remainingTime;
} Process;

void enqueue(Process queue[], int *rear, Process process) {
    queue[++(*rear)] = process;
}

Process dequeue(Process queue[], int *front, int *rear) {
    if (*front > *rear) {
        Process emptyProcess;
        emptyProcess.PID = -1;
        return emptyProcess; // Return an empty process if the queue is empty
    }
    return queue[(*front)++];
}

int main() {
    int n;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    Process Table[n];
    Process readyQueue[n]; // Create a ready queue for storing ready processes
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        printf("Enter Process %d details:\n", i + 1);
        Table[i].PID = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &Table[i].AT);

        printf("Burst Time: ");
        scanf("%d", &Table[i].BT);

        printf("Priority: ");
        scanf("%d", &Table[i].Priority);

        Table[i].remainingTime = Table[i].BT;
    }

    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        // Check for arriving processes and enqueue them in the ready queue
        for (int i = 0; i < n; i++) {
            if (Table[i].AT == currentTime) {
                enqueue(readyQueue, &rear, Table[i]);
            }
        }

        int highestPriorityProcess = -1;
        int highestPriority = INT_MAX;

        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                if (readyQueue[i].Priority < highestPriority) {
                    highestPriority = readyQueue[i].Priority;
                    highestPriorityProcess = i;
                }
            }
        }

        if (highestPriorityProcess == -1) {
            currentTime++;
        } else {
            Process currentProcess = dequeue(readyQueue, &front, &rear);
            int idx = currentProcess.PID - 1;
            Table[idx].remainingTime--;

            currentTime++;

            if (Table[idx].remainingTime == 0) {
                completed++;
                Table[idx].CT = currentTime;
                Table[idx].TAT = Table[idx].CT - Table[idx].AT;
                Table[idx].WT = Table[idx].TAT - Table[idx].BT;
            } else {
                // Re-enqueue the process with reduced remaining time
                enqueue(readyQueue, &rear, Table[idx]);
            }
        }
    }

    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d \t  \t%d\t%d\t%d\n", Table[i].PID, Table[i].AT, Table[i].BT, Table[i].Priority,
               Table[i].CT, Table[i].TAT, Table[i].WT);
    }
    return 0;
}





*/