package entity;

import java.util.ArrayList;
import java.util.List;

public class Administrateur extends Employe {

    public Administrateur(Agence agence, Entreprise entreprise)
    {
        super(agence, entreprise);
    }

    //TODO Expliquer le fonctionnement de la méthode en détail
    public boolean attribuerMateriel(Empruntable empruntable, Emprunteur emprunteur)
    {
        if(empruntable.isLimitationPretAuxAgence())
        {
            if(emprunteur instanceof Agence || emprunteur instanceof Entreprise)
            {
                return validerTransfertMateriel(empruntable, emprunteur);
            }
            else
            {
                System.out.println("Matériel réservé");
            }
        }
        else
        {
            return validerTransfertMateriel(empruntable, emprunteur);
        }

        return false;
    }

    private boolean validerTransfertMateriel(Empruntable empruntable, Emprunteur emprunteur)
    {
        entreprise.perdreMateriel(empruntable);
        return emprunteur.ajouterAuStock(empruntable);
    }

    public boolean recupererMateriel(Empruntable empruntable, Emprunteur emprunteur)
    {
        if(emprunteur.perdreMateriel(empruntable))
        {
            return entreprise.ajouterAuStock(empruntable);
        }

        return false;
    }

    public List<Empruntable> stockEntreprise()
    {
        return entreprise.listeMateriel();
    }

    public List<Empruntable> stockAgence()
    {
        return agence.listeMateriel();
    }

    //TODO Détailler cette méthode
    public void transfererMateriel(Emprunteur emprunteurSend, Empruntable empruntable, Emprunteur emprunteurReceive)
    {
        if(emprunteurSend.listeMateriel().contains(empruntable))
        {
            if(attribuerMateriel(empruntable, emprunteurReceive))
            {
                emprunteurSend.perdreMateriel(empruntable);
            }
        }
    }

    //TODO Détailler pourquoi passer parmis les employés de l'agence ET de l'entreprise (SS2I)
    //TODO Peut-être passer par toutes les agences de l'entreprise ?
    public void supprimerMateriel(Empruntable empruntable)
    {
        entreprise.perdreMateriel(empruntable);
        agence.perdreMateriel(empruntable);

        for(Employe employe : agence.getEmployes())
        {
            employe.perdreMateriel(empruntable);
        }

        for(Employe employe : entreprise.listeEmployes())
        {
            employe.perdreMateriel(empruntable);
        }
    }

    public void supprimerMaterielDefectueuxEntreprise()
    {
        supprimerMaterielDefectueuxDe(entreprise);
    }

    public void supprimerMaterielDefectueuxAgence()
    {
        supprimerMaterielDefectueuxDe(agence);
    }

    public void supprimerMaterielDefectueuxAgence(Agence agence)
    {
        supprimerMaterielDefectueuxDe(agence);
    }

    private void supprimerMaterielDefectueuxDe(Emprunteur emprunteur)
    {
        int index = 0;

        while(index < emprunteur.listeMateriel().size())
        {
            if(emprunteur.listeMateriel().get(index).isDefectueux())
            {
                emprunteur.perdreMateriel(emprunteur.listeMateriel().get(index));
            }

            index++;
        }
    }

    public void achatDeMateriel(Empruntable empruntable)
    {
        entreprise.ajouterAuStock(empruntable);
    }
}
