#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, st=0,head;
    printf("Enter the number of sequence: ");
    scanf("%d",&n);

    printf("Enter the sequence: ");
    int seq[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&seq[i]);
    }

    printf("Enter the position of head:  ");
    scanf("%d",&head);

    printf("The FCFS seq is : ");

    for (int i = 0; i < n; i++)
    {
        printf("%d\n",seq[i]);
        st=st+abs(head-seq[i]);
        head=seq[i];
    }

    printf("\nTotal seek time is : %d\n", st);

    return 0;
}