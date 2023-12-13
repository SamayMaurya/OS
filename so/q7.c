#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct {
    int PID;
    int AT; // Arrival Time
    int BT; // Burst Time
    int Priority;
    int TAT; // Turnaround Time
    int CT;  // Completion Time
    int WT;  // Waiting Time
    int RT;
} Process;

// Function to calculate the time and tat using Priority Scheduling
void caltime(Process table[], int n) {
    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        int highestPriorityProcess = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (table[i].AT <= currentTime && table[i].Priority < highestPriority && table[i].RT > 0) {
                highestPriority = table[i].Priority;
                highestPriorityProcess = i;
            }
        }

        if (highestPriorityProcess == -1) {
            currentTime++;
        } else {
            int idx = highestPriorityProcess;
            table[idx].RT--;
            currentTime++;

            if (table[idx].RT == 0) {
                completed++;
                table[idx].CT = currentTime;
                table[idx].TAT = table[idx].CT - table[idx].AT;
                table[idx].WT = table[idx].TAT - table[idx].BT;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    Process Table[n];

    // Adding values in the table
    // Values of Number of PID, AT, BT, and Priority
    for (int i = 0; i < n; i++) {
        printf("Enter Process %d details:\n", i + 1);
        Table[i].PID = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &Table[i].AT);

        printf("Burst Time: ");
        scanf("%d", &Table[i].BT);

        printf("Priority: ");
        scanf("%d", &Table[i].Priority);

        Table[i].RT= Table[i].BT;
        
    }

    // Calculate CT, TAT, and WT using Priority Scheduling
    caltime(Table, n);

    // Calculate ideal time, total time, idleness, utilization, and throughput
    int idealTime = 0;
    int totalTime = 0;

    for (int i = 0; i < n; i++) {
        idealTime += Table[i].BT;
        totalTime += Table[i].CT;
    }

    int idleness = totalTime - idealTime;
    float utilization = ((float)idealTime / totalTime) * 100;
    float throughput = (float)n / totalTime;

    // Show the result in tabular format
    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", Table[i].PID, Table[i].AT, Table[i].BT, Table[i].Priority,
               Table[i].CT, Table[i].TAT, Table[i].WT);
    }

    printf("\nIdeal Time: %d\n", idealTime);
    printf("Total Time: %d\n", totalTime);
    printf("Idleness: %d\n", idleness);
    printf("Utilization: %.2f%%\n", utilization);
    printf("Throughput: %.2f processes per unit time\n", throughput);

    return 0;
}