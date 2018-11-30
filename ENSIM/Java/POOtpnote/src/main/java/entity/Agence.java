package entity;

import java.util.ArrayList;
import java.util.List;

public class Agence extends Emprunteur implements Comparable<Agence> {

    private List<Employe> employes;
    private String nom;

    public Agence(String nom)
    {
        this.nom = nom;
        employes = new ArrayList<Employe>();
    }

    public List<Employe> getEmployes() {
        return employes;
    }

    //TODO Détailler l'ajout de l'ENSEMBLE des stocks
    @Override
    public List<Empruntable> listeMateriel()
    {
        List<Empruntable> stock = super.listeMateriel();

        for(Employe employe : employes)
        {
            stock.addAll(employe.listeMateriel());
        }

        return stock;
    }

    public int getNbMaterielDefectueux()
    {
        int nb = 0;

        for(Empruntable empruntable : listeMateriel())
        {
            if(empruntable.isDefectueux())
            {
                nb++;
            }
        }

        return nb;
    }

    public int compareTo(Agence o)
    {
        return (getNbMaterielDefectueux() - o.getNbMaterielDefectueux());
    }
}
