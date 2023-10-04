#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int PID;
    int AT;
    int BT;
    int Priority;
    int TAT;
    int CT;
    int WT;
    int remainingTime;

} Process;

void caltime(Process table[], int n, int QT)
{
    int CT = 0;
    int remainingProcess = n;

    int que[n];
    int front = 0;
    int rear = -1;
    while (remainingProcess > 0)
    {
        int indx = que[front]; // front process in quee
        front = (front + 1) % n;
        // current process hoga ise with QT
        if (table[indx].remainingTime > QT)
        {
            CT += QT;
            table[indx].remainingTime -= QT;
        }

        else
        {
            CT += table[indx].remainingTime;
            table[indx].remainingTime = 0;
            table[indx].TAT = CT;
            table[indx].WT = table[indx].TAT - table[indx].BT;
            remainingProcess--;
        }

        for (int i = 0; i < n; i++)
        {
            if (table[i].remainingTime > 0 && table[i].AT <= CT)
            {
                que[++rear] = i;
            }
        }

        if (table[indx].remainingTime > 0)
        {
            que[++rear] = indx;
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

    caltime(Table, n, timeQuantum);

    printf("\nPID\tAT\tBT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", Table[i].PID, Table[i].AT, Table[i].BT, Table[i].TAT, Table[i].WT);
    }
    return 0;
}
