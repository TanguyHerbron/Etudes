#include "fonctions.h"

void effacerEcran(){
    printf("%c[2J", 0x1B);
    printf("\033[50A");
}

int changerEtat(feu *pfeu)
{

    switch(pfeu->etatActuel)
    {

        case RECOUVREMENT:

            if (pfeu->debut==1)
            {
                pfeu->etatActuel = VERT;
                pfeu->finCycle = 0;
            }

            printf("%s%s%s ████\n", RESET, pfeu->id, RED);
            break;

        case VERT:

            if (pfeu->timer[VERT]>15)
            {
                pfeu->etatActuel = ORANGE;
                pfeu->timer[VERT]=0;
            }

            pfeu->timer[VERT]++;
            printf("%s%s%s ████\n", RESET, pfeu->id, GREEN);
            break;

        case ORANGE:

            if (pfeu->timer[ORANGE]>=3)
            {
                pfeu->etatActuel = ROUGE;
                pfeu->timer[ORANGE] = 0;
            }

            pfeu->timer[ORANGE]++;
            printf("%s%s%s ████\n", RESET, pfeu->id, YELLOW);
            break;

         case ROUGE:

            if (pfeu->timer[ROUGE]>2)
            {
                pfeu->etatActuel = RECOUVREMENT;

                pfeu->finCycle = 1;
                pfeu->timer[ROUGE] = 0;
            }

            pfeu->timer[ROUGE]++;
            printf("%s%s%s ████\n", RESET, pfeu->id, RED);
            break;
    }
    return 0;
}

int initialisation(feu *pfeu)
{
    pfeu->etatActuel = RECOUVREMENT;
    pfeu->finCycle = 0;
    pfeu->timer[ROUGE] = 0;
    pfeu->timer[ORANGE] = 0;
    pfeu->timer[VERT]= 0;
    return 0;
}

