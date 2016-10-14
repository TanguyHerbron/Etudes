/***************************************************************************
golf.c
 ***************************************************************************/
#include "golf.h"


/*
  *  paramètre d'entrées  : 	le nombre actuel d'element(s) du tableau
  *
  *  en entrées :
  *
  *  paramètre de sortie
  *
  *  paramètre  d'E/S 		un tableau de pointeur(s) sur parcours
  *
  * en sortie :

  *  valeur retournée :		le nouveau nombre de parcours present dans le tableau
  *
  *  DESCRIPTION	: 	creation dynamique d'un parcours, initialisation
  *				et ajout de ce dernier dans le tableau des parcours
  *
  */
int creerParcours( typeParcours *tab[], int nbParcours )
{
	int i;
	// creation du parcours a l'indice nbParcours
	tab[nbParcours] = ( typeParcours* ) malloc( sizeof( typeParcours ) );
	printf( "\nnom du parcours " );
	scanf( "%s", tab[nbParcours]->nom );
	printf( "nombre de trous " );
	scanf( "%d", &tab[nbParcours]->nbTrou );

	// initialisation des trous
	for ( i = 0;i < tab[nbParcours]->nbTrou;i++ )
	{
		printf( "numero du trou : %d\n", i + 1 );
		tab[nbParcours]->listeTrous[i].numero = i + 1;
		printf( "distance (en metre) : " );
		scanf( "%f", &tab[nbParcours]->listeTrous[i].distance );
		printf( "valeur du par : " );
		scanf( "%d", &tab[nbParcours]->listeTrous[i].par );
		printf( "nombre maximum de coups pour ce trou : " );
		scanf( "%d", &tab[nbParcours]->listeTrous[i].nbMaxCoups );
	}

	return nbParcours + 1;
}

/*
  *  paramètre d'entrées  : 	un tableau de pointeur(s) sur parcours
  				le numero d'index du parcours a afficher
  *
  *  en entrées :
  *
  *  paramètre de sortie
  *
  *  paramètre  d'E/S
  *
  * en sortie :			affichage de info à l'ecran

  *  valeur retournée :
  *
  *  DESCRIPTION	: 	afficher les informations d'un parcours particulier
  *
  */
void afficherUnParcours( typeParcours *tab[], int nro )
{
	int i;
	printf( "\nnom du parcours %s\n", tab[nro]->nom );
	printf( "nombre de trous %d\n", tab[nro]->nbTrou );

	// afficher le detail de chaque trou du parcours
	for ( i = 0;i < tab[nro]->nbTrou;i++ )
	{
		afficherInfoTrou( tab[nro]->listeTrous[i] );
	}
}


/*
  *  paramètre d'entrées  : 	un tableau de pointeur(s) sur parcours
  				le nombre actuel d'element(s) du tableau
  *
  *  en entrées :
  *
  *  paramètre de sortie
  *
  *  paramètre  d'E/S
  *
  * en sortie :			fichier contenant l'ensemble des parcours

  *  valeur retournée :
  *
  *  DESCRIPTION	: 	sauvegarder les donnees des parcours dans un fichier
  *
  */
void sauvegarderParcours( typeParcours *tab[], int nbParcours )
{
    FILE *fd;
    int i;
    int nbEnregistrement;
    int retourFclose;
    // ouverture du fichier des parcours en ecriture
    fd = fopen( FICHIER_PARCOURS, "w+" );
    if ( fd == NULL )
    {
        printf( "%s\n", strerror( errno ) );
        exit( errno );
    }

    //ecriture de chacun des parcours
    for ( i = 0; i < nbParcours; i++ )
    {
        nbEnregistrement=fwrite( tab[i], sizeof( typeParcours ), 1, fd );
        if (nbEnregistrement!=1)
        {
            printf( " pb sauvegarde parcours%s\n", strerror( errno ) );
            exit( errno );

        }
    }

    retourFclose=fclose( fd );
    if(retourFclose==EOF)
    {
        printf( " pb fermeture sauvegarde parcours%s\n", strerror( errno ) );
        exit( errno );
    }
}

/*
  *  paramètre d'entrées  :

  *
  *  en entrées :		fichier contenant l'ensemble des parcours
  *
  *  paramètre de sortie :	un tableau de pointeur(s) sur parcours
  *
  *  paramètre  d'E/S
  *
  * en sortie :

  *  valeur retournée :		le nombre actuel d'element(s) du tableau des parcours
  *
  *  DESCRIPTION	: 	initialiser le tableau des parcours
  *				à partir d'un fichier
  *
  */
