/***************************************************************************
caveHunter.c
 ***************************************************************************/
#include "caveHunter.h"
#include <sys/timeb.h>
#include <math.h>
#include <time.h>



// attendre un maxTime millisecondes
void msleep(unsigned int maxTime)
{
    /*
    struct timespec {
    time_t tv_sec;        // secondes
    long   tv_nsec;       // nanosecondes
    };
    */
    struct timespec req;
    struct timespec rem;
    time_t secondes=0;
    long nanoSecondes=0;
    if (maxTime>=1000)
    {
        do
        {
            secondes++;
            maxTime-=1000;
        }
        while(maxTime>=1000);
    }
    nanoSecondes=maxTime*1000000;
    req.tv_sec=secondes;
    req.tv_nsec=nanoSecondes;
    nanosleep(&req,&rem);

}

void initPiege( char tab[LARGEUR][HAUTEUR], int nbPiege )
{

    int x, y, i;

    for ( i = 0; i < nbPiege; i++ )
    {
        do
        {
            x = aleatoire( LARGEUR );
            y = aleatoire( HAUTEUR );
        }
        while ( tab[x][y] != 0 );

        tab[x][y] = PIEGE;
    }
}

void initMonstre( char tab[LARGEUR][HAUTEUR], int nbMonstre )
{

    int x, y, i;

    for(i = 0; i < nbMonstre; i++){
        do{
            x = aleatoire(LARGEUR);
            y = aleatoire(HAUTEUR);
        }while(tab[x][y] != 0);

        tab[x][y] = MONSTRE;
    }

}

void initPotion( char tab[LARGEUR][HAUTEUR], int nbPotion )
{

    int x, y, i;

    for(i = 0; i < nbPotion; i++){
        do{
            x = aleatoire(LARGEUR);
            y = aleatoire(HAUTEUR);
        }while(tab[x][y] != 0);

        tab[x][y] = POTION;
    }

}

void initSortie(char tab[LARGEUR][HAUTEUR])
{

    int x, y;

    x = aleatoire(LARGEUR);
    y = aleatoire(HAUTEUR);

    tab[x][y] = SORTIE;

}

void initMonde( char tab[LARGEUR][HAUTEUR], int nbMonstre, int nbPotion, int nbPiege )
{
    int x, y;
    printf("veuillez patientez, creation du monde...\n");

    for ( x = 0; x < LARGEUR; x++ )
    {
        for ( y = 0; y < HAUTEUR; y++ )
        {
            tab[x][y] = 0;
        }
    }

    // placer tresor
    x = aleatoire( LARGEUR );

    y = aleatoire( HAUTEUR );

    tab[x][y] = TRESOR;



    initPotion( tab, nbPotion );

    initMonstre( tab, nbMonstre );

    initPiege( tab, nbPiege );

    initSortie(tab);

}

void afficheMonde( char tab[LARGEUR][HAUTEUR], int posX, int posY )
{
    int x, y, cadre, i;
// afficher haut du cadre

    for(i = 0; i <= LARGEUR+1; i++){
        printf("*");
    }

    printf("\n");

//afficher les bords du cadre et l'aire de jeu
    for ( y = HAUTEUR - 1; y >= 0; y-- )
    {
        // bord gauche
        printf( "*" );
        // aire de jeu
        for ( x = 0; x < LARGEUR; x++ )
        {

            // afficher un . pour representer l'aire  de jeu

            // afficher une X si x,y sont la position du joueur

            if(x == posX && y == posY){
                printf("X");
            }else{
                printf(".");
            }

        }
        // bord droit
        printf( "*" );

        printf( "\n" );
    }
// afficher bas du cadre

    for(i = 0; i <= LARGEUR+1; i++){
        printf("*");
    }

    printf("\n");

// afficher les coordonnees du joueur
    printf( "pos(%d,%d) ", posX, posY );

}


//retourne une valeur entiere E[0..maxAlea[
unsigned int aleatoire( unsigned int maxAlea )
{
    /*	struct timeb {
        time_t         time;
        unsigned short millitm;
        short          timezone;
        short          dstflag;
    };*/

    struct timeb t;
    //long t;
    float a, b ;
    unsigned int nbmilli;
    ftime( &t );
    nbmilli = t.time * 1000 + t.millitm;
    srand( nbmilli );
    a = rand();
    b = ( maxAlea * a ) / RAND_MAX;
    //printf( "in alea %i\n", nbmilli );
    msleep(100);
    return( ( unsigned int )b );


}

unsigned int getXTresor( char tab[LARGEUR][HAUTEUR] )
{
    int x = 0, y;
    int retour = -1;

    do
    {
        y = 0;

        do
        {
            if ( ( tab[x][y] ) == TRESOR )
            {
                retour = x;
            }

            y++;
        }
        while ( y < HAUTEUR && retour == -1 );

        x++;
    }
    while ( x < LARGEUR && retour == -1 );

    return retour;

}

