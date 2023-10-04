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

void caltime(Process table[], int n) {
    int currentTime = 0;
    int completed = 0;

    while (completed < n) { 
        int highestPriorityProcess = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (table[i].AT <= currentTime && table[i].remainingTime > 0) {
                if (table[i].Priority < highestPriority) {
                    highestPriority = table[i].Priority;
                    highestPriorityProcess = i;
                }
            }
        }

        if (highestPriorityProcess == -1) {
            currentTime++;
        } 
        
        else {
            int idx = highestPriorityProcess;
            table[idx].remainingTime--;
            currentTime++;

            if (table[idx].remainingTime == 0) {
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

    caltime(Table, n);

    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d \t  \t%d\t%d\t%d\n", Table[i].PID, Table[i].AT, Table[i].BT, Table[i].Priority,
               Table[i].CT, Table[i].TAT, Table[i].WT);
    }
    return 0;
}