int chargerParcours( typeParcours *tab[] )
{
	FILE *fd;
	int nbEnregistrement;
	int i = 0;
	int retourFclose;
	// ouverture du fichier des parcours en lecture
	fd = fopen( FICHIER_PARCOURS, "r" );

	if ( fd == NULL )
	{
		printf( "%s\n", strerror( errno ) );
		exit( errno );
	}

	// lecture et stockage de tous les parcours
    while ( !feof( fd ) )
    {
        // reservation memoire pour stokcer un parcours
        tab[i] = ( typeParcours* ) malloc( sizeof( typeParcours ) );
        //lecture d'un parcours
        nbEnregistrement=fread( tab[i], sizeof( typeParcours ), 1, fd );
        if (nbEnregistrement!=1)    // pb de lecture
        {
            if (!feof(fd))
            {
                printf( " pb lecture charger parcours%s\n", strerror( errno ) );
                exit( errno );
            }
            else
            {
                // c'est la fin de fichier
                // on a donc réserve une case en trop pour les parcours
                // il faut la supprimer
                    free( tab[i] );

            }

        }
        else
        {
            // augmentation du nombre de parcours lu
            i++;
        }


    }

    retourFclose=fclose( fd );
    if(retourFclose==EOF)
    {
        printf( " pb fermeture charger parcours%s\n", strerror( errno ) );
        exit( errno );
    }

	// je retourne le nombre de parcours maintenant present dans mon tableau
	return i;
}


/*
 *	retourne une valeur entiere E[0..maxAlea[
 */
