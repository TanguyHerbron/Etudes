/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testcompteepargne;

/**
 *
 * @author therbron
 */
public class CompteEpargne extends CompteBancaire{
    
    private double tauxInteret;
    
    CompteEpargne()
    {
        super();
        tauxInteret = 0.03;
    }
    
    CompteEpargne(double solde, double tauxInteret)
    {
        super(solde);
        this.tauxInteret = tauxInteret;
    }
    
    double calculerInteret()
    {
        return tauxInteret * solde;
    }
    
    void crediterInteret()
    {
        solde = solde + calculerInteret();
    }
    
    void changerTaux(double tauxInteret)
    {
        this.tauxInteret = tauxInteret;
    }
    
}
