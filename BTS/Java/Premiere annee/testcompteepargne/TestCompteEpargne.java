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
public class TestCompteEpargne {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        CompteEpargne ce;
        CompteCheque cc;
        double interet;
        
        ce = new CompteEpargne();
        cc = new CompteCheque(50);
        ce.deposer(100.0);
        interet = ce.calculerInteret();
        System.out.println(interet);
        
        
    }
    
}
