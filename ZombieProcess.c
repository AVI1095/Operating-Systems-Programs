#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    if ((pid = fork()) < 0) {
        printf("Fork error\n");
    } else if (pid == 0) {
        printf("Child process id: %d\n", getpid());
    } else {
        sleep(5);
        printf("*** Parent Process ***\n");
        system("ps -axj | tail");
        // ps lists processes running on the system.
        //-a shows processes for all users.
        //-x includes processes not attached to a terminal.
        //-j shows the process in job format, which includes columns like PID, PPID, state, etc.
        // |tail displays default last 10 lines
    }

    return 0;
}