#include <stdio.h>
#include "reveil.h"
#include "horloge.h"

Reveil::Reveil(const short _resolution, const short _nbMode)
    : heureAlarme(0), minuteAlarme(0), active(false), Horloge(_resolution, _nbMode)
{}

bool Reveil::Surveiller()
{
    if(heureAlarme == heures && minuteAlarme == minutes)
    {

    }
}

void Reveil::AvancerHeureAlarme()
{
    heureAlarme++;
    if(heureAlarme == 24)
    {
        heureAlarme = 0;
    }
}

void Reveil::AvancerMinuteAlarme()
{
    minuteAlarme++;
    if(heureAlarme == 60)
    {
        heureAlarme = 0;
    }
}

void Reveil::ReculerHeureALarme()
{
    heureAlarme--;
    if(heureAlarme < 0)
    {
        heureAlarme = 23;
    }
}

void Reveil::ReculerMinuteAlarme()
{
    minuteAlarme--;
    if(minuteAlarme < 0)
    {
        minuteAlarme = 59;
    }
}

void Reveil::Controler()
{
    while(1)
    {
        switch(mode)
        {
        case ACTIVER_ALARME:
            break;

        case REGLAGE_HEURES_ALARME:
            break;

            case REGLAGE_MINUTES_ALARME:
                break;


        }
    }

}

void Reveil::ChangerEtatAlarme()
{
    if(active == false)
    {
        active = true;
    }
    else
    {
        active = false;
    }
}
