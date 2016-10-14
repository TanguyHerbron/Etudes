#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include "zone.h"
#include <unistd.h>
#include <string.h>

int main()
{
    zone maZoneMemoire;

    key_t clef;
    int msqid;


    clef = ftok("/tmp/bidon", 5678);

    msqid = msgget(clef, 0600 | IPC_CREAT);
    if(msqid == -1)
    {
        printf("Erreur creation file message : %s\n", strerror(errno));
    }

    while(1)
    {
        msgrcv(msqid, (struct msgbuf *) &maZoneMemoire, sizeof(maZoneMemoire), 0, 0);
        printf("%ul %c\n", maZoneMemoire.type, maZoneMemoire.texte);
        usleep(99999);
    }

    return 0;
}
