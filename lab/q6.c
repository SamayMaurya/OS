#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int PID;
    int AT;
    int BT;
    int TAT;
    int CT;
    int WT;
    int remainingTime;  // Remaining burst time for SRTF
} Process;

// Function to calculate the time and tat
void caltime(Process table[], int n) {
    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        int shortestProcess = -1;
        int shortestTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (table[i].AT <= currentTime && table[i].remainingTime < shortestTime && table[i].remainingTime > 0) {
                shortestProcess = i;
                shortestTime = table[i].remainingTime;
            }
        }

        if (shortestProcess == -1) {
            currentTime++;
        } else {
            int idx = shortestProcess;
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

    // Adding values in the table
    // Values of Number of PID and AT and BT
    for (int i = 0; i < n; i++) {
        printf("Enter Process %d details:\n", i + 1);
        Table[i].PID = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &Table[i].AT);

        printf("Burst Time: ");
        scanf("%d", &Table[i].BT);

        Table[i].remainingTime = Table[i].BT;
    }

    // Now calculate CT, TAT, and WT using SRTF
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













// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h> 

// typedef struct {
//     int PID;
//     int AT;
//     int BT;
//     int TAT;
//     int CT;
//     int WT;
//     int remainingTime;  // Remaining burst time for SRTF
// } Process;

// // Function to calculate the time and tat
// void caltime(Process table[], int n) {
//     int currentTime = 0;
//     int completed = 0;

//     while (completed < n) {
//         int shortestProcess = -1;
//         int shortestTime = INT_MAX;

//         for (int i = 0; i < n; i++) {
//             if (table[i].AT <= currentTime && table[i].remainingTime < shortestTime && table[i].remainingTime > 0) {
//                 shortestProcess = i;
//                 shortestTime = table[i].remainingTime;
//             }
//         }

//         if (shortestProcess == -1) {
//             currentTime++;
//         } else {
//             int idx = shortestProcess;
//             table[idx].remainingTime--;
//             currentTime++;

//             if (table[idx].remainingTime == 0) {
//                 completed++;
//                 table[idx].CT = currentTime;
//                 table[idx].TAT = table[idx].CT - table[idx].AT;
//                 table[idx].WT = table[idx].TAT - table[idx].BT;
//             }
//         }
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
//         scanf("%d", &Table[i]   .AT);

//         printf("Burst Time: ");
//         scanf("%d", &Table[i].BT);

//         Table[i].remainingTime = Table[i].BT;
//     }

//     // Now calculate CT, TAT, and WT using SRTF
//     caltime(Table, n);

//     // Show the result in tabular format
//     printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d\t%d\t%d\t%d\t%d\t%d\n", Table[i].PID, Table[i].AT, Table[i].BT, Table[i].CT, Table[i].TAT,
//                Table[i].WT);
//     }
//     return 0;
// }
