#include "gestionPendu.h"

int main(int argc, char *argv[])
{
	char *listeMots[NBMOTS]={"bonjour","maison","noyau","temps","blond"};
	int cptErreur=0;
	int longueurMot;
	char *motATrouver;
	char *motCourant;
	int choix,i;
	char lettre;
	char histo[NB_MAX_LETTRES_POSSIBLE];
	int cptProposition=0;
	int trouve;
	do{
		choix=afficherMenu();
		// l'utilisateur veut jouer
		if (choix>0){
			// init des compteurs
			cptErreur=0;
			cptProposition=0;
			// tirage aleatooire du mot
			motATrouver=listeMots[aleatoire(NBMOTS-1)];
			// init du motCourant
			longueurMot=strlen(motATrouver);
			motCourant=(char *)malloc(longueurMot+1);
			initialiserMot(motCourant,longueurMot);
			// boucle de jeu
			do{
				printf("%s\n",motCourant);
				afficherLettre(histo,cptProposition);
				// demander/redemander une lettre tant que
				// le caractere saisi n'est pas une lettre
				// ou a deja ete propose
				do{
					printf("donnez une lettre :");
					scanf(" %c",&lettre);
				}while(verifierLettrePropose(histo,cptProposition,lettre)==0);
				// mise a jour du tableau des lettres proposees
				histo[cptProposition]=lettre;
				cptProposition++;
				// mise a jour du compteur d'erreur
				cptErreur+=placerLettre(motATrouver,motCourant,lettre);

				afficherPendu(cptErreur);
				trouve=motEstTrouve(motATrouver,motCourant);
			}while(/* a completer*/);
			// liberation de la memoire du mot courant
			free(motCourant);
			// affichage des messages de fin de jeu
			if (trouve==0)
			{
				printf("bravo\n");
			}
			else
			{
				printf("Perdu le mot etait %s\n",motATrouver);
			}
		}	// fin boucle de jeu

	}while (choix!=-1);


  return EXIT_SUCCESS;
}
