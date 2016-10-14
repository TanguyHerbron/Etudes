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
public class Cercle {
    private double x;
    private double y;
    private double rayon;
    
    Cercle()
    {
        x = 2;
        y = 3;
        rayon = 1.5;
    }
    
    Cercle(double x, double y, double rayon)
    {
        this.x = x;
        this.y = y;
        this.rayon = rayon;
    }
    
    void deplacerCercle(double nouveauX, double nouveauY)
    {
        x = nouveauX;
        y = nouveauY;
    }
    
    void changerRayon(double nouveauRayon)
    {
        rayon = nouveauRayon;
    }
    
    double perimetre()
    {
        return 2 * Math.PI * rayon;
    }
    
    void afficher()
    {
        System.out.println("x = " + x);
        System.out.println("y = " + y);
        System.out.println("Rayon = " + rayon);
    }
}
