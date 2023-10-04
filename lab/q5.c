


//Non Primitive
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







/*


SJF
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int PID;
    int BT; // Burst Time
    int TAT; // Turnaround Time
    int CT; // Completion Time
    int WT; // Waiting Time
} Process;

// Function to calculate the time and tat
void caltime(Process table[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        // Set completion time
        table[i].CT = currentTime + table[i].BT;

        // Set Turnaround Time
        table[i].TAT = table[i].CT;

        // Set Waiting Time
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
    // Values of Number of PID and BT
    for (int i = 0; i < n; i++) {
        printf("Enter Process %d details:\n", i + 1);
        Table[i].PID = i + 1;

        printf("Burst Time: ");
        scanf("%d", &Table[i].BT);
    }

    // Now we will sort the processes by BT for SJF
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (Table[j].BT > Table[j + 1].BT) {
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

    // Show the result in table format
    printf("\nPID\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", Table[i].PID, Table[i].BT, Table[i].CT, Table[i].TAT, Table[i].WT);
    }

    printf("\nIdeal Time: %d\n", idealTime);
    printf("Total Time: %d\n", totalTime);
    printf("Idleness: %d\n", idleness);
    printf("Utilization: %.2f%%\n", utilization);
    printf("Throughput: %.2f processes per unit time\n", throughput);

    return 0;
}





*/


/*

//Gunjan code

#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int priority;
};

int main() {
    int idleTime=0;
    int totalTime=0;
    int n;
    printf("Enter the total number of processes: ");
    scanf("%d",&n);
    struct Process p[n];
    for (int i=0;i<n;i++) {
        int temp2,tp;
        printf("Enter the burst time for process P%d: ",i+1);
        scanf("%d",&temp2);
        printf("Enter the priority for process P%d: ",i+1);
        scanf("%d",&tp);
        p[i].pid=i+1;
        p[i].at=0;
        p[i].bt=temp2;
        p[i].priority=tp;
    }
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (p[j].priority>p[j+1].priority) {
                struct Process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    p[0].ct=p[0].at+p[0].bt;
    for (int i=1;i<n;i++) {
        if (p[i].at>p[i-1].ct) {
            p[i].ct=p[i].at+p[i].bt;
            idleTime=idleTime+p[i].at-p[i-1].ct;
        }
        else {
            p[i].ct=p[i-1].ct+p[i].bt;
        }
    }
    totalTime=p[n-1].ct;
    for (int i=0;i<n;i++) {
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
    float avg_tat=0,avg_wt=0;
    for (int i=0;i<n;i++) {
        avg_tat+=p[i].tat;
        avg_wt+=p[i].wt;
    }
    avg_tat/=n;
    avg_wt/=n;
    float cpuUtilization=((totalTime-idleTime)*100.0)/(float)totalTime;
    float throughput = (float)n/totalTime;
    printf("pid   at   bt   priority   ct   tat   wt\n");
    for (int i=0;i<n;i++) {
        printf(" P%d    %d    %d    %d    %d    %d    %d\n", p[i].pid, p[i].at, p[i].bt, p[i].priority,
               p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Average tat: %f   Average wt: %f\n",avg_tat,avg_wt);
    printf("CPU utilization: %f   Throughput: %f\n",cpuUtilization,throughput);
    return 0;

}



*/