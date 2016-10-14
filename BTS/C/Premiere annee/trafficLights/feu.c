#include "fonctions.h"

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

            printf("%s  rouge %d  allume\n", pfeu->id, pfeu->pinRouge);
            digitalWrite(pfeu->pinRouge,1);
            digitalWrite(pfeu->pinOrange,0);
            digitalWrite(pfeu->pinVert,0);
            break;

        case VERT:

            if (pfeu->timer[VERT]>15)
            {
                pfeu->etatActuel = ORANGE;
                pfeu->timer[VERT]=0;
            }

            pfeu->timer[VERT]++;
            digitalWrite(pfeu->pinRouge,0);
            digitalWrite(pfeu->pinOrange,0);
            digitalWrite(pfeu->pinVert,1);
            printf("%s vert %d allume\n", pfeu->id, pfeu->pinVert);
            break;

        case ORANGE:

            if (pfeu->timer[ORANGE]>=3)
            {
                pfeu->etatActuel = ROUGE;
                pfeu->timer[ORANGE] = 0;
            }

            pfeu->timer[ORANGE]++;
            printf("%s orange %d allume\n", pfeu->id, pfeu->pinOrange);
            digitalWrite(pfeu->pinRouge,0);
            digitalWrite(pfeu->pinOrange,1);
            digitalWrite(pfeu->pinVert,0);
            break;

         case ROUGE:

            if (pfeu->timer[ROUGE]>2)
            {
                pfeu->etatActuel = RECOUVREMENT;

                pfeu->finCycle = 1;
                pfeu->timer[ROUGE] = 0;
            }

            pfeu->timer[ROUGE]++;
            printf("%s rouge %d allume\n", pfeu->id, pfeu->pinRouge);
            digitalWrite(pfeu->pinRouge,1);
            digitalWrite(pfeu->pinOrange,0);
            digitalWrite(pfeu->pinVert,0);
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

void initialisationGPIO()
{
    int i;
    wiringPiSetup();
    for(i=0; i<8; i++)
    {
        //pinMode(i,OUTPUT);
    }
}
