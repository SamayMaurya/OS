

// Practical No. 03
//Write a program to implement zombie process & orphan proces
//ZOMBIE PROCESS :-
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <unistd.h>
// int main()
// {

//     pid_t child_pid = fork();

//     if (child_pid > 0)
//     {
//         printf("parent process");
//         sleep(10);
//     }

//     else
//     {
//         printf("child process \n");
//         exit(0);
//     }

//     return 0;
// }



#include <stdio.h>
#include <unistd.h>
int main()
{
    int x = fork();
    if (x == 0)
    {
        sleep(2);
        printf("\nIt is an orphan process.... as parent has executed earlier\n");
        printf("it is child process\n");
        printf("Child is terminated\n");
    }
    else
    {
        printf("It is parent process\n");
        printf("Parent is terminated\n");
    }
}
