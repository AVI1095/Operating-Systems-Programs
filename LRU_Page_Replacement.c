#include <stdio.h>

int main() {
    int pages[30], frames[10], temp[10];
    int n, f, i, j, k, pos, pageFaults = 0, least;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage Reference\tFrames\n");

    for (i = 0; i < n; i++) {
        int flag1 = 0, flag2 = 0;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    pageFaults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            for (j = 0; j < f; j++) {
                temp[j] = 0;
                for (k = i - 1; k >= 0; k--) {
                    if (frames[j] == pages[k]) {
                        temp[j] = k;
                        break;
                    }
                }
            }

            least = temp[0];
            pos = 0;
            for (j = 1; j < f; j++) {
                if (temp[j] < least) {
                    least = temp[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            pageFaults++;
        }

        printf("%d\t\t", pages[i]);
        for (j = 0; j < f; j++) {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}