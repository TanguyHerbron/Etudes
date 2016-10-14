/*********************************************************
 *
 *  NOM 	: main.c
 *  TYPE	: APPLICATION
 *  SUJET 	: simulation de jeu de golf
 *
 *  AUTEUR	:
 *  VERSION	:
 *  CREATION	: 08/01/2014
 *  DER. MODIF.	: 05/01/2016
 *
 *  ACCES SRC	:
 *  ACCES OBJ 	:
 *  ACCES EXEC	:
 *  FABRICATION  : codeblocks
 *
 *  LIMITES	: 20 parcours maximum, 50 parties stockables au maxi
 *  CONTRAINTES	: sous linux pour avoir de la couleur
 *
  ********************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "golf.h"

int main( int argc, char *argv[] )
{

	typeScore *scores[NBMAXSCORES];

	/**********************************************
	declaration du tableau des parcours
	**********************************************/

	typeParcours *tab[NBMAXPARCOURS];

	int nbParcours = 0;
	int nbScores = 0;
	char choix;
	int nro, i;
	nbParcours = chargerParcours( tab );
	nbScores = chargerLesScores( scores );

	do
	{
		/*********************
		appel a la fonction afficherMenu
		*********************/

        afficherMenu(nbParcours, nbScores);

		scanf( " %c", &choix );
		choix = toupper( choix );

		switch ( choix )
		{

			case 'C':
				nbParcours = creerParcours( tab, nbParcours );
				sauvegarderParcours( tab, nbParcours );
				break;

			case 'V':
				afficherLesParcours( tab, nbParcours );
				printf( "Numero du parcours a afficher :" );
				scanf( " %d", &nro );
				afficherUnParcours( tab, nro );
				break;

			case 'J':
				afficherLesParcours( tab, nbParcours );
				printf( "Numero du parcours sur lequel vous voulez jouer :" );
				scanf( " %d", &nro );
				scores[nbScores++] = jouerParcours( tab[nro] );
				break;

			case 'D':
				afficherLesParcours( tab, nbParcours );
				printf( "Numero du parcours sur lequel vous voulez jouer :" );
				scanf( " %d", &nro );
				jouerParcoursADeux( tab[nro] );
				break;

			case 'Z':
				classement( scores, nbScores );
				printf( "classement [G]lobale ou selon un circuit [P]articulier?\n" );
				scanf( " %c", &choix );
				choix = toupper( choix );

				if ( choix == 'P' )
				{
					afficherLesParcours( tab, nbParcours );
					printf( "Numero du parcours sur lequel vous voulez le classement :" );
					scanf( " %d", &nro );
				}

				for ( i = 0;i < nbScores;i++ )
				{
					if ( choix != 'G' )
					{
						if ( strcmp( scores[i]->parcoursJoue.nom, tab[nro]->nom ) == 0 )
						{
							afficherScore( scores[i] );
						}
					}
					else
					{
						afficherScore( scores[i] );
					}
				}

				break;

		}
	}
	while ( choix != 'Q' );

	return EXIT_SUCCESS;
}