float aleatoire( float maxAlea )
{
	/* struct timeb {
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
	return ( b );


}
/*
 *	retourne un entier entre min et max
*/
float lancement( float min, float max )
{
	float lancee;
	lancee = min + aleatoire( max - min );
	return ( lancee );
}


/*
  *  paramètre d'entrées  : 	un trou
  *				la difficulte sur le green
  *
  *
  *  en entrées :		le choix du club utilise
  *
  *  paramètre de sortie :
  *
  *  paramètre  d'E/S
  *
  * en sortie :			affichage de la distance restante
  *				et du nombre de points

  *  valeur retournée :		le nombre de coups effectue pour arriver au trou
  *
  *  DESCRIPTION	: 	jouer un trou ->
  *					demander autant de fois que necessaire
  *					le type de club a utilise
  *					jusqu'à arriver au trou.
  *				->la difficulte est de determiner à partir de
  *					combien de metres du trou
  *					une balle est consideree dans le trou.
  *
  */
int jouerTrou( typeTrou t, float difficulte )
{
	int fin = 1; // la balle n'est pas dans le trou
	float dist = t.distance;
	int nbCoups = 1;
	char choix;

	do
	{
		printf( "=============== coups nro %d\n", nbCoups );
		printf( "choix du club : \n[D]river\n[B]ois\n[F]er\n[P]utter\n" );
		scanf( " %c", &choix );
		choix = toupper( choix );
		// en fonction du choix de club, je reduis la distance avec le trou

		switch ( choix )
		{

			case 'D':
				dist -= lancement( DRIVER_MIN, DRIVER_MAX );
				break;

			case 'B':
				dist -= lancement( BOIS_MIN, BOIS_MAX );
				break;

			case 'F':
				dist -= lancement( FER_MIN, FER_MAX );
				break;

			case 'P':
				dist -= lancement( PUTTER_MIN, PUTTER_MAX );
				break;
		}

		if ( dist <= 0.0 )
		{// si je depasse le trou je remets une distance positive
			dist = -dist;

			if ( dist > difficulte )
				printf( "%svous avez depasse le trou%s\n", RED, GREY );
		}

		if ( dist <= difficulte && dist >= 0.0 )
		{// la balle est dans le trou
			fin = 0;
		}
		if ( nbCoups == t.nbMaxCoups )
		{// j'ai atteint le nombre maxi de coups pour le trou
			if ( fin != 0 )
			{// et en plus la balle n'est toujours pas dans le trou
				printf( "%sNombre de coups maxi atteint!! abandon de ce trou%s\n", RED, GREY );
			}

			fin = 0;
		}

		if ( fin != 0 )
		{// je dois rejouer, j'affiche la distance restante
			nbCoups++;
			printf( "=================================================\n" );
			printf( "il vous reste %.1f metres avant le trou\n", dist );
			printf( "=================================================\n" );
		}
	}
	while ( fin != 0 );

	printf( "\n\n\n" );

	// suivant le nombre de coups joue par rapport au "par" du trou
	// j'affiche la designation correspondante
	switch ( nbCoups - t.par )
	{

		case CONDOR:
			printf( "%s CONDOR !!!! %d\n%s", YELLOW, CONDOR, GREY );
			break;

		case ALBATROS:
			printf( "%s ALBATROS!!! %d\n%s", YELLOW, ALBATROS, GREY );
			break;

		case EAGLE:
			printf( "%sEAGLE!! %d%s\n", YELLOW, EAGLE, GREY );
			break;

		case BIRDIE:
			printf( "%sBIRDIE! %d%s\n", YELLOW, BIRDIE, GREY );
			break;

		case PAR:
			printf( "PAR %d\n", PAR );
			break;

		case BOGEY:
			printf( "%sBOGEY +%d%s\n", RED, BOGEY, GREY );
			break;

		case DOUBLE_BOGEY:
			printf( "%sDOUBLE_BOGEY +%d%s\n", RED, DOUBLE_BOGEY, GREY );
			break;

		case TRIPLE_BOGEY:
			printf( "%sTRIPLE_BOGEY +%d%s\n", RED, TRIPLE_BOGEY, GREY );
			break;

		default:
			printf( "%s+%d%s\n", RED, nbCoups - t.par, GREY );
	}

	printf( "\n\n\n" );

	// retourne le nombre de coups joue pour ce trou
	return ( nbCoups );
}




/*
  *  paramètre d'entrées  : 	un pointeur sur un score
  *
  *  en entrées :
  *
  *  paramètre de sortie :
  *
  *  paramètre  d'E/S
  *
  * en sortie :			affichage du score d'un joueur pour un parcours
  *  valeur retournée :
  *
  *  DESCRIPTION	: 	affichage du score d'un joueur pour un parcours
  *
  */
void afficherScore( typeScore *s )
{
	int i, total = 0;

	printf( "score de%s %s:%s\n", CYAN, s->nomJoueur, GREY );
	printf( "parcours : %s     difficulte : ", s->parcoursJoue.nom );

	// suivant la valeur de la difficulte, afficher la difficulte en toute lettre
	switch ( s->difficulte )
	{

		case 0:
			printf( "infernale\n" );

		case 1:
			printf( "tres difficile\n" );

		case 2:
			printf( "difficile\n" );

		case 3:
			printf( "normale\n" );

		case 4:
			printf( "facile\n" );

		case 5:
			printf( "tres facile\n" );
	}

	// affichage de la grille avec le numero des trous, les valeurs des "par" et le score du joueur
	printf( "--------------" );

	for ( i = 0;i < s->parcoursJoue.nbTrou + 1;i++ )
	{
		printf( "----" );
	}

	printf( "\n" );

	//affichage des numeros de trou
	printf( "nro Trou      " );

	for ( i = 0;i < s->parcoursJoue.nbTrou;i++ )
	{
		if ( i < 10 )
		{
			printf( "| %.1d ", i + 1 );
		}
		else
		{
			printf( "| %.2d", i + 1 );
		}
	}

	printf( "|TOT" );

	printf( "\n" );
	printf( "--------------" );

	for ( i = 0;i < s->parcoursJoue.nbTrou + 1;i++ )
	{
		printf( "----" );
	}

	printf( "\n" );

	//affichage des valeurs de "par" pour chaque trou
	printf( "valeur du par " );

	for ( i = 0;i < s->parcoursJoue.nbTrou;i++ )
	{
		printf( "| %.1d ", s->parcoursJoue.listeTrous[i].par );
		total += s->parcoursJoue.listeTrous[i].par;
	}

	printf( "| %.2d", total );

	printf( "\n" );
	total = 0;
	printf( "--------------" );

	for ( i = 0;i < s->parcoursJoue.nbTrou + 1;i++ )
	{
		printf( "----" );
	}

	printf( "\n" );

	//affichage du score du joueur
	printf( "score         " );

	for ( i = 0;i < s->parcoursJoue.nbTrou;i++ )
	{
		printf( "| " );

		if ( s->points[i] > ( s->parcoursJoue.listeTrous[i].par ) )
			printf( "%s", RED );

		if ( s->points[i] < ( s->parcoursJoue.listeTrous[i].par ) )
			printf( "%s", YELLOW );

		printf( "%.1d %s", s->points[i], GREY );

		total += s->points[i];
	}

	printf( "| %.2d", total );

	printf( "\n" );
	printf( "--------------" );

	for ( i = 0;i < s->parcoursJoue.nbTrou + 1;i++ )
	{
		printf( "----" );
	}

	printf( "\n" );
}


/*
  *  paramètre d'entrées  : 	le nombre de scores present dans le tableau des scores
  *
  *  en entrées :
  *
  *  paramètre de sortie :
  *
  *  paramètre  d'E/S 		tableau de pointeurs sur des scores
  *
  * en sortie :			le tableau des scores trie
  *					selon la somme des coups par ordre croissant
  *  valeur retournée :
  *
  *  DESCRIPTION	: 	trier les scores du meilleur au plus mauvais
  *
  */
void classement( typeScore *tab[], int nbScore )
{
	int i, j, k;
	typeScore *tmp;
	int sommei = 0, sommej = 0;

	for ( i = 0;i < nbScore;i++ )
	{
		sommei = 0;
		// calcul de la somme des points au rang i
		for ( k = 0;k < tab[i]->parcoursJoue.nbTrou;k++ )
			sommei += tab[i]->points[k];

		for ( j = i;j < nbScore;j++ )
		{
			sommej = 0;
			// calcul de la somme des points au rang j
			for ( k = 0;k < tab[j]->parcoursJoue.nbTrou;k++ )
				sommej += tab[j]->points[k];

			// si le score au rang j est plus petit qu'au rang i swapper les pointeurs
			if ( sommej < sommei )
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}

		}
	}

}


