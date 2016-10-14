#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include "zone.h"
#include <unistd.h>
#include <time.h>

float randomC()
{
    return ((char)('A'+((char)(25.0*(rand()/(RAND_MAX+0.1))))));
}

int main()
{
    int i;
    zone maZoneMemoire;

    key_t clef;
    int msqid;

    clef = ftok("/tmp/bidon", 5678);

    msqid = msgget(clef, 0666 | IPC_CREAT);
    if(msqid == -1)
    {
        printf("Erreur creation file message : %s\n", strerror(errno));
    }

    while(1)
    {
        maZoneMemoire.texte = (char)randomC();
        msgsnd(msqid, (struct msgbuf *) &maZoneMemoire, sizeof(maZoneMemoire), 0);
        printf("Nouveau message envoye.\n");
        usleep(99999);
    }
}