unsigned int getYTresor( char tab[LARGEUR][HAUTEUR] )
{
    int x, y=0;
    int retour = -1;

    do
    {
        x = 0;

        do
        {
            if ( ( tab[x][y] ) == TRESOR )
            {
                retour = y;
            }

            x++;
        }
        while ( x < LARGEUR && retour == -1 );

        y++;
    }
    while ( y < HAUTEUR && retour == -1 );

    return retour;
}


unsigned int getXSortie( char tab[LARGEUR][HAUTEUR] )
{
    int x = 0, y;
    int retour = -1;

    do
    {
        y = 0;

        do
        {
            if ( ( tab[x][y] ) == SORTIE )
            {
                retour = x;
            }

            y++;
        }
        while ( y < HAUTEUR && retour == -1 );

        x++;
    }
    while ( x < LARGEUR && retour == -1 );

    return retour;

}

unsigned int getYSortie( char tab[LARGEUR][HAUTEUR] )
{
    int x, y=0;
    int retour = -1;

    do
    {
        x = 0;

        do
        {
            if ( ( tab[x][y] ) == SORTIE )
            {
                retour = y;
            }

            x++;
        }
        while ( x < LARGEUR && retour == -1 );

        y++;
    }
    while ( y < HAUTEUR && retour == -1 );

    return retour;
}


float getDistance( unsigned int xt, unsigned int yt, unsigned int xp, unsigned int yp )
{
    int xVecteur=xt-xp;
    int yVecteur=yt-yp;
    float module;
    module=sqrt((xVecteur*xVecteur+yVecteur*yVecteur));
    return module;
}

void afficheTresor()
{

    printf("  _______ _____  ______  _____  ____  _____  \n |__   __|  __ \\|  ____|/ ____|/ __ \\|  __ \\ \n    | |  | |__) | |__  | (___ | |  | | |__) |\n    | |  |  _  /|  __|  \\___ \\| |  | |  _  / \n    | |  | | \\ \\| |____ ____) | |__| | | \\ \\ \n    |_|  |_|  \\_\\______|_____/ \\____/|_|  \\_\\\n");

}
void afficheMonstre()
{

    printf("  __  __  ____  _   _  _____ _______ _____  ______ \n |  \\/  |/ __ \\| \\ | |/ ____|__   __|  __ \\|  ____|\n | \\  / | |  | |  \\| | (___    | |  | |__) | |__   \n | |\\/| | |  | | . ` |\\___ \\   | |  |  _  /|  __|  \n | |  | | |__| | |\\  |____) |  | |  | | \\ \\| |____ \n |_|  |_|\\____/|_| \\_|_____/   |_|  |_|  \\_\\______|\n");

}
void affichePotion()
{

    printf("  _____      _   _                   _                  _       \n |  __ \\    | | (_)                 | |                (_)      \n | |__) |__ | |_ _  ___  _ __     __| | ___   ___  ___  _ _ __  \n |  ___/ _ \\| __| |/ _ \\| '_ \\   / _` |/ _ \\ / __|/ _ \\| | '_ \\ \n | |  | (_) | |_| | (_) | | | | | (_| |  __/ \\__ \\ (_) | | | | |\n |_|   \\___/ \\__|_|\\___/|_| |_|  \\__,_|\\___| |___/\\___/|_|_| |_|\n");

}
void affichePiege()
{

    printf("                                                _                 \n                                               (_)                \n   ___  _   _ _ __  ___     _   _ _ __    _ __  _  ___  __ _  ___ \n  / _ \\| | | | '_ \\/ __|   | | | | '_ \\  | '_ \\| |/ _ \\/ _` |/ _ \\\n | (_) | |_| | |_) \\__ \\_  | |_| | | | | | |_) | |  __/ (_| |  __/\n  \\___/ \\__,_| .__/|___( )  \\__,_|_| |_| | .__/|_|\\___|\\__, |\\___|\n             | |       |/                | |            __/ |     \n             |_|                         |_|           |___/      \n");

}
void afficheSortie()
{

    printf("  ________   _______ _______ \n |  ____\\ \\ / /_   _|__   __|\n | |__   \\ V /  | |    | |   \n |  __|   > <   | |    | |   \n | |____ / . \\ _| |_   | |   \n |______/_/ \\_\\_____|  |_|   \n");

}
void affichePerdu()
{
    printf("                (\\  _  /)\n                ( \\ O / )\n                 (// \\\\)\n                    X\n                   / \\\n                  /___\\\n           _____/      \\\\_____\n          |                  ||\n          |                  ||\n          |                  ||\n          |  _     ___   _   ||\n          | | \\     |   | \\  ||\n          | |  |    |   |  | ||\n          | |_/     |   |_/  ||\n          | | \\     |   |    ||\n          | |  \\    |   |    ||\n          | |   \\. _|_. | .  ||\n          |                  ||\n  *     * | *   **    * **   |**      **\n    ");

}