/****************************************************************************************************
****************************************************************************************************
****************************************************************************************************
	fonctions a coder/completer
****************************************************************************************************
****************************************************************************************************
****************************************************************************************************/

void afficherMenu(int nbParcours, int nbScores)
{
    if(nbParcours > 0)
    {
        printf("[J] Jouer un parcours\n");
        printf("[D] Jouer un parcours avec 2 joueurs\n");
        printf("[V] Afficher un parcours\n");
    }

    if(nbScores > 0)
    {
        printf("[Z] Classement\n");
    }

    printf("[C] Creer un parcours\n");
    printf("[Q] Quitter\n");

    printf("Votre choix :");
}


/*
  *  paramètre d'entrées  : 	un trou
  *
  *  en entrées :
  *
  *
  *  paramètre de sortie :
  *
  *  paramètre  d'E/S
  *
  * en sortie : Affichage des champs du trou

  *  valeur retournée :
  *
  *  DESCRIPTION	: 	Affichage des caracteristiques d'un trou
  *
  *
  */
void afficherInfoTrou( typeTrou unTrou)
{
    printf("[Trou numero %d |", unTrou.numero);
    printf(" Distance %.2f metres |", unTrou.distance);
    printf(" Par %d |", unTrou.par);
    printf(" %d coups maximum]\n", unTrou.nbMaxCoups);
}


/*
  *  paramètre d'entrées  : 	tableau de pointeur sur des parcours
								nombre de parcours actuellement dans le tableau
  *
  *  en entrées :
  *
  *
  *  paramètre de sortie :
  *
  *  paramètre  d'E/S
  *
  * en sortie :	affichage de l'index(numero d'indice) de chaque parcours suivi de son nom

  *  valeur retournée :
  *
  *  DESCRIPTION	: 	Affichage des différents parcours disponibles
  *
  *
  */
void afficherLesParcours( typeParcours *tab[], int nbParcours )
{
    int i;

    for(i = 0; i <
 nbParcours; i++)
    {
        printf("%d - %s\n", i, tab[i]->nom);
    }
}



/*
  *  paramètre d'entrées  : 	un pointeur sur le parcours a jouer
  *
  *  en entrées :		nom du joueur
  *				difficulte de la partie
  *
  *  paramètre de sortie :
  *
  *  paramètre  d'E/S
  *
  * en sortie :			affichage des differents coups joues
  				affichage du score
  				mise à jour du fichier des scores

  *  valeur retournée :		un pointeur sur le score du joueur
  *
  *  DESCRIPTION	: 	creation d'un joueur avec son score,
  *				joue chaque trou du parcours.
  *
  */
