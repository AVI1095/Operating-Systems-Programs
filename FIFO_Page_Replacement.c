#include <stdio.h>

int main() {
    int pages[30], frames[10];
    int n, f, i, j, k, flag, pageFaults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    j = 0; // FIFO pointer
    printf("\nPage Reference\tFrames\n");

    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page already exists in any frame
        for (k = 0; k < f; k++) {
            if (frames[k] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // Page fault occurs if page not found
        if (flag == 0) {
            frames[j] = pages[i];
            j = (j + 1) % f;
            pageFaults++;
        }

        // Display current frame status
        printf("%d\t\t", pages[i]);
        for (k = 0; k < f; k++) {
            if (frames[k] == -1)
                printf("- ");
            else
                printf("%d ", frames[k]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}