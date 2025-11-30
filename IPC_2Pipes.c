#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 100

int main() {
    int pipe1[2], pipe2[2];
    char parent_msg[MAX], child_msg[MAX];
    pid_t pid;

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        close(pipe1[0]);
        close(pipe2[1]);

        printf("Parent: Enter message for child: ");
        fgets(parent_msg, sizeof(parent_msg), stdin);
        parent_msg[strcspn(parent_msg, "\n")] = '\0';

        write(pipe1[1], parent_msg, strlen(parent_msg) + 1);

        read(pipe2[0], child_msg, sizeof(child_msg));
        printf("Parent received: %s\n", child_msg);

        close(pipe1[1]);
        close(pipe2[0]);
        wait(NULL);
    } else {
        close(pipe1[1]);
        close(pipe2[0]);

        read(pipe1[0], child_msg, sizeof(child_msg));
        printf("Child received: %s\n", child_msg);

        printf("Child: Enter reply for parent: ");
        fgets(parent_msg, sizeof(parent_msg), stdin);
        parent_msg[strcspn(parent_msg, "\n")] = '\0';

        write(pipe2[1], parent_msg, strlen(parent_msg) + 1);

        close(pipe1[0]);
        close(pipe2[1]);
        exit(0);
    }

    return 0;
}