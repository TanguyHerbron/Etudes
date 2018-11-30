package entity;

public class Employe extends Emprunteur {

    protected Agence agence;
    protected Entreprise entreprise;

    public Employe(Agence agence, Entreprise entreprise)
    {
        this.agence = agence;
        this.entreprise = entreprise;
    }
}
