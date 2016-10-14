/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fonderie;

/**
 *
 * @author therbron
 */
public class Fonderie {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Barre barre = new Barre();
        //Barre ronde en cuivre
        BarreRonde barreRonde0 = new BarreRonde(3, 8.9, 8, "0002");
        BarreRonde barreRonde1 = new BarreRonde(4, 8.9, 8, "0002");
        //Barre carree en cuivre
        BarreCarree barreCarree = new BarreCarree(3, 8.9, 8, "0003");
        //Barre rectangle en plutonium
        BarreRectangle barreRectangle = new BarreRectangle(8, 2.1, 19.8, 15, "0004");
        
        barre.afficherReference();
        barreRonde0.afficherReference();
        System.out.println(barreRonde0.calculerMasse());
        barreRonde1.afficherReference();
        System.out.println(barreRonde1.calculerMasse());
        barreCarree.afficherReference();
        System.out.println(barreCarree.calculerMasse());
        barreRectangle.afficherReference();
        System.out.println(barreRectangle.calculerMasse());
    }
    
}
