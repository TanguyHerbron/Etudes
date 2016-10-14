#ifndef REVEIL_H_INCLUDED
#define REVEIL_H_INCLUDED

enum MODE_REVEIL
{
    REGLAGE_HEURES,
    REGLAGE_MINUTES,
    ACTIVER_ALARME
};

class Reveil
{
private:
    short heure;
    short minute;
    short mode;

public:
    bool AvancerHeure();
    bool ReculerHeure();
    bool AvancerMinute();
    bool ReculerMinute();

};

#endif // REVEIL_H_INCLUDED
