package entity;

import org.apache.log4j.Logger;

import java.util.ArrayList;
import java.util.List;

public class Administrateur extends Employe {
    private static final Logger LOG = Logger.getLogger(Administrateur.class);

    public Administrateur(Agence agence, Entreprise entreprise)
    {
        super(agence, entreprise);

        LOG.debug("Création d'un administrateur");
    }

    //La méthode attribuerMateriel fonctionne de la manière suivante :
    //Si l'empruntable n'a aucune limitation, on retourne le succès ou l'échec de l'ajout à la liste du stock.
    //Si une limitation est présente, on vérifie d'abord si l'emprunteur est bien une entreprise ou un agent.
    //Ensuite on retourne le succès ou l'échec de l'ajout à la liste stock.
    public boolean attribuerMateriel(Empruntable empruntable, Emprunteur emprunteur)
    {
        if(empruntable.isLimitationPretAuxAgence())
        {
            if(emprunteur instanceof Agence || emprunteur instanceof Entreprise)
            {
                return validerTransfertMateriel(empruntable, emprunteur);
            }
        }
        else
        {
            return validerTransfertMateriel(empruntable, emprunteur);
        }

        LOG.debug("Erreur d'attribution de matériel");

        return false;
    }

    private boolean validerTransfertMateriel(Empruntable empruntable, Emprunteur emprunteur)
    {
        LOG.debug("Validation d'attribution de matériel");

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

    //On vérifie d'abord si le premier emprunteur possède bien l'empruntable qu'il faut transférer
    //Si l'attribution à l'autre emprunteur est validée, on enlève le matériel de l'envoyeur
    //Cela évite de transférer un empruntable si la cible n'a pas les autorisations d'avoir cet objet
    //Ex : Un empruntable avec limitation ne peut pas aller à un employé
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

    //On supprime le matériel de l'intégralité de l'entreprise, donc aussi de chaque agence et de chaque employé de l'entreprise ainsi que de chaque agence.
    //On vérifie bien que le matériel est supprimé de toutes les agences indépendamment des entreprises (en cas de membres provenant d'SS2I)
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
