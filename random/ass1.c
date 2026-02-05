#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        execlp("ls", "ls", "-l", NULL);

        // execlp only returns if error occurs
        perror("execlp");
        exit(1);
    } 
    else {
        // Parent process
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        } else {
            printf("Child did not terminate normally\n");
        }
    }

    return 0;
}
