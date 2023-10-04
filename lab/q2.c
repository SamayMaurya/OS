#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // Include sys/wait.h for wait function

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    pid_t child_pid;
    int even_sum = 0, odd_sum = 0;

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        printf("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // This code runs in the child process
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                odd_sum += arr[i];
            }
        }
        printf("Child Process (PID %d) - Sum of Odd Numbers: %d\n", getpid(), odd_sum);
    } else {
        // This code runs in the parent process
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                even_sum += arr[i];
            }
        }
        wait(NULL); // Wait for the child process to finish
        printf("Parent Process (PID %d) - Sum of Even Numbers: %d\n", getpid(), even_sum);
    }

    return 0;
}
