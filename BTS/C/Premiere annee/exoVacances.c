#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/timeb.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#define TAILLEMAX 50

void formatageDate(int jour, int mois, int annee){
    int choixFormatage;
    do{
        printf("Format d'affichage de votre date de naissance : \n");
        printf("1 - jj/mm/aaaa\n");
        printf("2 - jj-mm-aaaa\n");
        printf("3 - jj:mm:aaaa\n");
        printf("4 - jj.mm.aaaa\n");
        printf("Choisissez le format d'affichage (1, 2, 3 ou 4) : ");
        scanf("%d", &choixFormatage);
        switch (choixFormatage){
        case 1:
            printf("Votre date de naissance est le %d/%d/%d.\n\n", jour, mois, annee);
            break;
        case 2:
            printf("Votre date de naissance est le %d-%d-%d.\n\n", jour, mois, annee);
            break;
        case 3:
            printf("Votre date de naissance est le %d:%d:%d.\n\n", jour, mois, annee);
            break;
        case 4:
            printf("Votre date de naissance est le %d.%d.%d.\n\n", jour, mois, annee);
            break;
        default:
            printf("La valeur entrée est incorrecte, réessayez.\n");
        }
    }while(choixFormatage < 1 || choixFormatage > 4);
}

int acquisitionJourNaissance(){
    int jour;
    do{
        printf("Jour de naissance : ");
        scanf("%d", &jour);
    }while(jour < 1 || jour > 31);
    printf("Jour correcte.\n");
    return jour;
}

int acquisitionMoisNaissance(){
    int mois;
    do{
        printf("Mois de naissance : ");
        scanf("%d", &mois);
    }while(mois < 1 || mois > 12);
    printf("Mois correcte.\n");
    return mois;
}

int acquisitionAnneeNaissance(){
    int annee;
    do{
        printf("Année de naissance : ");
        scanf("%d", &annee);
    }while(annee < 1900 || annee > 2013);
    printf("Année correcte.\n");
    return annee;
}

void comptageMois(int jour, int mois, int annee, int tabJourMois[]){
    int deroulementMois;
    int nbMoisPlus30 = 0;

    for(deroulementMois = 0; deroulementMois < 12; deroulementMois++){
        printf("Le mois numéro %d contient %d jours.\n", deroulementMois+1, tabJourMois[deroulementMois]);
        if(tabJourMois[deroulementMois] > 30){
            nbMoisPlus30++;
        }
    }
    printf("Il y a %d mois ayant plus de 30 jours dans l'année.\n\n", nbMoisPlus30);
}

void verificationDateNaissance(int jour, int mois, int tabJourMois[]){
    if(jour <= tabJourMois[mois-1]){
        printf("Votre date de naissance semble correcte car le mois numéro %d ne possède que %d jours.\n\n", mois, tabJourMois[mois-1]);
    }else{
        printf("Votre date de naissance est impossible car le mois numéro %d ne possède que %d jours.\n\n", mois, tabJourMois[mois-1]);
    }
}

