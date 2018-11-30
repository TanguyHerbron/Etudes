package entity;

import java.util.ArrayList;
import java.util.List;

public class Emprunteur{

    private List<Empruntable> stock;

    public Emprunteur()
    {
        stock = new ArrayList<Empruntable>();
    }

    //La méthode est ici amélioréé par rapport au sujet.
    //J'utilise le retour de la méthode add de List comme valeur de retour.
    //La méthode add retourne true si l'ajout a bien été effectué, false sinon.
    public boolean ajouterAuStock(Empruntable empruntable)
    {
        return stock.add(empruntable);
    }

    public List<Empruntable> listeMateriel()
    {
        return stock;
    }

    public boolean perdreMateriel(Empruntable empruntable)
    {
        return stock.remove(empruntable);
    }
}
