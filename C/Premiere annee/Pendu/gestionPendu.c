#include "gestionPendu.h"



int motEstTrouve(char *motATtrouver, char *motPropose){
	return(strcmp(motATtrouver,motPropose));
}


int verifierLettrePropose(char *lettresProposees, int nbLettreProposee, char lettre)
{
	int lettreTrouve=1;
	int i;
	for(i = 0; i<nbLettreProposee;i++){
		/*
			a completer
		*/
	}
	return lettreTrouve;

}

//retourne une valeur entiere E[0..maxAlea[
unsigned int aleatoire( unsigned int maxAlea )
{
	struct timeb t;
	float a, b ;
	unsigned int nbmilli;
	ftime( &t );
	nbmilli = t.time * 1000 + t.millitm;
	srand( nbmilli );
	a = rand();
	b = ( maxAlea * a ) / RAND_MAX;
	return( ( unsigned int )b );
}

void initialiserMot(char *motCourant,int longueurMot){
	/*
		a completer
	*/
	motCourant[longueurMot]='\0';	// pour que le tableau de caracteres devienne une chaine de caracteres
}

int afficherMenu(){
    int choix;

    printf("Voulez-vous jouer ?");
    printf("1 - Oui");
    printf("2 - Non");
    scanf("%d", &choix);
    if(choix == 1){
        return choix;
    }else{
        if(choix == 2){
            return -choix;
        }else{
            printf("Erreur");
            return -choix;
        }
    }
}

void afficherPendu(int nroErreur){

    switch (nroErreur){
    case 1:
        printf(" \n           \n           \n           \n           \n           \n   \n   \n   \n   \n");
        break;
    case 2:
        printf(" \n           \n           \n           \n           \n           \n   \n   \n   \n   \n==================");
        break;
    case 3:
        printf(" \n   ||        \n   ||        \n   ||        \n   ||        \n   ||        \n   ||\n   ||\n   ||\n   ||\n==================");
        break;
    case 4:
        printf(" \n   ||        \n   ||        \n   ||        \n   ||        \n   ||        \n   ||\n   ||\n  /||\n //||\n==================");
        break;
    case 5:
        printf(" \n   ||  /      \n   || /       \n   ||/        \n   ||        \n   ||        \n   ||\n   ||\n  /||\n //||\n==================");
        break;
    case 6:
        printf("\n   ,==========Y===\n   ||  /      \n   || /       \n   ||/        \n   ||        \n   ||        \n   ||\n   ||\n  /||\n //||\n==================");
        break;
    case 7:
        printf("\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        \n   ||        \n   ||        \n   ||\n   ||\n  /||\n //||\n==================");
        break;
    case 8:
        printf("\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        o\n   ||        \n   ||        \n   ||\n   ||\n  /||\n //||\n==================");
        break;
    case 9:
        printf("\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        o\n   ||         |\n   ||        \n   ||\n   ||\n  /||\n //||\n==================");
        break;
    case 10:
        printf("\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        o\n   ||        /|\n   ||        \n   ||\n   ||\n  /||\n //||\n==================");
        break;
    case 11:
        printf("\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        o\n   ||        /|\\\n   ||        \n   ||\n   ||\n  /||\n //||\n==================");
        break;
    case 12:
        printf("\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        o\n   ||        /|\\\n   ||        /\n   ||\n   ||\n  /||\n //||\n==================");
        break;
    case 13:
        printf("\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        o\n   ||        /|\\\n   ||        /|\n   ||\n   ||\n  /||\n //||\n==================");
        break;
    }
    printf("\n");
}

void afficherLettre(char *histo, int nbLettre){
    int boucle;
    for(boucle = 0; boucle < nbLettre; boucle++){
        printf("%c", histo[nbLettre]);
    }
}


int motEstTrouve(char *motATtrouver, char *motPropose){

}
