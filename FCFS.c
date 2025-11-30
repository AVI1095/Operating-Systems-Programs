#include <stdio.h>

struct Process {
    int pid;
    int at, bt, ct, tat, wt;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
    }

    // Sorting by Arrival Time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int time = 0;
    printf("\nGantt Chart:\n|");

    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            printf(" IDLE |");
            time = p[i].at;
        }
        printf(" P%d |", p[i].pid);
        time += p[i].bt;
        p[i].ct = time;
    }

    printf("\n0");
    time = 0;

    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            printf(" \t%d", p[i].at);
            time = p[i].at;
        }
        time += p[i].bt;
        printf(" %d", time);
    }

    float avg_tat = 0, avg_wt = 0;

    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}