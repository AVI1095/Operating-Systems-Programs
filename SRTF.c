#include <stdio.h>
#include <limits.h>

struct Process {
    int id;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n, i, completed = 0, time = 0, min_index;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time of P%d: ", p[i].id);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time of P%d: ", p[i].id);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
    }

    while (completed < n) {
        int min_rt = INT_MAX;
        min_index = -1;

        for (i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].rt < min_rt) {
                min_rt = p[i].rt;
                min_index = i;
            }
        }

        if (min_index == -1) {
            time++;
            continue;
        }

        p[min_index].rt--;
        time++;

        if (p[min_index].rt == 0) {
            completed++;
            p[min_index].ct = time;
            p[min_index].tat = p[min_index].ct - p[min_index].at;
            p[min_index].wt = p[min_index].tat - p[min_index].bt;
            avg_tat += p[min_index].tat;
            avg_wt += p[min_index].wt;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}