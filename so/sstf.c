#include <stdio.h>
#include <stdlib.h>
#define LOW 0
#define HIGH 199

int main()
{
    int n, seektime = 0, head, temp, max;

    printf("Enter the number of sequences: ");
    scanf("%d", &n);

    int seq[n];

    printf("Enter the sequences: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &seq[i]);
    }

    printf("Enter the position of the head: ");
    scanf("%d", &head);

    seq[n] = head; // add RW head into the queue
    n++;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (seq[i] > seq[j])
            {
                temp = seq[i];
                seq[i] = seq[j];
                seq[j] = temp;
            }
        }
    }

    max = seq[n - 1];

    printf("The SCAN Sequence is: ");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", seq[j]);
    }

    seektime = 2 * max - head;

    printf("\nTotal Seek Time is: %d\n", seektime);

    return 0;
}
