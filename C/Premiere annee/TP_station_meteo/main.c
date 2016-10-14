#include <stdio.h>
#include <stdlib.h>

int main()
{
    float boolean = 1, lacune = 0, entree = 0;
    float minimum = 0, maximum = 0, minimumBuffer = 0, maximumBuffer = 0;
    do{
        printf("Entrer température minimum :");
        scanf("%f", &minimum);
        printf("Entrer température maximum :");
        scanf("%f", &maximum);

        maximumBuffer = maximumBuffer + maximum;
        minimumBuffer = minimumBuffer + minimum;

        if(minimum == 0 && maximum == 0)
        {
            boolean = 0;
        }
        else
        {
            if(minimum == 0 || maximum == 0)
            {
                lacune++;
                entree++;
            }
            else
            {
                entree++;
            }
        }
    }while(boolean == 1);

    if(entree != 0){
        printf("La moyenne des températures maximum est de %.2f.\n", maximumBuffer/entree);
        printf("La moyenne des températures minimum est de %.2f.\n", minimumBuffer/entree);
        printf("Il y a eu %.0f lacune(s).\n", lacune);
        printf("Il y a eu %.0f entrée(s).\n", entree);
        printf("Le nombre de lacune représente %.2f pourcent du nombre de données.", ((lacune/entree)/2)*100);
    }else{
        printf("Vous devez entrer une valeur.\n");
    }

}
