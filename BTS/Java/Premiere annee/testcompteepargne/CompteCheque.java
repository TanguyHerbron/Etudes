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
public class CompteCheque extends CompteBancaire{
    
    private double decouvertAutorise;
    
    CompteCheque(double decouvertAutorise)
    {
        super();
        this.decouvertAutorise = decouvertAutorise;
    }
    
    void changerDecouvert(double nouveauDecouvert)
    {
        decouvertAutorise = nouveauDecouvert;
    }
    
    @SuppressWarnings("override")
    void retirer(double retrait)
    {
        
    }
}
