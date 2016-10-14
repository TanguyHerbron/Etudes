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
public class CompteBancaire {
    protected double solde;
    
    CompteBancaire()
    {
        
    }
    
    CompteBancaire(double solde)
    {
        this.solde = solde;
    }
    
    void deposer(double somme)
    {
        solde += somme;
    }
    
    void retirer(double retrait)
    {
        solde -= retrait;
    }
}
