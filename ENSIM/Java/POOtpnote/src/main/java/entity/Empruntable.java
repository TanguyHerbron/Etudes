package entity;

//Un package entity a été créé pour que les objets du package material puissent bien hérité d'empruntable
public class Empruntable {

    private boolean limitationPretAuxAgence;
    private boolean defectueux;

    public Empruntable() {}

    public Empruntable(boolean limitationPretAuxAgence)
    {
        this.limitationPretAuxAgence = limitationPretAuxAgence;
    }

    public void declarerDefectueux()
    {
        defectueux = true;
    }

    public boolean isDefectueux()
    {
        return defectueux;
    }

    public boolean isLimitationPretAuxAgence() {
        return limitationPretAuxAgence;
    }

    public void setLimitationPretAuxAgence(boolean limitationPretAuxAgence) {
        this.limitationPretAuxAgence = limitationPretAuxAgence;
    }
}
