/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cercledepuisc;

/**
 *
 * @author therbron
 */
public class CercleDepuisC {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Cercle c1 = new Cercle(3, 5, 10);
        Cercle c2 = new Cercle(-2, 4, 3);
        
        c1.afficher();
        System.out.println("perimetre = " + c1.perimetre());
        c2.afficher();
        System.out.println("perimetre = " + c2.perimetre());
        c1.deplacerCercle(1, 2);
        c1.afficher();
        System.out.println("perimetre = " + c1.perimetre());
        c2.changerRayon(6);
        c2.afficher();
        System.out.println("perimetre = " + c2.perimetre());
    }
    
}