void affichageNomMois(int jour, int mois, int annee){
    char tabNomMois[12][10] = {"Janvier", "Février", "Mars", "Avril", "Mais", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Décembre"};
    int deroulementMois;

    for(deroulementMois = 0; deroulementMois < 12; deroulementMois++){
        printf("Le mois numéro %d a pour nom %s.\n", deroulementMois+1, tabNomMois[deroulementMois]);
    }
    printf("\n");
    printf("Votre date de naissance est le %d %s %d.\n", jour, tabNomMois[mois - 1], annee);
}

void msleep(unsigned int maxTime){
    struct timespec req;
    struct timespec rem;
    timer_t secondes = 0;
    long nanoSecondes = 0;
    if(maxTime>=1000){
        do{
            secondes++;
            maxTime-=1000;
        }while(maxTime>=1000);
    }
    nanoSecondes = maxTime*1000000;
    req.tv_sec = secondes;
    req.tv_nsec = nanoSecondes;
    nanosleep(&req, &rem);
}

unsigned int aleatoire(unsigned int maxAlea){
    struct timeb t;
    float a, b;
    unsigned int nbmilli;
    ftime(&t);
    nbmilli = t.time * 1000 + t.millitm;
    srand(nbmilli);
    a = rand();
    b = (maxAlea * a) / RAND_MAX;
    msleep(250);
    return((unsigned int) b);
}

void effacerEcran(){
    printf("%c[2J", 0x1B);
    printf("\033[50A");
}

int comptageCaractere(char proposition[]){
    int nombre;
    for(nombre = 0; proposition[nombre] != 0; nombre++){}
    return nombre;
}

void ecrireTextePendu(int nbCaractere, char carBon[TAILLEMAX]){
    int boucle;

    for(boucle = 0; boucle < nbCaractere; boucle++){
        if(carBon[boucle] != '\0'){
            printf("%c ", carBon[boucle]);
        }else{
            printf("_ ");
        }
    }
    printf("\n");
}

char verificationPendu(char aDeviner, char proposition, char carBon){
    if(aDeviner == proposition){
        return aDeviner;
    }else{
        if(carBon != '\0'){}
        else{
            return '\0';
        }
    }
}

void dessinerPendu(int lePendu){
    switch (lePendu){
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

void exercice1(){
    int jour;
    int mois;
    int annee;
    int tabJourMois[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

    char nom[TAILLEMAX];
    char prenom[TAILLEMAX];

    printf("Bienvenue dans l'exercice de synthèse !\n\n");

    annee = acquisitionAnneeNaissance();
    mois = acquisitionMoisNaissance();
    jour = acquisitionJourNaissance();

    printf("\n");

    printf("Votre date de naissance est le %d/%d/%d.\n\n", jour, mois, annee);

    printf("Votre nom : ");
    scanf("%s", nom);
    printf("Votre prénom : ");
    scanf("%s", prenom);
    printf("\n");

    printf("Bonjour %s %s.\n", prenom, nom);

    if(annee >= 1995){
        printf("Désolé, vous êtes trop jeune.");
    }else{
        printf("Vous êtes autorisé à continuer.");
        formatageDate(jour, mois, annee);
        comptageMois(jour, mois, annee, tabJourMois);
        verificationDateNaissance(jour, mois, tabJourMois);
        affichageNomMois(jour, mois, annee);
    }
}

void exercice2(){
    char proposition[5];
    char couleur[5] = {'r', 'r', 'v', 'b', 'b'};
    int deroulementCouleur;
    int nbPosBon;
    int tentative = 0;

    printf("Bienvenue dans le jeu MinorMind !\n\n");
    printf("Arriverez vous à deviner la couleur ?\n");

    do{
        tentative++;
        printf("Votre proposition (ex: rbvbr) : ");
        scanf(" %c%c%c%c%c", &proposition[0], &proposition[1], &proposition[2], &proposition[3], &proposition[4]);

        nbPosBon = 0;
        if((proposition[0] == 'r' || proposition[0] == 'v' || proposition[0] == 'b')
        && (proposition[1] == 'r' || proposition[1] == 'v' || proposition[1] == 'b')
        && (proposition[2] == 'r' || proposition[2] == 'v' || proposition[2] == 'b')
        && (proposition[3] == 'r' || proposition[3] == 'v' || proposition[3] == 'b')
        && (proposition[4] == 'r' || proposition[4] == 'v' || proposition[4] == 'b')){
            for(deroulementCouleur = 0; deroulementCouleur < 5; deroulementCouleur++){
                if(proposition[deroulementCouleur] == couleur[deroulementCouleur]){
                    nbPosBon++;
                }
            }
            printf("%d de vos couleurs sont à la bonne place.\n", nbPosBon);
        }else{
            printf("Saisie incorrecte.\n");
        }
    }while(nbPosBon < 5);
    printf("Félicitations !\n");
    printf("La séquence %c%c%c%c%c était la bonne !\n", couleur[0], couleur[1], couleur[2], couleur[3], couleur[4]);
    printf("Vous avez réussi à trouver la bonne séquence en %d tentative(s).\n", tentative);
}

void exercice3(){
    char phrasesENA[4][8][255] = {{"Mesdames, mesieurs, ", "Je reste fondamentalement persuadé que ", "Dès lors, sachez que je me battrai pour faire admettre que", "Par ailleurs, c'est en toute connaissance de cause que je peux affirmer aujourd'hui que ", "Je tiens à vous dire ici ma détermination sans faille pour clamer haut et fort que ", "J'ai depuis longtemps (ai-je besoin de vous le rappeler?), défendu l'idée que ", "Et c'est en toute conscience que je déclare avec conviction que ", "Et ce n'est certainement pas vous, mes chers compatriotes, qui me contredirez si je vous dis que "},
                                  {"la conjoncture actuelle ", "la situation d'exclusion que certains d'entre vous connaissent ", "l'acuité des problèmes de la vie quotidienne ", "la volonté farouche de sortir notre pays de la crise ", "l'effort prioritaire en faveur de statut précaire des exclus ", "le particularisme dû à notre histoire unique ", "l'aspiration plus que légitime de chacun au progrès social ", "la nécessité de répondre à votre inquiétude journalière, que vous soyez jeunes ou âgés, ", "Je reste fondamentalement persuadé que "},
                                  {"doit s'intégrer à la finalisation globale ", "oblige à la prise en compte encore plus effective ", "interpelle le citoyen que je suis et nous oblige tous à aller de l'avant dans la voie ", "a pour conséquence obligatoire l'urgente nécessité ", "conforte mon désir incontestable d'aller dans le sens ", "doit nous amener au choix réellement impératif ", "doit prendre en compte les préoccupations de la population de la base dans l'élaboration ", "entraine une mission somme toute des plus exaltantes pour moi : l'élaboration "},
                                  {"d'un projet porteur de véritable espoirs, notamment pour les plus démunis.", "d'un programme plus humain, plus fraternel et plus juste.", "de solutions rapides correspondant aux grands axes sociaux prioritaies.", "d'un plan correspondant véritablement aux exigences légitimes de chacun.", "d'une valorisation sans concession de nors caractères spécifiques.", "d'une restructuration dans laquelle chacun pourra enfin retrouver sa dignité.", "d'un avenir s'orientant vers plus de progrès et plus de justice.", "d'un processus allant vers plus d'égalité."}};

    int nbPhrase;
    int genererPhrase;

    printf("Combien de phrases voulez-vous générer ?");
    scanf("%d", &nbPhrase);
    for(genererPhrase = 0; genererPhrase < nbPhrase; genererPhrase++){
        printf("%d :\n", genererPhrase+1);
        printf("%s%s%s%s", phrasesENA[0][aleatoire(7)], phrasesENA[1][aleatoire(7)]
        , phrasesENA[2][aleatoire(7)], phrasesENA[3][aleatoire(7)]);
        printf("\n");
    }
}

void exercice4(){
    char proposition;
    char carBon[TAILLEMAX];
    char comparaisonCarBon[TAILLEMAX];
    char aDeviner[TAILLEMAX];
    int nbCaractere;
    int curseur;
    int lePendu = 1;
    int comparaison;

    printf("Bienvenue dans le jeu du pendu !\n\n");
    printf("Saisir le mot à deviner :");
    scanf("%s", aDeviner);

    effacerEcran();

    do{
        printf("\nProposer une lettre :");
        scanf(" %c", &proposition);

        effacerEcran();

        for(curseur = 0; curseur < TAILLEMAX; curseur++){
            comparaisonCarBon[curseur] = carBon[curseur];
        }

        nbCaractere = comptageCaractere(aDeviner);
        for(curseur = 0; curseur < TAILLEMAX; curseur++){
            carBon[curseur] = verificationPendu(aDeviner[curseur], proposition, carBon[curseur]);
        }

        if(strcmp(comparaisonCarBon, carBon) == 0){
            lePendu++;
            printf("Votre lettre n'est pas présente dans le mot à deviner.\n");
        }else{
            printf("Votre lettre est bien dans le mot à deviner.\n");
        }

        for(curseur = 0; curseur < 50; curseur++){
            comparaisonCarBon[curseur] = carBon[curseur];
        }

        ecrireTextePendu(nbCaractere, carBon);
        dessinerPendu(lePendu);
    }while((strcmp(carBon, aDeviner) != 0) && (lePendu < 13));
    if(lePendu == 13){
        effacerEcran();
        printf("GAME OVER\n\n");
        printf("Vous avez tué notre bon vieux M.Bidochon...\n");
        printf("Le mot était %s.\n", aDeviner);
    }else{
        effacerEcran();
        printf("Vous avez gagné, félicitations ! \nVous avez sauvé M.Bidochon de la pendaison.\n");
        printf("\nLe mot à deviner était bien %s !\n", aDeviner);
    }
}

int main()
{
    int numExercice;

    do{
    printf("Bienvenue dans le programme d'occupation de vacances.\n");
    printf("Quel exercice souhaitez-vous essayer ?\n");
    printf("1 - Synthèse Septembre Octobre\n");
    printf("2 - MinorMind\n");
    printf("3 - Générateur de langue de bois\n");
    printf("4 - Le pendu\n");
    printf("Votre choix : ");
    scanf("%d", &numExercice);

        switch (numExercice){
        case 1:
            effacerEcran();
            exercice1();
            break;
        case 2:
            effacerEcran();
            exercice2();
            break;
        case 3:
            effacerEcran();
            exercice3();
            break;
        case 4:
            effacerEcran();
            exercice4();
            break;
        default:
            printf("La valeur est incorrecte, réessayez.");
        }
    }while(numExercice < 1 || numExercice > 4);
}
