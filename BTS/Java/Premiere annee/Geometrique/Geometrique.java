/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Geometrique;

/**
 *
 * @author therbron
 */
public class Geometrique {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Point p1 = new Point();
        Point p2 = new Point( 1, 2);
        
        Carre carre0 = new Carre();
        Carre carre1 = new Carre(10);
        Carre carre2 = new Carre(15);
        Carre carre3 = new Carre(100);
        
        Cercle cercle1 = new Cercle();
        
        Triangle triangle1 = new Triangle();
        
        Trait trait1 = new Trait();
        
        p1.translater(10.0, 20.1);
        
        p1.afficher("P1");
        p2.afficher("P2"); 
        
        carre0.calculerAire();        
        carre0.afficherAire();
              
        carre1.calculerAire();        
        carre1.afficherAire();
                
        carre2.calculerAire();        
        carre2.afficherAire();
                
        carre3.calculerAire();        
        carre3.afficherAire();
    }
    
}