typeScore *jouerParcours( typeParcours *p )
{
	typeScore *sc;
	int i;
	float niveau;
	// creation d'un nouveau score
	sc = ( typeScore* ) malloc( sizeof( typeScore ) );

	printf( "votre nom :" );
	scanf( "%s", sc->nomJoueur );
	printf( "difficulte [0-infernale .. 5-tres facile]" );
	scanf( "%d", &sc->difficulte );
	niveau = 1.0 + 3.0 * ( float ) sc->difficulte;
	// recopie des donnees du parcours fait par le joueur
	memcpy( &sc->parcoursJoue, p, sizeof( typeParcours ) );

	printf( "parcour %s\n", p->nom );
/*****************************************************************************************/
	// pour chaque trou du parcours
	// afficher les informations concernant le trou
	// jouer le trou et sauvegarder le nombre de coups joue dans le tableau
	// des points du joueur
	for ( i = 0;i < p->nbTrou;i++ )
	{
		afficherInfoTrou( p->listeTrous[i] );
		sc->points[i] = jouerTrou( p->listeTrous[i], niveau );
	}

	// afficher le score du joueur pour ce parcours
    afficherScore( sc );

	// sauvegarder ce score

	sauvegarderScore(sc);

/*****************************************************************************************/
	return sc;
}

void sauvegarderScore( typeScore *sc )
{
    FILE *fd;
    int erreurEcriture;
    int erreurFClose;

    fd = fopen( FICHIER_SCORE, "w+");

    erreurEcriture = fwrite(sc, sizeof(typeScore), 1, fd);
    if(erreurEcriture != 1)
    {
        printf("Probleme sauvegarde scores%s\n", strerror(errno));
        exit(errno);
    }

    erreurFClose = fclose(fd);
    if(erreurFClose == EOF)
    {
        printf("Probleme fermeture sauvegarde scores%s\n", strerror(errno));
        exit(errno);
    }
}

int chargerLesScores( typeScore *tab[] )
{
    FILE *fd;
    int i = 0;
    int erreurLecture;
    int erreurFClose;

    fd = fopen(FICHIER_SCORE, "r");
    if(fd == NULL)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }

    while(!feof(fd))
    {
        tab[i] = (typeScore*) malloc(sizeof(typeScore));

        erreurLecture = fread(tab[i], sizeof(typeScore), 1, fd);
        if(erreurLecture != 1)
        {
            if(!feof(fd))
            {
                printf("Probleme lecture chargement scores%s\n", strerror(errno));
                exit(errno);
            }
            else
            {
                free(tab[i]);
            }
        }
        else
        {
            i++;
        }
    }
    erreurFClose = fclose(fd);
    if(erreurFClose == EOF)
    {
        printf("Probleme fermeture chargement scores%s\n", strerror(errno));
        exit(errno);
    }

    return i;

}

void jouerParcoursADeux( typeParcours *p )
{
    typeScore *scP1;
    typeScore *scP2;
	int i;
	float niveauP1;
	float niveauP2;
	// creation d'un nouveau score
	scP1 = ( typeScore* ) malloc( sizeof( typeScore ) );
	scP2 = ( typeScore* ) malloc( sizeof( typeScore ) );

	printf( "Nom player 1 :" );
	scanf( "%s", scP1->nomJoueur );
	printf( "difficulte player 1 [0-infernale .. 5-tres facile]" );
	scanf( "%d", &scP1->difficulte );

	printf( "Nom player 2 :" );
	scanf( "%s", scP2->nomJoueur );
	printf( "difficulte player 2 [0-infernale .. 5-tres facile]" );
	scanf( "%d", &scP2->difficulte );

	niveauP1 = 1.0 + 3.0 * ( float ) scP1->difficulte;
	niveauP2 = 1.0 + 3.0 * ( float ) scP2->difficulte;

	// recopie des donnees du parcours fait par le joueur
	memcpy( &scP1->parcoursJoue, p, sizeof( typeParcours ) );
	memcpy( &scP2->parcoursJoue, p, sizeof( typeParcours ) );

	printf( "parcour %s\n", p->nom );

	// pour chaque trou du parcours
	// afficher les informations concernant le trou
	// jouer le trou et sauvegarder le nombre de coups joue dans le tableau
	// des points du joueur
	for ( i = 0;i < p->nbTrou;i++ )
	{
		afficherInfoTrou( p->listeTrous[i] );
		printf("%s", scP1->nomJoueur);
		scP1->points[i] = jouerTrou( p->listeTrous[i], niveauP1 );
		printf("%s", scP2->nomJoueur);
		scP2->points[i] = jouerTrou( p->listeTrous[i], niveauP2 );
	}

	afficherScore( scP1 );
	afficherScore( scP2 );
}

