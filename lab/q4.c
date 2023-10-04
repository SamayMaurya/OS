


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int PID;
//     int AT;
//     int BT;
//     int TAT;
//     int CT;
//     int WT;
// } Process;

// // Function to calculate the time and tat
// void caltime(Process table[], int n) {
//     int currentTime = 0;

//     for (int i = 0; i < n; i++) {
//         // Set completion time
//         table[i].CT = currentTime + table[i].BT;

//         // Set Tat
//         table[i].TAT = table[i].CT - table[i].AT;

//         // Set waiting time
//         table[i].WT = table[i].TAT - table[i].BT;

//         // Update current time
//         currentTime = table[i].CT;
//     }
// }

// // Main Function
// int main() {
//     int n;
//     printf("Enter the number of Processes: ");
//     scanf("%d", &n);

//     Process Table[n];

//     // Adding values in the table
//     // Values of Number of PID and AT and BT
//     for (int i = 0; i < n; i++) {
//         printf("Enter Process %d details:\n", i + 1);
//         Table[i].PID = i + 1;

//         printf("Arrival Time: ");
//         scanf("%d", &Table[i].AT);

//         printf("Burst Time: ");
//         scanf("%d", &Table[i].BT);
//     }

//     // Now we will sort the processes by AT because of FCFS
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (Table[j].AT > Table[j + 1].AT) {
//                 // Here we swap the processes
//                 Process temp = Table[j];
//                 Table[j] = Table[j + 1];
//                 Table[j + 1] = temp;
//             }
//         }
//     }

//     // Now calculate CT, TAT, and WT
//     caltime(Table, n);

//     // Show the result in tabular format
//     printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d\t%d\t%d\t%d\t%d\t%d\n", Table[i].PID, Table[i].AT, Table[i].BT, Table[i].CT, Table[i].TAT,
//                Table[i].WT);
//     }
//     return 0;
// }






#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int PID;
    int AT;
    int BT;
    int TAT;
    int CT;
    int WT;
} Process;

// Function to calculate the time and tat
void caltime(Process table[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        // Set completion time
        table[i].CT = currentTime + table[i].BT;

        // Set Tat
        table[i].TAT = table[i].CT - table[i].AT;

        // Set waiting time
        table[i].WT = table[i].TAT - table[i].BT;

        // Update current time
        currentTime = table[i].CT;
    }
}

int main() {
    int n;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    Process Table[n];

    // Adding values in the table
    // Values of Number of PID and AT and BT
    for (int i = 0; i < n; i++) {
        printf("Enter Process %d details:\n", i + 1);
        Table[i].PID = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &Table[i].AT);

        printf("Burst Time: ");
        scanf("%d", &Table[i].BT);
    }

    // Now we will sort the processes by AT because of FCFS
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (Table[j].AT > Table[j + 1].AT) {
                // Here we swap the processes
                Process temp = Table[j];
                Table[j] = Table[j + 1];
                Table[j + 1] = temp;
            }
        }
    }

    // Now calculate CT, TAT, and WT
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
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", Table[i].PID, Table[i].AT, Table[i].BT, Table[i].CT, Table[i].TAT,
               Table[i].WT);
    }

    printf("\nIdeal Time: %d\n", idealTime);
    printf("Total Time: %d\n", totalTime);
    printf("Idleness: %d\n", idleness);
    printf("Utilization: %.2f%%\n", utilization);
    printf("Throughput: %.2f processes per unit time\n", throughput);

    return 0;
}
    