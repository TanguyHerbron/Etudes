#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZ 255

int main()
{
    int nbOctets;
    int descTube[2];
    int descTube2[2];
    char chaine[] = "Salut papa!";
    char buffer[BUFSIZ];
    pid_t pid;
    memset(buffer, '\0', BUFSIZ);

    if ( pipe(descTube) == 0 && pipe(descTube2) == 0)
    {
        pid = fork();	// duplication du processus
        if (pid == -1)  	// oups un probleme
        {
            fprintf(stderr, "Pb de fork");
            exit(EXIT_FAILURE);
        }

        else	// fork ok
        {
            if (pid == 0)  	// je suis dans le process fils
            {
                nbOctets = read(descTube[0], buffer, BUFSIZ);
                nbOctets = write(descTube2[1], chaine, strlen(chaine));
                printf("%d octets ecrits\n", nbOctets);
                printf("octets lus: %d: %s\n", nbOctets, buffer);
                exit(EXIT_SUCCESS);
            }
            else //je suis dans le process pere
            {
                strcpy(chaine, "test");
                nbOctets = write(descTube[1], chaine, strlen(chaine));
                nbOctets = read(descTube2[0], buffer, BUFSIZ);
                printf("%d octets ecrits\n", nbOctets);
                printf("octets lus: %d: %s\n", nbOctets, buffer);
            }
        }
    }
    exit(EXIT_SUCCESS);
}
