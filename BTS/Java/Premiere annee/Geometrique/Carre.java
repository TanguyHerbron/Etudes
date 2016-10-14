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
public class Carre {
    
    final private int longueurDuCote;
    
    Carre()
    {
        longueurDuCote = 5;
    }
    
    Carre(int longueurDuCote)
    {
        this.longueurDuCote = longueurDuCote;        
    }
    
    int calculerAire()
    {
        int aire;
        aire = longueurDuCote * longueurDuCote;
        return aire;
    }
    
    int calculerPerimetre()
    {
        int perimetre;
        perimetre = longueurDuCote * 4;
        return perimetre;
    }
    
    void afficherPerimetre()
    {
        System.out.println("Perimetre = " + calculerPerimetre());
    }
    
    void afficherAire()
    {
        System.out.println("Aire = " + calculerAire());        
    }
    
}
