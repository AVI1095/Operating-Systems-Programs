#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void sort_asc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
}
void sort_desc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] < arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork Failed\n");
        free(arr);
        return 1;
    } else if (pid == 0) {
        sort_desc(arr, n);
        printf("Child process descending: ");
        display(arr, n);
    } else {
        sort_asc(arr, n);
        printf("Parent process ascending: ");
        display(arr, n);
    }

    free(arr);
    return 0;
}
