//C Program to demonstrate the working of fork() system call

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        printf("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // This code runs in the child process
        printf("Child process (PID %d)\n", getpid());
    } else {
        // This code runs in the parent process
        printf("Parent process (PID %d) created a child process (PID %d)\n", getpid(), child_pid);
    }

    return 0;
}
