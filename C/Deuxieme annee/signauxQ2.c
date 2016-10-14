#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void traitement(int sig)
{

        (void ) signal(SIGUSR1, traitement);
        printf("Un signal SIGUSR1 ppid : %d %d\n", getppid(), getpid());
}

int main(int argc, char *argv[])
{
    int pid;
    int pid2;
    int pid2temp;
    (void) signal(SIGUSR1, traitement);
    pid = fork();
    pid2temp = pid;

    if (pid == -1)
    {
        printf("pb creation fork : %s\n", strerror(errno));
        exit(1);
    }
    else
    {
        if (pid == 0)		// process fils
        {
            pid2 = fork();
            if(pid2 == -1)
            {
                printf("Pb creation fork :%s\n", strerror(errno));
                exit(1);
            }
            else
            {
                if(pid2 == 0)// Process fils du fils
                {
                    printf("fils P3 pid=%d\n", getpid());
                    kill(pid2temp, SIGUSR1);
                    sleep(2);                    // tempo pour être certain que le fils sera
                    //encore vivant quand le pere lui
                    //enverra son signal
                }
                else //process fils
                {
                    printf("fils P2 pid=%d\n", getpid());
                    sleep(2);                    // tempo pour être certain que le fils sera
                    //encore vivant quand le pere lui
                    //enverra son signal
                }
            }

        }
        else		// process principal (pere)
        {
            kill(pid2temp, SIGUSR1);
            printf("pere pid=%d\n", getpid());
            sleep(2);	// tempo pour être certain que le pere sera
            //encore vivant quand le fils lui
            //enverra son signal
        }
    }

    return EXIT_SUCCESS;
}
