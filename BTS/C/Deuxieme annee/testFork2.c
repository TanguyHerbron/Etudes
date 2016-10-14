#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pid1, pid2, pid3;
    pid1 = fork();
    if (pid1 == 0)
    {
        printf("p1\n");
    }
    else
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            printf("p2\n");
        }
        else
        {
            pid3 = fork();
            if (pid3 == 0)
            {
                printf("p3\n");
            }
            else
            {
                printf("p4\n");
            }
        }
    }
    return 0;
}
