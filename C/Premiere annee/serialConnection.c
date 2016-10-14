#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
    int fd;
    int retour;
    char str[255];

    struct termios tty, orig;
    tty.c_iflag = IGNBRK | IGNPAR;
    tty.c_oflag = 0;
    tty.c_cflag = B9600 | CS8 | CLOCAL | CREAD | IGNPAR | CSTOP;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tty.c_cc[VMIN] = 0;
    tty.c_cc[VTIME] = 1;

    //Ouverture de la liaison serie
    fd = open("/dev/ttyS0", O_RDWR);
    if(fd == -1)
    {
        printf("Probleme d'ouverture : %s\n", strerror(errno));
        exit(errno);
    }

    /*traitement, lecture/ecriture*/
    //fermeture du port
    if(retour == -1)
    {
        printf("Probleme de fermeture : %s\n", strerror(errno));
        exit(errno);
    }

    /* Lecture et sauvegarde des parametres courants */
    tcgetattr(fd,&tty);
    orig=tty;
    /* remplissage des champs de la structure termios*/

    /* appplication des nouveaux parametres */
    if(tcsetattr(fd,TCSANOW,&tty)<0)
    {
        printf ("impossible d'initialiser le port série\n");
    }

    /* lecture/ecriture/traitement sur la liaison série */

    do{
        printf("Que voulez-vous envoyer ?\n");
        gets(str);

        write(fd, str, strlen(str));

        printf("%s a ete envoye.\n", str);

    }while(1);

    /* on remet l'etat initiale de la configuration du port*/
    if(tcsetattr(fd,TCSANOW,&orig)<0)
    {
        printf ("impossible d'initialiser le port série\n");
    }
    /* Fermeture port série*/
    retour=close(fd);
    if ( retour == -1 )
    {
        printf("pb fermeture: %s\n",strerror(errno));
        exit(errno);
    }
    return 0;
}
