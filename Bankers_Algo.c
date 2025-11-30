#include <stdio.h>

int main() {
    int n, m, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m], available[m];
    int finish[n], safeSequence[n];

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for (j = 0; j < m; j++)
        scanf("%d", &available[j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    for (i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < m; j++)
                    if (need[i][j] > available[j])
                        break;
                if (j == m) {
                    for (k = 0; k < m; k++)
                        available[k] += allocation[i][k];
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("\nSystem is in UNSAFE STATE!\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE STATE.\nSafe Sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSequence[i]);
    printf("\n");

    return 0;
}