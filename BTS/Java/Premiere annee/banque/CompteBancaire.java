/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package banque;

/**
 *
 * @author therbron
 */
public class CompteBancaire {
    
    private float solde;
    private float decouvertAutorise;
    
    CompteBancaire()
    {
        solde = 100;
        decouvertAutorise = 50;
    }
    
    CompteBancaire(float solde, float decouvertAutorise)
    {
        this.solde = solde;
        if(decouvertAutorise < 0)
        {
            this.decouvertAutorise = 0;
        }
        else
        {
            this.decouvertAutorise = decouvertAutorise;            
        }
    }
    
    //Duplication d'un compte existant
    CompteBancaire(CompteBancaire unAutreCompte)
    {
        solde = unAutreCompte.solde;
        decouvertAutorise = unAutreCompte.decouvertAutorise;
    }
    
    void deposerArgent(float sommeDeposee)
    {
        if(sommeDeposee >= 0)
        {
            solde += sommeDeposee;
        }
        else
        {
            System.out.println("Vous ne pouvez pas déposer une somme négative.");
        }
    }
    
    //Retrait d'argent à condition que le dévouert autorisé ne soit pas dépassé
    void retirerArgent(float sommeRetiree)
    {
        if(sommeRetiree < 0)
        {
            System.out.println("Il est impossible de retirer une somme négative.");
        }
        else
        {
            if(( sommeRetiree) <= (solde + decouvertAutorise))
            {
                solde -= sommeRetiree;
            }
            else
            {
                System.out.println("Le retrait de cet argent est impossible, autorisation de découvert dépassée.");
            }
        }
    }
    
    void afficherCompte()
    {
        System.out.println("Solde : " + solde);
        System.out.println("Autorisation de découvert : " + decouvertAutorise);
    }
    
    void changerDecouvert(float nouveauDecouvert)
    {
        if(nouveauDecouvert >= 0)
        {
            decouvertAutorise = nouveauDecouvert;
        }
        else
        {
            System.out.println("Vous ne pouvez pas avoir une autorisation de découvert négative.");
        }
    }
    
}
