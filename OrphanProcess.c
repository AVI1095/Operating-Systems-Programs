#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    int pid = fork();
    if (pid > 0) {
        printf("Parent process id: %d\n", getpid());
        printf("Child process id: %d\n", pid);
        exit(0);
    } else if (pid == 0) {
        sleep(5);
        printf("\nChild process id: %d\n", getpid());
        printf("Parent process id (should be 1): %d\n", getppid());
    }
    return 0;
}

