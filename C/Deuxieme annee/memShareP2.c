#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    float temp;
    int press;
    char ordre;
}uneStruct;

char randomC(){
	return ((char)126.0*(rand()/(RAND_MAX+0.1)));
}

int main()
{
    uneStruct *memShare;
    int shmid;
    key_t clef;
    void *shm;

    clef = ftok("/tmp/bidon", 1234);
    shmid = shmget(clef, sizeof(uneStruct), 0666);
    if(shmid < 0)
    {
        perror("Erreur shmget");
        exit(EXIT_FAILURE);
    }

    memShare = shmat(shmid, NULL, 0);

    while(1)
    {
        memShare->ordre = randomC();
        printf("Memoire mise a jour.\nVal->\n\tordre : %c\n\n", memShare->ordre);
        usleep(999999);
    }
}
