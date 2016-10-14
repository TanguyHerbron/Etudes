#include "caveHunter.h"

int main( int argc, char *argv[] )
{

    char monde[LARGEUR][HAUTEUR];
    int i;
    int x, y;
    int sortie = 1;
    int tresor = 0;
    int vie ;
    unsigned char dir;
    char choix;

    do
    {
        initMonde(monde,10,2,5);	// 10 monstres, 2 potions et 5 pieges
        x = LARGEUR / 2;
        y = HAUTEUR / 2;
        sortie = 1;
        tresor = 0;
        vie = VIE;

        do
        {
            afficheMonde( monde, x, y );
            printf( " Vie[%d] ", vie );



            if ( tresor == 0 )
            {
                printf( "(tresor a %.1f m)\n", getDistance( x, y, getXTresor( monde ), getYTresor( monde ) ) );
            }
            else
            {
                printf( "(sortie a %.1f m)\n", getDistance( x, y, getXSortie( monde ), getYSortie( monde ) ) );
            }
            printf( "direction : " );
            scanf( " %c", &dir );

            switch ( dir )
            {

            case '7':
                x--;
                y++;
                break;

            case '8':
                y++;
                break;

            case '9':
                x++;
                y++;
                break;

            case '4':
                x--;
                break;

            case '6':
                x++;
                break;

            case '1':
                x--;
                y--;
                break;

            case '2':
                y--;
                break;

            case '3':
                x++;
                y--;
                break;
            }

            if ( x == LARGEUR )
            {
                x = LARGEUR - 1;
            }

            if ( x == -1 )
            {
                x = 0;
            }


            if ( y == HAUTEUR )
            {
                y = HAUTEUR - 1;
            }

            if ( y == -1 )
            {
                y = 0;
            }

            switch ( monde[x][y] )
            {

            case MONSTRE:
                vie -= MONSTRE;
                afficheMonstre();
                printf( "un monstre!!! vous perdez %d pv\n", MONSTRE );
                break;

            case PIEGE:
                vie -= PIEGE;
                affichePiege();
                printf("arg, un piege!!! %d pv en moins\n", PIEGE);
                break;

            case POTION:
                vie += POTION;
                affichePotion();
                printf("une potion de soin! %d pv en plus\n", POTION);
                break;

            case SORTIE:

                if ( tresor == 1 )
                {
                    sortie = 0;
                }

                afficheSortie();
                printf( "La sortie\n" );

                break;

            case TRESOR:
                tresor = 1;
                afficheTresor();
                printf( "vous avez trouve le tresor. reste a trouver la sortie\n" );

                break;
            }

            if ( vie <= 0 )
            {
                sortie = 0;
            }
        }
        while ( sortie == 1 );

        if ( vie <= 0 )
        {
            affichePerdu();
            printf( "vous avez perdu\n" );
        }
        else
        {
            printf( "congratulation!!\n" );
        }
        printf("\nUne autre partie (O/N)?");
        scanf(" %c",&choix);
    }
    while (choix=='o' || choix=='O');

    return EXIT_SUCCESS;

}
