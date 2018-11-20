import exception.LimiteVisiteurException;

import java.util.ArrayList;
import java.util.List;

public class Zoo {

    private int nbVisiteurs;
    private List<Secteur> secteursAnimaux;

    public Zoo()
    {
        secteursAnimaux = new ArrayList<Secteur>();
    }

    public void nouveauVisiteur() throws LimiteVisiteurException
    {
        if(nbVisiteurs >= getLimiteVisiteur())
        {
            throw new LimiteVisiteurException();
        }
        else
        {
            nbVisiteurs++;
        }
    }

    public int getLimiteVisiteur()
    {
        return secteursAnimaux.size() * Secteur.NB_MAX_VISITEURS;
    }

    public void nouvelAnimal(Animal animal)
    {
        int index = 0;
        boolean found = false;

        while(index < secteursAnimaux.size() && !found)
        {
            index++;

            if(secteursAnimaux.get(index).obtenirType().equals(animal.getTypeAnimal()))
            {
                found = true;

                secteursAnimaux.get(index).ajouterAnimal(animal);
            }
        }

        if(secteursAnimaux.size() == 0 || !found)
        {
            Secteur secteur = new Secteur(animal.getTypeAnimal());
            secteur.ajouterAnimal(animal);
            secteursAnimaux.add(secteur);
        }
    }

    public int nombreAnimaux()
    {
        return 0;
    }

    public int getNombreVisiteur()
    {
        return nbVisiteurs;
    }
}
