package entity;

//TODO Préciser pourquoi un package entity a été créé (héritage du matériel)
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
