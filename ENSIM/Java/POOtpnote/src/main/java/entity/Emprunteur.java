package entity;

import java.util.ArrayList;
import java.util.List;

public class Emprunteur{

    private List<Empruntable> stock;

    public Emprunteur()
    {
        stock = new ArrayList<Empruntable>();
    }

    //TODO Amélioration de la méthode, préciser pourquoi utiliser un boolean plutôt qu'un void
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
