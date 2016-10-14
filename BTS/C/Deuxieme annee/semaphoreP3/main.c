#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include "semtools.h"

typedef struct
{
    float temp;
    int press;
    char ordre;
} uneStruct;

int main()
{
    int shmid, loop = 0;
    uneStruct *sharedStruct;
    key_t clef;

    clef = ftok("/tmp/bidon", 5678);
    shmid = shmget(clef, sizeof(uneStruct), IPC_CREAT | 0666);
    if(shmid < 0)
    {
        perror("Erreur shmget");
        exit(EXIT_FAILURE);
    }

    //debut sem
    id_sem = semget (5678, 1, IPC_CREAT | 0600);
    if (id_sem == -1)
    {
        printf("pb semget: %s\n",strerror(errno));
        if (errno!=EEXIST)
        {
            exit(errno);
        }
    }
    if ( fixe_valeursem()== 0)
    {
        exit ( 0 );
    }
    //fin init sem

    sharedStruct = shmat(shmid, NULL, 0);

    while(1)
    {
        if(P() == 1)
        {
            printf("Loop %d\t|%d\t|%f\t| %c\n", loop, sharedStruct->temp, sharedStruct->press, sharedStruct->ordre);

            if(V() == 0)
            {
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            exit(EXIT_FAILURE);
        }
        loop++;
        usleep(999999);
    }
    return 0;
}
