#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "semtools.h"

typedef struct
{
    float temp;
    int press;
    char ordre;
} uneStruct;

char randomC()
{
    return ((char)126.0*(rand()/(RAND_MAX+0.1)));
}

int main()
{
    uneStruct *memShare;
    int shmid;
    key_t clef;
    void *shm;

    clef = ftok("/tmp/bidon", 5678);
    shmid = shmget(clef, sizeof(uneStruct), 0666);
    if(shmid < 0)
    {
        perror("Erreur shmget");
        exit(EXIT_FAILURE);
    }

    //debut sem
    id_sem = semget (5678, 1, IPC_CREAT | 0600);
    if (id_sem == -1)
    {
        printf("Probleme semget : %s\n", strerror(errno));
        if(errno != EEXIST)
        {
            exit(errno);
        }
    }
    if(fixe_valeursem() == 0)
    {
        exit(0);
    }
    //fin init sem

    memShare = shmat(shmid, NULL, 0);

    while(1)
    {
        if(P() == 1)
        {
            memShare->ordre = randomC();
            printf("Memoire mise a jour.\nVal->\n\tordre : %c\n\n", memShare->ordre);


            if(V() == 0)
            {
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            exit(EXIT_FAILURE);
        }
        usleep(999999);
    }
}
