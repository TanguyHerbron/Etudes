#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

typedef struct {
    float temp;
    int press;
    char ordre;
}uneStruct;

int main()
{
    int shmid, loop = 0;
    char *shm;
    uneStruct *sharedStruct;
    key_t clef;

    clef = ftok("/tmp/bidon", 1234);
    shmid = shmget(clef, sizeof(uneStruct), IPC_CREAT | 0666);
    if(shmid < 0)
    {
        perror("Erreur shmget");
        exit(EXIT_FAILURE);
    }
    sharedStruct = shmat(shmid, NULL, 0);

    while(1)
    {
        loop++;
        printf("Loop %d\t|%d\t|%f\t| %c\n", loop, sharedStruct->temp, sharedStruct->press, sharedStruct->ordre);
        usleep(999999);
    }
    return 0;
}
