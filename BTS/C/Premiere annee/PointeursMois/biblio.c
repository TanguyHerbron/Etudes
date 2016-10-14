#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define NBMOIS 12
#define TAILLEMAX 50

char* moisNom(int numeroMois){
    char *mois[NBMOIS] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
    char *moisRetour;

    numeroMois--;

    moisRetour = (char*)malloc( ( strlen(mois[numeroMois])+1) * sizeof(char));
    strcpy(moisRetour, mois[numeroMois]);

    return moisRetour;
}

char* supprimerE(char chaine[]){
    int boucle;
    int boucleSensE = 0;
    int nbE = 0;

    char *sensE;

    for(boucle = 0; boucle < strlen(chaine); boucle++){
        if(chaine[boucle] == 'e'){
            nbE++;
        }
    }

    sensE = (char*)malloc( ( strlen(chaine)-nbE+1) * sizeof(char));

    for(boucle = 0; boucle < strlen(chaine); boucle++){
        if(chaine[boucle] != 'e'){
            sensE[boucleSensE] = chaine[boucle];
            boucleSensE++;
        }
    }

    return sensE;
}

char* saisirChaine(char *message){
    char *nom;
    char buffer[TAILLEMAX];

    printf("%s", message);
    scanf("%s", buffer);

    nom = (char*) malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(nom, buffer);

    return nom;

}

void swapFloat(float *ptr1, float *ptr2){
    float tmp;

    tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

void discriminant(float a, float b, float c, float *racine1, float *racine2, int *printResult){
    int delta;

    delta = b*b - 4*a*c;

    if(delta >= 0){
        *racine1 = ((-b - sqrt(delta)) / (2*a));
        *racine2 = ((-b + sqrt(delta)) / (2*a));
        *printResult = 1;
    }
}

void exercice1(){
    int choix;
    char *pointeur;

    printf("De quel mois voulez-vous le nom ? (Entre 1 et 12)\n");
    scanf("%d", &choix);

    pointeur = moisNom(choix);

    printf("%s", pointeur);
}

void exercice2(){
    char chaine[TAILLEMAX];
    char *pointeur;

    printf("Saisissez une chaine de caractère :");
    scanf("%s", chaine);

    pointeur = supprimerE(chaine);

    printf("%s", pointeur);
}

void exercice3(){
    char *nom;
    nom = saisirChaine("Comment vous appelez-vous ?");
    printf("Vous vous appelez %s.\n", nom);
}

void exercice4(){
    float val1;
    float val2;

    printf("Saisissez deux réels.\n");
    printf("1: ");
    scanf("%f", &val1);
    printf("2: ");
    scanf("%f", &val2);

    printf("Avant le changement:\n");
    printf("Val1 = %.2f \tVal2 = %.2f\n", val1, val2);
    swapFloat(&val1, &val2);

    printf("Après le changement:\n");
    printf("Val1 = %.2f \tVal2 = %.2f", val1, val2);
}

void exercice5(){
    float a;
    float b;
    float c;

    float racine1;
    float racine2;

    int printResult = 0;

    printf("Calcul de discriminant.\n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    discriminant(a, b, c, &racine1, &racine2, &printResult);

    if(printResult){
        printf("%f\t%f", racine1, racine2);
    }else{
        printf("Aucune racine.");
    }
}
